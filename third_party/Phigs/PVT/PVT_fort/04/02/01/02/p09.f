C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/09                        *
C  *    TEST TITLE : Appearance of predefined polyline     *
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

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

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
      INTEGER   NPREI, NUMBUN, BUNDIS(8), BUNDIF, IX, PDLT, PDCI
      INTEGER   RNDINT, IARFND, ITRIM

      REAL      PDLW, XA(2), YA(2), YLOC, YINCR, YBOT,YTOP

      LOGICAL   DYN

      INTEGER   IDUM1, IDUM2, IDUM3
      REAL      RDUM1, RDUM2, RDUM3

      CHARACTER LNTID*40, LTNAME(PLSOLI:PLDASD)*10

      DATA LTNAME / 'Solid', 'Dashed', 'Dotted', 'Dash-dot' /

      CALL INITGL ('04.02.01.02/09')

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

C  nprei = number of predefined polyline bundles
      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3, RDUM1,
     1            RDUM2, RDUM3, NPREI)
      CALL CHKINQ ('pqplf', ERRIND)

C *** *** *** *** predefined polyline bundles 1-5

C  mark start of polyline bundles 1-5
      CALL PLB (1)

C  use first 5 indices + 1 duplicate
      NUMBUN = 6
      CALL RNPERM (6, BUNDIS)
C  location of #6
      BUNDIF = IARFND(6, 6, BUNDIS)
      BUNDIS(BUNDIF) = RNDINT(1,5)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '          //
     1             'workstation>, the first five defined polyline ' //
     2             'bundles of the WSL should appear as specified ' //
     3             'in the corresponding predefined polyline '      //
     4             'bundles of the WDT.')

      CALL DRWPLB (NUMBUN, BUNDIS, BUNDIF)
C  mark end of bundles 1-5
      CALL PLB (2)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES 1-5: Which pair of lines does NOT match?',
     2             NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C *** *** *** *** predefined polyline bundles > 5

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
      CALL DISPLB (NUMBUN, 6, NPREI, BUNDIS)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '           //
     1             'workstation>, the defined polyline bundles > '   //
     2             '5 of the WSL should appear as specified in the ' //
     3             'corresponding predefined polyline bundles of '   //
     4             'the WDT.')

C  bundif = randomly selected bundle to be shown incorrectly
      BUNDIF = RNDINT(1, NUMBUN)
      CALL DRWPLB (NUMBUN, BUNDIS, BUNDIF)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES > 5: Which pair of lines does NOT match?',
     2             NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_comp_tables
500   CONTINUE

C *** *** *** ***  predefined bundle descriptions

      CALL SETMSG ('3 6 20', 'The appearance of predefined polyline ' //
     1             'bundles should agree with the descriptions '      //
     2             'supplied by the implementor.')

      NUMBUN = MIN(8, NPREI)
C  bundis = distinct bundles to be displayed, chosen from [1,nprei]
      CALL DISPLB (NUMBUN, 1, NPREI, BUNDIS)
      CALL SRTIAR (NUMBUN, BUNDIS)

C  set position and label
      XA(1) = 0.20
      XA(2) = 0.50
      YINCR = 0.1
      YLOC  = 0.9
      YBOT = YLOC-0.3*YINCR
      YTOP = YLOC+0.3*YINCR
      CALL VISLAB ('Bundle#',       'R', 0.02, 0.15, YBOT,YTOP)
      CALL VISLAB ('  Linetype',    'R', 0.50, 0.65, YBOT,YTOP)
      CALL VISLAB ('  Width-scale', 'R', 0.65, 0.80, YBOT,YTOP)
      CALL VISLAB ('  Color-index', 'R', 0.80, 0.95, YBOT,YTOP)

C  draw polyline and its pdlt, pdlw, pdci
      DO 600 IX = 1, NUMBUN
         YLOC  = YLOC-YINCR
         CALL PQPPLR (SPECWT, BUNDIS(IX), ERRIND, PDLT, PDLW, PDCI)
         CALL CHKINQ ('pqpplr', ERRIND)
         YA(1) = YLOC
         YA(2) = YLOC
         YBOT = YLOC-0.3*YINCR
         YTOP = YLOC+0.3*YINCR
         WRITE (LNTID, '(I5,A)') BUNDIS(IX), ': '
         CALL VISLAB (LNTID(1:7), 'R', 0.02,0.15, YBOT,YTOP)
         CALL PSPLI (BUNDIS(IX))
         CALL PPL  (2, XA,YA)

         IF (PDLT.LT.PLSOLI .OR. PDLT.GT.PLDASD) THEN
            WRITE (LNTID, '(I5)') PDLT
         ELSE
            LNTID = ' ' // LTNAME(PDLT)
         ENDIF
         CALL VISLAB (LNTID(1:ITRIM(LNTID)), 'L', 0.50, 0.65, YBOT,YTOP)
         WRITE (LNTID, '(F8.3)') PDLW
         CALL VISLAB (LNTID(1:8), 'R', 0.65, 0.80, YBOT,YTOP)
         WRITE (LNTID, '(I5)')   PDCI
         CALL VISLAB (LNTID(1:5), 'R', 0.80, 0.95, YBOT,YTOP)
600   CONTINUE

      IF (DYN('PREDEFINED POLYLINE BUNDLES: Does the appearance ' //
     1        'of each polyline agree with the displayed aspect ' //
     2        'values for that bundle?')) THEN
         CALL DYNPF ('PREDEFINED POLYLINE BUNDLES: If the '          //
     1               'implementor provides external documentation, ' //
     2               'is it consistent with the polyline '           //
     3               'appearance and displayed aspect values for '   //
     4               'every bundle identifier?', 'Y')
      ELSE
         CALL OPFAIL
      ENDIF

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
