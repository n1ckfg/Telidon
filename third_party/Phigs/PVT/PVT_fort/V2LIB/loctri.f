      SUBROUTINE LOCTRI (YLOC, XVAL)

C  LOCTRI draws a triangle using fill area set at the real
C  y-location corresponding to the integer index given in YLOC.
C  LOCTRI is normally used to display edges (unique to fill area
C  set, as opposed to simple fill area) rather than interiors.

      INTEGER    YLOC, NPTS(1)

      REAL       XVAL(3), YVAL(3), YLOCEL

      NPTS(1) = 3
      YVAL(2) = YLOCEL(YLOC) - .02
      YVAL(3) = YVAL(2)
      YVAL(1) = YVAL(2) + .035

      CALL PFAS (1, NPTS, XVAL,YVAL)

      END
