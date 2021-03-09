      SUBROUTINE OPCO (TOPIC)

C  OPCO allows the operator to enter a character string as a
C  comment, which is then generated as an OP-type message.
C  If there is a current topical heading, it is prefixed to
C  the string.

      COMMON /OPCOMM/ OPHEAD
      CHARACTER  OPHEAD*300

      INTEGER    ITRIM, OPLEN
      CHARACTER  TOPIC*(*), PROMPT*300, RESP*900

      OPLEN = ITRIM(OPHEAD) + 1

      IF (TOPIC .EQ. ' ') THEN
         PROMPT = OPHEAD(:OPLEN) // 'Operator comment?'
      ELSE
         PROMPT = OPHEAD(:OPLEN) // 'Operator comment ' // TOPIC // '?'
      ENDIF

      CALL DSTRNG (PROMPT, RESP)
      IF (RESP .NE. ' ') THEN
         CALL BRDMSG ('OP: ' // OPHEAD(:OPLEN) // RESP)
      ENDIF

      END
