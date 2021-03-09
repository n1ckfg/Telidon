C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.03/setpst                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETPST (NUMSTR, STRID, NUMWKS, ACWKID, STINWK)

C  SETPST sets up the complete state of posting among a set
C  of structures and workstations.

C  ------- INPUT PARAMETERS
C  numstr   : number of structures
C  strid    : list of structure identifiers
C  numwks   : number of workstations
C  acwkid   : list of workstation identifiers
C  stinwk   : 2D array, indicating what is to be posted

      INTEGER     NUMSTR, STRID(NUMSTR), NUMWKS, ACWKID(NUMWKS)
      INTEGER     STINWK(NUMSTR, NUMWKS), IWK, ISTR

      DO 100 IWK = 1, NUMWKS
         CALL PUPAST (ACWKID(IWK))
         DO 200 ISTR = 1, NUMSTR
            IF (STINWK (ISTR, IWK) .EQ. 1) THEN
               CALL PPOST (ACWKID(IWK), STRID(ISTR), 1.0)
            ENDIF
200      CONTINUE
100   CONTINUE
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 05.03/chkpst                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1                   LWPCOD, LPSCOD)

C  CHKPST checks the complete actual state of posting among a set
C  of structures and workstations against the expected state.

C  ------- INPUT PARAMETERS
C  numstr   : number of structures
C  strid    : list of structure identifiers
C  numwks   : number of workstations
C  acwkid   : list of workstation identifiers
C  stvswk   : 2D array, indicating expected posted state

C  ------- OUTPUT PARAMETERS
C  lwpcod   : validity of lists of workstations to which posted
C  lpscod   : validity of lists of posted structures

      INTEGER     NUMSTR, STRID(NUMSTR), NUMWKS, ACWKID(NUMWKS)
      INTEGER     STVSWK(NUMSTR, NUMWKS), IWK, ISTR, IDUM1, ERRIND
C  actual, expected list of workstations to which posted
      INTEGER     ACTLWP(10), EXPLWP(10), EXPSIZ,ACTSIZ
C  actual, expected list of posted structures
      INTEGER     ACTLPS(10), EXPLPS(10)

      REAL        DISPRI

      LOGICAL     LWPCOD, LPSCOD, SETEQ

C  check list of workstations to which posted
      DO 100 ISTR = 1, NUMSTR
C  construct expected lwp
         EXPSIZ = 0
         DO 110 IWK = 1,NUMWKS
            IF (STVSWK(ISTR,IWK) .EQ. 1) THEN
C  add workstation to expected list
               EXPSIZ = EXPSIZ+1
               EXPLWP(EXPSIZ) = ACWKID(IWK)
            ENDIF
110      CONTINUE

         CALL PQWKPO (STRID(ISTR), 0, ERRIND, ACTSIZ, IDUM1)
         IF (ERRIND .EQ. 0 .AND. ACTSIZ .EQ. EXPSIZ) THEN
C           OK so far
         ELSE
            LWPCOD = .FALSE.
            GOTO 190
         ENDIF
C  construct actual lwp
         DO 120 IWK = 1,ACTSIZ
            CALL PQWKPO (STRID(ISTR), IWK, ERRIND, IDUM1, ACTLWP(IWK))
            IF (ERRIND .NE. 0) THEN
               LWPCOD = .FALSE.
               GOTO 190
            ENDIF
120      CONTINUE
         IF (.NOT. SETEQ(ACTSIZ, ACTLWP, EXPLWP)) THEN
            LWPCOD = .FALSE.
            GOTO 190
         ENDIF
100   CONTINUE
      LWPCOD = .TRUE.
190   CONTINUE

C  check list of posted structures
      DO 200 IWK = 1,NUMWKS
C  construct expected lps
         EXPSIZ = 0
         DO 210 ISTR = 1,NUMSTR
            IF (STVSWK(ISTR,IWK) .EQ. 1) THEN
C  add structure to expected list
               EXPSIZ = EXPSIZ+1
               EXPLPS(EXPSIZ) = STRID(ISTR)
            ENDIF
210      CONTINUE

         CALL PQPOST (ACWKID(IWK), 0, ERRIND, ACTSIZ, IDUM1, DISPRI)
         IF (ERRIND .EQ. 0 .AND. ACTSIZ .EQ. EXPSIZ) THEN
C           OK so far
         ELSE
            LPSCOD = .FALSE.
            GOTO 290
         ENDIF
C  construct actual lps
         DO 220 ISTR = 1,ACTSIZ
            CALL PQPOST (ACWKID(IWK), ISTR,
     1                   ERRIND, IDUM1, ACTLPS(ISTR), DISPRI)
            IF (ERRIND .NE. 0) THEN
               LPSCOD = .FALSE.
               GOTO 290
            ENDIF
220      CONTINUE
         IF (.NOT. SETEQ(ACTSIZ, ACTLPS, EXPLPS)) THEN
            LPSCOD = .FALSE.
            GOTO 290
         ENDIF
200   CONTINUE
      LPSCOD = .TRUE.
290   CONTINUE

      END
