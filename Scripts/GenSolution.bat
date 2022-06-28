@echo off
title Premake5 Solution Generator
mode con cols=55 lines=27

:: LINE COLORS REQUIREMENTS - HEADER
SETLOCAL EnableDelayedExpansion
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "DEL=%%a"
)
:: END REQUIREMENTS

:start
echo		 \===============================\
echo		  \	  Made by Daversini!	  \
echo		   \===============================\
echo.
call :colorEcho 03 " Select a Visual Studio version to build the solution"
echo.
call :colorEcho 0c " - 2012 (Oldest available)"
echo.
call :colorEcho 06 " - 2013"
echo.
call :colorEcho 06 " - 2015"
echo.
call :colorEcho 06 " - 2017"
echo.
call :colorEcho 0a " - 2019 (Reccomended)"
echo.
call :colorEcho 0a " - 2022 (Latest)"
echo.
echo.
set /P VSVersion= ^> 
if /I "%VSVersion%" EQU "2012" 		goto versionSelected
if /I "%VSVersion%" EQU "2013" 		goto versionSelected
if /I "%VSVersion%" EQU "2015" 		goto versionSelected
if /I "%VSVersion%" EQU "2017" 		goto versionSelected
if /I "%VSVersion%" EQU "2019" 		goto versionSelected
if /I "%VSVersion%" EQU "2022" 		goto versionSelected
if /I "%VSVersion%" EQU "designer"	goto homer
goto :errorHandler

:versionSelected
color 06
cls
echo.
premake5.exe vs%VSVersion%
echo.
echo Solution built for Visual Studio %VSVersion%^^!
echo.
pause
exit

:errorHandler
echo.
call :colorEcho 0c "--Error--"
echo.
echo.
call :colorEcho 06 "%VSVersion% is not an available option, try again"
echo.
echo.
pause
cls
goto :start
















:homer
cls
color 06
:::
:::              _ _,---._
:::           ,-','       `-.___
:::          /-;'               `._
:::         /\/          ._   _,'o \
:::        ( /\       _,--'\,','"`. )
:::         |\      ,'o     \'    //\
:::         |      \        /   ,--'""`-.
:::         :       \_    _/ ,-'         `-._
:::          \        `--'  /                )
:::           `.  \`._    ,'     ________,','
:::             .--`     ,'  ,--` __\___,;'
:::              \`.,-- ,' ,`_)--'  /`.,'
:::               \( ;  | | )      (`-/
:::                 `--'| |)       |-/
:::                   | | |        | |
:::                   | | |,.,-.   | |_
:::                   | `./ /   )---`  )
:::                  _|  /    ,',   ,-'
:::                 ,'|_(    /-<._,' |--,
:::                 |    `--'---.     \/ \
:::                 |          / \    /\  \
:::               ,-^---._     |  \  /  \  \
:::            ,-'        \----'   \/    \--`.
:::           /            \              \   \
:::

:: ASCI ART REQUIREMENTS
for /f "delims=: tokens=*" %%A in ('findstr /b ::: "%~f0"') do @echo(%%A
:: END REQUIREMENTS

pause
start GenSolution.bat
exit

:: LINE COLORS REQUIREMENTS - FOOTER
:colorEcho
echo off
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i
:: END REQUIREMENTS

:: CREDITS
:: Homer ASCII Art:	https://stackoverflow.com/a/19645839/17818428
:: Line Colors:		https://stackoverflow.com/a/21666354/17818428