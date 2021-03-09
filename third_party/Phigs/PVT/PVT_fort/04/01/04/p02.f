C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.01.04/02                           *
C  *    TEST TITLE : Appearance of annotation text         *
C  *                 primitives                            *
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
 
C line type
      INTEGER    PLSOLI,    PLDASH,     PLDOT,   PLDASD
      PARAMETER (PLSOLI=1,  PLDASH=2,   PLDOT=3, PLDASD=4)
 
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
      INTEGER    PICSTR, TXCI, IX, NGSQ, PERM(10), RNDINT
 
      REAL       XMID,YMID,EXT,XEXT,YEXT,X0,Y0,Z0, XF(4,4), CHHT
      REAL       NPCX, NPCY, NPCPWC, TX(2), TY(2), YBOT,YTOP, NGDELT
      REAL       XREFPT,YREFPT,ZREFPT,XANNPT,YANNPT,ZANNPT, YB,YH,YC
      REAL       XSIZ,YSIZ,XWINLO(6),YWINLO(6), RDUM1, RDUM2
      REAL       RNDRL,SIDER(6,3),IDM(4,4),XFA(4,4),XFB(4,4)
      REAL       Z, H, U, PI
      PARAMETER  (Z=0., H=0.5, U=1.0, PI=3.14159265)
 
      CHARACTER  UPPER*26, CHSTR*5, LOWER*26, REPSTR*10, CHRABC*3
 
      DATA       SIDER/18*Z/
 
      CALL INITGL ('04.01.04/02')
 
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
C  ratio of NPC to WC
      CALL WCNPC (0., 0., NPCX, NPCY, NPCPWC)
 
C  set default attributes:
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSATAL (PACENT, PAHALF)
      CALL PSATP  (PRIGHT)
      CHHT = 0.05
      CALL PSATCH (CHHT * NPCPWC)
      CALL PSANS  (1)
      CALL PSLN   (PLSOLI)
      CALL PSPLCI (3)
 
C  set up 102 as sub-structure
      CALL PEXST (102)
      CALL PCLST
C
C  *** *** *** *** ***  character content  *** *** *** *** ***
C
      CALL SETMSG ('7', 'A displayed annotation text primitive ' //
     1             'should contain the specified character string.')
 
      CALL POPST (102)
 
      CALL PSATCH (0.08 * NPCPWC)
      CALL PSTXFN (2)
      UPPER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
 
C  chstr = string of 5 randomly chosen upper-case letters.
      CALL RNSET (5, 26, PERM)
      DO 100 IX = 1, 5
         CHSTR(IX:IX) = UPPER(PERM(IX):PERM(IX))
100   CONTINUE
 
C  display <annotation text relative 3> consisting of chstr:
C    reference position = 0.5, 0.5, 0.5
C    offset = 0., 0., 0.1
      CALL PATR3 (H,H,H, Z,Z,Z, CHSTR)
 
      CALL DLINE ('CHARACTER CONTENT: Enter the displayed character ' //
     1            'string.', REPSTR)
      IF (REPSTR .NE. CHSTR) THEN
         CALL FAIL
         GOTO 199
      ENDIF
 
      CALL PEMST (102)
      CALL PSTXFN (1)
      CALL PSATCH (0.08 * NPCPWC)
 
C  chstr = string of 5 randomly chosen lower-case letters
      LOWER = 'abcdefghijklmnopqrstuvwxyz'
      CALL RNSET (5, 26, PERM)
      DO 110 IX = 1, 5
         CHSTR(IX:IX) = LOWER(PERM(IX):PERM(IX))
110   CONTINUE
 
C  display <annotation text relative> consisting of chstr:
C     reference point = 0.5, 0.5
C     offset = 0., 0.
      CALL PATR (H,H, Z,Z, CHSTR)
 
      CALL DLINE ('CHARACTER CONTENT: Enter the displayed character ' //
     1            'string.', REPSTR)
      CALL IFPF (REPSTR .EQ. CHSTR)
 
C  end_char:
199   CONTINUE
      CALL PEMST (102)
 
C  *** *** *** ***   effect of reference point   *** *** *** ***
 
      CALL PEXST (106)
      CALL PEXST (103)
      CALL PCLST
 
C  set up rotations for viewing from 6 sides
C  back - Y-axis
      SIDER (2,2) = PI
C  left - Y-axis
      SIDER (3,2) = 0.5*PI
C  right - Y-axis
      SIDER (4,2) = 1.5*PI
C  top - X-axis
      SIDER (5,1) = 0.5*PI
C  bottom - X-axis
      SIDER (6,1) = 1.5*PI
 
C  Divide screen up into 6 squares labelled areas
      CALL WIN6 (106, 2, XSIZ, YSIZ, XWINLO, YWINLO)
 
      CALL POPST (103)
 
      CHRABC = 'ABC'
      CALL IDMAT (4, IDM)
C  amount by which "incorrect" rectangle is to be shifted
      NGDELT = 0.01
 
C  <Inquire text extent> to get extent rectangle for CHRABC
      CALL PQTXX (SPECWT, 1, 1., 0., CHHT, PRIGHT,PACENT,PABASE,
     1            CHRABC, ERRIND, TX, TY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      YB = TY(1)
      CALL PQTXX (SPECWT, 1, 1., 0., CHHT, PRIGHT,PACENT,PAHALF,
     1            CHRABC, ERRIND, TX, TY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      YH = TY(1)
      CALL PQTXX (SPECWT, 1, 1., 0., CHHT, PRIGHT,PACENT,PACAP,
     1            CHRABC, ERRIND, TX, TY, RDUM1, RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      YC = TY(1)
C  horizontal size of string in MC
      XEXT = TX(2)-TX(1)
C  MC distance from baseline to halfline
      YBOT = ABS(YH-YB)
C  MC distance from capline to halfline
      YTOP = ABS(YC-YH)
C  MC vertical distance from baseline to capline
      YEXT = YTOP+YBOT
 
C  select reference point randomly from cube:
C    (ext,1-ext),(ext,1-ext),(ext,1-ext)
C  to make sure that annotation text fits in window
 
C  Distance from center of rectangle to farthest border, divided
C  by XSIZ to cancel effect of modelling transformation, which
C  multiplies by XSIZ.  Thus, when string is located, aligned at
C  its center, it won't overlap border.
      EXT = 0.5 * MAX(XEXT, YEXT) / XSIZ
 
C  which square is no good
      NGSQ = RNDINT (1,6)
 
C  reference point must be at least EXT distant from any side of the
C  unit cube in all dimensions, because modelling transformation will
C  rotate cube, and reference point along with it, but NOT annotation
C  text itself, which is always in NPC-XY plane.  Therefore, it is
C  incorrect (even though plausible) to apply XEXT in X-dimension,
C  and YEXT in Y-dimension, because rotation mixes up dimensions.
      XREFPT = RNDRL (EXT, 1-EXT)
      YREFPT = RNDRL (EXT, 1-EXT)
      ZREFPT = RNDRL (EXT, 1-EXT)
 
      DO 250 IX = 1, 6
         XMID = XWINLO(IX)+XSIZ/2
         YMID = YWINLO(IX)+YSIZ/2
 
C  scale down to fit in square, rotate, and move to square #ix
         CALL EBLTM3 (H, H, H, XMID-H, YMID-H, Z,
     2        SIDER(IX,1),SIDER(IX,2),SIDER(IX,3), XSIZ,XSIZ,XSIZ,XF)
         CALL PSLMT3 (XF, PCREPL)
C  draw the annotation text at transformed reference point
         CALL PATR3 (XREFPT,YREFPT,ZREFPT, Z,Z,Z, CHRABC)
 
         CALL PSLMT3 (IDM, PCREPL)
C  find expected center of rectangle
         CALL ETP3 (XREFPT,YREFPT,ZREFPT, XF, X0,Y0,Z0)
 
         IF (IX .EQ. NGSQ) THEN
C  distort towards middle of square - don't overlap border
            IF (X0 .LT. XMID) THEN
                X0 = X0 + NGDELT
            ELSE
                X0 = X0 - NGDELT
            ENDIF
 
            IF (Y0 .LT. YMID) THEN
                Y0 = Y0 + NGDELT
            ELSE
                Y0 = Y0 - NGDELT
            ENDIF
         ENDIF
 
C  outline the annotation text
         CALL DRWREC (X0-XEXT/2, X0+XEXT/2, Y0-YBOT, Y0+YTOP)
250   CONTINUE
 
      CALL SETMSG ('7 8 9', 'The location of an annotation text ' //
     1             'primitive should reflect its 3D reference '   //
     2             'point after being transformed.')
      CALL DCHPFV ('EFFECT OF REFERENCE POINT: In which box is '  //
     1             'the annotation text NOT accurately outlined ' //
     2             'by the rectangle?', 6, NGSQ)
      CALL PEMST(103)
 
C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
 
C  which square will be marked wrong?
      NGSQ = RNDINT (1,6)
 
C  reference point:
      XREFPT = RNDRL (EXT, 1-EXT)
      YREFPT = RNDRL (EXT, 1-EXT)
      ZREFPT = Z
 
      DO 260 IX = 1,6
         XMID = XWINLO(IX)+XSIZ/2
         YMID = YWINLO(IX)+YSIZ/2
C  first, move from Z=0 plane to somewhere in middle
         CALL ETR3 (Z, Z, RNDRL(EXT,1-EXT), XFA)
C  scale down to fit in square, rotate, and move to square #ix
         CALL EBLTM3 (H,H,H, XMID-H, YMID-H, Z,
     2         SIDER(IX,1),SIDER(IX,2),SIDER(IX,3), XSIZ,XSIZ,XSIZ,XFB)
         CALL ECOM3 (XFB, XFA, XF)
 
         CALL PSLMT3 (XF, PCREPL)
         CALL PATR (XREFPT,YREFPT, Z,Z, CHRABC)
 
         CALL PSLMT3 (IDM, PCREPL)
C  find expected center of rectangle
         CALL ETP3 (XREFPT,YREFPT,ZREFPT, XF, X0,Y0,Z0)
 
         IF (IX .EQ. NGSQ) THEN
C  distort towards middle of square - don't overlap border
            IF (X0 .LT. XMID) THEN
                X0 = X0 + NGDELT
            ELSE
                X0 = X0 - NGDELT
            ENDIF
 
            IF (Y0 .LT. YMID) THEN
                Y0 = Y0 + NGDELT
            ELSE
                Y0 = Y0 - NGDELT
            ENDIF
         ENDIF
 
C  outline annotation text
         CALL DRWREC (X0-XEXT/2, X0+XEXT/2, Y0-YBOT, Y0+YTOP)
260   CONTINUE
 
      CALL SETMSG ('7 8 9', 'The location of an annotation text ' //
     1             'primitive should reflect its 2D reference '   //
     2             'point after being transformed.')
      CALL DCHPFV ('EFFECT OF REFERENCE POINT: In which box is '  //
     1             'the annotation text NOT accurately outlined ' //
     2             'by the rectangle?', 6, NGSQ)
      CALL PEMST(103)
 
C  *** *** ***   effect of annotation offset   *** *** ***
 
C  ngsq = no-good square containing error = random from 1 to 6
      NGSQ = RNDINT (1,6)
C  chstr = "ABC"
      CHRABC = 'ABC'
 
      DO 300 IX = 1, 6
C  unscaled reference point
         XREFPT = U
         YREFPT = U
         ZREFPT = U
 
C  center of current square
         XMID = XWINLO(IX) + XSIZ/2
         YMID = YWINLO(IX) + YSIZ/2
C  scale into center of current square
         CALL ESC3 (XMID, YMID, H, XF)
         CALL PSLMT3 (XF, PCREPL)
 
C  pick NPC offset randomly - but keep within square
         XANNPT = NPCPWC * RNDRL ((XEXT-XSIZ)/2, (XSIZ-XEXT)/2)
         YANNPT = NPCPWC * RNDRL (YBOT - YSIZ/2, YSIZ/2 - YTOP)
         ZANNPT = NPCPWC * RNDRL (-0.499, 0.499)
 
         IF (IX .LE. 3) THEN
            CALL PATR3 (XREFPT,YREFPT,ZREFPT, XANNPT,YANNPT,ZANNPT,
     1                  CHRABC)
         ELSE
            CALL PATR  (XREFPT,YREFPT, XANNPT,YANNPT, CHRABC)
         ENDIF
 
         CALL PSLMT3 (IDM, PCREPL)
C  expected center of rectangle, in MC
         X0 = XMID + XANNPT/NPCPWC
         Y0 = YMID + YANNPT/NPCPWC
 
         IF (IX .EQ. NGSQ) THEN
C  distort towards middle of square - don't overlap border
            IF (X0 .LT. XMID) THEN
                X0 = X0 + NGDELT
            ELSE
                X0 = X0 - NGDELT
            ENDIF
 
            IF (Y0 .LT. YMID) THEN
                Y0 = Y0 + NGDELT
            ELSE
                Y0 = Y0 - NGDELT
            ENDIF
         ENDIF
 
         CALL DRWREC (X0-XEXT/2, X0+XEXT/2, Y0-YBOT, Y0+YTOP)
300   CONTINUE
 
      CALL SETMSG ('7 8 9', 'An annotation text primitive should be ' //
     1             'displaced from the reference point as specified ' //
     2             'by its annotation offset values.')
      CALL DCHPFV ('EFFECT OF ANNOTATION OFFSET: In which box is ' //
     1             'the annotation text NOT accurately outlined '  //
     2             'by the rectangle?', 6, NGSQ)
 
      CALL PEMST (103)
 
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
