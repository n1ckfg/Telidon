      SUBROUTINE LOCTX2 (YLOC, XVAL)

C  LOCTX2 draws a text string at the real y-location corresponding
C  to the integer index given in YLOC, and puts a polymarker at
C  the text position.

      INTEGER    YLOC

      REAL       XVAL, YLOCEL, XA(1),YA(1)

      XA(1) = XVAL
      YA(1) = YLOCEL(YLOC)
      CALL PPM (1, XA,YA)
      CALL PTX (XVAL, YLOCEL(YLOC), 'Phigs')

      END
