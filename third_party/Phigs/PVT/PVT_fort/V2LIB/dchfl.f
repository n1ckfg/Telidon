      LOGICAL FUNCTION DCHFL (PROMPT, MAXVAL, TRUANS, PERM)

C  DCHFL gets an integer response from the operator, to be used as
C  an index into PERM, and, if the result is incorrect, issues fail
C  and returns TRUE.  If correct, it returns FALSE, but does not
C  issue pass.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.
C    PERM        : permutation of 1-MAXVAL, used to randomize prompt.

      INTEGER     TRUANS, MAXVAL, PERM(*), ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      IF (ANS .EQ. 0) THEN
         DCHFL = .TRUE.
         CALL OPFAIL
      ELSE
         IF (PERM(ANS) .EQ. TRUANS) THEN
            DCHFL = .FALSE.
         ELSE
            DCHFL = .TRUE.
            CALL FAIL
         ENDIF
      ENDIF

      END
