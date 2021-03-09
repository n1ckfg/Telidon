C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/10                        *
C  *    TEST TITLE : Appearance of predefined text         *
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

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

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

      INTEGER   PICSTR, TXCI, IX, CLEN
      INTEGER   NPREI, NUMBUN, BUNDIS(8), BUNDIF, PDFN, PDPR, PDCI
      INTEGER   RNDINT, IARFND
      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5
      REAL      RDUM1, RDUM2, RDUM3, RDUM4

      REAL      YLOC, YINCR, YBOT,YTOP, PDEX, PDSP

      LOGICAL   DYN

      CHARACTER LNTID*40, PRECNM(PSTRP:PSTRKP)*6

      DATA PRECNM / 'STRING', 'CHAR', 'STROKE' /

      CALL INITGL ('04.02.03.02/10')

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

C  nprei = number of predefined text bundles
      CALL PQTXF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1           RDUM1, RDUM2, IDUM5, RDUM3, RDUM4, NPREI)
      CALL CHKINQ ('pqtxf', ERRIND)

C *** *** *** *** predefined text bundles 1-6

C  mark start of text bundles 1-6
      CALL PLB (1)

C  use first 6 indices + 1 duplicate
      NUMBUN = 7
      CALL RNPERM (7, BUNDIS)
C  location of #7
      BUNDIF = IARFND(7, 7, BUNDIS)
      BUNDIS(BUNDIF) = RNDINT(1,6)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '           //
     1             'workstation>, the first 6 defined text bundles ' //
     2             'of the WSL should appear as specified in the '   //
     3             'corresponding predefined text bundles of the WDT.')

      CALL DRWTXT (NUMBUN, BUNDIS, BUNDIF)
C  mark end of bundles 1-6
      CALL PLB (2)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, '  //
     1             'INDICES 1-6: Which pair of text primitives does ' //
     2             'NOT match?', NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C *** *** *** *** predefined text bundles > 6

C  skip if there are only 6 bundles
      IF (NPREI .LE. 6) THEN
         CALL INMSG ('Skip test of bundles > 6, only 6 predefined ' //
     1               'bundles supported.')
         GOTO 500
      ENDIF

C  numbun = number of bundles beyond #6 to be displayed
      NUMBUN = MIN (8, NPREI-6)
C  select bundles (as distinct as possible) from list of
C    predefined bundles [7, nprei]
      CALL DISTXB (NUMBUN, 7, NPREI, BUNDIS)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '          //
     1             'workstation>, the defined text bundles > 6 of ' //
     2             'the WSL should appear as specified in the '     //
     3             'corresponding predefined text bundles of the WDT.')

C  bundif = randomly selected bundle to be shown incorrectly
      BUNDIF = RNDINT(1, NUMBUN)
      CALL DRWTXT (NUMBUN, BUNDIS, BUNDIF)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, '  //
     1             'INDICES > 6: Which pair of text primitives does ' //
     2             'NOT match?', NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C  end_comp_tables
500   CONTINUE

C *** *** *** ***  predefined bundle descriptions

      CALL SETMSG ('3 6 20', 'The appearance of predefined ' //
     1             'text bundles should agree with the '     //
     2             'descriptions supplied by the implementor.')

      NUMBUN = MIN (8, NPREI)
C  bundis = distinct bundles to be displayed, chosen from [1,nprei]
      CALL DISTXB (NUMBUN, 1, NPREI, BUNDIS)
      CALL SRTIAR (NUMBUN, BUNDIS)

C  set all ASFs to BUNDLED
      CALL SETASF (PBUNDL)
      YLOC = 0.8
      YINCR = 0.1
      CALL PSCHH (0.03)
      CALL PSTXAL (PALEFT, PAHALF)
      DO 550 IX = 1, NUMBUN
         CALL PSTXI (BUNDIS(IX))
         CALL PTX (0.2, YLOC, 'Phigs')
         YLOC = YLOC - YINCR
550   CONTINUE

C  set all ASFs to INDIVIDUAL
      CALL SETASF (PINDIV)

C  set label
      YLOC  = 0.9
      YBOT = YLOC-0.3*YINCR
      YTOP = YLOC+0.3*YINCR
      CALL VISLAB ('Bundle#',   'R', 0.02, 0.15, YBOT,YTOP)
      CALL VISLAB ('     Font', 'R', 0.40, 0.50, YBOT,YTOP)
      CALL VISLAB ('Precision', 'R', 0.53, 0.63, YBOT,YTOP)
      CALL VISLAB ('Expansion', 'R', 0.66, 0.76, YBOT,YTOP)
      CALL VISLAB ('  Spacing', 'R', 0.76, 0.86, YBOT,YTOP)
      CALL VISLAB ('    Color', 'R', 0.86, 0.96, YBOT,YTOP)

C  display and label values for pdfn, pdpr, pdex, pdsp, pdci
      DO 600 IX = 1, NUMBUN
         YLOC = YLOC - YINCR
         CALL PQPTXR (SPECWT, BUNDIS(IX), ERRIND, PDFN, PDPR, PDEX,
     1                PDSP, PDCI)
         CALL CHKINQ ('pqptxr', ERRIND)

         YBOT = YLOC-0.3*YINCR
         YTOP = YLOC+0.3*YINCR

         WRITE (LNTID, '(I5,A)') BUNDIS(IX), ': '
         CALL VISLAB (LNTID(1:7), 'R', 0.02, 0.15, YBOT,YTOP)
         WRITE (LNTID, '(I5)') PDFN
         CALL VISLAB (LNTID(1:5), 'R', 0.40, 0.50, YBOT,YTOP)

         IF (PDPR.GE.PSTRP .AND. PDPR.LE.PSTRKP) THEN
            LNTID = ' ' // PRECNM(PDPR)
            CLEN = 7
         ELSE
            WRITE (LNTID, '(I5)') PDPR
            CLEN = 5
         ENDIF
         CALL VISLAB (LNTID(1:CLEN), 'R', 0.53, 0.63, YBOT,YTOP)

         WRITE (LNTID, '(F7.3)') PDEX
         CALL VISLAB (LNTID(1:7), 'R', 0.66, 0.76, YBOT,YTOP)
         WRITE (LNTID, '(F7.3)') PDSP
         CALL VISLAB (LNTID(1:7), 'R', 0.76, 0.86, YBOT,YTOP)
         WRITE (LNTID, '(I5)') PDCI
         CALL VISLAB (LNTID(1:5), 'R', 0.86, 0.96, YBOT,YTOP)

600   CONTINUE

      IF (DYN('PREDEFINED TEXT BUNDLES: Does the appearance of ' //
     1        'each text primitive agree with the displayed '    //
     2        'aspect values for that bundle?')) THEN
         CALL DYNPF ('PREDEFINED TEXT BUNDLES: If the implementor ' //
     1               'provides external documentation, is it '      //
     2               'consistent with the text appearance and '     //
     3               'displayed aspect values for every bundle '    //
     4               'identifier?', 'Y')
      ELSE
         CALL OPFAIL
      ENDIF

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
