C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/10                        *
C  *    TEST TITLE : Foreground colour                     *
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
      INTEGER    PCPRE,      PCPOST,    PCREPL
      PARAMETER (PCPRE = 0,  PCPOST = 1,PCREPL = 2)
C  colour model
      INTEGER    PRGB,       PCIE,      PHSV,     PHLS
      PARAMETER (PRGB = 1,   PCIE = 2,  PHSV = 3, PHLS = 4)

      INTEGER    PICSTR, TXCI, IX, BGI, NUMRET, COLSIZ, MAXCI, SQSIDE
      INTEGER    NGSQ, WINDOW, NXTCOL, PERM(6), RNDINT
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

      REAL       GBM(3,3), FG(3), BG(3),BCKCOL(3),NOMMS
      REAL       SIDE1, SIDE2, SQINC, MRKSIZ, XSIZ, YSIZ
      REAL       XLOC, YLOC, Z, U, H, XWINLO(6), YWINLO(6), XF(3,3)
      REAL       XA(100), YA(100), RDUM2, RDUM3

      PARAMETER  (Z = 0.0, U = 1.0, H = 0.5)

      DATA GBM / 0.,1.,0.,0.,0.,1.,1.,0.,1. /

      CALL INITGL ('04.03.02.02/10')

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
C  set colour model = RGB
      CALL PSCMD (WKID, PRGB)

      CALL PEXST (106)
      CALL PEXST (102)
      CALL PCLST

C  divide screen up into six labelled square areas
      CALL WIN6 (106, 1, XSIZ, YSIZ, XWINLO, YWINLO)

      CALL POPST (102)

C  bg = requested background colour = randomly: green, blue or magenta
      BGI = RNDINT (1, 3)
      BG(1) = GBM(1,BGI)
      BG(2) = GBM(2,BGI)
      BG(3) = GBM(3,BGI)
C  set color representation #0 to bg
      CALL PSCR (WKID, 0, 3, BG)

C  inquire color representation #0 as realized to determine
C    bckcol = actual background color
      CALL PQCR (WKID, 0, 3, PREALI, ERRIND, NUMRET, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  inquire workstation state table lengths to determine
C    colsiz = number of settable entries in color table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             IDUM5, IDUM6, COLSIZ, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)
C  maxci = maximum color index = colsiz-1
      MAXCI = COLSIZ - 1

C  fg = foreground color farthest from bckcol in color cube
      DO 50 IX = 1, 3
         IF (BCKCOL(IX) .LT. 0.5) THEN
            FG(IX) = 1.0
         ELSE
            FG(IX) = 0.0
         ENDIF
50    CONTINUE

C  set color representations from #1 to #maxci to fg
      DO 100 IX = 1, MAXCI
         CALL PSCR (WKID, IX, 3, FG)
100   CONTINUE

      CALL SETMSG ('30 31 32', 'All the positive entries within the ' //
     1             'reported size of the color table should control ' //
     2             'a foreground colour.')

C  sqside = integer number of polymarkers per side of square array
C         = sqrt(colsiz/4 + 1) + 1
C  (this ensures all color slots will be used)
C  side1 = 0.1
C  side2 = 0.9
C  sqinc = increment for square = (side2-side1) / (sqside-1)
C  mrksiz = polymarker size = min(0.05, 0.2 * sqinc)
      SQSIDE = SQRT(COLSIZ/4. + 1.) + 1
      SIDE1 = 0.1
      SIDE2 = 0.9
      SQINC = (SIDE2 - SIDE1) / (SQSIDE - 1)
      MRKSIZ = MIN(0.05, 0.2*SQINC)

      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3, NOMMS,
     1            RDUM2, RDUM3, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)

C  set polymarker style = plus (+)
C  set polymarker size = mrksiz (in WC)
      CALL PSMK (PPLUS)
      CALL PSMKSC (MRKSIZ/(NOMMS * WCPDC))

C  perm = randomize order from 1 to 6
      CALL RNPERM (6, PERM)
C  nxtcol = next color index to use = maxci
      NXTCOL = MAXCI

C  draw square grids of polymarkers
      DO 200 IX = 1, 6
         WINDOW = PERM(IX)
C     set tranformation to scale unit square into this window
         CALL EBLTM (Z, Z, XWINLO(IX), YWINLO(IX), Z, XSIZ, XSIZ, XF)
         CALL PSLMT (XF, PCREPL)

         IF (WINDOW .EQ. 1) THEN
C  simulate incorrect display
            NGSQ = IX
            CALL PSPMCI (1)

            CALL SQGRMK (SIDE1, SIDE2+0.5*SQINC, SQINC)
C  put a polymarker at a non-aligned position
            XA(1) = SIDE1 + SQINC * (RNDINT(0, SQSIDE-2) + 0.5)
            YA(1) = SIDE1 + SQINC * (RNDINT(0, SQSIDE-2) + 0.5)

            CALL PPM (1, XA, YA)
         ELSEIF (WINDOW .EQ. 2) THEN
C  simulate correct display
            CALL PSPMCI (1)
            CALL SQGRMK (SIDE1, SIDE2+0.5*SQINC, SQINC)
         ELSE
C  draw an actual grid
            DO 230 XLOC = SIDE1, SIDE2 + 0.5*SQINC, SQINC
            DO 235 YLOC = SIDE1, SIDE2 + 0.5*SQINC, SQINC
               IF (NXTCOL .LT. MAXCI) THEN
                  NXTCOL = NXTCOL + 1
               ELSE
                  NXTCOL = 1
               ENDIF
C  display single polymarker: xa,ya
               CALL PSPMCI (NXTCOL)
               XA(1) = XLOC
               YA(1) = YLOC
               CALL PPM (1, XA, YA)
235         CONTINUE
230         CONTINUE
         ENDIF
200   CONTINUE

      CALL DCHPFV ('FOREGROUND COLOUR: Which polymarker is ' //
     1             'different in either color or geometry?',
     2             6, NGSQ)
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
