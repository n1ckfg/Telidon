C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/18                           *
C  *    TEST TITLE : Modelling clipping for fill area,     *
C  *                 fill area set, and cell array         *
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
C marker type    .         +        *       o         x
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)
C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)
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
C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER    PICSTR, TXCI, IX,JX, COLIA(3,2), HATSTY, NUMSTY, NUMHAT
      INTEGER    RANSTY(6), RANWIN(6), WNDEX,THISWN, INTSTY, NSTYUS
      INTEGER    NGWIN, FASDX(6), NFA, PRIMSW, LOCHAR, VX(30), VXSIZ
      INTEGER    AFASDX(3), ANFA
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4

      REAL       XP(14),YP(14),ZP(14), XT(30),YT(30),ZT(30)
      REAL       XFAS(30),YFAS(30),ZFAS(30), XCA(3),YCA(3),ZCA(3)
      REAL       XEXP(30),YEXP(30), XCO,YCO,ZCO, IDXF(4,4)
      REAL       ACL(3),BCL(3),CCL(3),DCL(3), MCV3(6,2), MCV2(4,2)
      REAL       PQX,PQY,PRX,PRY, ACA,BCA,CCA
      REAL       XWINLO(6),YWINLO(6), XSIZ,YSIZ, U,Z, XF(4,4)
      PARAMETER (U=1.0, Z=0.0)

      CHARACTER  INTLAB(PHOLLO:PHATCH)*8, SETLAB*5, SETPR*5

      DATA  INTLAB / 'hollow.', 'solid.', 'pattern.', 'hatch.' /
      DATA  SETLAB / ' set ' /, SETPR / ' SET:' /
      DATA  COLIA / 1,2,3,2,3,1 /
C  x,y, coordinates of fill area to be clipped
      DATA  XP / 0.6,  0.6,  0.4,  0.4, 0.3, 0.3, 0.9, 0.9, 0.1, 0.1,
     1           0.7,  0.7,  0.1,  0.1 /
      DATA  YP / 0.15, 0.7,  0.7,  0.0, 0.0, 0.9, 0.9, 0.3, 0.3, 0.8,
     1           0.8,  0.15, 0.15, 0.3 /

      CALL INITGL ('06.01.02/18')

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
      CALL PSICI  (1)
      CALL PSPLCI (3)
      CALL PSLN   (PLDASD)
      CALL PEXST (102)
      CALL PCLST

C  how many hatch and interior styles?
      CALL PQIF (SPECWT, 0,0, ERRIND, NUMSTY,IDUM1, NUMHAT,IDUM2, IDUM3)
      CALL CHKINQ ('pqif', ERRIND)

C  hatsty = available hatch style
      IF (NUMHAT .GT. 0) THEN
         CALL DENHAT (102, 10, SPECWT, HATSTY)
      ENDIF

C  list of interior styles, drawn from hollow,solid,hatch,pattern,
C  as available.
      NSTYUS = 0
      DO 100 IX = 1,NUMSTY
         CALL PQIF (SPECWT, IX,0, ERRIND, IDUM1,INTSTY,
     1              IDUM2,IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (INTSTY.GE.PHOLLO .AND. INTSTY.LE.PHATCH) THEN
            NSTYUS = NSTYUS+1
            RANSTY(NSTYUS) = INTSTY
         ENDIF
100   CONTINUE

C  set up identity matrix
      CALL IDMAT (4, IDXF)

C  Set up 6 windows on the screen
      CALL WIN6 (106, 2, XSIZ, YSIZ, XWINLO, YWINLO)

      CALL POPST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  the two 2D clipping planes are:
C     -0.45x + y - 0.07 = 0
C     -0.8x  - y + 1.1  = 0

C  clipping plane co-efficients (MC)
      ACL(1) = -0.45
      BCL(1) = 1.0
      CCL(1) = Z
      DCL(1) = -0.07

      ACL(2) = -0.8
      BCL(2) = -1.0
      CCL(2) = Z
      DCL(2) = 1.1

C  coefficients for line connecting first/last vertex:
      CALL PT2COF (XP(1),YP(1), XP(14),YP(14), ACL(3),BCL(3),DCL(3))

C  2D MCV format for the two clipping planes (MC):
      DO 190 JX = 1,2
         MCV2(1,JX) = -DCL(JX)/ACL(JX)
         MCV2(2,JX) = Z
         MCV2(3,JX) = ACL(JX)
         MCV2(4,JX) = BCL(JX)
190   CONTINUE

C  expected vertices for fill area and fill area set:
      CALL SETVS ('5,10,14,17,23,26', FASDX, NFA)
C  sub-area #1
      XEXP(1) = XP(13)
      XEXP(2) = XP(14)
      YEXP(1) = YP(13)
      YEXP(2) = YP(14)
      CALL LINTPT (ACL(3),BCL(3),DCL(3), U,Z,-XP(5),  XEXP(3),YEXP(3))
      CALL LINTPT (ACL(1),BCL(1),DCL(1), U,Z,-XP(5),  XEXP(4),YEXP(4))
      CALL LINTPT (ACL(1),BCL(1),DCL(1), Z,U,-YP(13), XEXP(5),YEXP(5))

C  sub-area #2
      XEXP(6) = XEXP(3)
      YEXP(6) = YEXP(3)
      XEXP(7) = XP(5)
      YEXP(7) = YP(8)
      XEXP(8) = XP(4)
      YEXP(8) = YP(8)
      CALL LINTPT (ACL(1),BCL(1),DCL(1), U,Z,-XP(4),  XEXP(9),YEXP(9))
      CALL LINTPT (ACL(1),BCL(1),DCL(1), ACL(3),BCL(3),DCL(3),
     1             XEXP(10),YEXP(10))

C  sub-area #3
      XEXP(11) = XP(9)
      YEXP(11) = YP(9)
      XEXP(12) = XP(10)
      YEXP(12) = YP(10)
      XEXP(13) = XP(5)
      YEXP(13) = YP(10)
      XEXP(14) = XP(5)
      YEXP(14) = YP(9)

C  sub-area #4
      XEXP(15) = XP(5)
      YEXP(15) = YP(10)
      CALL LINTPT (ACL(2),BCL(2),DCL(2), U,Z,-XP(5),  XEXP(16),YEXP(16))
      CALL LINTPT (ACL(2),BCL(2),DCL(2), Z,U,-YP(10), XEXP(17),YEXP(17))

C  sub-area #5
      XEXP(18) = XP(4)
      YEXP(18) = YP(8)
      XEXP(19) = XP(4)
      YEXP(19) = YP(3)
      CALL LINTPT (ACL(2),BCL(2),DCL(2), Z,U,-YP(3), XEXP(20),YEXP(20))
      CALL LINTPT (ACL(2),BCL(2),DCL(2), U,Z,-XP(1), XEXP(21),YEXP(21))
      CALL LINTPT (ACL(1),BCL(1),DCL(1), U,Z,-XP(1), XEXP(22),YEXP(22))
      CALL LINTPT (ACL(1),BCL(1),DCL(1), Z,U,-YP(8), XEXP(23),YEXP(23))

C  sub-area #6
      CALL LINTPT (ACL(1),BCL(1),DCL(1), U,Z,-XP(11), XEXP(24),YEXP(24))
      CALL LINTPT (ACL(2),BCL(2),DCL(2), U,Z,-XP(11), XEXP(25),YEXP(25))
      CALL LINTPT (ACL(1),BCL(1),DCL(1), ACL(2),BCL(2),DCL(2),
     1             XEXP(26),YEXP(26))

C  actual vertices for fill area set
      CALL SETVS ('6,16,24', AFASDX, ANFA)

C  set most of the fill area set vertices directly to
C  fill area vertices

      CALL SETVS ('4,5,5,14,13,12,1,8,8,7,6,6,10,9,9,5,' //
     1            '11,12,3,3,2,8,5,5', VX, VXSIZ)
      DO 160 IX = 1,VXSIZ
         XFAS(IX) = XP(VX(IX))
         YFAS(IX) = YP(VX(IX))
160   CONTINUE

C  adjust sub-area #1
      CALL LINTPT (ACL(3),BCL(3),DCL(3), U,Z,-XP(5), XFAS(3),YFAS(3))
      XFAS(6) = XP(4)

C  adjust sub-area #2
      XFAS(8)  = XP(1)
      YFAS(12) = YP(10)
      XFAS(15) = XP(5)
      YFAS(16) = YFAS(3)

C  adjust sub-area #3
      YFAS(19) = YP(12)
      XFAS(22) = XP(2)
      YFAS(23) = YP(8)
      YFAS(24) = YP(10)

C *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
C  loop thru:
C    1. fill area / fill area set
C    2. interior styles
C    3. 6 windows

      DO 150 PRIMSW = 1,2
         LOCHAR = 9 - 4*PRIMSW
C  cycle thru non-empty interior styles
      DO 200 IX = 1,NSTYUS

         INTSTY = RANSTY(IX)
         CALL PSIS (INTSTY)
         CALL PSEDFG (POFF)

         IF (INTSTY .EQ. PHOLLO) THEN
            CALL SETMSG ('40 41 42 43 53 57 58 63', 'When the '     //
     1                   'interior style is hollow, exactly those ' //
     2                   'parts of a fill area' // SETLAB(LOCHAR:)  //
     3                   'that lie outside the current modelling '  //
     4                   'clipping volume should be clipped, and '  //
     5                   'the new boundaries formed by clipping '   //
     6                   'should be drawn.')
         ELSE
            CALL SETMSG ('40 41 42 43 53 57 58', 'Exactly those '   //
     1                   'parts of a fill area' // SETLAB(LOCHAR:)  //
     2                   'that lie outside the current modelling '  //
     3                   'clipping volume should be clipped when '  //
     4                   'the interior style is ' // INTLAB(INTSTY))

            IF (INTSTY .EQ. PPATTR) THEN
C  set pattern rep #1 to simple small checkerboard
               CALL PSPAR (WKID, 1, 3,2, 1,1, 3,2, COLIA)
               CALL PSPA  (.03,.03)
               CALL PSISI (1)
            ELSEIF (INTSTY .EQ. PHATCH) THEN
               CALL PSISI (HATSTY)
            ENDIF
         ENDIF

C  ranwin = permuted list of 1-6
         CALL RNPERM (6, RANWIN)
         CALL PSMCLI (PCLIP)

         DO 210 WNDEX = 1,6
C  xf = modelling transformation to map unit square (0-1) into
C    window #WNDEX (with z-dimension unaltered)
            CALL EBLTM3 (Z,Z,Z, XWINLO(WNDEX),YWINLO(WNDEX),Z,
     1                   Z,Z,Z, XSIZ,XSIZ,U, XF)

            CALL FACLIP (ACL,BCL,CCL,DCL, XCO,YCO,ZCO, MCV3)

C  transform clipping plane to WC:
            CALL PSLMT3 (XF, PCREPL)

            THISWN = RANWIN(WNDEX)

C  no clipping planes in effect
            CALL PSMCV (PMCREP, 0, MCV2)
            IF (THISWN .EQ. 1) THEN
C  set up 2D clipping planes using replace
               CALL PSMCV (PMCREP, 2, MCV2)
            ELSEIF (THISWN .EQ. 2) THEN
C  set up 2D clipping planes using intersect
               CALL PSMCV (PMCINT, 1, MCV2(1,2))
               CALL PSMCV (PMCINT, 1, MCV2(1,1))
            ELSEIF (THISWN .EQ. 3) THEN
C  set up 3D clipping planes using replace
               CALL PSMCV3 (PMCREP, 2, MCV3)
            ELSEIF (THISWN .EQ. 4) THEN
C  set up 3D clipping planes using intersect
               CALL PSMCV3 (PMCINT, 1, MCV3(1,2))
               CALL PSMCV3 (PMCINT, 1, MCV3(1,1))
            ELSEIF (THISWN .EQ. 5) THEN
C  simulate complex self-intersecting fill area, properly clipped
               CALL PFAS (NFA, FASDX, XEXP,YEXP)
               GOTO 210
            ELSE
C  simulate complex self-intersecting fill area, improperly clipped
               CALL PFAS (NFA-1, FASDX, XEXP,YEXP)
               NGWIN = WNDEX
               GOTO 210
            ENDIF

C  render primitive using different transformation
            CALL PSLMT3 (IDXF, PCREPL)
            IF (PRIMSW .EQ. 1) THEN
C  compute z-values for fill area
               DO 220 JX = 1,14
                  ZP(JX) = XCO*XP(JX) + YCO*YP(JX) + ZCO
220            CONTINUE
C  transform fill area "by hand" to WC:
               CALL ARRTP3 (14, XP,YP,ZP, XF, XT,YT,ZT)
C  draw complex self-intersecting 3D fill area
               CALL PFA3 (14, XT,YT,ZT)
            ELSE
C  compute z-values for fill area set
               DO 225 JX = 1,24
                  ZFAS(JX) = XCO*XFAS(JX) + YCO*YFAS(JX) + ZCO
225            CONTINUE
C  transform fill area set "by hand" to WC:
               CALL ARRTP3 (24, XFAS,YFAS,ZFAS, XF, XT,YT,ZT)
C  draw complex self-intersecting 3D fill area set
               CALL PFAS3 (ANFA, AFASDX, XT,YT,ZT)
            ENDIF

C  next wndex
210      CONTINUE

         CALL DCHPFV ('MODELLING CLIPPING OF FILL AREA'    //
     1                SETPR(LOCHAR:) // ' Which fill area' //
     2                SETLAB(LOCHAR:) // 'is different?', 6, NGWIN)
         CALL PEMST (102)

C  next interior style
200   CONTINUE
C  next primitive
150   CONTINUE

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

      CALL SETMSG ('40 41 42 43 53 57 58 64', 'When a fill area set ' //
     1             'with a visible edge is clipped, the new '         //
     2             'boundary formed by the clipping should not be '   //
     3             'indicated by the edge.')

      CALL PSIS   (PISEMP)
      CALL PSEDFG (PON)

      CALL PSEDT  (PLDASD)
      CALL PSLN   (PLDASD)
      CALL PSEWSC (1.0)
      CALL PSLWSC (1.0)
      CALL PSEDCI (1)
      CALL PSPLCI (1)

C  ranwin = permuted list of 1-6
      CALL RNPERM (6, RANWIN)
      CALL PSMCLI (PCLIP)

      DO 310 WNDEX = 1,6
C  xf = modelling transformation to map unit square (0-1) into
C    window #WNDEX (with z-dimension unaltered)
         CALL EBLTM3 (Z,Z,Z, XWINLO(WNDEX),YWINLO(WNDEX),Z,
     1                Z,Z,Z, XSIZ,XSIZ,U, XF)

         CALL FACLIP (ACL,BCL,CCL,DCL, XCO,YCO,ZCO, MCV3)

C  transform clipping plane to WC:
         CALL PSLMT3 (XF, PCREPL)

         THISWN = RANWIN(WNDEX)

C  no clipping planes in effect
         CALL PSMCV (PMCREP, 0, MCV2)
         IF (THISWN .EQ. 1) THEN
C  set up 2D clipping planes using replace
            CALL PSMCV (PMCREP, 2, MCV2)
         ELSEIF (THISWN .EQ. 2) THEN
C  set up 2D clipping planes using intersect
            CALL PSMCV (PMCINT, 1, MCV2(1,2))
            CALL PSMCV (PMCINT, 1, MCV2(1,1))
         ELSEIF (THISWN .EQ. 3) THEN
C  set up 3D clipping planes using replace
            CALL PSMCV3 (PMCREP, 2, MCV3)
         ELSEIF (THISWN .EQ. 4) THEN
C  set up 3D clipping planes using intersect
            CALL PSMCV3 (PMCINT, 1, MCV3(1,2))
            CALL PSMCV3 (PMCINT, 1, MCV3(1,1))
         ELSEIF (THISWN .EQ. 5) THEN

C  draw expected edge vertices:
            CALL EXEDV ('5,1,2,3,4',          XEXP,YEXP)
            CALL EXEDV ('10,6,7,11,12,15,16', XEXP,YEXP)
            CALL EXEDV ('21,22',              XEXP,YEXP)
            CALL EXEDV ('24,25',              XEXP,YEXP)
            CALL EXEDV ('9,19,20',            XEXP,YEXP)
            CALL EXEDV ('23,14,13,17',        XEXP,YEXP)

            GOTO 310
         ELSE

C  draw incorrect edge vertices:
            CALL EXEDV ('5,1,2,3,4',          XEXP,YEXP)
            CALL EXEDV ('10,6,7,11,12,15,16', XEXP,YEXP)
C  this one is wrong:
            CALL EXEDV ('21,22,24,25,21',     XEXP,YEXP)
            CALL EXEDV ('9,19,20',            XEXP,YEXP)
            CALL EXEDV ('23,14,13,17',        XEXP,YEXP)

            NGWIN = WNDEX
            GOTO 310
         ENDIF

C  render primitive using different transformation
         CALL PSLMT3 (IDXF, PCREPL)
C  compute z-values for fill area set
         DO 325 JX = 1,24
            ZFAS(JX) = XCO*XFAS(JX) + YCO*YFAS(JX) + ZCO
325      CONTINUE
C  transform fill area set "by hand" to WC:
         CALL ARRTP3 (24, XFAS,YFAS,ZFAS, XF, XT,YT,ZT)
C  draw complex self-intersecting 3D fill area set
         CALL PFAS3 (ANFA, AFASDX, XT,YT,ZT)

C  next wndex
310   CONTINUE

      CALL DCHPFV ('MODELLING CLIPPING OF EDGED FILL AREA SET: ' //
     1             'Which clipped fill area set has different '  //
     2             'edges?', 6, NGWIN)

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
C
      CALL SETMSG ('40 41 42 43 53 57 58', 'Exactly those parts of ' //
     1             'a cell array that lie outside the current '      //
     2             'modelling clipping volume should be clipped.')

      CALL PSIS   (PSOLID)
      CALL PSEDFG (POFF)

C  cell array x-y coordinates
      CALL SETRVS ('0.1, 0.4, 0.5', XCA, IX)
      CALL SETRVS ('0.3, 0.9, 0.2', YCA, IX)

C  compute cell vectors
      PQX = (XCA(2) - XCA(1)) / 3
      PQY = (YCA(2) - YCA(1)) / 3

      PRX = (XCA(3) - XCA(1)) / 2
      PRY = (YCA(3) - YCA(1)) / 2

C  compute clipped cell vertices
C  cell #1, color #1
      XEXP(1) = XCA(1)
      XEXP(2) = XCA(1) + PQX
      XEXP(3) = XCA(1) + PQX + PRX
      XEXP(4) = XCA(1) + PRX

      YEXP(1) = YCA(1)
      YEXP(2) = YCA(1) + PQY
      YEXP(3) = YCA(1) + PQY + PRY
      YEXP(4) = YCA(1) + PRY

C  cell #2, color #1
      XEXP(5) = XCA(1) + 2*PQX + PRX
      YEXP(5) = YCA(1) + 2*PQY + PRY

      CALL PARCOF (XEXP(5),YEXP(5), PQX,PQY, ACA,BCA,CCA)
      CALL LINTPT (ACL(2),BCL(2),DCL(2), ACA,BCA,CCA, XEXP(6),YEXP(6))
      CALL PARCOF (XEXP(5),YEXP(5), PRX,PRY, ACA,BCA,CCA)
      CALL LINTPT (ACL(2),BCL(2),DCL(2), ACA,BCA,CCA, XEXP(7),YEXP(7))

C  cell #3, color #2
      XEXP(8)  = XCA(1) +   PQX
      XEXP(9)  = XCA(1) + 2*PQX
      XEXP(10) = XCA(1) + 2*PQX + PRX
      XEXP(11) = XCA(1) +   PQX + PRX

      YEXP(8)  = YCA(1) +   PQY
      YEXP(9)  = YCA(1) + 2*PQY
      YEXP(10) = YCA(1) + 2*PQY + PRY
      YEXP(11) = YCA(1) +   PQY + PRY

C  cell #4, color #2
      XEXP(12) = XCA(1)       +   PRX
      XEXP(13) = XCA(1) + PQX +   PRX
      XEXP(14) = XCA(1) + PQX + 2*PRX

      YEXP(12) = YCA(1)       +   PRY
      YEXP(13) = YCA(1) + PQY +   PRY
      YEXP(14) = YCA(1) + PQY + 2*PRY

      CALL PARCOF (XEXP(14),YEXP(14), PQX,PQY, ACA,BCA,CCA)
      CALL LINTPT (ACL(1),BCL(1),DCL(1), ACA,BCA,CCA, XEXP(15),YEXP(15))
      CALL PARCOF (XEXP(12),YEXP(12), PRX,PRY, ACA,BCA,CCA)
      CALL LINTPT (ACL(1),BCL(1),DCL(1), ACA,BCA,CCA, XEXP(16),YEXP(16))

C  cell #5, color #3
      XEXP(17) = XEXP(3)
      XEXP(18) = XEXP(5)
      XEXP(19) = XEXP(7)
      XEXP(21) = XEXP(14)

      YEXP(17) = YEXP(3)
      YEXP(18) = YEXP(5)
      YEXP(19) = YEXP(7)
      YEXP(21) = YEXP(14)

      CALL PARCOF (XEXP(21),YEXP(21), PQX,PQY, ACA,BCA,CCA)
      CALL LINTPT (ACL(2),BCL(2),DCL(2), ACA,BCA,CCA, XEXP(20),YEXP(20))

C  cell #6, color #3
      XEXP(22) = XEXP(9)
      XEXP(24) = XEXP(6)
      XEXP(25) = XEXP(5)

      YEXP(22) = YEXP(9)
      YEXP(24) = YEXP(6)
      YEXP(25) = YEXP(5)

      CALL PARCOF (XEXP(22),YEXP(22), PQX,PQY, ACA,BCA,CCA)
      CALL LINTPT (ACL(2),BCL(2),DCL(2), ACA,BCA,CCA, XEXP(23),YEXP(23))

C  ranwin = permuted list of 1-6
      CALL RNPERM (6, RANWIN)
      CALL PSMCLI (PCLIP)

      DO 410 WNDEX = 1,6
C  xf = modelling transformation to map unit square (0-1) into
C    window #WNDEX (with z-dimension unaltered)
         CALL EBLTM3 (Z,Z,Z, XWINLO(WNDEX),YWINLO(WNDEX),Z,
     1                Z,Z,Z, XSIZ,XSIZ,U, XF)

         CALL FACLIP (ACL,BCL,CCL,DCL, XCO,YCO,ZCO, MCV3)

C  transform clipping plane to WC:
         CALL PSLMT3 (XF, PCREPL)

         THISWN = RANWIN(WNDEX)

C  no clipping planes in effect
         CALL PSMCV (PMCREP, 0, MCV2)
         IF (THISWN .EQ. 1) THEN
C  set up 2D clipping planes using replace
            CALL PSMCV (PMCREP, 2, MCV2)
         ELSEIF (THISWN .EQ. 2) THEN
C  set up 2D clipping planes using intersect
            CALL PSMCV (PMCINT, 1, MCV2(1,2))
            CALL PSMCV (PMCINT, 1, MCV2(1,1))
         ELSEIF (THISWN .EQ. 3) THEN
C  set up 3D clipping planes using replace
            CALL PSMCV3 (PMCREP, 2, MCV3)
         ELSEIF (THISWN .EQ. 4) THEN
C  set up 3D clipping planes using intersect
            CALL PSMCV3 (PMCINT, 1, MCV3(1,2))
            CALL PSMCV3 (PMCINT, 1, MCV3(1,1))
         ELSEIF (THISWN .EQ. 5) THEN
C  draw expected cells
            CALL PSICI (1)
            CALL SETVS ('4,7', FASDX, NFA)
            CALL PFAS (NFA, FASDX, XEXP(1),YEXP(1))

            CALL PSICI (2)
            CALL SETVS ('4,9', FASDX, NFA)
            CALL PFAS (NFA, FASDX, XEXP(8),YEXP(8))

            CALL PSICI (3)
            CALL SETVS ('5,9', FASDX, NFA)
            CALL PFAS (NFA, FASDX, XEXP(17),YEXP(17))

            GOTO 410
         ELSE
C  draw incorrect cells
            CALL PSICI (1)
            CALL SETVS ('4,7', FASDX, NFA)
            CALL PFAS (NFA, FASDX, XEXP(1),YEXP(1))

            CALL PSICI (2)
            CALL SETVS ('4,8', FASDX, NFA)
            CALL PFAS (NFA, FASDX, XEXP(8),YEXP(8))

            CALL PSICI (3)
            CALL SETVS ('5,9', FASDX, NFA)
            CALL PFAS (NFA, FASDX, XEXP(17),YEXP(17))

            NGWIN = WNDEX
            GOTO 410
         ENDIF

C  render primitive using different transformation
         CALL PSLMT3 (IDXF, PCREPL)
C  compute z-values for fill area set
         DO 425 JX = 1,3
            ZCA(JX) = XCO*XCA(JX) + YCO*YCA(JX) + ZCO
425      CONTINUE
C  transform fill area set "by hand" to WC:
         CALL ARRTP3 (3, XCA,YCA,ZCA, XF, XT,YT,ZT)
C  draw complex self-intersecting 3D fill area set
         CALL PCA3 (XT,YT,ZT, 3,2, 1,1, 3,2, COLIA)

C  next wndex
410   CONTINUE

      CALL DCHPFV ('MODELLING CLIPPING OF CELL ARRAY: Which cell ' //
     1             'array has a different size or shape?', 6, NGWIN)

      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
