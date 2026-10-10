# 一键同步：有改动就提交，然后推到 GitHub。
#
# 用法（在 cpp-demo 目录下）：
#   .\sync.ps1                     自动写一条带日期的提交信息
#   .\sync.ps1 "题十二 环形缓冲"     自己写提交信息
#
# 没改动的时候什么都不做，不会产生空提交。
#
# 2026-10-10 修：计划任务在干净的登录环境里跑，PATH 里没有 git，脚本第一句就抛错、
#   窗口闪一下就没；这里改成自己先找 git，并把每一步写进日志。

param([string]$Message)

$ErrorActionPreference = "Stop"
Set-Location $PSScriptRoot

# 桌面那份易错点台账，同步前先抄一份进仓库（主人只改桌面那份，仓库这份是镜子）
$ledgerSrc = Join-Path $env:USERPROFILE "Desktop\新建文件夹\C语言易错点.txt"
$ledgerDst = Join-Path $PSScriptRoot "C语言易错点.txt"
try {
    if (Test-Path $ledgerSrc) {
        Copy-Item -LiteralPath $ledgerSrc -Destination $ledgerDst -Force
    }
}
catch {
    Write-Host ("抄台账时出错：" + $_.Exception.Message)
}

$logDir = Join-Path $PSScriptRoot "_teacher\_tmp"
if (-not (Test-Path $logDir)) { New-Item -ItemType Directory -Path $logDir -Force | Out-Null }
$logFile = Join-Path $logDir "sync.log"
function Write-Log([string]$text) {
    $line = (Get-Date -Format "yyyy-MM-dd HH:mm:ss") + "  " + $text
    Write-Host $line
    Add-Content -Path $logFile -Value $line -Encoding UTF8
}

# 找 git：先看 PATH，找不到再翻几个常见位置（Codex 自带的那个、Git for Windows 默认装法）
$git = (Get-Command git -ErrorAction SilentlyContinue).Source
if (-not $git) {
    $cands = @(
        (Join-Path $env:USERPROFILE ".cache\codex-runtimes\codex-primary-runtime\dependencies\native\git\cmd\git.exe"),
        "C:\Program Files\Git\cmd\git.exe",
        "C:\Program Files (x86)\Git\cmd\git.exe"
    )
    foreach ($c in $cands) { if (Test-Path $c) { $git = $c; break } }
}
if (-not $git) {
    Write-Log "找不到 git。装一个 Git for Windows，或者把 git.exe 的目录加进 PATH。"
    exit 1
}

try {
    if (-not (& $git status --porcelain)) {
        Write-Log "没有改动，跳过。"
        exit 0
    }

    if (-not $Message) {
        $Message = "日常同步 " + (Get-Date -Format "yyyy-MM-dd HH:mm")
    }

    & $git add -A
    if ($LASTEXITCODE -ne 0) { Write-Log ("git add 失败，退出码 " + $LASTEXITCODE); exit 1 }

    & $git commit -q -m $Message
    if ($LASTEXITCODE -ne 0) { Write-Log ("git commit 失败，退出码 " + $LASTEXITCODE); exit 1 }

    & $git push
    if ($LASTEXITCODE -ne 0) {
        Write-Log ("直连推送失败，退出码 " + $LASTEXITCODE + "；改走本地代理 127.0.0.1:7897 再试一次")
        & $git -c http.proxy=http://127.0.0.1:7897 push
        if ($LASTEXITCODE -ne 0) { Write-Log ("走代理也没推上去，退出码 " + $LASTEXITCODE); exit 1 }
    }
    Write-Log ("已推送：" + $Message)
}
catch {
    Write-Log ("出错了：" + $_.Exception.Message)
    exit 1
}
