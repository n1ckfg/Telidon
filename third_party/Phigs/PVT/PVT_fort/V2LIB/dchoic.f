      SUBROUTINE DCHOIC (PROMPT, LOLIM, HILIM, ANS)

C  DCHOIC is used to get an integer response from the operator.
C
C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C    LOLIM,HILIM : low, high limit (inclusive) for answer.
C  Output parameters:
C    ANS         : valid answer from operator.

      INTEGER     LOLIM,HILIM, ANS, IERR

      CHARACTER   PROMPT*(*), RESP*100, MSG*100

110   CONTINUE
C  display prompt and get response string
      CALL DLINE (PROMPT, RESP)
      IF (RESP .EQ. ' ') THEN
         MSG = 'Response must be non-blank.'
      ELSE
         CALL PRSINT (RESP, ANS,IERR)
         IF (IERR .EQ. 0) THEN
            IF (ANS.GE.LOLIM .AND. ANS.LE.HILIM) THEN
               MSG = 'OK'
            ELSE
               MSG = 'Response out of range.'
            ENDIF
         ELSE
            MSG = 'Response not an integer.'
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
