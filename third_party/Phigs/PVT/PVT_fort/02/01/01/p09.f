C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.01/09                           *
C  *    TEST TITLE : Structure creation by changing        *
C  *                 structure identifier and references   *
C  *                 to the same value                     *
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
      INTEGER NSTID, NSTR, STRID, STRSTI
 
      CALL INITGL ('02.01.01/09')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('7', 'Changing structure identifier and '      //
     1             'references with the original identifier '     //
     2             'having the same value as the resulting '      //
     3             'identifier should create one new structure '  //
     4             'with the resulting identifier in the CSS.')
 
      STRID   = 10
      CALL PCSTIR (STRID, STRID)
 
C nstid = number of structure identifiers
C nstr  = Nth structure identifier
      CALL PQSID  (1, ERRIND, NSTID, NSTR)
      CALL IFPF   (ERRIND .EQ. 0 .AND.
     1             NSTID  .EQ. 1 .AND.
     2             NSTR   .EQ. STRID)
 
      CALL SETMSG ('7', 'Changing structure identifier and '      //
     1             'references with the original identifier '     //
     2             'having the same value as the resulting '      //
     3             'identifier should create an empty structure ' //
     4             'with the resulting identifier in the CSS.')
 
      CALL PQSTST (STRID, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF   (STRSTI .EQ. PSEMPT)
 
      CALL ENDIT
      END
 
