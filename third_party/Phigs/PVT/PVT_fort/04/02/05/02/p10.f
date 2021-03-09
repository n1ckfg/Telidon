C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/10                        *
C  *    TEST TITLE : Appearance of predefined interior     *
C  *                 bundles                               *
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

      INTEGER   PICSTR, TXCI, IX, SIZ, NPTS(3)
      INTEGER   NPREI, NUMBUN, BUNDIS(8), BUNDIF, PDIS, PDISI, PDCI
      INTEGER   RNDINT, IARFND, ITRIM
      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4

      REAL      XA(5), YA(5), YLOC, YINCR, YBOT,YTOP

      LOGICAL   DYN

      CHARACTER LNTID*40, INTNAM(PHOLLO:PISEMP)*9

      DATA INTNAM / 'Hollow', 'Solid', 'Pattern', 'Hatch', 'Empty' /

      CALL INITGL ('04.02.05.02/10')

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
C  set ASF individual: edge flag = off
      CALL PSIASF (PEDFG, PINDIV)
      CALL PSEDFG (POFF)

      CALL PSPA (.1,.1)

C  nprei = number of predefined interior bundles
      CALL PQIF (SPECWT, 0, 0, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1           NPREI)
      CALL CHKINQ ('pqif', ERRIND)

C *** *** *** *** predefined interior bundles 1-5

C  mark start of interior bundles 1-5
      CALL PLB (1)

C  use first 5 indices + 1 duplicate
      NUMBUN = 6
      CALL RNPERM (6, BUNDIS)
C  location of #6
      BUNDIF = IARFND(6, 6, BUNDIS)
      BUNDIS(BUNDIF) = RNDINT(1,5)

      CALL SETMSG ('3 4 7 21 25', 'Immediately after <open '       //
     1             'workstation>, the first 5 defined interior '   //
     2             'bundles of the WSL should appear as specified '//
     3             'in the corresponding predefined interior '     //
     4             'bundles of the WDT.')

      CALL DRWINT (NUMBUN, BUNDIS, BUNDIF)
C  mark end of bundles 1-5
      CALL PLB (2)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES 1-5: Which pair of rectangles does NOT ' //
     2             'match?', NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C *** *** *** *** predefined interior bundles > 5

C  skip if there are only 5 bundles
      IF (NPREI .LE. 5) THEN
         CALL INMSG ('Skip test of bundles > 5, only 5 predefined ' //
     1               'bundles supported.')
         GOTO 500
      ENDIF

C  numbun = number of bundles beyond #5 to be displayed
      NUMBUN = MIN (8, NPREI-5)
C  select bundles (as distinct as possible) from list of
C    predefined bundles [6,nprei]
      CALL DISINB (NUMBUN, 6, NPREI, BUNDIS)

      CALL SETMSG ('3 4 7 21 25', 'Immediately after <open '        //
     1             'workstation>, the defined interior bundles >5 ' //
     2             'of the WSL should appear as specified in the '  //
     3             'corresponding predefined interior bundles of '  //
     4             'the WDT.')

C  bundif = randomly selected bundle to be shown incorrectly
      BUNDIF = RNDINT(1, NUMBUN)
      CALL DRWINT (NUMBUN, BUNDIS, BUNDIF)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES > 5: Which pair of rectangles does NOT ' //
     2             'match?', NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_comp_tables
500   CONTINUE

C *** *** *** ***  predefined bundle descriptions

      CALL SETMSG ('3 4 7 21', 'The appearance of predefined ' //
     1             'interior bundles should agree with the '   //
     2             'descriptions supplied by the implementor.')

      NUMBUN = MIN(8, NPREI)
C  bundis = distinct bundles to be displayed, chosen from [1,nprei]
      CALL DISINB (NUMBUN, 1, NPREI, BUNDIS)
      CALL SRTIAR (NUMBUN, BUNDIS)
C  set position and label
      CALL SETRVS ('0.2,0.45,0.45,0.2', XA, SIZ)
      YINCR = 0.1
      YLOC  = 0.9
      YBOT = YLOC-0.3*YINCR
      YTOP = YLOC+0.3*YINCR
      CALL VISLAB ('Bundle#',       'R', 0.02, 0.15, YBOT,YTOP)
      CALL VISLAB ('InteriorStyle', 'L', 0.50, 0.65, YBOT,YTOP)
      CALL VISLAB ('  Style-index', 'R', 0.65, 0.80, YBOT,YTOP)
      CALL VISLAB ('  Color-index', 'R', 0.80, 0.95, YBOT,YTOP)

C  draw interior and its pdis, pdisi, pdci
      NPTS(1) = 4
      DO 600 IX = 1, NUMBUN
         YLOC  = YLOC-YINCR
         CALL PQPIR (SPECWT, BUNDIS(IX), ERRIND, PDIS, PDISI, PDCI)
         CALL CHKINQ ('pqpir', ERRIND)
         YBOT = YLOC-0.3*YINCR
         YTOP = YLOC+0.3*YINCR
         YA(1) = YBOT
         YA(2) = YBOT
         YA(3) = YTOP
         YA(4) = YTOP

         WRITE (LNTID, '(I5,A)') BUNDIS(IX), ': '
         CALL VISLAB (LNTID(1:7), 'R', 0.02,0.15, YBOT,YTOP)
         CALL PSII (BUNDIS(IX))
C switch between fill area and fill area set
         IF ( MOD(IX,2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (4, XA, YA)
         ENDIF

         IF (PDIS .GE. PHOLLO .AND. PDIS .LE. PISEMP) THEN
            LNTID = INTNAM(PDIS)
         ELSE
            WRITE (LNTID, '(A,I5)')  '#', PDIS
         ENDIF
         CALL VISLAB (LNTID(1:ITRIM(LNTID)), 'L', 0.50, 0.65, YBOT,YTOP)
         WRITE (LNTID, '(I5)') PDISI
         CALL VISLAB (LNTID(1:5), 'R', 0.65, 0.80, YBOT,YTOP)
         WRITE (LNTID, '(I5)')   PDCI
         CALL VISLAB (LNTID(1:5), 'R', 0.80, 0.95, YBOT,YTOP)
600   CONTINUE

      IF (DYN('PREDEFINED INTERIOR BUNDLES: Does the appearance ' //
     1        'of each interior agree with the displayed aspect ' //
     2        'values for that bundle?')) THEN
         CALL DYNPF ('PREDEFINED INTERIOR BUNDLES: If the '          //
     1               'implementor provides external documentation, ' //
     2               'is it consistent with the interior '           //
     3               'appearance and displayed aspect values for '   //
     4               'every bundle identifier?', 'Y')
      ELSE
         CALL OPFAIL
      ENDIF

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
