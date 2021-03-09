C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/13                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of interior index      *
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

C aspect identifier
      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

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

C interior got
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

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

      INTEGER      PERM(14), PICSTR, TXCI, NAINTS, IX, IY, FCOL
      INTEGER      COLIND(5), EXPDX(14), SIZ
      INTEGER      LINTS(5), THISIS, THISHS, ISTYDX(5), NXTVAL
      INTEGER      IDUM1, IDUM2, IDUM3, IDUM4

      REAL         FXPTY,SCALEY,SHIFTY, Z,U, YLOCEL
      REAL         XACT(4),XEXP(4),XFORM(3,3)

C set up pattern array index values
      INTEGER    DIMX, DIMY
      PARAMETER (DIMX = 50, DIMY = 50)
      INTEGER    PCIA(DIMX, DIMY)

      LOGICAL      GOT(5)

      CALL INITGL ('04.02.05.02/13')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

C  x-location of actual/expected interiors
      CALL SETRVS ('0.2, 0.2, 0.5, 0.5', XACT, SIZ)
      CALL SETRVS ('0.6, 0.6, 0.9, 0.9', XEXP, SIZ)

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

C  *** *** ***   inheritance for interior index  *** ***

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

C  istydx = interior style indexes (will be reset if have HATCH)
C  initialize istydx
      CALL SETVAL ('1,2,3,4,5', ISTYDX)

C  see which interior styles are available
      DO 50 IX = PHOLLO, PISEMP
         GOT(IX) = .FALSE.
50    CONTINUE
C  naints = number of available interior styles
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1, IDUM2, IDUM3,
     1            IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
C  keep track of which styles are available
      DO 200 IX = 1,NAINTS
         CALL PQIF (SPECWT, IX, 0, ERRIND, IDUM1, THISIS, IDUM2,
     1              IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
C  only use valid styles HOLLOW:EMPTY
         IF (PHOLLO .LE. THISIS .AND. THISIS .LE. PISEMP) THEN
            GOT(THISIS) = .TRUE.
         ENDIF
200   CONTINUE

C  initialize lints = PHOLLO,PISEMP,PHOLLO,PHOLLO,PHOLLO
C                   = list of interior styles to be used
      CALL SETVAL('0,4,0,0,0',LINTS)

C  check which styles are available, beside hollow and empty
      NXTVAL = 3
C  if got(SOLID) then fill LINTS(nxtval:5) with solid
      IF (GOT(PSOLID)) THEN
         DO 400 IX = NXTVAL, 5
            LINTS(IX) = PSOLID
400      CONTINUE
         NXTVAL = NXTVAL + 1
      ENDIF

C  if got(HATCH) then fill LINTS(nxtval:5) with hatch
      IF (GOT(PHATCH)) THEN
         IY = 1
         DO 425 IX = NXTVAL, 5
            LINTS(IX) = PHATCH
            CALL PQIF (SPECWT, 0,IY, ERRIND, IDUM1, IDUM2, IDUM3,
     1                 THISHS, IDUM4)
            CALL CHKINQ ('pqif', ERRIND)
            ISTYDX(IX) = THISHS
            IY = IY+1
425      CONTINUE
         NXTVAL = NXTVAL + 1
      ENDIF

C  if got(PATTERN) then fill LINTS(nxtval:5) with pattern
      IF (GOT(PPATTR)) THEN
C  set up pattern array
         PCIA(5,5) = 1
         PCIA(6,5) = 0
         PCIA(7,5) = 1
         PCIA(8,5) = 1
         PCIA(5,6) = 0
         PCIA(6,6) = 1
         PCIA(7,6) = 0
         PCIA(8,6) = 0
         DO 450 IX = NXTVAL, 5
            LINTS(IX) = PPATTR
            CALL PSPAR (WKID, IX, DIMX, DIMY, 5,5,(IX-1),2, PCIA)
450      CONTINUE
      ENDIF

C  set_bundles:
1000  CONTINUE
C  set up 5 bundles
      DO 1010 IX = 1,5
         CALL PSIR (WKID, IX, LINTS(IX), ISTYDX(IX), COLIND(IX))
1010  CONTINUE

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
C  use bundled attributes, except for edge flag
      CALL SETASF (PBUNDL)
C  set ASF individual: edge flag = off
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)

      CALL LOCREC (PERM(1), XACT, 1)
      CALL PEXST (102)
      CALL LOCREC (PERM(9), XACT, 9)
      CALL PSII  (2)
      CALL LOCREC (PERM(10), XACT, 10)

C  Tricky code here: since structure 104 is re-invoked, it
C  generates interior #5,6 on first invocation, and 11,12
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

      CALL LOCREC (PERM(13), XACT, 13)
      CALL LOCREC (PERM(14), XACT, 14)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCREC (PERM(2), XACT, 2)
      CALL PSII  (3)
      CALL PEXST (103)
      CALL LOCREC (PERM(8), XACT, 8)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCREC (PERM(3), XACT, 3)
      CALL PSII  (4)
      CALL LOCREC (PERM(4), XACT, 4)
      CALL PEXST (104)
      CALL LOCREC (PERM(7), XACT, 7)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  interior 5 / 11
      CALL LOCREC (PERM(5), XACT, 5)
      CALL PSII  (5)
C  interior 6 / 12
      CALL LOCREC (PERM(6), XACT, 6)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for bundle index
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 1200 IX =1,14
         CALL PSII (EXPDX(IX))
         CALL LOCREC (PERM(IX), XEXP, IX)
1200   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 6 7 9 10', 'The interior index should '    //
     1             'be saved and restored by <execute structure> ' //
     2             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR INTERIOR ' //
     1             'INDEX: Which pair of interiors does NOT match?',
     2              14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT

      END
