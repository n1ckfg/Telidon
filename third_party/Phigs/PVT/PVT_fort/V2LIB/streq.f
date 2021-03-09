      LOGICAL FUNCTION STREQ (REQ)

C  STREQ determines whether a required state is actually in force,
C  as reported by all the relevant inquire functions.
C
C  Input parameter:
C    REQ : 4-character code for required state, position 1-4 standing
C          for PHIGS, Workstation, Structure, and Archive, respectively.
C          Each position must be 'O', 'C', or '*', standing for open,
C          closed, and don't care.

C system state value
      INTEGER    PPHCL,     PPHOP
      PARAMETER (PPHCL = 0, PPHOP = 1)
C workstation state
      INTEGER    PWSCL,     PWSOP
      PARAMETER (PWSCL = 0, PWSOP = 1)
C structure state value
      INTEGER    PSTCL,     PSTOP
      PARAMETER (PSTCL = 0, PSTOP = 1)
C archive state
      INTEGER    PARCL,   PAROP
      PARAMETER (PARCL=0, PAROP=1)
C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER   PST,WST,SST,AST, NWK,NAR, OPSTAT, ERRIND
      INTEGER   IDUM1, IDUM2

      CHARACTER REQ*4

      STREQ = .FALSE.
      CALL PQSYS  (PST)
      CALL PQWKST (WST)
      CALL PQSTRS (SST)
      CALL PQARS  (AST)

      IF (REQ(1:1).EQ.'O') THEN
C  PHIGS should be open
         IF (PST.NE.PPHOP) RETURN
         IF (REQ(2:2).EQ.'*') THEN
C           don't care about workstation status
         ELSE
            CALL PQOPWK (0, ERRIND, NWK, IDUM1)
            CALL CHKINQ ('pqopwk', ERRIND)
            IF (REQ(2:2).EQ.'O') THEN
               IF (WST.NE.PWSOP) RETURN
               IF (NWK.LT.1)     RETURN
            ELSEIF (REQ(2:2).EQ.'C') THEN
               IF (WST.NE.PWSCL) RETURN
               IF (NWK.NE.0)     RETURN
            ELSE
               CALL UNMSG ('Second character of parameter to ' //
     1               'STREQ must be O or C or *.')
            ENDIF
         ENDIF

         IF (REQ(3:3).EQ.'*') THEN
C           don't care about structure status
         ELSE
            CALL PQOPST (ERRIND, OPSTAT, IDUM1)
            CALL CHKINQ ('pqopst', ERRIND)
            IF (REQ(3:3).EQ.'O') THEN
               IF (SST.NE.PSTOP)     RETURN
               IF (OPSTAT.NE.POPNST) RETURN
            ELSEIF (REQ(3:3).EQ.'C') THEN
               IF (SST.NE.PSTCL)     RETURN
               IF (OPSTAT.NE.PNONST) RETURN
            ELSE
               CALL UNMSG ('Third character of parameter to ' //
     1               'STREQ must be O or C or *.')
            ENDIF
         ENDIF

         IF (REQ(4:4).EQ.'*') THEN
C           don't care about archive status
         ELSE
            CALL PQARF (0, ERRIND, NAR, IDUM1,IDUM2)
            CALL CHKINQ ('pqarf', ERRIND)
            IF (REQ(4:4).EQ.'O') THEN
               IF (AST.NE.PAROP) RETURN
               IF (NAR.LT.1)     RETURN
            ELSEIF (REQ(4:4).EQ.'C') THEN
               IF (AST.NE.PARCL) RETURN
               IF (NAR.NE.0)     RETURN
            ELSE
               CALL UNMSG ('Fourth character of parameter to ' //
     1               'STREQ must be O or C or *.')
            ENDIF
         ENDIF

      ELSEIF (REQ(1:1).EQ.'C') THEN
C  PHIGS should be closed
         IF (REQ.NE.'CCCC') THEN
            CALL UNMSG ('STREQ parameter should be CCCC.')
         ENDIF
         IF (PST.NE.PPHCL) RETURN
         IF (WST.NE.PWSCL) RETURN
         IF (SST.NE.PSTCL) RETURN
         IF (AST.NE.PARCL) RETURN
      ELSE
         CALL UNMSG ('First character of parameter to STREQ must ' //
     1               'be O or C.')
      ENDIF

      STREQ = .TRUE.

      END
