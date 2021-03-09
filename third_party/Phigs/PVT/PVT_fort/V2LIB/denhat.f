      SUBROUTINE DENHAT (STRID, MAXH, SPECWT, IHAT)

C  DENHAT displays a random selection of hatch styles and asks the
C  operator to select a dense one.

C  Input parameters:
C    STRID  : identifier for available closed posted structure
C    MAXH   : maximum number of styles to display
C    SPECWT : specific workstation type
C  Output parameters:
C    IHAT   : selected hatch style

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER   STRID, MAXH, SPECWT, IHAT, NUMHS, NUMLIN, PERM(100)
      INTEGER   ERRIND, HS(100), IX, ANS
      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4

      REAL      YINCR,YTOP,YLOC, XA(4),YA(4)

      CALL POPST (STRID)
      CALL PQIF (SPECWT,0,0,ERRIND, IDUM1,IDUM2, NUMHS,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
      NUMLIN = MIN(MAXH, ABS(NUMHS))
      CALL RNSET (NUMLIN, ABS(NUMHS), PERM)
      YINCR = 1 / (NUMLIN+1.0)
      YTOP  = 1 - YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      CALL PSIS (PHATCH)
      XA(1) = 0.2
      XA(2) = 0.9
      XA(3) = 0.9
      XA(4) = 0.2
      DO 60 IX = 1,NUMLIN
         YA(1) = YLOC + 0.4*YINCR
         YA(2) = YLOC + 0.4*YINCR
         YA(3) = YLOC - 0.4*YINCR
         YA(4) = YLOC - 0.4*YINCR
         CALL PQIF (SPECWT,0,PERM(IX), ERRIND,
     1              IDUM1,IDUM2,IDUM3,HS(IX),IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         CALL PSISI (HS(IX))
         CALL PFA (4, XA,YA)
         YLOC = YLOC-YINCR
60    CONTINUE
      CALL DCHOIC ('Pick a dense hatch style, preferably diagonal.',
     1             1, NUMLIN, ANS)
      CALL PEMST (STRID)
      CALL PCLST
      IHAT = HS(ANS)

      END
