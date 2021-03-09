      SUBROUTINE DILIST (PROMPT, ANSSIZ, ANSLST)

C  DILIST is used to get an integer-list response from the operator.
C
C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    ANSSIZ      : size of list from operator.
C    ANSLST      : contents of list from operator

      CHARACTER   PROMPT*(*), RESP*100, MSG*100

      INTEGER     IERR, ANSSIZ, ANSLST(*)

110   CONTINUE
C  display prompt and get response string
      CALL DLINE (PROMPT, RESP)
      IF (RESP .EQ. ' ') THEN
         MSG = 'Response must be non-blank.'
      ELSEIF (RESP .EQ. 'N' .OR. RESP .EQ. 'n') THEN
C  null list
         ANSSIZ = 0
         MSG = 'OK'
      ELSE
         CALL INIARI (RESP, ANSLST, ANSSIZ, IERR)
         IF (IERR .EQ. 0) THEN
            MSG = 'OK'
         ELSE
            MSG = 'Invalid list.'
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
