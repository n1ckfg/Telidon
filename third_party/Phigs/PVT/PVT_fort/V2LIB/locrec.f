      SUBROUTINE LOCREC (YLOC, XVAL, FAFAS)

C  LOCREC draws a rectangle at the real y-location corresponding to
C  the integer index given in YLOC.

C  Every 3rd rectangle is drawn with the FILL AREA primitive rather
C  than FILL AREA SET, as controlled by FAFAS

      INTEGER    YLOC, FAFAS
      REAL       XVAL(4)

      CALL PATREC (1.0, YLOC, XVAL, FAFAS)

      END
