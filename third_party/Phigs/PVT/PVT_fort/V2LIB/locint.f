      SUBROUTINE LOCINT (YLOC, XVAL)

C  LOCINT draws a fill area or fill area set at the real y-location
C  corresponding to the integer index given in YLOC.  It may be used
C  to check interiors.

      INTEGER    YLOC, NPTS(1)

      REAL       XVAL(4), YVAL(4), YLOCEL, YMID, YHALF

      NPTS(1) = 4
      YMID  = YLOCEL(YLOC)
      YHALF = 0.02
      YVAL(1) = YMID + YHALF
      YVAL(2) = YMID - YHALF
      YVAL(3) = YMID - YHALF
      YVAL(4) = YMID + YHALF

      IF (MOD(YLOC,2) .EQ. 0) THEN
         CALL PFA (4, XVAL,YVAL)
      ELSE
         CALL PFAS (1, NPTS, XVAL,YVAL)
      ENDIF

      END
