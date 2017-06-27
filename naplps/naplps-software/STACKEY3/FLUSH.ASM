                              title FLUSH.ASM
;Copyright (C) 1990 by B. Simon and R. M. Wilson, all rights reserved.

cseg segment
        assume  cs:cseg

begin:  mov al,0AEH
        out 64H,al
        xor cx,cx
      here: loop here
        mov ah,1
        int 16h
        jz nomore
        xor ah,ah
        int 16h
        jmp short begin
      nomore: ret

cseg ends
end begin
