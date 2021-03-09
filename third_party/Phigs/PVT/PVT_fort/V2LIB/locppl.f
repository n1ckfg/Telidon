      SUBROUTINE LOCPPL (YLOC, XVAL)

C  LOCPPL draws a polyline at the real y-location corresponding to
C  the integer index given in YLOC.

      INTEGER    YLOC

      REAL       XVAL(2), YVAL(2), YLOCEL

      YVAL(1) = YLOCEL(YLOC)
      YVAL(2) = YVAL(1)
      CALL PPL (2, XVAL,YVAL)

      END
