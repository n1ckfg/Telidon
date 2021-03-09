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
