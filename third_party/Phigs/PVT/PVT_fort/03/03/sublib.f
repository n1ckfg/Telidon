C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 03.03/cssids                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION CSSIDS (IDSTR)

C  This routine checks the actual set of structure identifiers in
C  the CSS against an expected list, encoded in idstr.  If equal it
C  returns true, else false.

      INTEGER    ARRSIZ, IDUM, IX, ERRIND
      PARAMETER (ARRSIZ = 300)

      INTEGER    EXPIDS(ARRSIZ), EXPSIZ, ACTIDS(ARRSIZ), ACTSIZ
      CHARACTER  IDSTR*(*)
      LOGICAL    SETEQ

      CALL SETVS (IDSTR, EXPIDS, EXPSIZ)
      IF (EXPSIZ .GT. ARRSIZ) THEN
         CALL UNMSG ('Expected size exceeds limits of CSSIDS.')
      ENDIF

C  <inquire structure identifiers> to determine actual list of structures
      CALL PQSID (0, ERRIND, ACTSIZ, IDUM)
      CALL CHKINQ ('pqsid', ERRIND)
      IF (ACTSIZ .NE. EXPSIZ) THEN
         CSSIDS = .FALSE.
         RETURN
      ENDIF
      IF (ACTSIZ .GT. ARRSIZ) THEN
         CALL UNMSG ('Actual size exceeds limits of CSSIDS.')
      ENDIF

      DO 100 IX = 1,ACTSIZ
         CALL PQSID (IX, ERRIND, IDUM, ACTIDS(IX))
         CALL CHKINQ ('pqsid', ERRIND)
100   CONTINUE

      CSSIDS = SETEQ (ACTSIZ, ACTIDS, EXPIDS)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 03.03/retopn                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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
