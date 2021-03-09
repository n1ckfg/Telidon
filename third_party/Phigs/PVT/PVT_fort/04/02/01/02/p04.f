C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/04                        *
C  *    TEST TITLE : Validity of predefined polyline       *
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
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   MPCI, NPE, PLI, PLCI, PLCI2, ERPLCI, IDUM1, IDUM2, IDUM3
      INTEGER   PLI2, SVPDLT (5), PDLT, SVPDCI (5), PDCI
      INTEGER   NALT, LI, ERPLLT, LINTY, LINTY2, RLINTY, ERBUN

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, RDUM4(9), SVPDLW(5), ERLW
      REAL      PDLW, NOMLW, MINLW, MAXLW, PLWSF, PLWSF2, GENLW

      LOGICAL   LINERR, LWERR, COLERR, RLZERR

      CHARACTER MSG*300

      CALL INITGL ('04.02.01.02/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  mpci = maximum predefined color index
      CALL PQCF (SPECWT, ERRIND, IDUM1, IDUM2, MPCI, RDUM4)
      CALL CHKINQ ('pqcf', ERRIND)
C  Since color indices are numbered from 0, the maximum index is
C  one less than the number of predefined indices.
      MPCI = MPCI - 1

C  npe = number of predefined entries
C  nalt = number of available linetypes
C  nomlw = nominal linewidth
C  minlw = minimum linewidth
C  maxlw = maximum linewidth
      CALL PQPLF (SPECWT, 0, ERRIND, NALT, IDUM2, IDUM3,
     1            NOMLW, MINLW, MAXLW, NPE)
      CALL CHKINQ ('pqplf', ERRIND)

C  linerr = linetype error found yet
      LINERR = .FALSE.
C  lwerr  = linewidth error found yet
      LWERR  = .FALSE.
C  colerr = color error found yet
      COLERR = .FALSE.
C  rlzerr = realized error found yet
      RLZERR = .FALSE.

      CALL SETMSG ('19 20 23', '<Inquire predefined polyline '      //
     1             'representation> should be able to access as '   //
     2             'many entries as reported by <inquire polyline ' //
     3             'facilities>.')

      DO 100 PLI = 1, NPE
         CALL PQPPLR (SPECWT, PLI, ERRIND, LINTY, PLWSF, PLCI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 150
         ENDIF

         DO 50 LI = 1, ABS(NALT)
            CALL PQPLF (SPECWT, LI, ERRIND, IDUM1, RLINTY, IDUM3,
     1                  RDUM1, RDUM2, RDUM3, NPE)
            CALL CHKINQ ('pqplf', ERRIND)
            IF (LINTY .EQ. RLINTY) GOTO 60
50       CONTINUE
         LINERR = .TRUE.
         ERPLLT = LINTY

60       CONTINUE
         GENLW = PLWSF * NOMLW
         IF (GENLW .LT. MINLW .OR. GENLW .GT. MAXLW) THEN
            LWERR = .TRUE.
            ERLW  = PLWSF
         ENDIF

         IF (PLCI .LT. 0 .OR. PLCI .GT. MPCI) THEN
            COLERR = .TRUE.
            ERPLCI = PLCI
         ENDIF

         CALL PSPLR (WKID, 3, LINTY,  PLWSF,  PLCI)
         CALL PQPLR (WKID, 3, PREALI, ERRIND, LINTY2, PLWSF2, PLCI2)
         CALL CHKINQ ('pqplr', ERRIND)
         IF (LINTY.EQ.LINTY2 .AND. PLWSF.EQ.PLWSF2
     1                       .AND. PLCI.EQ.PLCI2) THEN
C           OK
         ELSE
            RLZERR = .TRUE.
            ERBUN  = PLI
         ENDIF

100   CONTINUE
      CALL PASS

      CALL SETMSG ('20 26', 'All linetypes in predefined polyline ' //
     1             'bundles should themselves be in the list of '  //
     2             'available linetypes.')
      IF (LINERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined linetype #', ERPLLT,
     1                        ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 27', 'All linewidth scale factors in '      //
     1             'predefined polyline bundles should generate ' //
     2             'linewidths within the minimum and maximum '   //
     3             'linewidths.')
      IF (LWERR) THEN
         CALL FAIL
         WRITE (MSG,'(A,F11.4,A)')
     1          'Unrealizable linewidth scale factor, ',
     2           ERLW, ', found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 28', 'All color indices in predefined '      //
     1             'polyline bundles should themselves be in the ' //
     2             'predefined color table.')
      IF (COLERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color #', ERPLCI,
     1                        ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('15 26 27 28', 'All aspects of all predefined ' //
     1             'polyline bundles should be reported as '       //
     2             'realizable by <inquire polyline representation>.')
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
     1         ' predefined polyline bundles.'
      CALL INMSG (MSG)
      CALL SETMSG ('19 21', '<Inquire polyline facilities> should ' //
     1             'report at least 5 predefined entries.')
      IF (NPE .LT. 5) THEN
         CALL FAIL
         GOTO 666
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 22', 'The first five predefined polyline ' //
     1             'bundle entries should all be mutually '     //
     2             'distinguishable.')

C  pdlt = predefined linetype
C  pdlw = predefined linewidth scale factor
C  pdci = predefined polyline color index
      DO 200 PLI = 1, 5
C  get attributes for current bundle
         CALL PQPPLR (SPECWT, PLI, ERRIND, PDLT, PDLW, PDCI)
         CALL CHKINQ ('pqpplr', ERRIND)
C  compare current to all previous bundles
         DO 250 PLI2 = 1, PLI-1
            IF (SVPDLT (PLI2) .EQ. PDLT  .AND.
     1          SVPDLW (PLI2) .EQ. PDLW  .AND.
     2          SVPDCI (PLI2) .EQ. PDCI)     THEN
               CALL FAIL
               WRITE (MSG, '(A,I2,A,I2,A)') 'Polyline bundle #',
     1             PLI, ' is indistinguishable from #', PLI2, '.'
               CALL INMSG (MSG)
               GOTO 666
            ENDIF
250      CONTINUE
C  save current attributes
         SVPDLT (PLI) = PDLT
         SVPDLW (PLI) = PDLW
         SVPDCI (PLI) = PDCI
200   CONTINUE
      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
