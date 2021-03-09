      SUBROUTINE CHKELP (ELPOS)

C  Chkelp checks whether or not the current actual element position
C  equals the expected position, as indicated by the parameter,
C  and issues pass or fail as appropriate.  In the case of
C  failure, it attempts to re-set the pointer to the correct value.

      INTEGER  ELPOS, ACTPOS, ERRIND

      CALL PQEP (ERRIND, ACTPOS)
      CALL CHKINQ ('pqep', ERRIND)
      IF (ELPOS .EQ. ACTPOS) THEN
         CALL PASS
      ELSE
         CALL FAIL
         CALL PSEP (ELPOS)
      ENDIF

      END
