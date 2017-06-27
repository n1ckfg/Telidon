@echo off
if %1. == . goto help
set IN=%1
set OUT=%2
qbasic /RUN dbgscr.bas
set IN=
set OUT=
goto end
:help
echo Usage:
echo ÿ
echo dbgscr inputfile ouputfile
echo ÿ
echo This program converts the inputfile into a plain ASCII
echo DEBUG script in outputfile that can be sent via e-mail or netmail.
echo At the receiving end the original file can be reconstituted by
echo typing "DEBUG <outputfile"
:end
