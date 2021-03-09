C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/11                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization for geometric          *
C  *                 annotation text attributes            *
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

      INTEGER    PICSTR, TXCI, IX, IY, SIZ, PERM(14), EXPDX(14)
      INTEGER    LALGNH(5), LALGNV(5), LTXP(5), NUMAS, LSIZ, ADX
      INTEGER    THISAS, LANST(5)
      INTEGER    IDUM1,IDUM2

      REAL       XACT,XEXP, LHTS(5), Z,U, FXPTY, SHIFTY, YLOCEL
      REAL       XFORM(3,3), LCHUPX(5),LCHUPY(5), YINCR
      REAL       NPCX,NPCY,NPCPWC
      REAL       RDUM1,RDUM2

      LOGICAL    GOT1

      CHARACTER  T3STR*3

      DATA  T3STR / 'Up!' /

      CALL INITGL ('04.02.04.01/11')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

C  All test cases use the same basic structure network for testing
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
C
C
C  *** *** ***   annotation text character height   *** *** ***

C  lhts = list of 5 distinct character heights
C       = [.010, .020, .015, .025, .030]
C    with 0.010 (default) in 1st position.
      CALL SETRVS ('.010, .020, .015, .025, .030', LHTS, SIZ)

      XACT = 0.2
      XEXP = 0.5
      YINCR = 1.0/15

C  randomize location of text strings
      CALL RN1SHF (14, PERM)

C  set up CSS as described above
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  Throughout, use font=1, precision=stroke, alignment=left,half
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSATAL (PALEFT, PAHALF)

      CALL LOCATX (PERM(1), XACT)
      CALL PEXST (102)
      CALL LOCATX (PERM(9), XACT)
      CALL PSATCH (LHTS(2))
      CALL LOCATX (PERM(10), XACT)

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
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)

C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCATX (PERM(13), XACT)
      CALL LOCATX (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCATX (PERM(2), XACT)
      CALL PSATCH (LHTS(3))
      CALL PEXST (103)
      CALL LOCATX (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCATX (PERM(3), XACT)
      CALL PSATCH (LHTS(4))
      CALL LOCATX (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCATX (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCATX (PERM(5), XACT)
      CALL PSATCH (LHTS(5))
C  fill area set 6 / 12
      CALL LOCATX (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 105 IX = 1,14
         CALL PSATCH (LHTS (EXPDX(IX)))
         CALL LOCATX (PERM(IX), XEXP)
105   CONTINUE

C  draw labels
      CALL NUMLAB (14, .15, YLOCEL(1), YINCR)
      CALL PCLST

      CALL SETMSG ('5 48 53 54', 'The annotation text character '   //
     1             'height attribute should be saved and restored ' //
     2             'by <execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR ANNOTATION ' //
     1             'TEXT CHARACTER HEIGHT: Which pair of '         //
     2             'annotation text strings does NOT match?',
     3             14, PERM(14))


C  *** *** *** ***   annotation text alignment   *** *** *** ***

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

C  set up CSS as described above; display 14 pairs of annotation
C    text strings with annotation text alignments from lalgnh, lalgnv
C  show alignment point for each with polymarker

C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  Throughout, use font=1, precision=stroke, character height = .025
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSATCH (0.025 * NPCPWC)
      CALL PSPMCI (2)

      CALL LOCAT2 (PERM(1), XACT)
      CALL PEXST (102)
      CALL LOCAT2 (PERM(9), XACT)
      CALL PSATAL (LALGNH(2), LALGNV(2))
      CALL LOCAT2 (PERM(10), XACT)

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
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)

C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCAT2 (PERM(13), XACT)
      CALL LOCAT2 (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCAT2 (PERM(2), XACT)
      CALL PSATAL (LALGNH(3), LALGNV(3))
      CALL PEXST (103)
      CALL LOCAT2 (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCAT2 (PERM(3), XACT)
      CALL PSATAL (LALGNH(4), LALGNV(4))
      CALL LOCAT2 (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCAT2 (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCAT2 (PERM(5), XACT)
      CALL PSATAL (LALGNH(5), LALGNV(5))
C  fill area set 6 / 12
      CALL LOCAT2 (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 205 IX = 1,14
         CALL PSATAL (LALGNH (EXPDX(IX)), LALGNV (EXPDX(IX)))
         CALL LOCAT2 (PERM(IX), XEXP)
205   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), (1.0/15))
      CALL PCLST

      CALL SETMSG ('5 65 66 68 69', 'The annotation text alignment ' //
     1             'attribute should be saved and restored by '      //
     2             '<execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR ANNOTATION '  //
     1             'TEXT ALIGNMENT: Which pair of annotation text ' //
     2             'strings is NOT similarly aligned with respect ' //
     3             'to the marked annotation point?', 14, PERM(14))


C  *** ***   annotation text path and character up   *** ***

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

C  randomize location of annotation text strings
      CALL RN1SHF (14, PERM)

C  set up CSS as described above; display 14 pairs of annotation
C    text strings with annotation text paths and character ups
C    from ltxp, lchup

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
      CALL PSATCH (0.03 * NPCPWC)
      CALL PSATAL (PACENT, PAHALF)

      CALL PATR (XACT, YLOCEL(PERM(1)), Z,Z, T3STR)
      CALL PEXST (102)
      CALL PATR (XACT, YLOCEL(PERM(9)), Z,Z, T3STR)
      CALL PSATCU (LCHUPX(2), LCHUPY(2))
      CALL PSATP  (LTXP(2))
      CALL PATR (XACT, YLOCEL(PERM(10)), Z,Z, T3STR)

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
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)

C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL PATR (XACT, YLOCEL(PERM(13)), Z,Z, T3STR)
      CALL PATR (XACT, YLOCEL(PERM(14)), Z,Z, T3STR)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL PATR (XACT, YLOCEL(PERM(2)), Z,Z, T3STR)
      CALL PSATCU (LCHUPX(3), LCHUPY(3))
      CALL PSATP  (LTXP(3))
      CALL PEXST (103)
      CALL PATR (XACT, YLOCEL(PERM(8)), Z,Z, T3STR)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL PATR (XACT, YLOCEL(PERM(3)), Z,Z, T3STR)
      CALL PSATCU (LCHUPX(4), LCHUPY(4))
      CALL PSATP  (LTXP(4))
      CALL PATR (XACT, YLOCEL(PERM(4)), Z,Z, T3STR)
      CALL PEXST (104)
      CALL PATR (XACT, YLOCEL(PERM(7)), Z,Z, T3STR)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL PATR (XACT, YLOCEL(PERM(5)), Z,Z, T3STR)
      CALL PSATCU (LCHUPX(5), LCHUPY(5))
      CALL PSATP  (LTXP(5))
C  fill area set 6 / 12
      CALL PATR (XACT, YLOCEL(PERM(6)), Z,Z, T3STR)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 305 IX = 1,14
         IY = EXPDX(IX)
         CALL PSATCU (LCHUPX(IY), LCHUPY(IY))
         CALL PSATP  (LTXP(IY))
         CALL PATR (XEXP, YLOCEL(PERM(IX)), Z,Z, T3STR)
305   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), (1.0/15))
      CALL PCLST

      CALL SETMSG ('5 57 58 61 62 71 72 73 74', 'The annotation ' //
     1             'text path and annotation text character up '  //
     2             'attributes should be saved and restored by '  //
     3             '<execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR ANNOTATION ' //
     1             'TEXT PATH AND CHARACTER UP: Which pair of '    //
     2             'annotation text strings does NOT match?',
     3             14, PERM(14))

C  *** *** ***   annotation style   *** *** ***

C  Clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  Use <inquire annotation facilities> to develop
C    lanst = list of available annotation styles

      CALL PQANF (SPECWT, 0, ERRIND, NUMAS, IDUM1,IDUM2, RDUM1,RDUM2)
      CALL CHKINQ ('pqanf', ERRIND)

      IF (NUMAS .LT. 2) THEN
         CALL INMSG ('Skipping test of annotation style ' //
     1               'inheritance; less than two styles available.')
         GOTO 666
      ENDIF

      LSIZ = 1
      GOT1 = .FALSE.
      DO 150 ADX = 1, NUMAS
         CALL PQANF (SPECWT,ADX, ERRIND, IDUM1, THISAS,
     1               IDUM2,RDUM1,RDUM2)
         CALL CHKINQ ('pqanf', ERRIND)

         IF (THISAS .EQ. 1) THEN
            LANST(1) = 1
            GOT1 = .TRUE.
         ELSE
            LSIZ = MIN(5,LSIZ+1)
            LANST (LSIZ) = THISAS
         ENDIF
150   CONTINUE

      IF (.NOT. GOT1) THEN
         CALL INMSG ('Skipping test of annotation style ' //
     1               'inheritance; style #1 not available.')
         GOTO 666
      ENDIF

C  lanst contains exactly five elements; element #1 = 1 (default)

C  fill out list
      IY = 1
      DO 400 IX = LSIZ+1,5
         LANST(IX) = LANST(IY)
         IY = IY+1
400   CONTINUE

      XACT = 0.4
      XEXP = 0.8
      YINCR = 1.0/15

C  randomize location of text strings
      CALL RN1SHF (14, PERM)

C  set up CSS as described above
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  Throughout, use font=1, precision=stroke, alignment=rite,half
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSATAL (PARITE, PAHALF)
      CALL PSATCH (0.5 * YINCR * NPCPWC)
      CALL PSPLCI (2)
      CALL PSLN   (2)

      CALL LOCANS (PERM(1), XACT)
      CALL PEXST (102)
      CALL LOCANS (PERM(9), XACT)
      CALL PSANS (LANST(2))
      CALL LOCANS (PERM(10), XACT)

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
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)

C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCANS (PERM(13), XACT)
      CALL LOCANS (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCANS (PERM(2), XACT)
      CALL PSANS (LANST(3))
      CALL PEXST (103)
      CALL LOCANS (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCANS (PERM(3), XACT)
      CALL PSANS (LANST(4))
      CALL LOCANS (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCANS (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCANS (PERM(5), XACT)
      CALL PSANS (LANST(5))
C  fill area set 6 / 12
      CALL LOCANS (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 405 IX = 1,14
         CALL PSANS (LANST (EXPDX(IX)))
         CALL LOCANS (PERM(IX), XEXP)
405   CONTINUE

C  draw labels
      CALL NUMLAB (14, .15, YLOCEL(1), YINCR)
      CALL PCLST

      CALL SETMSG ('5 76 83 84', 'The annotation style attribute ' //
     1             'should be saved and restored by <execute '     //
     2             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR ANNOTATION ' //
     1             'STYLE: Which pair of annotation styles does '  //
     2             'NOT match?', 14, PERM(14))

C  end_style:
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
