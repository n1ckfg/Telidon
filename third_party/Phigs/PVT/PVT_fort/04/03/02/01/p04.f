C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.01/04                        *
C  *    TEST TITLE : Simultaneous use of all color table   *
C  *                 entries                               *
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

C  type of returned value
      INTEGER    PSET,       PREALI
      PARAMETER (PSET = 0,   PREALI = 1)
C  composition type
      INTEGER    PCPRE,      PCPOST,     PCREPL
      PARAMETER (PCPRE = 0,  PCPOST = 1, PCREPL = 2)
C  colour model
      INTEGER    PRGB,       PCIE,       PHSV,       PHLS
      PARAMETER (PRGB = 1,   PCIE = 2,   PHSV = 3,   PHLS = 4)

C  Declare program-specific variables
      INTEGER    PICSTR, TXCI, IX, NUMRET, SQSIDE, RNDINT
      INTEGER    COLSIZ, MAXCI, NXTCOL, WINDOW, NGSQ, PERM(6)
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7

      REAL       SIDE1, SIDE2, SQINC, MRKSIZ, XSIZ, YSIZ
      REAL       XLOC, YLOC, Z, U, H, NOMMS, RNDRL
      REAL       BCKCOL(3), FORCOL(3), XWINLO(6), YWINLO(6), XF(3,3)
      REAL       XA(10), YA(10)
      PARAMETER (Z = 0.0, U = 1.0, H = 0.5)
      REAL       RDUM2,RDUM3

      CHARACTER  SIDLBL*3

      CALL INITGL ('04.03.02.01/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

      CALL PEXST (106)
      CALL PEXST (102)
      CALL PCLST

C  divide screen up into six labelled square areas
      CALL WIN6 (106, 1, XSIZ, YSIZ, XWINLO, YWINLO)

      CALL POPST (102)

C  inquire color representation #0 as realized to determine
C    bckcol = background color
      CALL PQCR (WKID, 0, 3, PREALI, ERRIND, NUMRET, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
C  inquire color representation #1 as realized to determine
C    forcol = foreground color
      CALL PQCR (WKID, 1, 3, PREALI, ERRIND, NUMRET, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  inquire workstation state table lengths to determine
C    colsiz = number of settable entries in color table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             IDUM5, IDUM6, COLSIZ, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  maxci = maximum color index = colsiz-1
      MAXCI = COLSIZ - 1
C
      CALL SETMSG ('1 2 7', 'All the entries within the reported ' //
     1             'size of the color table should be usable and ' //
     2             'effective.')

C  set all even entries = background color
C           odd entries = foreground color:
      DO 100 IX = 2, MAXCI, 2
         CALL PSCR (WKID, IX, 3, BCKCOL)
100   CONTINUE

      DO 110 IX = 3, MAXCI, 2
         CALL PSCR (WKID, IX, 3, FORCOL)
110   CONTINUE

C  sqside = integer number of polymarkers per side of square array
C  (this ensures all color slots will be used)
C  side1 = 0.1, side2 = 0.9
C  sqinc = increment for square = (side2-side1) / (sqside-1)
C  mrksiz = polymarker size = min(0.05, 0.2 * sqinc)
      SQSIDE = SQRT (COLSIZ/4.0 + 1) + 1
      SIDE1 = 0.1
      SIDE2 = 0.9
      SQINC = (SIDE2 - SIDE1) / (SQSIDE-1)
      MRKSIZ = MIN (0.05, 0.1 * SQINC)
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3,
     1            NOMMS,RDUM2,RDUM3, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
C  set polymarker size = mrksiz (in WC)
      CALL PSMKSC (MRKSIZ / (NOMMS*WCPDC))
C  set polymarker style = plus (+)
      CALL PSMK (PPLUS)

C  perm = randomize order from 1 to 6
      CALL RNPERM (6, PERM)

C  nxtcol = next color index to use = 0
      NXTCOL = 0

      DO 200 IX = 1 , 6
         WINDOW = PERM(IX)
         CALL EBLTM (Z,Z, XWINLO(IX),YWINLO(IX), Z, XSIZ,XSIZ, XF)
         CALL PSLMT (XF, PCREPL)

         IF (WINDOW .EQ. 1) THEN
C  simulate incorrect display.
            NGSQ = IX
            CALL PSPMCI (1)
            CALL SQGRMK (SIDE1, SIDE2+0.5*SQINC, SQINC)
C  put a polymarker at a non-aligned position:
            XA(1) = SIDE1 + SQINC * (RNDINT(0, SQSIDE-2) + 0.5)
            YA(1) = SIDE1 + SQINC * (RNDINT(0, SQSIDE-2) + 0.5)
            CALL PPM (1, XA, YA)

         ELSEIF (WINDOW .EQ. 2) THEN
C  simulate correct display:
            CALL PSPMCI (1)
            CALL SQGRMK (SIDE1, SIDE2+0.5*SQINC, SQINC)
         ELSE
C  for other windows, draw actual grid
            DO 245 XLOC = SIDE1, SIDE2 + 0.5 * SQINC, SQINC
            DO 240 YLOC = SIDE1, SIDE2 + 0.5 * SQINC, SQINC
C  visible aligned marker:
               IF (NXTCOL .LT. MAXCI) THEN
                  NXTCOL = NXTCOL + 1
               ELSE
                  NXTCOL = 1
               ENDIF
C  set polymarker color = nxtcol
               CALL PSPMCI (NXTCOL)
               XA(1) = XLOC
               YA(1) = YLOC
               CALL PPM (1, XA, YA)

C  invisible mis-aligned marker:
               IF (NXTCOL .LT. MAXCI) THEN
                  NXTCOL = NXTCOL + 1
               ELSE
                  NXTCOL = 0
               ENDIF
C  set polymarker color = nxtcol
               CALL PSPMCI (NXTCOL)
C  put a polymarker at a non-aligned position: the RNDRL makes it
C  unlikely that a bad (visible) polymarker will be overwritten
C  by a good (invisible) one.
               XA(1) = SIDE1 + SQINC * (RNDINT(0, SQSIDE-2) +
     1                 RNDRL(0.3, 0.7))
               YA(1) = SIDE1 + SQINC * (RNDINT(0, SQSIDE-2) +
     1                 RNDRL(0.3, 0.7))
               CALL PPM (1, XA, YA)
240         CONTINUE
245         CONTINUE
         ENDIF
200   CONTINUE

      WRITE (SIDLBL, '(I3)') SQSIDE
      CALL DCHPFV ('USE OF ENTIRE COLOUR TABLE: Which area does NOT ' //
     1             'contain a ' // SIDLBL // ' by ' // SIDLBL //
     2             ' square grid of polymarkers of a single colour?',
     3             6, NGSQ)
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
