C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.01/04                        *
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
 
      INTEGER      PERM(14), PICSTR, TXCI, NUMMW, IX, FCOL, CBASE
      INTEGER      COLIND(0:10), EXPBAS(14)
      INTEGER      IDUM1,IDUM2,IDUM3
 
      REAL         NOMMW,MINMW,MAXMW, ALTMW1,ALTMW2, NOLAP
      REAL         FXPTY,SCALEY,SHIFTY, Z,U, YLOCEL, AVG1,AVG2
      REAL         XACT(5),XEXP(5),XFORM(3,3)
 
 
      DATA   COLIND / 1,2,3,4,5,6,7,8,9,10,11 /
      DATA   EXPBAS / 0,0,2,3,3,4,3,2,0,1,1,4,1,2 /
 
      CALL INITGL ('04.02.02.01/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
 
C  *** *** ***   inheritance for marker type and marker size *** ***
 
C  use <inquire polymarker facilities> to determine:
C    nummw  = number of available marker-sizes
C    nommw  = nominal marker-size (DC)
C    minmw,maxmw = minimum,maximum marker-size (DC)
      CALL PQPMF (SPECWT,0, ERRIND, IDUM1,IDUM2,
     1            NUMMW,NOMMW,MINMW,MAXMW, IDUM3 )
      CALL CHKINQ ('pqpmf', ERRIND)
 
C  nolap = .05 = distance between lines will be 1/15 - to avoid overlap
      NOLAP = 0.05 / (NOMMW * WCPDC)
C  get alternative marker size scale factor values:
C  make sure ALTMW1 < NOLAP
      ALTMW1 = MIN (MAXMW/NOMMW, NOLAP)
      ALTMW2 = QVIS / NOMMW
 
C  if default (1.0) is near altmw1 or altmw2, set alternate so as to
C  maximize the smallest gap among altmw1, altmw2, and 1.0:
      AVG1 = (ALTMW1 + 1) / 2
      AVG2 = (ALTMW2 + 1) / 2
      IF (ABS(ALTMW1-1) .LT. ABS(AVG2-1)) THEN
         ALTMW1 = AVG2
      ELSEIF (ABS(ALTMW2-1) .LT. ABS(AVG1-1)) THEN
         ALTMW2 = AVG1
      ENDIF
 
C  randomize order of polymarkers:
      CALL RNPERM (14, PERM)
C  x-location of actual/expected markers:
      XACT(1) = .35
      XEXP(1) = .50
 
C  set up CSS:
 
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  polymarker 1
      CALL LOCPPM (PERM(1), XACT)
      CALL PEXST (102)
C  polymarker 9
      CALL LOCPPM (PERM(9), XACT)
C  change-attributes: marker type=2, marker size=altmw1
C  do not use marker type 1 (dot)
      CALL PSMK   (2)
      CALL PSMKSC (ALTMW1)
C  polymarker 10
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
C  polymarker 13
      CALL LOCPPM (PERM(13), XACT)
C  polymarker 14
      CALL LOCPPM (PERM(14), XACT)
C  execute 105 for expected values
      CALL PEXST (105)
      CALL PCLST
 
      CALL POPST (102)
C  polymarker 2
      CALL LOCPPM (PERM(2), XACT)
C  change-attributes: marker type=5, marker size=altmw2
      CALL PSMK   (5)
      CALL PSMKSC (ALTMW2)
C  execute 103
      CALL PEXST (103)
C  polymarker 8
      CALL LOCPPM (PERM(8), XACT)
      CALL PCLST
 
      CALL POPST (103)
C  polymarker 3
      CALL LOCPPM (PERM(3), XACT)
C  change-attributes: marker type=4, marker size=altmw1
      CALL PSMK   (4)
      CALL PSMKSC (ALTMW1)
C  polymarker 4
      CALL LOCPPM (PERM(4), XACT)
C  execute 104
      CALL PEXST (104)
C  polymarker 7
      CALL LOCPPM (PERM(7), XACT)
      CALL PCLST
 
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCPPM (PERM(5), XACT)
C  change-attributes: marker type=2, marker size=altmw2
      CALL PSMK   (2)
      CALL PSMKSC (ALTMW2)
C  polymarker 6 / 12
      CALL LOCPPM (PERM(6), XACT)
      CALL PCLST
 
C  Expected attributes (except #14, whose actual marker type should be 2)
      CALL POPST (105)
      CALL EXPPPM (PERM(01), XEXP, 3, 1.0)
      CALL EXPPPM (PERM(02), XEXP, 3, 1.0)
      CALL EXPPPM (PERM(03), XEXP, 5, ALTMW2)
      CALL EXPPPM (PERM(04), XEXP, 4, ALTMW1)
      CALL EXPPPM (PERM(05), XEXP, 4, ALTMW1)
      CALL EXPPPM (PERM(06), XEXP, 2, ALTMW2)
      CALL EXPPPM (PERM(07), XEXP, 4, ALTMW1)
      CALL EXPPPM (PERM(08), XEXP, 5, ALTMW2)
      CALL EXPPPM (PERM(09), XEXP, 3, 1.0)
      CALL EXPPPM (PERM(10), XEXP, 2, ALTMW1)
      CALL EXPPPM (PERM(11), XEXP, 2, ALTMW1)
      CALL EXPPPM (PERM(12), XEXP, 2, ALTMW2)
      CALL EXPPPM (PERM(13), XEXP, 2, ALTMW1)
      CALL EXPPPM (PERM(14), XEXP, 4, ALTMW1)
C  draw labels
      CALL NUMLAB (14, .25, YLOCEL(1), 1.0/15)
      CALL PCLST
 
C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same random order on right side of picture, except for polymarker
C  14 which is deliberately drawn with different attributes. This
C  should be the only non-matching pair in the picture.
 
      CALL SETMSG ('3 5 6 11 12 14 15 18 19', 'The marker type '    //
     1             'and marker size attributes for the polymarker ' //
     2             'primitive should be saved and restored by '     //
     3             '<execute structure> during traversal.')
 
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR MARKER TYPE ' //
     1             'AND MARKER SIZE: Which pair of markers does '   //
     2             'NOT match?', 14, PERM(14))
 
C  *** *** ***   inheritance for polymarker color index   *** *** ***
 
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
 
C  set up PERM to randomize position of polymarkers
      CALL RNPERM (14, PERM)
      CBASE = 0
 
C  set up CSS:
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  set marker type = 3; set marker size = NOLAP (.05 in WC)
      CALL PSMK (3)
      CALL PSMKSC (NOLAP)
C  polymarker 1
      CALL LOCPPM (PERM(1), XACT)
      CALL PEXST (102)
C  polymarker 9
      CALL LOCPPM (PERM(9), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPMCI (COLIND (MOD(CBASE, FCOL)))
C  polymarker 10
      CALL LOCPPM (PERM(10), XACT)
 
C  Tricky code here: see comments above under marker type
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
C  polymarker 13
      CALL LOCPPM (PERM(13), XACT)
C  polymarker 14
      CALL LOCPPM (PERM(14), XACT)
 
C  execute 105 for expected values
      CALL PEXST (105)
      CALL PCLST
 
      CALL POPST (102)
C  polymarker 2
      CALL LOCPPM (PERM(2), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPMCI (COLIND (MOD(CBASE, FCOL)))
C  execute 103
      CALL PEXST (103)
C  polymarker 8
      CALL LOCPPM (PERM(8), XACT)
      CALL PCLST
 
      CALL POPST (103)
C  polymarker 3
      CALL LOCPPM (PERM(3), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPMCI (COLIND (MOD(CBASE, FCOL)))
C  polymarker 4
      CALL LOCPPM (PERM(4), XACT)
C  execute 104
      CALL PEXST (104)
C  polymarker 7
      CALL LOCPPM (PERM(7), XACT)
      CALL PCLST
 
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCPPM (PERM(5), XACT)
C  increment cbase
      CBASE = CBASE+1
C  change-attributes: use colind(cbase mod fcol) for next color index
      CALL PSPMCI (COLIND (MOD(CBASE, FCOL)))
C  polymarker 6 / 12
      CALL LOCPPM (PERM(6), XACT)
      CALL PCLST
 
C  Expected attributes (except #14, whose actual color should be
C  same as #13):
      CALL POPST (105)
C  color index = 1 or colind(cbase mod fcol)
C  polymarker 1:14 gets cbase = 0,0,2,3,3,4,3,2,0,1,1,4,1,2
 
C  draw labels
      CALL NUMLAB (14, .25, YLOCEL(1), 1.0/15)
 
      DO 210 IX = 1,14
         CALL PSPMCI (COLIND (MOD(EXPBAS(IX), FCOL)))
         CALL LOCPPM (PERM(IX), XEXP)
210   CONTINUE
      CALL PCLST
 
      CALL SETMSG ('3 21 22 24 25', 'The polymarker color index '   //
     1             'attribute for the polymarker primitive should ' //
     2             'be saved and restored by <execute structure> '  //
     3             'during traversal.')
 
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR POLYMARKER ' //
     1             'COLOR INDEX: Which pair of markers does NOT '  //
     2             'match?', 14, PERM(14))
 
666   CONTINUE
C  wrap it up.
      CALL ENDIT
 
      END
