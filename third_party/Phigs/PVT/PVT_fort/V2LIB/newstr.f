      SUBROUTINE NEWSTR (START, NEWID)

C  NEWSTR searches for a non-existent structure identifier, starting
C  with START, and returns it, if found, in NEWID.

C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)

      INTEGER     START, NEWID, IX, STRSTI, ERRIND

      DO 100 IX = START, START+100
         CALL PQSTST (IX, ERRIND, STRSTI)
         CALL CHKINQ ('pqstst', ERRIND)
         IF (STRSTI .EQ. PSNOEX) THEN
            NEWID = IX
            RETURN
         ENDIF
100   CONTINUE
      CALL UNMSG ('NEWSTR cannot find a new structure identifier.')

      END
