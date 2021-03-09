C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.04.01/02                        *
C  *    TEST TITLE : Nameset facilities                    *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

      INTEGER    INTG, RL, STR, INLEN, STLEN, RELEN, LDR
      PARAMETER (INLEN=4100, STLEN=10, RELEN=50, LDR=20)

      INTEGER    NANAMS, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6
      INTEGER    NAMSET(INLEN), INTAR(INLEN), STRL2(STLEN), IX

      REAL       RLAR(RELEN)
      LOGICAL    SETEQ
      CHARACTER  DATREC(LDR)*80, MSG*300

      CALL INITGL ('04.03.04.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C <inquire PHIGS facilities> to determine
C  nanams = number of available names in namesets

      CALL PQPHF (1, ERRIND, IDUM1, IDUM2, NANAMS, IDUM3, IDUM4,
     1            IDUM5, IDUM6)
      CALL CHKINQ ('pqphf', ERRIND)

      CALL SETMSG ('7 8', 'The reported number of available names ' //
     1             'should be at least 64.')
      CALL IFPF (NANAMS .GE. 64)

      WRITE (MSG, '(A,I6)') 'Reported number of names = ', NANAMS
      CALL INMSG (MSG)

      NAMSET(1) = 0
      NAMSET(2) = NANAMS-1

      CALL POPST (1)

C  <add names to set>: 0, nanams-1
      CALL PADS (2,NAMSET)

      CALL SETMSG ('1 3 10', '<Inquire current element content> '   //
     1             'should return the standard representation for ' //
     2             'add names to set when the operand includes '    //
     3             'the minimum and maximum allowed value for a name.')

C  <inquire current element content> to determine celcon
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DATREC)
      CALL IFPF (ERRIND    .EQ.   0         .AND.
     1           INTG      .EQ.   2         .AND.
     2           SETEQ (2, INTAR, NAMSET)   .AND.
     3           RL        .EQ.   0         .AND.
     4           STR       .EQ.   0)

      IF (NANAMS .GT. INLEN) THEN
         CALL INMSG ('Number of available names is too large to ' //
     1               'allow testing of maximum size nameset.')
         GOTO 666
      ENDIF

C  <remove names to set>: all names from 0 to nanams-1
      DO 100 IX = 1,NANAMS
         NAMSET(IX) = NANAMS-IX
100   CONTINUE

      CALL PRES (NANAMS,NAMSET)

      CALL SETMSG ('4 6 8 10', '<Inquire current element content> ' //
     1             'should return the standard representation for ' //
     2             'remove names from set when the nameset '        //
     3             'contains the maximum number of names.')
C  <inquire current element content> to determine celcon
      CALL PQCECO (INLEN, RELEN, STLEN, ERRIND, INTG, INTAR,
     1             RL, RLAR, STR, STRL2, DATREC)
      CALL IFPF (ERRIND    .EQ.   0           .AND.
     1           INTG      .EQ.   NANAMS      .AND.
     2           SETEQ (NANAMS,INTAR,NAMSET)  .AND.
     3           RL        .EQ.   0           .AND.
     4           STR       .EQ.   0)

666   CONTINUE
C wrap it up
      CALL ENDIT
      END
