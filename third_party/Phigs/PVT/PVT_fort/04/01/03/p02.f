C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.03/02                           *
C  *    TEST TITLE : Appearance of text primitives         *
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

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,     PCPOST,     PCREPL
      PARAMETER (PCPRE = 0, PCPOST = 1, PCREPL = 2)

      INTEGER    PICSTR, TXCI, IX, RNDINT, PRIMID
      INTEGER    NOTHOZ, NHOZ, NUMLIN, N2D, NGSQ, PERM(10)

      REAL       TDVX(2), TDVY(2), TDVZ(2), TDV1(3,5), TDV2(3,5)
      REAL       XLOC, YLOC, YINCR, XMID, YMID, ZMID
      REAL       XSIZ,YSIZ,XWINLO(6),YWINLO(6),ROTX,ROTY,ROTZ
      REAL       IDM(4,4), XF(4,4)
      REAL       XCORD, YCORD, ZCORD, Z, H, U, PI, RNDRL
      PARAMETER (Z=0.0, H=0.5, U=1.0, PI=3.14159265)

      CHARACTER  UPPER*26, CHSTR*5, LOWER*26, REPSTR*10, CHRABC*3

      DATA TDV1/0.,0.,0., 0.,0.,0., 3.,4.,5., 1.,-2.,3.,  8.,1.,0./
      DATA TDV2/2.,3.,4., 0.,0.,0., 0.,0.,0., 3.,-6.,9., -1.,8.,0./

      CALL INITGL ('04.01.03/02')

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

C  set default text attributes:
C  font = 1, precision = STROKE, text alignment = CENTRE,HALF
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSTXAL (PACENT, PAHALF)
      CALL PSTXP  (PRIGHT)
      CALL PSCHH (0.1)

C  set up 102 as sub-structure
      CALL PEXST (102)
      CALL PCLST

C  *** *** *** ***   character content   *** *** *** ***

      CALL SETMSG ('9', 'A displayed text primitive should contain ' //
     1             'the specified character string.')

      CALL POPST (102)

      CALL PSTXFN (2)
      UPPER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

C  chstr = string of 5 randomly chosen upper-case letters
      CALL RNSET (5, 26, PERM)
      DO 100 IX = 1, 5
         CHSTR(IX:IX) = UPPER(PERM(IX):PERM(IX))
100   CONTINUE

C  display <text 3> consisting of chstr:
C    position = 0.5,0.5,0.5
C    TDV = (1,0,0), (0,1,0)
      XCORD = H
      YCORD = H
      ZCORD = H
      TDVX(1) = U
      TDVY(1) = Z
      TDVZ(1) = Z
      TDVX(2) = Z
      TDVY(2) = U
      TDVZ(2) = Z
      CALL PTX3 (XCORD, YCORD, ZCORD, TDVX, TDVY, TDVZ, CHSTR)

      CALL DLINE ('CHARACTER CONTENT: Enter the displayed character '//
     1            'string.', REPSTR)
      CALL PEMST (102)

      IF (REPSTR .NE. CHSTR) THEN
         CALL FAIL
         GOTO 199
      ENDIF

      CALL PSTXFN (1)
C  chstr = string of 5 randomly chosen lower-case letters
      LOWER = 'abcdefghijklmnopqrstuvwxyz'
      CALL RNSET (5, 26, PERM)
      DO 110 IX = 1, 5
         CHSTR(IX:IX) = LOWER(PERM(IX):PERM(IX))
110   CONTINUE

C  display <text> consisting of chstr:
C     at (0.5, 0.5)
      XCORD = H
      YCORD = H
      CALL PTX (XCORD, YCORD, CHSTR)

      CALL DLINE ('CHARACTER CONTENT: Enter the displayed character '//
     1            'string.', REPSTR)
      CALL PEMST (102)
      CALL IFPF (REPSTR .EQ. CHSTR)

C  end_char:
199   CONTINUE

C  *** *** *** ***   degenerate vectors   *** *** *** ***

      NUMLIN = 6
      NHOZ = 5
      N2D = 6
      CHRABC = 'ABC'

C  create random array
      CALL RNPERM (NUMLIN, PERM)

C  In random order, display on 6 lines:
C                 1st vector   2nd vector
C  3D text "ABC"  (0,0,0)      (2,3,4)
C  3D text "ABC"  (0,0,0)      (0,0,0)
C  3D text "ABC"  (3,4,5)      (0,0,0)
C  3D text "ABC"  (1,-2,3)     (3,-6,9) (parallel vectors)
C  3D text "ABC"  (8,1,0)      (-1,8,0) (not horizontal)
C  2D text "ABC"   n.a.         n.a.
      XLOC = 0.4
      YINCR = 1.0/(NUMLIN+1)
      YLOC  = 1-YINCR
      CALL PSCHH (0.06)
      CALL NUMLAB (NUMLIN, 0.2, YLOC, YINCR)
      DO 230 IX = 1, NUMLIN
         PRIMID = PERM(IX)
         IF (PRIMID .EQ. NHOZ) THEN
            NOTHOZ = IX
         ENDIF
         IF (PRIMID .EQ. N2D)   THEN
            CALL PTX (XLOC, YLOC, CHRABC)
         ELSE
            TDVX(1) = TDV1(1, PRIMID)
            TDVY(1) = TDV1(2, PRIMID)
            TDVZ(1) = TDV1(3, PRIMID)
            TDVX(2) = TDV2(1, PRIMID)
            TDVY(2) = TDV2(2, PRIMID)
            TDVZ(2) = TDV2(3, PRIMID)
            CALL PTX3 (XLOC, YLOC, H, TDVX, TDVY, TDVZ, CHRABC)
         ENDIF
         YLOC = YLOC - YINCR
230   CONTINUE

      CALL SETMSG ('9 10 11', 'The values (1,0,0) and (0,1,0) '       //
     1             'should be used as text direction vectors for '    //
     2             'all 2D text primitives and also when the '        //
     3             'explicit vectors of a 3D text primitive fail to ' //
     4             'define a plane.')

      CALL DCHPFV ('DEGENERATE TEXT DIRECTION VECTORS: Which text '//
     1             'line is different?', NUMLIN, NOTHOZ)

      CALL PEMST (102)

C  *** *** *** ***   effect of text direction vectors   *** *** *** ***

      CALL PEXST (106)
      CALL PEXST (103)
      CALL PCLST
C  Divide screen up into 6 square labelled areas
      CALL WIN6 (106, 2, XSIZ, YSIZ, XWINLO, YWINLO)

      CALL POPST (103)

      NGSQ = RNDINT (1,6)
      CHRABC = 'ABC'
      ZMID = H
C  idm = identity matrix
      CALL IDMAT (4, IDM)

      DO 310 IX = 1, 6
C   xmid,ymid = center of box #ix
         XMID = XWINLO(IX) + XSIZ/2
         YMID = YWINLO(IX) + YSIZ/2
C  rotx = random from -45.0 to 45.0 degrees
C  roty = random from -45.0 to 45.0 degrees
C  rotz = random from 0 to 360 degrees
         ROTX = RNDRL (45., -45.) * PI/180.
         ROTY = RNDRL (45., -45.) * PI/180.
         ROTZ = RNDRL ( 0., 360.) * PI/180.

C   build transformation matrix xf for rotation - rotx, roty, rotz
C     centered at 0,0,0
         CALL EBLTM3 (Z, Z, Z, Z, Z, Z,
     1                ROTX, ROTY, ROTZ, U, U, U, XF)

C     calculate equivalent TDVs:
C     tdv1x,tdv1y,tdv1z = (1,0,0) transformed by xf
C     tdv2x,tdv2y,tdv2z = (0,1,0) transformed by xf
         CALL ETP3 (U, Z, Z, XF, TDVX(1), TDVY(1), TDVZ(1))
         CALL ETP3 (Z, U, Z, XF, TDVX(2), TDVY(2), TDVZ(2))

C     apply identity matrix as modelling transformation
         CALL PSLMT3 (IDM, PCREPL)

C     draw <text 3> chstr:
C        position: xmid,ymid,zmid
C        TDV: tdv1,tdv2
         CALL PTX3 (XMID, YMID, ZMID, TDVX, TDVY, TDVZ, CHRABC)

C     if (ix = ngsq) rotz = rotz + 15 degrees
         IF (IX .EQ. NGSQ) THEN
            ROTZ = ROTZ + 15. * PI/180.
         ENDIF

C   build transformation matrix  xf for rotx,roty,rotz,
C          centered at xmid,ymid,0
C          then shift by 0.5 in z-direction

         CALL EBLTM3 (XMID, YMID, Z, Z, Z, H,
     1                ROTX, ROTY, ROTZ, U, U, U, XF)
C   apply xf as modelling transformation
         CALL PSLMT3 (XF, PCREPL)

C   set up TDVs
         TDVX(1) = U
         TDVY(1) = Z
         TDVZ(1) = Z
         TDVX(2) = Z
         TDVY(2) = U
         TDVZ(2) = Z

C  draw text:   if (ix <= 3) then draw <text 3> chstr:
C     position: xmid, ymid, 0; TDV: (1, 0, 0), (0, 1, 0)
C     else draw <text> chstr: position: xmid, ymid
         IF (IX .LE. 3) THEN
            CALL PTX3 (XMID,YMID, Z, TDVX, TDVY, TDVZ, CHRABC)
         ELSE
            CALL PTX (XMID, YMID, CHRABC)
         ENDIF
310   CONTINUE

      CALL SETMSG ('9 10', 'A displayed text primitive should be '  //
     1             'rotated around the text position as specified ' //
     2             'by the first and second text direction vectors.')

      CALL DCHPFV ('TEXT DIRECTION VECTORS: Which box contains ' //
     1             'overlapping text?', 6, NGSQ)

      CALL PEMST (103)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
