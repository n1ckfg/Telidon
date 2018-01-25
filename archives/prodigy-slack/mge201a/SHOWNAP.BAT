@echo off

  rem  Written by David R. Hughes III, August, 1991
  rem
  rem  Fido: 1:128/67
  rem  uucp: ..!oldcolo!david

  rem  A small batch example on how to display a Naplps graphics
  rem  file from a Door in a Dos based BBS.   This example was
  rem  implemented on a Remote Access BBS v. 1.01
  rem
  rem  The flow of this small batch file is to #1: send the 'toggle
  rem  Naplps mode ON' (to Naplps terminal software that will recognize
  rem  the 'toggle on' sequence, #2; display a preview Naplps file,
  rem  #3; display the Primary Naplps file, #4; pause the primary Naplps
  rem  display, #5; send the 'toggle Naplps modem OFF' code to switch
  rem  back to ansi mode (for Naplps terminal software that will
  rem  recognize the 'toggle off' sequence.
  rem
  rem  Place all files (nap.on, nap.off, pause.nap and shownap.bat)
  rem  in the BBS directory.
  rem
  rem  Edit the paths to locate nap.on and nap.off. . . currently
  rem  set for \ra\ directory.
  rem
  rem  Have a DOOR call the batch file with the following parameters:
  rem
  rem        shownap.bat port# none [/naplps/filename] [%4]
  rem
  rem  Where port# is the port number i.e. 1, 2, 3, etc. . .
  rem
  rem  'none' is a hook that if a valid Naplps path\filename existed,
  rem  would display a Naplps file before the main Naplps file
  rem  display. Enter 'none' if no preview Naplps filename is to be
  rem  displayed. . . This was implemented to allow for a short Naplps 
  rem  frame to display before the primary frame was displayed. . .
  rem
  rem  [/naplps/filename] is the actual path and filename of the primary
  rem  Naplps file to be displayed.
  rem
  rem  A forth variable [%4] can be entered.  'menu' will display a Preview
  rem  Naplps frame, the primary Naplps frame, then exit without
  rem  pausing the primary frame or without sending the Naplps toggle off
  rem  code.  
  rem
  rem  Also 'nooff' in the forth variable position will allow both Preview
  rem  and Primary Naplps Frames to display and then pause the Primary 
  rem  Display, but will not send the Naplps toggle off code.
  rem
  rem  This forth variable is optional.
  rem
  rem
  rem  Example Door line from RA v. 1.01, using a type 7 Door exit:
  rem
  rem   c:\command.com /c \ra\shownap.bat *P none \file\naplps\firework
  rem
  rem  This loads command.com and executes shownap.bat, *P inserts the
  rem  current Port number, 'none' means there is no Preview Naplps
  rem  frame, \file\naplps\firework is the Primary Naplps path and
  rem  filename.  There is no forth variable. . .

 
 type \ra\nap.on > com%1
 if exist %2 type %2 > com%1
 type %3 > com%1
 if "%4" == "menu" goto End
 if exist \ra\pause.nap type \ra\pause.nap > com%1

:NoOff
 if not "%4" == "nooff" type \ra\nap.off > com%1

:End

