      SUBROUTINE DCHPF (PROMPT, MAXVAL, TRUANS, PERM)

C  DCHPF gets an integer response from the operator, to be used as
C  an index into PERM, and issues pass/fail as a result.  In all
C  cases the operator is given a choice between 0 and MAXVAL, where
C  0 indicates "none of the above" and triggers an operator comment.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    MAXVAL      : highest valid response.
C    TRUANS      : expected value from operator.
C    PERM        : permutation of 1-MAXVAL, used to randomize prompt.

      INTEGER     TRUANS, MAXVAL, PERM(*), ANS

      CHARACTER   PROMPT*(*)

      CALL DCHOIC (PROMPT, 0,MAXVAL, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPFAIL
      ELSE
         CALL IFPF (PERM(ANS) .EQ. TRUANS)
      ENDIF

      END
