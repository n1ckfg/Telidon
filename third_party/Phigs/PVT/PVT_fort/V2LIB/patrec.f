      SUBROUTINE PATREC (SCF, YLOC, XVAL, FAFAS)

C  PATREC draws a rectangle at the real y-location corresponding to
C  the integer index given in YLOC, but scaled to allow for current
C  transformation by SCF.

C  Every 3rd rectangle is drawn with the FILL AREA primitive rather
C  than FILL AREA SET, as controlled by FAFAS

      INTEGER    YLOC, NPTS(1), FAFAS, IX

      REAL       XVAL(4), XWK(4), YVAL(4), YLOCEL, SCF

      NPTS(1) = 4
      YVAL(2) = (YLOCEL(YLOC) - .02) / SCF
      YVAL(3) = YVAL(2)
      YVAL(1) = YVAL(2) + .045/SCF
      YVAL(4) = YVAL(1)
      DO 10 IX = 1,4
         XWK(IX) = XVAL(IX)/SCF
10    CONTINUE

      IF ((MOD(FAFAS, 3) .EQ. 0)) THEN
         CALL PFA (NPTS(1), XWK, YVAL)
      ELSE
         CALL PFAS (1, NPTS, XWK,YVAL)
      ENDIF

      END
