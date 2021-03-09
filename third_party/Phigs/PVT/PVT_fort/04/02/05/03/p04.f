C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/04                        *
C  *    TEST TITLE : Validity of predefined edge           *
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

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      INTEGER   IDUM1, IDUM2, IDUM3
      INTEGER   MPCI, NPE, EDI, EDI2, ERBUN
      INTEGER   EDCI, EDFL, EDTY, REDTY, PDEF, PDET, PDCI, NAET
      INTEGER   EDCI2, EDFL2, EDTY2
      INTEGER   EREDCI, ERFLG, EREDTY, SVPDET(5), SVPDCI(5), SVPDEF(5)

      REAL      RDUM1, RDUM2, RDUM3, RDUM4(9)
      REAL      EWSF, EWSF2, GENEW, EREW, NOMEW,MINEW,MAXEW
      REAL      SVPDEW(5), PDEW

      LOGICAL   FLGERR, EDGERR, EWERR, COLERR, RLZERR

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.03/04')

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
C  naet = number of available edgetypes
C  nomew = nominal edgewidth
C  minew = minimum edgewidth
C  maxew = maximum edgewidth
      CALL PQEDF (SPECWT, 0, ERRIND, NAET, IDUM1, IDUM2,
     1            NOMEW, MINEW, MAXEW, NPE)
      CALL CHKINQ ('pqedf', ERRIND)


C  edge flag error found yet
      FLGERR = .FALSE.
C  edgetype error found yet
      EDGERR = .FALSE.
C  edgewidth error found yet
      EWERR  = .FALSE.
C  color error found yet
      COLERR = .FALSE.
C  rlzerr = realized error found yet
      RLZERR = .FALSE.

      CALL SETMSG ('19 20 23', '<Inquire predefined edge '        //
     1             'representation> should be able to access as ' //
     2             'many entries as reported by <inquire edge '   //
     3             'facilities>.')

      DO 100 EDI = 1, NPE
         CALL PQPEDR (SPECWT, EDI, ERRIND, EDFL, EDTY, EWSF, EDCI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 150
         ENDIF

         IF (EDFL .LT. POFF .OR. EDFL .GT. PON) THEN
            FLGERR = .TRUE.
            ERFLG = EDFL
         ENDIF

         DO 50 EDI2 = 1, NAET
            CALL PQEDF (SPECWT, EDI2, ERRIND, IDUM1, REDTY, IDUM2,
     1                  RDUM1, RDUM2, RDUM3, IDUM3)
            CALL CHKINQ ('pqedf', ERRIND)
            IF (EDTY .EQ. REDTY) GOTO 60
50       CONTINUE
         EDGERR = .TRUE.
         EREDTY = EDTY

60       CONTINUE
         GENEW = EWSF * NOMEW
         IF (GENEW .LT. MINEW .OR. GENEW .GT. MAXEW) THEN
            EWERR = .TRUE.
            EREW  = EWSF
         ENDIF

         IF (EDCI .LT. 0 .OR. EDCI .GT. MPCI) THEN
            COLERR = .TRUE.
            EREDCI = EDCI
         ENDIF

         CALL PSEDR (WKID, 3, EDFL, EDTY, EWSF, EDCI)
         CALL PQEDR (WKID, 3, PREALI, ERRIND, EDFL2,EDTY2,EWSF2,EDCI2)
         CALL CHKINQ ('pqedr', ERRIND)
         IF (EDFL.EQ.EDFL2 .AND. EDTY.EQ.EDTY2 .AND.
     1       EWSF.EQ.EWSF2 .AND. EDCI.EQ.EDCI2) THEN
C           OK
         ELSE
            RLZERR = .TRUE.
            ERBUN  = EDI
         ENDIF

100   CONTINUE
      CALL PASS

      CALL SETMSG ('20 29', 'The edge flag in predefined edge ' //
     1             'bundles should be either OFF or ON.')
      IF (FLGERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined edge flag', ERFLG,
     1                           ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 26', 'All edgetypes in predefined edge '   //
     1             'bundles should themselves be in the list of ' //
     2             'available edgetypes.')
      IF (EDGERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined edgetype #', EREDTY,
     1                           ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 27', 'All edgewidth scale factors in '   //
     1             'predefined edge bundles should generate '   //
     2             'edgewidths within the minimum and maximum ' //
     3             'edgewidths.')
      IF (EWERR) THEN
         CALL FAIL
         WRITE (MSG,'(A,F11.4,A)')
     1          'Unrealizable edgewidth scale factor, ',
     2           EREW, ', found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 28', 'All color indices in predefined edge '  //
     1             'bundles should themselves be in the predefined ' //
     2             'color table.')
      IF (COLERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color #', EREDCI,
     1                           ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('15 26 27 28 29', 'All aspects of all predefined ' //
     1             'edge bundles should be reported as realizable '   //
     2             'by <inquire edge representation>.')
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
     1                        ' predefined edge bundles.'
      CALL INMSG (MSG)
      CALL SETMSG ('19 21', '<Inquire edge facilities> should ' //
     1             'report at least 5 predefined entries.')
      IF (NPE .LT. 5) THEN
         CALL FAIL
         GOTO 666
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 22', 'The first five predefined edge ' //
     1             'bundle entries should all be mutually '   //
     2             'distinguishable.')

C  pdef = predefined edge flag
C  pdet = predefined edgetype
C  pdew = predefined edgewidth scale factor
C  pdci = predefined edge color index
      DO 200 EDI = 1, 5
C  get attributes for current bundle
         CALL PQPEDR (SPECWT, EDI, ERRIND, PDEF, PDET, PDEW, PDCI)
         CALL CHKINQ ('pqpedr', ERRIND)
C  compare current to all previous bundles
         DO 250 EDI2 = 1, EDI-1
            IF (SVPDEF (EDI2) .EQ. PDEF  .AND.
     1          SVPDET (EDI2) .EQ. PDET  .AND.
     2          SVPDEW (EDI2) .EQ. PDEW  .AND.
     3          SVPDCI (EDI2) .EQ. PDCI)     THEN
               CALL FAIL
               WRITE (MSG, '(A,I2,A,I2,A)') 'Edge bundle #',
     1                EDI, ' is indistinguishable from #', EDI2, '.'
               CALL INMSG (MSG)
               GOTO 666
            ENDIF
250      CONTINUE
C  save current attributes
         SVPDEF (EDI) = PDEF
         SVPDET (EDI) = PDET
         SVPDEW (EDI) = PDEW
         SVPDCI (EDI) = PDCI
200   CONTINUE
      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
