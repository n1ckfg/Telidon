      SUBROUTINE EXPPPL (YLOC, XVAL, LNSTY, LWSC)

C  EXPPPL draws a polyline with the expected linestyle and linewidth

      INTEGER    YLOC, LNSTY

      REAL       XVAL(2), LWSC

      CALL PSLN   (LNSTY)
      CALL PSLWSC (LWSC)
      CALL LOCPPL (YLOC, XVAL)

      END
