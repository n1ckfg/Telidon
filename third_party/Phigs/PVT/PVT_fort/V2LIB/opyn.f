      SUBROUTINE OPYN (PROMPT, ANS)

C opyn gets a yes or no reply from operator - encoded as y or n.

      CHARACTER PROMPT*(*), ANS*1, BUF*132

800   FORMAT(A)

100   CONTINUE
      BUF = PROMPT // ' (y or n)'
      CALL OPMSG (BUF)
      READ (*, 800) ANS
      IF (ANS .EQ. 'y' .OR. ANS .EQ. 'n') RETURN
      CALL OPMSG ('Response must be y or n.')
      GOTO 100

      END
