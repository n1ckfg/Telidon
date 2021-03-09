      SUBROUTINE RETOPN (STRID, ELPTR, STRELS)

C  RETOPN checks that the state of the open structure is as expected
C  and issues pass or fail as a result.  If there is an open
C  structure, it is closed by RETOPN

C  Input parameters:
C    strid  : expected open structure identifier
C    elptr  : expected value of element pointer
C    strels : expected contents of open structure

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER    STRID, ELPTR, OPSTAT, OPSTID, ERRIND

      CHARACTER  STRELS*(*)

      LOGICAL    STRCON

      CALL PQOPST (ERRIND, OPSTAT, OPSTID)
      CALL CHKINQ ('pqopst', ERRIND)

      IF (OPSTAT .EQ. POPNST) THEN
         IF (OPSTID .EQ. STRID) THEN
            IF (STRCON (STRID, STRELS)) THEN
               CALL CHKELP (ELPTR)
            ELSE
               CALL FAIL
               CALL INMSG ('Failed because of incorrect ' //
     1                     'structure contents.')
            ENDIF
         ELSE
            CALL FAIL
            CALL INMSG ('Failed because incorrect structure was open.')
         ENDIF
         CALL PCLST
      ELSE
         CALL FAIL
         CALL INMSG ('Failed because no structure was open.')
      ENDIF

      END
