C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/11                        *
C  *    TEST TITLE : Interior bundle index                 *
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

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   PICSTR, TXCI, BUNEL, UNDF(3), EXPLCT, ALTSTY, RNDINT
      INTEGER   NUMSTY, SZBT, BUNDIS, BUNDIF, IX, PERM(10), INSTY, SIZ
      INTEGER   NPTS(3)

      REAL      ANG, YLOC, YINCR, RAD, CENTX, CENTY, PI, XA(40),YA(40)

      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7


      CALL INITGL ('04.02.05.02/11')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use bundled attributes, except edge flag (pedfg=14)
      CALL SETASF (PBUNDL)
C  set edge flag off to distinguish between hollow and empty styles
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)
      CALL PSPA (.1,.1)

C  szbt = maximum size of bundle table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, SZBT,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  <inquire interior facilities> to determine
C  altsty = alternative interior style to hollow or empty
      ALTSTY = PISEMP
      CALL PQIF (SPECWT, 0,0,ERRIND, NUMSTY, IDUM1, IDUM2,
     1           IDUM3, IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
C  get an interior style other than HOLLOW and EMPTY
      DO 50 IX = 1, NUMSTY
         CALL PQIF (SPECWT, IX, 0, ERRIND, IDUM1, INSTY, IDUM2,
     1              IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (INSTY .GT. 0 .AND. INSTY .LT. 4) THEN
            ALTSTY = INSTY
            GOTO 55
         ENDIF
50    CONTINUE
55    CONTINUE

C *** *** ***   interior index   *** *** ***

C  mark start of interior bundles
      CALL PLB (1)

      CALL SETMSG ('3 4 5 6 7', 'A defined interior index should '  //
     1             'cause the addressed entry in the bundle table ' //
     2             'to be used when rendering an interior.')

C  bundis = # of bundles to be displayed
      BUNDIS = MIN(8, SZBT)
C  initialize bundis to interior=HOLLOW, style index=1, col index=1
      DO 60 IX = 1,BUNDIS
         CALL PSIR (WKID, IX, PHOLLO, 1, 1)
60    CONTINUE

C  bundif = randomly selected bundle, set to
C           interior style = altsty, style index = 2, color index = 2
      BUNDIF = RNDINT(1, BUNDIS)
      CALL PSIR (WKID, BUNDIF, ALTSTY, 2, 2)

C  draw and label actual
      CALL SETRVS ('0.25, 0.5, 0.5, 0.25', XA, SIZ)
      YINCR = 0.8/BUNDIS
      YLOC  = 0.9
      CALL NUMLAB (BUNDIS, 0.2, YLOC, YINCR)
      NPTS(1) = 4
      DO 100 IX = 1,BUNDIS
         YA(1) = YLOC - .3*YINCR
         YA(2) = YA(1)
         YA(3) = YLOC + .3*YINCR
         YA(4) = YA(3)
         CALL PSII (IX)
C switch between fill area and fill area set
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (4, XA, YA)
         ENDIF
         YLOC  = YLOC-YINCR
100   CONTINUE

C  mark end of linetypes
      CALL PLB (2)

      CALL DCHPFV ('DEFINED INTERIOR INDICES: Which interior is ' //
     1             'different?', BUNDIS, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 6 8', 'An undefined interior index '     //
     1             'should cause bundle number 1 in the interior ' //
     2             'bundle table to be used when rendering an '    //
     3             'interior.')

C  set index #1 in bundle table to:
C            interior style=altsty, interior index=3, color index=3
      CALL PSIR (WKID, 1, ALTSTY, 3, 3)

C  undf1,undf2,undf3 = 3 undefined interior indices
      UNDF(1) = SZBT + 1
      UNDF(2) = SZBT + 10
      UNDF(3) = SZBT + 90

C  explct = number of explicit interiors of bundle #1 = random integer
C  from 0 to 4
      EXPLCT = RNDINT(0,4)
      BUNDIS = EXPLCT+3
      CALL RNPERM (BUNDIS, PERM)

C  draw circle with bundle #1
      RAD = .125
      CENTX = .5
      CENTY = .75
      PI = 3.14159265
      DO 400 IX = 1,40
         ANG = IX * 2 * PI/40
         XA(IX) = CENTX + RAD*COS(ANG)
         YA(IX) = CENTY + RAD*SIN(ANG)
400   CONTINUE
      CALL PSII (1)
      CALL PFA (40,XA,YA)

C  display interleaved: three rectangular interiors with bundles u1,u2,u3,
C    and explct interiors with bundle #1
      CALL SETRVS ('0.25, 0.75, 0.75, 0.25', XA, SIZ)
      YLOC  = 0.5
      YINCR = 0.5 / 8
      NPTS(1) = 4
      DO 500 IX = 1,BUNDIS
         BUNEL = PERM(IX)
         IF (BUNEL .LE. 3) THEN
            CALL PSII (UNDF(BUNEL))
         ELSE
            CALL PSII (1)
         ENDIF
         YA(1) = YLOC - .3*YINCR
         YA(2) = YA(1)
         YA(3) = YLOC + .3*YINCR
         YA(4) = YA(3)
C switch between fill area and fill area set
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (4, XA, YA)
         ENDIF
         YLOC  = YLOC-YINCR
500   CONTINUE

      CALL DCHPFV ('UNDEFINED INTERIOR INDICES: How many of the '   //
     1             'rectangular interiors have the same interior '  //
     2             'attributes (style, style index, and color) as ' //
     3             'the circle?', 12, BUNDIS)

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
