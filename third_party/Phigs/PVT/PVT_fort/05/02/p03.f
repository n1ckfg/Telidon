C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.02/03                              *
C  *    TEST TITLE : Explicit updating                     *
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
     3        DUMINT(20)
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

C  Declare program-specific variables
C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
C clear control flag
      INTEGER    PCONDI,     PALWAY
      PARAMETER (PCONDI = 0, PALWAY = 1)
C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND = 1)
C fortran binding: current and requested values
      INTEGER    PCURVL,     PRQSVL
      PARAMETER (PCURVL = 0, PRQSVL = 1)

      INTEGER   ACTSEV, ACTPCC
      LOGICAL   SVROK, ANYOK
      CHARACTER BADPIC*100


      CALL INITGL ('05.02/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  picture change categories are numbered from 1 to 17:
C    workstation changes :  1 to 12
C    structure changes   : 13 to 17

      BADPIC = 'Skipping next test case because PICCHG ' //
     1         'unable to perform requested operation.'

C open workstation
      CALL POPWK (WKID, CONID, WTYPE)

C  invoke PCCENV to set up standard environment
      CALL PICENV (WKID)

      CALL PSDUS (WKID, PWAITD, PNIVE)

      ANYOK = .FALSE.
C  request-change     (8,9,12)    of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '8,9,12', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  non-request-change (1-7,10,11) of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '1,2,3,4,5,6,7,10,11', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  structure change   (13-17)     of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '13,14,15,16,17', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.

      IF (.NOT. ANYOK) THEN
         CALL INMSG (BADPIC)
         GOTO 100
      ENDIF
C  <redraw all structures> with CONDITIONAL
      CALL PRST (WKID, PCONDI)
      CALL SETMSG ('4 13 16', '<Redraw all structures> should cause ' //
     1             'the state of visual representation to be '        //
     2             'CORRECT.')
      CALL IFPF (SVROK (WKID, 'c'))

100   CONTINUE
      ANYOK = .FALSE.

C  request-change     (12,9,8)    of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '12,9,8', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  non-request-change (11,10,7-1) of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '11,10,7,6,5,4,3,2,1', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  structure change   (17-13)     of greatest available severity
      CALL PICCHG (WKID, '0,2,1', '17,16,15,14,13', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.

      IF (.NOT. ANYOK) THEN
         CALL INMSG (BADPIC)
         GOTO 200
      ENDIF
C  <update workstation> with PERFORM
      CALL PUWK (WKID, PPERFO)
      CALL SETMSG ('4 13 17', '<Update workstation> with '         //
     1             'regeneration flag = PERFORM should cause the ' //
     2             'state of visual representation to be CORRECT.')
      CALL IFPF (SVROK (WKID, 'c'))

200   CONTINUE
      ANYOK = .FALSE.

C  <redraw all structures> with CONDITIONAL to make svr = CORRECT
      CALL PRST (WKID, PCONDI)
C  request-change     (9,8,12)         of severity = IMM
      CALL PICCHG (WKID, '1', '9,8,12', ACTSEV, ACTPCC)
C  non-request-change (10,7-1,11)      of severity = IMM
      CALL PICCHG (WKID, '1', '10,7,6,5,4,3,2,1,11', ACTSEV, ACTPCC)
C  structure change   (15,16,14,17,13) of severity = IMM
      CALL PICCHG (WKID, '1', '15,16,14,17,13', ACTSEV, ACTPCC)
C  <update workstation> with POSTPONE
      CALL PUWK (WKID, PPOSTP)

      CALL SETMSG ('4 18', 'If the severity of all deferred actions ' //
     1             'is IMM, then <update workstation> with '          //
     2             'regeneration flag = POSTPONE should cause the '   //
     3             'state of visual representation to be CORRECT.')
      CALL IFPF (SVROK (WKID, 'c'))

C  <redraw all structures> with CONDITIONAL to make svr = CORRECT
      CALL PRST (WKID, PCONDI)

      ANYOK = .FALSE.
C  request-change     (9,8,12)         of severity = IRG
      CALL PICCHG (WKID, '0', '9,8,12', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  non-request-change (10,7-1,11)      of severity = IRG
      CALL PICCHG (WKID, '0', '10,7,6,5,4,3,2,1,11', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.
C  structure change   (15,16,14,17,13) of severity = IRG
      CALL PICCHG (WKID, '0', '15,16,14,17,13', ACTSEV, ACTPCC)
      IF (ACTPCC .GT. 0) ANYOK = .TRUE.

      IF (.NOT. ANYOK) THEN
         CALL INMSG (BADPIC)
         GOTO 300
      ENDIF

C  <update workstation> with POSTPONE
      CALL PUWK (WKID, PPOSTP)

      CALL SETMSG ('4 18', 'If the severity of some of the deferred ' //
     1             'actions is IRG, then <update workstation> with '  //
     2             'regeneration flag = POSTPONE should leave the '   //
     3             'state of visual representation as DEFERRED or '   //
     4             'make it CORRECT.')
      CALL IFPF (SVROK (WKID, 'cd'))

C  end_irg:
300   CONTINUE

666   CONTINUE
      CALL ENDIT
      END
