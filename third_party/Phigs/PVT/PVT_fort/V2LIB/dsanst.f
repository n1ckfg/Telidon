      SUBROUTINE DSANST (LSIZ, LANST)

C  DSANST accepts a list of annotation styles and displays at most 8
C  of them.

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

      INTEGER    LSIZ, LANST(LSIZ), NUMDIS, IX, PERM(10), LDIS(10)

      REAL       XA(10),YA(10),XO(10),YO(10)
      REAL       NPCX,NPCY,NPCPWC, YINCR,YLOC, ANOFFX,ANOFFY

      CHARACTER  ANSTID*11

      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

      NUMDIS = MIN(8, LSIZ)
      CALL RNSET (NUMDIS, LSIZ, PERM)

C  build list of annotation styles to be displayed
      DO 100 IX = 1,NUMDIS
         LDIS(IX) = LANST(PERM(IX))
100   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, LDIS)

C  display in order and label all annotation styles in ldis
      YINCR = MIN (0.25, 1.0 / (LSIZ+1))
      YLOC  = 1 - YINCR
C  annotation offsets in WC
      ANOFFX = 0.2
      ANOFFY = 0.3 * YINCR
      DO 220 IX = 1,NUMDIS
C  mark reference and annotation point
         XO(IX) = 0.6
         YO(IX) = YLOC
         XA(IX) = XO(IX) - ANOFFX
         YA(IX) = YO(IX) - ANOFFY

         WRITE (ANSTID, '(A,I5,A)') 'Type#', LDIS(IX), ':'
         CALL VISLAB (ANSTID, 'R', 0.05,0.35,
     1                YLOC-0.3*YINCR, YLOC+0.3*YINCR)

         CALL PSANS (LDIS(IX))
         CALL PATR (XA(IX), YA(IX), ANOFFX*NPCPWC, ANOFFY*NPCPWC, 'abc')
         YLOC = YLOC-YINCR
220   CONTINUE
      CALL PSMK (PAST)
      CALL PPM  (NUMDIS, XA,YA)
      CALL PSMK (POMARK)
      CALL PPM  (NUMDIS, XO,YO)

      END
