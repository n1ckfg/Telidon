      SUBROUTINE LOCAT2 (YLOC, XVAL)

C  LOCAT2 draws an annotation text string at the real y-location
C  corresponding to the integer index given in YLOC, and puts a
C  polymarker at the text position.

      INTEGER    YLOC

      REAL       XVAL, YLOCEL, XA(1),YA(1)

      XA(1) = XVAL
      YA(1) = YLOCEL(YLOC)
      CALL PPM (1, XA,YA)
      CALL LOCATX (YLOC, XVAL)

      END
