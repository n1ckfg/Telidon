C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.03/03                              *
C  *    TEST TITLE : Update control of the workstation     *
C  *                 transformation                        *
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
 
C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND = 1)
C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)
C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
 
      REAL      OCWIN(6), OCVWP(6), RQWIN(6), RQVWP(6)
      REAL      NWWIN(6), NWVWP(6), CUWIN(6), CUVWP(6)
      REAL      RDUM1(6),RDUM2(6),RDUM3(6),RDUM4(6)
      INTEGER   IDUM1,IDUM2,IDUM3, SVR, WTUPD, IX
      LOGICAL   RAREQ
 
      CALL INITGL ('06.03/03')
 
C open PHIGS and workstation
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPWK  (WKID, CONID, WTYPE)
 
C  <Set display update state> to WAIT, NIVE to try to defer updates
      CALL PSDUS (WKID, PWAITD, PNIVE)
 
C  <inquire workstation transformation 3> to determine original
C     current state:
C     ocwin = 3D window
C     ocvwp = 3D viewport
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, OCWIN, RQVWP, OCVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
 
C  alter workstation transformation:
C  <set workstation window 3>   = nwwin = ocwin / 2
C  <set workstation viewport 3> = nwvwp = ocvwp / 2
 
      DO 300 IX=1,6
         NWWIN(IX) = OCWIN(IX) / 2.0
         NWVWP(IX) = OCVWP(IX) / 2.0
300   CONTINUE
 
C  <set workstation window 3>
      CALL PSWKW3 (WKID, NWWIN)
C  <set workstation viewport 3>
      CALL PSWKV3 (WKID, NWVWP)
 
C  <inquire workstation transformation 3> to determine new
C     current state:
C     wtupd = workstation transformation update state
C     cuwin = new 3D window
C     cuvwp = new 3D viewport
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
 
      CALL SETMSG ('15', 'The workstation transformation update '     //
     1             'state returned by <inquire workstation '          //
     2             'transformation 3> should be either PENDING or '   //
     3             'NOTPENDING.')
      IF (WTUPD .EQ. PNPEND) THEN
         CALL PASS
         CALL INMSG ('Skipping PENDING test.')
         GOTO 100
      ELSEIF (WTUPD .EQ. PPEND) THEN
         CALL PASS
      ELSE
         CALL FAIL
         GOTO 100
      ENDIF
 
C  pending_test:
      CALL SETMSG ('18', 'If the workstation transformation update '  //
     1             'state is PENDING, then the state of visual '      //
     2             'representation for that workstation should be '   //
     3             'DEFERRED.')
      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, IDUM3, SVR)
      CALL CHKINQ ('pqdus', ERRIND)
      CALL IFPF (SVR .EQ. PVRDFR)
 
      CALL SETMSG ('12 16', 'If the workstation transformation '      //
     1             'update state returned by <inquire workstation '   //
     2             'transformation 3> is PENDING, then the current '  //
     3             'values of the workstation transformation should ' //
     4             'be the same as they were before the requested '   //
     5             'values were last set.')
      CALL IFPF (RAREQ(6, CUWIN, OCWIN, 0.0,0.0)  .AND.
     1           RAREQ(6, CUVWP, OCVWP, 0.0,0.0))
 
C  notpending_test:
100   CONTINUE
 
C  <update workstation> to force update of view table
      CALL PUWK (WKID, PPERFO)
C  <inquire display update state> to determine
C     svr = state of visual representation
      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, IDUM3, SVR)
      CALL CHKINQ ('pqdus', ERRIND)
      IF (SVR .EQ. PVROK) THEN
         CALL SETMSG ('15 19', 'If the state of visual '            //
     1                'representation for a workstation is '        //
     2                'CORRECT, then the workstation '              //
     3                'transformation update returned by <inquire ' //
     4                'workstation transformation> state should '   //
     5                'be NOTPENDING.')
         CALL PQWKT3 (WKID, ERRIND, WTUPD, RDUM1,RDUM2,RDUM3,RDUM4)
         CALL CHKINQ ('pqwkt3', ERRIND)
         CALL IFPF (WTUPD .EQ. PNPEND)
      ELSE
         CALL INMSG ('Skipping test that CORRECT implies NOTPENDING.')
      ENDIF
 
C  <inquire workstation transformation 3> to determine new
C     current state:
C     wtupd = workstation transformation update state
C     cuwin = new 3D window
C     cuvwp = new 3D viewport
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
 
      IF (WTUPD .NE. PNPEND) THEN
         CALL INMSG ('Skipping NOTPENDING test.')
         GOTO 400
      ENDIF
 
      CALL SETMSG ('15 17', 'If the workstation transformation '      //
     1             'update state returned by <inquire workstation '   //
     2             'transformation 3> is NOTPENDING, then the '       //
     3             'current values of the workstation '               //
     4             'transformation should be the same as the most '   //
     5             'recently set requested values.')
      CALL IFPF (RAREQ(6, CUWIN, NWWIN, 0.0,0.0)  .AND.
     1           RAREQ(6, CUVWP, NWVWP, 0.0,0.0))
 
C  end_notpending_test:
400   CONTINUE
 
666   CONTINUE
      CALL ENDIT
      END
