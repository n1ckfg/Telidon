C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.01/07                           *
C  *    TEST TITLE : Structure creation by changing        *
C  *                 structure references                  *
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
      INTEGER NSTID, NSTR, NWSTID, STRID, STRID1, STRSTI, IDUM1, I
 
      CALL INITGL ('02.01.01/07')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('6', 'Changing structure references should '     //
     1             'create one new structure with the new '         //
     2             'identifier in the CSS when the new identifier ' //
     3             'refers to a non-existent structure and '        //
     4             'references to the original structure exist.')
 
      STRID   = 5
      STRID1  = 10
      NWSTID  = 20
 
      CALL POPST (STRID)
      CALL PEXST (STRID1)
      CALL PCSTRF (STRID1, NWSTID)
 
C nstid = number of structure identifiers
      CALL PQSID (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid',ERRIND)
      IF (NSTID .NE. 3) THEN
          CALL FAIL
          GOTO 300
      ENDIF
 
C nstr  = Nth structure identifier
      DO 100 I = 1, NSTID
         CALL PQSID (I, ERRIND, IDUM1, NSTR)
         CALL CHKINQ ('pqsid', ERRIND)
         IF (NSTR .EQ. NWSTID) THEN
            CALL PASS
            GOTO 300
         ENDIF
 100  CONTINUE
      CALL FAIL
 
 300  CONTINUE
      CALL SETMSG ('6', 'Changing structure references should '     //
     1             'create an empty structure with the new '        //
     2             'identifier in the CSS when the new identifier ' //
     3             'refers to a non-existent structure and '        //
     4             'references to the original structure exist.')
 
      CALL PQSTST (NWSTID, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STRSTI .EQ. PSEMPT)
 
      CALL ENDIT
      END
 
