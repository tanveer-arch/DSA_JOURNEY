@echo off
echo ==========================================
echo 🔄 Syncing DSA Progress with GitHub
echo ==========================================
echo.

:: Run python README generator
echo 📝 Generating updated README.md...
python generate_readme.py
if %ERRORLEVEL% NEQ 0 (
    echo ❌ README generation failed! Please check python script.
    pause
    exit /b %ERRORLEVEL%
)
echo.

:: Ask for commit message
set /p commit_msg="💬 Enter commit message (or press Enter for default 'Solve: updates'): "
if "%commit_msg%"=="" set commit_msg=Solve: updates

:: Git status check and sync
echo.
echo 🚀 Staging files...
git add .

echo 📦 Committing changes...
git commit -m "%commit_msg%"

echo 📤 Pushing to GitHub...
git push -u origin main

echo.
echo ==========================================
echo ✅ Sync completed successfully! Keep it up!
echo ==========================================
pause
