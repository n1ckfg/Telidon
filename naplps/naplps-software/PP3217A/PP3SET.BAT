echo off

REM   This batch file is used to setup Personality+III (Shareware) for use.
REM   Copyright (C) 1992 Microstar Software Ltd.
REM   Version __STPS2M

if a%1==a  goto NOLANG

REM **************************************************************************

if not exist PP3SET%1.BAT goto NOTCUSTOM
:CUSTOM
REM   The user has entered a language letter for which there is a setup file.
REM   Control is passed to the custom file.
REM   L'utilisateur a introduit une lettre alphabtique pour laquelle il
REM   existe un fichier d'installation.  L'excution est transfre au
REM   fichier modifi.
%0%1 %1 %2 %3 %4 %5 %6 %7 %8 %9
:NOTCUSTOM

REM **************************************************************************

REM   Check if no language or unrecognized language specified

if a%1==ae goto VALIDATE
if a%1==aE goto VALIDATE
if a%1==af goto VALIDATE
if a%1==aF goto VALIDATE

:NOLANG
REM  1234567890123456789012345678901234567890123456789012345678901234567890123456789
echo ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
dir /w *.SCR
echo บ                                                                             บ
echo บ You must set up Personality+III     บ Vous devez configurer Personnalit+IIIบ
echo บ for your graphics card before you   บ pour votre carte graphique avant de   บ
echo บ can use it.  Please type "PP3SET",  บ pouvoir l'utiliser.  Tapez "PP3SET",  บ
echo บ a letter to indicate language ("E"  บ une lettre pour indiquer la langue    บ
echo บ for English or "F" for French), and บ dsire ("E" pour l'anglais ou "F"    บ
echo บ one of the above graphic card names.บ pour le franais) et l'un des noms    บ
echo บ                                     บ des cartes graphiques ci-dessus.      บ
echo บ                                     บ                                       บ
echo บ   Example:  PP3SET E VGA640         บ     Exemple:  PP3SET F EGA640         บ
echo ศอออออออออออออออออออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออผ
goto DONE

REM **************************************************************************

REM  At this point, the language is acceptable, so validate arguments.

:VALIDATE

REM  Validate the message file exists

:MSGCHECK
if exist PP3S%1.msg goto MSGGOOD
:MSGBAD
if a%1==ae goto ENGMSGBAD
if a%1==aE goto ENGMSGBAD
if a%1==af goto FRNMSGBAD
if a%1==aF goto FRNMSGBAD
goto PROBLEM
:MSGGOOD

REM  Validate that the screen driver exists

if a%2==a              goto SCRBAD
if exist %2            goto SCRGOOD
if exist %2.SCR        goto SCRGOOD
:SCRBAD
if a%1==ae goto ENGSCRBAD
if a%1==aE goto ENGSCRBAD
if a%1==af goto FRNSCRBAD
if a%1==aF goto FRNSCRBAD
goto PROBLEM
:SCRGOOD

REM **************************************************************************

REM At this point, all argument variables are verified, so produce batch file.

echo ECHO OFF        >PP3.BAT

if     exist %2 echo MVDIAPP PP3SCOMM.EXE +Z +2 %2     %3 %4 %5 %6 %7 PP3SCOMM.EXE /FMPP3S%1.MSG %%1 %%2 %%3 >>PP3.BAT
if not exist %2 echo MVDIAPP PP3SCOMM.EXE +Z +2 %2.SCR %3 %4 %5 %6 %7 PP3SCOMM.EXE /FMPP3S%1.MSG %%1 %%2 %%3 >>PP3.BAT

if a%1==ae goto ENGDONE
if a%1==aE goto ENGDONE
if a%1==af goto FRNDONE
if a%1==aF goto FRNDONE
goto PROBLEM

REM **************************************************************************

REM Setup messages in English

:ENGSCRBAD
echo ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
dir /w *.SCR
echo ÿ
echo ÿ This graphics card name, "%2", cannot be found.
echo บ Please choose a name from the list above.                                   บ
echo บ                                                                             บ
echo บ    Example:  PP3SET E EGA640                                                บ
echo ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
goto DONE

:ENGMSGBAD
echo ÿ
echo ÿ The support file "PP3S%1.MSG" does not exist.
echo ÿ
goto DONE

:ENGDONE
echo ÿ
echo ÿ Type "PP3" to use Personality+III.
echo ÿ To change the graphics card support again, type "PP3SET".
echo ÿ
goto DONE

REM **************************************************************************

REM Setup messages in French

:FRNSCRBAD
echo ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
dir /w *.SCR
echo ÿ
echo ÿ Ce nom de carte grahique, "%2", est introuvable.
echo บ Choisissez un nom dans la liste ci-dessus.                                  บ
echo บ                                                                             บ
echo บ    Exemple:  PP3SET F MCGA320                                               บ
echo ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
goto DONE

:FRNMSGBAD
echo ÿ
echo ÿ Le fichier de soutien "PP3S%1.MSG" n'existe pas.
echo ÿ
goto DONE

:FRNDONE
echo ÿ
echo ÿ Tapez "PP3" pour utiliser Personnalit+III.
echo ÿ Pour changer de nouveau le support de la carte graphique, tapez "PP3SET".
echo ÿ
goto DONE

REM **************************************************************************

:PROBLEM

Echo The setup file execution has detected an unexpected error.

:DONE
