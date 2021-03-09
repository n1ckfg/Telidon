C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/17                           *
C  *    TEST TITLE : Modelling clipping for text and       *
C  *                 annotation text                       *
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
C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

C clipping indicator
C                noclip        cllip
      INTEGER    PNCLIP,       PCLIP
      PARAMETER (PNCLIP=0,     PCLIP=1)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

C modelling clipping operator
C                replace,      intersect
      INTEGER    PMCREP,       PMCINT
      PARAMETER (PMCREP=1,     PMCINT=2)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

      INTEGER    PICSTR, TXCI, IX,IY,IEX, THISWN, NGWIN, RNDINT
      INTEGER    TXFONT, TXPATH, NUMHP,EXPNUM, I2, MOD1, NUMVIS
      INTEGER    OPANS,TXLEN, RANWIN(8), VISLIS(8), VISDX, WNTYPE
      INTEGER    NUMLIN, NGLINE, THISLN

      REAL       XA(40),YA(40),ZA(40), H,U,Z, NPCPWC, WINSIZ
      REAL       XWINLO(6),YWINLO(6), CHXPH,CHXPV, CHHTH,CHHTV
      REAL       XF(4,4), MCV3(6,10), MCV2(4,10), NVECX,NVECY,NVECZ
      REAL       XSIZ,YSIZ, NTXWD,NTXHT, DELTA, XCENT
      REAL       HVECX,HVECY,HVECZ, VVECX,VVECY,VVECZ
      REAL       D1VECX,D1VECY,D1VECZ, D2VECX,D2VECY,D2VECZ
      REAL       RNDRL, EXPVX(20),EXPVY(20),EXPVZ(20)
      REAL       HTAB(PALEFT:PARITE),VTAB(PATOP:PABOTT)
      REAL       NOMHL,NOMHR,NOMHB,NOMHC, NOMVL,NOMVR,NOMVB,NOMVC
      REAL       TDX(2),TDY(2),TDZ(2), TDROT(4,4), SCXF(4,4), CORXF(4,4)
      REAL       CORX(4),CORY(4),CORZ(4), CENTX,CENTY,CENTZ
      REAL       XLEFT,XRITE,YBAS,YCAP, VYX, YINCR,YLOC,YTOP, ACHHT,CHXP

      PARAMETER (H=0.5, U=1.0, Z=0.0)

      REAL       RDUM1,RDUM2

      CHARACTER  ATXSTR*4, TXSTR*7, CHSTR*13

      CALL INITGL ('06.01.02/17')

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

      CALL PEXST (102)
      CALL PCLST

C  Set up 6 windows on the screen
      CALL WIN6 (106, 2, XSIZ, YSIZ, XWINLO, YWINLO)

      CALL POPST (102)
      CALL PEXST (106)

C  throughout, represent a line segment as a point P and vector V,
C    where endpoints = P and P+V

C  *** *** *** ***   text   *** *** *** ***
C
      CALL SETMSG ('40 41 42 43 53 57 58', 'Exactly those parts of ' //
     1             'a text primitive in STROKE precision that lie '  //
     2             'outside the current modelling clipping volume '  //
     3             'should be clipped.')

C  txstr = text string with ASCII characters that fill character box
      TXSTR = 'ZHMENKX'
      TXFONT = 1

C  *** *** ***  set up expected horizontal text extent:

      TXPATH = PRIGHT
      CALL TXEXAL (TXFONT, TXPATH, TXSTR, NTXWD, NTXHT, HTAB, VTAB)

C  using text alignment = center,half:
C  nomhl,nomhr = nominal x-location of left,right border of horizontal string
C  nomhb,nomhc = nominal y-location of baseline,capline of horizontal string
      NOMHL = HTAB(PALEFT) - HTAB(PACENT)
      NOMHR = HTAB(PARITE) - HTAB(PACENT)
      NOMHB = VTAB(PABASE) - VTAB(PAHALF)
      NOMHC = VTAB(PACAP)  - VTAB(PAHALF)

C  horizontal-path expansion factor
      CHXPH = 0.3
      NOMHL = NOMHL*CHXPH
      NOMHR = NOMHR*CHXPH

C  horizontal-path character height
      CHHTH = 1.9 / (NOMHR-NOMHL)

C  *** *** ***  set up expected vertical text extent:

      TXPATH = PDOWN
      CALL TXEXAL (TXFONT, TXPATH, TXSTR, NTXWD, NTXHT, HTAB, VTAB)

C  using text alignment = center,half:
C  nomvl,nomvr = nominal x-location of left,right border of vertical string
C  nomvb,nomvc = nominal y-location of baseline,capline of vertical string
      NOMVL = HTAB(PALEFT) - HTAB(PACENT)
      NOMVR = HTAB(PARITE) - HTAB(PACENT)
      NOMVB = VTAB(PABASE) - VTAB(PAHALF)
      NOMVC = VTAB(PACAP)  - VTAB(PAHALF)

C  vertical-path expansion factor
      CHXPV = 3.0
      NOMVL = NOMVL*CHXPV
      NOMVR = NOMVR*CHXPV

C  vertical-path character height
      CHHTV = 1.9 / (NOMVC-NOMVB)

C  set constant attributes
      CALL PSCHSP (0.0)
      CALL PSTXFN (TXFONT)
      CALL PSTXPR (PSTRKP)
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSTXCI (1)
      CALL PSPLCI (2)
      CALL PSLN (PLDOT)
      CALL PSLWSC (0.01)

C  incorrectly drawn window
      NGWIN = RNDINT(1,6)

      DO 100 THISWN = 1,6

C  xf = modelling transformation to map double-unit MC cube (-1 to 1)
C       into window #thiswn in xy-dimensions, and into (0 to 1)
C       in z-dimension
         CALL EBLTM3 (-U,-U,-U, U+XWINLO(THISWN),U+YWINLO(THISWN),U,
     1                Z,Z,Z, XSIZ/2,XSIZ/2,H, XF)
         CALL PSLMT3 (XF, PCREPL)
         CALL PSMCLI (PCLIP)

C  compute expected text position:
C  get_vecs: random 3D vector chosen from -1 to 1 in each dimension
105      CONTINUE
         DO 110 IX = 1,2
            TDX(IX) = RNDRL(-1.0, 1.0)
            TDY(IX) = RNDRL(-1.0, 1.0)
            TDZ(IX) = RNDRL(-1.0, 1.0)
110      CONTINUE

C  nvec = normal vector to text plane = cross-product of vec1 x vec2
         CALL CROSSP (TDX(1),TDY(1),TDZ(1), TDX(2),TDY(2),TDZ(2),
     1                NVECX,NVECY,NVECZ)

C  ensure text-plane not edge-on to operator:
         IF (ABS(NVECZ) .LT. 0.6*ABS(NVECX) .OR.
     1       ABS(NVECZ) .LT. 0.6*ABS(NVECY))   GOTO 105

C  tdrot = 3D rotation transformation resulting from application
C          of text direction vectors
         CALL IDMAT (4, TDROT)

C  compute unit vectors expressing TLC directions within MC -
C  build these into columns of transformation matrix.

C  TLC X-direction = 1st vector, scaled to unit size
         CALL VEC1 (TDX(1),TDY(1),TDZ(1),
     1              TDROT(1,1),TDROT(2,1),TDROT(3,1))
C  TLC Z-direction = 1st x 2nd vector, scaled to unit size
         CALL VEC1 (NVECX,NVECY,NVECZ, TDROT(1,3),TDROT(2,3),TDROT(3,3))
C  TLC Y-direction = Z-direction x X-direction
         CALL CROSSP (TDROT(1,3),TDROT(2,3),TDROT(3,3),
     1                TDROT(1,1),TDROT(2,1),TDROT(3,1),
     2                TDROT(1,2),TDROT(2,2),TDROT(3,2))

C  compute text rectangle corners:
         IF (THISWN .LT. 4) THEN
C  set up for horizontal path:
            CALL PSCHH (CHHTH)
            CALL PSCHXP (CHXPH)
            CALL PSTXP (PRIGHT)

C  scxf = transformation to scale by chhth
            CALL ESC3 (CHHTH,CHHTH,CHHTH, SCXF)
C  corxf = transformation for corners of text rectangle induced
C          by text direction vectors and char-height: TLC to MC
C        = scxf x tdrot
            CALL ECOM3 (SCXF, TDROT, CORXF)

C  compute expected corners of text rectangle in MC, in order
C  left-base, left-cap, right-cap, right-base
            CALL ETP3 (NOMHL,NOMHB,Z, CORXF, CORX(1),CORY(1),CORZ(1))
            CALL ETP3 (NOMHL,NOMHC,Z, CORXF, CORX(2),CORY(2),CORZ(2))
            CALL ETP3 (NOMHR,NOMHC,Z, CORXF, CORX(3),CORY(3),CORZ(3))
            CALL ETP3 (NOMHR,NOMHB,Z, CORXF, CORX(4),CORY(4),CORZ(4))

         ELSE
C  set up for vertical path:
            CALL PSCHH (CHHTV)
            CALL PSCHXP (CHXPV)
            CALL PSTXP (PDOWN)

C  scxf = transformation to scale by chhtv
            CALL ESC3 (CHHTV,CHHTV,CHHTV, SCXF)
C  corxf = transformation for corners of text rectangle induced
C          by text direction vectors and char-height: TLC to MC
C        = scxf x tdrot
            CALL ECOM3 (SCXF, TDROT, CORXF)

C  compute expected corners of text rectangle in MC, in order
C  1:left-base, 2:left-cap, 3:right-cap, 4:right-base
            CALL ETP3 (NOMVL,NOMVB,Z, CORXF, CORX(1),CORY(1),CORZ(1))
            CALL ETP3 (NOMVL,NOMVC,Z, CORXF, CORX(2),CORY(2),CORZ(2))
            CALL ETP3 (NOMVR,NOMVC,Z, CORXF, CORX(3),CORY(3),CORZ(3))
            CALL ETP3 (NOMVR,NOMVB,Z, CORXF, CORX(4),CORY(4),CORZ(4))

         ENDIF

C  the 4 computed corners form a scaled, rotated rectangle in 3D MC,
C  and a parallelogram when projected to xy-plane.

C  cent = center point = (corlb + corlc + corrb + corrc) / 4
         CENTX = (CORX(1)+CORX(2)+CORX(3)+CORX(4)) / 4
         CENTY = (CORY(1)+CORY(2)+CORY(3)+CORY(4)) / 4
         CENTZ = (CORZ(1)+CORZ(2)+CORZ(3)+CORZ(4)) / 4

C  base vector, char-up vector
         HVECX = CORX(4)-CORX(1)
         HVECY = CORY(4)-CORY(1)
         HVECZ = CORZ(4)-CORZ(1)

         VVECX = CORX(2)-CORX(1)
         VVECY = CORY(2)-CORY(1)
         VVECZ = CORZ(2)-CORZ(1)

C  d1vec = 1st diagonal vector = corrc-corlb
C  d2vec = 2nd diagonal vector = corlc-corrb
         D1VECX = CORX(3)-CORX(1)
         D1VECY = CORY(3)-CORY(1)
         D1VECZ = CORZ(3)-CORZ(1)

         D2VECX = CORX(2)-CORX(4)
         D2VECY = CORY(2)-CORY(4)
         D2VECZ = CORZ(2)-CORZ(4)

C  compute values for clipping planes and for expected vertices:
         IF (THISWN.EQ.1 .OR. THISWN.EQ.4) THEN
C  clip off all but one corner:
C  plpt(1) = (corlb + 2*cent) / 3
            MCV3(1,1) = (CORX(1) + 2*CENTX) / 3
            MCV3(2,1) = (CORY(1) + 2*CENTY) / 3
            MCV3(3,1) = (CORZ(1) + 2*CENTZ) / 3
C  vec(1)  = cross-product of d2vec x nvec
            CALL CROSSP (NVECX,NVECY,NVECZ, D2VECX,D2VECY,D2VECZ,
     1                   MCV3(4,1),MCV3(5,1),MCV3(6,1))

C  number of half-planes
            NUMHP = 1
C  expected number of vertices
            EXPNUM = 3
C  expected vertices
            EXPVX(1) = CORX(1)
            EXPVY(1) = CORY(1)
            EXPVZ(1) = CORZ(1)

            EXPVX(2) = (2*CORX(2) + CORX(1)) / 3
            EXPVY(2) = (2*CORY(2) + CORY(1)) / 3
            EXPVZ(2) = (2*CORZ(2) + CORZ(1)) / 3

            EXPVX(3) = (2*CORX(4) + CORX(1)) / 3
            EXPVY(3) = (2*CORY(4) + CORY(1)) / 3
            EXPVZ(3) = (2*CORZ(4) + CORZ(1)) / 3

         ELSEIF (THISWN.EQ.2 .OR. THISWN.EQ.5) THEN
C  clip off 4 corners:

            DO 120 IX = 1,4
               MCV3(1,IX) = (2*CORX(IX) + CENTX) / 3
               MCV3(2,IX) = (2*CORY(IX) + CENTY) / 3
               MCV3(3,IX) = (2*CORZ(IX) + CENTZ) / 3
120         CONTINUE

            CALL CROSSP (D2VECX,D2VECY,D2VECZ, NVECX,NVECY,NVECZ,
     1                   MCV3(4,1),MCV3(5,1),MCV3(6,1))
            CALL CROSSP (D1VECX,D1VECY,D1VECZ, NVECX,NVECY,NVECZ,
     1                   MCV3(4,2),MCV3(5,2),MCV3(6,2))
            DO 125 IX = 3,4
            DO 126 IY = 4,6
               MCV3(IY,IX) = -MCV3(IY,IX-2)
126         CONTINUE
125         CONTINUE

C  number of half-planes
            NUMHP = 4
C  expected number of vertices
            EXPNUM = 8
C  expected vertices
            DO 130 IX = 1,4
            DO 131 IY = 0,1
               IEX = 2*IX + IY - 1
               I2 = MOD1(IX + 2*IY - 1, 4)
               EXPVX(IEX) = (2*CORX(IX) + CORX(I2)) / 3
               EXPVY(IEX) = (2*CORY(IX) + CORY(I2)) / 3
               EXPVZ(IEX) = (2*CORZ(IX) + CORZ(I2)) / 3
131         CONTINUE
130         CONTINUE

         ELSE
C  (thiswn = 3 or 6) clip down the middle:

C  number of half-planes
            NUMHP = 1
            MCV3(1,1) = CENTX
            MCV3(2,1) = CENTY
            MCV3(3,1) = CENTZ

C  expected number of vertices
            EXPNUM = 4
            IF (THISWN.EQ.3) THEN
C  clip horizontally - clip away top half
C  vec(1) = cross-product of hvec x nvec
               CALL CROSSP (HVECX,HVECY,HVECZ, NVECX,NVECY,NVECZ,
     1                      MCV3(4,1),MCV3(5,1),MCV3(6,1))
               EXPVX(1) = CORX(1)
               EXPVY(1) = CORY(1)
               EXPVZ(1) = CORZ(1)

               EXPVX(2) = CORX(4)
               EXPVY(2) = CORY(4)
               EXPVZ(2) = CORZ(4)

               EXPVX(3) = (CORX(4) + CORX(3)) / 2
               EXPVY(3) = (CORY(4) + CORY(3)) / 2
               EXPVZ(3) = (CORZ(4) + CORZ(3)) / 2

               EXPVX(4) = (CORX(1) + CORX(2)) / 2
               EXPVY(4) = (CORY(1) + CORY(2)) / 2
               EXPVZ(4) = (CORZ(1) + CORZ(2)) / 2

            ELSE
C  clip vertically - clip away left side
C  vec(1) = cross-product of vvec x nvec
               CALL CROSSP (VVECX,VVECY,VVECZ, NVECX,NVECY,NVECZ,
     1                      MCV3(4,1),MCV3(5,1),MCV3(6,1))
               EXPVX(1) = CORX(3)
               EXPVY(1) = CORY(3)
               EXPVZ(1) = CORZ(3)

               EXPVX(2) = CORX(4)
               EXPVY(2) = CORY(4)
               EXPVZ(2) = CORZ(4)

               EXPVX(3) = (CORX(4) + CORX(1)) / 2
               EXPVY(3) = (CORY(4) + CORY(1)) / 2
               EXPVZ(3) = (CORZ(4) + CORZ(1)) / 2

               EXPVX(4) = (CORX(3) + CORX(2)) / 2
               EXPVY(4) = (CORY(3) + CORY(2)) / 2
               EXPVZ(4) = (CORZ(3) + CORZ(2)) / 2
            ENDIF
         ENDIF

C   set MCV (with REPLACE operator)
         CALL PSMCV3 (PMCREP, NUMHP, MCV3)

C  draw 3D text
         CALL PTX3 (Z,Z,Z, TDX,TDY,TDZ, TXSTR)

         IF (THISWN .EQ. NGWIN) THEN
            EXPVX(3) = CENTX
            EXPVY(3) = CENTY
            EXPVZ(3) = CENTZ
         ENDIF

C  compute expected vertices in WC
         DO 155 IX = 1,EXPNUM+1
            IY = MOD(IX, EXPNUM) + 1
            CALL ETP3 (EXPVX(IY),EXPVY(IY),EXPVZ(IY), XF,
     1                 XA(IX),YA(IX),ZA(IX))
155      CONTINUE
         CALL PSMCLI (PNCLIP)
         CALL IDMAT (4, SCXF)
         CALL PSLMT3 (SCXF, PCREPL)
         CALL PPL (EXPNUM+1, XA,YA)

C  next thiswn
100   CONTINUE

      CALL DCHPFV ('MODELLING CLIPPING OF STROKE TEXT: In which ' //
     1             'window is the clipped text NOT accurately '   //
     2             'outlined?', 6, NGWIN)

      CALL PEMST (102)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('40 41 42 43 53 57 58 60', 'Characters in a text ' //
     1             'primitive drawn in CHAR precision that lie '      //
     2             'completely outside the current modelling '        //
     3             'clipping volume should be clipped, and those '    //
     4             'completely inside should not be clipped.')

C  set constant attributes
      CALL PSCHSP (0.0)
      CALL PSTXFN (TXFONT)
      CALL PSTXPR (PCHARP)
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH (0.05 * CHHTH)
      CALL PSCHXP (1.0)
      CALL PSTXP (PRIGHT)

      CHSTR = 'EEEEEEEEEEEEE'
      NUMVIS = RNDINT(2,6)
C  number of characters drawn
      TXLEN = 2*NUMVIS + 1

C  set 2D MCV (with REPLACE operator) with 1 half-plane =
C     point: (.5,.5); vector: (1,0)
      CALL SETRVS ('.5,.5, 1,0', MCV2, IX)
      CALL PSMCV (PMCREP, 1, MCV2)
      CALL PSMCLI (PCLIP)

      CALL PTX (H,H, CHSTR(1:TXLEN))

      CALL DCHOIC ('MODELLING CLIPPING OF CHAR TEXT: How many ' //
     1             'characters are at least partially visible?',
     2             0,15, OPANS)
      IF (OPANS .EQ. 0) THEN
         CALL OPFAIL
      ELSE
         CALL IFPF (OPANS.EQ.NUMVIS .OR. OPANS.EQ.NUMVIS+1)
      ENDIF

      CALL PEMST (102)

C  *** *** *** ***   annotation text   *** *** *** ***

      CALL SETMSG ('40 41 42 43 53 57 58 61 62', 'If its reference '  //
     1             'point is inside the current MCV, then those '     //
     2             'parts of an annotation text primitive that also ' //
     3             'lie inside should be visible, but if its '        //
     4             'reference point is outside the current MCV, '     //
     5             'then the entire annotation text primitive '       //
     6             'should be model-clipped.')

C  set up 6 windows
      CALL PEXST (106)

C  npcpwc = NPC units per WC units
      CALL WCNPC (Z,Z, RDUM1,RDUM2, NPCPWC)
C  winsiz = window-size in NPC = window-size in WC * npcpwc
      WINSIZ = XSIZ * NPCPWC

      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSTXCI (1)
      CALL PSCHSP (0.0)
      CALL PSCHXP (1.0)
      CALL PSATCH (0.2 * WINSIZ)
      CALL PSATP  (PRIGHT)
      CALL PSATAL (PACENT,PAHALF)
      CALL PSANS  (2)
      CALL PSPLCI (2)
      CALL PSLN   (PLSOLI)

C  ranwin = list of 6 integers chosen from 1-8
      CALL RNSET (6, 8, RANWIN)
C  vislis = list of windows with invisible annotation text = empty
      VISDX = 0
C  set clipping ON
      CALL PSMCLI (PCLIP)

C  x-component of clipping vector
      MCV3(4,1) = Z
      DO 200 THISWN = 1,6       
         WNTYPE = RANWIN(THISWN)
C  center of window
         MCV3(1,1) = XWINLO(THISWN) + XSIZ/2
         MCV3(2,1) = YWINLO(THISWN) + YSIZ/2
         MCV3(3,1) = H

C  point MCV vector to 4 quadrants around the x-axis:
         IF (MOD(WNTYPE,4) .LT. 2) THEN
            MCV3(5,1) = -1
         ELSE
            MCV3(5,1) =  1
         ENDIF
         MCV3(6,1) = 2 * MOD(WNTYPE,2) - 1
         CALL PSMCV3 (PMCREP, 1, MCV3)

         IF (WNTYPE .LT. 5) THEN
C  should be partially visible:
            DELTA = 0.01
         ELSE
C  should be invisible:
            VISDX = VISDX+1
            VISLIS(VISDX) = THISWN
            DELTA = -0.01
         ENDIF

C  delta vector, in WC:
         D1VECX = 2*DELTA
         D1VECY = DELTA*MCV3(5,1)
         D1VECZ = DELTA*MCV3(6,1)

C  draw annotation text "ABC" at refpt with offset
         CALL PATR3 (MCV3(1,1) + D1VECX,
     1               MCV3(2,1) + D1VECY,
     2               MCV3(3,1) + D1VECZ,
     3        -2 * D1VECX * NPCPWC,
     4        -2 * D1VECY * NPCPWC,
     5        -2 * D1VECZ * NPCPWC, 'ABC')

C  next thiswn
200   CONTINUE

      CALL DLSTPF ('MODELLING CLIPPING OF ENTIRE ANNOTATION TEXT: ' //
     1             'List all the empty windows.', VISDX, VISLIS, 'S')

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** ***
C
      CALL SETMSG ('40 41 42 43 53 57 58 62', 'If its reference '    //
     1             'point is inside the current MCV, then at least ' //
     2             'those parts of an annotation text primitive '    //
     3             'that also lie inside should be visible.')

C  txstr = text string with ASCII characters that fill character box
      ATXSTR = 'EXAM'
      TXFONT = 1

C  *** *** ***  set up expected horizontal text extent:

      TXPATH = PRIGHT
      CALL TXEXAL (TXFONT, TXPATH, ATXSTR, NTXWD, NTXHT, HTAB, VTAB)
                                      
C  using text alignment = center,half:
C  nomhl,nomhr = nominal x-location of left,right border of horizontal string
C  nomhb,nomhc = nominal y-location of baseline,capline of horizontal string
      NOMHL = HTAB(PALEFT) - HTAB(PACENT)
      NOMHR = HTAB(PARITE) - HTAB(PACENT)
      NOMHB = VTAB(PABASE) - VTAB(PAHALF)
      NOMHC = VTAB(PACAP)  - VTAB(PAHALF)

C  number of lines to display 
      NUMLIN = 8
      YINCR = 1 / (NUMLIN + 1.0)
      YTOP = 1-YINCR
      YLOC = YTOP

C  set achht (in WC) to scale ann-text so as to fit on line:
      ACHHT = 0.5 * YINCR
      NOMHL = NOMHL * ACHHT
      NOMHR = NOMHR * ACHHT
      NOMHB = NOMHB * ACHHT
      NOMHC = NOMHC * ACHHT

C  set up attributes
      CALL PSTXFN (TXFONT)
      CALL PSTXPR (PSTRKP)
      CALL PSCHSP (0.0)
      CALL PSCHXP (1.0)
      CALL PSATCH (ACHHT*NPCPWC)
      CALL PSATAL (PACENT,PAHALF)
      CALL PSATP  (TXPATH)
      CALL PSTXCI (1)
      CALL PSPLCI (2)
      CALL PSLN   (PLDOT)
      CALL PSLWSC (0.01)

C  draw labels for numlin lines
      CALL NUMLAB (NUMLIN, 0.1, YTOP,YINCR)
C  ngline = incorrect line = random from 1 to numlin
      NGLINE = RNDINT(1,NUMLIN)
C  expected number of vertices 
      EXPNUM = 5

      DO 400 THISLN = 1,NUMLIN
         CALL PSMCLI (PCLIP)
C  compute values for clipping planes and for expected vertices:

C  compute expected annotation text position:
         CHXP = RNDRL(0.6, 1.4)
C  reference point for annotation text 
         XCENT = RNDRL(0.3, 0.8)

         XLEFT = XCENT + NOMHL*CHXP
         XRITE = XCENT + NOMHR*CHXP
         YBAS  = YLOC  + NOMHB
         YCAP  = YLOC  + NOMHC
         CALL PSCHXP (CHXP)

C    clip down the middle:
         MCV3(1,1) = XCENT
         MCV3(2,1) = YLOC
         MCV3(3,1) = 0.5

         MCV3(4,1) = NOMHC * SIGN(1.0, 0.55-XCENT)
         MCV3(5,1) = NOMHL * CHXP * RNDRL(-0.7,0.7)
         MCV3(6,1) = 0.1

C  set MCV (with REPLACE operator) with 1 half-plane
         CALL PSMCV3 (PMCREP, 1, MCV3)
                       
C  delta vector, in WC:
         DELTA = 0.1
         D1VECX = DELTA*MCV3(4,1)
         D1VECY = DELTA*MCV3(5,1)
         D1VECZ = DELTA*MCV3(6,1)

C     draw 3D annotation text:
         CALL PATR3 (MCV3(1,1) + D1VECX,
     1               MCV3(2,1) + D1VECY,
     2               MCV3(3,1) + D1VECZ,
     3               -D1VECX*NPCPWC, -D1VECY*NPCPWC, -D1VECZ*NPCPWC,
     4               ATXSTR)

C  compute expected vertices in WC:
         EXPVY(1) = YCAP
         EXPVY(2) = YBAS
         EXPVY(3) = YBAS
         EXPVY(4) = YCAP
         EXPVY(5) = YCAP

         IF (MCV3(4,1) .GT. 0.0) THEN
            EXPVX(1) = XRITE
            EXPVX(2) = XRITE
            EXPVX(5) = XRITE
         ELSE
            EXPVX(1) = XLEFT
            EXPVX(2) = XLEFT
            EXPVX(5) = XLEFT
         ENDIF

         VYX = MCV3(5,1)/MCV3(4,1)
         EXPVX(3) = XCENT + (YLOC-YBAS) * VYX
         EXPVX(4) = XCENT + (YLOC-YCAP) * VYX

         IF (THISLN .EQ. NGLINE) THEN
C  distort vertices:
            DELTA = 0.15
            IF (XCENT .GT. 0.55) DELTA = -DELTA
            DO 410 IX = 1,EXPNUM
               EXPVX(IX) = EXPVX(IX) + DELTA
410         CONTINUE
         ENDIF

         CALL PSMCLI (PNCLIP)
C     draw expected 2D polyline for expv(1 to expnum)
         CALL PPL (5, EXPVX,EXPVY)
         YLOC = YLOC-YINCR

C  next thisln
400   CONTINUE

      CALL DCHPFV ('PARTIAL MODELLING CLIPPING OF ANNOTATION TEXT: ' //
     1             'On which line is the dotted boundary NOT '       //
     2             'filled with annotation text (additional '        //
     3             'annotation text outside boundary is permitted)?',
     4             NUMLIN, NGLINE)

      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

