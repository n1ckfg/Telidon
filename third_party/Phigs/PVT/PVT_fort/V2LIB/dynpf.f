      SUBROUTINE DYNPF (PROMPT, EXPCTD)

C  DYNPF is used to ask the operator a yes/no question and issue pass
C  or fail as a result.  If the answer indicates failure, the operator
C  is given the opportunity to comment.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    EXPCTD      : expected answer (to pass) - must be y or n

      CHARACTER   PROMPT*(*), EXPCTD*1

      LOGICAL     EXPY, DYN

      IF     (EXPCTD.EQ.'Y' .OR. EXPCTD.EQ.'y') THEN
         EXPY = .TRUE.
      ELSEIF (EXPCTD.EQ.'N' .OR. EXPCTD.EQ.'n') THEN
         EXPY = .FALSE.
      ELSE
         CALL UNMSG ('DYNPF called with invalid value: ' // EXPCTD)
      ENDIF

      IF (EXPY .EQV. DYN (PROMPT)) THEN
         CALL PASS
      ELSE
         CALL OPFAIL
      ENDIF

      END
