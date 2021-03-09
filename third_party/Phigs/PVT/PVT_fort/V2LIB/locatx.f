      SUBROUTINE LOCATX (YLOC, XVAL)

C  LOCATX draws an annotation text primitive at the real y-location
C  corresponding to the integer index given in YLOC.

      INTEGER   YLOC
      REAL      XVAL, YLOCEL

      CALL PATR (XVAL, YLOCEL(YLOC), 0.0,0.0, 'Hi ho!')

      END
