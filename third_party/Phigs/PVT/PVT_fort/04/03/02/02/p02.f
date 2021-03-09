C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/02                        *
C  *    TEST TITLE : Validity of predefined colour         *
C  *                 table                                 *
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

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)
C NOTE:  INTEGER rather than enumeration type.  Explicitly defined and
C required portion of conceptually unbounded range defined here.

C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER    SPECWT,SPECON, NPE, CI, I, NUMRET, DEFMOD, ERRCI,ERRVAL
      INTEGER    RSIZ, IDUM1, IDUM2

      REAL       CSPEC(6), CSPEC1(6), RDUM1(9), RSPEC(6)

      LOGICAL    CHKCSR, VALCSV, GOTBF(0:1), PREAL, RAREQ

      CHARACTER  MSG*300

      CALL INITGL ('04.03.02.02/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C get default colour model
      CALL PQCMDF (SPECWT, 0, ERRIND, IDUM1, IDUM2, DEFMOD)
      CALL CHKINQ ('pqcmdf', ERRIND)

C check colour specification range
      IF (DEFMOD.LT.1 .OR. DEFMOD.GT.4) THEN
         WRITE (MSG, '(A,I5,A,A)') 'Colour model ', DEFMOD,
     1          ' not predefined.  Cannot check that colour ',
     2          'specification is within range.'
         CALL INMSG (MSG)
         CHKCSR = .FALSE.
      ELSE
         CHKCSR = .TRUE.
      ENDIF

C npe = number of predefined entries
      CALL PQCF (SPECWT, ERRIND, IDUM1, IDUM2, NPE, RDUM1)
      CALL CHKINQ ('pqcf', ERRIND)
      CALL SETMSG ('8 11', '<Inquire colour facilities> should ' //
     1             'report at least 2 predefined entries.')
      CALL IFPF (NPE .GE. 2)

C  got background or foreground index?
      GOTBF(0) = .FALSE.
      GOTBF(1) = .FALSE.
C  valid colour specification values?
      VALCSV   = .TRUE.
      PREAL    = .TRUE.

      CALL SETMSG ('8 9 10', '<Inquire predefined colour '        //
     1             'representation> should be able to access as ' //
     2             'many entries as reported by <inquire colour ' //
     3             'facilities>.')

C colour indices start at 0
      DO 100 CI = 0, NPE-1
         CALL PQPCR (SPECWT, CI, 6, ERRIND, NUMRET, CSPEC)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 150
         ENDIF

C check for index 0 and 1
         IF (CI.EQ.0 .OR. CI.EQ.1) GOTBF(CI) = .TRUE.

C check cspec is within range
         IF (CHKCSR) THEN
C all defined models are 3-dimensional
            IF (NUMRET .NE. 3) THEN
               VALCSV = .FALSE.
               ERRVAL = CI
            ENDIF
            DO 50 I = 1,NUMRET
               IF (CSPEC(I) .LT. 0.0 .OR. CSPEC(I) .GT. 1.0) THEN
                  VALCSV = .FALSE.
                  ERRVAL = CI
               ENDIF
50          CONTINUE
         ENDIF

C check all predefined are realizable
         CALL PSCR (WKID, 1, NUMRET, CSPEC)
         CALL PQCR (WKID, 1, 6, PREALI, ERRIND, RSIZ, RSPEC)
         CALL CHKINQ ('pqcr', ERRIND)

         IF (RSIZ .NE. NUMRET) THEN
             PREAL = .FALSE.
             ERRCI = CI
         ELSEIF (.NOT. RAREQ (NUMRET, CSPEC, RSPEC, 0.05, 0.)) THEN
             PREAL = .FALSE.
             ERRCI = CI
         ENDIF
100   CONTINUE
      CALL PASS

150   CONTINUE
      IF (CHKCSR) THEN
         CALL SETMSG ('9 15 26', 'The colour specification '       //
     1                'parameters for all the predefined colour '  //
     2                'indices should be valid for the default '   //
     3                'colour model.')
         IF (VALCSV) THEN
            CALL PASS
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I4,A)') 'Colour specification #',
     1             ERRVAL, ' invalid.'
            CALL INMSG (MSG)
         ENDIF
      ENDIF

      CALL SETMSG ('9 15 32 33', 'The colour specification '     //
     1             'parameters for all the predefined colour '   //
     2             'indices should be realizable by the workstation.')
      IF (PREAL) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I4,A)') 'Colour specification #',
     1          ERRCI, ' not realizable.'
         CALL INMSG (MSG)
      ENDIF

      CALL SETMSG ('11', 'The predefined colour indices should ' //
     1             'include entries 0 and 1.')
      CALL IFPF (GOTBF(0) .AND. GOTBF(1))

      CALL SETMSG ('9 11 12', 'The first two predefined colour ' //
     1             'indices should be mutually distinguishable.')
C cspec = predefined colour specification for index #0
      CALL PQPCR (SPECWT, 0, 6, ERRIND, NUMRET, CSPEC)
      CALL CHKINQ ('pqpcr', ERRIND)
C cspec1 = predefined colour specification for index #1
      CALL PQPCR (SPECWT, 1, 6, ERRIND, NUMRET, CSPEC1)
      CALL CHKINQ ('pqpcr', ERRIND)
      CALL IFPF (.NOT. RAREQ (NUMRET, CSPEC,CSPEC1, 0.001, 0.001))

666   CONTINUE
C wrap it up
      CALL ENDIT
      END
