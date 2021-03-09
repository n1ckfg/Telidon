      SUBROUTINE SETASF (FLAG)

C  SETASF sets all ASF flags to the same value, either individual or
C  bundled.

C aspect identifier
      INTEGER    PLN,      PEDCI
      PARAMETER (PLN  = 0, PEDCI=17)

      INTEGER   FLAG, ASPECT

      DO 50 ASPECT = PLN, PEDCI
         CALL PSIASF (ASPECT, FLAG)
50    CONTINUE

      END
