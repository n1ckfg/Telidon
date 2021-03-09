      SUBROUTINE OPINT (IANS)

C  OPINT gets an integer response from the operator.

      INTEGER    IANS, LEADNB, ITRIM, IERR
      CHARACTER  CANS*40

10    CONTINUE
      CALL OPLIN (CANS)
      IF (CANS .EQ. ' ') THEN
         CALL OPMSG ('Response must be a non-blank valid integer.  ' //
     1               'Re-enter.')
         GOTO 10
      ENDIF

      CALL PRSINT (CANS(LEADNB(CANS):ITRIM(CANS)), IANS, IERR)
      IF (IERR .NE. 0) THEN
         CALL OPMSG ('Response must be a non-blank valid integer.  ' //
     1               'Re-enter.')
         GOTO 10
      ENDIF

      END
