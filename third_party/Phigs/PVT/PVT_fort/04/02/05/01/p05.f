C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.01/05                        *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C edge flag indicator
      INTEGER    POFF,    PON
      PARAMETER (POFF=0, PON=1)

C edgetype  (linetype)
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

      INTEGER    PICSTR, TXCI, IX, IY, NUMSTY, NUMHAT, LSTYLE(10)
      INTEGER    LHATCH(5), PERM(20), COLIA(3,2), IARFND
      INTEGER    EXPDX(14), SIZ, THISIS, THISHT
      INTEGER    LAST, FCOL, COLIND(5), EDGFLG(5), NUMET,NUMEW
      INTEGER    LEDTYP(5), THISET
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4

      REAL       XACT(4), XEXP(4), Z,U, FXPTY,SHIFTY, YLOCEL, XFORM(3,3)
      REAL       XTACT(3), XTEXP(3), PATSZX(5), PATSZY(5)
      REAL       NOMEW,MINEW,MAXEW, EWVALS(5), MAXSC,MINSC, SCF, PI
      REAL       SCFORM(3,3), XVEC(2,5), YVEC(2,5), ZVEC(2,5), XREFPT(5)
      REAL       RECHT, ANG
      REAL       RDUM1,RDUM2,RDUM3

C  rectangle height for fill area and PI
      PARAMETER (RECHT = 0.045, PI = 3.14159254)

      CALL INITGL ('04.02.05.01/05')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

C  use <inquire interior facilities> to determine:
C    numsty = number of available interior styles
      CALL PQIF (SPECWT,0,0,ERRIND, NUMSTY,IDUM1, NUMHAT,
     1           IDUM2, IDUM3)
      CALL CHKINQ ('pqif', ERRIND)

      CALL PQEDF (SPECWT,0,ERRIND, NUMET, IDUM1, NUMEW,
     1            NOMEW, MINEW, MAXEW, IDUM4)
      CALL CHKINQ ('pqedf',ERRIND)

C  x-location of actual/expected rectangles:
      CALL SETRVS ('0.2, 0.2, 0.5, 0.5', XACT, SIZ)
      CALL SETRVS ('0.6, 0.6, 0.9, 0.9', XEXP, SIZ)

C  x-location of actual/expected triangles:
      CALL SETRVS ('0.2, 0.2, 0.45', XTACT, SIZ)
      CALL SETRVS ('0.6, 0.6, 0.85', XTEXP, SIZ)

C  All test cases use same basic structure network for testing
C  inheritance. Note that structure #104 is executed by both #103
C  and #101.
C
C     default attr
C       |
C       |
C       |                  102
C       |                 /  prim 2
C       |               /    attr #3    attr #3
C       V      attr #1/      exec 103--------------103
C     101           /        prim 8                  prim 3
C       prim 1    /                                  attr #4
C       exec 102/                                    prim 4
C       prim 9                                       exec 104\
C       attr #2                                      prim 7    \ attr #4
C       prim 10                                                  \
C       transform            attr #2                               \
C       exec 104----------------------------------------------------104
C       un-transform                                                  prim 5/11
C       prim 13                                                       attr #5
C       prim 14                                                       prim 6/12
C       exec 105---------->105
C                            expected values


C  *** *** *** ***   interior style   *** *** *** ***

C  lstyle = list of 5 (possibly repeated) available interior styles
      DO 50 IX = 1, NUMSTY
         CALL PQIF (SPECWT, IX,0,ERRIND, IDUM1, THISIS,
     1              IDUM2, IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         LSTYLE(IX) = THISIS
50    CONTINUE

C  make sure first 5 elements of LSTYLE are filled
      IY = 1
      DO 55 IX = NUMSTY+1,5
         LSTYLE(IX) = LSTYLE(IY)
         IY = IY+1
55    CONTINUE

C  put PHOLLO (default) in 1st position
      IX = IARFND(PHOLLO, NUMSTY, LSTYLE)
      IF (IX .GE. 1) THEN
         LSTYLE(IX) = LSTYLE(1)
         LSTYLE(1) = PHOLLO
      ELSE
         CALL INMSG ('HOLLOW not available - skipping test of ' //
     1               'interior style.')
         GOTO 1000
      ENDIF

C  randomize order of rectangles:
      CALL RN1SHF (14, PERM)

C  set up CSS:
C
C  Structure network #101 draws actual results in random order on
C  left side of picture.  Structure #105 draws expected results in
C  same random order on right side of picture, except for fill area
C  #14 which is deliberately drawn with incorrect attributes.  This
C  should be the only non-matching pair in the picture.

C  structure #101
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  turn off edge flag and set pattern size to reasonable value
      CALL PSEDFG (POFF)
      CALL PSPA  (0.6 * RECHT, 0.6 * RECHT)

      CALL LOCREC (PERM(1), XACT, 1)
      CALL PEXST (102)
      CALL LOCREC (PERM(9), XACT, 9)
      CALL PSIS (LSTYLE(2))
      CALL LOCREC (PERM(10), XACT, 10)

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

      CALL LOCREC (PERM(13), XACT, 13)
      CALL LOCREC (PERM(14), XACT, 14)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCREC (PERM(2), XACT, 2)
      CALL PSIS (LSTYLE(3))
      CALL PEXST (103)
      CALL LOCREC (PERM(8), XACT, 8)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCREC (PERM(3), XACT, 3)
      CALL PSIS (LSTYLE(4))
      CALL LOCREC (PERM(4), XACT, 4)
      CALL PEXST (104)
      CALL LOCREC (PERM(7), XACT, 7)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCREC (PERM(5), XACT, 5)
      CALL PSIS (LSTYLE(5))
C  fill area set 6 / 12
      CALL LOCREC (PERM(6), XACT, 6)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior styles
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 105 IX = 1,14
         CALL PSIS (LSTYLE (EXPDX(IX)))
         CALL LOCREC (PERM(IX), XEXP, IX)
105   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 7 8 16 17', 'The interior style attribute '  //
     1             'for the fill area and fill area set primitives ' //
     2             'should be saved and restored by <execute '       //
     3             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR INTERIOR ' //
     1             'STYLE: Which pair of rectangles does NOT match?',
     1             14, PERM(14))

C  *** *** *** ***   hatch index   *** *** *** ***
1000  CONTINUE

      IF (IARFND(PHATCH, NUMSTY, LSTYLE) .LE. 0) THEN
         CALL INMSG ('Hatch style unavailable - skipping test of ' //
     1               'hatch index.')
         GOTO 2000
      ENDIF

C  use <inquire interior facilities> to determine:
C    numhat = min(number of available hatch indexes, 5)
C    lhatch = list of 5 (possibly repeated) numhat hatch indexes

C get up to 5 random available hatch styles and see if #1 is available
      LHATCH(1) = 66
      LAST = 1
      DO 60 IX = 1, ABS(NUMHAT)
         CALL PQIF (SPECWT, 0,IX, ERRIND, IDUM1, IDUM2,
     1              IDUM3, THISHT, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISHT .EQ. 1) THEN
            LHATCH(1) = 1
         ELSE
            LAST = LAST+1
            LHATCH(MIN(5,LAST)) = THISHT
         ENDIF
60    CONTINUE

      IF (LHATCH(1) .NE. 1) THEN
         CALL INMSG ('Hatch style #1 unavailable - skipping test of ' //
     1               'hatch index.')
         GOTO 2000
      ENDIF

C  make sure first 5 elements of LHATCH are filled
      IY = 1
      DO 65 IX = LAST+1,5
         LHATCH(IX) = LHATCH(IY)
         IY = IY+1
65    CONTINUE

C  randomize order of rectangles:
      CALL RN1SHF (14, PERM)

C  clear and re-set up CSS:
      DO 1010 IX = 101,105
         CALL PEMST (IX)
1010  CONTINUE

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  turn off edge flag and set interior style to HATCH
      CALL PSEDFG (POFF)
      CALL PSIS   (PHATCH)

C  structure #101
      CALL LOCREC (PERM(1), XACT, 1)
      CALL PEXST (102)
      CALL LOCREC (PERM(9), XACT, 9)
      CALL PSISI (LHATCH(2))
      CALL LOCREC (PERM(10), XACT, 10)

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

      CALL LOCREC (PERM(13), XACT, 13)
      CALL LOCREC (PERM(14), XACT, 14)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCREC (PERM(2), XACT, 2)
      CALL PSISI (LHATCH(3))
      CALL PEXST (103)
      CALL LOCREC (PERM(8), XACT, 8)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCREC (PERM(3), XACT, 3)
      CALL PSISI (LHATCH(4))
      CALL LOCREC (PERM(4), XACT, 4)
      CALL PEXST (104)
      CALL LOCREC (PERM(7), XACT, 7)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCREC (PERM(5), XACT, 5)
      CALL PSISI (LHATCH(5))
C  fill area set 6 / 12
      CALL LOCREC (PERM(6), XACT, 6)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected hatch indexes, except for 14th entry
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 205 IX = 1,14
         CALL PSISI (LHATCH (EXPDX(IX)))
         CALL LOCREC (PERM(IX), XEXP, IX)
205   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 19 20 24 25', 'The hatch index attribute '   //
     1             'for the fill area and fill area set primitives ' //
     2             'should be saved and restored by <execute '       //
     3             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR HATCH INDEX: ' //
     1             'Which pair of rectangles does NOT match?',
     2             14, PERM(14))

C  *** *** *** ***   pattern index   *** *** *** ***
2000  CONTINUE

      IF (IARFND(PPATTR, NUMSTY, LSTYLE) .LE. 0) THEN
         CALL INMSG ('Pattern style unavailable - skipping test of ' //
     1               'pattern index.')
         GOTO 3000
      ENDIF

C     set up 5 distinct patterns in table
      CALL SETVAL ('1,0,0,0,1,0', COLIA)
      CALL PSPAR (WKID, 1, 3,2, 1,1, 3,2, COLIA)
      CALL SETVAL ('1,1,0,0,0,0', COLIA)
      CALL PSPAR (WKID, 2, 3,2, 1,1, 3,2, COLIA)
      CALL SETVAL ('1,1,1,0,0,0', COLIA)
      CALL PSPAR (WKID, 3, 3,2, 1,1, 3,2, COLIA)
      CALL SETVAL ('1,1,0,1,0,0', COLIA)
      CALL PSPAR (WKID, 4, 3,2, 1,1, 3,2, COLIA)
      CALL SETVAL ('1,1,0,0,0,1', COLIA)
      CALL PSPAR (WKID, 5, 3,2, 1,1, 3,2, COLIA)

C  randomize order of rectangles:
      CALL RN1SHF (14, PERM)

C  clear and re-set up CSS:
      DO 2010 IX = 101,105
         CALL PEMST (IX)
2010  CONTINUE

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  turn off edge flag, set interior style to PATTERN and
C  set pattern size to reasonable value
      CALL PSEDFG (POFF)
      CALL PSIS   (PPATTR)
      CALL PSPA  (0.6 * RECHT, 0.6 * RECHT)

C  structure #101
      CALL LOCREC (PERM(1), XACT, 1)
      CALL PEXST (102)
      CALL LOCREC (PERM(9), XACT, 9)
      CALL PSISI (2)
      CALL LOCREC (PERM(10), XACT, 10)

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

      CALL LOCREC (PERM(13), XACT, 13)
      CALL LOCREC (PERM(14), XACT, 14)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCREC (PERM(2), XACT, 2)
      CALL PSISI (3)
      CALL PEXST (103)
      CALL LOCREC (PERM(8), XACT, 8)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCREC (PERM(3), XACT, 3)
      CALL PSISI (4)
      CALL LOCREC (PERM(4), XACT, 4)
      CALL PEXST (104)
      CALL LOCREC (PERM(7), XACT, 7)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCREC (PERM(5), XACT, 5)
      CALL PSISI (5)
C  fill area set 6 / 12
      CALL LOCREC (PERM(6), XACT, 6)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for expected pattern indexes
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 305 IX = 1,14
         CALL PSISI (EXPDX(IX))
         CALL LOCREC (PERM(IX), XEXP, IX)
305   CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 19 20 24 25', 'The pattern index attribute ' //
     1             'for the fill area and fill area set primitives ' //
     2             'should be saved and restored by <execute '       //
     3             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR PATTERN ' //
     1             'INDEX: Which pair of rectangles does NOT match?',
     2             14, PERM(14))

3000  CONTINUE

C  *** *** *** ***   edge flag   *** *** *** ***

C  set up 5 edge flags in table - 1st must be default (OFF), and
C  make 2nd <> 4th, since these are both inherited by #104
      CALL SETVAL ('0,1,1,0,1', EDGFLG)

C  randomize order of triangles:
      CALL RN1SHF (14, PERM)

C  clear and re-set up CSS:
      DO 3110 IX = 101,105
         CALL PEMST (IX)
3110  CONTINUE

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  set interior style to EMPTY and try for moderately thick edge
      CALL PSIS   (PISEMP)
      CALL PSEWSC (.01 / (NOMEW*WCPDC))

C  structure #101
      CALL LOCTRI (PERM(1), XTACT)
      CALL PEXST (102)
      CALL LOCTRI (PERM(9), XTACT)
      CALL PSEDFG (EDGFLG(2))
      CALL LOCTRI (PERM(10), XTACT)

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

      CALL LOCTRI (PERM(13), XTACT)
      CALL LOCTRI (PERM(14), XTACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTRI (PERM(2), XTACT)
      CALL PSEDFG (EDGFLG(3))
      CALL PEXST (103)
      CALL LOCTRI (PERM(8), XTACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTRI (PERM(3), XTACT)
      CALL PSEDFG (EDGFLG(4))
      CALL LOCTRI (PERM(4), XTACT)
      CALL PEXST (104)
      CALL LOCTRI (PERM(7), XTACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCTRI (PERM(5), XTACT)
      CALL PSEDFG (EDGFLG(5))
C  fill area set 6 / 12
      CALL LOCTRI (PERM(6), XTACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected edge flags
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,4', EXPDX)
      DO 3105 IX = 1,14
         CALL PSEDFG (EDGFLG(EXPDX(IX)))
         CALL LOCTRI (PERM(IX), XTEXP)
3105  CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 34 35 36 38 39', 'The edge flag attribute ' //
     1             'for the fill area set primitive should be '     //
     2             'saved and restored by <execute structure> '     //
     3             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR EDGE FLAG: ' //
     1             'Which pair of triangles does NOT match?',
     2             14, PERM(14))

C  *** *** *** ***   edgetype and width   *** *** *** ***

      IF (ABS(NUMET).EQ.1 .AND. NUMEW.EQ.1) THEN
         CALL INMSG ('Only one edgetype and edgewidth available ' //
     1               '- skipping test of edgetype and edgewidth.')
         GOTO 4190
      ENDIF

C  ledtyp = list of 5 (possibly repeated) edgetypes
C  get up to 5 random available edge types see if #1 is available
      LEDTYP(1) = 6666
      LAST = 1
      DO 4160 IX = 1, ABS(NUMET)
         CALL PQEDF (SPECWT,IX, ERRIND, IDUM1, THISET, IDUM2,
     1               RDUM1,RDUM2,RDUM3, IDUM4)
         CALL CHKINQ ('pqedf',ERRIND)
         IF (THISET .EQ. 1) THEN
            LEDTYP(1) = 1
         ELSE
            LAST = LAST+1
            LEDTYP(MIN(5,LAST)) = THISET
         ENDIF
4160  CONTINUE

      IF (LEDTYP(1) .NE. 1) THEN
         CALL INMSG ('Edgetype #1 unavailable - skipping test of ' //
     1               'edgetype and edgewidth.')
         GOTO 4190
      ENDIF

C  make sure first 5 elements of LEDTYP are filled
      IY = 1
      DO 4165 IX = LAST+1,5
         LEDTYP(IX) = LEDTYP(IY)
         IY = IY+1
4165  CONTINUE

C  try to set up 5 distinct edgewidth scale factors
      MAXSC = 0.6*RECHT / (NOMEW*WCPDC)
      MINSC = MINEW / NOMEW
      DO 4175 IX = 1,5
         EWVALS(IX) = MINSC + ((MAXSC-MINSC) * (IX-1)) / 4
4175  CONTINUE

C  randomize order of triangles:
      CALL RN1SHF (14, PERM)

C  clear and re-set up CSS:
      DO 4110 IX = 101,105
         CALL PEMST (IX)
4110  CONTINUE

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  set interior style to EMPTY and edge flag ON
      CALL PSIS   (PISEMP)
      CALL PSEDFG (PON)

C  structure #101
      CALL LOCTRI (PERM(1), XTACT)
      CALL PEXST (102)
      CALL LOCTRI (PERM(9), XTACT)
      CALL PSEDT  (LEDTYP(2))
      CALL PSEWSC (EWVALS(2))
      CALL LOCTRI (PERM(10), XTACT)

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

      CALL LOCTRI (PERM(13), XTACT)
      CALL LOCTRI (PERM(14), XTACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTRI (PERM(2), XTACT)
      CALL PSEDT  (LEDTYP(3))
      CALL PSEWSC (EWVALS(3))
      CALL PEXST (103)
      CALL LOCTRI (PERM(8), XTACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTRI (PERM(3), XTACT)
      CALL PSEDT  (LEDTYP(4))
      CALL PSEWSC (EWVALS(4))
      CALL LOCTRI (PERM(4), XTACT)
      CALL PEXST (104)
      CALL LOCTRI (PERM(7), XTACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCTRI (PERM(5), XTACT)
      CALL PSEDT  (LEDTYP(5))
      CALL PSEWSC (EWVALS(5))
C  fill area set 6 / 12
      CALL LOCTRI (PERM(6), XTACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected edgetypes and widths
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 4105 IX = 1,14
         CALL PSEDT  (LEDTYP(EXPDX(IX)))
         CALL PSEWSC (EWVALS(EXPDX(IX)))
         CALL LOCTRI (PERM(IX), XTEXP)
4105  CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 41 42 47 48 50 51 52 53 54', 'The edgetype ' //
     1             'and edgewidth scale factor attributes for the '  //
     2             'fill area set primitive should be saved and '    //
     3             'restored by <execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR EDGETYPE AND ' //
     1             'EDGEWIDTH: Which pair of triangles does NOT match?',
     2             14, PERM(14))

4190  CONTINUE

C  *** *** *** ***   pattern size   *** *** *** ***

      IF (IARFND(PPATTR, NUMSTY, LSTYLE) .LE. 0) THEN
         CALL INMSG ('Pattern style unavailable - skipping tests of ' //
     1               'pattern size, reference point, and vectors.')
         GOTO 5900
      ENDIF

C  set up simple checkerboard pattern in table
      CALL SETVAL ('1,0,0,1', COLIA)
      CALL PSPAR (WKID, 1, 3,2, 1,1, 2,2, COLIA)

C  set up distinguishable pattern sizes
      CALL SETRVS ('1, 1.2, 0.8, 1.4, 0.6', PATSZX, SIZ)
      CALL SETRVS ('1, 0.8, 1.2, 1.4, 0.6', PATSZY, SIZ)

C  randomize order of rectangles:
      CALL RN1SHF (14, PERM)

C  clear and re-set up CSS:
      DO 5120 IX = 101,105
         CALL PEMST (IX)
5120  CONTINUE

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  turn off edge flag, set interior style to PATTERN and
C  set pattern index to 1
      CALL PSEDFG (POFF)
      CALL PSIS   (PPATTR)
      CALL PSISI  (1)

C  Because default pattern size of 1,1 would fill whole screen,
C  we have to scale everything such that 1,1 is part of a rectangle,
C  whose height is RECHT = 0.045 - so map 1.2 to RECHT
      SCF = RECHT/1.2
      CALL PSC (SCF, SCF, ERRIND, SCFORM)
      CALL CHKINQ ('psc', ERRIND)
      CALL PSLMT (SCFORM, PCREPL)

C  structure #101
      CALL PATREC (SCF, PERM(1), XACT, 1)
      CALL PEXST (102)
      CALL PATREC (SCF, PERM(9), XACT, 9)
      CALL PSPA (PATSZX(2), PATSZY(2))
      CALL PATREC (SCF, PERM(10), XACT, 10)

      FXPTY  =  YLOCEL(PERM(5)) / SCF
      SHIFTY =  (YLOCEL(PERM(11)) - YLOCEL(PERM(5))) / SCF
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,U, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
C  note we add this to current transform
      CALL PSLMT (XFORM, PCPRE)
C  execute 104
      CALL PEXST (104)
C  now, cancel out transformation ...
      CALL IDMAT (3, XFORM)
      CALL PSLMT (SCFORM, PCREPL)

      CALL PATREC (SCF, PERM(13), XACT, 13)
      CALL PATREC (SCF, PERM(14), XACT, 14)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL PATREC (SCF, PERM(2), XACT, 2)
      CALL PSPA (PATSZX(3), PATSZY(3))
      CALL PEXST (103)
      CALL PATREC (SCF, PERM(8), XACT, 8)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL PATREC (SCF, PERM(3), XACT, 3)
      CALL PSPA (PATSZX(4), PATSZY(4))
      CALL PATREC (SCF, PERM(4), XACT, 4)
      CALL PEXST (104)
      CALL PATREC (SCF, PERM(7), XACT, 7)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL PATREC (SCF, PERM(5), XACT, 5)
      CALL PSPA (PATSZX(5), PATSZY(5))
C  fill area set 6 / 12
      CALL PATREC (SCF, PERM(6), XACT, 6)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected pattern sizes
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 5130 IX = 1,14
         CALL PSPA (PATSZX(EXPDX(IX)), PATSZY(EXPDX(IX)))
         CALL PATREC (SCF, PERM(IX), XEXP, IX)
5130  CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15/SCF, YLOCEL(1)/SCF, (1.0/15)/SCF)
      CALL PCLST

      CALL SETMSG ('3 4 62 64 65 73 74', 'The pattern size '        //
     1             'attribute for the fill area and fill area set ' //
     2             'primitives should be saved and restored by '    //
     3             '<execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR PATTERN ' //
     1             'SIZE: Which pair of rectangles does NOT match?',
     2             14, PERM(14))

C  *** *** ***   pattern reference point and vectors   *** *** ***

C  set up simple stripe pattern in table
      CALL SETVAL ('1,1,0,0', COLIA)
      CALL PSPAR (WKID, 1, 3,2, 1,1, 2,2, COLIA)

C  set up distinguishable pattern reference point and vectors
      DO 5110 IX = 1,5
C  move reference point along x-axis by 5ths of a rectangle height
         XREFPT(IX) = (IX-1) * RECHT / 5
         ANG = (IX-1) * PI / 5
         XVEC(1,IX) = COS(ANG)
         YVEC(1,IX) = SIN(ANG)
         ZVEC(1,IX) = 0.0
         XVEC(2,IX) = -YVEC(1,IX)
         YVEC(2,IX) =  XVEC(1,IX)
         ZVEC(2,IX) = 0.0
5110  CONTINUE

C  randomize order of rectangles:
      CALL RN1SHF (14, PERM)

C  clear and re-set up CSS:
      DO 5520 IX = 101,105
         CALL PEMST (IX)
5520  CONTINUE

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  turn off edge flag, set interior style to PATTERN, set
C  pattern index to 1 and set pattern size to reasonable value
      CALL PSEDFG (POFF)
      CALL PSIS   (PPATTR)
      CALL PSISI  (1)
      CALL PSPA   (RECHT, RECHT)

C  structure #101
      CALL LOCREC (PERM(1), XACT, 1)
      CALL PEXST (102)
      CALL LOCREC (PERM(9), XACT, 9)
      CALL PSPRPV (XREFPT(2),Z,Z, XVEC(1,2), YVEC(1,2), ZVEC(1,2))
      CALL LOCREC (PERM(10), XACT, 10)

      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  (YLOCEL(PERM(11)) - YLOCEL(PERM(5)))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,U, ERRIND, XFORM)
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
      CALL PSPRPV (XREFPT(3),Z,Z, XVEC(1,3), YVEC(1,3), ZVEC(1,3))
      CALL PEXST (103)
      CALL LOCREC (PERM(8), XACT, 8)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCREC (PERM(3), XACT, 3)
      CALL PSPRPV (XREFPT(4),Z,Z, XVEC(1,4), YVEC(1,4), ZVEC(1,4))
      CALL LOCREC (PERM(4), XACT, 4)
      CALL PEXST (104)
      CALL LOCREC (PERM(7), XACT, 7)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCREC (PERM(5), XACT, 5)
      CALL PSPRPV (XREFPT(5),Z,Z, XVEC(1,5), YVEC(1,5), ZVEC(1,5))
C  fill area set 6 / 12
      CALL LOCREC (PERM(6), XACT, 6)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected pattern reference points and vectors
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 5530 IX = 1,14
C  allow for different x-location of rectangles
         CALL PSPRPV (XREFPT(EXPDX(IX)) + XEXP(1) - XACT(1),Z,Z,
     1      XVEC(1,EXPDX(IX)), YVEC(1,EXPDX(IX)), ZVEC(1,EXPDX(IX)))
         CALL LOCREC (PERM(IX), XEXP, IX)
5530  CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 68 71 72 73 74 75 76 77 80 81 82 83',
     1             'The pattern reference point and vectors '        //
     2             'attributes for the fill area and fill area set ' //
     3             'primitives should be saved and restored by '     //
     4             '<execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR PATTERN '  //
     1             'REFERENCE POINT AND VECTORS: Which pair of ' //
     2             'rectangles does NOT match?', 14, PERM(14))

5900  CONTINUE

C  save color tests for last, since they may change the color table
C  *** *** *** *** ***   interior color index   *** *** *** *** ***

C  clear the decks
      DO 3200 IX = 101,105
         CALL PEMST (IX)
3200  CONTINUE

C  call DISCOL to try to get 5 distinct foreground colors,
C    returning fcol = actual number of foreground colors
      CALL DISCOL (5, WKID, FCOL)

      IF (FCOL .LE. 1) THEN
         FCOL = 2
         CALL SETVAL ('1,0,1,1,0', COLIND)
      ELSE
C  colind = circular list of indices = [1,..,fcol, 1,..]
         CALL SETVAL ('1,2,3,4,5', COLIND)
         IY = 1
         DO 3300 IX = FCOL+1,5
            COLIND(IX) = COLIND(IY)
            IY = IY+1
3300     CONTINUE
      ENDIF

C  set up PERM to randomize position of triangles
      CALL RN1SHF (14, PERM)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  set edge flag off and try for interior style = SOLID, but take
C  HOLLOW as default
      CALL PSEDFG (POFF)
      CALL PSIS   (PSOLID)

C  structure #101
      CALL LOCREC (PERM(1), XACT, 1)
      CALL PEXST (102)
      CALL LOCREC (PERM(9), XACT, 9)
      CALL PSICI (COLIND(2))
      CALL LOCREC (PERM(10), XACT, 10)

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

      CALL LOCREC (PERM(13), XACT, 13)
      CALL LOCREC (PERM(14), XACT, 14)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCREC (PERM(2), XACT, 2)
      CALL PSICI (COLIND(3))
      CALL PEXST (103)
      CALL LOCREC (PERM(8), XACT, 8)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCREC (PERM(3), XACT, 3)
      CALL PSICI (COLIND(4))
      CALL LOCREC (PERM(4), XACT, 4)
      CALL PEXST (104)
      CALL LOCREC (PERM(7), XACT, 7)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCREC (PERM(5), XACT, 5)
      CALL PSICI (COLIND(5))
C  fill area set 6 / 12
      CALL LOCREC (PERM(6), XACT, 6)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected interior colour indexes
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 3305 IX = 1,14
         CALL PSICI (COLIND(EXPDX(IX)))
         CALL LOCREC (PERM(IX), XEXP, IX)
3305  CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 27 28 30 31', 'The interior colour index '  //
     1             'attribute for the fill area and fill area set ' //
     2             'primitives should be saved and restored by '    //
     3             '<execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR INTERIOR '      //
     1             'COLOUR INDEX: Which pair of rectangles does NOT ' //
     2             'match?', 14, PERM(14))

C  *** *** *** *** ***   edge color index   *** *** *** *** ***

C  clear the decks
      DO 4200 IX = 101,105
         CALL PEMST (IX)
4200  CONTINUE

C  FCOL and COLIND set from interior colour index

C  set up PERM to randomize position of triangles
      CALL RN1SHF (14, PERM)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  set edge flag ON, interior style = EMPTY, and try for
C  moderately thick edge
      CALL PSEDFG (PON)
      CALL PSIS   (PISEMP)
      CALL PSEWSC (.01 / (NOMEW*WCPDC))

C  structure #101
      CALL LOCTRI (PERM(1), XTACT)
      CALL PEXST (102)
      CALL LOCTRI (PERM(9), XTACT)
      CALL PSEDCI (COLIND(2))
      CALL LOCTRI (PERM(10), XTACT)

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

      CALL LOCTRI (PERM(13), XTACT)
      CALL LOCTRI (PERM(14), XTACT)
      CALL PEXST (105)
      CALL PCLST

C  structure #102
      CALL POPST (102)
      CALL LOCTRI (PERM(2), XTACT)
      CALL PSEDCI (COLIND(3))
      CALL PEXST (103)
      CALL LOCTRI (PERM(8), XTACT)
      CALL PCLST

C  structure #103
      CALL POPST (103)
      CALL LOCTRI (PERM(3), XTACT)
      CALL PSEDCI (COLIND(4))
      CALL LOCTRI (PERM(4), XTACT)
      CALL PEXST (104)
      CALL LOCTRI (PERM(7), XTACT)
      CALL PCLST

C  structure #104
      CALL POPST (104)
C  fill area 5 / 11
      CALL LOCTRI (PERM(5), XTACT)
      CALL PSEDCI (COLIND(5))
C  fill area set 6 / 12
      CALL LOCTRI (PERM(6), XTACT)
      CALL PCLST

C  Expected attributes: structure #105
      CALL POPST (105)
C  values for index into expected edge colour indexes
      CALL SETVAL ('1,1,3,4,4,5,4,3,1,2,2,5,2,3', EXPDX)
      DO 4305 IX = 1,14
         CALL PSEDCI (COLIND(EXPDX(IX)))
         CALL LOCTRI (PERM(IX), XTEXP)
4305  CONTINUE

C  draw labels
      CALL NUMLAB (14, 0.15, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('3 4 56 57 59 60', 'The edge colour index '  //
     1             'attribute for the fill area set primitive ' //
     2             'should be saved and restored by <execute '  //
     3             'structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR EDGE COLOUR ' //
     1             'INDEX: Which pair of triangles does NOT match?',
     2             14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
