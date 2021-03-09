C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/09                        *
C  *    TEST TITLE : Interior color index                  *
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
      INTEGER    LISTEL, MCI, UNDCI, NCE, COLI, RICI, IDUM1, IDUM2

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      CHARACTER  MSG*900

      CALL INITGL ('04.02.05.02/09')

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

C  <set interior representation>, index #5, interior color index = mci
      CALL PSIR (WKID, 5, PHOLLO, 1, MCI)
      CALL SETMSG ('16 51 52', '<Inquire interior representation> ' //
     1             'should report a defined interior color index '  //
     2             'realized as itself.')
C  <inquire interior representation>, index #5 to determine
C  rici = realized interior color index
      CALL PQIR (WKID, 5, PREALI, ERRIND, IDUM1, IDUM2, RICI)
      CALL CHKINQ ('pqir', ERRIND)

      IF (RICI .EQ. MCI) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'Color set as ', MCI,
     1          ', but realized as ', RICI, '.'
         CALL INMSG (MSG)
      ENDIF

C  <set interior representation>, index #5, interior color index = undci
      CALL ERRCTL (.TRUE.)
      CALL PSIR (WKID, 5, PHOLLO, 1, UNDCI)
      CALL ERRCTL (.FALSE.)
      CALL SETMSG ('50', 'Any non-negative color index should be ' //
     1             'accepted as valid.')
      CALL SIGTST (0, FAILED)

      IF (FAILED) THEN
         WRITE (MSG, '(A,I5,A)') 'Color set as ', UNDCI,
     1          ' signalled error.'
         CALL INMSG (MSG)
      ENDIF

      CALL SETMSG ('16 51 53', '<Inquire interior representation> ' //
     1             'should report an undefined interior color '     //
     2             'index realized as 1.')

C  <inquire interior representation>, index #5 to determine
C  rici = realized interior color index
      CALL PQIR (WKID, 5, PREALI, ERRIND, IDUM1, IDUM2, RICI)
      CALL CHKINQ ('pqir', ERRIND)

      IF (RICI .EQ. 1) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'Undefined color index realized as ',
     1          RICI, '.'
         CALL INMSG (MSG)
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
