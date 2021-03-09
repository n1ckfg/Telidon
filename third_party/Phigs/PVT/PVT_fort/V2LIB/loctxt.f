      SUBROUTINE LOCTXT (YLOC, XVAL)

C  LOCTXT draws a text primitive at the real y-location
C  corresponding to the integer index given in YLOC.

      INTEGER   YLOC
      REAL      XVAL, YLOCEL

      CALL PTX (XVAL, YLOCEL(YLOC), 'Hi ho!')

      END
