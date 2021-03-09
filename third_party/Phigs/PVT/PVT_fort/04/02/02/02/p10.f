C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/10                        *
C  *    TEST TITLE : Polymarker bundle index               *
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

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   PICSTR, TXCI, BUNEL, UNDF(3), EXPLCT
      INTEGER   SZBT, BUNDIS, BUNDIF, IX, PERM(10), RNDINT

      REAL      XLOC, XINCR, YLOC, YINCR, XA(9),YA(9), MSCF, NOMMS
      REAL      RDUM1,RDUM2

      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7

      CALL INITGL ('04.02.02.02/10')

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
C  use bundled attributes
      CALL SETASF (PBUNDL)

C  szbt = maximum size of bundle table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, SZBT, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      CALL PQPMF (SPECWT, 0, ERRIND,IDUM1,IDUM2,IDUM3, NOMMS, 
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)

C *** *** *** *** polymarker index

C  mark start of polymarker bundles
      CALL PLB (1)

      CALL SETMSG ('3 4 5 6', 'A defined polymarker index should '  //
     1             'cause the addressed entry in the bundle table ' //
     2             'to be used when rendering a polymarker.')

C  bundis = # of bundles to be displayed
      BUNDIS = MIN(8, SZBT)
      YINCR = 0.8/BUNDIS
      YLOC  = 0.9
      MSCF = (YINCR/2) / (NOMMS*WCPDC)
C  initialize bundis to marker type=3, marker size=YINCR/2, color index=1
      DO 60 IX = 1,BUNDIS
         CALL PSPMR (WKID, IX, 3, MSCF, 1)
60    CONTINUE

C  bundif = randomly selected bundle, set to
C           marker type=2, marker size=2.0, color index = 2
      BUNDIF = RNDINT(1, BUNDIS)
      CALL PSPMR (WKID, BUNDIF, 2, 0.5*MSCF, 2)

C  draw and label actual
      XA(1) = 0.425
      CALL NUMLAB (BUNDIS, 0.2, YLOC, YINCR)
      DO 100 IX = 1,BUNDIS
         YA(1) = YLOC
         CALL PSPMI (IX)
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
100   CONTINUE

C  mark end of marker types
      CALL PLB (2)

      CALL DCHPFV ('DEFINED POLYMARKER INDICES: Which marker is ' //
     1             'different?', BUNDIS, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 7', 'An undefined polymarker index should ' //
     1             'cause bundle number 1 in the polymarker bundle '  //
     2             'table to be used when rendering a polymarker.')

      XINCR = .125
      XLOC  = XINCR
      MSCF = (XINCR/2) / (NOMMS*WCPDC)
C  draw marker, use individual attributes:
C               markertype=4,width=XINCR/2,color=#2
C  set ASFs to INDIVIDAUL
      CALL SETASF (PINDIV)
      XA(1) = .5
      YA(1) = .75
      CALL PSMK (POMARK)
      CALL PSMKSC (MSCF)
      CALL PSPMCI (2)
      CALL PPM (1,XA,YA)
C  draw line underneath
      XA(1) = .1
      XA(2) = .9
      YA(1) = .625
      YA(2) = YA(1)
      CALL PPL (2, XA, YA)

C  reset ASFs to BUNDLED
      CALL SETASF (PBUNDL)
C  set index #1 in bundle table to markertype=4, size=2.0, color index=2
      CALL PSPMR (WKID, 1, POMARK, MSCF, 2)

C  undf1,undf2,undf3 = 3 undefined polymarker indices
      UNDF(1) = SZBT + 1
      UNDF(2) = SZBT + 10
      UNDF(3) = SZBT + 90

C  explct = number of explicit markers of bundle #1 = random integer
C  from 0 to 4
      EXPLCT = RNDINT(0,4)
      BUNDIS = EXPLCT+3
      CALL RNPERM (BUNDIS, PERM)

C  display interleaved: three markers with bundles u1,u2,u3,
C    and explct markers with bundle #1
      YA(1) = .5

      DO 500 IX = 1,BUNDIS
         BUNEL = PERM(IX)
         IF (BUNEL .LE. 3) THEN
            CALL PSPMI (UNDF(BUNEL))
         ELSE
            CALL PSPMI (1)
         ENDIF
         XA(1) = XLOC
         CALL PPM (1, XA,YA)
         XLOC  = XLOC + XINCR
500   CONTINUE

      CALL DCHPFV ('UNDEFINED POLYMARKER INDICES: How many '      //
     1             'of the markers below the line have the same ' //
     2             'attributes as the marker above the line?',
     3             12, BUNDIS)

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
