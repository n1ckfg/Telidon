C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.02.01.02/rlzlw                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION RLZLW (LWSET, LWEXP)

C  RLZLW sets a requested linewidth scale factor in the polyline bundle
C  table, and checks to see that it is realized approximately equal to the
C  expected value.

C  Input parameters:
C    LWSET : Requested value for linewidth scale factor
C    LWEXP : Expected value for realized linewidth scale factor

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

      REAL     LWSET,LWEXP,RLW

      LOGICAL  APPEQ

      CALL PSPLR (WKID, 4, 1, LWSET, 1)
      CALL PQPLR (WKID, 4, PREALI, ERRIND, IDUM1, RLW, IDUM2)
      CALL CHKINQ ('pqplr', ERRIND)
      RLZLW = APPEQ (RLW, LWEXP, 0.0, 0.02)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.01.02/displb                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DISPLB (SAMP, START, UNIV, SUBSET)

C  DISPLB selects SAMP predefined bundles at random from the
C  polyline bundle table which are distinct in all their attributes.
C  If there are not SAMP completely distinct bundles, DISPLB tries
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
      INTEGER    ATRCNT, MAXATR,MAXLOC, JLT,KLT, JCI,KCI, RNDINT, OPTATR

      REAL       JLW,KLW

      LOGICAL    ATRNEW(TOTATR)

      IF (UNIV+1-START .LT. SAMP) THEN
         CALL UNMSG ('Abort in DISPLB because size of universe ' //
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
            CALL PQPPLR (SPECWT, J, ERRIND, JLT, JLW, JCI)
            CALL CHKINQ ('pqpplr', ERRIND)

C  check against all those picked so far;
            DO 300 K = 1, I-1
C  if already picked, get another j
               IF (J .EQ. SUBSET(K)) GOTO 400
               CALL PQPPLR (SPECWT, SUBSET(K), ERRIND, KLT,KLW,KCI)
               CALL CHKINQ ('pqpplr', ERRIND)
C  check all attributes
               IF (JLT .EQ. KLT) ATRNEW(1) = .FALSE.
               IF (JLW .EQ. KLW) ATRNEW(2) = .FALSE.
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
C  *    SUBROUTINE 04.02.01.02/drwplb                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DRWPLB (NUMBUN, BUNDIS, BUNDIF)

C  DRWPLB draws a set of actual polylines using the specified bundle
C  values, and a set of expected polylines, using the attribute
C  values returned by <inquire predefined polyline representation>.
C  It draws the expected polyline incorrectly at the specified
C  position.
C  
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of polyline bundle indices to be displayed
C    BUNDIF : position of polyline to be drawn incorrectly

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

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDLT,PDCI, BUNDIF, IX

      REAL     XA(2),YA(2), YINCR,YLOC, PDLW

C  draw and label actual; use individual attributes
      CALL SETASF (PBUNDL)
      XA(1) = 0.25
      XA(2) = 0.55
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.2, YLOC, YINCR)
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PSPLI (BUNDIS(IX))
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
100   CONTINUE

C  now draw expected results - with individual attributes from WDT
C  use individual attributes
      CALL SETASF (PINDIV)
      XA(1) = .6
      XA(2) = .9
      YLOC  = .9

      DO 200 IX = 1, NUMBUN
         CALL PQPPLR (SPECWT, BUNDIS(IX), ERRIND, PDLT, PDLW, PDCI)
         CALL CHKINQ ('pqpplr', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            PDLT = MOD(PDLT,4) + 1
            PDLW = PDLW * 1.5
            PDCI = MOD(PDCI,5) + 1
         ENDIF
         CALL PSLN   (PDLT)
         CALL PSLWSC (PDLW)
         CALL PSPLCI (PDCI)
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.01.02/shplbw                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SHPLBW (HDING, WKID, REQLW, EXPLW, NOMLW,
     1                   MINLW, PFSW)

C  SHPLBW tests the rendering of a given linewidth, and returns the
C  pass/fail result.  
C
C  Input parameters:
C    HDING : Title for this test
C    WKID  : Workstation identifier
C    REQLW : The linewidth (in DC) to be requested.
C    EXPLW : The expected linewidth (in DC) - the one which should
C            be realized in order to pass.
C    NOMLW : The nominal linewidth
C    MINLW : The minimum linewidth
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

C aspect identifier
      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    IX, NUMALT, ANS, PERM(20), WKID

      REAL       REQLW, EXPLW, NOMLW, MINLW, XA(5),YA(5), ALT(10)
      REAL       XLOC,YBASE, XINCR, FSIZE, XMARG,XLEN,XGAP

      CHARACTER  PFSW*1, HDING*(*), MSG*300, DIGIT*1

      YBASE = 0.2
C  can we fit in top of picture area? - if not, quit
      IF (EXPLW * WCPDC .GT. 1-YBASE) THEN
         PFSW = 'A'
         RETURN
      ENDIF

C  get list of alternate sizes
      CALL ALTSIZ (EXPLW, QVIS, (1.0-YBASE) / WCPDC, 4, NUMALT,ALT)
      CALL RNPERM (NUMALT, PERM)

C  draw actual and simulated lines of various widths
C  first simulated -use individual attributes
      CALL SETASF (PINDIV)
      CALL PSLN   (PLSOLI)
      CALL PSPLCI (1)
      CALL PSLWSC (0.0)
      XINCR = 1.0 / NUMALT
      XLOC  = 0.0
      XMARG =  3*XINCR/25
      XGAP  =    XINCR/25
      XLEN  = (XINCR - XGAP - 2*XMARG) / 2
      YA(2) = YBASE + MINLW * WCPDC / 2
      YA(3) = YA(2)
      DO 500 IX = 1,NUMALT
C  size of linewidth to be simulated - allow for thickness
C  of simulating polylines by subtracting minimum linewidth.
         FSIZE = (ALT(PERM(IX))-MINLW) * WCPDC
         YA(1) = YA(2) + FSIZE
         YA(4) = YA(1)
         YA(5) = YA(1)
         XA(1) = XLOC + XMARG
         XA(2) = XA(1)
         XA(5) = XA(1)
         XA(3) = XA(1) + XLEN
         XA(4) = XA(3)
         CALL PPL (5, XA,YA)
         XLOC = XLOC + XINCR
500   CONTINUE

C  now actual - use bundle attributes
C  use bundle index #5
      CALL SETASF (PBUNDL)
      CALL PSPLR (WKID, 5, 1, REQLW/NOMLW, 1)
      CALL PSPLI (5)
C  set up text for individual attributes
      DO 110 IX = PTXFN,PTXCI
         CALL PSIASF (IX, PINDIV)
110   CONTINUE
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)
      XLOC = 0.0
      YA(1) = YBASE + EXPLW * WCPDC / 2
      YA(2) = YA(1)
      DO 600 IX = 1,NUMALT
         XA(1) = XLOC + XMARG + XLEN + XGAP
         XA(2) = XA(1) + XLEN
         CALL PPL (2, XA,YA)
         WRITE (DIGIT, '(I1)') IX
         CALL PTX (XLOC + XINCR/2, YBASE - 0.05, DIGIT)
         XLOC = XLOC + XINCR
600   CONTINUE

      MSG = HDING // ': Which pair has the same vertical thickness?'

      CALL DCHOIC (MSG, 0,NUMALT, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPCOFL
         PFSW = 'F'
      ELSEIF (PERM(ANS) .EQ. 1) THEN
         PFSW = 'P'
      ELSE
         PFSW = 'F'
      ENDIF

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      END
