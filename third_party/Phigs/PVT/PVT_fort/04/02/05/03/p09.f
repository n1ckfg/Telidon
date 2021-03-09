C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/09                        *
C  *    TEST TITLE : Edge color index                      *
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
      INTEGER    LISTEL, MCI, UNDCI, NCE, COLI, REDCI, IDUM1, IDUM2

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      REAL       RDUM1

      CHARACTER  MSG*300

      CALL INITGL ('04.02.05.03/09')

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

C  <set edge representation>, index #5, edge color index = mci
      CALL PSEDR (WKID, 5, PON, 1, 1.0, MCI)
      CALL SETMSG ('15 50 51', '<Inquire edge representation> ' //
     1             'should report a defined edge colour index ' //
     1             'realized as itself.')

C  <inquire edge representation>, index #5 to determine
C  redci = realized edge color index
      CALL PQEDR (WKID, 5, PREALI, ERRIND, IDUM1, IDUM2, RDUM1, REDCI)
      CALL CHKINQ ('pqedr', ERRIND)

      IF (REDCI .EQ. MCI) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'Color set as ', MCI,
     1          ', but realized as ', REDCI, '.'
         CALL INMSG (MSG)
      ENDIF

C  <set edge representation>, index #5, edge color index = undci
      CALL ERRCTL (.TRUE.)
      CALL PSEDR (WKID, 5, PON, 1, 1.0, UNDCI)
      CALL ERRCTL (.FALSE.)
      CALL SETMSG ('49', 'Any non-negative color index should be ' //
     1             'accepted as valid.')
      CALL SIGTST (0, FAILED)

      IF (FAILED) THEN
         WRITE (MSG, '(A,I5,A)') 'Color set as ', UNDCI,
     1          ' signalled error.'
         CALL INMSG (MSG)
      ENDIF

      CALL SETMSG ('15 50 52', '<Inquire edge representation> '    //
     1             'should report an undefined edge colour index ' //
     2             'realized as 1.')

C  <inquire edge representation>, index #5 to determine
C  redci = realized edge color index
      CALL PQEDR (WKID, 5, PREALI, ERRIND, IDUM1, IDUM2, RDUM1, REDCI)
      CALL CHKINQ ('pqedr', ERRIND)

      IF (REDCI .EQ. 1) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color index realized as ',
     1          REDCI, '.'
         CALL INMSG (MSG)
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
