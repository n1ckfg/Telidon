C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/12                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of polyline index      *
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

      INTEGER      PERM(14), PICSTR, TXCI, NUMLW, IX, IY, FCOL
      INTEGER      COLIND(5), EXPDX(14), SIZ, NUMLT
      INTEGER      LLNTYP(5), THISLT, IDUM1, IDUM2,IDUM3

      REAL         NOMLW,MINLW,MAXLW, ALTLW1,ALTLW2
      REAL         FXPTY,SCALEY,SHIFTY, Z,U, YLOCEL, AVG1,AVG2
      REAL         XACT(2),XEXP(2),XFORM(3,3),RDUM1, RDUM2, RDUM3

      CALL INITGL ('04.02.01.02/12')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

C  x-location of actual/expected polylines
      CALL SETRVS ('0.2, 0.5', XACT, SIZ)
      CALL SETRVS ('0.6, 0.9', XEXP, SIZ)

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

C  *** *** ***   inheritance for polyline index  *** ***

      CALL PQPLF (SPECWT,0, ERRIND, NUMLT, IDUM2,
     1            NUMLW,NOMLW,MINLW,MAXLW, IDUM3 )
      CALL CHKINQ ('pqplf', ERRIND)

C  llntyp = list of 5 (possibly repeated) linetypes;
      CALL SETVAL ('1,2,3,4,1', LLNTYP)

C  look for any non-std linetype.
      DO 100 IX = 1,ABS(NUMLT)
C  get linetype from available list
         CALL PQPLF (SPECWT, IX, ERRIND, IDUM1, THISLT, IDUM2,
     1               RDUM1, RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqplf', ERRIND)
         IF (THISLT .LT. 1 .OR. THISLT .GT. 4) THEN
            LLNTYP (5) = THISLT
            GOTO 110
         ENDIF
100   CONTINUE

110   CONTINUE

C  get alternative linewidth scale factors:
C  altlw1,2 = max,min scale factor
      ALTLW1 = MAXLW/NOMLW
C  but make sure ALTLW1 < 0.05 in WC
      ALTLW1 = MIN (ALTLW1, 0.05 / (NOMLW * WCPDC) )
      ALTLW2 = MINLW/NOMLW

C  if default (1.0) is near altlw1 or altlw2, set alternate so as to
C  maximize the smallest gap among altlw1, altlw2, and 1.0:
      AVG1 = (ALTLW1 + 1) / 2
      AVG2 = (ALTLW2 + 1) / 2
      IF (ABS(ALTLW1-1) .LT. ABS(AVG2-1)) THEN
         ALTLW1 = AVG2
      ELSEIF (ABS(ALTLW2-1) .LT. ABS(AVG1-1)) THEN
         ALTLW2 = AVG1
      ENDIF

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
      CALL PSPLR (WKID, 1, LLNTYP(1), 1.0,    COLIND(1))
      CALL PSPLR (WKID, 2, LLNTYP(2), ALTLW1, COLIND(2))
      CALL PSPLR (WKID, 3, LLNTYP(3), ALTLW2, COLIND(3))
      CALL PSPLR (WKID, 4, LLNTYP(4), ALTLW1, COLIND(4))
      CALL PSPLR (WKID, 5, LLNTYP(5), ALTLW2, COLIND(5))

C  randomize order of polylines
      CALL RN1SHF (14, PERM)

C  set up CSS:
C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same order on right side of picture, expect for polyline #14
C  which is deliberately drawn with incorrect attributes.  This
C  should be the only non-matching pair in the picture.

C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use bundled attributes
      CALL SETASF (PBUNDL)

      CALL LOCPPL (PERM(1), XACT)
      CALL PEXST (102)
      CALL LOCPPL (PERM(9), XACT)
      CALL PSPLI  (2)
      CALL LOCPPL (PERM(10), XACT)

C  Tricky code here: since structure 104 is re-invoked, it
C  generates polyline #5,6 on first invocation, and 11,12
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

      CALL LOCPPL (PERM(13), XACT)
      CALL LOCPPL (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCPPL (PERM(2), XACT)
      CALL PSPLI  (3)
      CALL PEXST (103)
      CALL LOCPPL (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCPPL (PERM(3), XACT)
      CALL PSPLI  (4)
      CALL LOCPPL (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCPPL (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polyline 5 / 11
      CALL LOCPPL (PERM(5), XACT)
      CALL PSPLI  (5)
C  polyline 6 / 12
      CALL LOCPPL (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for bundle index
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 400 IX =1,14
         CALL PSPLI (EXPDX(IX))
         CALL LOCPPL (PERM(IX), XEXP)
400   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 5 6 8 9', 'The polyline index should '       //
     1             'be saved and restored by <execute structure> ' //
     2             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR POLYLINE '//
     1             'INDEX: Which pair of lines does NOT match?',
     2              14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT

      END
