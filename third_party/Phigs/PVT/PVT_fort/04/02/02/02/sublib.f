C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.02.02.02/rlzms                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION RLZMS (MSSET, MSEXP)

C  RLZMS sets a requested marker size scale factor in the polymarker bundle
C  table, and checks to see that it is realized approximately equal to the
C  expected value.

C  Input parameters:
C    MSSET : Requested value for marker size scale factor
C    MSEXP : Expected value for realized marker size scale factor

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER  IDUM1,IDUM2

      REAL     MSSET,MSEXP,RMS

      LOGICAL  APPEQ

      CALL PSPMR (WKID, 4, 1, MSSET, 1)
      CALL PQPMR (WKID, 4, PREALI, ERRIND, IDUM1, RMS, IDUM2)
      CALL CHKINQ ('pqpmr', ERRIND)
      RLZMS = APPEQ (RMS, MSEXP, 0.0, 0.02)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.02.02/dispmb                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE DISPMB (SAMP, START, UNIV, SUBSET)
 
C  DISPMB selects SAMP predefined bundles at random from the
C  polymarker bundle table which are distinct in all their attributes.
C  If there are not SAMP completely distinct bundles, DISPMB tries
C  to maximize the number of different attributes.
C
C  Input parameters:
C    SAMP        : number of predefined bundles to be picked
C    START       : starting index
C    UNIV        : last element in universe to pick from
C  Output parameters:
C    SUBSET      : array containing the selected distinct bundles
 
      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT, ERRIND
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
 
C  total number of attributes
      INTEGER    TOTATR
      PARAMETER (TOTATR=3)
 
      INTEGER    SAMP, START, UNIV, SUBSET(SAMP), I,J,JJ,K, OT
      INTEGER    ATRCNT, MAXATR,MAXLOC, JMT,KMT, JCI,KCI, RNDINT, OPTATR
 
      REAL       JMW,KMW
 
      LOGICAL    ATRNEW(TOTATR)
 
      IF (UNIV+1-START .LT. SAMP) THEN
         CALL UNMSG ('Abort in DISPMB because size of universe ' //
     1               'is less than requested sample.')
      ENDIF
 
C  OPTATR is the best possible number of attributes that can be distinct
      OPTATR = TOTATR
 
C  this loop picks out samp elements
      DO 500 I = 1, SAMP
C  number of new attribute values so far
         MAXATR = -1
C  look at entire universe each time, starting at random location
         J = RNDINT(START, UNIV)
         DO 400 JJ = START, UNIV
            IF (J.GE.UNIV) THEN
C  cycle around to beginning
               J = START
            ELSE
               J = J+1
            ENDIF
            DO 50 OT = 1,TOTATR
               ATRNEW(OT) = .TRUE.
50          CONTINUE
C  get attributes of next candidate
            CALL PQPPMR (SPECWT, J, ERRIND, JMT, JMW, JCI)
            CALL CHKINQ ('pqppmr', ERRIND)
 
C  check against all those picked so far;
            DO 300 K = 1, I-1
C  if already picked, get another j
               IF (J .EQ. SUBSET(K)) GOTO 400
               CALL PQPPMR (SPECWT, SUBSET(K), ERRIND, KMT,KMW,KCI)
               CALL CHKINQ ('pqppmr', ERRIND)
C  check all attributes
               IF (JMT .EQ. KMT) ATRNEW(1) = .FALSE.
               IF (JMW .EQ. KMW) ATRNEW(2) = .FALSE.
               IF (JCI .EQ. KCI) ATRNEW(3) = .FALSE.
300         CONTINUE
C  count # of trues
            ATRCNT = 0
            DO 75 OT = 1,TOTATR
               IF (ATRNEW(OT)) ATRCNT = ATRCNT + 1
75          CONTINUE
C  take the best so far
            IF (ATRCNT .GT. MAXATR) THEN
               MAXATR = ATRCNT
               MAXLOC = J
            ENDIF
C  cannot get better than OPTATR
            IF (MAXATR .GE. OPTATR) GOTO 410
400      CONTINUE
 
C  put best one on the list
410      CONTINUE
         SUBSET(I) = MAXLOC
C  remember greatest number of distinct attributes
         OPTATR = MAXATR
500   CONTINUE
 
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.02.02/drwpmb                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE DRWPMB (NUMBUN, BUNDIS, BUNDIF)
 
C  DRWPMB draws a set of actual polymarkers using the specified bundle
C  values, and a set of expected polymarkers, using the attribute
C  values returned by <inquire predefined polymarker representation>.
C  It draws the expected polymarker incorrectly at the specified
C  position.
C
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of polymarker bundle indices to be displayed
C    BUNDIF : position of polymarker to be drawn incorrectly
 
      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
 
C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
 
      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDMT,PDCI, BUNDIF, IX
 
      REAL     XA(1),YA(1), YINCR,YLOC, PDMW
 
C  draw and label actual; use ASFs bundle
      CALL SETASF (PBUNDL)
      XA(1) = 0.4
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.2, YLOC, YINCR)
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC
         CALL PSPMI (BUNDIS(IX))
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
100   CONTINUE
 
C  now draw expected  results - with individual attributes from WDT
      CALL SETASF (PINDIV)
      XA(1) = .7
      YLOC  = .9
 
      DO 200 IX = 1, NUMBUN
         CALL PQPPMR (SPECWT, BUNDIS(IX), ERRIND, PDMT, PDMW, PDCI)
         CALL CHKINQ ('pqppmr', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            PDMT = MOD(PDMT,5) + 1
            PDMW = PDMW * 1.5
            PDCI = MOD(PDCI,5) + 1
         ENDIF
         CALL PSMK   (PDMT)
         CALL PSMKSC (PDMW)
         CALL PSPMCI (PDCI)
         YA(1) = YLOC
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE
 
      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.02.02/shpmbw                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SHPMBW (HDING, WKID, REQMW, EXPMW, NOMMW, PFSW)

C  SHPMBW tests the rendering of a given marker size, and returns the
C  pass/fail result.
C
C  Input parameters:
C    HDING : Title for this test
C    WKID  : Workstation identifier
C    REQMW : The marker size (in DC) to be requested.
C    EXPMW : The expected marker size (in DC) - the one which should
C            be realized in order to pass.
C    NOMMW : The nominal marker size
C  Output parameters:
C    PFSW  : Result of the test - P for pass, F for fail, A for abort.

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    IX, NUMALT, RNDINT, ANS, PERM(20), WKID
      INTEGER    MKST, ERRIND, IDUM1,IDUM2,IDUM3

      REAL       REQMW, EXPMW, NOMMW, XA(60),YA(60), ALT(10)
      REAL       XLOC,YBASE, YLOC, XINCR, MSIZE
      REAL       PMX(1),PMY(1), YGAP, CENTX,CENTY
      REAL       SCRSIZ, SCRX,SCRY, MKRAD

      LOGICAL    DYN

      CHARACTER  PFSW*1, HDING*(*), MSG*300, DIGIT*1

C  can we fit 4 across in the picture area?
      IF (EXPMW * WCPDC .LT. 0.25) GOTO 50

C  can we fit on the screen as a whole? - if not, quit
      CALL PQDSP (SPECWT, ERRIND, IDUM1, SCRX,SCRY, IDUM2,IDUM3)
      CALL CHKINQ ('pqdsp', ERRIND)
      SCRSIZ = MIN(SCRX,SCRY)
      IF (EXPMW .GT. SCRSIZ) THEN
         PFSW = 'A'
         RETURN
      ENDIF

C  draw on full screen - override view #1
      CALL PSVWI (3)
C  use ASFs bundled
      CALL SETASF (PBUNDL)
C  attributes for actual marker, use index #13
      CALL PSPMR (WKID, 13, PPLUS, REQMW/NOMMW, 1)
      XA(1) = .5
      YA(1) = SYXRAT/2
      CALL PSPMI (13)
      CALL PPM (1, XA,YA)

C  MKRAD is simulated marker radius - this works because in
C  view #3, in x-dimension, WC:1 = DC:SCRX
      MKRAD = EXPMW / (2 * SCRX)
      CENTX = .5
      CENTY = SYXRAT/2
C  simulate circle to surround non-circle marker
      CALL SIMARK (POMARK, 1, MKRAD, CENTX,CENTY)

      IF (DYN('Does the marker fit exactly within the circle?')) THEN
         PFSW = 'P'
      ELSE
         PFSW = 'F'
      ENDIF
      GOTO 666

50    CONTINUE

C  alt = list of alternative operator choices for marker size
C  numalt = total number of alternative marker sizes generated
      CALL ALTSIZ (EXPMW, QVIS, 0.25 / WCPDC, 4, NUMALT,ALT)

      CALL RNPERM (NUMALT, PERM)

C  draw actual markers and simulate markers of various sizes
      XINCR = 1.0 / NUMALT
      XLOC  = XINCR/2
      YBASE = 0.375
      PMY(1) = YBASE
      YGAP = MAX(1.5 * EXPMW * WCPDC, 0.1)
      YLOC  = YBASE + YGAP
C  bundle for actual marker, use bundle 17
C  pick a marker between 2 and 4
      MKST = RNDINT(2,4)
      CALL PSPMR (WKID, 17, MKST, REQMW/NOMMW, 1)
      CALL PSPMI (17)
C  attributes for label
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)

      DO 500 IX = 1,NUMALT
C  reset  to bundled, since SIMARK uses individual
         CALL SETASF (PBUNDL)
C draw actual marker
         PMX(1) = XLOC
         CALL PPM (1, PMX,PMY)

C  simulate marker with polylines
         MSIZE = ALT(PERM(IX)) * WCPDC
         MKRAD = MSIZE / 2
         CALL SIMARK (MKST, 1, MKRAD, XLOC,YLOC)
C  now label
         WRITE (DIGIT, '(I1)') IX
         CALL PTX (XLOC, 0.175, DIGIT)

         XLOC = XLOC + XINCR
500   CONTINUE

      MSG = HDING // ': Which pair of markers has the same size?'
      CALL DCHOIC (MSG, 0,NUMALT, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPCOMT
         PFSW = 'F'
      ELSEIF (PERM(ANS) .EQ. 1) THEN
         PFSW = 'P'
      ELSE
         PFSW = 'F'
      ENDIF
666   CONTINUE
C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      END
