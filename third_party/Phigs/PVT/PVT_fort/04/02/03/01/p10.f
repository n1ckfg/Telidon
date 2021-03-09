C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.01/10                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization for geometric text     *
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

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

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

      INTEGER    PICSTR, TXCI, IX, SIZ, PERM(14), EXPDX(14)
      INTEGER    LALGNH(5), LALGNV(5), LTXP(5), IY

      REAL       XACT,XEXP, LHTS(5), Z,U, FXPTY, SHIFTY, YLOCEL
      REAL       SCF, SCFORM(3,3), XFORM(3,3), LCHUPX(5),LCHUPY(5)

      CHARACTER  T3STR*3

      DATA  T3STR / 'Up!' /

      CALL INITGL ('04.02.03.01/10')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

C  All test cases use same basic structure network for testing
C  inheritance.  Five (distinct if possible) values for the
C  attribute(s) to be tested are set up and propagated throughout
C  the network.  The first value is the system default from the PDT.
C  Note that structure #104 is executed by both #103 and #101.
C  Actual results are displayed on the left, expected results on the
C  right, with the 14th deliberately made incorrect.
C
C  default = val#1
C    |                  102
C    |                 /  prim 2
C    |               /    attr = val#3   val#3
C    V        val#1/      exec 103---------------103
C  101           /        prim 8                   prim 3
C    prim 1    /                                   attr = val#4
C    exec 102/                                     prim 4
C    prim 9                                        exec 104\
C    attr = val#2                                  prim 7    \ val#4
C    prim 10                                                   \
C    transform             val#2                                 \
C    exec 104-----------------------------------------------------104
C    un-transform                                                   prim 5/11
C    prim 13                                                        attr = val#5
C    prim 14                                                        prim 6/12
C    exec 105---------->105
C                         expected values

C  *** *** *** ***   character height   *** *** *** ***

C  lhts = list of 5 distinct character heights
C       = [.010, .012, .006, .008, .014]
C    with 0.010 (default) in 1st position.
      CALL SETRVS ('.010, .012, .006, .008, .014', LHTS, SIZ)

      XACT = 0.2
      XEXP = 0.5

C  randomize location of text strings
      CALL RN1SHF (14, PERM)

C  set up CSS as described above

C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  Throughout, use font=1, precision=stroke, alignment=left,half
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSTXAL (PALEFT, PAHALF)
C  Throughout, scale such that char-ht of 0.01 and nearby values
C  are reasonably visible and fit on line.
      SCF = .04/.014
      CALL PSC (SCF,SCF, ERRIND, SCFORM)
      CALL CHKINQ ('psc', ERRIND)
      CALL PSLMT (SCFORM, PCREPL)

      CALL LOCTX1 (PERM(1), XACT, SCF)
      CALL PEXST (102)
      CALL LOCTX1 (PERM(9), XACT, SCF)
      CALL PSCHH (LHTS(2))
      CALL LOCTX1 (PERM(10), XACT, SCF)

C  Tricky code here: since structure 104 is re-invoked, it
C  generates rectangle #5,6 on first invocation, and 11,12
C  on 2nd.  But 11,12 would simply overlay 5,6, so we must
C  also pass down a local transformation which maps locations 5,6
C  to locations 11,12, respectively.
      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,U, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCPOST)
C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL PSLMT (SCFORM, PCREPL)

      CALL LOCTX1 (PERM(13), XACT, SCF)
      CALL LOCTX1 (PERM(14), XACT, SCF)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTX1 (PERM(2), XACT, SCF)
      CALL PSCHH (LHTS(3))
      CALL PEXST (103)
      CALL LOCTX1 (PERM(8), XACT, SCF)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTX1 (PERM(3), XACT, SCF)
      CALL PSCHH (LHTS(4))
      CALL LOCTX1 (PERM(4), XACT, SCF)
      CALL PEXST (104)
      CALL LOCTX1 (PERM(7), XACT, SCF)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCTX1 (PERM(5), XACT, SCF)
      CALL PSCHH (LHTS(5))
C  fill area set 6 / 12
      CALL LOCTX1 (PERM(6), XACT, SCF)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 105 IX = 1,14
         CALL PSCHH (LHTS (EXPDX(IX)))
         CALL LOCTX1 (PERM(IX), XEXP, SCF)
105   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15/SCF, YLOCEL(1)/SCF, (1.0/15)/SCF)
      CALL PCLST

      CALL SETMSG ('11 58 62 63', 'The character height attribute ' //
     1             'should be saved and restored by <execute '      //
     2             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR CHARACTER ' //
     1             'HEIGHT: Which pair of text strings does NOT ' //
     2             'match?', 14, PERM(14))


C  *** *** *** ***   text alignment   *** *** *** ***

C  Clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  lalgnh, lalgnv = list of 5 distinct text alignments (default in
C                   first position) =
C
C          horizontal  vertical
C          ----------  --------
C     1:   LEFT        BASE
C     2:   CENTER      HALF
C     3:   RIGHT       CAP
C     4:   LEFT        BOTTOM
C     5:   RIGHT       TOP

      CALL SETVAL ('1,2,3,1,3', LALGNH)
      CALL SETVAL ('4,3,2,5,1', LALGNV)

      XACT = 0.4
      XEXP = 0.7

C  randomize location of text strings
      CALL RN1SHF (14, PERM)

C  Set up CSS as described above; display 14 pairs of text strings
C  with text alignments from lalgnh, lalgnv; show alignment point
C  for each with polymarker

C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  Throughout, use font=1, precision=stroke, character height = .04
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSCHH  (0.025)
      CALL PSPMCI (2)

      CALL LOCTX2 (PERM(1), XACT)
      CALL PEXST (102)
      CALL LOCTX2 (PERM(9), XACT)
      CALL PSTXAL (LALGNH(2), LALGNV(2))
      CALL LOCTX2 (PERM(10), XACT)

C  Tricky code here: since structure 104 is re-invoked, it
C  generates rectangle #5,6 on first invocation, and 11,12
C  on 2nd.  But 11,12 would simply overlay 5,6, so we must
C  also pass down a local transformation which maps locations 5,6
C  to locations 11,12, respectively.
      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,U, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCPRE)
C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, SCFORM)
      CALL PSLMT (SCFORM, PCREPL)

      CALL LOCTX2 (PERM(13), XACT)
      CALL LOCTX2 (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTX2 (PERM(2), XACT)
      CALL PSTXAL (LALGNH(3), LALGNV(3))
      CALL PEXST (103)
      CALL LOCTX2 (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTX2 (PERM(3), XACT)
      CALL PSTXAL (LALGNH(4), LALGNV(4))
      CALL LOCTX2 (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCTX2 (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCTX2 (PERM(5), XACT)
      CALL PSTXAL (LALGNH(5), LALGNV(5))
C  fill area set 6 / 12
      CALL LOCTX2 (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 205 IX = 1,14
         CALL PSTXAL (LALGNH (EXPDX(IX)), LALGNV (EXPDX(IX)))
         CALL LOCTX2 (PERM(IX), XEXP)
205   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), (1.0/15))
      CALL PCLST

      CALL SETMSG ('11 74 75 77 78', 'The text alignment attribute ' //
     1             'should be saved and restored by <execute '       //
     2             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR TEXT '       //
     1             'ALIGNMENT: Which pair of text strings is NOT ' //
     2             'similarly aligned with respect to the marked ' //
     3             'text position?', 14, PERM(14))


C  *** *** *** ***   text path and character up   *** *** *** ***
C  Clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  ltxp, lchup = list of 5 distinct text paths and character-ups
C                (default in first position) =
C
C          text path   character up
C          ---------   ------------
C     1:   RIGHT        0, 1
C     2:   UP          -3, 1
C     3:   LEFT         1,-3
C     4:   DOWN        -3,-1
C     5:   LEFT        -1,-3

      CALL SETVAL (' 0, 2, 1, 3, 1', LTXP)
      CALL SETRVS (' 0,-3, 1,-3,-1', LCHUPX, SIZ)
      CALL SETRVS (' 1, 1,-3,-1,-3', LCHUPY, SIZ)

      XACT = 0.3
      XEXP = 0.6

C  randomize location of text strings
      CALL RN1SHF (14, PERM)

C  set up CSS as described above; display 14 pairs of text strings
C  with text paths and character ups from ltxp, lchup

C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  Throughout, use font=1, precision=stroke, character height = .04,
C  alignment=center,half
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSCHH  (0.03)
      CALL PSTXAL (PACENT, PAHALF)

      CALL PTX (XACT, YLOCEL(PERM(1)), T3STR)
      CALL PEXST (102)
      CALL PTX (XACT, YLOCEL(PERM(9)), T3STR)
      CALL PSCHUP (LCHUPX(2), LCHUPY(2))
      CALL PSTXP  (LTXP(2))
      CALL PTX (XACT, YLOCEL(PERM(10)), T3STR)

C  Tricky code here: since structure 104 is re-invoked, it
C  generates rectangle #5,6 on first invocation, and 11,12
C  on 2nd.  But 11,12 would simply overlay 5,6, so we must
C  also pass down a local transformation which maps locations 5,6
C  to locations 11,12, respectively.
      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,U, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCPRE)
C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, SCFORM)
      CALL PSLMT (SCFORM, PCREPL)

      CALL PTX (XACT, YLOCEL(PERM(13)), T3STR)
      CALL PTX (XACT, YLOCEL(PERM(14)), T3STR)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL PTX (XACT, YLOCEL(PERM(2)), T3STR)
      CALL PSCHUP (LCHUPX(3), LCHUPY(3))
      CALL PSTXP  (LTXP(3))
      CALL PEXST (103)
      CALL PTX (XACT, YLOCEL(PERM(8)), T3STR)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL PTX (XACT, YLOCEL(PERM(3)), T3STR)
      CALL PSCHUP (LCHUPX(4), LCHUPY(4))
      CALL PSTXP  (LTXP(4))
      CALL PTX (XACT, YLOCEL(PERM(4)), T3STR)
      CALL PEXST (104)
      CALL PTX (XACT, YLOCEL(PERM(7)), T3STR)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL PTX (XACT, YLOCEL(PERM(5)), T3STR)
      CALL PSCHUP (LCHUPX(5), LCHUPY(5))
      CALL PSTXP  (LTXP(5))
C  fill area set 6 / 12
      CALL PTX (XACT, YLOCEL(PERM(6)), T3STR)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 305 IX = 1,14
         IY = EXPDX(IX)
         CALL PSCHUP (LCHUPX(IY), LCHUPY(IY))
         CALL PSTXP  (LTXP(IY))
         CALL PTX (XEXP, YLOCEL(PERM(IX)), T3STR)
305   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), (1.0/15))
      CALL PCLST

      CALL SETMSG ('11 66 67 70 71 80 81 82 83', 'The text path and ' //
     1             'character up attributes should be saved and '     //
     2             'restored by <execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR TEXT PATH '  //
     1             'AND CHARACTER UP: Which pair of text strings ' //
     2             'does NOT match?', 14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
