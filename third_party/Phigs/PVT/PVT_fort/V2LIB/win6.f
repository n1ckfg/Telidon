      SUBROUTINE WIN6 (STRID, COLI, XSIZ,YSIZ, XWINLO, YWINLO)

C  WIN6 sets up a structure which generates 6 labelled
C  windows on the screen.

C  Input parameters:
C    STRID         : Identifier of structure to contain windows
C    COLI          : Color index to be used
C  Output parameters:
C    XSIZ,YSIZ     : Size of windows
C    XWINLO,YWINLO : Location of lower left corner of windows

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)
C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    IX,IY,STRID, COLI, WINID

      REAL       TXHT, XSIZ,YSIZ, XWINLO(6), YWINLO(6)
      REAL       XA(2),YA(2), Z,U, XLOC,YLOC
      PARAMETER (Z = 0.0, U = 1.0)

      CHARACTER  DIG*1

      XSIZ = 0.3333
      YSIZ = 0.3333
      TXHT = 0.1666

      CALL POPST (STRID)
      CALL PSLWSC (0.0)
      CALL PSPLCI (COLI)
      CALL PSTXCI (COLI)
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (U)
      CALL PSCHH  (0.3 * TXHT)
      CALL PSCHUP (Z,U)
      CALL PSTXAL (PACENT, PATOP)
      WINID = 1
      DO 100 IY = 1,0,-1
         XA(1) = Z
         XA(2) = U
         YLOC = TXHT + IY*(YSIZ+TXHT)
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL (2, XA,YA)
         YA(1) = YLOC + YSIZ
         YA(2) = YA(1)
         CALL PPL (2, XA,YA)

      DO 200 IX = 0,3
         XLOC = IX*XSIZ
         YA(1) = YLOC
         YA(2) = YLOC + YSIZ
         XA(1) = XLOC
         XA(2) = XLOC
         CALL PPL (2, XA,YA)
         IF (IX .EQ. 3) GOTO 200

         XWINLO(WINID) = XLOC
         YWINLO(WINID) = YLOC
         WRITE (DIG, '(I1)') WINID
         CALL PTX (XLOC + XSIZ/2, YLOC - 0.1*TXHT, DIG)
         WINID = WINID+1
200   CONTINUE
100   CONTINUE

      CALL PCLST

      END
