C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/12                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of polymarker index    *
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

C reference handling flag
      INTEGER    PDELE,     PKEEP
      PARAMETER (PDELE = 0, PKEEP = 1)

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

      INTEGER      PERM(14), PICSTR, TXCI, NUMMW, IX, IY, FCOL
      INTEGER      COLIND(5), EXPDX(14), SIZ, NUMMT
      INTEGER      IDUM2,IDUM3

      REAL         NOMMW,MINMW,MAXMW, ALTMW1
      REAL         FXPTY,SCALEY,SHIFTY, Z,U, YLOCEL
      REAL         XACT(5),XEXP(5),XFORM(3,3)

      CALL INITGL ('04.02.02.02/12')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

C  x-location of actual/expected polymarkers
      CALL SETRVS ('0.35', XACT, SIZ)
      CALL SETRVS ('0.55', XEXP, SIZ)

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

C  *** *** ***   inheritance for polymarker index  *** ***

      CALL PQPMF (SPECWT,0, ERRIND, NUMMT, IDUM2,
     1            NUMMW,NOMMW,MINMW,MAXMW, IDUM3 )
      CALL CHKINQ ('pqpmf', ERRIND)

C  get alternative marker size scale factors:
C  altmw1 = max scale factor
      ALTMW1 = MAXMW/NOMMW
C  but make sure ALTMW1 < 0.05 in WC
      ALTMW1 = MIN (ALTMW1, 0.05 / (NOMMW * WCPDC) )

C  call DISCOL to try to get 5 distinct foreground colors,
C    returning fcol = actual number of foreground colors
      CALL DISCOL (5, WKID, FCOL)

C  colind[1:fcol] = list of indices
      CALL SETVAL ('1,2,3,4,5', COLIND)
      IY = 1
      DO 300 IX = FCOL+1,5
         COLIND(IX) = COLIND(IY)
         IY = IY+1
300   CONTINUE

C  set up 5 bundles
       CALL PSPMR (WKID, 1, 1, 1.0,    COLIND(1))
       CALL PSPMR (WKID, 2, 2, ALTMW1, COLIND(2))
       CALL PSPMR (WKID, 3, 3, 1.0,    COLIND(3))
       CALL PSPMR (WKID, 4, 4, ALTMW1, COLIND(4))
       CALL PSPMR (WKID, 5, 5, 1.0,    COLIND(5))

C  randomize order of polymarkers
       CALL RN1SHF (14, PERM)

C  set up CSS:
C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same order on right side of picture, expect for polymarker #14
C  which is deliberately drawn with incorrect attributes.  This
C  should be the only non-matching pair in the picture.

C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use bundled attributes
      CALL SETASF (PBUNDL)

      CALL LOCPPM (PERM(1), XACT)
      CALL PEXST (102)
      CALL LOCPPM (PERM(9), XACT)
      CALL PSPMI  (2)
      CALL LOCPPM (PERM(10), XACT)

C  Tricky code here: since structure 104 is re-invoked, it
C  generates polymarker #5,6 on first invocation, and 11,12
C  on 2nd.  But 11,12 would simply overlay 5,6, so we must
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

      CALL LOCPPM (PERM(13), XACT)
      CALL LOCPPM (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCPPM (PERM(2), XACT)
      CALL PSPMI  (3)
      CALL PEXST (103)
      CALL LOCPPM (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCPPM (PERM(3), XACT)
      CALL PSPMI  (4)
      CALL LOCPPM (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCPPM (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCPPM (PERM(5), XACT)
      CALL PSPMI  (5)
C  polymarker 6 / 12
      CALL LOCPPM (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for bundle index
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 400 IX =1,14
         CALL PSPMI (EXPDX(IX))
         CALL LOCPPM (PERM(IX), XEXP)
400   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 5 6 8 9', 'The polymarker index should '     //
     1             'be saved and restored by <execute structure> ' //
     2             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR POLYMARKER '//
     1             'INDEX: Which pair of markers does NOT match?',
     2              14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT

      END
