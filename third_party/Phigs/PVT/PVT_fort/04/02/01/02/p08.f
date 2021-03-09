C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/08                        *
C  *    TEST TITLE : Polyline color index                  *
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

      LOGICAL    FAILED
      INTEGER    LISTEL, MCI, UNDCI, NCE, COLI, RPLCI, IDUM1
      REAL       RDUM1

      CHARACTER  MSG*300

      CALL INITGL ('04.02.01.02/08')

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

C  <set polyline representation>, index #5, polyline color index = mci
      CALL PSPLR (WKID, 5, 1, 1.0, MCI)
      CALL SETMSG ('15 47 48', '<Inquire polyline representation> '//
     1             'should report a defined polyline colour index '//
     1             'realized as itself.')

C  <inquire polyline representation>, index #5 to determine
C  rplci = realized polyline color index
      CALL PQPLR (WKID, 5, 1, ERRIND, IDUM1, RDUM1, RPLCI)
      CALL CHKINQ ('pqplr', ERRIND)

      IF (RPLCI .EQ. MCI) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'Color set as ', MCI,
     1      ', but realized as ', RPLCI, '.'
         CALL INMSG (MSG)
      ENDIF

C  <set polyline representation>, index #5, polyline color index = undci
      CALL ERRCTL (.TRUE.)
      CALL PSPLR (WKID, 5, 1, 1.0, UNDCI)
      CALL ERRCTL (.FALSE.)
      CALL SETMSG ('46', 'Any non-negative color index should be ' //
     1             'accepted as valid.')
      CALL SIGTST (0, FAILED)

      IF (FAILED) THEN
         WRITE (MSG, '(A,I5,A)') 'Color set as ', UNDCI,
     1      ' signalled error.'
         CALL INMSG (MSG)
      ENDIF

      CALL SETMSG ('15 47 49', '<Inquire polyline representation> '//
     1             'should report an undefined polyline colour ' //
     2             'index realized as 1.')

C  <inquire polyline representation>, index #5 to determine
C  rplci = realized polyline color index
      CALL PQPLR (WKID, 5, 1, ERRIND, IDUM1, RDUM1, RPLCI)
      CALL CHKINQ ('pqplr', ERRIND)

      IF (RPLCI .EQ. 1) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color index realized as ',
     1                            RPLCI, '.'
         CALL INMSG (MSG)
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
