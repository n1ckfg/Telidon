echo off

REM.   This batch file is used to setup MGE (shareware) for use.
REM.   Copyright (C) 1991 Microstar Software Ltd.
REM.   Version __STMG1K

REM. **************************************************************************

REM.   Check if no arguments are specified
if not a%1==a  goto ENGLISH

:NOLANG
REM  1234567890123456789012345678901234567890123456789012345678901234567890123456789
echo ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
dir /w *.SCR
echo บ                                                                             บ
echo บ You must set up the MGE program for your graphics card before you can use   บ
echo บ it.  Please type "MGESET" and one of the above graphic card names.          บ
echo บ                                                                             บ
echo บ   Example:  MGESET VGA640                                                   บ
echo ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
goto DONE

:ENGLISH
if exist %1.SCR        goto ENGSUFF

:ENGNODRV
:ENGMISSD
echo ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
dir /w *.SCR
echo. ÿ
echo ÿ This graphics card name, "%1.SCR", cannot be found.
echo บ Please choose a name from the list above.                                   บ
echo บ                                                                             บ
echo บ    Example:  MGESET EGA640                                                  บ
echo ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
goto DONE

:ENGSUFF
if exist %1.OPT del %1.OPT
if exist %1.OPT echo  Unable to remove old '%1.OPT' file of options.
echo.  %2 %3 %4 %5 %6 %7 %8 %9      >%1.OPT
if not exist %1.OPT echo Unable to save '%1.OPT' file of options.

echo echo off                     >mge.bat
echo lookmous                     >>mge.bat
echo if errorlevel 1 goto nomouse >>mge.bat
echo goto start                   >>mge.bat
echo :nomouse                     >>mge.bat
echo echo MGE requires a mouse. Please install one and try again. >>mge.bat
echo goto end                     >>mge.bat
echo :start                       >>mge.bat
echo MVDIAPP MGEEXE.EXE +2 DUMMY.MGE MGEEXE.EXE %1.SCR %2 %3 %4 %5 %6 %7 %8 %9 %%1 >>mge.bat
echo :end                         >>mge.bat
goto ENGDONE

:ENGDONE
echo. ÿ
echo ÿ Type "MGE" to use the software.
echo ÿ To change the graphics card support again, type "MGESET".
echo. ÿ
goto DONE

REM. **************************************************************************

:DONE
