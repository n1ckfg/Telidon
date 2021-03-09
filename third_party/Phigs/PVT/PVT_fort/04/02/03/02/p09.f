C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/09                        *
C  *    TEST TITLE : Text color index support              *
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
      INTEGER    LISTEL, MCI, UNDCI, NCE, COLI, RTXCI, IDUM1, IDUM2
      INTEGER    PREALI, PSTRKP
      PARAMETER  (PREALI = 1, PSTRKP = 2)
      REAL       RDUM1, RDUM2

      CHARACTER  MSG*300

      CALL INITGL ('04.02.03.02/09')

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

C  <set text representation>, index #6, text color index = mci
      CALL PSTXR (WKID, 6, 1, PSTRKP, 1.0, 0.0, MCI)
      CALL SETMSG ('15 65', '<Inquire text representation> should ' //
     1             'report a defined text color index realized '    //
     2             'as itself.')
C  <inquire text representation>, index #6 to determine
C  rtxci = realized text color index
      CALL PQTXR (WKID, 6, PREALI, ERRIND, IDUM1, IDUM2, RDUM1,
     1            RDUM2, RTXCI)
      CALL CHKINQ ('pqtxr', ERRIND)

      IF (RTXCI .EQ. MCI) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'Color set as ', MCI,
     1          ', but realized as ', RTXCI, '.'
         CALL INMSG (MSG)
      ENDIF

C  <set text representation>, index #6, text color index = undci
      CALL ERRCTL (.TRUE.)
      CALL PSTXR (WKID, 6, 1, PSTRKP, 1.0, 0.0, UNDCI)
      CALL ERRCTL (.FALSE.)
      CALL SETMSG ('63', 'Any non-negative color index should be ' //
     1             'accepted as valid.')
      CALL SIGTST (0, FAILED)

      IF (FAILED) THEN
         WRITE (MSG, '(A,I5,A)') 'Color set as ', UNDCI,
     1          ' signalled error.'
         CALL INMSG (MSG)
      ENDIF

      CALL SETMSG ('15 66', '<Inquire text representation> should ' //
     1             'report an undefined text color index realized ' //
     2             'as 1.')

C  <inquire text representation>, index #6 to determine
C  rtxci = realized text color index
      CALL PQTXR (WKID, 6, PREALI, ERRIND, IDUM1, IDUM2, RDUM1,
     1            RDUM2, RTXCI)
      CALL CHKINQ ('pqtxr', ERRIND)

      IF (RTXCI .EQ. 1) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color index realized as ',
     1          RTXCI, '.'
         CALL INMSG (MSG)
      ENDIF

666   CONTINUE
C wrap it up
      CALL ENDIT
      END

