C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/04                        *
C  *    TEST TITLE : Validity of predefined interior       *
C  *                 bundles                               *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   MPCI,MPPI,MPHI, NPE, II,II2, HI, ICI, ICI2, ERBUN
      INTEGER   ERICI, LAINTS(90), HSTYLE(90), NAINTS, IARFND
      INTEGER   THISIS, INTS, INTS2, ERINTS, STYI, STYI2, ERPAT, ERHAT
      INTEGER   THISHI, IDUM1, IDUM2, IDUM3, IDUM4
      INTEGER   SVPDIN(5), PDIN, SVPDSI(5), PDSI, SVPDCI(5), PDCI

      REAL      RDUM1(9)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      LOGICAL   COLERR, RLZERR, STYERR, PATERR, HATERR, LASERR

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.02/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
C get maximum predefined color index and
C adjust for color index starting at 0 (not 1)
      CALL PQCF (SPECWT, ERRIND, IDUM1, IDUM2, MPCI, RDUM1)
      CALL CHKINQ ('pqcf', ERRIND)
      MPCI = MPCI - 1
C get maximum predefined pattern index
      CALL PQPAF (SPECWT, ERRIND, MPPI)
      CALL CHKINQ ('pqpaf', ERRIND)
C get number of predefined indices (style, hatch, bundle)
C naints  = number of available style indices
C laints  = list of available style indices
C mphi    = number of available hatch indices
C npe     = number of predefined entries
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1, MPHI,
     1           IDUM2, NPE)
      CALL CHKINQ ('pqif', ERRIND)
      DO 100 II = 1, NAINTS
         CALL PQIF (SPECWT, II, 0, ERRIND, IDUM1, THISIS, IDUM2,
     1        IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         LAINTS(II) = THISIS
100   CONTINUE

      DO 200 HI = 1, ABS(MPHI)
         CALL PQIF (SPECWT, 0, HI, ERRIND, IDUM1, IDUM2, IDUM3,
     1      THISHI, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         HSTYLE(HI)  = THISHI
200   CONTINUE

C  error found yet (color, style, pattern, hatch, list of available
C                   styles)
      COLERR = .FALSE.
      RLZERR = .FALSE.
      STYERR = .FALSE.
      PATERR = .FALSE.
      HATERR = .FALSE.
      LASERR = .FALSE.

      CALL SETMSG ('20 21 24', '<Inquire predefined interior '      //
     2             'representation> should be able to access as '   //
     3             'many entries as reported by <inquire interior ' //
     4             'facilities>.')

      DO 300 II = 1, NPE
         CALL PQPIR (SPECWT, II, ERRIND, INTS, STYI, ICI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 400
         ENDIF
C check interior color index
         IF (ICI .LT. 0 .OR. ICI .GT. MPCI) THEN
            COLERR = .TRUE.
            ERICI = ICI
         ENDIF

         CALL PSIR (WKID, 3, INTS, STYI, ICI)
         CALL PQIR (WKID, 3, PREALI, ERRIND, INTS2, STYI2, ICI2)
         CALL CHKINQ ('pqir', ERRIND)
         IF (INTS.EQ.INTS2 .AND. STYI.EQ.STYI2 .AND. ICI.EQ.ICI2) THEN
C           OK
         ELSE
            RLZERR = .TRUE.
            ERBUN  = II
         ENDIF

C check list of available interior styles
         IF (IARFND (INTS, NAINTS, LAINTS) .LE. 0) THEN
            LASERR = .TRUE.
            ERINTS = INTS
         ENDIF

C check PATTERN interior style
         IF (INTS .EQ. PPATTR) THEN
            IF (STYI .LT. 1 .OR. STYI .GT. MPPI) THEN
               PATERR = .TRUE.
               ERPAT  = STYI
            ENDIF
         ENDIF

C check HATCH interior style
         IF (INTS .EQ. PHATCH)  THEN
C check list of available interior styles
            IF (IARFND (STYI, ABS(MPHI), HSTYLE) .LE. 0) THEN
               HATERR = .TRUE.
               ERHAT  = STYI
            ENDIF
         ENDIF
300   CONTINUE
      CALL PASS

      CALL SETMSG ('21 30', 'All color indices in predefined '     //
     1             'interior bundles should themselves be in the ' //
     2             'predefined color table.')
      IF (COLERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color #', ERICI,
     1          ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('16 27 28 29 30', 'All aspects of all predefined ' //
     1             'interior bundles should be reported as '          //
     2             'realizable by <inquire interior representation>.')
      IF (RLZERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Predefined bundle #', ERBUN,
     1                           ' not realized as set.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('21 27', 'All interior styles in predefined '  //
     1             'bundles should themselves be in the list of ' //
     2             'available interior styles.')
      IF (LASERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined interior style', ERINTS,
     1          ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('21 28', 'For PATTERN interior style, all ' //
     1             'pattern indices in predefined interior '   //
     2             'bundles should themselves be in the '      //
     3             'predefined pattern table.')
      IF (PATERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined pattern index', ERPAT,
     1          ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('21 29', 'For HATCH interior style, all hatch '  //
     1             'indices in predefined interior bundles should ' //
     2             'themselves be in the list of available hatch '  //
     3             'styles.')
      IF (HATERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined interior style', ERHAT,
     1          ' found in list of available hatch styles.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

400   CONTINUE
      WRITE (MSG, '(A,I5,A)') 'PHIGS reported ', NPE,
     1       ' predefined interior bundles.'
      CALL INMSG (MSG)
      CALL SETMSG ('20 22', '<Inquire interior facilities> should ' //
     1             'report at least 5 predefined entries.')
      IF (NPE .LT. 5) THEN
         CALL FAIL
         GOTO 666
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('21 23', 'The first five predefined interior ' //
     1             'bundle entries should all be mutually '       //
     2             'distinguishable.')

C  pdin = predefined interior style
C  pdsi = predefined interior style index
C  pdci = predefined interior color index
      DO 550 II = 1, 5
C  get attributes for current bundle
         CALL PQPIR (SPECWT, II, ERRIND, PDIN, PDSI, PDCI)
         CALL CHKINQ ('pqpir', ERRIND)
C  compare current to all previous bundles
         DO 500 II2 = 1, II-1
            IF (SVPDIN (II2) .EQ. PDIN  .AND.
     1          SVPDSI (II2) .EQ. PDSI  .AND.
     2          SVPDCI (II2) .EQ. PDCI) THEN
               CALL FAIL
               WRITE (MSG, '(A,I2,A,I2,A)') 'Interior bundle #',
     1                II, ' is indistinguishable from #', II2, '.'
               CALL INMSG (MSG)
               GOTO 666
            ENDIF
500      CONTINUE
C  save current attributes
         SVPDIN (II) = PDIN
         SVPDSI (II) = PDSI
         SVPDCI (II) = PDCI
550   CONTINUE
      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
