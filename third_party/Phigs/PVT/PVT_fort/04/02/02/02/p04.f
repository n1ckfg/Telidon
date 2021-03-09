C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/04                        *
C  *    TEST TITLE : Validity of predefined polymarker     *
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

      INTEGER   MPCI, NPE, PMI, PMCI, PMCI2, ERPMCI, IDUM1,IDUM2,IDUM3
      INTEGER   PMI2, SVPDMT (5), PDMT, SVPDCI (5), PDCI, ERBUN
      INTEGER   MTYPE, MTYPE2, RMTYPE, ERPMMT, MI, NAMT

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, RDUM4(9), SVPDMS(5), ERMS
      REAL      PDMS, NOMMS, MINMS, MAXMS, PMSSF, PMSSF2, GENMS

      LOGICAL   MARERR, MSERR, COLERR, RLZERR

      CHARACTER MSG*300

      CALL INITGL ('04.02.02.02/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  mpci = maximum predefined color index
      CALL PQCF   (SPECWT, ERRIND, IDUM1, IDUM2, MPCI, RDUM4)
      CALL CHKINQ ('pqcf', ERRIND)
C  Since color indices are numbered from 0, the maximum index is
C  one less than the number of predefined indices.
      MPCI = MPCI - 1

C  npe = number of predefined entries
C  namt = number of available marker types
C  nomms = nominal marker size
C  minms = minimum marker size
C  maxms = maximum marker size
      CALL PQPMF  (SPECWT, 0, ERRIND, NAMT, IDUM2, IDUM3,
     1             NOMMS, MINMS, MAXMS, NPE)
      CALL CHKINQ ('pqpmf', ERRIND)

C  marerr = marker type error found yet
      MARERR = .FALSE.
C  mserr  = marker size error found yet
      MSERR  = .FALSE.
C  colerr = color error found yet
      COLERR = .FALSE.
C  rlzerr = realized error found yet
      RLZERR = .FALSE.

      CALL SETMSG ('19 20 23', '<Inquire predefined polymarker '      //
     1             'representation> should be able to access as '     //
     2             'many entries as reported by <inquire polymarker ' //
     3             'facilities>.')
      DO 100 PMI = 1, NPE
         CALL PQPPMR (SPECWT, PMI, ERRIND, MTYPE, PMSSF, PMCI)
         IF (ERRIND .NE. 0) THEN
            CALL FAIL
            GOTO 150
         ENDIF

         DO 50 MI = 1, ABS(NAMT)
            CALL PQPMF  (SPECWT, MI, ERRIND, IDUM1, RMTYPE, IDUM3,
     1                   RDUM1, RDUM2, RDUM3, NPE)
            CALL CHKINQ ('pqpmf', ERRIND)
            IF (MTYPE .EQ. RMTYPE) GOTO 60
50       CONTINUE
         MARERR = .TRUE.
         ERPMMT = MTYPE

60       CONTINUE
         GENMS = PMSSF * NOMMS
         IF (GENMS .LT. MINMS .OR. GENMS .GT. MAXMS) THEN
            MSERR = .TRUE.
            ERMS  = PMSSF
         ENDIF

         IF (PMCI .LT. 0 .OR. PMCI .GT. MPCI) THEN
            COLERR = .TRUE.
            ERPMCI = PMCI
         ENDIF

         CALL PSPMR (WKID, 3, MTYPE,  PMSSF,  PMCI)
         CALL PQPMR (WKID, 3, PREALI, ERRIND, MTYPE2, PMSSF2, PMCI2)
         CALL CHKINQ ('pqpmr', ERRIND)
         IF (MTYPE.EQ.MTYPE2 .AND. PMSSF.EQ.PMSSF2
     1                       .AND. PMCI.EQ.PMCI2) THEN
C           OK
         ELSE
            RLZERR = .TRUE.
            ERBUN  = PMI
         ENDIF
100   CONTINUE

      CALL PASS

      CALL SETMSG ('20 26', 'All marker types in predefined '    //
     1             'polymarker bundles should themselves be in ' //
     2             'the list of available marker types.')
      IF (MARERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined marker type #', ERPMMT,
     1                        ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 27', 'All marker size scale factors in '     //
     1             'predefined polymarker bundles should generate ' //
     2             'marker sizes within the minimum and maximum '   //
     3             'marker sizes.')
      IF (MSERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,F11.4,A)')
     1          'Unrealizable marker size scale factor, ',
     2           ERMS, ', found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 28', 'All color indices in predefined '   //
     1             'polymarker bundles should themselves be in ' //
     2             'the predefined color table.')
      IF (COLERR) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color #', ERPMCI,
     1                        ' found in predefined bundle.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('15 26 27 28', 'All aspects of all predefined '   //
     1             'polymarker bundles should be reported as '       //
     2             'realizable by <inquire polymarker representation>.')
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
     1         ' predefined polymarker bundles.'
      CALL INMSG (MSG)
      CALL SETMSG ('19 21', '<Inquire polymarker facilities> should ' //
     1             'report at least 5 predefined entries.')
      IF (NPE .LT. 5) THEN
         CALL FAIL
         GOTO 666
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 22', 'The first five predefined polymarker ' //
     1             'bundle entries should all be mutually '         //
     2             'distinguishable.')

C  pdmt = predefined marker type
C  pdms = predefined marker size scale factor
C  pdci = predefined polymarker color index
      DO 200 PMI = 1, 5
C  get attributes for current bundle
         CALL PQPPMR (SPECWT, PMI, ERRIND, PDMT, PDMS, PDCI)
         CALL CHKINQ ('pqppmr', ERRIND)
C  compare current to all previous bundles
         DO 250 PMI2 = 1, PMI-1
            IF (SVPDMT (PMI2) .EQ. PDMT  .AND.
     1          SVPDMS (PMI2) .EQ. PDMS  .AND.
     2          SVPDCI (PMI2) .EQ. PDCI)     THEN
               CALL FAIL
               WRITE (MSG, '(A,I2,A,I2,A)') 'Polymarker bundle #',
     1             PMI, ' is indistinguishable from #', PMI2, '.'
               CALL INMSG (MSG)
               GOTO 666
            ENDIF
250      CONTINUE
C  save current attributes
         SVPDMT (PMI) = PDMT
         SVPDMS (PMI) = PDMS
         SVPDCI (PMI) = PDCI
200   CONTINUE
      CALL PASS

666   CONTINUE
      CALL ENDIT
      END
