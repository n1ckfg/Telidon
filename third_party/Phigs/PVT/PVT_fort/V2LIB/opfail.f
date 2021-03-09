      SUBROUTINE OPFAIL

C  OPFAIL allows the operator to enter a character string as a
C  comment, by using OPCO, and then issues a failure.

      CALL OPCOFL
      CALL FAIL

      END
