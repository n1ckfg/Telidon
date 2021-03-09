C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.03/02                           *
C  *    TEST TITLE : Set and inquire HLHSR mode            *
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

C  Declare program-specific variables
      INTEGER    NUMMOD, HRMD, UPDATE, ORGMOD, CURMOD, REQMOD
      INTEGER    DYNMOD, SURFMT, VAL, I
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7,
     1           IDUM8, IDUM9, IDUM10, IDUM11

C display surface empty
      INTEGER    PNEMPT,     PEMPTY
      PARAMETER (PNEMPT = 0, PEMPTY =1)
C dynamic modification
      INTEGER    PIRG,     PIMM,    PCBS
      PARAMETER (PIRG = 0, PIMM =1, PCBS =2)
C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND =1)
C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)


C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      REAL       XP(2),YP(2)

      DATA  XP /0.0, 1.0/
      DATA  YP /0.0, 1.0/

      CALL INITGL ('04.03.03/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
C get this workstation type
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C <inquire HLHSR facilities> to determine
C  nummod = number of available HLHSR modes
C in Fortran: - get lstmod, list of HLHSR modes, one element at a time
C        use:   hrmd = nth element of list
      CALL PQHRMF (SPECWT, 0, ERRIND, NUMMOD, IDUM3)
      CALL CHKINQ ('pqhrmf', ERRIND)

C <inquire HLHSR mode> to determine
C  orgmod = original current HLHSR mode
      UPDATE = -6
      ORGMOD = -6
      REQMOD = -6
      CALL PQHRM (WKID, ERRIND, UPDATE, ORGMOD, REQMOD)
      CALL CHKINQ ('pqhrm', ERRIND)

C find different value for HLHSR mode
      VAL = 0
      DO 100 I = 1, NUMMOD
         CALL PQHRMF (SPECWT, I, ERRIND, IDUM3, HRMD)
         CALL CHKINQ ('pqhrmf', ERRIND)
         IF (HRMD .NE. ORGMOD) THEN
            VAL = HRMD
            GOTO 150
         ENDIF
100   CONTINUE

150   CONTINUE
C  <set display update state> to WAIT, UWOR to allow
C     testing of hlhsr update status.
      CALL PSDUS (WKID, PWAITD, PUWOR)

C  <set HLHSR mode> to val
      CALL PSHRM (WKID, VAL)
      UPDATE = -66
      CURMOD = -66
      REQMOD = -66
C  <inquire HLHSR mode> to determine
C     update = HLHSR update state
C     curmod = current HLHSR mode
C     reqmod = requested HLHSR mode
      CALL PQHRM (WKID, ERRIND, UPDATE, CURMOD, REQMOD)
      CALL CHKINQ ('pqhrm', ERRIND)

      CALL SETMSG ('4 5', 'The requested HLHSR mode should be ' //
     1             'returned as set.')
      CALL IFPF (REQMOD .EQ. VAL)

C  <inquire dynamics of workstation attributes> to determine
C     dynmod = dynamic modification entry for HLHSR mode
      CALL PQDSWA (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             IDUM5, IDUM6, IDUM7, IDUM8, IDUM9, IDUM10,
     2             IDUM11, DYNMOD)
      CALL CHKINQ ('pqdswa', ERRIND)

C  Surface should be empty
      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, SURFMT, IDUM3)
      CALL CHKINQ ('pqdus', ERRIND)
      IF (SURFMT .NE. PEMPTY) THEN
         CALL INMSG ('Skipping surface-empty test.')
         GOTO 500
      ENDIF

      IF (DYNMOD .EQ. PIMM) THEN
         CALL SETMSG ('5 6', 'If the dynamic modification entry '  //
     1                'for HLHSR mode is IMM and the display '     //
     2                'surface is EMPTY, then new values should '  //
     3                'be set for current HLHSR mode and the '     //
     4                'HLHSR update state should be NOTPENDING.')
      ELSE
         CALL SETMSG ('5 6', 'If the dynamic modification entry '  //
     1                'for HLHSR mode is not IMM and the display ' //
     2                'surface is EMPTY, then new values should '  //
     3                'be set for current HLHSR mode and the '     //
     4                'HLHSR update state should be NOTPENDING.')
      ENDIF
      CALL IFPF (UPDATE .EQ. PNPEND .AND. CURMOD .EQ. VAL)

C  Cause surface to be NOT EMPTY:
      CALL POPST (10)
      CALL PPL   (2,XP,YP)
      CALL PCLST
      CALL PPOST (WKID, 10, 0.5)

C  <set HLHSR mode> to orgmod
      CALL PSHRM (WKID, ORGMOD)

C  <update workstation> to force orgmod to be current
C  and screen to be non-empty
      CALL PUWK  (WKID, PPERFO)

C  Surface should be non-empty
      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, SURFMT, IDUM3)
      CALL CHKINQ ('pqdus', ERRIND)
      IF (SURFMT .NE. PNEMPT) THEN
         CALL INMSG ('Skipping surface-not-empty test.')
         GOTO 666
      ENDIF

C  <set HLHSR mode> to val
      CALL PSHRM (WKID, VAL)
      UPDATE = -66
      CURMOD = -66
      REQMOD = -66
C  <inquire HLHSR mode> to determine
C     update = HLHSR update state
C     curmod = current HLHSR mode
C     reqmod = requested HLHSR mode
      CALL PQHRM (WKID, ERRIND, UPDATE, CURMOD, REQMOD)
      CALL CHKINQ ('pqhrm', ERRIND)

C  non_empty_test:
500   CONTINUE

      IF (DYNMOD .EQ. PIMM) THEN
         CALL SETMSG ('5 6', 'If the dynamic modification entry '  //
     1                'for HLHSR mode is IMM and the display '     //
     2                'surface is not EMPTY, then new values '     //
     3                'should be set for current HLHSR mode and '  //
     4                'the HLHSR update state should be NOTPENDING.')
         CALL IFPF (UPDATE .EQ. PNPEND .AND. CURMOD .EQ. VAL)
      ELSE
         IF (REQMOD .NE. CURMOD) THEN
            CALL SETMSG ('5 7', 'If the current HLHSR mode differs ' //
     1                   'from that requested by <set HLHSR mode>, ' //
     2                   'then the current HLHSR mode should be '    //
     3                   'unchanged and the HLHSR update state '     //
     4                   'should be PENDING.')
            CALL IFPF (UPDATE .EQ. PPEND  .AND. CURMOD .EQ. ORGMOD)
         ENDIF
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
