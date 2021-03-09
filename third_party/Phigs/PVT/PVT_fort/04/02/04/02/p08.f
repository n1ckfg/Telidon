C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.02/08                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of text index          *
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
 
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
 
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
 
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
 
      INTEGER      PERM(14), PICSTR, TXCI, IX, IY, FCOL
      INTEGER      COLIND(5), EXPDX(14)
 
      REAL         FXPTY,SCALEY,SHIFTY, Z,U, YLOCEL
      REAL         XACT,XEXP,XFORM(3,3), NPCX, NPCY, NPCPWC
 
      CALL INITGL ('04.02.04.02/08')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)
 
C  All test cases use same basic structure network for testing
C  inheritance.  Note that strutucre #14 is executed by both #103
C  and #101
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
 
C  *** *** ***   inheritance for text index  *** ***
 
C  call DISCOL to try to get 5 distinct foreground colors,
C    returning fcol = actual number of foreground colors
      CALL DISCOL (5, WKID, FCOL)
C  colind[1:fcol] = list of indices
      CALL SETVAL ('1,2,3,4,5', COLIND)
      IY = 1
      DO 100 IX = FCOL+1,5
         COLIND(IX) = COLIND(IY)
         IY = IY+1
100   CONTINUE
 
C  set up 5 bundles
      CALL PSTXR (WKID, 1, 1, PSTRKP, 1.0, 0.0, COLIND(1))
      CALL PSTXR (WKID, 2, 2, PSTRKP, 1.0, 0.3, COLIND(2))
      CALL PSTXR (WKID, 3, 1, PSTRKP, 0.7, 0.3, COLIND(3))
      CALL PSTXR (WKID, 4, 2, PSTRKP, 0.7, 0.0, COLIND(4))
      CALL PSTXR (WKID, 5, 1, PSTRKP, 1.3, 0.0, COLIND(5))
 
C  randomize order of interiors
       CALL RN1SHF (14, PERM)
C  set up CSS:
C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same order on right side of picture, expect for interior #14
C  which is deliberately drawn with incorrect attributes.  This
C  should be the only non-matching pair in the picture.
 
C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  ratio of NPC to WC
      CALL WCNPC (0., 0., NPCX, NPCY, NPCPWC)
 
C  use bundled attributes
      CALL SETASF (PBUNDL)
      CALL PSATCH (0.03 * NPCPWC)
      CALL PSATAL (PACENT, PAHALF)
      XACT = 0.4
      XEXP = 0.7
 
      CALL LOCATX (PERM(1), XACT)
      CALL PEXST (102)
 
      CALL LOCATX (PERM(9), XACT)
      CALL PSTXI  (2)
      CALL LOCATX (PERM(10), XACT)
 
C  Tricky code here: since structure 104 is re-invoked, it
C  generates annotation text primitive #5,6 on first invocation,
C  and 11,12 on 2nd.  But 11,12 would simply overlay 5,6, so we must
C  also pass down a transformation which maps locations 5,6
C  to locations 11,12, respectively.
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
 
      CALL LOCATX (PERM(13), XACT)
      CALL LOCATX (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST
 
C  structure #102
      CALL POPST (102)
      CALL LOCATX (PERM(2), XACT)
      CALL PSTXI  (3)
      CALL PEXST (103)
      CALL LOCATX (PERM(8), XACT)
      CALL PCLST
 
C  structure #103
      CALL POPST (103)
      CALL LOCATX (PERM(3), XACT)
      CALL PSTXI  (4)
      CALL LOCATX (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCATX (PERM(7), XACT)
      CALL PCLST
 
C  structure #104
      CALL POPST (104)
C  text primitive 5 / 11
      CALL LOCATX (PERM(5), XACT)
      CALL PSTXI  (5)
C  text primitive 6 / 12
      CALL LOCATX (PERM(6), XACT)
      CALL PCLST
 
C  Expected attributes: structure #105
      CALL POPST (105)
C  values for bundle index
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 1200 IX =1,14
         CALL PSTXI (EXPDX(IX))
         CALL LOCATX (PERM(IX), XEXP)
1200   CONTINUE
 
C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST
 
      CALL SETMSG ('1 3 4 6 7', 'The text index should be saved ' //
     1             'and restored by <execute structure> during '  //
     2             'traversal.')
 
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR TEXT INDEX: ' //
     1             'Which pair of annotation text primitives does ' //
     2             'NOT match?', 14, PERM(14))
 
666   CONTINUE
C  wrap it up.
      CALL ENDIT
 
      END
