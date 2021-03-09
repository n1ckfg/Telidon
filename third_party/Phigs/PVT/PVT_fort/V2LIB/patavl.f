      LOGICAL FUNCTION PATAVL (SPECWT)

C  PATAVL tests whether the PATTERN interior style is available for
C  a given workstation type.

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER   SPECWT, ISI, THISIS, NAINTS, ERRIND
      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4

C <inquire interior facilities> to determine if pattern is supported:
C  naints = number of available interior styles
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)

C loop thru list of available interior styles till find PPATTR
      DO 100 ISI = 1, NAINTS
         CALL PQIF (SPECWT, ISI, 0, ERRIND, IDUM1, THISIS, IDUM2,
     1              IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .EQ. PPATTR) THEN
            PATAVL = .TRUE.
            RETURN
         ENDIF
100   CONTINUE
      PATAVL = .FALSE.

      END
