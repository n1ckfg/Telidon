      LOGICAL FUNCTION INTSTY (SPECWT, RQSTYL)

C  INTSTY indicates whether or not a requested interior style is
C  available for a workstation type.
C
C  Input parameters:
C    SPECWT : workstation type
C    RQSTYL : the interior style in question

      INTEGER  SPECWT, RQSTYL, IX, ERRIND, NIS, THISIS
      INTEGER  IDUM1,IDUM2,IDUM3,IDUM4

      CALL PQIF (SPECWT, 0,0, ERRIND, NIS, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)

      DO 100 IX = 1,NIS
         CALL PQIF (SPECWT, IX, 0, ERRIND,
     1              IDUM1, THISIS, IDUM2,IDUM3,IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .EQ. RQSTYL) THEN
            INTSTY = .TRUE.
            RETURN
         ENDIF
100   CONTINUE

      INTSTY = .FALSE.

      END
