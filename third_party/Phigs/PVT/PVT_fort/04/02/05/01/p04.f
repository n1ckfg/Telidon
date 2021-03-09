C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.01/04                        *
C  *    TEST TITLE : Appearance of individual geometric    *
C  *                 attributes                            *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER    PICSTR, TXCI, IX, IY, COLIA(2,2), NGPAT
      INTEGER    RNDINT, NPTS(1), PERM(10), CEILNG, SIZ, JX,JY
      INTEGER    PSIZ1,PSIZ2, FCOL, COL1
      PARAMETER (PSIZ1 = 3, PSIZ2 = 2)
      INTEGER    BCOLIA(PSIZ1,PSIZ2), WCOLIA(PSIZ1,PSIZ2)
      INTEGER    ST1INC,ST2INC, EN1INC,EN2INC, MOD1

      REAL       PATSZ1, PATSZ2, YLOC,YINCR, XLA(5),RNDRL, XORG
      REAL       RND01, EXP1,EXP2, XA(5),YA(5),ZA(5), X1,XVAL, Y1,YVAL
      REAL       YTOP, YBOT, PATX(10), PATY(10), PI, CELSZX, CELSZY
      REAL       VEC(6), ANG, TANANG,COSANG, ZOFF, REFPTX,REFPTY,REFPTZ
      REAL       RFVCX(2), RFVCY(2), RFVCZ(2), A,B,C,D, XF(4,4), ID(4,4)
      REAL       PRVC1X, PRVC1Y, PRVC1Z, PRVC2X, PRVC2Y, PRVC2Z, VECANG
      REAL       NPCANG, VECL, VL, RX,RY,RZ, DIST, CX,CY, RCX,RCY
      REAL       FAC1,FAC2, STX,STY, ENX,ENY, RCXX,RCYY
      REAL       CEL1X,CEL1Y, CEL2X,CEL2Y, RVCVL(6,5)

      PARAMETER (PI = 3.14159265, ZOFF = 0.2)

      LOGICAL    DYN, PATAVL

      CALL INITGL ('04.02.05.01/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      IF (.NOT. PATAVL(SPECWT)) THEN
C  pattern is unavailable
         CALL INMSG ('Skipping tests of geometric attributes, since ' //
     1               'these apply only to pattern interior style, '   //
     2               'which is unavailable.')
         GOTO 666
      ENDIF

C  pattern is available
30    CONTINUE

      IF (DYN('Does this workstation support transformable ' //
     1        'patterns?')) THEN
C        keep going
      ELSE
         CALL INMSG ('Skipping tests of geometric attributes, since ' //
     1               'their effect is predictable only for '          //
     2               'transformable patterns, which are unavailable.')
         GOTO 666
      ENDIF

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C                                                      ---------
C                                                      | 0 | 1 |
C  set up simple checkerboard pattern representation   |---+---|
C    as entry #1, for use throughout:                  | 1 | 0 |
C                                                      ---------
      CALL SETVAL ('0,1,1,0', COLIA)
      CALL PSPAR (WKID, 1, 2,2, 1,1, 2,2, COLIA)
      CALL PSIS  (PPATTR)
      CALL PSISI (1)

C  mark start of variable part of structure
      CALL PLB (1)
C
C  *** *** *** ***   pattern size   *** *** *** ***
C
      CALL SETMSG ('3 4 61 62 71 72 73 74 75 76 77 78 79', 'The '    //
     1             'lengths of the sides of the pattern box should ' //
     2             'equal the magnitudes of the pattern size '       //
     3             'attribute of a fill area or fill area set '      //
     4             'primitive.')

C  ngpat = random integer from 1 to 5
      NGPAT = RNDINT(1,5)

      YINCR = 1.0/6
      YLOC  = 1 - YINCR
      NPTS(1) = 4
      CALL SETRVS ('0.3,0.3,0.8,0.8', XA, IX)
      CALL NUMLAB (5, 0.13, YLOC, YINCR)
      CALL PSLN (PLDOT)
      DO 100 IX = 1,5
C  pick a pattern size
         PATSZ1 = RNDRL(0.06, 0.12)
         PATSZ2 = RNDRL(0.04, 0.08)
C  only the magnitude should matter
         IF (RND01() .LT. 0.5) PATSZ1 = -PATSZ1
         IF (RND01() .LT. 0.5) PATSZ2 = -PATSZ2

C  exp1,exp2 = expected cell size = patsz1,patsz2 / 2
         EXP1 = ABS(PATSZ1/2)
         EXP2 = ABS(PATSZ2/2)
         IF (IX .EQ. NGPAT) THEN
            IF (EXP1 .LT. 0.1) THEN
               EXP1 = 1.2 * EXP1
            ELSE
               EXP1 = 0.8 * EXP1
            ENDIF
         ENDIF

         YTOP = YLOC + 0.3*YINCR
         YBOT = YLOC - 0.3*YINCR

C  draw expected boundaries of pattern cells,
C  using dotted polylines
         YA(1) = YLOC + 0.45*YINCR
         YA(2) = YLOC - 0.45*YINCR
C  assume reference point = 0,0
         X1 = CEILNG(0.3/EXP1) * EXP1
         DO 110 XVAL = X1,.8, EXP1
            XLA(1) = XVAL
            XLA(2) = XVAL
            CALL PPL (2, XLA,YA)
110      CONTINUE

         XLA(1) = 0.2
         XLA(2) = 0.9
C  assume reference point = 0,0
         Y1 = CEILNG(YBOT/EXP2) * EXP2
         DO 120 YVAL = Y1, YTOP, EXP2
            YA(1) = YVAL
            YA(2) = YVAL
            CALL PPL (2, XLA,YA)
120      CONTINUE

C  draw fill area or fill area set with actual pattern size
         CALL PSPA (PATSZ1, PATSZ2)
         YA(1) = YTOP
         YA(2) = YBOT
         YA(3) = YA(2)
         YA(4) = YA(1)
         IF (RND01() .LT. 0.5) THEN
            CALL PFA (4, XA,YA)
         ELSE
            CALL PFAS (1, NPTS, XA,YA)
         ENDIF

         YLOC = YLOC - YINCR
100   CONTINUE

C  mark end of variable part fo structure
      CALL PLB (2)

      CALL DCHPFV ('ACCURACY OF PATTERN SIZE: For which rectangle ' //
     1             'are the dotted lines NOT aligned with cell '    //
     2             'boundaries?', 5, NGPAT)

C  clear out structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 61 63 71 72 73 74 75 76 77 78 79',
     1             'A degenerate value in a pattern size element '  //
     2             '(either component zero) should not affect the ' //
     3             'traversal state list, nor the value bound to '  //
     4             'fill area primitives.')

C  set perm to randomize positions of primitives
      CALL RNPERM (5, PERM)

C  set up zeros in initial pattern size arrays
      CALL SETRVS ('.0,.0,.0,.0,.0', PATX, IX)
      CALL SETRVS ('.0,.0,.0,.0,.0', PATY, IX)

C  set reasonable default pattern size
      PATSZ1 = RNDRL(0.08, 0.12)
      PATSZ2 = RNDRL(0.06, 0.08)
C  set values for pattern size - only 1st and 5th should take effect
      PATX(1) = PATSZ1
      PATY(1) = PATSZ2
      PATY(2) = -2 * PATSZ2
      PATX(3) =  3 * PATSZ1
      PATX(5) = 1.2 * PATSZ1
      PATY(5) = 0.8 * PATSZ2

      YINCR = 1.0/6
      YLOC  = 1 - YINCR
      NPTS(1) = 4
      CALL SETRVS ('0.3,0.3,0.8,0.8', XA, IX)
      CALL NUMLAB (5, 0.13, YLOC, YINCR)

      DO 200 IX = 1,5
         YLOC = 1.0 - PERM(IX) / 6.0
         YTOP = YLOC + 0.3*YINCR
         YBOT = YLOC - 0.3*YINCR

C  draw fill area or fill area set with actual pattern size
         CALL PSPA (PATX(IX), PATY(IX))
         YA(1) = YTOP
         YA(2) = YBOT
         YA(3) = YA(2)
         YA(4) = YA(1)
         IF (RND01() .LT. 0.5) THEN
            CALL PFA (4, XA,YA)
         ELSE
            CALL PFAS (1, NPTS, XA,YA)
         ENDIF
200   CONTINUE

      CALL DCHPFV ('DEGENERATE PATTERN SIZE: Which rectangle has a ' //
     1             'different pattern size?', 5, PERM(5))

C  clear out structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 67 69 71 72 73 74 75 76 77 78 79', '<Set '    //
     1             'pattern reference point> should set the x-y '     //
     2             'values of the reference point as specified, the ' //
     3             'z-value to zero, and the pattern reference '      //
     4             'vectors to (1,0,0) and (0,1,0).')

C  ngpat = random integer from 1 to 5
      NGPAT = RNDINT(1,5)

C  set pattern size
      PATSZ1 = 0.15
      PATSZ2 = 0.08
      CALL PSPA (PATSZ1, PATSZ2)

      YINCR = 1.0/6
      YLOC  = 1 - YINCR
      NPTS(1) = 4
      CALL SETRVS ('0.3,0.3,0.8,0.8', XA, IX)
      CALL NUMLAB (5, 0.13, YLOC, YINCR)
      CALL PSLN (PLDOT)

      DO 300 IX = 1,5

C  set up reference point values:
         REFPTX = RNDRL(-2.0, 2.0)
         REFPTY = RNDRL(-2.0, 2.0)
C  rvec1, rvec2 always = (1,0,0), (0,1,0)

C  ang = angle of rotation around axis (x=0, z=zoff) for fill area plane
C      = random from within [15deg, 40deg]
         ANG = PI * RNDRL(15.0, 40.0) / 180
         TANANG = TAN(ANG)
         COSANG = COS(ANG)

C  Note relation among ZOFF, ANG and right edge of fillarea (= 0.8).
C  In order to keep right edge within unit cube of NPC, must ensure
C  that ZOFF .le. 1 - 0.8*TANANG.  This is satisfied for ZOFF=0.2
C  and ANG .le. 40 degrees.

C  celsz = size of cell
         CELSZX = PATSZ1/2
         CELSZY = PATSZ2/2

C  <set pattern reference point and vectors> to
C     refptx, refpty + celszy/2, celszx / (2 * sin(ang));
C         (if left in effect, this positions box boundary in
C          x-dimension exactly halfway from correct boundary; this
C          will be conspicuously wrong if not overridden by <set
C          pattern reference point>.)
C     vec1, vec2 = = random from within [-2,2]
         DO 310 IY = 1,6
            VEC(IY) = RNDRL(-2.0, 2.0)
310      CONTINUE
         CALL PSPRPV (REFPTX,REFPTY + CELSZY/2, CELSZX / (2*SIN(ANG)),
     1                VEC(1),VEC(3),VEC(5))

C  exp1,exp2 = expected cell size as projected on to NPC plane
         EXP1 = ABS(CELSZX * COSANG)
         EXP2 = ABS(CELSZY)

C  set up incorrect EXP1 for NGPAT
         IF (IX .EQ. NGPAT) THEN
            IF (EXP1 .LT. 0.1) THEN
               EXP1 = 1.2 * EXP1
            ELSE
               EXP1 = 0.8 * EXP1
            ENDIF
         ENDIF

C  draw expected boundaries of pattern cells, based on exp1
C    and exp2, using dotted polylines
         YA(1) = YLOC + 0.45*YINCR
         YA(2) = YLOC - 0.45*YINCR

C  assume reference point = refptx,refpty,0 fill area plane =
C  rotated by ANG around axis.  Axis: (x=0, z=ZOFF)

C  x-location in NPC of reference point after projection onto
C  fill area plane.
         XORG = COSANG**2 * (REFPTX - ZOFF*TANANG)

C  x-location of first cell boundary in range of fill area
         X1 = XORG + CEILNG((0.3-XORG) / EXP1) * EXP1
         DO 3110 XVAL = X1,.8, EXP1
            XLA(1) = XVAL
            XLA(2) = XVAL
            CALL PPL (2, XLA,YA)
3110     CONTINUE

         XLA(1) = 0.2
         XLA(2) = 0.9
         YTOP = YLOC + 0.3*YINCR
         YBOT = YLOC - 0.3*YINCR

C  assume reference point = refptx,refpty,0
C  y-location of first cell boundary in range of fill area
         Y1 = REFPTY + CEILNG((YBOT-REFPTY) / EXP2) * EXP2
         DO 3120 YVAL = Y1, YTOP, EXP2
            YA(1) = YVAL
            YA(2) = YVAL
            CALL PPL (2, XLA,YA)
3120     CONTINUE

C  set up z-values based on ang: this rotates fill area plane
C  around axis.  Axis: (x=0, z=ZOFF)
         ZA(1) = XA(1) * TANANG + ZOFF
         ZA(2) = ZA(1)
         ZA(3) = XA(3) * TANANG + ZOFF
         ZA(4) = ZA(3)

C  <set pattern reference point> to refptx, refpty
         CALL PSPARF (REFPTX, REFPTY)
C  draw fill area or fill area set #ix
         YA(1) = YTOP
         YA(2) = YBOT
         YA(3) = YA(2)
         YA(4) = YA(1)
         IF (RND01() .LT. 0.5) THEN
            CALL PFA3 (4, XA,YA,ZA)
         ELSE
            CALL PFAS3 (1, NPTS, XA,YA,ZA)
         ENDIF

         YLOC = YLOC - YINCR
300   CONTINUE

      CALL DCHPFV ('EFFECT OF SET PATTERN REFERENCE POINT: For ' //
     1             'which rectangle are the dotted lines NOT '   //
     2             'aligned with cell boundaries?', 5, NGPAT)

C  clear out structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  *** *** ***   pattern reference point and vectors   *** *** ***

      CALL SETMSG ('3 4 66 68 71 72 73 74 75 76 77 78 79', 'The '    //
     1             'geometric attributes pattern size, pattern '     //
     2             'reference point, and pattern reference vectors ' //
     3             'should determine the location of colored '       //
     4             'pattern cells within fill area and fill area '   //
     5             'set primitives.')

C  ngpat = no-good pattern: random integer from 1 to 5
      NGPAT = RNDINT(1,5)

      YINCR = 1.0/6
C  yloc = midpoint for next rectangle
      YLOC  = 1 - YINCR
      NPTS(1) = 4

C  xleft,xright = left,right MC edges of rectangle = -.1, +.1
      CALL SETRVS ('-0.1,-0.1, 0.1,0.1', XA, IX)
      CALL NUMLAB (5, 0.13, YLOC, YINCR)

C  set up PSIZ1 x PSIZ2 pattern representation as index #1, using as many
C  distinct colors as available (try for all distinct).
      CALL DISCOL (PSIZ1*PSIZ2, WKID, FCOL)
      COL1 = 1
      DO 410 IX = 1,PSIZ1
      DO 420 IY = 1,PSIZ2
         BCOLIA(IX,IY) = COL1
         COL1 = MOD(COL1+1, FCOL+1)
420   CONTINUE
410   CONTINUE
      CALL PSPAR (WKID, 1, PSIZ1,PSIZ2, 1,1, PSIZ1,PSIZ2, BCOLIA)
      CALL IDMAT (4, ID)

C  loop to create 5 patterned fill areas, with simulated cells
      DO 450 IX = 1,5

C  pick_coeff:
451      CONTINUE
C     a,b,c = first three coefficients for equation of fill area plane
C           = random from within [-5,5]
C     fill area plane: a*x + b*y + c*z + d = 0
         A = RNDRL(-5.0, 5.0)
         B = RNDRL(-5.0, 5.0)
         C = RNDRL(-5.0, 5.0)
C  make sure not too oblique
         IF (ABS(C).LT.1E-4 .OR. ABS(C).LT.ABS(A) .OR.
     1                           ABS(C).LT.ABS(B)) GOTO 451

C  calculate d such that rectangle MC center (0,yloc,.5) is
C  contained in plane
         D = -(B*YLOC + C*0.5)

C  MC rectangle coordinates are: x: -1. : +.1
C                                y: yloc + or - 0.4*yincr
         YBOT = YLOC - 0.4*YINCR
         YTOP = YLOC + 0.4*YINCR
         YA(1) = YTOP
         YA(2) = YBOT
         YA(3) = YBOT
         YA(4) = YTOP

C  set up z-values based on a,b,c,d plane coefficients
         DO 455 IY = 1,4
            ZA(IY) = -(A*XA(IY) + B*YA(IY) + D) / C
C  if (z-values of corners of rectangle not within [0,1]) then
C     plane too oblique, pick new coefficients
            IF (ZA(IY) .LE. 0.0 .OR. ZA(IY) .GE. 1.0) GOTO 451
455      CONTINUE

C  refptx,refpty,refptz = random reference point
         REFPTX = RNDRL(-2.0, 2.0)
         REFPTY = RNDRL(-2.0, 2.0)
         REFPTZ = RNDRL(-2.0, 2.0)

C  pick_vecs: 2 random reference vectors
460      CONTINUE
         RFVCX(1) = RNDRL(-2.0, 2.0)
         RFVCY(1) = RNDRL(-2.0, 2.0)
         RFVCZ(1) = RNDRL(-2.0, 2.0)
         RFVCX(2) = RNDRL(-2.0, 2.0)
         RFVCY(2) = RNDRL(-2.0, 2.0)
         RFVCZ(2) = RNDRL(-2.0, 2.0)

C  calculate shape of WC cell, based on vectors rfvc1, rfvc2 projected
C  on to fill area plane, and then onto NPC.

C  project reference vectors on to fill area plane
         CALL PERVEC (A,B,C, RFVCX(1),RFVCY(1),RFVCZ(1),
     1                PRVC1X,PRVC1Y,PRVC1Z)
         CALL PERVEC (A,B,C, RFVCX(2),RFVCY(2),RFVCZ(2),
     1                PRVC2X,PRVC2Y,PRVC2Z)

C  if shape not rectangular enough (angle projected into NPC < 55deg,
C     ignoring z-coordinate)
C  then goto pick_vecs
         NPCANG = VECANG(PRVC1X,PRVC1Y,0.0, PRVC2X,PRVC2Y,0.0) * 180/PI
         IF (NPCANG.LT.55 .OR. NPCANG.GT.125) GOTO 460

C  calculate patsz1,patsz2 so as to make cell size visible
         PATSZ1 = 0.05 * VECL(PRVC1X,PRVC1Y,PRVC1Z) /
     1                   VECL(PRVC1X,PRVC1Y,0.)
         PATSZ2 = 0.05 * VECL(PRVC2X,PRVC2Y,PRVC2Z) /
     1                   VECL(PRVC2X,PRVC2Y,0.)

C  <set pattern size> to patsz1,patsz2
         CALL PSPA (PATSZ1, PATSZ2)
C  <set pattern reference point and vectors>
         CALL PSPRPV (REFPTX,REFPTY,REFPTZ, RFVCX,RFVCY,RFVCZ)
C  <set local modelling transform> such that in x, -.1,+.1 maps
C        to .4,.8) at z=1, and in y, yloc maps to yloc at z=0.5:
C
C          2   0  0   0.6                x' = (2x + .6/w
C          0   1  0   yloc/4   yields    y' =  (y + yloc/4)/w
C          0   0  1   0                  z' =  z/w
C          0   0 -0.5 1.5                w  = (3-z)/2

         CALL SETRVS ('2,0,0,0, 0,1,0,0, 0,0,1,-0.5, 0.6,0,0,1.5',
     1                XF, SIZ)
         XF(2,4) = YLOC/4
         CALL PSLMT3 (XF, PCREPL)

C  draw fill area or fill area set #ix
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFAS3 (1, NPTS, XA,YA,ZA)
         ELSE
            CALL PFA3 (4, XA,YA,ZA)
         ENDIF
C  <set local modelling transform> back to identity
         CALL PSLMT3 (ID, PCREPL)

C  Now for simulation: calculate WC location and color of expected
C  cells, based on refpt, rfvc, patsz, and transformation.
C
C  First, in MC, get projected reference vectors adjusted to
C  pattern size = pattern width and height vectors
         VL = VECL (PRVC1X,PRVC1Y,PRVC1Z)
         PRVC1X = PRVC1X * PATSZ1 / VL
         PRVC1Y = PRVC1Y * PATSZ1 / VL
         PRVC1Z = PRVC1Z * PATSZ1 / VL

         VL = VECL (PRVC2X,PRVC2Y,PRVC2Z)
         PRVC2X = PRVC2X * PATSZ2 / VL
         PRVC2Y = PRVC2Y * PATSZ2 / VL
         PRVC2Z = PRVC2Z * PATSZ2 / VL

C  project reference point on to fill area plane
         CALL PTPLDS (REFPTX,REFPTY,REFPTZ, A,B,C,D, RX,RY,RZ, DIST)

C  center of rectangle in MC
         CX = (XA(1) + XA(3)) / 2
         CY = (YA(1) + YA(3)) / 2
C  fac1,fac2 are the number of times vec1 and vec2 have to be added to
C  rx,ry to get to center of rectangle.
         CALL LINTPT (PRVC1X,PRVC2X,RX-CX,
     1                PRVC1Y,PRVC2Y,RY-CY, FAC1,FAC2)
C  find a "reference point" near middle of rectangle by adding integral
C  number of vec1 and vec2.
         RCX = RX + NINT(FAC1)*PRVC1X + NINT(FAC2)*PRVC2X
         RCY = RY + NINT(FAC1)*PRVC1Y + NINT(FAC2)*PRVC2Y

C  Idea here is to construct smallest parallelogram which contains
C  rectangle (fill area) and whose corners are valid reference
C  points, i.e. formed by adding integer multiples of reference
C  vectors to actual reference point.

C  get starting and ending corners
         CALL PARPT (RCX,RCY, -1, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1               XA,YA, STX,STY, ST1INC,ST2INC)
         CALL PARPT (RCX,RCY, +1, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1               XA,YA, ENX,ENY, EN1INC,EN2INC)

C  working copy of color array
         DO 4101 JX = 1,PSIZ1
         DO 4201 JY = 1,PSIZ2
            WCOLIA(JX,JY) = BCOLIA(JX,JY)
4201     CONTINUE
4101     CONTINUE

C  if (ix = ngpat) then set up switching of colors for expected cells
         IF (IX .EQ. NGPAT) THEN
            WCOLIA(1,1) = BCOLIA(1,2)
            WCOLIA(1,2) = BCOLIA(1,1)
         ENDIF

C  cell increments (within pattern box)
         CEL1X = PRVC1X/PSIZ1
         CEL1Y = PRVC1Y/PSIZ1
         CEL2X = PRVC2X/PSIZ2
         CEL2Y = PRVC2Y/PSIZ2

C  Loop through potential pattern cells in MC from STX,STY to ENX,ENY
         RCX = STX
         RCY = STY
         DO 4510 JX = 1, PSIZ1 * (ST1INC+EN1INC+1)
C  start new "row" (along first vector) of parallelogram
            RCXX = RCX
            RCYY = RCY

C  Loop thru cells; RCXX,RCYY is "lower left" corner of current
C  cell, in MC.
         DO 4520 JY = 1, PSIZ2 * (ST2INC+EN2INC+1)
            CALL PSPLCI (WCOLIA (        MOD1(JX,PSIZ1),
     1                           PSIZ2+1-MOD1(JY,PSIZ2)))
C  draw the two diagonals within cell
            CALL CLDIAG (RCXX,RCYY, RCXX+CEL1X+CEL2X, RCYY+CEL1Y+CEL2Y,
     1                      A,B,C,D, XA,YA, XF)
            CALL CLDIAG (RCXX+CEL1X, RCYY+CEL1Y, RCXX+CEL2X, RCYY+CEL2Y,
     1                      A,B,C,D, XA,YA, XF)

C  next pattern cell within this row: increment column within row
            RCXX = RCXX + CEL2X
            RCYY = RCYY + CEL2Y
4520     CONTINUE
C  increment rcx,rcy to new row
            RCX = RCX + CEL1X
            RCY = RCY + CEL1Y
4510     CONTINUE

         YLOC = YLOC - YINCR
C  next ix
450   CONTINUE

      CALL DCHPFV ('EFFECT OF SET PATTERN REFERENCE POINT, VECTORS, ' //
     1             'AND SIZE: For which rectangle are colored '       //
     2             'pattern cell diagonals visible?', 5, NGPAT)

C  clear out structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 66 68 70 71 72 73 74 75 76 77 78 79',
     1             'Degenerate values in the pattern reference '     //
     2             'vector (zero length or parallel) should not '    //
     3             'affect the traversal state list, nor the value ' //
     4             'bound to fill area primitives.')

C  set reasonable pattern size
      PATSZ1 = 0.05
      PATSZ2 = 0.05
C  <set pattern size> to patsz1,patsz2
      CALL PSPA (PATSZ1, PATSZ2)

C  use 3x2 pattern from previous test; interior style index #1

C  set perm to randomize positions of primitives
      CALL RNPERM (5, PERM)

C  set up values for 5 pairs of reference vectors: original pair,
C    rfvc1,rfvc2 = (2.0, 2.0, 1.0), (-1.0, 3.0, -1.0)

C  vectors    values            comments
C  -------    ------            --------
C    #1       rfvc1,rfvc2       valid entry
C    #2           0,rfvc1       zero length vector: no effect
C    #3       rfvc2,0           zero length vector: no effect
C    #4       5*rfvc1,rfvc1     parallel vectors: no effect
C    #5       rfvc2,rfvc1       valid entry, distinct from #1

      CALL SETRVS (' 2.0,  2.0,  1.0, -1.0, 3.0, -1.0, ' //
     1             ' 0.0,  0.0,  0.0,  2.0, 2.0,  1.0, ' //
     2             '-1.0,  3.0, -1.0,  0.0, 0.0,  0.0, ' //
     3             '10.0, 10.0,  5.0,  2.0, 2.0,  1.0, ' //
     4             '-1.0,  3.0, -1.0,  2.0, 2.0,  1.0', RVCVL, SIZ)

C  Re-locate fill areas by applying modelling transformation; thus
C  pattern reference point (in MC) will be constant.  Use previous
C  reference point.

      YINCR = 1.0/6
      NPTS(1) = 4
C  untransformed location of fill area:
      CALL SETRVS (' 0.3,   0.3,   0.8,   0.8' , XA, IX)
      CALL SETRVS ('-0.05, +0.05, +0.05, -0.05', YA, IX)
      CALL NUMLAB (5, 0.13, 1.0-YINCR, YINCR)

      DO 510 IX = 1,5
C  set up reference vectors
         RFVCX(1) = RVCVL(1,IX)
         RFVCY(1) = RVCVL(2,IX)
         RFVCZ(1) = RVCVL(3,IX)
         RFVCX(2) = RVCVL(4,IX)
         RFVCY(2) = RVCVL(5,IX)
         RFVCZ(2) = RVCVL(6,IX)

         CALL PSPRPV (REFPTX,REFPTY,REFPTZ, RFVCX,RFVCY,RFVCZ)
         YLOC = 1.0 - YINCR * PERM(IX)
C  shift up by YLOC
         CALL PTR3 (0.0, YLOC, 0.0, ERRIND, XF)
         CALL CHKINQ ('ptr3', ERRIND)
         CALL PSLMT3 (XF, PCREPL)

C  draw fill area or fill area set #ix
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA,YA)
         ELSE
            CALL PFA (4, XA,YA)
         ENDIF
510   CONTINUE

      CALL DCHPFV ('DEGENERATE PATTERN VECTORS: Which rectangle''s ' //
     1             'pattern cells have a different orientation?',
     2             5, PERM(5))

C  endit:
666   CONTINUE
C  wrap it up.
      CALL ENDIT

      END
