                                title MUSIC.ASM
;Copyright (C) 1990 by B. Simon and R. M. Wilson, all rights reserved.

      ;-----------------------------------------------------------------;
      ;             **  For use with STACKEY or DOS  **                 ;
      ;                                                                 ;
      ;  This file may be modified by assembly language programmers.    ;
      ;  You may change anything in the two boxes like this one.  That  ;
      ;  is, change the tempo and pitch just below, and the notes in    ;
      ;  the middle of this file.  (The note data alternates: pitches   ;
      ;  and note lengths.) Then assemble, link and exe2bin.  Run as a  ;
      ;  com file from DOS or as STACKEY ex(music.com)                  ;
      ;-----------------------------------------------------------------;

;-----------------------;
tempo=300               ;  increase to make tempo SLOWER
pitch=128               ;  increase to LOWER pitch
;-----------------------;

n1=16*tempo                  ;whole note       legato (full length)
n2=8*tempo                   ;half note        legato (full length)
n4=4*tempo                   ;quarter note     legato (full length)
n8=2*tempo                   ;eighth note      legato (full length)
n16=tempo                    ;sixteenth note   legato (full length)
n32=tempo/2                  ;32nd note        legato (full length)

n1d=16*tempo +4000h          ;whole note       detached (3/4 length)
n2d=8*tempo  +4000h          ;half note        detached (3/4 length)
n4d=4*tempo  +4000h          ;quarter note     detached (3/4 length)
n8d=2*tempo  +4000h          ;eighth note      detached (3/4 length)
n16d=tempo   +4000h          ;sixteenth note   detached (3/4 length)
n32d=tempo/2 +4000h          ;32nd note        detached (3/4 length)

n1s=16*tempo +8000h          ;whole note       staccato  (1/2 length)
n2s=8*tempo  +8000h          ;half note        staccato  (1/2 length)
n4s=4*tempo  +8000h          ;quarter note     staccato  (1/2 length)
n8s=2*tempo  +8000h          ;eighth note      staccato  (1/2 length)
n16s=tempo   +8000h          ;sixteenth note   staccato  (1/2 length)
n32s=tempo/2 +8000h          ;32nd note        staccato  (1/2 length)

rest= 0

; Just for fun, we use "just intonation".

c0=64*pitch
c1=32*pitch
c2=16*pitch
c3=8*pitch
c4=4*pitch
c5=2*pitch
c6=pitch

d1=32*pitch*8/9
d2=16*pitch*8/9
d3=8*pitch *8/9
d4=4*pitch *8/9
d5=2*pitch *8/9
d6=pitch   *8/9

e1=32*pitch*4/5
e2=16*pitch*4/5
e3=8*pitch *4/5
e4=4*pitch *4/5
e5=2*pitch *4/5
e6=pitch   *4/5

f1=32*pitch*3/4
f2=16*pitch*3/4
f3=8*pitch *3/4
f4=4*pitch *3/4
f5=2*pitch *3/4
f6=pitch   *3/4

g1=32*pitch*2/3
g2=16*pitch*2/3
g3=8*pitch *2/3
g4=4*pitch *2/3
g5=2*pitch *2/3
g6=pitch   *2/3

a1=32*pitch*3/5
a2=16*pitch*3/5
a3=8*pitch *3/5
a4=4*pitch *3/5
a5=2*pitch *3/5
a6=pitch   *3/5

bf1=32*pitch*9/16
bf2=16*pitch*9/16
bf3=8*pitch *9/16
bf4=4*pitch *9/16
bf5=2*pitch *9/16
bf6=pitch   *9/16

b1=32*pitch*8/15
b2=16*pitch*8/15
b3=8*pitch *8/15
b4=4*pitch *8/15
b5=2*pitch *8/15
b6=pitch   *8/15
;-------------------------------------------

cseg segment
        assume  cs:cseg

begin:
        xor dx,dx         ;Time the processor to get an approximate
        push ds           ;machine independent note length.
        xor ax,ax
        mov ds,ax
        mov al,byte ptr ds:[46CH]
      up2886:mov ah,byte ptr ds:[46CH]
        cmp ah,al
        je up2886
      inc9823: inc dx
        mov cx,4*138
      here6: loop here6
        mov al,byte ptr ds:[46CH]
        cmp al,ah
        je inc9823
        pop ds
        call overmusic

music label word
;----------------------------------------------------------------------;
        dw e2,n4d   ;Gavotte I from Bach's Orch. Suite #1 in C         ;
        dw f2,n4s                                                      ;
        dw g2,n4d                                                      ;
        dw a2,n8d, f2,n8d                                              ;
        dw g2,n4d, c2,n4s, a2,n4d, f2,n4s, d2,n4d, e2,n4s, f2,n4d      ;
        dw g2,n8d,e2,n8d,f2,n8d,d2,n8d,g2,n4s                          ;
        dw  f2,n16,e2,n16,f2,n16,e2,n16s   ;trill on e2,n4d            ;
        dw d2,n8,c2,n8d                                                ;
        dw f2,n8,e2,n8,d2,n8,c2,n8d                                    ;
        dw d2,n4d,e2,n8d,c2,n8d,d2,n8d,b1,n8d,e2,n4s                   ;
        dw  d2,n16,c2,n16,d2,n16,c2,n16s   ;trill on c2,n4d            ;
        dw b1,n8,a1,n8d                                                ;
        dw d2,n8,c2,n8,b1,n8,a1,n8d                                    ;
        dw d2,n4d,g2,n4s                                               ;
        dw  c2,n16,b1,n16,c2,n16,b1,n16s   ;trill on b1,n4d            ;
        dw a1,n8d,g1,n8s                                               ;
        dw g1,n2                                                       ;
                                                                       ;
   ;The following line is Pop Goes the Weasel, if you prefer that.     ;
        ;dw a2 ,n2s, d2 ,n4d, f2 ,n4s, e2 ,n2, c2 ,n2d                 ;
;----------------------------------------------------------------------;
        dw -1
overmusic: pop si     ;points to music
        shl dx,1
        mov word ptr ds:[offset timer2 +1-offset music+si],dx
     note: lodsw
        cmp ax,-1
        je done
        or ax,ax
        je ov2            ;rest
        mov cx,ds:[si]
        mov bx,cx
        and ch,0111111B
        mov dx,cx
        shr dx,1
        test bh,0C0h
        je ov3            ;legato if equal
        test bh,80h
        jne ov4           ;staccato if not equal
        shr dx,1          ;else detached
      ov4: sub cx,dx
        call setup
        call timer2
        mov cx,dx
        call timer2
        inc si
        inc si
        jmp note
      ov3: call setup
      ov2: push ax
        lodsw
        mov cx,ax
        pop ax
        call timer2
        jmp note
setup:  dec si
        dec si
        mov al,0b6H
        out 43H,al
        lodsb
        out 42H,al
        lodsb
        out 42H,al
        in al,61H
        or al,3
        out 61H,al
        ret
timer2: mov bx,0000     ;will be filled in with a number
      decbx: dec bx
        jg decbx
        loop timer2
        and al,0FDH     ;turn off speaker
        out 61H,al
    done: ret
cseg ends
end begin
