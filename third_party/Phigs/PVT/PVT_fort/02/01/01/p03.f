C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.01/03                           *
C  *    TEST TITLE : Structure creation by executing a     *
C  *                 non-existent structure                *
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
 
 
      INTEGER    PSEMPT
      PARAMETER (PSEMPT = 1)
 
C PHIGS parameter types
      INTEGER NSTID, NSTR1, NSTR2, RSTRID, STRID, STRSTI,
     1        IDUM1, IDUM2
 
      CALL INITGL ('02.01.01/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('3', 'Executing a non-existent structure ' //
     1             'should create a new structure with '      //
     2             'the specified identifier in the CSS.')
 
      RSTRID  = 101
      STRID   = 102
C open structure
      CALL POPST (RSTRID)
 
C execute structure
      CALL PEXST (STRID)
 
C close structure
      CALL PCLST
 
C nstid = number of structure identifiers
      CALL PQSID  (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      IF (NSTID .NE. 2)  THEN
          CALL FAIL
          GOTO 100
      ENDIF
 
C nstr  = Nth structure identifier
      CALL PQSID  (1, ERRIND, IDUM1, NSTR1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL PQSID  (2, ERRIND, IDUM2, NSTR2)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL IFPF   (NSTR1 .EQ. STRID .OR. NSTR2 .EQ. STRID)
 
100   CONTINUE
      CALL SETMSG ('3', 'Executing a non-existent structure '    //
     1             'should create an empty structure '           //
     2             'with the specified identifier in '           //
     3             'the CSS.')
 
C strsti = structure status identifier
      CALL PQSTST (STRID, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF   (STRSTI .EQ. PSEMPT)
 
666   CONTINUE
      CALL ENDIT
      END
 
