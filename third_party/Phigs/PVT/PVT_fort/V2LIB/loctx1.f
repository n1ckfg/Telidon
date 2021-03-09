      SUBROUTINE LOCTX1 (YLOC, XVAL, SCF)

C  LOCTX1 draws a text string at the real y-location corresponding
C  to the integer index given in YLOC, scaled down by SCF

      INTEGER    YLOC

      REAL       XVAL, YLOCEL, SCF

      CALL PTX (XVAL/SCF, YLOCEL(YLOC)/SCF, 'Phigs')

      END
