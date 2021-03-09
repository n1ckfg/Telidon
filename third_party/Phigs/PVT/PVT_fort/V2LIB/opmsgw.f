      SUBROUTINE OPMSGW (MSG)

C  OPMSGW sends a character string (MSG) to the operator in
C  accordance with DOUTYP.  It then waits for a response, to ensure
C  that the message has been read.

      INTEGER    ITRIM
      CHARACTER  MSG*(*), PMSG*999, RESP*80

      PMSG = MSG(1:ITRIM(MSG)) // '  Enter anything to continue.'
      CALL DLINE (PMSG, RESP)

      END
