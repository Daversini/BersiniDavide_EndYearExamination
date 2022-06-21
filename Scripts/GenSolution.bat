@echo off
title Premake5 Solution Generator
mode con cols=55 lines=20

:: https://stackoverflow.com/a/21666354/17818428
SETLOCAL EnableDelayedExpansion
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "DEL=%%a"
)

echo		\===============================\
echo		 \	Made by Daversini!	 \
echo		  \===============================\
echo.
call :colorEcho 03 " Select a Visual Studio version to build the solution"
echo.
call :colorEcho 0a "          2017         2019         2022"
echo.
set /P c= ^> 
if /I "%c%" EQU "2017" goto :premake2017
if /I "%c%" EQU "2019" goto :premake2019
if /I "%c%" EQU "2022" goto :premake2022

:premake2017
color 06
cls
echo.
premake5 vs2017
echo.
pause
exit

:premake2019
color 06
cls
echo.
premake5 vs2019
echo.
pause
exit

:premake2022
color 06
cls
echo.
premake5 vs2022
echo.
pause
exit

:colorEcho
echo off
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i