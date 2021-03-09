C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.01/05                           *
C  *    TEST TITLE : Structure creation by changing        *
C  *                 the structure identifier to a         *
C  *                 different value                       *
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
      INTEGER NSTID, NSTR, NWSTID, STRID, STRSTI
 
      CALL INITGL ('02.01.01/05')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('5', 'Changing a structure identifier with the '  //
     1             'original identifier having a different value '   //
     2             'than the resulting identifier should create '    //
     3             'one new structure with the resulting '           //
     4             'identifier in the CSS.')
 
      STRID  = 101
      NWSTID = 102
      CALL PCSTID (STRID, NWSTID)
 
C nstid = number of structure identifiers
C nstr  = Nth structure identifier
      CALL PQSID  (1, ERRIND, NSTID, NSTR)
      CALL IFPF   (ERRIND .EQ. 0 .AND.
     1             NSTID  .EQ. 1 .AND.
     2             NSTR   .EQ. NWSTID)
 
      CALL SETMSG ('5', 'Changing a structure identifier with '      //
     1             'the original identifier having a different '     //
     2             'value than the resulting identifier should '     //
     3             'create an empty structure with the resulting '   //
     4             'identifier in the CSS.')
 
      CALL PQSTST (NWSTID, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STRSTI .EQ. PSEMPT)
 
      CALL ENDIT
      END
 
