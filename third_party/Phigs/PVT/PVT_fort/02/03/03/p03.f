C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.03/03                           *
C  *    TEST TITLE : Geometrical borderline cases for      *
C  *                 graphical primitives                  *
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
 
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
 
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
 
C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON
 
      INTEGER    ARRSIZ
      PARAMETER (ARRSIZ = 20)
      INTEGER    NSZ, TXPATH, TXALH,TXALV, CX
      INTEGER    COLIA(3,2), ENDPTS(5), NPTS
 
      REAL       NDTRAN(4,4), XS(ARRSIZ), YS(ARRSIZ), ZS(ARRSIZ),
     1                        XC(ARRSIZ), YC(ARRSIZ), ZC(ARRSIZ)
      REAL       SISRPX,SISRPY,SISRPZ, SDIST, PI, ZDIST, VECL
      REAL       TDVX(2),TDVY(2),TDVZ(2), COR12X,COR12Y,COR12Z
      REAL       TLCUX,TLCUY,TLCUZ, TLCVX,TLCVY,TLCVZ, TLCWX,TLCWY,TLCWZ
      REAL       TPOSX,TPOSY,TPOSZ, TEMPX,TEMPY,TEMPZ, MIDX,MIDY,MIDZ
      REAL       CHHT, CHUPU,CHUPV, IDTRAN(4,4)
      REAL       RECX(2),RECY(2), RDUM1,RDUM2
      REAL       ROTMAT(4,4), XTLC(4),YTLC(4),ZTLC(4)
      REAL       XMC(4),YMC(4),ZMC(4), NPEX,NPEY,NPEZ
 
      LOGICAL    SPHDIS
 
      PARAMETER (PI = 3.14159265)
 
      CHARACTER  STR*32
 
      CALL INITGL ('02.03.03/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF
 
C  ndtran = non-distorting transformation: arbitrary shift and
C    rotate (but not scale).  Apply this to easily visualized
C    2D cases to generate more complex 3D cases.
      CALL EBLTM3 (.2,.3,.434, 2.2,3.1,4.9, 1.3,2.4,3.55, 1.0,1.0,1.0,
     1             NDTRAN)
 
C  identity matrix
      CALL IDMAT (4, IDTRAN)
 
      DATA ZS / ARRSIZ*0.0 /
 
      CALL POPST (101)
 
C  *** *** *** *** ***   polyline   *** *** *** *** *** ***
C
C  simpl = simple polyline = (1,1),(2,2),(2,1)
      CALL SETRVS ('1,2,2', XS, NSZ)
      CALL SETRVS ('1,2,1', YS, NSZ)
C  compl = complex polyline = ndtran X simpl
      CALL ARRTP3 (NSZ, XS,YS,ZS, NDTRAN, XC,YC,ZC)
 
C  Build structure 101:
      CALL PEMST (101)
      CALL PPL3 (NSZ, XC,YC,ZC)
 
C  sisrp = simple search reference point = (2.1, 1.5, 0.1)
      SISRPX = 2.1
      SISRPY = 1.5
      SISRPZ = 0.1
C  sdist = distance from primitive
      SDIST = 0.1 * SQRT(2.0)
 
      CALL SETMSG ('2 4 5 6 7 9 10 12', 'The middle of a line '       //
     1             'segment in a 3D polyline should be found if and ' //
     2             'only if its true distance from the search '       //
     3             'reference point is not greater than the search '  //
     4             'distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
C  sisrp = simple search reference point = (2.1, 2.1, 0.1)
      SISRPX = 2.1
      SISRPY = 2.1
      SISRPZ = 0.1
C  sdist = distance from primitive = 0.1 * sqrt(3)
      SDIST = 0.1 * SQRT(3.0)
 
      CALL SETMSG ('2 4 5 6 7 9 10 12', 'The vertex of a 3D '       //
     1             'polyline should be found if and only if its '   //
     2             'true distance from the search reference point ' //
     3             'is not greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
 
C  *** *** *** *** ***   text   *** *** *** *** *** ***
C
C  tdv1 =  first text direction vector = 1.2, 5.1, 0.2
      TDVX(1) = 1.2
      TDVY(1) = 5.1
      TDVZ(1) = 0.2
C  tdv2 = second text direction vector = 2.1, 1.4, 3.2
      TDVX(2) = 2.1
      TDVY(2) = 1.4
      TDVZ(2) = 3.2
C  tlcu = text local co-ordinate U vector = normalized tdv1
      CALL VEC1 (TDVX(1),TDVY(1),TDVZ(1),  TLCUX,TLCUY,TLCUZ)
C  tlcv = text local co-ordinate V vector = unit vector in tdv-plane,
C         perpendicular to tlcu, and such that tlcv . tdv2 > 0
      CALL PERVEC ( TLCUX,TLCUY,TLCUZ, TDVX(2),TDVY(2),TDVZ(2),
     1              TEMPX,TEMPY,TEMPZ)
      CALL VEC1   ( TEMPX,TEMPY,TEMPZ, TLCVX,TLCVY,TLCVZ)
C  tlcw = text local co-ordinate W vector, perpendicular to text
C         plane = tlcu X tlcv
      CALL CROSSP ( TLCUX,TLCUY,TLCUZ, TLCVX,TLCVY,TLCVZ,
     1              TLCWX,TLCWY,TLCWZ)
C  tpos = text position = 3.1, 4.2, 0.1
      TPOSX = 3.1
      TPOSY = 4.2
      TPOSZ = 0.1
 
C  Set up geometric attributes: character height, character up
C  vector, text path, text alignment
      CHHT   =  3.3
      CHUPU  =  1.2
      CHUPV  = -3.1
      TXPATH = PUP
      TXALH  = PACENT
      TXALV  = PACAP
C  str = character string = "Quod licet Jovi, non licet bovi."
      STR = 'Quod licet Jovi, non licet bovi.'
 
C  Get specific workstation type
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
C  <inquire text extent> with
C    workstation type           = primary workstation type
C      (ignored because font #1 is workstation-independent)
C    text font                  = 1
C    character expansion factor = 1.0
C    character spacing          = 0.0
C      (three above set as assumed by spatial search, see SR15)
C    character height           = chht
C    text path                  = txpath
C    text alignment             = txalh,txalv
C    character string           = str
C      to determine:
C    recxlo,recxhi,recylo,recyhi = text extent rectangle in TLC,
C      with assumed text position = 0,0 character up vector = (0,1),
C      and text precision = STROKE.
      CALL PQTXX (SPECWT, 1, 1.0, 0.0, CHHT, TXPATH, TXALH,TXALV, STR,
     1            ERRIND, RECX,RECY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
 
C close workstation
      CALL PCLWK (WKID)
 
C  Rotate expected rectangle in TLC around 0,0 according to
C    character-up vector.
C  build and apply transformation
      CALL EROZ (ATAN2(CHUPV, CHUPU) - PI/2, ROTMAT)
      CALL ETP3 (RECX(1), RECY(1), 0.0, ROTMAT, XTLC(1),YTLC(1),ZTLC(1))
      CALL ETP3 (RECX(2), RECY(1), 0.0, ROTMAT, XTLC(2),YTLC(2),ZTLC(2))
      CALL ETP3 (RECX(2), RECY(2), 0.0, ROTMAT, XTLC(3),YTLC(3),ZTLC(3))
      CALL ETP3 (RECX(1), RECY(2), 0.0, ROTMAT, XTLC(4),YTLC(4),ZTLC(4))
 
C  Transform 4 TLC corners to expected values in MC; use tlc-vectors
C  for rotation and tpos for shift.  Also, get midpoint:
      MIDX = 0.0
      MIDY = 0.0
      MIDZ = 0.0
 
      DO 110 CX = 1,4
         XMC(CX) = TPOSX + TLCUX*XTLC(CX)+TLCVX*YTLC(CX)+TLCWX*ZTLC(CX)
         YMC(CX) = TPOSY + TLCUY*XTLC(CX)+TLCVY*YTLC(CX)+TLCWY*ZTLC(CX)
         ZMC(CX) = TPOSZ + TLCUZ*XTLC(CX)+TLCVZ*YTLC(CX)+TLCWZ*ZTLC(CX)
         MIDX = MIDX + XMC(CX)/4
         MIDY = MIDY + YMC(CX)/4
         MIDZ = MIDZ + ZMC(CX)/4
110   CONTINUE
 
C  Expected MC rectangle is complete; now generate actual text extent.
 
C  Build structure 101:
C    1.  set text precision      = STRING
C    2.  set character height    = chht
C    3.  set character up vector = chup
C    4.  set text path           = txpath
C    5.  set text alignment      = txalh,txalv
C    6.  text 3: str at tpos with tdv1,tdv2
 
      CALL PEMST  (101)
      CALL PSTXPR (PSTRP)
      CALL PSCHH  (CHHT)
      CALL PSCHUP (CHUPU,CHUPV)
      CALL PSTXP  (TXPATH)
      CALL PSTXAL (TXALH,TXALV)
      CALL PTX3   (TPOSX,TPOSY,TPOSZ, TDVX,TDVY,TDVZ, STR)
 
C  Project SRP out past corner #4:
C  SRP    = corner(4) + (corner(4) - mid-point)
      SISRPX = XMC(4) + (XMC(4) - MIDX)
      SISRPY = YMC(4) + (YMC(4) - MIDY)
      SISRPZ = ZMC(4) + (ZMC(4) - MIDZ)
C  sdist  = distance from corner(4) to mid-point
      SDIST = VECL (XMC(4)-MIDX, YMC(4)-MIDY, ZMC(4)-MIDZ)
 
      CALL SETMSG ('2 4 5 6 7 9 10 15', 'The size of a 3D text '  //
     1             'extent rectangle, as treated by ISS, should ' //
     2             'be based on STROKE precision, even if the '   //
     3             'current precision is not STROKE.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, IDTRAN, PNCLIP, '101,6')
 
C  replace element number #1 with:
C     1.  set text precision      = STROKE
      CALL PDELRA (1,1)
      CALL PSTXPR (PSTRKP)
 
      CALL SETMSG ('2 4 5 6 7 9 10 15', 'The corner of a 3D text '    //
     1             'extent rectangle should be found if and only if ' //
     2             'its true distance from the search reference '     //
     3             'point is not greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, IDTRAN, PNCLIP, '101,6')
 
C  Project SRP above text plane:
C  SRP    = mid-point + tlcw
      SISRPX = MIDX + TLCWX
      SISRPY = MIDY + TLCWY
      SISRPZ = MIDZ + TLCWZ
C  sdist  = 1.0 (because tlcw is a unit vector).
      SDIST = 1.0
 
      CALL SETMSG ('2 4 5 6 7 9 10 15', 'The middle of a 3D text '    //
     1             'extent rectangle should be found if and only if ' //
     2             'its true distance from the search reference '     //
     3             'point is not greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, IDTRAN, PNCLIP, '101,6')
 
C  Project SRP above and outside of edge of text plane:
      ZDIST = 2.2
C  cor12  = vector from corner 2 to corner 1 = corner(1) - corner(2)
      COR12X = XMC(1) - XMC(2)
      COR12Y = YMC(1) - YMC(2)
      COR12Z = ZMC(1) - ZMC(2)
C  SRP    = mid-point + zdist*tlcw + cor12
      SISRPX = MIDX + ZDIST*TLCWX + COR12X
      SISRPY = MIDY + ZDIST*TLCWY + COR12Y
      SISRPZ = MIDZ + ZDIST*TLCWZ + COR12Z
C  sdist  = sqrt (zdist ** 2 + (cor12 / 2) ** 2 )
      SDIST = SQRT (ZDIST**2 + VECL (COR12X/2, COR12Y/2, COR12Z/2) )
 
      CALL SETMSG ('2 4 5 6 7 9 10 15', 'The edge of a 3D text '      //
     1             'extent rectangle should be found if and only if ' //
     2             'its true distance from the search reference '     //
     3             'point is not greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, IDTRAN, PNCLIP, '101,6')
 
 
C  *** *** *** *** ***   cell array   *** *** *** *** *** ***
C
C  simpl = simple cell array = p:(1,1), q:(4,2), r:(2,3)
      CALL SETRVS ('1,4,2', XS, NSZ)
      CALL SETRVS ('1,2,3', YS, NSZ)
C  compl = complex cell array = ndtran X simpl
      CALL ARRTP3 (NSZ, XS,YS,ZS, NDTRAN, XC,YC,ZC)
 
      DATA COLIA / 0, 1, 1, 0, 1, 0 /
 
C  Build structure 101:
      CALL PEMST (101)
      CALL PCA3  (XC,YC,ZC, 3,2, 1,1, 3,2, COLIA)
 
C  sisrp = simple search reference point = (2, 2, 0.1)
      SISRPX = 2.0
      SISRPY = 2.0
      SISRPZ = 0.1
C  sdist = distance from primitive = 0.1
      SDIST  = 0.1
 
      CALL SETMSG ('2 4 5 6 7 9 10 17', 'The interior region of a ' //
     1             '3D cell array should be found if and only if '  //
     2             'its true distance from the search reference '   //
     3             'point is not greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
C  sisrp = simple search reference point = (1, 2.25, 0.1)
      SISRPX = 1.0
      SISRPY = 2.25
      SISRPZ = 0.1
C  npe   = nearest point on edge = (1.5, 2, 0)
      NPEX = 1.5
      NPEY = 2.0
      NPEZ = 0.0
C  sdist = distance from primitive =
      SDIST = VECL (SISRPX-NPEX, SISRPY-NPEY, SISRPZ-NPEZ)
 
      CALL SETMSG ('2 4 5 6 7 9 10 17', 'The edge of a 3D cell '      //
     1             'array should be found if and only if its true '   //
     2             'distance from the search reference point is not ' //
     3             'greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
C  *** *** *** *** ***   fill area   *** *** *** *** *** ***
C
C  simple fill area looks like:
C
C          ------- 2,3.5
C          |     |
C       ---+---  |
C       |  |  |  |
C       |  ----  |
C       |        |
C       |  ----  |
C       |  |  |  |
C       ----  |  |
C             |  |
C       -------  |
C       |        |
C   0,0 ---------- 2,0
 
      CALL SETRVS ('0,2,2,   .5, .5,1.5,1.5,0,0, .5,.5,1.5,1.5,0  ',
     1             XS,NSZ)
      CALL SETRVS ('0,0,3.5,3.5,2,  2,  3,  3,1,1, 1.5,1.5, .5, .5',
     1             YS,NSZ)
C  compl = complex fill area = ndtran X simpl
      CALL ARRTP3 (NSZ, XS,YS,ZS, NDTRAN, XC,YC,ZC)
 
C  Build structure 101:
      CALL PEMST (101)
      CALL PFA3  (NSZ, XC,YC,ZC)
 
C  sisrp = simple search reference point = (1, 1.7, 0.1)
      SISRPX = 1.0
      SISRPY = 1.7
      SISRPZ = 0.1
C  sdist = distance from primitive = 0.1
      SDIST = 0.1
 
      CALL SETMSG ('2 4 5 6 7 9 10 13', 'The interior region of a '   //
     1             '3D fill area should be found if and only if its ' //
     2             'true distance from the search reference point '   //
     3             'is not greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
C  sisrp = simple search reference point = (2.2, 1, 5)
      SISRPX = 2.2
      SISRPY = 1.0
      SISRPZ = 5.0
C  sdist = distance from primitive
      SDIST = VECL (0.2, 0.0, 5.0)
 
      CALL SETMSG ('2 4 5 6 7 9 10 13', 'The edge of a 3D fill area ' //
     1             'should be found if and only if its true '         //
     2             'distance from the search reference point is not ' //
     3             'greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
C  sisrp = simple search reference point = (1.1, 1.2, 0)
      SISRPX = 1.1
      SISRPY = 1.2
      SISRPZ = 0.0
C  sdist = distance from primitive = 0.3
      SDIST = 0.3
 
      CALL SETMSG ('2 4 5 6 7 9 10 13', 'A concave region of a 3D ' //
     1             'fill area should be found if and only if its '  //
     2             'true distance from the search reference point ' //
     3             'is not greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
C  sisrp = simple search reference point = (1.1, 2.7, 0)
      SISRPX = 1.1
      SISRPY = 2.7
      SISRPZ = 0.0
C  sdist = distance from primitive = 0.3
      SDIST = 0.3
 
      CALL SETMSG ('2 4 5 6 7 9 10 13', 'An interior region of a 3D ' //
     1             'fill area surrounding a hole formed by a '        //
     2             'self-intersecting border should be found if and ' //
     3             'only if its true distance from the search '       //
     4             'reference point is not greater than the search '  //
     5             'distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
C  *** *** *** *** ***   fill area set   *** *** *** *** *** ***
C
C  simpl = simple fill area set = (1,0), (0,0), (0,1), (1,1) /
C                                 (2,1), (3,1), (3,0), (2,0)
      CALL SETRVS ('1,0,0,1,2,3,3,2', XS,NSZ)
      CALL SETRVS ('0,0,1,1,1,1,0,0', YS,NSZ)
C  compl = complex fill area set = ndtran X simpl
      CALL ARRTP3 (NSZ, XS,YS,ZS, NDTRAN, XC,YC,ZC)
 
      CALL SETVS  ('4,8', ENDPTS, NPTS)
C  Build structure 101:
      CALL PEMST (101)
      CALL PFAS3 (NPTS, ENDPTS, XC,YC,ZC)
 
C  sisrp = simple search reference point = (1.8, 0.2, 0)
      SISRPX = 1.8
      SISRPY = 0.2
      SISRPZ = 0.0
C  sdist = distance from primitive = 0.2
      SDIST = 0.2
 
      CALL SETMSG ('2 4 5 6 7 9 10 14', 'The edge of a 3D fill area ' //
     1             'set should be found if and only if its true '     //
     2             'distance from the search reference point is not ' //
     3             'greater than the search distance.')
      CALL ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, NDTRAN, PNCLIP, '101,1')
 
666   CONTINUE
      CALL ENDIT
      END
