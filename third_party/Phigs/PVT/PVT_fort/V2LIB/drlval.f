      SUBROUTINE DRLVAL (PROMPT, ANS)

C  DRLVAL is used to get a real-number response from the operator.
C
C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    ANS         : valid answer from operator.

      INTEGER     IERR

      REAL        ANS

      CHARACTER   PROMPT*(*), RESP*100, MSG*100

110   CONTINUE
C  display prompt and get response string
      CALL DLINE (PROMPT, RESP)
      IF (RESP .EQ. ' ') THEN
         MSG = 'Response must be non-blank.'
      ELSE
         CALL PRSRL (RESP, ANS,IERR)
         IF (IERR .EQ. 0) THEN
            MSG = 'OK'
         ELSE
            MSG = 'Response not a real number.'
         ENDIF
      ENDIF

      IF (MSG .EQ. 'OK') THEN
C        OK - do nothing
      ELSE
C  show error message in dialogue area and pause
         CALL OPMSGW (MSG)
         GOTO 110
      ENDIF

      END
