      SUBROUTINE EXPPPM (YLOC, XVAL, MKSTY, MWSC)

C  EXPPPM draws a polymarker with the expected marker type and
C  marker size.

      INTEGER    YLOC, MKSTY

      REAL       XVAL(2), MWSC

      CALL PSMK   (MKSTY)
      CALL PSMKSC (MWSC)
      CALL LOCPPM (YLOC, XVAL)

      END
