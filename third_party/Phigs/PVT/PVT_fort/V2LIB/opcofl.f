      SUBROUTINE OPCOFL

C  OPCOFL allows the operator to enter a character string as a
C  comment, by using OPCO.  The comment is made in anticipation
C  of failure of the current test case.

      CALL OPCO ('on failure')
      END
