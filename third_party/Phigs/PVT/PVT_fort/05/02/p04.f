C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.02/04                              *
C  *    TEST TITLE : Deferral mode ASAP                    *
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
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
 
      INTEGER   ACTSEV, ACTPCC
 
      LOGICAL   SVROK, ANYOK
      CHARACTER BADPIC*100
 
      CALL INITGL ('05.02/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  picture change categories are numbered from 1 to 17:
C    workstation changes :  1 to 12
C    structure changes   : 13 to 17
 
      BADPIC = 'Skipping next test case because PICCHG ' //
     1         'unable to perform requested operation.'
 
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
 
C invoke PICENV to set up standard picture environment
      CALL PICENV (WKID)
 
C  *** *** *** *** ***  visual changes   *** *** *** *** ***
 
      CALL PSDUS (WKID, PASAP, PNIVE)
C  request-change (8,9,12) of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '8,9,12', ACTSEV, ACTPCC)
      IF (ACTPCC .LT. 1) THEN
         CALL INMSG (BADPIC)
         GOTO 190
      ENDIF
 
      CALL SETMSG ('3 4 13 22', 'After altering a current/request ' //
     1             'type entity in the WSL, the state of visual '   //
     2             'representation should be CORRECT when the '     //
     3             'deferral mode is ASAP.')
      CALL IFPF (SVROK (WKID, 'c'))
190   CONTINUE
 
C  non-request-change (1-7,10,11) of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '1,2,3,4,5,6,7,10,11', ACTSEV, ACTPCC)
      IF (ACTPCC .LT. 1) THEN
         CALL INMSG (BADPIC)
         GOTO 290
      ENDIF
 
      CALL SETMSG ('3 4 13 22', 'After altering a single-valued ' //
     1             'type entity in the WSL, the state of visual ' //
     2             'representation should be CORRECT when the '   //
     3             'deferral mode is ASAP.')
      CALL IFPF (SVROK (WKID, 'c'))
290   CONTINUE
 
C  structure change (13-17) of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '13,14,15,16,17', ACTSEV, ACTPCC)
      IF (ACTPCC .LT. 1) THEN
         CALL INMSG (BADPIC)
         GOTO 390
      ENDIF
 
      CALL SETMSG ('3 4 13 22', 'After performing some CSS-type ' //
     1             'change, the state of visual representation '  //
     2             'should be CORRECT when the deferral mode is ' //
     3             'ASAP.')
      CALL IFPF (SVROK (WKID, 'c'))
390   CONTINUE
 
C  *** *** *** *** ***  deferral-mode changes   *** *** *** *** ***
 
      CALL PSDUS (WKID, PWAITD, PNIVE)
      ANYOK = .FALSE.
 
C  structure change   (17-13)     of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '17,16,15,14,13', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  non-request-change (11,10,7-1) of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '11,10,7,6,5,4,3,2,1', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  request-change     (12,9,8)    of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '12,9,8', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
 
      IF (.NOT. ANYOK) THEN
         CALL INMSG (BADPIC)
         GOTO 490
      ENDIF
 
      CALL PSDUS (WKID, PASAP, PNIVE)
 
      CALL SETMSG ('3 4 13 22', 'After performing visual changes ' //
     1             'in WAIT,NIVE mode, the state of visual '       //
     2             'representation should be CORRECT when the '    //
     3             'deferral mode is re-set to ASAP.')
      CALL IFPF (SVROK (WKID, 'c'))
490   CONTINUE
 
666   CONTINUE
      CALL ENDIT
      END
