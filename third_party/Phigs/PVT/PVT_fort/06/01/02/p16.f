C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/16                           *
C  *    TEST TITLE : Modelling clipping for polyline and   *
C  *                 polymarker                            *
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

      INTEGER    PICSTR, TXCI, IX,IY, THISWN, NGWIN, RNDINT, THISLN
      INTEGER    NSIZ, EXPNUM, PTID, DELTA, IDEL, NUMLIN, NGLINE
      INTEGER    MKTYPE, NUMVIS
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4

      REAL       XA(40),YA(40),ZA(40), H,U,Z, YINCR,YTOP,YLOC, XLOC
      REAL       PRIMX(40),PRIMY(40),PRIMZ(40), XWINLO(6),YWINLO(6)
      REAL       NOMMS, MSCF, XF(4,4), PI, MCV3(6,10)
      REAL       DCO(10), ANG, XSIZ,YSIZ, UPOS,UNEG,UPARM, BRAD, XINCR
      REAL       RNDRL, PDIFX,PDIFY,PDIFZ, EXPVX(20),EXPVY(20),EXPVZ(20)
      REAL       RDUM1,RDUM2
      PARAMETER (PI=3.14159265)
      PARAMETER (H=0.5, U=1.0, Z=0.0)

      CALL INITGL ('06.01.02/16')

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
C  adjust polymarker size
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS, RDUM1,
     1            RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
      MSCF = .012 / (NOMMS*WCPDC)
      CALL PSMKSC (MSCF)

C  set marker type = circle
      CALL PSMK (POMARK)
 
      CALL PEXST (102)
      CALL PCLST

C  Set up 6 windows on the screen
      CALL WIN6 (106, 2, XSIZ, YSIZ, XWINLO, YWINLO)

      CALL POPST (102)
      CALL PEXST (106)

C  throughout, represent a line segment as a point P and vector V,
C    where endpoints = P and P+V

C                                              
C  *** *** *** ***   polyline   *** *** *** ***
C  
      CALL SETMSG ('40 41 42 43 53 57 58', 'Exactly those parts of ' //
     1             'a polyline that lie outside the current '        //
     2             'modelling clipping volume should be clipped.')

C  ngwin = incorrectly drawn window = random from 1 to 6
      NGWIN = RNDINT(1,6)

C  for thiswn = 1 to 6
      DO 100 THISWN = 1,6

C  xf = modelling transformation to map unit square (0-1) into
C    window #thiswn (with z-dimension unaltered)
         CALL EBLTM3 (Z,Z,Z, XWINLO(THISWN),YWINLO(THISWN),Z,
     2                Z,Z,Z, XSIZ,XSIZ,U, XF)
         CALL PSLMT3 (XF, PCREPL)
         CALL PSMCLI (PCLIP)

C  expected number of vertices
         EXPNUM = 0

         IF (THISWN.EQ.1 .OR. THISWN.EQ.4) THEN
C  *** *** ***  multi line segment, several ends clipped:

C  this creates a wedge shaped MCV, pointed away from the viewer,
C  somewhat like looking into a slightly opened vertical book

C  points on clipping planes = (0.5, 0.5, 0), (0.5, 0.5, 0)
C    vec(1) = attitude of plane #1 =  5,0,2
C    vec(2) = attitude of plane #2 = -5,0,2
            CALL SETRVS ('0.5,0.5,0, 5,0,2, 0.5,0.5,0, -5,0,2',
     1                   MCV3, NSIZ)
            CALL PSMCV3 (PMCREP, 2, MCV3)

C  4th co-efficient for planes
            DCO(1) = - (MCV3(1,1) * MCV3(4,1) + 
     1                  MCV3(2,1) * MCV3(5,1) + 
     2                  MCV3(3,1) * MCV3(6,1))

            DCO(2) = - (MCV3(1,2) * MCV3(4,2) + 
     1                  MCV3(2,2) * MCV3(5,2) +
     2                  MCV3(3,2) * MCV3(6,2))

C  generate zig-zag polyline to be clipped

            DO 110 IX = 1,6
C  next point
               PRIMX(IX) = 0.9 * MOD(IX,2) + 0.05
               PRIMY(IX) = IX/7.0
               PRIMZ(IX) = RNDRL (0.1, 0.9)
               IF (IX.LE.1) GOTO 110
C  vector from previous point
               PDIFX = PRIMX(IX) - PRIMX(IX-1)
               PDIFY = PRIMY(IX) - PRIMY(IX-1)
               PDIFZ = PRIMZ(IX) - PRIMZ(IX-1)
C  intersection of this line segment and clipping planes in MC
               EXPNUM = EXPNUM+1
               CALL LNPLPT (PRIMX(IX),PRIMY(IX),PRIMZ(IX), 
     1                      PDIFX,PDIFY,PDIFZ,
     1                      MCV3(4,1),MCV3(5,1),MCV3(6,1),DCO(1),
     2                      EXPVX(EXPNUM),EXPVY(EXPNUM),EXPVZ(EXPNUM))
               EXPNUM = EXPNUM+1
               CALL LNPLPT (PRIMX(IX),PRIMY(IX),PRIMZ(IX), 
     1                      PDIFX,PDIFY,PDIFZ,
     1                      MCV3(4,2),MCV3(5,2),MCV3(6,2),DCO(2),
     2                      EXPVX(EXPNUM),EXPVY(EXPNUM),EXPVZ(EXPNUM))

C  next ix
110         CONTINUE

C  draw clipped polyline 
            CALL PPL3 (6, PRIMX,PRIMY,PRIMZ)

         ELSEIF (THISWN.EQ.2 .OR. THISWN.EQ.5) THEN
C  *** *** ***  use six clipping planes:

C  xf = modelling transformation to map double-unit cube (-1 to 1)
C       into window #thiswn (in z-dimension map -1 to 1 into 0 to 1)
       
            CALL EBLTM3 (-U,-U,-U, U+XWINLO(THISWN),U+YWINLO(THISWN),U,
     1                   Z,Z,Z, XSIZ/2,XSIZ/2,H, XF)
            CALL PSLMT3 (XF, PCREPL)

C  set up planes surrounding the origin, clipping away from the origin:
            DO 120 IX = 1,6
               ANG = (2*PI*IX) / 6.0
               MCV3(1,IX) = 0.7 * SIN(ANG)
               MCV3(2,IX) = 0.7 * COS(ANG)
               MCV3(3,IX) = 0
               MCV3(4,IX) = -MCV3(1,IX)
               MCV3(5,IX) = -MCV3(2,IX)
C  wobble here - planes not parallel to z-axis
               MCV3(6,IX) = RNDRL(-0.5, 0.5)

C  4th coefficient for plane #ix
               DCO(IX) = - (MCV3(1,IX) * MCV3(4,IX) + 
     1                      MCV3(2,IX) * MCV3(5,IX) + 
     2                      MCV3(3,IX) * MCV3(6,IX))

C  next ix
120         CONTINUE
            CALL PSMCV3 (PMCREP, 6, MCV3)

C  draw 8 line segments through the origin:
            DO 130 IX = 1,4

               ANG = IX * PI / 4
               PRIMX(1) = 2 * SIN(ANG)
               PRIMY(1) = 2 * COS(ANG)
               PRIMZ(1) = RNDRL(-1.0, 1.0)
               PRIMX(2) = -PRIMX(1)
               PRIMY(2) = -PRIMY(1)
               PRIMZ(2) = -PRIMZ(1)
               CALL PPL3 (2, PRIMX,PRIMY,PRIMZ)

C  calculate clipped points as those closest to the origin:
               UPOS =  1000
               UNEG = -1000
               DO 140 IY = 1,6
                  UPARM = -DCO(IY) / (MCV3(4,IY)*PRIMX(1) +
     1                                MCV3(5,IY)*PRIMY(1) +
     2                                MCV3(6,IY)*PRIMZ(1) )
                  IF (UPARM .GT. 0) THEN
                     UPOS = MIN(UPOS,UPARM)
                  ELSE
                     UNEG = MAX(UNEG,UPARM)
                  ENDIF
140            CONTINUE
               EXPNUM = EXPNUM+1
               EXPVX(EXPNUM) = UPOS*PRIMX(1)
               EXPVY(EXPNUM) = UPOS*PRIMY(1)
               EXPVZ(EXPNUM) = UPOS*PRIMZ(1)
            
               EXPNUM = EXPNUM+1
               EXPVX(EXPNUM) = UNEG*PRIMX(1)
               EXPVY(EXPNUM) = UNEG*PRIMY(1)
               EXPVZ(EXPNUM) = UNEG*PRIMZ(1)

C  next ix
130         CONTINUE

         ELSE

C  elseif (thiswn = 3 or 6) then
C  *** *** ***  clip away entire 2D line segments:

C  point, vector for clipping plane: ( 0.6, 0.5, 0), (-3.0,-1.0, 5.0)
            CALL SETRVS ('0.6,0.5,0, -3.0,-1.0,5.0', MCV3, NSIZ)
            CALL PSMCV3 (PMCREP, 1, MCV3)

C  build spiral 2D polyline:
            PTID = 1
            PRIMX(PTID) = 0.5
            PRIMY(PTID) = 0.5
            DELTA = 1

            DO 150 IX = 1,5
               PTID = PTID+1
               PRIMX(PTID) = PRIMX(PTID-1) + DELTA*0.15
               PRIMY(PTID) = PRIMY(PTID-1)

C  horizontal segment crosses clipping plane:
               EXPNUM = EXPNUM+1
               EXPVX(EXPNUM) = MIN(PRIMX(PTID), PRIMX(PTID-1))
               EXPVY(EXPNUM) = PRIMY(PTID)
               EXPVZ(EXPNUM) = 0

               EXPNUM = EXPNUM+1
               EXPVX(EXPNUM) = (2.3-PRIMY(PTID)) / 3
               EXPVY(EXPNUM) = PRIMY(PTID)
               EXPVZ(EXPNUM) = 0

               PTID = PTID+1
               PRIMX(PTID) = PRIMX(PTID-1)
               PRIMY(PTID) = PRIMY(PTID-1) + DELTA*0.15

               IF (DELTA .GT. 0) THEN
                  DELTA = DELTA+1
               ELSE
                  DELTA = DELTA-1
               ENDIF
               DELTA = -DELTA

C  next ix
150         CONTINUE

C  draw polyline using prim(1 to ptid)
            CALL PPL (PTID, PRIMX,PRIMY)

         ENDIF

C  *** *** ***  common post-processing   *** *** ***

         IF (THISWN .EQ. NGWIN) THEN
C  omit at random one expected vertex:
            IDEL = RNDINT(1,EXPNUM)
            EXPVX(IDEL) = EXPVX(EXPNUM)
            EXPVY(IDEL) = EXPVY(EXPNUM)
            EXPVZ(IDEL) = EXPVZ(EXPNUM)
            EXPNUM = EXPNUM-1
         ENDIF

C  draw expected vertices
         DO 190 IX = 1,EXPNUM
C  expv(ix) as transformed by xf
            CALL ETP3 (EXPVX(IX),EXPVY(IX),EXPVZ(IX), XF, 
     1                    XA(IX),   YA(IX),   ZA(IX))
190      CONTINUE
         CALL PSMCLI (PNCLIP)

C  set modelling transformation to identity 
C  draw 2D circle polymarker for pmloc
         CALL IDMAT (4, XF)
         CALL PSLMT3 (XF, PCREPL)
         CALL PPM3 (EXPNUM, XA,YA,ZA)

C  next thiswn
100   CONTINUE

      CALL DCHPFV ('MODELLING CLIPPING OF POLYLINE: In which window ' //
     1             'is there NOT exactly one enclosing circle '       //
     2             'marker for each polyline vertex?', 6, NGWIN)

      CALL PEMST (102)

C  *** *** *** ***   polymarker   *** *** *** ***
C  
      CALL SETMSG ('40 41 42 43 53 57 58 59', 'If the location of a ' //
     1             'marker lies outside the current modelling '       //
     2             'clipping volume, the entire marker should be '    //
     3             'clipped; if inside it should be unclipped or '    //
     4             'partially clipped.')

C  set marker size = 0.03 in WC
C  set line width = minimum available
      CALL PSMKSC (0.03 / (NOMMS*WCPDC))
      CALL PSLWSC (0.0)

C  numlin = number of lines to display 
      NUMLIN = 8
C  ngline = incorrectly drawn line 
      NGLINE = RNDINT(1, NUMLIN) 
C  yincr = space between lines 
      YINCR = 1.0 / (NUMLIN+1)

      YTOP = 1 - YINCR
      YLOC = YTOP                                              
      CALL SETRVS ('0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9', XA, NSIZ)
      CALL NUMLAB (NUMLIN, 0.1, YTOP, YINCR)
      BRAD = 0.035/2
      DO 200 THISLN = 1,NUMLIN
         CALL PSMCLI (PCLIP)
         MKTYPE = MOD(THISLN, 5) + 1
         CALL PSMK (MKTYPE)
C  number visible markers 
         NUMVIS = RNDINT(1,8)

C  put clipping plane just to the right of marker #numvis or
C  just to the left of marker #numvis+1:
         XINCR = MOD(THISLN,2) * 0.098
C  set MCV = point: (numvis/10.0 + 0.101 + xincr, 0, 0); vector: (-1,0,0)
         CALL SETRVS ('0,0,0, -1,0,0', MCV3, NSIZ)
         MCV3(1,1) = NUMVIS/10.0 + 0.101 + XINCR
         CALL PSMCV3 (PMCREP, 1, MCV3)
         DO 210 IX = 1,8
            YA(IX) = YLOC
            ZA(IX) = RNDRL(0.01, 0.99)
210      CONTINUE
         CALL PPM3 (8, XA,YA,ZA)

         CALL PSMCLI (PNCLIP)
         IF (THISLN .EQ. NGLINE) NUMVIS = NUMVIS-1
         XLOC = 0.2
         DO 220 IX = 1,NUMVIS
C  draw square, using polyline, size = 0.035 in WC, centered at xloc, yloc
            CALL DRWREC (XLOC-BRAD, XLOC+BRAD, YLOC-BRAD, YLOC+BRAD)
            XLOC = XLOC + 0.1
220      CONTINUE
         YLOC = YLOC-YINCR

C  next thisln
200   CONTINUE

      CALL DCHPFV ('MODELLING CLIPPING OF POLYMARKER: On which line ' //
     1             'is there NOT exactly one enclosing box for each ' //
     2             'marker?', 8, NGLINE)

      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
