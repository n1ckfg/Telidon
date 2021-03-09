C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.01/02                        *
C  *    TEST TITLE : Appearance of individual interior     *
C  *                 attributes                            *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C edge flag indicator
      INTEGER    POFF,    PON
      PARAMETER (POFF=0, PON=1)

C linetype  (edgetype)
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)

      INTEGER    IMPMAX
      PARAMETER (IMPMAX = 600)

      INTEGER    PICSTR,TXCI, LAVIS(5), NALIS, NUMHS, THISIS
      INTEGER    NOSEG, SIZ, INTCST(0:2)
      INTEGER    REGDX,IMPDX, ISI, HDX, MAXRHS, MINIHS, ENDPTS(3)
      INTEGER    THISHS, LAVRHS(100), LAVIHS(IMPMAX), OPLTYP
      INTEGER    ITRIM, UNSUDX,LUNSUP(10), NUMDIS, MDI,NPI, UNDPI
      INTEGER    HATDIS(20), CDIM,CSIZ, SZCOLT, NUMFIL
      INTEGER    FACOL(20), IX, VISDX,VISCOL, RNDINT, ISCI, NUMCI
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPFAS, PERM(10), RTANS(10)

      REAL       YLOC,YINCR, XA(40),YA(40), OPLWID, YRAD, NOMLW, LWSCF
      PARAMETER (CSIZ = 6)
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ)
      REAL       RAD, CENTX,CENTY, PI, ANG
      PARAMETER (PI = 3.14159265)

C set up pattern array index values
      INTEGER    DIMX, DIMY, PAI, DIFFI
      PARAMETER (DIMX = 50, DIMY = 50)
      INTEGER    PCIA(DIMX, DIMY)

      CHARACTER  LDESCR(4)*14, PROMPT*200, HATID*12
      CHARACTER  MSG*2600
      CHARACTER  LDESIS(PHOLLO:PISEMP)*14

      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7
      REAL       RDUM1,RDUM2

      LOGICAL    NOZERO, DYN,NOAVAL(PHOLLO:PISEMP)

      DATA  LDESIS / 'hollow','solid','pattern','hatch','empty' /
      DATA  LDESCR / 'solid', 'dashed', 'dotted', 'dashed-dotted' /
C  interior styles affected by interior color
      DATA  INTCST / PHOLLO, PHATCH, PSOLID /

      CALL INITGL ('04.02.05.01/02')

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
C set up pattern size
      CALL PSPA (.1,.1)

C  use <inquire interior style facilities> to determine:
C    lavis  = list of available interior styles
C    nalis  = number of available & legal interior styles (hollow:empty)
C    numhs  = number of available hatch styles
C    lavrhs = list of available registered (non-mandatory) hatch styles
C    lavihs = list of available implementor-defined hatch styles
C             (may be derived directly from hatch style value, if
C              reported number of hatch styles< 0)
C    noaval = boolean table of interior styles not available

      NALIS = 0
      DO 10 ISI = PHOLLO, PISEMP
         NOAVAL(ISI) = .TRUE.
10    CONTINUE

      CALL PQIF (SPECWT,0,0,ERRIND, SIZ, IDUM1,
     1            NUMHS,IDUM2,IDUM3)
      CALL CHKINQ ('pqif', ERRIND)
C get interior styles
      DO 50 ISI = 1, SIZ
         CALL PQIF (SPECWT, ISI,0,ERRIND, IDUM1, THISIS,
     1              IDUM2, IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .GE. PHOLLO .AND. THISIS .LE. PISEMP)THEN
            NALIS = NALIS + 1
            LAVIS(NALIS) = THISIS
C mark which interior styles are available
            NOAVAL(THISIS) = .FALSE.
         ENDIF
50    CONTINUE

C get hatch styles
      REGDX = 0
      IMPDX = 0
      DO 100 HDX = 1,ABS(NUMHS)
         CALL PQIF (SPECWT,0,HDX, ERRIND, IDUM1, IDUM2,IDUM3,
     1               THISHS,IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISHS .GT. 0) THEN
            REGDX = REGDX+1
            LAVRHS (REGDX) = THISHS
         ELSE
            IF (IMPDX .LT. IMPMAX) THEN
               IMPDX = IMPDX+1
               IF (NUMHS .LE. 0) THEN
C  build list from first HDX negative integers
                  LAVIHS (IMPDX) = -HDX
               ELSE
                  LAVIHS (IMPDX) = THISHS
               ENDIF
            ENDIF
         ENDIF
100   CONTINUE

C  sort them
      IF (REGDX .GT. 0) CALL SRTIAR (REGDX, LAVRHS)
      IF (IMPDX .GT. 0) CALL SRTIAR (IMPDX, LAVIHS)

C *** *** *** interior style

C  mark start of interior styles
      CALL PLB (1)

C  Display in random order with FILL AREA all available (hollow:empty)
C  interior styles
      CALL RNPERM (NALIS,PERM)
      YINCR = 0.8/NALIS
      YLOC  = 0.85
      CALL NUMLAB (NALIS, 0.2, YLOC, YINCR)

      NOSEG = 7
      RAD = 0.33 * YINCR
      CENTX = 0.5

      DO 200 ISI = 1,NALIS
         DO 202 SIZ = 1, NOSEG
            ANG = SIZ * 2 * PI /NOSEG
            XA(SIZ) = CENTX + 2 * RAD*SIN(ANG)
            YA(SIZ) = YLOC  +     RAD*COS(ANG)
202      CONTINUE
         CALL PSIS (LAVIS(PERM(ISI)))
         CALL PFA  (NOSEG, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

C  mark end of interior styles
      CALL PLB (2)

      CALL SETMSG ('3 5 6 7 8 10 12 13 14 15', 'The interior '    //
     1             'styles, including mandatory styles (HOLLOW, ' //
     2             'EMPTY), should be recognizable from their '   //
     3             'standard description.')

C  Operator must identify each interior style according to official
C  English description: 0-hollow,1-solid, 2-pattern,3-hatch, 4-empty.
      PROMPT = 'INTERIOR STYLES: List, in order, the numeric ' //
     1         'labels for interior styles: ' // LDESIS(LAVIS(1))
      RTANS(PERM(1)) = 1
      DO 300 ISI = 2,NALIS
         PROMPT(ITRIM(PROMPT)+1:) = ', ' // LDESIS(LAVIS(ISI))
         RTANS(PERM(ISI)) = ISI
300   CONTINUE
      PROMPT(ITRIM(PROMPT)+1:) = '.'
      CALL DLSTPF (PROMPT, NALIS,RTANS, 'L')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C look for unsupported interior styles
C LUNSUP is list of unsupported interior styles, indexed by UNSUDX
      UNSUDX = 0
      DO 400 ISI = PHOLLO,PISEMP
          IF (NOAVAL(ISI))THEN
             UNSUDX = UNSUDX + 1
             LUNSUP(UNSUDX) = ISI
          ENDIF
400   CONTINUE
C skip test - if all interior styles supported
      IF (UNSUDX .LE. 0) THEN
         CALL INMSG ('Skipping test of unsupported interior ' //
     1               'style, since they are all supported.')
         GOTO 500
      ENDIF

C want 3 unsupported interiors, even if repetitive
      IF (UNSUDX .LT. 3) THEN
         DO 420 ISI = UNSUDX+1, 3
            LUNSUP(ISI)= LUNSUP(1)
            UNSUDX = UNSUDX +1
420      CONTINUE
      ENDIF

C add HOLLOW to the list
      UNSUDX = UNSUDX +1
      LUNSUP(UNSUDX) = PHOLLO

C now get a supported interior other than HOLLOW
      UNSUDX = UNSUDX + 1
      IF (LAVIS(1) .NE. PHOLLO) THEN
         LUNSUP(UNSUDX) = LAVIS(1)
      ELSE
         LUNSUP(UNSUDX) = LAVIS(2)
      ENDIF

C display in random order interior styles in LUNSUP
      CALL RNPERM (UNSUDX, PERM)
      CALL SETRVS ('0.3,0.9,0.9,0.3',  XA, SIZ)
      YINCR = 0.8/UNSUDX
      YLOC  = 0.85
      CALL NUMLAB (UNSUDX, 0.2, YLOC+.05, YINCR)

      DO 450 ISI = 1, UNSUDX
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         CALL PSIS (LUNSUP(PERM(ISI)))
         CALL PFA (4, XA, YA)
         YLOC  = YLOC - YINCR
450   CONTINUE

      CALL SETMSG ('3 5 6 7 9 10', 'Unavailable interior styles ' //
     1             'should be displayed as HOLLOW.')
      CALL DCHPF  ('UNSUPPORTED INTERIOR STYLES: Which rectangle ' //
     1             'is NOT hollow?', UNSUDX, UNSUDX, PERM)

C clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_nosup:
500   CONTINUE

      CALL SETMSG ('3 5 6 7 8 10 11', 'For HOLLOW interior style, ' //
     1             'the linetype and linewidth of the bounding '    //
     2             'polyline should be as specified by the '        //
     3             'implementor.')

      IF (DYN('Does the implementor document the linetype and ' //
     1        'linewidth used for the boundary of HOLLOW fill ' //
     2        'areas?')) THEN
C        OK so far
      ELSE
         CALL FAIL
         GOTO 590
      ENDIF

      CALL DCHOIC ('Enter the linetype used for a HOLLOW fill area ' //
     1             'boundary, as documented by the implementor.',
     2             -99999,99999, OPLTYP)
      CALL DRLVAL ('Enter the linewidth (in DC) used for a HOLLOW ' //
     1             'fill area boundary, as documented by the '      //
     2             'implementor.', OPLWID)
C  calculate equivalent scale factor
      CALL PQPLF (SPECWT,0, ERRIND, IDUM1,IDUM2,IDUM3, NOMLW,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)
      LWSCF = OPLWID/NOMLW

C  draw 5 fill areas: 2 actual, and 3 simulated, with one of the
C  simulated ones drawn incorrectly
      YINCR = 1.0/6.0
      YLOC  = 1 - YINCR
      YRAD  = 0.3*YINCR
      CALL NUMLAB (5, .2, YLOC, YINCR)
      CALL RNPERM (5,PERM)
C  set x values
      CALL SETRVS ('0.3,0.3,0.7,0.7,0.3', XA, SIZ)

C  display a FILL AREA with HOLLOW
      CALL PSIS (PHOLLO)
C  make sure colors are the same
      CALL PSICI (2)
      CALL PSPLCI (2)
      DO 520 IX = 1,5
         YA(1) = YLOC-YRAD
         YA(4) = YA(1)
         YA(5) = YA(1)
         YA(2) = YLOC+YRAD
         YA(3) = YA(2)

         IF (PERM(IX) .LE. 3) THEN
C  simulate
            CALL PSLN (OPLTYP)
            CALL PSLWSC (LWSCF)
            IF (PERM(IX) .EQ. 1) THEN
C  simulate incorrectly
               IF (OPLTYP .EQ. 4) THEN
                  CALL PSLN (3)
               ELSE
                  CALL PSLN (4)
               ENDIF
            ENDIF
            CALL PPL (5, XA,YA)
         ELSE
C  draw actual
            CALL PFA (4, XA,YA)
         ENDIF
         YLOC = YLOC - YINCR
520   CONTINUE

      CALL DCHPF ('INTERIOR STYLE - HOLLOW: Which rectangle is ' //
     1            'different?', 5, 1, PERM)

C clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_hollow:
590   CONTINUE

C *** *** *** interior style index - hatch

C use noaval to check if hatch available
      IF (NOAVAL(PHATCH)) THEN
         CALL INMSG ('Hatch interior style not supported, skip ' //
     1               'hatch index tests.')
         GOTO 990
      ENDIF

C  set HATCH interior style
      CALL PSIS (PHATCH)

C  REGDX = size of lavrhs
      IF (REGDX .LT. 1) THEN
         CALL INMSG ('No registered hatch styles are supported.')
         GOTO 890
      ENDIF
C display and label at most 8 hatch styles in lavrhs
      NUMDIS = MIN(8, REGDX)
      CALL RNSET (NUMDIS, REGDX, PERM)

C  build list of hatch styles to be displayed
      DO 770 HDX = 1,NUMDIS
         HATDIS(HDX) = LAVRHS(PERM(HDX))
770   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, HATDIS)

C  Display in order (some) hatch styles in LAVRHS
      CALL SETRVS ('0.5,0.9,0.9,0.5', XA, SIZ)
      YINCR = 0.8/NUMDIS
      YLOC  = 0.85

      DO 800 HDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         THISHS = HATDIS(HDX)
         WRITE (HATID, '(A,I5,A)') 'Type#', THISHS, ':'
         CALL VISLAB (HATID(1:11), 'R', 0.05,0.45,
     1                YLOC, YLOC+0.6*YINCR)
         CALL PSISI (THISHS)
         CALL PFA  (4, XA,YA)
         YLOC  = YLOC-YINCR
800   CONTINUE
      CALL SETMSG ('3 5 7 8 14 18 19 20 22', 'The registered '   //
     1             'hatch styles (> 0) should agree with their ' //
     2             'registered descriptions.')
      CALL DYNPF ('REGISTERED HATCH STYLES: Is each hatch style '    //
     1            'depicted according to its numeric identifier''s ' //
     2            'specification in the ISO register?',
     3            'Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  neg_type:
890   CONTINUE

C  set HATCH interior style
      CALL PSIS (PHATCH)

C  IMPDX = size of lavihs
      IF (IMPDX .LT. 1) THEN
         CALL INMSG ('No implementor-defined hatch styles are ' //
     1               'supported.')
         GOTO 903
      ENDIF
C display and label at most 8 hatch styles in lavihs
      NUMDIS = MIN(8, IMPDX)
      CALL RNSET (NUMDIS, IMPDX, PERM)

C  build list of hatch styles to be displayed
      DO 870 HDX = 1,NUMDIS
         HATDIS(HDX) = LAVIHS(PERM(HDX))
870   CONTINUE
C  and sort it
      CALL SRTIAR (NUMDIS, HATDIS)

C  Display (some) hatch styles in LAVIHS
      CALL SETRVS ('0.5,0.9,0.9,0.5', XA, SIZ)
      YINCR = 0.8/NUMDIS
      YLOC  = 0.9

      DO 900 HDX = 1,NUMDIS
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         THISHS = HATDIS(HDX)
         WRITE (HATID, '(A,I5,A)') 'Type#', THISHS, ':'
         CALL VISLAB (HATID(1:11), 'R', 0.05,0.45,
     1                YLOC, YLOC+0.6*YINCR)
         CALL PSISI (THISHS)
         CALL PFA  (4, XA,YA)
         YLOC  = YLOC-YINCR
900   CONTINUE
      CALL SETMSG ('4 5 7 8 14 18 19 20 23', 'Implementor-defined ' //
     1             'hatch styles (< 1) should agree with the '      //
     2             'descriptions supplied by the implementor.')
      CALL DYNPF ('IMPLEMENTOR DEFINED HATCH STYLES: Is each hatch ' //
     1            'style depicted according to its numeric '         //
     2            'identifier''s specification in the implementor '  //
     3            'documentation?','Y')

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  Check if all implementor hatch styles already shown or
C  hatch style appearance derived directly from value - if so, skip test
      IF (IMPDX .LE. 8 .OR. NUMHS .LT. 0) GOTO 903

      CALL SETMSG ('23', 'All reported implementor-defined hatch ' //
     1             'styles available for a given workstation '     //
     2             'type should be documented by the implementor.')

      WRITE (MSG, '(500I5)') (LAVIHS(HDX), HDX=1,IMPDX)
      CALL DYNPF ('COMPLETE DOCUMENTATION FOR IMPLEMENTOR HATCH '     //
     1            'STYLES: Are all these reportedly available hatch ' //
     2            'styles documented by the implementor?' // MSG, 'Y')

C end_hatch_style:
903   CONTINUE

C  check for hatch style 1 - OK to check only 1st position,
C  because list is sorted
      IF (LAVRHS(1) .NE. 1) THEN
         CALL INMSG ('No hatch style #1, skip test of unsupported ' //
     1               'hatch style.')
         GOTO 990
      ENDIF

C set HATCH interior style
      CALL PSIS (PHATCH)
C look for unsupported negative hatch style
      IF (NUMHS .GT. 0) THEN
C  find negative hatch style *not* in LAVIHS and whether zero
C  is supported.
         NOZERO = .TRUE.
         MINIHS = 0
         DO 910 HDX = 1,IMPDX
            IF (LAVIHS(HDX) .EQ. 0) THEN
               NOZERO = .FALSE.
            ENDIF
            MINIHS = MIN(MINIHS, LAVIHS(HDX))
910      CONTINUE
C  LUNSUP is list of unsupported hatch styles, indexed by UNSUDX
         IF (NOZERO) THEN
            UNSUDX = 1
            LUNSUP (UNSUDX) = 0
         ELSE
            UNSUDX = 0
         ENDIF
C  since this value is less than minimum of LAVIHS, it's unsupported
         UNSUDX = UNSUDX+1
         LUNSUP (UNSUDX) = MINIHS - 1
      ELSE
C  all non-positive hatch styles supported - derived directly from
C  interior style index value
         UNSUDX = 0
      ENDIF

C now look for unsupported positive hatch style
      MAXRHS = 2
      DO 920 HDX = 1,REGDX
         MAXRHS = MAX(MAXRHS, LAVRHS(HDX))
920   CONTINUE
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = MAXRHS + 1

C  now add to end of LUNSUP entry #1 and a non-horizontal hatch style
      UNSUDX = UNSUDX+1
      LUNSUP (UNSUDX) = 1
C  other = another available non-horizontal hatch style
C  get positive hatch style, if not, get negative style
C  this is the only one that should appear as non-horizontal style #1
      UNSUDX = UNSUDX+1
      IF (REGDX .GT. 1) THEN
         LUNSUP(UNSUDX) = LAVRHS(2)
      ELSE
         LUNSUP(UNSUDX) = LAVIHS(1)
      ENDIF

C  Display in random order hatch styles in LUNSUP
      CALL RNPERM (UNSUDX, PERM)
      XA(1) = 0.3
      XA(2) = 0.9
      XA(3) = 0.6
      YINCR = 0.8/UNSUDX
      YLOC  = 0.85
      CALL NUMLAB (UNSUDX, 0.2, YLOC+.05,YINCR)

      DO 970 HDX = 1,UNSUDX
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         CALL PSISI (LUNSUP(PERM(HDX)))
         CALL PFA  (3, XA,YA)
         YLOC  = YLOC-YINCR
970   CONTINUE

      CALL SETMSG ('3 5 7 8 14 18 19 21', 'Unavailable hatch ' //
     1             'styles should be displayed as hatch style #1.')
      CALL DCHPF ('UNSUPPORTED HATCH STYLES: Which hatch style is ' //
     1            'not the horizontal hatch style of index #1?',
     2             UNSUDX, UNSUDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_hatch:
990   CONTINUE

*** *** *** interior style index - pattern

C use noavail to check if pattern available
      IF (NOAVAL(PPATTR)) THEN
         CALL INMSG ('Pattern interior style not supported, skip ' //
     1               'pattern index tests.')
         GOTO 1900
      ENDIF

C  set PATTERN interior style
      CALL PSIS (PPATTR)

      CALL SETMSG ('3 4 5 7 8 15 18 19 20', 'A defined pattern '    //
     1             'index should cause the addressed entry in the ' //
     2             'pattern table to be used when rendering a '     //
     3             'polygonal area filled with pattern interior style.')

C set 5 patterns (index 1-5): 4 identical and one different
      PCIA(5,5) = 1
      PCIA(6,5) = 0
      PCIA(7,5) = 2
      PCIA(5,6) = 0
      PCIA(6,6) = 1
      PCIA(7,6) = 2
      DO 1100 PAI = 1, 5
         CALL PSPAR (WKID, PAI, DIMX, DIMY, 5,5, 3,2, PCIA)
1100  CONTINUE

C now randomly set the different one
      DIFFI = RNDINT(1,5)
      PCIA (1,1) = 0
      PCIA (2,1) = 1
      PCIA (1,2) = 1
      PCIA (2,2) = 0
      CALL PSPAR (WKID, DIFFI, DIMX, DIMY, 1,1, 2,2, PCIA)
      CALL SETRVS ('0.3,0.7,0.7,0.3', XA, NOSEG)
      ENDPTS(1) = NOSEG
      YLOC   = 0.9
      YINCR  = 0.8 / 5
      CALL NUMLAB (5, .15, YLOC, YINCR)

      DO 1350 IX = 1,5
         YA(1) = YLOC - 0.25*YINCR
         YA(2) = YLOC - 0.25*YINCR
         YA(3) = YLOC + 0.25*YINCR
         YA(4) = YLOC + 0.25*YINCR
         CALL PSISI (IX)
C alternate between PFA and PFAS
         IF (MOD(IX,2) .EQ. 1) THEN
            CALL PFA (NOSEG, XA,YA)
         ELSE
            CALL PFAS (1, ENDPTS, XA, YA)
         ENDIF
         YLOC = YLOC - YINCR
1350  CONTINUE

      CALL DCHPFV ('DEFINED PATTERN INDICES: Which pattern ' //
     1             'is different?', 5, DIFFI)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  set PATTERN interior style
      CALL PSIS (PPATTR)

C look for 3 undefined pattern indices
C loop thru pattern table to determine mdi = the maximum defined index
C npi = number of pattern indices
      CALL PQEPAI (WKID,0, ERRIND, NPI,IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)
      MDI =  -9999
      DO 1400 IX = 1,NPI
         CALL PQEPAI (WKID, IX, ERRIND, IDUM1, PAI)
         CALL CHKINQ ('pqepai', ERRIND)
         IF (MDI .LT. PAI) MDI = PAI
1400  CONTINUE

C set up 5 patterns: 3 undefined, index #1, and another
      UNSUDX = 5
C undpi = undefined pattern index
      UNDPI = MDI + 1

C lunsup = list of (mostly) unsupported pattern indicies
      LUNSUP(1) = UNDPI
      LUNSUP(2) = UNDPI + 1
      LUNSUP(3) = UNDPI + 2
C reset pattern for index #1 to checkerboard
      PCIA (1,1) = 1
      PCIA (2,1) = 0
      PCIA (1,2) = 0
      PCIA (2,2) = 1
      CALL PSPAR (WKID, 1, DIMX, DIMY, 1,1, 2,2, PCIA)

      LUNSUP(4) = 1
C set pattern for index #5 (because we know 1-5 defined above, so this
C won't define an undefined index)
      PCIA (1,1) = 1
      PCIA (2,1) = 1
      PCIA (1,2) = 1
      PCIA (2,2) = 0
      CALL PSPAR (WKID, 5, DIMX, DIMY, 1,1, 2,2, PCIA)

      LUNSUP(5) = 5

C  Display in random order patterns in LUNSUP
      CALL RNPERM (UNSUDX, PERM)
      CALL SETRVS ('0.3,0.9,0.9,0.3', XA, NOSEG)
      YINCR = 0.8/UNSUDX
      YLOC  = 0.85
      CALL NUMLAB (UNSUDX, 0.2, YLOC+.05, YINCR)

      DO 1500 PAI = 1,UNSUDX
         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
         YA(4) = YLOC + YINCR/2
         CALL PSISI (LUNSUP(PERM(PAI)))
         CALL PFA (4, XA, YA)
         YLOC  = YLOC - YINCR
1500  CONTINUE

      CALL SETMSG ('3 4 5 6 7 8 15 18 19 21', 'Unavailable patterns ' //
     1             'should be displayed as pattern #1.')
      CALL DCHPF ('UNDEFINED PATTERNS: Which pattern is different?',
     1             UNSUDX, UNSUDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C end_pattern:
1900  CONTINUE

C  *** *** ***   interior color index

      CALL SETMSG ('3 4 10 13 14 26 27 28', 'A defined interior '     //
     1             'color index should cause the addressed entry in ' //
     2             'the color table to be used when rendering the '   //
     3             'interior of a fill area or fill area set.')

      CALL PSCMD (WKID, PRGB)
C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  szcolt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             SZCOLT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)
C  how many fill areas to draw
      NUMFIL = MIN(8, SZCOLT)
C  from values 2 to SZCOLT-1, pick NUMFIL-2 entries
      CALL RNBSET (NUMFIL-2, 2, SZCOLT-1, FACOL)
C  add in 0 and 1
      FACOL(NUMFIL-1) = 1
      FACOL(NUMFIL)   = 0
      CALL RNPERM (NUMFIL, PERM)

C  from facol, randomly select entry #visdx, but not the one that
C    contains 0, since this may not be re-settable.
      VISDX  = RNDINT(1,NUMFIL-1)
      VISCOL = FACOL(VISDX)

C  ensure dialogue visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / NUMFIL
      RAD = 0.3 * YINCR
      CENTX = .25 + RAD
      CENTY = YLOC
      CALL NUMLAB (NUMFIL, .15, YLOC, YINCR)

C set edge flag on
      CALL PSEDFG (PON)
      NOSEG = 11
      ENDPTS(1) = NOSEG

C  for each color entry - set to background color and draw fill area
      DO 2100 IX = 1,NUMFIL
         ISCI = FACOL(PERM(IX))
         CALL PSCR (WKID, ISCI, CDIM, BCKCOL)
         CALL PSICI (ISCI)
C set edge color = interior color
         CALL PSEDCI (ISCI)

C  set interior style to rotate through [HATCH,SOLID,HOLLOW]
C  (if unavailable, will default to HOLLOW)
         CALL PSIS (INTCST(MOD(IX,3)))

         DO 2050 SIZ = 1, NOSEG
            ANG = SIZ * 2 * PI /NOSEG
            XA(SIZ) = CENTX + RAD*COS(ANG)
            YA(SIZ) = CENTY + RAD*SIN(ANG)
2050     CONTINUE
C alternate between PFA and PFAS
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFA (ENDPTS(1), XA,YA)
         ELSE
            CALL PFAS (1,ENDPTS, XA,YA)
         ENDIF
         YLOC  = YLOC-YINCR
         CENTY = YLOC
2100  CONTINUE

C  set entry facol(visdx) to forcol
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED INTERIOR COLOR INDICES: Which ' //
     1            'circle is visible?', NUMFIL, VISDX, PERM)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 10 13 14 26 27 29', 'An undefined interior ' //
     1             'color index should cause entry #1 in the color ' //
     2             'table to be used when rendering the interior '   //
     3             'of a fill area or fill area set.')

C  Try to set entry #1 opposite from BCKCOL
      DO 2150 IX = 1,3
         IF (BCKCOL(IX) .GT. 0.5) THEN
            NEWCOL(IX) = 0.0
         ELSE
            NEWCOL(IX) = 1.0
         ENDIF
2150  CONTINUE

C  set entry #1 different from FORCOL - make sure other default
C  is to current color-rep of #1, not just a predefined color.
      IF (FORCOL(3) .GT. 0.5) THEN
         NEWCOL(3) = 0.0
      ELSE
         NEWCOL(3) = 1.0
      ENDIF

      CALL PSCR  (WKID, 1, CDIM, NEWCOL)

      CALL PQECI (WKID, 0, ERRIND, NUMCI, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      MAXCOL = 0
      DO 2200 IX = 1,NUMCI
         CALL PQECI (WKID, IX, ERRIND, IDUM1, COLEL)
         CALL CHKINQ ('pqeci', ERRIND)
         MAXCOL = MAX(MAXCOL, COLEL)
2200  CONTINUE
C  undf1,undf2,undf3 = 3 undefined, positive color indices
      UNDF(1) = MAXCOL+1
      UNDF(2) = MAXCOL+10
      UNDF(3) = MAXCOL+90

C  expfas = number of explicit fill area/area set of color #1 =
C  random integer from 0 to 4
      EXPFAS = RNDINT(0,4)
      NUMFIL = EXPFAS+3
      CALL RNPERM (NUMFIL, PERM)

C  draw star with color #1
      RAD = .15
      CENTX = .5
      CENTY = .75
      DO 2400 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
2400  CONTINUE
      CALL PSPLCI (1)
      CALL PPL (6,XA,YA)

C  display interleaved:
C    three fill areas of color u1,u2,u3,
C    expfas fill areas of color #1
      YLOC  = 0.5
      YINCR = 0.5 / 8
      XA(1) = .3
      XA(2) = .7
      XA(3) = .5
      ENDPTS(1) = 3

C  for each color entry - set to background color and draw fill area
      DO 2300 IX = 1,NUMFIL
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSICI (UNDF(COLEL))
C set edge color = interior color
            CALL PSEDCI (UNDF(COLEL))
         ELSE
            CALL PSICI (1)
C set edge color = interior color
            CALL PSEDCI (1)
         ENDIF

C  set interior style to rotate through [HATCH,SOLID,HOLLOW]
C  (if unavailable, will default to HOLLOW)
         CALL PSIS (INTCST(MOD(IX,3)))

         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC + YINCR/2
C alternate between PFA and PFAS
         IF (MOD(IX,2) .EQ. 0)THEN
            CALL PFA (3, XA,YA)
         ELSE
            CALL PFAS (1,ENDPTS, XA,YA)
         ENDIF
         YLOC  = YLOC-YINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED INTERIOR COLOR INDICES: How many of ' //
     1             'the fill areas are the same color as the star?',
     2             12, NUMFIL)

666   CONTINUE
      CALL ENDIT

      END
