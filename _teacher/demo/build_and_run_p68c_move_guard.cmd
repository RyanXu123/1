@echo off
setlocal
cd /d "%~dp0"

gcc -std=c11 -Wall -Wextra -Werror p68c_move_guard.c -o p68c_move_guard.exe
if errorlevel 1 (
    echo.
    echo Compile failed.
    if /I not "%~1"=="--no-pause" pause
    exit /b 1
)

echo.
echo Compile succeeded.
echo.
p68c_move_guard.exe

if /I not "%~1"=="--no-pause" pause
exit /b 0
