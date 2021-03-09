      SUBROUTINE INMSG (MSG)

C INMSG is used to generate informational messages.

      CHARACTER  MSG*(*), BUF*900

      BUF = 'IN: ' // MSG
      CALL BRDMSG (BUF)

      END
