C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.01/04                        *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization                        *
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

      INTEGER      PERM(14), PICSTR, TXCI, NUMLW, IX, FCOL, CBASE
      INTEGER      COLIND(0:10), EXPBAS(14)
      INTEGER      IDUM1,IDUM2,IDUM3

      REAL         NOMLW,MINLW,MAXLW, ALTLW1,ALTLW2
      REAL         FXPTY,SCALEY,SHIFTY, Z,U, YLOCEL, AVG1,AVG2
      REAL         XACT(2),XEXP(2),XFORM(3,3)

      DATA   COLIND / 1,2,3,4,5,6,7,8,9,10,11 /
      DATA   EXPBAS / 0,0,2,3,3,4,3,2,0,1,1,4,1,2 /

      CALL INITGL ('04.02.01.01/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

C  *** *** ***   inheritance for linestyle and linewidth   *** *** ***

C  use <inquire polyline facilities> to determine:
C    numlw  = number of available line-widths
C    nomlw  = nominal line-width (DC)
C    minlw,maxlw = minimum,maximum line-width (DC)
      CALL PQPLF (SPECWT,0, ERRIND, IDUM1,IDUM2,
     1            NUMLW,NOMLW,MINLW,MAXLW, IDUM3 )
      CALL CHKINQ ('pqplf', ERRIND)

C  get alternative linewidth scale factors:
C  altlw1,2 = max,min scale factor
      ALTLW1 = MAXLW/NOMLW
C  but make sure ALTLW1 .le. 0.05 in WC
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

C  randomize order of polylines:
      CALL RNPERM (14, PERM)
C  x-location of actual/expected lines:
      XACT(1) = .20
      XACT(2) = .55
      XEXP(1) = .60
      XEXP(2) = .95

C  set up CSS:

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  polyline 1
      CALL LOCPPL (PERM(1), XACT)
      CALL PEXST (102)
C  polyline 9
      CALL LOCPPL (PERM(9), XACT)
C  change-attributes: linestyle=2, linewidth=altlw1
      CALL PSLN   (2)
      CALL PSLWSC (ALTLW1)
C  polyline 10
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
C  polyline 13
      CALL LOCPPL (PERM(13), XACT)
C  polyline 14
      CALL LOCPPL (PERM(14), XACT)
C  execute 105 for expected values
      CALL PEXST (105)
      CALL PCLST

      CALL POPST (102)
C  polyline 2
      CALL LOCPPL (PERM(2), XACT)
C  change-attributes: linestyle=3, linewidth=altlw2
      CALL PSLN   (3)
      CALL PSLWSC (ALTLW2)
C  execute 103
      CALL PEXST (103)
C  polyline 8
      CALL LOCPPL (PERM(8), XACT)
      CALL PCLST

      CALL POPST (103)
C  polyline 3
      CALL LOCPPL (PERM(3), XACT)
C  change-attributes: linestyle=4, linewidth=altlw1
      CALL PSLN   (4)
      CALL PSLWSC (ALTLW1)
C  polyline 4
      CALL LOCPPL (PERM(4), XACT)
C  execute 104
      CALL PEXST (104)
C  polyline 7
      CALL LOCPPL (PERM(7), XACT)
      CALL PCLST

      CALL POPST (104)
C  polyline 5 / 11
      CALL LOCPPL (PERM(5), XACT)
C  change-attributes: linestyle=2, linewidth=altlw2
      CALL PSLN   (2)
      CALL PSLWSC (ALTLW2)
C  polyline 6 / 12
      CALL LOCPPL (PERM(6), XACT)
      CALL PCLST

C  Expected attributes (except #14, whose actual linestyle should be 2):
      CALL POPST (105)
      CALL EXPPPL (PERM(01), XEXP, 1, 1.0)
      CALL EXPPPL (PERM(02), XEXP, 1, 1.0)
      CALL EXPPPL (PERM(03), XEXP, 3, ALTLW2)
      CALL EXPPPL (PERM(04), XEXP, 4, ALTLW1)
      CALL EXPPPL (PERM(05), XEXP, 4, ALTLW1)
      CALL EXPPPL (PERM(06), XEXP, 2, ALTLW2)
      CALL EXPPPL (PERM(07), XEXP, 4, ALTLW1)
      CALL EXPPPL (PERM(08), XEXP, 3, ALTLW2)
      CALL EXPPPL (PERM(09), XEXP, 1, 1.0)
      CALL EXPPPL (PERM(10), XEXP, 2, ALTLW1)
      CALL EXPPPL (PERM(11), XEXP, 2, ALTLW1)
      CALL EXPPPL (PERM(12), XEXP, 2, ALTLW2)
      CALL EXPPPL (PERM(13), XEXP, 2, ALTLW1)
      CALL EXPPPL (PERM(14), XEXP, 4, ALTLW1)
C  draw labels

      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same random order on right side of picture, except for polyline
C  14 which is deliberately drawn with incorrect attributes. This
C  should be the only non-matching pair in the picture.

      CALL SETMSG ('3 5 6 11 12 14 15 17 18', 'The linestyle and '    //
     1             'linewidth attributes for the polyline primitive ' //
     2             'should be saved and restored by <execute '        //
     3             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR LINESTYLE AND ' //
     1             'LINEWIDTH: Which pair of lines does NOT match?',
     2              14, PERM(14))

C  *** *** ***   inheritance for polyline color index   *** *** ***

C  clear the decks
      DO 200 IX = 101,105
         CALL PEMST (IX)
200   CONTINUE

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

C  set up PERM to randomize position of polylines
      CALL RNPERM (14, PERM)
      CBASE = 0

C  set up CSS:
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  set linetype = 1; set linewidth = .05 in WC
      CALL PSLN (1)
      CALL PSLWSC (0.05 / (NOMLW * WCPDC) )
C  polyline 1
      CALL LOCPPL (PERM(1), XACT)
      CALL PEXST (102)
C  polyline 9
      CALL LOCPPL (PERM(9), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPLCI (COLIND (MOD(CBASE, FCOL)))
C  polyline 10
      CALL LOCPPL (PERM(10), XACT)

C  Tricky code here: see comments above under linestyle
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
C  polyline 13
      CALL LOCPPL (PERM(13), XACT)
C  polyline 14
      CALL LOCPPL (PERM(14), XACT)

C  execute 105 for expected values
      CALL PEXST (105)
      CALL PCLST

      CALL POPST (102)
C  polyline 2
      CALL LOCPPL (PERM(2), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPLCI (COLIND (MOD(CBASE, FCOL)))
C  execute 103
      CALL PEXST (103)
C  polyline 8
      CALL LOCPPL (PERM(8), XACT)
      CALL PCLST

      CALL POPST (103)
C  polyline 3
      CALL LOCPPL (PERM(3), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPLCI (COLIND (MOD(CBASE, FCOL)))
C  polyline 4
      CALL LOCPPL (PERM(4), XACT)
C  execute 104
      CALL PEXST (104)
C  polyline 7
      CALL LOCPPL (PERM(7), XACT)
      CALL PCLST

      CALL POPST (104)
C  polyline 5 / 11
      CALL LOCPPL (PERM(5), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPLCI (COLIND (MOD(CBASE, FCOL)))
C  polyline 6 / 12
      CALL LOCPPL (PERM(6), XACT)
      CALL PCLST

C  Expected attributes (except #14, whose actual color should be
C  same as #13):
      CALL POPST (105)
C  color index = 1 or colind(cbase mod fcol)
C  polyline 1:14 gets cbase = 0,0,2,3,3,4,3,2,0,1,1,4,1,2

      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)

      DO 210 IX = 1,14
         CALL PSPLCI (COLIND (MOD(EXPBAS(IX), FCOL)))
         CALL LOCPPL (PERM(IX), XEXP)
210   CONTINUE
      CALL PCLST

      CALL SETMSG ('3 20 21 23 24', 'The polyline color index '      //
     1             'attribute for the polyline primitive should be ' //
     2             'saved and restored by <execute structure> '      //
     3             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR POLYLINE ' //
     1             'COLOR INDEX: Which pair of lines does NOT match?',
     2              14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT

      END
