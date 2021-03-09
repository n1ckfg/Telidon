C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.01/03                           *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of ASFs                *
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

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

      INTEGER    PEDT,     PEWSC,    PEDCI
      PARAMETER (PEDT=15,  PEWSC=16, PEDCI=17)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

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

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER    PICSTR, TXCI, IX, NDISCT, INDMRK,BUNMRK, ASFDEF,OPPDEF
      INTEGER    RNDINT, OPANS, SIZ, NIS, THISIS, COLIA(2,2), IIX1,IIX2
      INTEGER    INDVAL(2), ASFTAB(5, PLN:PEDCI), PERM(14), EXPDX(14)
      INTEGER    INTS1,INTS2, NEDT, ED2
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4

      REAL       NOMSIZ, MKSCF, XA(10), YA(10)
      REAL       XACT(5),XEXP(5),XFORM(3,3), YLOCEL, XTXACT,XTXEXP
      REAL       RDUM1, RDUM2, RDUM3

      LOGICAL    ISAVL(PHOLLO:PISEMP)

      DATA ISAVL  / 5*.FALSE. /
      DATA INDVAL / PPLUS,POMARK /

      CALL INITGL ('04.03.01/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

C  call DISCOL to try to get 2 distinct foreground colors
      CALL DISCOL (2, WKID, NDISCT)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)

      CALL SETMSG ('5 7 8 9', 'The implementation should initialize ' //
     1             'the ASF for markertype to individual or bundled.')

C  Determine whether individual or bundled is the default (no ASFs
C    set yet):
C  indmrk = individual markertype = plus or circle, randomly
C  bunmrk = bundled markertype = circle or plus, opposite of indmrk
      INDMRK = RNDINT(0,1) * (POMARK-PPLUS) + PPLUS
      BUNMRK = POMARK + PPLUS - INDMRK
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMSIZ,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)

C  set individual attribute:
      CALL PSMK   (INDMRK)
      MKSCF = 0.1 / (NOMSIZ * WCPDC)
      CALL PSMKSC (MKSCF)
C  set bundle #1
      CALL PSPMR (WKID, 1, BUNMRK, MKSCF, 1)
      CALL PSPMI (1)

C  display a polymarker
      XA(1) = 0.5
      YA(1) = 0.5
      CALL PPM (1, XA,YA)

      CALL DCHOIC ('ASF DEFAULT: Is the displayed marker: 1-plus ' //
     1             'or 2-circle?', 0,2,OPANS)
      CALL PEMST (PICSTR)

      IF (OPANS .EQ. 0) THEN
         CALL OPFAIL
         CALL INMSG ('Skipping rest of test cases because ASF ' //
     1               'default cannot be determined.')
         GOTO 666
      ENDIF

      CALL PASS
      IF (INDVAL(OPANS) .EQ. INDMRK) THEN
         ASFDEF = PINDIV
         CALL INMSG ('Default for initial value of ASFs is INDIVIDUAL.')
      ELSE
         ASFDEF = PBUNDL
         CALL INMSG ('Default for initial value of ASFs is BUNDLED.')
      ENDIF
C  opposite of asfdef
      OPPDEF = (PBUNDL+PINDIV) - ASFDEF

C  All the rest of the test cases use same basic structure network
C  for testing inheritance.  Five (distinct if possible) values for
C  the attribute to be tested are set up and propagated throughout
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

C  *** *** ***   inheritance for polyline ASFs   *** *** ***

C  asftab = ASF table:
C        linetype    linewidth   color
C        --------    ---------   -----
C  1:    asfdef      asfdef      asfdef
C  2:    individual  bundled     individual
C  3:    oppdef      oppdef      oppdef
C  4:    bundled     individual  bundled
C  5:    asfdef      asfdef      oppdef

C  entry #1 always set to ASF default
      DO 50 IX = PLN,PEDCI
         ASFTAB (1, IX) = ASFDEF
50    CONTINUE

      ASFTAB (2, PLN  ) = PINDIV
      ASFTAB (2, PLWSC) = PBUNDL
      ASFTAB (2, PPLCI) = PINDIV

      ASFTAB (3, PLN  ) = OPPDEF
      ASFTAB (3, PLWSC) = OPPDEF
      ASFTAB (3, PPLCI) = OPPDEF

      ASFTAB (4, PLN  ) = PBUNDL
      ASFTAB (4, PLWSC) = PINDIV
      ASFTAB (4, PPLCI) = PBUNDL

      ASFTAB (5, PLN  ) = ASFDEF
      ASFTAB (5, PLWSC) = ASFDEF
      ASFTAB (5, PPLCI) = OPPDEF

C  PICSTR has been emptied - start over
      CALL PSVWI (1)

      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMSIZ,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)

C  x-location of actual/expected polylines
      CALL SETRVS ('0.2, 0.5', XACT, SIZ)
      CALL SETRVS ('0.6, 0.9', XEXP, SIZ)

C  randomize order of polylines
      CALL RN1SHF (14, PERM)

C  Make individual and bundled as distinct as possible:
C  set individual attributes:
      CALL PSLN   (PLDOT)
      CALL PSLWSC (0.03 / (NOMSIZ*WCPDC))
      CALL PSPLCI (1)
C  set bundle #1:
      CALL PSPLR (WKID, 1, PLDASH, 0.001 / (NOMSIZ*WCPDC), 2)
      CALL PSPLI (1)

      CALL LOCPPL (PERM(1), XACT)
      CALL PEXST  (102)
      CALL LOCPPL (PERM(9), XACT)
      CALL ASFSET (2, ASFTAB, PLN,PPLCI)
      CALL LOCPPL (PERM(10), XACT)
      CALL XFINH  (PERM)

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
      CALL ASFSET (3, ASFTAB, PLN,PPLCI)
      CALL PEXST (103)
      CALL LOCPPL (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCPPL (PERM(3), XACT)
      CALL ASFSET (4, ASFTAB, PLN,PPLCI)
      CALL LOCPPL (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCPPL (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polyline 5 / 11
      CALL LOCPPL (PERM(5), XACT)
      CALL ASFSET (5, ASFTAB, PLN,PPLCI)
C  polyline 6 / 12
      CALL LOCPPL (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected ASFs:
C  last "incorrect" index set to 4, rather than 3, because
C  #2 and #4 are guaranteed to differ in linetype, which
C  in turn, is guaranteed to be distinct
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 100 IX =1,14
         CALL ASFSET (EXPDX(IX), ASFTAB, PLN,PPLCI)
         CALL LOCPPL (PERM(IX), XEXP)
100   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The polyline ASFs should ' //
     1             'be saved and restored by <execute structure> '  //
     2             'during traversal.')
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR POLYLINE ' //
     1             'ASFS: which pair of lines does NOT match?',
     2             14, PERM(14))

C  *** *** ***   inheritance for polymarker ASFs   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  asftab = ASF table:
C        markertype    markerwidth   color
C        --------      ---------     -----
C  1:    asfdef        asfdef        asfdef
C  2:    individual    bundled       individual
C  3:    oppdef        oppdef        oppdef
C  4:    bundled       individual    bundled
C  5:    asfdef        asfdef        oppdef

C  entry #1 always set to ASF default

      ASFTAB (2, PMK  ) = PINDIV
      ASFTAB (2, PMKSC) = PBUNDL
      ASFTAB (2, PPMCI) = PINDIV

      ASFTAB (3, PMK  ) = OPPDEF
      ASFTAB (3, PMKSC) = OPPDEF
      ASFTAB (3, PPMCI) = OPPDEF

      ASFTAB (4, PMK  ) = PBUNDL
      ASFTAB (4, PMKSC) = PINDIV
      ASFTAB (4, PPMCI) = PBUNDL

      ASFTAB (5, PMK  ) = ASFDEF
      ASFTAB (5, PMKSC) = ASFDEF
      ASFTAB (5, PPMCI) = OPPDEF

C  PICSTR has been emptied - start over
      CALL POPST (101)
      CALL PSVWI (1)

      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMSIZ,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)

C  x-location of actual/expected polymarkers
      CALL SETRVS ('0.3', XACT, SIZ)
      CALL SETRVS ('0.5', XEXP, SIZ)

C  randomize order of polymarkers
      CALL RN1SHF (14, PERM)

C  Make individual and bundled as distinct as possible:
C  set individual attributes:
      CALL PSMK   (PXMARK)
      CALL PSLWSC (0.04 / (NOMSIZ*WCPDC))
      CALL PSPMCI (1)
C  set bundle #1:
      CALL PSPMR (WKID, 1, POMARK, 0.02 / (NOMSIZ*WCPDC), 2)
      CALL PSPMI (1)

      CALL LOCPPM (PERM(1), XACT)
      CALL PEXST  (102)
      CALL LOCPPM (PERM(9), XACT)
      CALL ASFSET (2, ASFTAB, PMK,PPMCI)
      CALL LOCPPM (PERM(10), XACT)
      CALL XFINH  (PERM)

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
      CALL ASFSET (3, ASFTAB, PMK,PPMCI)
      CALL PEXST (103)
      CALL LOCPPM (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCPPM (PERM(3), XACT)
      CALL ASFSET (4, ASFTAB, PMK,PPMCI)
      CALL LOCPPM (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCPPM (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCPPM (PERM(5), XACT)
      CALL ASFSET (5, ASFTAB, PMK,PPMCI)
C  polymarker 6 / 12
      CALL LOCPPM (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected ASFs:
C  last "incorrect" index set to 4, rather than 3, because
C  #2 and #4 are guaranteed to differ in markertype, which
C  in turn, is guaranteed to be distinct
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 200 IX =1,14
         CALL ASFSET (EXPDX(IX), ASFTAB, PMK,PPMCI)
         CALL LOCPPM (PERM(IX), XEXP)
200   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The polymarker ASFs should ' //
     1             'be saved and restored by <execute structure> '    //
     2             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR POLYMARKER ' //
     1             'ASFS: which pair of markers does NOT match?',
     2             14, PERM(14))

C  *** *** ***   inheritance for text ASFs   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  asftab = ASF table:
C  These are carefully arranged to maximize visible difference -
C  e.g. use STROKE a lot so that expansion and spacing have effect
C        font      precision   expansion  spacing  color
C        ----      ---------   ---------  -------  -----
C  1:    asfdef    asfdef      asfdef     asfdef   asfdef
C  2:    individ   bundled     individ    bundled  individ
C  3:    oppdef    oppdef      oppdef     oppdef   oppdef
C  4:    bundled   individ     bundled    individ  bundled
C  5:    bundled   individ     individ    individ  bundled

C  entry #1 always set to ASF default

      ASFTAB (2, PTXFN) = PINDIV
      ASFTAB (2, PTXPR) = PBUNDL
      ASFTAB (2, PCHXP) = PINDIV
      ASFTAB (2, PCHSP) = PBUNDL
      ASFTAB (2, PTXCI) = PINDIV

      ASFTAB (3, PTXFN) = OPPDEF
      ASFTAB (3, PTXPR) = OPPDEF
      ASFTAB (3, PCHXP) = OPPDEF
      ASFTAB (3, PCHSP) = OPPDEF
      ASFTAB (3, PTXCI) = OPPDEF

      ASFTAB (4, PTXFN) = PBUNDL
      ASFTAB (4, PTXPR) = PINDIV
      ASFTAB (4, PCHXP) = PBUNDL
      ASFTAB (4, PCHSP) = PINDIV
      ASFTAB (4, PTXCI) = PBUNDL

      ASFTAB (5, PTXFN) = PBUNDL
      ASFTAB (5, PTXPR) = PINDIV
      ASFTAB (5, PCHXP) = PINDIV
      ASFTAB (5, PCHSP) = PINDIV
      ASFTAB (5, PTXCI) = PBUNDL

C  PICSTR has been emptied - start over
      CALL POPST (101)
      CALL PSVWI (1)
      CALL PSCHH (0.03)
      CALL PSTXAL (PALEFT, PAHALF)

      XTXACT = 0.2
      XTXEXP = 0.6

C  Make individual and bundled as distinct as possible:
C  set individual attributes:
      CALL PSTXFN (2)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (0.7)
      CALL PSCHSP (0.3)
      CALL PSTXCI (2)

C  set bundle #1 to:
      CALL PSTXR (WKID, 1, 1, PSTRP, 1.2, -0.2, 1)
      CALL PSTXI (1)

C  randomize order of text
      CALL RN1SHF (14, PERM)

C  set up CSS as described above
      CALL LOCTXT (PERM(1), XTXACT)
      CALL PEXST  (102)
      CALL LOCTXT (PERM(9), XTXACT)
      CALL ASFSET (2, ASFTAB, PTXFN,PTXCI)
      CALL LOCTXT (PERM(10), XTXACT)
      CALL XFINH  (PERM)

C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCTXT (PERM(13), XTXACT)
      CALL LOCTXT (PERM(14), XTXACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTXT (PERM(2), XTXACT)
      CALL ASFSET (3, ASFTAB, PTXFN,PTXCI)
      CALL PEXST (103)
      CALL LOCTXT (PERM(8), XTXACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTXT (PERM(3), XTXACT)
      CALL ASFSET (4, ASFTAB, PTXFN,PTXCI)
      CALL LOCTXT (PERM(4), XTXACT)
      CALL PEXST (104)
      CALL LOCTXT (PERM(7), XTXACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCTXT (PERM(5), XTXACT)
      CALL ASFSET (5, ASFTAB, PTXFN,PTXCI)
C  polymarker 6 / 12
      CALL LOCTXT (PERM(6), XTXACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected ASFs:
C  last "incorrect" index set to 4, rather than 3, because
C  #2 and #4 are guaranteed to differ in text font, which
C  in turn, is guaranteed to be distinct
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 300 IX =1,14
         CALL ASFSET (EXPDX(IX), ASFTAB, PTXFN,PTXCI)
         CALL LOCTXT (PERM(IX), XTXEXP)
300   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The text ASFs should be ' //
     1             'saved and restored by <execute structure> '    //
     2             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR TEXT ASFS: ' //
     1             'which pair of text primitives does NOT match?',
     2             14, PERM(14))

C  *** *** ***   inheritance for interior style ASF   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  asftab = ASF table: (this combination judged most likely to catch
C    a failure)
      ASFTAB (2, PIS) = OPPDEF
      ASFTAB (3, PIS) = OPPDEF
      ASFTAB (4, PIS) = ASFDEF
      ASFTAB (5, PIS) = OPPDEF

C  PICSTR has been emptied - start over
      CALL POPST (101)
      CALL PSVWI (1)

C  Make individual and bundled as distinct as possible:
C  set individual attributes: interior style = hollow
      CALL PSIS (PHOLLO)
C  set bundle #1 to: interior style = empty
      CALL PSIR (WKID,1, PISEMP,1,2)
      CALL PSII (1)
      CALL INTINH (ASFTAB, PIS,PIS, PERM)

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The interior style ASF ' //
     1             'should be saved and restored by <execute '    //
     2             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR INTERIOR '  //
     1             'STYLE ASF: which pair of interiors does NOT ' //
     2             'match?', 14, PERM(14))

C  *** *** ***   inheritance for interior index ASF   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  check available interior styles
      CALL PQIF (SPECWT, 0,0, ERRIND, NIS, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
      DO 510 IX = 1,ABS(NIS)
         CALL PQIF (SPECWT, IX,0, ERRIND, IDUM1, THISIS,
     1              IDUM2,IDUM3,IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS.GE.PHOLLO .AND. THISIS.LE.PISEMP) THEN
            ISAVL(THISIS) = .TRUE.
         ENDIF
510   CONTINUE

C  thisis = this interior style to be used
C  iix1,iix2 = two available interior indices
      IF (ISAVL(PHATCH)) THEN
C  using HATCH - get hatch styles
         THISIS = PHATCH
         CALL PQIF (SPECWT, 0,1, ERRIND, IDUM1,IDUM2,IDUM3, IIX1, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         CALL PQIF (SPECWT, 0,2, ERRIND, IDUM1,IDUM2,IDUM3, IIX2, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
      ELSEIF (ISAVL(PPATTR)) THEN
C  using PATTERN
         THISIS = PPATTR
         CALL PSPA (0.1, 0.05)
         IIX1 = 1
         IIX2 = 2
C  set up two distinct patterns
         CALL SETVAL ('1,1,1,0', COLIA)
         CALL PSPAR (WKID,1, 2,2, 1,1, 2,2, COLIA)
         CALL SETVAL ('0,0,1,0', COLIA)
         CALL PSPAR (WKID,2, 2,2, 1,1, 2,2, COLIA)
      ELSE
C  no style sensitive to interior style index is available
         CALL INMSG ('Skipping test case for interior style index ' //
     1               'ASF, since no available interior style is '   //
     2               'sensitive to it.')
         GOTO 590
      ENDIF

C  asftab = ASF table: (this combination judged most likely to catch
C    a failure)
      ASFTAB (2, PISI) = OPPDEF
      ASFTAB (3, PISI) = OPPDEF
      ASFTAB (4, PISI) = ASFDEF
      ASFTAB (5, PISI) = OPPDEF

C  PICSTR has been emptied - start over
      CALL POPST (101)
      CALL PSVWI (1)

C  Make individual and bundled as distinct as possible:
C  set individual attributes:
      CALL PSIS  (THISIS)
      CALL PSISI (IIX1)
      CALL PSICI (1)
C  set bundle #1:
      CALL PSIR (WKID,1, THISIS, IIX2, 2)
      CALL PSII (1)

      CALL INTINH (ASFTAB, PISI,PISI, PERM)

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The interior style index ' //
     1             'ASF should be saved and restored by <execute '  //
     2             'structure> during traversal.')
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR INTERIOR '    //
     1             'STYLE INDEX ASF: which pair of interiors does ' //
     2             'NOT match?', 14, PERM(14))

C  end_int_index:
590   CONTINUE

C  *** *** ***   inheritance for interior color ASF   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  ints1,2 = 1st,2nd interior style
      INTS1 = PHOLLO
      IF (ISAVL(PSOLID)) THEN
         INTS2 = PSOLID
      ELSEIF (ISAVL(PHATCH)) THEN
         INTS2 = PHATCH
         CALL PQIF (SPECWT, 0,1, ERRIND, IDUM1,IDUM2,IDUM3, IIX1, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
      ELSE
         INTS2 = PHOLLO
      ENDIF

C  asftab = ASF table:
C        style       color
C        -----       -----
C  1:    asfdef      asfdef
C  2:    asfdef      oppdef
C  3:    oppdef      oppdef
C  4:    oppdef      asfdef
C  5:    oppdef      oppdef
      ASFTAB (2, PIS)  = ASFDEF
      ASFTAB (2, PICI) = OPPDEF

      ASFTAB (3, PIS)  = OPPDEF
      ASFTAB (3, PICI) = OPPDEF

      ASFTAB (4, PIS)  = OPPDEF
      ASFTAB (4, PICI) = ASFDEF

      ASFTAB (5, PIS)  = OPPDEF
      ASFTAB (5, PICI) = OPPDEF

C  PICSTR has been emptied - start over
      CALL POPST (101)
      CALL PSVWI (1)

C  Make individual and bundled as distinct as possible:
C  set individual attributes:
      CALL PSIS  (INTS1)
      CALL PSISI (IIX1)
      IF (NDISCT .GT. 1) THEN
         CALL PSICI (2)
      ELSE
         CALL PSICI (0)
      ENDIF
C  set bundle #1:
      CALL PSIR (WKID,1, INTS2, IIX1,1)
      CALL PSII (1)

      CALL INTINH (ASFTAB, PIS,PICI, PERM)

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The interior colour ASF ' //
     1             'should be saved and restored by <execute '     //
     2             'structure> during traversal.')
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR INTERIOR '     //
     1             'COLOUR INDEX ASF: which pair of interiors does ' //
     2             'NOT match?', 14, PERM(14))

C  *** *** ***   inheritance for edge flag ASF   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)

C  asftab = ASF table: (this combination judged most likely to catch
C    a failure)
      ASFTAB (2, PEDFG) = OPPDEF
      ASFTAB (3, PEDFG) = OPPDEF
      ASFTAB (4, PEDFG) = ASFDEF
      ASFTAB (5, PEDFG) = OPPDEF

C  PICSTR has been emptied - start over
      CALL POPST (101)
      CALL PSVWI (1)

C  set interior style = EMPTY
      CALL PSIASF (PIS, PINDIV)
      CALL PSIS   (PISEMP)

C  Make individual and bundled as distinct as possible:
C  set individual attributes: edge flag=ON
      CALL PSEDFG (PON)
C  set bundle #1
      CALL PSEDR (WKID, 1, POFF, 1, 1.0, 1)
      CALL PSEDI (1)

C  x-location of actual/expected interiors
      CALL SETRVS ('0.2,0.2,0.5', XACT, SIZ)
      CALL SETRVS ('0.6,0.6,0.9', XEXP, SIZ)

C  randomize order of interiors
      CALL RN1SHF (14, PERM)

C  set up CSS as described above
      CALL LOCTRI (PERM(1), XACT)
      CALL PEXST  (102)
      CALL LOCTRI (PERM(9), XACT)
      CALL ASFSET (2, ASFTAB, PEDFG,PEDFG)
      CALL LOCTRI (PERM(10), XACT)
      CALL XFINH  (PERM)

C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCTRI (PERM(13), XACT)
      CALL LOCTRI (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTRI (PERM(2), XACT)
      CALL ASFSET (3, ASFTAB, PEDFG,PEDFG)
      CALL PEXST (103)
      CALL LOCTRI (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTRI (PERM(3), XACT)
      CALL ASFSET (4, ASFTAB, PEDFG,PEDFG)
      CALL LOCTRI (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCTRI (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCTRI (PERM(5), XACT)
      CALL ASFSET (5, ASFTAB, PEDFG,PEDFG)
C  polymarker 6 / 12
      CALL LOCTRI (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected ASFs:
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 400 IX =1,14
         CALL ASFSET (EXPDX(IX), ASFTAB, PEDFG,PEDFG)
         CALL LOCTRI (PERM(IX), XEXP)
400   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The edge flag ASF should ' //
     1             'be saved and restored by <execute structure> '  //
     2             'during traversal.')
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR EDGE FLAG ' //
     1             'ASF: which pair of edges does NOT match?',
     2             14, PERM(14))

C  *** *** ***   inheritance for edge aspects ASFs   *** *** ***

C  clear the decks
      CALL PEMST (101)
      CALL PEMST (102)
      CALL PEMST (103)
      CALL PEMST (104)
      CALL PEMST (105)
C
C  asftab = ASF table:
C        edgetype    edgewidth   color
C        --------    ---------   -----
C  1:    asfdef      asfdef      asfdef
C  2:    individual  bundled     individual
C  3:    oppdef      oppdef      oppdef
C  4:    bundled     individual  bundled
C  5:    asfdef      asfdef      oppdef

      ASFTAB (2, PEDT ) = PINDIV
      ASFTAB (2, PEWSC) = PBUNDL
      ASFTAB (2, PEDCI) = PINDIV

      ASFTAB (3, PEDT ) = OPPDEF
      ASFTAB (3, PEWSC) = OPPDEF
      ASFTAB (3, PEDCI) = OPPDEF

      ASFTAB (4, PEDT ) = PBUNDL
      ASFTAB (4, PEWSC) = PINDIV
      ASFTAB (4, PEDCI) = PBUNDL

      ASFTAB (5, PEDT ) = ASFDEF
      ASFTAB (5, PEWSC) = ASFDEF
      ASFTAB (5, PEDCI) = OPPDEF


C  PICSTR has been emptied - start over
      CALL POPST (101)
      CALL PSVWI (1)

C  set interior style = EMPTY, edge flag = ON
      CALL PSIASF (PIS, PINDIV)
      CALL PSIS   (PISEMP)
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (PON)

C  try to get non-1 edgetype:
      CALL PQEDF (SPECWT, 0, ERRIND, NEDT,IDUM2,IDUM3,
     1            NOMSIZ,RDUM2,RDUM3, IDUM4)
      CALL CHKINQ ('pqedf', ERRIND)
      NEDT = ABS(NEDT)
      DO 610 IX = 1,NEDT
         CALL PQEDF (SPECWT, IX, ERRIND, IDUM1,ED2,IDUM2,
     1               RDUM1,RDUM2,RDUM3, IDUM4)
         CALL CHKINQ ('pqedf', ERRIND)
         IF (ED2 .NE. 1) GOTO 620
610   CONTINUE
620   CONTINUE

C  Make individual and bundled as distinct as possible:
C  set individual attributes:
      CALL PSEDT  (1)
      CALL PSEWSC (0.01 / (NOMSIZ*WCPDC))
      CALL PSEDCI (1)
C  set bundle #1 to:
      CALL PSEDR (WKID, 1, PON, ED2, 0.001 / (NOMSIZ*WCPDC), 2)
      CALL PSEDI (1)

C  randomize order of interiors
      CALL RN1SHF (14, PERM)

C  set up CSS as described above
      CALL LOCTRI (PERM(1), XACT)
      CALL PEXST  (102)
      CALL LOCTRI (PERM(9), XACT)
      CALL ASFSET (2, ASFTAB, PEDT,PEDCI)
      CALL LOCTRI (PERM(10), XACT)
      CALL XFINH  (PERM)

C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCTRI (PERM(13), XACT)
      CALL LOCTRI (PERM(14), XACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTRI (PERM(2), XACT)
      CALL ASFSET (3, ASFTAB, PEDT,PEDCI)
      CALL PEXST (103)
      CALL LOCTRI (PERM(8), XACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTRI (PERM(3), XACT)
      CALL ASFSET (4, ASFTAB, PEDT,PEDCI)
      CALL LOCTRI (PERM(4), XACT)
      CALL PEXST (104)
      CALL LOCTRI (PERM(7), XACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  polymarker 5 / 11
      CALL LOCTRI (PERM(5), XACT)
      CALL ASFSET (5, ASFTAB, PEDT,PEDCI)
C  polymarker 6 / 12
      CALL LOCTRI (PERM(6), XACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected ASFs:
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 600 IX =1,14
         CALL ASFSET (EXPDX(IX), ASFTAB, PEDT,PEDCI)
         CALL LOCTRI (PERM(IX), XEXP)
600   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('4 5 6 7 8 9 10 11', 'The edge ASFs should be ' //
     1             'saved and restored by <execute structure> ' //
     2             'during traversal.')
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR EDGE ASFS: ' //
     1             'which pair of edges does NOT match?', 14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
