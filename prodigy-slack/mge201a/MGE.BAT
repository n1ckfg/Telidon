echo off
lookmous
if errorlevel 1 goto nomouse
goto start
:nomouse
echo MGE requires a mouse. Please install one and try again.
goto end
:start
MVDIAPP MGEEXE.EXE +2 DUMMY.MGE MGEEXE.EXE vga640.SCR         %1
:end
