      SUBROUTINE LOCPPM (YLOC, XVAL)

C  LOCPPM draws a polymarker at the real y-location corresponding to
C  the integer index given in YLOC.

      INTEGER    YLOC

      REAL       XVAL(1), YVAL(1), YLOCEL

      YVAL(1) = YLOCEL(YLOC)
      CALL PPM (1, XVAL,YVAL)

      END
