C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/13                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of edge index          *
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
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C composition type
      INTEGER    PCPRE,    PCPOST,   PCREPL
      PARAMETER (PCPRE = 0,PCPOST=1, PCREPL = 2)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

      INTEGER    PICSTR, TXCI, IX, IY, SIZ
      INTEGER    NUMET, NUMEW, EDFLG(5), LEDTYP(5), DSEDGE
      INTEGER    EXPDX(14), THISED, FCOL, COLIND(5), PERM(14)
      INTEGER    IDUM1, IDUM2, IDUM3

      REAL       ALTEW1, ALTEW2, AVG1, AVG2, Z, U, SHIFTY, FXPTY
      REAL       SCALEY, XFORM(3,3), RDUM1, RDUM2, RDUM3
      REAL       XACT(3), XEXP(3), YLOCEL, NOMEW, MINEW, MAXEW

      CALL INITGL ('04.02.05.03/13')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

C  All test cases use same basic structure network for testing
C  inheritance.
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

C  *** *** ***   inheritance for edge index   *** *** ***

C  numet  = number of edgetypes
C  numew  = number of available edge-widths
C  nomew  = nominal edge-width (DC)
C  minew,maxew = minimum,maximum edge-width (DC)
      CALL PQEDF (SPECWT, 0, ERRIND, NUMET, IDUM2, NUMEW, NOMEW,
     1            MINEW, MAXEW, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)

C  x-location of actual / expected triangle
      CALL SETRVS ('0.2,0.2,0.5',XACT,SIZ)
      CALL SETRVS ('0.6,0.6,0.9',XEXP,SIZ)

C  set edge flag
      DO 50 IX = 1,5
         EDFLG(IX) = PON
50    CONTINUE
      IF (NUMET .EQ. 1) EDFLG(3) = POFF

C  distinct edgetypes
      DSEDGE = MIN (5, ABS(NUMET))
C  pick no more than 5 out of whatever is available
      CALL RNSET (DSEDGE, ABS(NUMET), PERM)

      DO 100 IX = 1, 5
         IF (IX .LE. DSEDGE) THEN
            CALL PQEDF (SPECWT, PERM(IX), ERRIND,IDUM1,THISED,IDUM2,
     1                  RDUM1,RDUM2,RDUM3, IDUM3)
            CALL CHKINQ ('pqedf', ERRIND)
            LEDTYP(IX) = THISED
         ELSE
            LEDTYP(IX) = LEDTYP(IX-DSEDGE)
         ENDIF
100   CONTINUE

C  get alternative edgewidth scale values:
C  altew1, altew2 =  max, min edgewidth scale factor
      ALTEW1 = MAXEW/NOMEW
      ALTEW2 = MINEW/NOMEW

C  but, altew1 should not exceed .05 (WC) to avoid overlap - distance
C  between edges will be 1/15 = .06666
      ALTEW1 = MIN(ALTEW1,(0.0666-0.05)/(NOMEW * WCPDC))

C  if default (1.0) is near altew1 or altew2, set alternate so as to
C  maximize the smallest gap among altew1, altew2, and 1.0:
      AVG1 = (ALTEW1 + 1) / 2
      AVG2 = (ALTEW2 + 1) / 2
      IF (ABS(ALTEW1-1) .LT. ABS(AVG2-1)) THEN
         ALTEW1 = AVG2
      ELSEIF (ABS(ALTEW2-1) .LT. ABS(AVG1-1)) THEN
         ALTEW2 = AVG1
      ENDIF

C  call DISCOL to try to get 5 distinct foreground colors,
C  returning fcol = actual number of foreground colors
      CALL DISCOL (5, WKID, FCOL)
      CALL SETVAL ('1,2,3,4,5', COLIND)

C  if (fcol < 5)  copy 1st valid part of list to tail of list
      IF (FCOL .LT. 5) THEN
         IY = 1
         DO 300 IX = FCOL+1, 5
            COLIND(IX) = COLIND(IY)
            IY = IY+1
300      CONTINUE
      ENDIF

C  set up bundles 1-5
      CALL PSEDR (WKID, 1, EDFLG(1), LEDTYP(1), 1.0,    COLIND(1))
      CALL PSEDR (WKID, 2, EDFLG(2), LEDTYP(2), ALTEW1, COLIND(2))
      CALL PSEDR (WKID, 3, EDFLG(3), LEDTYP(3), ALTEW2, COLIND(3))
      CALL PSEDR (WKID, 4, EDFLG(4), LEDTYP(4), ALTEW1, COLIND(4))
      CALL PSEDR (WKID, 5, EDFLG(5), LEDTYP(5), ALTEW2, COLIND(5))

C  display 14 pairs of triangles, using bundles 1-5

C  randomize location of edges
      CALL RN1SHF (14, PERM)

C  set up CSS as described above
C  structure #101
      CALL POPST (PICSTR)
C  by convention , view #1 is for picture
      CALL PSVWI (1)
C  use bundled attributes
      CALL SETASF (PBUNDL)
C  set interior style attribute ASFs to INDIVIDUAL
      CALL PSIASF (PIS, PINDIV)
      CALL PSIASF (PICI, PINDIV)
C  set interior style = EMPTY, interior color index = 1
      CALL PSIS (PISEMP)
      CALL PSICI (1)

      CALL LOCTRI (PERM(1), XACT)
      CALL PEXST (102)
      CALL LOCTRI (PERM(9), XACT)
      CALL PSEDI (2)
      CALL LOCTRI (PERM(10), XACT)

      Z = 0.0
      U = 1.0
      FXPTY = YLOCEL (PERM(5))
      SHIFTY = YLOCEL (PERM(11)) - YLOCEL (PERM(5))
      SCALEY = (YLOCEL (PERM(12)) - YLOCEL (PERM(11))) /
     1         (YLOCEL (PERM(06)) - YLOCEL (PERM(05)))
      CALL PBLTM (Z, FXPTY, Z, SHIFTY, Z, U, SCALEY, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)

C  execute structure #104
      CALL PEXST (104)
C  now, cancel out transformation
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)
      CALL LOCTRI (PERM(13), XACT)
      CALL LOCTRI (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTRI (PERM(2), XACT)
      CALL PSEDI (3)
      CALL PEXST (103)
      CALL LOCTRI (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTRI (PERM(3), XACT)
      CALL PSEDI (4)
      CALL LOCTRI (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCTRI (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
      CALL LOCTRI (PERM(5), XACT)
      CALL PSEDI (5)
      CALL LOCTRI (PERM(6), XACT)
      CALL PCLST

C  Expected attrubutes:   structure #105
      CALL POPST (105)

      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 400 IX = 1,14
         CALL PSEDI (EXPDX(IX))
         CALL LOCTRI (PERM(IX), XEXP)
400   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 5 6 8 9', 'The edge index should be saved and ' //
     1             'restored by <execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR EDGE INDEX: ' //
     1             'Which pair of triangles does NOT match?',
     2             14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
