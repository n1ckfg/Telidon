C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.01.01/01                           *
C  *    TEST TITLE : Initial state of workstations         *
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
 
      INTEGER    WKSVAL, NUMOPW, IDUM1
 
C workstation state
      INTEGER    PWSCL,     PWSOP
      PARAMETER (PWSCL = 0, PWSOP = 1)
 
      CALL INITGL ('05.01.01/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      NUMOPW = -6
C  <Inquire set of open workstations> to determine
C     numopw = number of open workstation
      CALL PQOPWK (0, ERRIND, NUMOPW, IDUM1)
      CALL CHKINQ ('pqopwk', ERRIND)
 
      WKSVAL = -6
C  <Inquire workstation state value> to determine
C     wksval = workstation state value
      CALL PQWKST (WKSVAL)
 
      CALL SETMSG ('1 7', 'Immediately after <open phigs>, and '      //
     1             'until the first invocation of <open '             //
     2             'workstation>, the set of open workstations '      //
     3             'should be empty.')
      CALL IFPF (NUMOPW .EQ. 0)
 
      CALL SETMSG ('2 3 4', 'Immediately after <open phigs> and '     //
     1             'until the first invocation of <open '             //
     2             'workstation>, the workstation state should be '   //
     3             'WSCL.')
      CALL IFPF (WKSVAL .EQ. PWSCL)
 
666   CONTINUE
      CALL ENDIT
      END
