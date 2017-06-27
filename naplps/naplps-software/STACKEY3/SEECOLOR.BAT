echo off
cls
stackey {cu=-}
stackey /u/
stackey /i/ ;turn off smart processing to prevent stray keypresses
:                       from causing havoc
if %1a == a goto error
echo [37;40;0m
:top
cls
if %1 == 7 stackey [7=0]
stackey [0=%1]>nul
if errorlevel 1 goto error
echo This is color number %1
pause
if %1 == 7 stackey [7=7]
shift
if %1a == a goto end
goto top
:end
echo [44;1m
stackey []
cls
goto finish
:error
echo:
echo:
echo Oops!  The input parameter is not correct.
echo The input parameter should be a number from 0 to 63 or a RrBbGg string
echo:
pause
echo [44;1m
stackey []
:finish
stackey {cu=+}
stackey /o/ ; remember to restore users options

