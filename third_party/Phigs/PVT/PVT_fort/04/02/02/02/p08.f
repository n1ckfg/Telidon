C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/08                        *
C  *    TEST TITLE : Polymarker color index                *
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

      LOGICAL    FAILED
      INTEGER    LISTEL, MCI, UNDCI, NCE, COLI, RPMCI, IDUM1
      REAL       RDUM1

      CHARACTER  MSG*300

      CALL INITGL ('04.02.02.02/08')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)

C  loop thru color table to determine mci (maximum defined color index)
C  nce = number of color entries
      CALL PQECI (WKID, 0, ERRIND, NCE, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      MCI = -9999
      DO 100 LISTEL = 1,NCE
         CALL PQECI (WKID, LISTEL, ERRIND, IDUM1, COLI)
         CALL CHKINQ ('pqeci', ERRIND)
         IF (MCI .LT. COLI) MCI = COLI
100   CONTINUE

C  undci = = undefined color index
      UNDCI = MCI + 1

C  <set polymarker representation>, index #5, polymarker color index = mci
      CALL PSPMR (WKID, 5, 1, 1.0, MCI)
      CALL SETMSG ('15 48 49', '<Inquire polymarker representation> ' //
     1             'should report a defined polymarker colour index ' //
     2             'realized as itself.')
C  <inquire polymarker representation>, index #5 to determine
C  rpmci = realized polymarker color index
      CALL PQPMR (WKID, 5, PREALI, ERRIND, IDUM1, RDUM1, RPMCI)
      CALL CHKINQ ('pqpmr', ERRIND)

      IF (RPMCI .EQ. MCI) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'Color set as ', MCI,
     1      ', but realized as ', RPMCI, '.'
         CALL INMSG (MSG)
      ENDIF

C  <set polymarker representation>, index #5, polymarker color index = undci
      CALL ERRCTL (.TRUE.)
      CALL PSPMR (WKID, 5, 1, 1.0, UNDCI)
      CALL ERRCTL (.FALSE.)
      CALL SETMSG ('47', 'Any non-negative color index should be ' //
     1             'accepted as valid.')
      CALL SIGTST (0, FAILED)

      IF (FAILED) THEN
         WRITE (MSG, '(A,I5,A)') 'Color set as ', UNDCI,
     1      ' signalled error.'
         CALL INMSG (MSG)
      ENDIF

      CALL SETMSG ('15 48 50', '<Inquire polymarker representation> ' //
     1             'should report an undefined polymarker colour '    //
     2             'index realized as 1.')

C  <inquire polymarker representation>, index #5 to determine
C  rpmci = realized polymarker color index
      CALL PQPMR (WKID, 5, PREALI, ERRIND, IDUM1, RDUM1, RPMCI)
      CALL CHKINQ ('pqpmr', ERRIND)

      IF (RPMCI .EQ. 1) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color index realized as ',
     1                            RPMCI, '.'
         CALL INMSG (MSG)
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
