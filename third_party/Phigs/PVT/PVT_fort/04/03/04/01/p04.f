C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.04.01/04                        *
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
C  composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    PICSTR, TXCI, PERM(14)
      INTEGER    NAMSIZ, NAMES(10), HISN, HIS(3), HESN, HES(3)
      INTEGER    IVISN, IVIS(3), IVESN, IVES(3), COLID(3,3)

      REAL       YLOCEL, XACT, XEXP, XPPM(1), Z, U, NPCX, NPCY, NPCPWC
      REAL       FXPTY,SHIFTY,SCALEY,XFORM(3,3)
      REAL       XCA1,XCA2,YCA1,YCA2,XPPL(2),XFILL(4),XFILLS(3)

      DATA COLID/0,1,0,1,0,1,0,0,1/

      CALL INITGL ('04.03.04.01/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL PSCMD (WKID, PRGB)

C
C  Five distinct values for nameset are set up and propagated
C  throughout the network.  The first value is the system default
C  from the PDT. Note that structure #104 is executed by both #103
C  and #101. Actual results are displayed on the left, expected
C  results on the right, with the 14th deliberately made incorrect.
C
C  default = null
C    |                  102
C    |                 /  prim 2
C    |               /    nmset = {3,4,5}  {3,4,5}
C    V         null/      exec 103---------------103
C  101           /        prim 8                   prim 3
C    prim 1    /                                   nmset = {1,6}
C    exec 102/                                     prim 4
C    prim 9                                        exec 104\
C    nmset = {2,3}                                 prim 7    \ {1,6}
C    prim 10                                                   \
C    transform             {2,3}                                 \
C    exec 104-----------------------------------------------------104
C    un-transform                                                   prim 5/11
C    prim 13                                                        nmset = {5,6}/{2,3,5}
C    prim 14                                                        prim 6/12
C    exec 105---------->105
C                         expected values
C
C  nameset    attribute
C  -------    ---------
C  null       normal
C  {2,3}      invisible
C  {3,4,5}    highlighted
C  {1,6}      invisible
C  {5,6}      normal
C  {2,3,5}    highlighted
C  {7}        normal

C
C  set highlighting filter:
C     inclusion set = {2,3,5}
C     exclusion set = {6}

      CALL SETVS ('2, 3, 5', HIS, HISN)
      CALL SETVS ('6', HES, HESN)
      CALL PSHLFT (WKID, HISN, HIS, HESN, HES)

C
C  set invisibility filter:
C     inclusion set = {3,6}
C     exclusion set = {5}

      CALL SETVS ('3, 6', IVIS, IVISN)
      CALL SETVS ('5', IVES, IVESN)
      CALL PSIVFT (WKID, IVISN, IVIS, IVESN, IVES)

      CALL PSCHH (0.025)
      CALL WCNPC (0., 0., NPCX, NPCY, NPCPWC)
      CALL PSATCH (0.025 * NPCPWC)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PSATAL (PALEFT, PAHALF)
C
C  randomize location of primitives
      CALL RN1SHF (14, PERM)

      XACT = 0.4
      XPPM(1) = XACT + 0.05
      XPPL(1) = XACT
      XPPL(2) = XPPL(1) + 0.1
      XFILL(1) = XACT
      XFILL(2) = XFILL(1)
      XFILL(3) = XFILL(2) + 0.1
      XFILL(4) = XFILL(3)
      XFILLS(1) = XACT + 0.05
      XFILLS(2) = XACT
      XFILLS(3) = XACT + 0.1
      XCA1 = XACT
      XCA2 = XACT + 0.15
C
C  polyline 1 (order within traversal)
      CALL LOCPPL (PERM(1), XPPL)

C  execute 102
      CALL PEXST (102)
C  polymarker 9
      CALL LOCPPM (PERM(9), XPPM)
C  add names to set: 2,3
      CALL SETVS ('2, 3', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
C  fill area 10
      CALL LOCINT (PERM(10), XFILL)
C  set local transformation to make primitives 11,12 distinguishable
C    from 5,6
      Z = 0.0
      U = 1.0
      FXPTY =   YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      SCALEY = (YLOCEL(PERM(12)) - YLOCEL(PERM(11))) /
     1         (YLOCEL(PERM(06)) - YLOCEL(PERM(05)))
      CALL PBLTM (Z,FXPTY,Z,SHIFTY,Z,U,SCALEY,ERRIND,XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)

C  execute 104
      CALL PEXST (104)

C  re-set local transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

C  text 13
      CALL LOCTXT (PERM(13), XACT)

C  text 14
      CALL LOCTXT (PERM(14), XACT)
      CALL SETVS ('2, 3', NAMES, NAMSIZ)
      CALL PRES (NAMSIZ, NAMES)

C  execute 105
      CALL PEXST (105)
      CALL PCLST
C
C  structure #102
      CALL POPST (102)

C  cell array 2
      YCA1 = YLOCEL(PERM(2)) - 0.02
      YCA2 = YCA1 + 0.035
      CALL PCA (XCA1,YCA1, XCA2,YCA2, 3,3, 1,1, 3,3, COLID)

C  add names to set: 3,4,5
      CALL SETVS ('3, 4, 5', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)

C  execute 103
      CALL PEXST (103)
C  annotation text 8
      CALL LOCATX (PERM(8), XACT)
      CALL PCLST
C
C  structure #103
      CALL POPST (103)
C  polyline 3
      CALL LOCPPL (PERM(3), XPPL)
C  add names to set: 1,6; remove names from set: 3,4,5
      CALL SETVS ('1, 6', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL SETVS ('3, 4, 5', NAMES, NAMSIZ)
      CALL PRES (NAMSIZ, NAMES)
C  polymarker 4
      CALL LOCPPM (PERM(4), XPPM)
C  execute 104
      CALL PEXST (104)
C  polyline 7
      CALL LOCPPL (PERM(7), XPPL)
      CALL PCLST
C
C  structure #104
      CALL POPST (104)
C  fill area set 5 / 11
      CALL LOCINT (PERM(5), XFILL)

C  remove names from set: 1; add names to set: 5
      CALL SETVS ('1', NAMES, NAMSIZ)
      CALL PRES (NAMSIZ, NAMES)
      CALL SETVS ('5', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)

C  fill area  6 / 12
      CALL LOCTRI (PERM(6), XFILLS)
      CALL PCLST
C
C  Expected attributes (except #14, whose actual nameset should be {2,3}
C
C  structure #105
      CALL POPST (105)

C  sequence #   primitive         nameset        attribute
C  ----------   ---------         -------        ----------
C     01        polyline          null           normal
C     02        cell array        null           normal
C     03        polyline          {3,4,5}        highlighted
C     04        polymarker        {1,6}          invisible
C     05        fill area set     {1,6}          invisible
C     06        fill area         {5,6}          normal
C     07        polyline          {1,6}          invisible
C     08        annotation text   {3,4,5}        highlighted
C     09        polymarker        null           normal
C     10        fill area         {2,3}          invisible
C     11        fill area set     {2,3}          invisible
C     12        fill area         {2,3,5}        highlighted
C     13        text              {2,3}          invisible
C     14        text              {7}            normal
C
      XEXP = 0.7
      XPPM(1) = XEXP + 0.05
      XPPL(1) = XEXP
      XPPL(2) = XPPL(1) + 0.1
      XFILL(1) = XEXP
      XFILL(2) = XFILL(1)
      XFILL(3) = XFILL(2) + 0.1
      XFILL(4) = XFILL(3)
      XFILLS(1) = XEXP + 0.05
      XFILLS(2) = XEXP
      XFILLS(3) = XEXP + 0.1
      XCA1 = XEXP
      XCA2 = XEXP + 0.15

      CALL LOCPPL (PERM(1), XPPL)

      YCA1 = YLOCEL(PERM(2)) - 0.02
      YCA2 = YCA1 + 0.035
      CALL PCA (XCA1,YCA1,XCA2,YCA2, 3,3, 1,1, 3,3, COLID)

      CALL SETVS ('3, 4, 5', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCPPL (PERM(3), XPPL)
      CALL PRES (NAMSIZ, NAMES)

      CALL SETVS ('1, 6', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCPPM (PERM(4), XPPM)
      CALL LOCINT (PERM(5), XFILL)
      CALL PRES (NAMSIZ, NAMES)

      CALL SETVS ('5, 6', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCTRI (PERM(6), XFILLS)
      CALL PRES (NAMSIZ, NAMES)

      CALL SETVS ('1, 6', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCPPL (PERM(7), XPPL)
      CALL PRES (NAMSIZ, NAMES)

      CALL SETVS ('3, 4, 5', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCATX (PERM(8), XEXP)
      CALL PRES (NAMSIZ, NAMES)

      CALL LOCPPM (PERM(9), XPPM)

      CALL SETVS ('2, 3', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCINT (PERM(10), XFILL)
      CALL LOCINT (PERM(11), XFILL)
      CALL PRES (NAMSIZ, NAMES)

      CALL SETVS ('2, 3, 5', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCTRI (PERM(12), XFILLS)
      CALL PRES (NAMSIZ, NAMES)

      CALL SETVS ('2, 3', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCTXT (PERM(13), XEXP)
      CALL PRES (NAMSIZ, NAMES)

      CALL SETVS ('7', NAMES, NAMSIZ)
      CALL PADS (NAMSIZ, NAMES)
      CALL LOCTXT (PERM(14), XEXP)

      CALL NUMLAB (14, 0.25, YLOCEL(1), 1.0/15)
      CALL PCLST

      CALL SETMSG ('1 4 11 12 13 14 15', 'The nameset attribute for ' //
     1             'the all primitives should be saved and restored ' //
     2             'by <execute structure> during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR NAMESET: ' //
     1             'Which pair of primitives does NOT match?',
     2             14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
