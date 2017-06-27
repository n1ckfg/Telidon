                              title FLASH.ASM
;Copyright (C) 1990 by B. Simon and R. M. Wilson, all rights reserved.

onlyseg segment
        assume  cs:onlyseg

begin:                        ;DO NOT RUN FROM DOS!!
        mov es,ds:[40h]       ;STACKEY stores the segment of the screen
        call xorscreen        ;   memory at word ptr ds:[40h].
        xor cx,cx
      here: loop here
      xorscreen:  mov cx,8192
        mov si,1
      lp: xor byte ptr es:[si],07FH
        inc si
        inc si
        loop lp
        ret

onlyseg ends
end begin
