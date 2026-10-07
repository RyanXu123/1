# 一键同步：有改动就提交，然后推到 GitHub。
#
# 用法（在 cpp-demo 目录下）：
#   .\sync.ps1                     自动写一条带日期的提交信息
#   .\sync.ps1 "题十二 环形缓冲"     自己写提交信息
#
# 没改动的时候什么都不做，不会产生空提交。

param([string]$Message)

$ErrorActionPreference = "Stop"
Set-Location $PSScriptRoot

if (-not (git status --porcelain)) {
    Write-Host "没有改动，跳过。"
    exit 0
}

if (-not $Message) {
    $Message = "日常同步 " + (Get-Date -Format "yyyy-MM-dd HH:mm")
}

git add -A
git commit -q -m $Message
git push
Write-Host ("已推送：" + $Message)