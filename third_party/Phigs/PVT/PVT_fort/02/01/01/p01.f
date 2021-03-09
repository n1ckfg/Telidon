C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.01/01                           *
C  *    TEST TITLE : Structure creation by opening a       *
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
      INTEGER NSTID, NSTR, STRID, STRSTI, IDUM1
 
      CALL INITGL ('02.01.01/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('8', 'The CSS should be empty upon first ' //
     1             'opening PHIGS.')
      CALL PQSID  (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL IFPF   (NSTID .EQ. 0)
 
      CALL SETMSG ('1', 'Opening a non-existent structure ' //
     1             'should create one new structure '       //
     2             'with the specified identifier in '      //
     3             'the CSS.')
 
      STRID = 100
 
C open structure
      CALL POPST (STRID)
 
C nstid = number of structure identifiers
C nstr  = Nth structure identifier
      CALL PQSID  (1, ERRIND, NSTID, NSTR)
      CALL IFPF   (ERRIND .EQ. 0 .AND.
     1             NSTID  .EQ. 1 .AND.
     2             NSTR   .EQ. STRID)
 
      CALL SETMSG ('1', 'Opening a non-existent structure '    //
     1             'should create an empty structure '         //
     2             'with the specified identifier in '         //
     3             'the CSS.')
 
C strsti = structure status identifier
      CALL PQSTST (STRID, ERRIND, STRSTI)
      CALL IFPF   (ERRIND .EQ. 0  .AND.  STRSTI .EQ. PSEMPT)
C close structure
      CALL PCLST
 
      CALL SETMSG ('8', 'The CSS should be empty after closing and ' //
     1             're-opening PHIGS.')
      CALL PCLPH
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL PQSID  (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL IFPF   (NSTID .EQ. 0)
 
      CALL ENDIT
      END
