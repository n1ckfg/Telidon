echo off
cls
rem This file assumes that either you have an ANSI driver installed or that
rem your background color is black.  It displays each of the 64 colors with
rem a wait of n/2 seconds n=1,2,3,4,... if you enter "color n".
if %1a == a goto noparm
echo [0;37;40m
cls
stackey [7=7] >nul    ;check for EGA
if errorlevel 1 goto no EGA
stackey [7=%1] [7=7] >nul  ;check for bad parameter
if errorlevel 1 goto badparam
stackey /u/ {cu=-}  ; save user's options and surpress cursor
stackey /i n/ ;turn off smart processing to prevent stray keypresses
:                       from causing havoc
stackey {w=9*%1}[0=1]{w=9*%1}[0=2]{w=9*%1}[0=3]{w=9*%1}[0=4]{w=9*%1}[0=5]{w=9*%1}[0=6]{w=9*%1}[0=7]{w=9*%1}[0=8]
stackey {w=9*%1}[0=9]{w=9*%1}[0=10]{w=9*%1}[0=11]{w=9*%1}[0=12]{w=9*%1}[0=13]{w=9*%1}[0=14]{w=9*%1}[0=15]{w=9*%1}[0=16]
stackey {w=9*%1}[0=17]{w=9*%1}[0=18]{w=9*%1}[0=19]{w=9*%1}[0=20]{w=9*%1}[0=21]{w=9*%1}[0=22]{w=9*%1}[0=23]{w=9*%1}[0=24]
stackey {w=9*%1}[0=25]{w=9*%1}[0=26]{w=9*%1}[0=27]{w=9*%1}[0=28]{w=9*%1}[0=29]{w=9*%1}[0=30]{w=9*%1}[0=31]{w=9*%1}[0=32]
stackey {w=9*%1}[0=33]{w=9*%1}[0=34]{w=9*%1}[0=35]{w=9*%1}[0=36]{w=9*%1}[0=37]{w=9*%1}[0=38]{w=9*%1}[0=39]{w=9*%1}[0=40]
stackey {w=9*%1}[0=41]{w=9*%1}[0=42]{w=9*%1}[0=43]{w=9*%1}[0=44]{w=9*%1}[0=45]{w=9*%1}[0=46]{w=9*%1}[0=47]{w=9*%1}[0=48]
stackey {w=9*%1}[0=49]{w=9*%1}[0=50]{w=9*%1}[0=51]{w=9*%1}[0=52]{w=9*%1}[0=53]{w=9*%1}[0=54]{w=9*%1}[0=55]{w=9*%1}[0=56]
stackey {w=9*%1}[0=57]{w=9*%1}[0=58]{w=9*%1}[0=59]{w=9*%1}[0=60]{w=9*%1}[0=61]{w=9*%1}[0=62]{w=9*%1}[0=63]{w=9*%1}[0=0]
stackey {cu=+}
stackey /o/ ; remember to restore the users options
goto end
:noparm
echo Run as color n to make the pauses last n/2 seconds with n between 1 and 20
goto cont
:noega
echo Sorry!  This demo will only work on an EGA.  With a CGA, try cgacolor.bat
goto end
:badparam
echo The only legal values for the parameter after color are integers.
echo Run as color n to make the pauses last n/2 seconds with n between 1 and 20
:cont
echo:
echo:
echo:
echo  Do you wish to run the demo at the default 1/2 second (Y/N)
stackey {~a} >nul
color 1
:end

