      LOGICAL FUNCTION DYN (PROMPT)

C  DYN is used to ask the operator a yes/no question and return
C  a logical value as a result: .true. for yes, .false. for no.

C  Input parameters:
C    PROMPT      : prompt to be sent to operator.

      INTEGER     ITRIM

      CHARACTER   PROMPT*(*), LINEIN*100, MSGTXT*3000

C  display prompt
      MSGTXT = PROMPT(1:ITRIM(PROMPT)) // ' (y or n)'

100   CONTINUE
      CALL DLINE (MSGTXT, LINEIN)
      IF     (LINEIN.EQ.'Y' .OR. LINEIN.EQ.'y') THEN
         DYN = .TRUE.
      ELSEIF (LINEIN.EQ.'N' .OR. LINEIN.EQ.'n') THEN
         DYN = .FALSE.
      ELSE
C  show error message in dialogue area and pause
         CALL OPMSGW ('Response must be y or n.')
         GOTO 100
      ENDIF

      END
