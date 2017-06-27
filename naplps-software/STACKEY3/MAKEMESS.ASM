                              title MAKEMESS.ASM
;Copyright (C) 1990 by B. Simon and R. M. Wilson, all rights reserved.

      ;--------------------------------------------------------------;
      ; This file may be modified by assembly language programmers.  ;
      ; You may change anything in boxes like this one.              ;
      ; But BE CAREFUL.  Then assemble, link, and exe2bin and        ;
      ; rename to message.bin or sample.msg (or whatever you like).  ;
      ;                    DO NOT RUN FROM DOS!!!                    ;
      ;                                                              ;
      ; Example:                                                     ;
      ;   STACKEY  ex(sample.msg) :1 be 'yes' j0  :2 'no'            ;
      ;                                                              ;
      ; (The "findlabel" procedure below may be incorporated into    ;
      ; other external programs to be called by STACKEY.)            ;
      ;--------------------------------------------------------------;

;--------------------------;
main_attribute = 30h       ;
border = 3bh               ;
screen_offset = 660        ;
;--------------------------;

cseg segment
        assume  cs:cseg

begin:  mov dx,offset endmess-offset beginmess
        mov es,ds:[40h]          ;segment of screen
        add si, offset beginmess-offset begin
        add si,dx
        mov bx,si                ;now points to endmess
        push di

        mov di,screen_offset     ;save user's screen
        call savesc
        mov di,160+screen_offset
        call savesc
        mov di,320+screen_offset
        call savesc

        mov ah,border            ;draw box and print message
        mov di,screen_offset
        mov al,'É'
        stosw
        mov al,'Í'
        mov cx,dx
        rep stosw
        mov al,'»'
        stosw
        mov di,160+screen_offset
        mov al,'º'
        stosw
        add di,dx
        add di,dx
        stosw
        mov di,320+screen_offset
        mov al,'È'
        stosw
        mov al,'Í'
        mov cx,dx
        rep stosw
        mov al,'¼'
        stosw
        mov ah,main_attribute
        mov di,162+screen_offset
        mov si,bx
        sub si,dx                ;points to beginmess
        mov cx,dx
      loopy: lodsb
        stosw
        loop loopy
        mov si, bx               ;offset endmess for restoring later

        xor bx,bx
      getkey:  xor ah,ah
        int 16h

;-----------------------------------------------------------------;
;  Change stuff between these lines.  For example, you could say  ;
       ; or al,20H                                                ;
       ; cmp al,'a'                                               ;
       ; je label0                                                ;
       ; cmp al,'b'                                               ;
       ; je label1                                                ;
       ; cmp al,'c'                                               ;
       ; je label2                                                ;
       ; cmp al,'d'                                               ;
       ; je label3                                                ;
       ; cmp al,'e'                                               ;
       ; je label4                                                ;
       ; cmp al,'f'                                               ;
       ; je label5                                                ;
       ; cmp al,'g'                                               ;
       ; je label6                                                ;
       ; cmp al,'h'                                               ;
       ; je label7                                                ;
       ; cmp al,'i'                                               ;
       ; je label8                                                ;
       ; cmp al,'j'                                               ;
       ; je label9                                                ;
                                                                  ;
        cmp al,1bh   ;esc                                         ;
        je label0                                                 ;
        or al,20H    ;force lower case                            ;
        cmp al,'y'                                                ;
        je label1                                                 ;
        cmp al,'n'                                                ;
        je label2                                                 ;
;-----------------------------------------------------------------;
        jmp getkey

      label9:  inc bx
      label8:  inc bx
      label7:  inc bx
      label6:  inc bx
      label5:  inc bx
      label4:  inc bx
      label3:  inc bx
      label2:  inc bx
      label1:  inc bx
      label0:

        mov di,screen_offset
        call restsc
        mov di,160+screen_offset
        call restsc
        mov di,320+screen_offset
        call restsc
        pop di
        jmp findlabel

      savesc: mov cx,dx
        inc cx
        inc cx
      savesc2:  mov ax,es:[di]
        inc di
        inc di
        mov ds:[si],ax
        inc si
        inc si
        loop savesc2
        ret
      restsc: mov cx,dx
        inc cx
        inc cx
        rep movsw
        ret

      findlabel: mov bh,0ffh     ;Jumps to label number bl on the STACKEY
        mov si,ds:[6eh]          ;   command line.
      comp: cmp si,ds:[74h]
        jae foundlabel
        lodsw
        cmp ax,bx
        je foundlabel
        cmp ah,0f1h              ;code for inline
        jne comp
        lodsw
        sub ax,4
        add si,ax
        jmp comp
      foundlabel: mov ds:[72h],si
        ret

;--------------------------------------------------;
beginmess db 'Press <y> for Yes, <n> for No.'      ; At most 78 bytes.
;--------------------------------------------------;

endmess dw 3*(2+$-offset beginmess) dup(0)

        ret      ;just for form

cseg ends
end begin
