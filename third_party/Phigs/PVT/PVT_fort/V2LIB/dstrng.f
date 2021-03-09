      SUBROUTINE DSTRNG (PROMPT, RESP)

C  DSTRNG is used to get possibly multi-line character string
C  response from the operator.  Operator response is terminated
C  by a single "." on a line.  This termination line is not
C  included in the response.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    RESP        : answer from operator.

      INTEGER     ITRIM, NXTPOS

      CHARACTER   PROMPT*(*), RESP*(*), LINEIN*200

C  display prompt
      CALL IACMSG (PROMPT)
      NXTPOS = 1
      RESP = ' '

100   CONTINUE
C  get response string
      CALL IACANS (LINEIN)
      IF (LINEIN .EQ. '.') GOTO 200
C  append last line to non-blank stuff in RESP
      RESP (NXTPOS:) = LINEIN
      NXTPOS = ITRIM(RESP) + 2
C  check if at or near overflow ...
      IF (NXTPOS+5 .LT. LEN(RESP)) GOTO 100

200   CONTINUE

      END
