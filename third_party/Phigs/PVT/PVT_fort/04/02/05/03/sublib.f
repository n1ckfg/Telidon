C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.02.05.03/rlzew                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION RLZEW (EWSET, EWEXP)

C  RLZEW sets a requested edgewidth scale factor in the edge bundle
C  table, and checks to see that it is realized approximately equal to the
C  expected value.

C  Input parameters:
C    EWSET : Requested value for edgewidth scale factor
C    EWEXP : Expected value for realized edgewidth scale factor

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

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER  IDUM1,IDUM2

      REAL     EWSET,EWEXP,REW

      LOGICAL  APPEQ

      CALL PSEDR (WKID, 4, POFF, 1, EWSET, 1)
      CALL PQEDR (WKID, 4, PREALI, ERRIND, IDUM1, IDUM2, REW, IDUM2)
      CALL CHKINQ ('pqedr', ERRIND)
      RLZEW = APPEQ (REW, EWEXP, 0.0, 0.02)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.03/disedb                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DISEDB (SAMP, START, UNIV, SUBSET)

C  DISEDB selects SAMP predefined bundles at random from the
C  edge bundle table which are distinct in all their attributes.
C  If there are not SAMP completely distinct bundles, DISEDB tries
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

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C  total number of attributes
      INTEGER    TOTATR
      PARAMETER (TOTATR=4)

      INTEGER    SAMP, START, UNIV, SUBSET(SAMP), I,J,JJ,K, OT
      INTEGER    ATRCNT, MAXATR,MAXLOC, JEF, JET,  JECI,
     1           KEF, KET, KECI, RNDINT, OPTATR

      REAL       JEW,KEW

      LOGICAL    ATRNEW(TOTATR)

      IF (UNIV+1-START .LT. SAMP) THEN
         CALL UNMSG ('Abort in DISEDB because size of universe ' //
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
            CALL PQPEDR (SPECWT, J, ERRIND, JEF, JET, JEW, JECI)
            CALL CHKINQ ('pqpedr', ERRIND)

C  check against all those picked so far;
            DO 300 K = 1, I-1
C  if already picked, get another j
               IF (J .EQ. SUBSET(K)) GOTO 400
               CALL PQPEDR (SPECWT, SUBSET(K),ERRIND,KEF,KET,KEW,KECI)
               CALL CHKINQ ('pqpedr', ERRIND)
C  check all attributes
               IF (JEF .EQ. KEF) THEN
                  IF (JEF .EQ. POFF) THEN
C  edge flag off implies all other attributes indistinguishable
                     ATRCNT = 0
                     GOTO 80
                  ELSE
                     ATRNEW(1) = .FALSE.
                  ENDIF
               ENDIF
               IF (JET .EQ. KET) ATRNEW(2) = .FALSE.
               IF (JEW .EQ. KEW) ATRNEW(3) = .FALSE.
               IF (JECI .EQ. KECI) ATRNEW(4) = .FALSE.
300         CONTINUE
C  count # of trues = # of distinct attributes
            ATRCNT = 0
            DO 75 OT = 1,TOTATR
               IF (ATRNEW(OT)) ATRCNT = ATRCNT + 1
75          CONTINUE
80          CONTINUE
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
C  *    SUBROUTINE 04.02.05.03/drwedb                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DRWEDB (NUMBUN, BUNDIS, BUNDIF, NUMET)

C  DRWEDB draws a set of actual edges using the specified bundle
C  values, and a set of expected edges, using the attribute
C  values returned by <inquire predefined edge representation>.
C  It draws the expected edge incorrectly at the specified
C  position.
C  
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of edge bundle indices to be displayed
C    BUNDIF : position of edge to be drawn incorrectly
C    NUMET  : number of edge types

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDEF, PDET, PDCI
      INTEGER  BUNDIF, IX, NPTS(1), NUMET

      REAL     XA(4),YA(4), YINCR,YLOC, PDEW

C  draw triangles to display edge
      NPTS(1) = 3

C  draw and label actual
      CALL DRBUED (NUMBUN, BUNDIS)

C  now draw expected results - with individual attributes from WDT
C  use individual attributes
      CALL SETASF (PINDIV)
      XA(1) = .6
      XA(2) = .6
      XA(3) = .9
      YLOC  = .9
      YINCR = 0.8/NUMBUN

      DO 200 IX = 1, NUMBUN
         CALL PQPEDR (SPECWT, BUNDIS(IX), ERRIND, 
     1                PDEF, PDET, PDEW, PDCI)
         CALL CHKINQ ('pqpedr', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            IF (NUMET .EQ. 1) THEN
C  switch edge flag
               IF (PDEF .EQ. PON) THEN
                  PDEF = POFF
               ELSE
                  PDEF = PON
               ENDIF
            ENDIF
            PDET = MOD(PDET, 4) + 1
            PDEW = PDEW * 1.3
            PDCI = MOD(PDCI, 5) + 1
         ENDIF
         CALL PSEDFG (PDEF)
         CALL PSEDT  (PDET)
         CALL PSEWSC (PDEW)
         CALL PSEDCI (PDCI)

         YA(1) = YLOC - 0.25*YINCR
         YA(2) = YLOC + 0.25*YINCR
         YA(3) = YLOC - 0.25*YINCR

         CALL PFAS  (1, NPTS, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.03/drbued                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DRBUED (NUMBUN, BUNDIS)

C  DRBUED draws a set of edges using the specified edge bundle
C  values.

C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of edge bundle indices to be displayed

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER  NUMBUN, BUNDIS(NUMBUN),IX, NPTS(1)

      REAL     XA(4),YA(4), YINCR,YLOC

      NPTS(1) = 3
      XA(1) = 0.25
      XA(2) = 0.25
      XA(3) = 0.55
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.2, YLOC, YINCR)
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC - 0.25*YINCR
         YA(2) = YLOC + 0.25*YINCR
         YA(3) = YLOC - 0.25*YINCR
         CALL PSEDI(BUNDIS(IX))
         CALL PFAS  (1, NPTS, XA, YA)
         YLOC  = YLOC-YINCR
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.03/shedbw                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SHEDBW (HDING, WKID, REQEW, EXPEW, NOMEW,
     1                   MINLW, PFSW)

C  SHEDBW tests the rendering of a given edgewidth, and returns the
C  pass/fail result, or an abort signal if the requested edge is
C  too wide to be tested.

C  Input parameters:
C    HDING : Title for this test
C    WKID  : Workstation identification
C    REQEW : The edgewidth (in DC) to be requested.
C    EXPEW : The expected edgewidth (in DC) - the one which should
C            be realized in order to pass.
C    NOMEW : The nominal edgewidth
C    MINLW : The minimum linewidth (used for simulation)
C  Output parameters:
C    PFSW  : Result of the test - P:pass, F:fail, A:abort.

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS


C aspect source
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C edge-, line-type
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C edge flag indicator
      INTEGER    POFF,    PON
      PARAMETER (POFF=0, PON=1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    WKID
      INTEGER    IX, NUMALT, ANS, PERM(20)
      INTEGER    NPTS(1)

      REAL       REQEW, EXPEW, NOMEW, MINLW, XA(5),YA(5),ZA(5)
      REAL       XLOC,YBASE, XINCR, FSIZE, XMARG,XLEN,XGAP,  ALT(10)

      CHARACTER  PFSW*1, HDING*(*), MSG*300, DIGIT*1

      YBASE = 0.2
C  can we fit in top of picture area? - if not, quit
      IF (EXPEW * WCPDC .GT. 1-YBASE) THEN
         PFSW = 'A'
         RETURN
      ENDIF

C  get list of alternate sizes
      CALL ALTSIZ (EXPEW, QVIS, (1.0-YBASE) / WCPDC, 4, NUMALT,ALT)
      CALL RNPERM (NUMALT, PERM)

C  draw actual and simulated edges of various widths
C  first simulated - use individual attributes 
      CALL SETASF (PINDIV)
      CALL PSLN (PLSOLI)
      CALL PSPLCI (1)
      CALL PSLWSC (0.0)
      XINCR = 1.0 / NUMALT
      XLOC  = 0.0 
      XGAP  = XINCR/25
      XMARG = 3*XGAP
      XLEN  = (XINCR - XGAP - 2*XMARG) / 2
      YA(2) = YBASE + MINLW * WCPDC / 2
      YA(3) = YA(2)
      DO 500 IX = 1,NUMALT
C  size of linewidth to be simulated - allow for thickness
C  of simulating edge by subtracting minimum edgewidth.
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
      CALL PSEDR (WKID, 5, PON, 1, REQEW/NOMEW, 1)
      CALL PSEDI (5)
C   set up text for individual attributes
      DO 110 IX = PTXFN, PTXCI
          CALL PSIASF (IX, PINDIV)
110   CONTINUE
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)
      CALL PSIASF ( PIS, PINDIV)
      CALL PSIASF ( PICI, PINDIV)
      CALL PSIS (PISEMP)
      CALL PSICI (1)
      XLOC = 0.0
      ZA(1) = 0.5
      ZA(2) = 0.9
      ZA(3) = ZA(2)
      ZA(4) = ZA(1)
      YA(1) = YBASE + EXPEW * WCPDC/2
      YA(2) = YA(1)
      YA(3) = YA(1)
      YA(4) = YA(1)
      NPTS(1) = 4
      DO 600 IX = 1,NUMALT
C  offset 2nd and 4th point slightly so that Z-oriented edges (1-2 and
C  3-4) project to a short horizontal line, rather than to a point.
         XA(1) = XLOC + XMARG + XGAP + XLEN
         XA(2) = XA(1) + XLEN/100
         XA(3) = XA(1) + XLEN
         XA(4) = XA(3) - XLEN/100
         CALL PFAS3 (1, NPTS, XA,YA,ZA)
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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.05.03/lbedty                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LBEDTY (WKID, NUMDIS, PERM, LEDTYP)

C  LBEDTY is used to display a list of edgetypes, under bundled control.
C
C  Input parameters:
C    WKID   : Workstation identifier for edge bundles
C    NUMDIS : Number of edgetypes to be selected and displayed
C    PERM   : List of positions of selected edgetypes within LEDTYP
C    LEDTYP : List of edgetypes from which selection is made

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER   WKID, IX, NUMDIS, PERM(NUMDIS), LEDTYP(*), NPTS(1)
      INTEGER   THISET

      REAL      YLOC, YINCR, YBOT,YTOP, XA(3),YA(3)

      CHARACTER LNTID*20

C  display in order and label bundles 1 thru numdis
      XA(1) = 0.5
      XA(2) = 0.5
      XA(3) = 0.9
      YINCR = 0.8/NUMDIS
      YLOC =  0.9
      NPTS(1) = 3

      DO 300 IX = 1,NUMDIS
         YBOT = YLOC - 0.3*YINCR
         YTOP = YLOC + 0.3*YINCR
         YA(1) = YBOT
         YA(2) = YTOP
         YA(3) = YBOT
         THISET = LEDTYP(PERM(IX))
         WRITE (LNTID, '(A, I4, A)') 'Type#', THISET, ':'
         CALL VISLAB (LNTID(1:10), 'R', 0.05, 0.45, YBOT,YTOP)
         CALL PSEDI (IX)
         CALL PFAS (1, NPTS, XA, YA)
         CALL PSEDR (WKID, IX, PON, THISET, 1.0, 1)
         YLOC = YLOC - YINCR
300   CONTINUE

      END

