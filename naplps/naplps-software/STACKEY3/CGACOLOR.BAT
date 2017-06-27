echo off
echo [0;40;37m
cls
stackey {cu=-}
echo This demonstration program will illustrate STACKEY's L command
echo on the CGA.  What it does depends on the mode.
echo:
echo  ENJOY THE DEMONSTRATION
stackey /u/   ;save values of flags to restore users options
stackey /i n/ ;turn off smart processing to prevent stray keypresses
stackey !     ;   and flush buffer from causing havoc; stop test mode
stackey {w=25}
cls
echo In text mode, the border color changes
stackey {w=32}L1{w=16}L2{w=16}L3{w=16}L4{w=16}L5{w=16}L6{w=16}L7{w=16}L8
stackey {w=16}L9{w=16}L10{w=16}L11{w=16}L12{w=16}L13{w=16}L14{w=16}L15{w=16}L0
cls
stackey {mode=4}
echo In medium resolution graphics mode, the
echo background and border color are changed
stackey {w=32}L1{w=16}L2{w=16}L3{w=16}L4{w=16}L5{w=16}L6{w=16}L7{w=16}L8
stackey {w=16}L9{w=16}L10{w=16}L11{w=16}L12{w=16}L13{w=16}L14{w=16}L15{w=16}L0
echo:
echo:
echo With the P command, you can change the
echo foreground palette of three colors
stackey {w=16}
stackey P0{w=32}L1{w=16}L2{w=16}L3{w=16}L4{w=16}L5{w=16}L6{w=16}L7{w=16}L8
stackey {w=16}L9{w=16}L10{w=16}L11{w=16}L12{w=16}L13{w=16}L14{w=16}L15{w=16}L0
if not exist boxes.com goto noboxes
boxes
stackey {w=20}P1{w=32}P0{w=32}P1{w=32}P0{w=32}
:noboxes
stackey {mode=6}
echo In high resolution graphics mode, the foreground color is changed
echo:
stackey {w=32}L1{w=16}L2{w=16}L3{w=16}L4{w=16}L5{w=16}L6{w=16}L7{w=16}L8
stackey {w=16}L9{w=16}L10{w=16}L11{w=16}L12{w=16}L13{w=16}L14{w=16}L15{w=16}
stackey {mode=3 cu=+}
stackey /o/ ; remember to restore the users options
echo [33;44;1m
cls

