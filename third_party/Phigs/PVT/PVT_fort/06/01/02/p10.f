C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/10                           *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of modelling           *
C  *                 transformation                        *
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
 
C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)
 
      INTEGER    PICSTR, TXCI, IX, PERM(14), SIZ
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4
 
      REAL       NOMMW, XLOC(1), SHIFTY, Z, U, XFORM(3,3), YLOCEL
      REAL       EXPLOC(14)
      REAL       RDUM1, RDUM2
 
      CHARACTER  QUES*63
 
      QUES = ' Which line does NOT have a single accurately ' //
     1       'circled asterisk?'
      Z = 0.0
      U = 1.0
 
      CALL INITGL ('06.01.02/10')
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
 
C  use <inquire polymarker facilities> to determine :
C     nommw = nominal marker-size (DC)
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3,
     1            NOMMW, RDUM1, RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
 
C  *** *** *** *** ***    local transformation    *** *** *** *** ***
 
C   xloc = x-MC for polymarkers, (before transformation) = 0.2
      XLOC(1) = 0.2
 
C  set up CSS:
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL RN1SHF (14, PERM)
C  polymarker style = asterisk
      CALL PSMK (PAST)
C  set marker size scale factor equivalent to WC = 0.04
      CALL PSMKSC (0.04 / (NOMMW * WCPDC))
C  polymarker #1
      CALL LOCPPM (PERM(1), XLOC)
      CALL PEXST (102)
C  polymarker #9
      CALL LOCPPM (PERM(9), XLOC)
C  postconcatenate x-shift of +0.4 to local transformation
      CALL ETR (0.4, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCPOST)
C  polymarker #10
      CALL LOCPPM (PERM(10), XLOC)
C  set global transformation to make markers #11,12 distinguishable
C    from #5,6
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      CALL ETR (Z, SHIFTY, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSGMT (XFORM)
C  execute 104
      CALL PEXST (104)
C  re-set global transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSGMT (XFORM)
C  polymarker #13
      CALL LOCPPM (PERM(13), XLOC)
C  polymarker #14
      CALL LOCPPM (PERM(14), XLOC)
C  execute 105
      CALL PEXST (105)
      CALL PCLST
 
C  structure #102
      CALL POPST (102)
C  polymarker #2
      CALL LOCPPM (PERM(2), XLOC)
C  replace x-shift of +0.1 for local transformation
      CALL ETR (0.1, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  execute 103
      CALL PEXST (103)
C  polymarker #8
      CALL LOCPPM (PERM(8), XLOC)
      CALL PCLST
 
C  structure #103
      CALL POPST (103)
C  polymarker #3
      CALL LOCPPM (PERM(3), XLOC)
C  preconcatenate x-shift of +0.1 to local transformation
      CALL ETR (0.1, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCPRE)
C  polymarker #4
      CALL LOCPPM (PERM(4), XLOC)
C  execute 104
      CALL PEXST (104)
C  polymarker #7
      CALL LOCPPM (PERM(7), XLOC)
      CALL PCLST
 
C  structure #104
      CALL POPST (104)
C  polymarker #5 / #11
      CALL LOCPPM (PERM(5), XLOC)
C  postconcatenate x-shift of +0.1 to local transformation
      CALL ETR (0.1, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCPOST)
C  polymarker #6 / #12
      CALL LOCPPM (PERM(6), XLOC)
      CALL PCLST
 
C  structure #105
      CALL POPST (105)
C  set marker style = circle
      CALL PSMK (POMARK)
C  set marker size scale factor equivalent to WC = 0.05
      CALL PSMKSC (0.05 / (NOMMW * WCPDC))
      CALL PSPMCI (2)
C  re-set local, global transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)
      CALL PSGMT  (XFORM)
 
      CALL NUMLAB (14, .10, YLOCEL(1), 1.0/15)
      CALL SETRVS ('0.2,0.2,0.3,0.4,0.4,0.5,0.4,0.3,0.2,0.6,0.6,' //
     1             '0.7,0.6,0.5', EXPLOC, SIZ)
      DO 150 IX = 1,SIZ
         CALL LOCPPM (PERM(IX), EXPLOC(IX))
150   CONTINUE
      CALL PCLST
 
      CALL SETMSG ('4 7 8 16 17 18 19 20 21 22', 'The current local ' //
     1             'transformation should be saved and restored by '  //
     2             '<execute structure> during traversal.')
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR LOCAL '  //
     1             'TRANSFORMATION:' // QUES, 14, PERM(14))
 
C  *** *** *** *** ***    global transformation    *** *** *** *** ***
 
C  clear the decks
      DO 200 IX = 101, 105
         CALL PEMST (IX)
200   CONTINUE
 
      XLOC(1) = 0.2
      CALL RN1SHF (14, PERM)
C  structure #101
      CALL POPST (PICSTR)
      CALL PSVWI (1)
      CALL SETASF (PINDIV)
C  polymarker style = asterisk
      CALL PSMK (PAST)
C  set marker size scale factor equivalent to WC = 0.04
      CALL PSMKSC (0.04 / (NOMMW * WCPDC))
C  polymarker #1
      CALL LOCPPM (PERM(1), XLOC)
C  execute 102
      CALL PEXST (102)
C  polymarker #9
      CALL LOCPPM (PERM(9), XLOC)
C  replace global transformation with x-shift of +0.4
      CALL ETR (0.4, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSGMT (XFORM)
C  polymarker #10
      CALL LOCPPM (PERM(10), XLOC)
C  set local transformation to make markers #11,12 distinguishable
C  from #5,6
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      CALL ETR (Z, SHIFTY, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  execute 104
      CALL PEXST (104)
C  re-set local transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)
C  polymarker #13
      CALL LOCPPM (PERM(13), XLOC)
C  polymarker #14
      CALL LOCPPM (PERM(14), XLOC)
C  execute 105
      CALL PEXST (105)
      CALL PCLST
 
C  structure #102
      CALL POPST (102)
C  polymarker #2
      CALL LOCPPM (PERM(2), XLOC)
C  replace global transformation with x-shift of +0.1
      CALL ETR (0.1, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSGMT (XFORM)
C  execute 103
      CALL PEXST (103)
C  polymarker #8
      CALL LOCPPM (PERM(8), XLOC)
      CALL PCLST
 
C  structure #103
      CALL POPST (103)
C  polymarker #3
      CALL LOCPPM (PERM(3), XLOC)
C  replace global transformation with x-shift of +0.2
      CALL ETR (0.2, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSGMT (XFORM)
C  polymarker #4
      CALL LOCPPM (PERM(4), XLOC)
C  execute 104
      CALL PEXST (104)
C  polymarker #7
      CALL LOCPPM (PERM(7), XLOC)
      CALL PCLST
 
C  structure #104
      CALL POPST (104)
C  polymarker #5 / #11
      CALL LOCPPM (PERM(5), XLOC)
C  replace global transformation with x-shift of +0.3
      CALL ETR (0.3, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSGMT (XFORM)
C  polymarker #6 / #12
 
C  Usually for inheritance tests, this would explicitly draw
C  something only at location PERM(6), and rely on a transformation
C  passed down from #101 to move it to location PERM(12) on the
C  second invocation.  However, since that inheritance gets done by
C  setting the global transformation to the old composite
C  transformation, and since we need to set the global
C  transformation explicitly, this is the one case where that trick
C  won't work; so we have to render explicitly at location 6 and 12
C  both times; otherwise, we'd just get location 6.
 
      CALL LOCPPM (PERM (6), XLOC)
      CALL LOCPPM (PERM(12), XLOC)
      CALL PCLST
 
C  structure #105
      CALL POPST (105)
C  set marker style = circle
      CALL PSMK (POMARK)
C  set marker size scale factor equivalent to WC = 0.05
      CALL PSMKSC (0.05 / (NOMMW * WCPDC))
      CALL PSPMCI (2)
C  re-set global transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSGMT (XFORM)
 
      CALL NUMLAB (14, .10, YLOCEL(1), 1.0/15)
 
      CALL SETRVS ('0.2,0.2,0.3,0.4,0.4,0.5,0.4,0.3,0.2,0.6,0.6,' //
     1             '0.5,0.6,0.5', EXPLOC, SIZ)
      DO 250 IX = 1,SIZ
         CALL LOCPPM (PERM(IX), EXPLOC(IX))
250   CONTINUE
 
      CALL PCLST
 
      CALL SETMSG ('12 15 16 17 18 19 20 21 22', 'The current ' //
     1             'global transformation should be saved and ' //
     2             'restored by <execute structure> during '    //
     3             'traversal.')
      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR GLOBAL '  //
     1             'TRANSFORMATION:' // QUES, 14, PERM(14))
 
C  *** *** *** *** ***    composite transformation    *** *** *** *** ***
 
      DO 300 IX = 101, 105
         CALL PEMST (IX)
300   CONTINUE
 
      XLOC(1) = 0.1
      CALL RN1SHF (14, PERM)
 
C  structure #101
      CALL POPST (PICSTR)
      CALL PSVWI (1)
      CALL SETASF (PINDIV)
C  polymarker style = asterisk
      CALL PSMK (PAST)
C  set marker size scale factor equivalent to WC = 0.04
      CALL PSMKSC (0.04 / (NOMMW * WCPDC))
C  set global transformation = scale X by 1.5
      CALL ESC (1.5, U, XFORM)
      CALL CHKINQ ('esc', ERRIND)
      CALL PSGMT (XFORM)
C  set local transformation  = scale X by 4
      CALL ESC (4.0, U, XFORM)
      CALL CHKINQ ('esc', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  polymarker #1
      CALL LOCPPM (PERM(1), XLOC)
C  execute 102
      CALL PEXST (102)
C  polymarker #9
      CALL LOCPPM (PERM(9), XLOC)
C  replace local transformation with x-shift of +0.1
      CALL ETR (0.1, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  polymarker #10
      CALL LOCPPM (PERM(10), XLOC)
C  set local transformation to make markers #11,12 distinguishable
C    from #5,6: preconcatenate appropriate y-shift
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      CALL ETR (Z, SHIFTY, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCPRE)
C  execute 104
      CALL PEXST (104)
C  re-set local transformation: preconcatenate negative y-shift
      CALL ETR (Z, -SHIFTY, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCPRE)
C  polymarker #13
      CALL LOCPPM (PERM(13), XLOC)
C  polymarker #14
      CALL LOCPPM (PERM(14), XLOC)
C  execute 105
      CALL PEXST (105)
      CALL PCLST
 
C  structure #102
      CALL POPST (102)
C  polymarker #2
      CALL LOCPPM (PERM(2), XLOC)
C  set global transformation = scale X by 8
      CALL ESC (8., U, XFORM)
      CALL CHKINQ ('esc', ERRIND)
      CALL PSGMT (XFORM)
C  execute 103
      CALL PEXST (103)
C  polymarker #8
      CALL LOCPPM (PERM(8), XLOC)
      CALL PCLST
 
C  structure #103
      CALL POPST (103)
C  polymarker #3
      CALL LOCPPM (PERM(3), XLOC)
C  set local transformation = shift X by -0.05
      CALL ETR (-0.05, Z, XFORM)
      CALL CHKINQ ('etr', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  polymarker #4
      CALL LOCPPM (PERM(4), XLOC)
C  execute 104
      CALL PEXST (104)
C  postconcatenate to local transformation: scale X by 1.4
      CALL ESC (1.4, U, XFORM)
      CALL CHKINQ ('esc', ERRIND)
      CALL PSLMT (XFORM, PCPOST)
C  polymarker #7
      CALL LOCPPM (PERM(7), XLOC)
      CALL PCLST
 
C  structure #104
      CALL POPST (104)
C  polymarker #5 / #11
      CALL LOCPPM (PERM(5), XLOC)
C  set local transformation = scale X by 0.8
      CALL ESC (0.8, U, XFORM)
      CALL CHKINQ ('esc', ERRIND)
      CALL PSLMT (XFORM, PCREPL)
C  polymarker #6 / #12
      CALL LOCPPM (PERM(6), XLOC)
      CALL PCLST
 
C  structure #105
      CALL POPST (105)
C  set marker style = circle
      CALL PSMK (POMARK)
C  set marker size scale factor equivalent to WC = 0.05
      CALL PSMKSC (0.05 / (NOMMW * WCPDC))
      CALL PSPMCI (2)
C  re-set global transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSGMT (XFORM)
 
      CALL NUMLAB (14, 0.1, YLOCEL(1), 1.0/15)
      CALL SETRVS ('0.6,0.6,0.8,0.4,0.4,0.24,0.56,0.8,0.6,0.3,' //
     1             '0.3,0.27,0.3,0.27', EXPLOC, SIZ)
      DO 350 IX = 1,SIZ
         CALL LOCPPM (PERM(IX), EXPLOC(IX))
350   CONTINUE
      CALL PCLST
 
      CALL SETMSG ('4 8 12 15 16 17 18 19 20 21 22', 'For an '       //
     1             'executed structure, its global transformation '  //
     2             'should be initialized to the composite '         //
     3             'transformation of the invoking structure and '   //
     4             'its local transformation should be initialized ' //
     5             'to the identity transformation.')
 
      CALL DCHPFV ('INHERITANCE OF MODELLING TRANSFORMATIONS:' // QUES,
     1             14, PERM(14))
 
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
