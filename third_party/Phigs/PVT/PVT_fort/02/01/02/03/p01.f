C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.03/01                        *
C  *    TEST TITLE : Deletion of all closed structures     *
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
 
C PHIGS parameter types
 
      INTEGER NSTID, IDUM1
 
      CALL INITGL ('02.01.02.03/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C creation of structures
      CALL POPST (100)
      CALL PEXST (103)
      CALL PEXST (104)
      CALL PCLST
      CALL POPST (103)
      CALL PEXST (105)
      CALL PEXST (105)
      CALL PCLST
      CALL POPST (104)
      CALL PEXST (106)
      CALL PCLST
      CALL POPST (106)
      CALL PEXST (107)
      CALL PEXST (108)
      CALL PCLST
      CALL POPST (102)
      CALL PEXST (106)
      CALL PEXST (109)
      CALL PCLST
      CALL POPST (109)
      CALL PEXST (108)
      CALL PEXST (110)
      CALL PCLST
 
 
      CALL SETMSG ('1', '<Delete all structures> should remove all ' //
     1             'the closed structures contained in the CSS.')
      CALL PDAS
 
C nstid = number of sturcture identifiers
      CALL PQSID (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL IFPF (NSTID .EQ. 0)
 
      CALL ENDIT
      END
