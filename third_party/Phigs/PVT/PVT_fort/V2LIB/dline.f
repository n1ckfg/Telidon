      SUBROUTINE DLINE (PROMPT, RESP)

C  DLINE issues a prompt to the operator and gets a single line
C  character string response.  If the operator responds with
C  the escape character "@", DLINE allows entry of a non-committal
C  operator comment (neither pass nor fail), to be sent out as
C  an OP message, and then re-issues the original prompt.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.
C  Output parameters:
C    RESP        : answer from operator.

      CHARACTER   PROMPT*(*), RESP*(*)

100   CONTINUE
      CALL IACMSG (PROMPT)
      CALL IACANS (RESP)

C  allow operator-requested comment.
      IF (RESP .EQ. '@') THEN
         CALL OPCOMT
         GOTO 100
      ENDIF

      END
