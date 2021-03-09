C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.04/06                        *
C  *    TEST TITLE : Pattern color index array             *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER    SPECWT, SPECON, LISTEL, MCI, COLI, UNDCI, NCE
C set up pattern color index array
      INTEGER    DIMX, DIMY, ISC, ISR, DX, DY, RDX, RDY
      PARAMETER  (DIMX = 100, DIMY = 100 )
      INTEGER    COLIA(DIMX,DIMY), RCOLIA(DIMX, DIMY)
      INTEGER    IDUM1

      LOGICAL    PATAVL, FAILED, ARREQ

      CHARACTER  MSG*300

      CALL INITGL ('04.02.05.04/06')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      IF (.NOT. PATAVL(SPECWT)) THEN
         CALL INMSG ('Skipping all tests because pattern interior ' //
     1               'style is not supported on this workstation.')
         GOTO 666
      ENDIF

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

C  <set pattern representation>, index #5, starting at isc=6, isr=4
C  pattern color index array = mci mci
C                              mci mci
      ISC = 6
      ISR = 4
      DX =  2
      DY =  2
      COLIA(6,4) = MCI
      COLIA(7,4) = MCI
      COLIA(6,5) = MCI
      COLIA(7,5) = MCI

      CALL PSPAR (WKID, 5, DIMX, DIMY, ISC, ISR, DX, DY, COLIA)
      CALL SETMSG ('6 20', '<Inquire pattern representation> '       //
     1             'should report a defined pattern color index in ' //
     2             'the pattern color index array realized as itself.')

C  <inquire pattern representation>, index #5 to determine
C  rcolia = realized pattern color index array
      CALL PQPAR (WKID, 5, PREALI, DIMX, DIMY, ERRIND, RDX, RDY, RCOLIA)
      CALL CHKINQ ('pqpar', ERRIND)

C check all entries in rcolia
      CALL IFPF (DX .EQ. RDX   .AND.
     1           DY .EQ. RDY   .AND.
     2           ARREQ (DIMX, DIMY, ISC, ISR, DX, DY, COLIA, RCOLIA ))

C  <set pattern representation>, index #5, isc=1, isr=1
C  pattern color index array = undci undci
C                              undci undci
      ISC = 1
      ISR = 1
      COLIA(1,1) = UNDCI
      COLIA(2,1) = UNDCI
      COLIA(1,2) = UNDCI
      COLIA(2,1) = UNDCI

      CALL ERRCTL (.TRUE.)
      CALL PSPAR (WKID, 5, DIMX, DIMY, ISC, ISR, DX, DY, COLIA)
      CALL ERRCTL (.FALSE.)
      CALL SETMSG ('19', 'Any non-negative color index specified ' //
     1             'in the pattern color index array should be '   //
     2             'accepted as valid.')
      CALL SIGTST (0, FAILED)

      IF (FAILED) THEN
         WRITE (MSG, '(A,I5,A)') 'Color set as ', UNDCI,
     1      ' signalled error.'
         CALL INMSG (MSG)
      ENDIF

      CALL SETMSG ('6 21', '<Inquire pattern representation> '      //
     1             'should report an undefined color index in the ' //
     2             'pattern color index array realized as 1.')

C  <inquire pattern representation>, index #5 to determine
C  rcolia = realized pattern color index array
      CALL PQPAR (WKID, 5, PREALI, DIMX, DIMY, ERRIND, RDX, RDY, RCOLIA)
      CALL CHKINQ ('pqpar', ERRIND)

C check all entries in rcolia
      CALL IFPF (RDX          .EQ. DX  .AND.
     1           RDY          .EQ. DY  .AND.
     2           RCOLIA(1,1)  .EQ. 1   .AND.
     3           RCOLIA(1,2)  .EQ. 1   .AND.
     4           RCOLIA(2,1)  .EQ. 1   .AND.
     5           RCOLIA(2,2)  .EQ. 1)

666   CONTINUE
      CALL ENDIT
      END
