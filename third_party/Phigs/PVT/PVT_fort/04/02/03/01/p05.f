C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.01/05                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization for non-geometric      *
C  *                 text attributes                       *
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
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER    NFPP, IX, IY, THISFN, THISPR, LDISFN(5), LDISPR(5)
      INTEGER    PERM(20), EXPDX(14), PICSTR, TXCI, SUBCT
      INTEGER    FCOL, CBASE, COLIND(0:10)

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL       XACT,XEXP, YINCR, Z,U, FXPTY, SHIFTY, SCALEY, YLOCEL
      REAL       XFORM(3,3), LDISXP(5), LDISSP(5)
      REAL       RDUM1,RDUM2,RDUM3,RDUM4

C  ldisfn,ldispr = list of 5 distinct font,precision pairs
      DATA  LDISFN / 1,      2,      1,     2,      1      /
      DATA  LDISPR / PCHARP, PSTRKP, PSTRP, PCHARP, PSTRKP /
C  ldisxp,ldissp = list of 5 distinct expansion and spacing values
      DATA  LDISXP / 1.0, 0.4, 0.7, 1.3,  1.7 /
      DATA  LDISSP / 0.0, 1.4, 1.1, 0.5, -0.3 /

      DATA  COLIND / 1,2,3,4,5,6,7,8,9,10,11 /

      CALL INITGL ('04.02.03.01/05')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

C  use <inquire text facilities> to find three other available
C  fonts, if any, and use them in ldisfn(3, 4, and 5).
      CALL PQTXF (SPECWT, 0, ERRIND, NFPP, IDUM1,IDUM2,
     1            IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
      SUBCT = 0
      DO 100 IX = 1,NFPP
         CALL PQTXF (SPECWT, IX, ERRIND, IDUM1, THISFN,THISPR,
     1               IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf', ERRIND)
         IF (THISFN.EQ.1 .OR. THISFN.EQ.2) GOTO 100

C  searching back from 5 to 3, because 5 has the hardest precision
C  to be requested (stroke), while 3 has the easiest (string).
         DO 105 IY = 5,3,-1
            IF (LDISFN(IY).GE.1 .AND. LDISFN(IY).LE.2  .AND.
     1          THISPR.GE.LDISPR(IY) ) THEN
               LDISFN(IY) = THISFN
               SUBCT = SUBCT+1
               IF (SUBCT .GE. 3) THEN
                  GOTO 110
               ELSE
                  GOTO 100
               ENDIF
            ENDIF
105      CONTINUE

100   CONTINUE

110   CONTINUE

C  set up random permutation, with uniform scaling
      CALL RN1SHF (14,PERM)

C  set up CSS:
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL PSCHXP (0.8)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PSCHH  (0.035)
      CALL PSTXP  (PRIGHT)

C  left margin for actual, expected values, and Y-increment:
      XACT = 0.2
      XEXP = 0.6
      YINCR = 1.0/15

C  text 1
      CALL LOCTXT (PERM(1), XACT)
      CALL PEXST (102)
C  text 9
      CALL LOCTXT (PERM(9), XACT)
C  change-attributes: use ldisfn(2),ldispr(2)
      CALL PSTXFN (LDISFN(2))
      CALL PSTXPR (LDISPR(2))
C  text 10
      CALL LOCTXT (PERM(10), XACT)

C  Tricky code here: since structure 104 is re-invoked, it
C  generates text #5,6 on first invocation, and 11,12
C  on 2nd.  But 11,12 would simply overlay 5,6, so we must
C  also pass down a transformation which maps locations 5,6
C  to locations 11,12, respectively.
      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
C  scaley should be 1.0, because PERM was craftily re-arranged, above
      SCALEY = (YLOCEL(PERM(12)) - YLOCEL(PERM(11))) /
     1         (YLOCEL(PERM(06)) - YLOCEL(PERM(05)))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,SCALEY, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)
C  text 13
      CALL LOCTXT (PERM(13), XACT)
C  text 14
      CALL LOCTXT (PERM(14), XACT)
C  execute 105 for expected values
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
C  text 2
      CALL LOCTXT (PERM(2), XACT)
C  change-attributes: use ldisfn(3),ldispr(3)
      CALL PSTXFN (LDISFN(3))
      CALL PSTXPR (LDISPR(3))
C  execute 103
      CALL PEXST (103)
C  text 8
      CALL LOCTXT (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
C  text 3
      CALL LOCTXT (PERM(3), XACT)
C  change-attributes: use ldisfn(4),ldispr(4)
      CALL PSTXFN (LDISFN(4))
      CALL PSTXPR (LDISPR(4))
C  text 4
      CALL LOCTXT (PERM(4), XACT)
C  execute 104
      CALL PEXST (104)
C  text 7
      CALL LOCTXT (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  text 5 / 11
      CALL LOCTXT (PERM(5), XACT)
C  change-attributes: use ldisfn(5),ldispr(5)
      CALL PSTXFN (LDISFN(5))
      CALL PSTXPR (LDISPR(5))
C  text 6 / 12
      CALL LOCTXT (PERM(6), XACT)
      CALL PCLST

C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same random order on right side of picture, except for text
C  14 which is deliberately drawn with incorrect attributes. This
C  should be the only non-matching pair in the picture.

C  structure #105
      CALL POPST (105)

C  using 1 as 14th "incorrect" value because 1st and 2nd must be distinct,
C  since font 1 and 2 must be distinct.
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,1', EXPDX)

      DO 200  IX = 1,14
C  change-attributes to expected values
         CALL PSTXFN (LDISFN(EXPDX(IX)))
         CALL PSTXPR (LDISPR(EXPDX(IX)))
         CALL LOCTXT (PERM(IX), XEXP)
200   CONTINUE

C  draw labels
      CALL NUMLAB (14, .15, YLOCEL(1), YINCR)
      CALL PCLST

      CALL SETMSG ('11 13 21 23 24 27 28 32 33', 'The text font and ' //
     1             'precision attributes for the text primitive '     //
     2             'should be saved and restored by <execute '        //
     3             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR TEXT FONT '  //
     1             'AND PRECISION: Which pair of text primitives ' //
     2             'does NOT match?', 14, PERM(14))

C  *** *** ***   character expansion and spacing   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  set up random permutation, with uniform scaling
      CALL RN1SHF (14,PERM)

C  set up CSS:
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PSCHH  (0.035)
      CALL PSTXP  (PRIGHT)
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)

C  text 1
      CALL LOCTXT (PERM(1), XACT)
      CALL PEXST (102)
C  text 9
      CALL LOCTXT (PERM(9), XACT)
C  change-attributes: use ldisxp(2),ldissp(2)
      CALL PSCHXP (LDISXP(2))
      CALL PSCHSP (LDISSP(2))
C  text 10
      CALL LOCTXT (PERM(10), XACT)

C  Tricky code here: see comments above
      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
C  scaley should be 1.0, because PERM was craftily re-arranged, above
      SCALEY = (YLOCEL(PERM(12)) - YLOCEL(PERM(11))) /
     1         (YLOCEL(PERM(06)) - YLOCEL(PERM(05)))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,SCALEY, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)
C  text 13
      CALL LOCTXT (PERM(13), XACT)
C  text 14
      CALL LOCTXT (PERM(14), XACT)
C  execute 105 for expected values
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
C  text 2
      CALL LOCTXT (PERM(2), XACT)
C  change-attributes: use ldisxp(3),ldissp(3)
      CALL PSCHXP (LDISXP(3))
      CALL PSCHSP (LDISSP(3))
C  execute 103
      CALL PEXST (103)
C  text 8
      CALL LOCTXT (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
C  text 3
      CALL LOCTXT (PERM(3), XACT)
C  change-attributes: use ldisxp(4),ldissp(4)
      CALL PSCHXP (LDISXP(4))
      CALL PSCHSP (LDISSP(4))
C  text 4
      CALL LOCTXT (PERM(4), XACT)
C  execute 104
      CALL PEXST (104)
C  text 7
      CALL LOCTXT (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  text 5 / 11
      CALL LOCTXT (PERM(5), XACT)
C  change-attributes: use ldisxp(5),ldissp(5)
      CALL PSCHXP (LDISXP(5))
      CALL PSCHSP (LDISSP(5))
C  text 6 / 12
      CALL LOCTXT (PERM(6), XACT)
      CALL PCLST

C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same random order on right side of picture, except for text
C  14 which is deliberately drawn with incorrect attributes. This
C  should be the only non-matching pair in the picture.

C  structure #105
      CALL POPST (105)

C  values for index into expected expansion and spacing
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)

      DO 210  IX = 1,14
C  change-attributes to expected values
         CALL PSCHXP (LDISXP(EXPDX(IX)))
         CALL PSCHSP (LDISSP(EXPDX(IX)))
         CALL LOCTXT (PERM(IX), XEXP)
210   CONTINUE

C  draw labels
      CALL NUMLAB (14, .15, YLOCEL(1), YINCR)
      CALL PCLST

      CALL SETMSG ('11 35 36 38 39 41 42 44 45', 'The character ' //
     1             'expansion factor and character spacing '      //
     2             'attributes for the text primitive should be ' //
     3             'saved and restored by <execute structure> '   //
     4             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR CHARACTER ' //
     1             'EXPANSION AND SPACING: Which pair of text '   //
     2             'primitives does NOT match?', 14, PERM(14))

C  *** *** *** ***   text colour index   *** *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  set up random permutation, with uniform scaling
      CALL RN1SHF (14,PERM)

C  call DISCOL to try to get 5 distinct foreground colors,
C    returning fcol = actual number of foreground colors
      CALL DISCOL (5, WKID, FCOL)

      IF (FCOL .LE. 1) THEN
         FCOL = 2
C  colind[0:1] = circular list of indices = [1,0]
         COLIND (0) = 1
         COLIND (1) = 0
      ELSE
C  colind[0:fcol-1] = circular list of indices = [1,..,fcol] (as is)
      ENDIF

      CBASE = 0

C  set up CSS:
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PSCHH  (0.035)
      CALL PSTXP  (PRIGHT)
      CALL PSTXFN (2)
      CALL PSTXPR (PSTRKP)

C  text 1
      CALL LOCTXT (PERM(1), XACT)
      CALL PEXST (102)
C  text 9
      CALL LOCTXT (PERM(9), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSTXCI (COLIND (MOD(CBASE, FCOL)))
C  text 10
      CALL LOCTXT (PERM(10), XACT)

C  Tricky code here: see comments above
      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      SCALEY = (YLOCEL(PERM(12)) - YLOCEL(PERM(11))) /
     1         (YLOCEL(PERM(06)) - YLOCEL(PERM(05)))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,SCALEY, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)
C  text 13
      CALL LOCTXT (PERM(13), XACT)
C  text 14
      CALL LOCTXT (PERM(14), XACT)

C  execute 105 for expected values
      CALL PEXST (105)
      CALL PCLST

      CALL POPST (102)
C  text 2
      CALL LOCTXT (PERM(2), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSTXCI (COLIND (MOD(CBASE, FCOL)))
C  execute 103
      CALL PEXST (103)
C  text 8
      CALL LOCTXT (PERM(8), XACT)
      CALL PCLST

      CALL POPST (103)
C  text 3
      CALL LOCTXT (PERM(3), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSTXCI (COLIND (MOD(CBASE, FCOL)))
C  text 4
      CALL LOCTXT (PERM(4), XACT)
C  execute 104
      CALL PEXST (104)
C  text 7
      CALL LOCTXT (PERM(7), XACT)
      CALL PCLST

      CALL POPST (104)
C  text 5 / 11
      CALL LOCTXT (PERM(5), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSTXCI (COLIND (MOD(CBASE, FCOL)))
C  text 6 / 12
      CALL LOCTXT (PERM(6), XACT)
      CALL PCLST

      CALL POPST (105)

C  Expected attributes (except #14, whose actual color should be
C  same as #13):
C  color index = colind(cbase mod fcol)
C
C  structure #105
C  text    cbase           text    cbase
C  ----    -----           ----    -----
C  01      0               08      2
C  02      0               09      0
C  03      2               10      1
C  04      3               11      1
C  05      3               12      4
C  06      4               13      1
C  07      3               14      2

      DO 220 IX = 1,14
         CALL PSTXCI (COLIND (MOD(EXPDX(IX)-1, FCOL)))
         CALL LOCTXT (PERM(IX), XEXP)
220   CONTINUE
C  draw labels
      CALL NUMLAB (14, .15, YLOCEL(1), YINCR)

      CALL PCLST

      CALL SETMSG ('11 47 48 50 51', 'The text color index '     //
     1             'attribute for the text primitive should be ' //
     2             'saved and restored by <execute structure> '  //
     3             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR TEXT COLOR ' //
     1             'INDEX: Which pair of text primitives does '    //
     2             'NOT match?', 14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
