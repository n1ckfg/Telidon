C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/09                        *
C  *    TEST TITLE : Appearance of predefined polymarker   *
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

      INTEGER   PICSTR, TXCI
      INTEGER   NPREI, NUMBUN, BUNDIS(8), BUNDIF, IX, PDMT, PDCI
      INTEGER   RNDINT, IARFND, ITRIM

      REAL      PMKS, XA(2), YA(2), YLOC, YINCR, YBOT,YTOP

      LOGICAL   DYN

      INTEGER   IDUM1, IDUM2, IDUM3
      REAL      RDUM1, RDUM2, RDUM3

      CHARACTER LNTID*40, MTNAME(PPOINT:PXMARK)*10

      DATA MTNAME / 'Dot', 'Plus', 'Asterisk', 'Circle', 'X-cross' /

      CALL INITGL ('04.02.02.02/09')

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

C  nprei = number of predefined polymarker bundles
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3, RDUM1,
     1            RDUM2, RDUM3, NPREI)
      CALL CHKINQ ('pqpmf', ERRIND)

C *** *** *** *** predefined polymarker bundles 1-5

C  mark start of polymarker bundles 1-5
      CALL PLB (1)

C  use first 5 indices + 1 duplicate
      NUMBUN = 6
      CALL RNPERM (6, BUNDIS)
C  location of #6
      BUNDIF = IARFND(6, 6, BUNDIS)
      BUNDIS(BUNDIF) = RNDINT(1,5)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '            //
     1             'workstation>, the first five defined polymarker ' //
     2             'bundles of the WSL should appear as specified '   //
     3             'in the corresponding predefined polymarker '      //
     4             'bundles of the WDT.')

      CALL DRWPMB (NUMBUN, BUNDIS, BUNDIF)
C  mark end of bundles 1-5
      CALL PLB (2)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES 1-5: Which pair of markers does NOT match?',
     2             NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C *** *** *** *** predefined polymarker bundles > 5

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
      CALL DISPMB (NUMBUN, 6, NPREI, BUNDIS)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '           //
     1             'workstation>, the defined polymarker bundles > ' //
     2             '5 of the WSL should appear as specified in the ' //
     3             'corresponding predefined polymarker bundles of ' //
     4             'the WDT.')

C  bundif = randomly selected bundle to be shown incorrectly
      BUNDIF = RNDINT(1, NUMBUN)
      CALL DRWPMB (NUMBUN, BUNDIS, BUNDIF)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES > 5: Which pair of markers does NOT match?',
     2             NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_comp_tables
500   CONTINUE

C *** *** *** ***  predefined bundle descriptions

      CALL SETMSG ('3 6 20', 'The appearance of predefined '    //
     1             'polymarker bundles should agree with the '  //
     2             'descriptions supplied by the implementor.')

      NUMBUN = MIN(8, NPREI)
C  bundis = distinct bundles to be displayed, chosen from [1,nprei]
      CALL DISPMB (NUMBUN, 1, NPREI, BUNDIS)
      CALL SRTIAR (NUMBUN, BUNDIS)

C  set position and label
      XA(1) = 0.35
      YINCR = 0.1
      YLOC  = 0.9
      YBOT = YLOC-0.3*YINCR
      YTOP = YLOC+0.3*YINCR
      CALL VISLAB ('Bundle#',       'R', 0.02, 0.15, YBOT,YTOP)
      CALL VISLAB ('  Marker type', 'R', 0.50, 0.65, YBOT,YTOP)
      CALL VISLAB ('  Width-scale', 'R', 0.65, 0.80, YBOT,YTOP)
      CALL VISLAB ('  Color-index', 'R', 0.80, 0.95, YBOT,YTOP)

C  draw polymarker and its pdmt, pdmw, pdci
      DO 600 IX = 1, NUMBUN
         YLOC  = YLOC-YINCR
         CALL PQPPMR (SPECWT, BUNDIS(IX), ERRIND, PDMT, PMKS, PDCI)
         CALL CHKINQ ('pqppmr', ERRIND)
         YA(1) = YLOC
         YA(2) = YLOC
         YBOT = YLOC-0.3*YINCR
         YTOP = YLOC+0.3*YINCR
         WRITE (LNTID, '(I5,A)') BUNDIS(IX), ': '
         CALL VISLAB (LNTID(1:7), 'R', 0.02,0.15, YBOT,YTOP)
         CALL PSPMI (BUNDIS(IX))
         CALL PPM  (1, XA,YA)
         IF (PDMT.LT.PPOINT .OR. PDMT.GT.PXMARK) THEN
            WRITE (LNTID, '(I5)') PDMT
         ELSE
            LNTID = ' ' // MTNAME(PDMT)
         ENDIF
         CALL VISLAB (LNTID(1:ITRIM(LNTID)), 'L', 0.50, 0.65, YBOT,YTOP)
         WRITE (LNTID, '(F8.3)') PMKS
         CALL VISLAB (LNTID(1:8), 'R', 0.65, 0.80, YBOT,YTOP)
         WRITE (LNTID, '(I5)')   PDCI
         CALL VISLAB (LNTID(1:5), 'R', 0.80, 0.95, YBOT,YTOP)
600   CONTINUE

      IF (DYN('PREDEFINED POLYMARKER BUNDLES: Does the appearance ' //
     1        'of each polymarker agree with the displayed aspect ' //
     2        'values for that bundle?')) THEN
         CALL DYNPF ('PREDEFINED POLYMARKER BUNDLES: If the '        //
     1               'implementor provides external documentation, ' //
     2               'is it consistent with the polymarker '         //
     3               'appearance and displayed aspect values for '   //
     4               'every bundle identifier?', 'Y')
      ELSE
         CALL OPFAIL
      ENDIF

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
