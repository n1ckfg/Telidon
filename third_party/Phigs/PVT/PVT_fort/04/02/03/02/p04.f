
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/04                        *
C  *    TEST TITLE : Validity of predefined text           *
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

      INTEGER   MPCI, NPE, TXI, TXCI, ERTXCI, IDUM1, IDUM2, IDUM3
      INTEGER   IDUM4, IDUM5, IDUM6, PFONT, PPRC, ERFONT, ERPREC
      INTEGER   TXI2, SVPDFN(6), PDFN, SVPDPR(6), PDPR, MAXFP, NUMFP
      INTEGER   RFONT, RPREC, RTXCI, ERBUN
      REAL      RCEX, RCSP, PCSP
      PARAMETER (MAXFP = 1000)
      INTEGER   SVPDCI(6), PDCI, AVFONT(MAXFP), AVPREC(MAXFP), FPX

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, RDUM4, RDUM5(9), PCEX, ERCEX
      REAL      SVPDXP(6), PDXP, SVPDSP(6), PDSP, MINCEX,MAXCEX

      LOGICAL   FPERR, CEXERR, COLERR, RLZERR

      CHARACTER MSG*300

      CALL INITGL ('04.02.03.02/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
      CALL PQCF (SPECWT, ERRIND, IDUM1, IDUM2, MPCI, RDUM5)
      CALL CHKINQ ('pqcf', ERRIND)
C  Since color indices are numbered from 0, the maximum index is
C  one less than the number of predefined indices.
      MPCI = MPCI - 1
C  npe = number of predefined entries
      CALL PQTXF (SPECWT, 0, ERRIND, NUMFP, IDUM2, IDUM3,
     1            IDUM4, RDUM1, RDUM2, IDUM5, MINCEX, MAXCEX, NPE)
      CALL CHKINQ ('pqtxf', ERRIND)

C create list of font-precision pairs
      DO 20 FPX = 1,NUMFP
         CALL PQTXF (SPECWT, FPX, ERRIND,
     1               IDUM1, AVFONT(FPX), AVPREC(FPX),
     2               IDUM4, RDUM1, RDUM2, IDUM5, RDUM3,RDUM4, IDUM6)
         CALL CHKINQ ('pqtxf', ERRIND)
20    CONTINUE

C  font/precision error found yet
      FPERR  = .FALSE.
C  character expansion factor error found yet
      CEXERR = .FALSE.
C  color error found yet
      COLERR = .FALSE.
C  realized  error found yet
      RLZERR = .FALSE.

      CALL SETMSG ('19 20 23', '<Inquire predefined text '        //
     1             'representation> should be able to access as ' //
     2             'many entries as reported by <inquire text '   //
     3             'facilities>.')

      DO 100 TXI = 1, NPE
         CALL PQPTXR (SPECWT, TXI, ERRIND, PFONT, PPRC, PCEX, PCSP,
     1                TXCI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 150
         ENDIF

C check that font & precision are available - note that list of available
C fopnt/precision pairs need only contain highest precision.
         DO 110 FPX = 1,NUMFP
            IF (PFONT .EQ. AVFONT(FPX) .AND.
     1          PPRC  .LE. AVPREC(FPX))   GOTO 120
110      CONTINUE
         FPERR  = .TRUE.
         ERFONT = PFONT
         ERPREC = PPRC
120      CONTINUE

C check char-exp-factor
         IF (PPRC .NE. PSTRKP .AND.
     1       (PCEX .LT. MINCEX .OR. PCEX .GT. MAXCEX)) THEN
            CEXERR = .TRUE.
            ERCEX  = PCEX
         ENDIF

C check text color index
         IF (TXCI .LT. 0 .OR. TXCI .GT. MPCI) THEN
            COLERR = .TRUE.
            ERTXCI = TXCI
         ENDIF

C set text representation #3
         CALL PSTXR (WKID, 3, PFONT, PPRC, PCEX, PCSP, TXCI)
         CALL PQTXR (WKID, 3, PREALI, ERRIND, RFONT, RPREC, RCEX, RCSP,
     1               RTXCI)
         CALL CHKINQ ('pqtxr', ERRIND)
         IF (RFONT .NE. PFONT     .OR.
     1       RPREC .NE. PPRC      .OR.
     2       RCEX  .NE. PCEX      .OR.
     3       RCSP  .NE. PCSP      .OR.
     4       RTXCI .NE. TXCI ) THEN
            RLZERR = .TRUE.
            ERBUN = TXI
         ENDIF

100   CONTINUE
      CALL PASS

      CALL SETMSG ('20 26', 'All font-precision pairs in '        //
     1             'predefined text bundles should be supported ' //
     2             'by an entry in the list of text '             //
     3             'font-precision pairs.')
      IF (FPERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'Unsupported font/precision: ',
     1          ERFONT, '/', ERPREC, ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 27', 'All character expansion factors in '  //
     1             'predefined text bundles should be within the ' //
     2             'reported minimum and maximum character '       //
     3             'expansion factors for non-STROKE precision.')
      IF (CEXERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,F11.4,A)')
     1         'Out-of-range character expansion factor: ',
     2          ERCEX, ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 29', 'All color indices in predefined text '  //
     1             'bundles should themselves be in the predefined ' //
     2             'color table.')
      IF (COLERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color #', ERTXCI,
     1          ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('15 26 27 28 29', 'All aspects of all predefined ' //
     1             'text bundles should be reported as realizable '   //
     2             'by <inquire text representation>.')
      IF (RLZERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Predefined bundle #', ERBUN,
     1                           ' not realized as set.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

150   CONTINUE
      WRITE (MSG, '(A,I5,A)') 'PHIGS reported ', NPE,
     1       ' predefined text bundles.'
      CALL INMSG (MSG)
      CALL SETMSG ('19 21', '<Inquire text facilities> should ' //
     1             'report at least 6 predefined entries.')
      IF (NPE .LT. 6) THEN
         CALL FAIL
         GOTO 666
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 22', 'The first six predefined text ' //
     1             'bundle entries should all be mutually '  //
     2             'distinguishable.')

C  pdfn = predefined font
C  pdpr = predefined precision
C  pdxp = predefined character expansion factor
C  pdsp = predefined character spacing
C  pdci = predefined text color index
      DO 200 TXI = 1, 6
C  get attributes for current bundle
         CALL PQPTXR (SPECWT, TXI, ERRIND, PDFN, PDPR, PDXP, PDSP,
     1                PDCI)
         CALL CHKINQ ('pqptxr', ERRIND)
C  compare current to all previous bundles
         DO 250 TXI2 = 1, TXI-1
            IF (SVPDFN (TXI2) .EQ. PDFN  .AND.
     1          SVPDPR (TXI2) .EQ. PDPR  .AND.
     2          SVPDXP (TXI2) .EQ. PDXP  .AND.
     3          SVPDSP (TXI2) .EQ. PDSP  .AND.
     4          SVPDCI (TXI2) .EQ. PDCI)     THEN
               CALL FAIL
               WRITE (MSG, '(A,I2,A,I2,A)') 'Text bundle #',
     1                TXI, ' is indistinguishable from #', TXI2, '.'
               CALL INMSG (MSG)
               GOTO 666
            ENDIF
250      CONTINUE
C  save current attributes
         SVPDFN (TXI) = PDFN
         SVPDPR (TXI) = PDPR
         SVPDXP (TXI) = PDXP
         SVPDSP (TXI) = PDSP
         SVPDCI (TXI) = PDCI
200   CONTINUE
      CALL PASS

666   CONTINUE
C wrap it up
      CALL ENDIT
      END

