      SUBROUTINE ENDIT

C  ENDIT performs all normal close-out chores for a PVT test:
C  it clears and closes all open workstations, closes the open
C  structure if there is one, closes PHIGS and issues WINDUP.

C system state value
      INTEGER    PPHCL,     PPHOP
      PARAMETER (PPHCL = 0, PPHOP = 1)

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER    WKID, ERRIND, NUMWK, OPSTAT, IX, SYSST, IDUM

C  check if PHIGS open
      CALL PQSYS (SYSST)
      IF (SYSST .EQ. PPHCL) GOTO 666

C  close all open workstations
      CALL PQOPWK (0, ERRIND, NUMWK, IDUM)
      CALL CHKINQ ('pqopwk', ERRIND)
      DO 100 IX = 1,NUMWK
C  always delete 1st element of remaining list - list changes each
C  time thru loop because of call to PCLWK
         CALL PQOPWK (1, ERRIND, IDUM, WKID)
         CALL CHKINQ ('pqopwk', ERRIND)
         CALL PUPAST (WKID)
         CALL PCLWK  (WKID)
100   CONTINUE

C  close open structure
      CALL PQOPST (ERRIND, OPSTAT, IDUM)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL PCLST
      ENDIF
      CALL PCLPH

666   CONTINUE
      CALL WINDUP

      END
