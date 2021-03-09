C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/10                        *
C  *    TEST TITLE : Appearance of predefined edge bundles *
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
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C type of returned value
      INTEGER    PSET, PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

      INTEGER  PICSTR, TXCI
      INTEGER  NPREI, NUMBUN, BUNDIS(8), BUNDIF, IX, PDEF, PDET, PDCI
      INTEGER  RNDINT, IARFND, NUMET, ITRIM, NPTS(1)
      INTEGER  IDUM1, IDUM2

      REAL     PDEW, XA(4), YA(4), YLOC, YBOT, YTOP, YINCR
      REAL     RDUM1, RDUM2, RDUM3

      LOGICAL  DYN

      CHARACTER  LNTID*40

      CALL INITGL ('04.02.05.03/10')

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

C  use bundle attributes
      CALL SETASF (PBUNDL)
C  set interior style attribute ASF to INDIVIDUAL
      CALL PSIASF (PIS, PINDIV)
      CALL PSIASF (PICI, PINDIV)

C  set interior style = EMPTY, interior color index = 1
      CALL PSIS (PISEMP)
      CALL PSICI (1)

C  nprei  = number of predefined bundles
C  numet = number of edge types
      CALL PQEDF (SPECWT, 0, ERRIND, NUMET, IDUM1, IDUM2, RDUM1, RDUM2,
     1            RDUM3, NPREI)
      CALL CHKINQ ('pqedf', ERRIND)

C
C  *** *** ***   predefined edge bundles 1-5   *** *** ***
C
C  mark start of edge bundles 1-5
       CALL PLB (1)

C  bundis = bundles to be displayed (1 to 5 , with one repeated)
C  bundif = location of repeated bundle identifier (so that all 5
C           may be verified)
      NUMBUN = 6
      CALL RNPERM (NUMBUN, BUNDIS)
      BUNDIF = IARFND(NUMBUN, NUMBUN, BUNDIS)
      BUNDIS(BUNDIF) = RNDINT(1, NUMBUN-1)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '            //
     1             'workstation>, the first five defined edge '       //
     2             'bundles of the WSL should appear as specified '   //
     3             'in the corresponding predefined edge bundles of ' //
     4             'the WDT.')

C  display and label results
      CALL DRWEDB (NUMBUN, BUNDIS, BUNDIF, NUMET)

C  mark end of bundles 1-5
      CALL PLB (2)
      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES 1-5; which pair of edges does NOT match?',
     2             NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

C
C  *** *** ***   predefined edge bundles > 5   *** *** ***
C
C  if nprei <= 5 then skip to end_comp_tables
      IF (NPREI .LE. 5) THEN
         CALL INMSG ('Skip test of bundles > 5, only 5 predefined ' //
     1               'bundles supported.')
         GOTO 500
      ENDIF

C  get distinct bundles to be displayed
C  numbun = number of distinct bundles to be displayed
      NUMBUN = MIN (8, NPREI-5)
      CALL DISEDB (NUMBUN, 6, NPREI, BUNDIS)

      CALL SETMSG ('3 6 20 24', 'Immediately after <open '          //
     1             'workstation>, the defined edge bundles > 5 of ' //
     2             'the WSL should appear as specified in the '     //
     3             'corresponding predefined edge bundles of the '  //
     4             'WDT.')

C  bundif = randomly selected bundle from bundis
      BUNDIF = RNDINT (1, NUMBUN)

C  display and label bundis
      CALL DRWEDB (NUMBUN, BUNDIS, BUNDIF, NUMET)

      CALL DCHPFV ('WORKSTATION DESCRIPTION AND STATE LIST TABLES, ' //
     1             'INDICES > 5; Which pair of edges does NOT match?',
     2             NUMBUN, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1, 2)

C  end_comp_tables:
500   CONTINUE

C  *** ***  predefined bundle descriptions   *** ***
C
      CALL SETMSG ('3 6 20', 'The appearance of predefined edge ' //
     1             'bundles should agree with the descriptions '  //
     2             'supplied by the implementor.')

      NUMBUN = MIN (8, NPREI)
C  get distinct bundles to be displayed, chosed from [1,nprei]
      CALL DISEDB (NUMBUN, 1, NPREI, BUNDIS)
C  sorted
      CALL SRTIAR (NUMBUN, BUNDIS)

C  set position and label
      XA(1) = 0.15
      XA(2) = 0.15
      XA(3) = 0.45
      YINCR = 1.0 / (NUMBUN+2)
      YLOC = 0.9
      YBOT = YLOC-0.3*YINCR
      YTOP = YLOC+0.3*YINCR
      CALL VISLAB ('Bundle#',      'R', 0.02, 0.15, YBOT, YTOP)
      CALL VISLAB ('  Edgeflag',   'R', 0.50, 0.60, YBOT, YTOP)
      CALL VISLAB ('  Edgetype',   'R', 0.60, 0.70, YBOT, YTOP)
      CALL VISLAB ('  Width-scale','R', 0.70, 0.85, YBOT, YTOP)
      CALL VISLAB ('  Color'      ,'R', 0.85, 0.95, YBOT, YTOP)

C  draw edge and its pdef, pdet, pdew, pdci
      NPTS(1) = 3
      DO 600 IX = 1, NUMBUN
         YLOC = YLOC - YINCR
         CALL PQPEDR (SPECWT, BUNDIS(IX), ERRIND, PDEF, PDET,
     1                PDEW, PDCI)
         CALL CHKINQ ('pqpedr', ERRIND)
         YBOT = YLOC - 0.3*YINCR
         YTOP = YLOC + 0.3*YINCR
         YA(1) = YBOT
         YA(2) = YTOP
         YA(3) = YBOT
         WRITE (LNTID, '(I5,A)') BUNDIS(IX), ': '
         CALL VISLAB (LNTID(1:7), 'R', 0.02, 0.12, YBOT, YTOP)
         CALL PSEDI (BUNDIS(IX))
         CALL PFAS (1,NPTS,XA,YA)

         IF (PDEF.EQ.PON) THEN
            LNTID = 'On'
         ELSEIF (PDEF.EQ.POFF) THEN
            LNTID = 'Off'
         ELSE
            WRITE (LNTID, '(I5)') PDEF
         ENDIF
         CALL VISLAB (LNTID(1:ITRIM(LNTID)), 'R', 0.50,0.60, YBOT,YTOP)
         WRITE (LNTID, '(I5)') PDET
         CALL VISLAB (LNTID(1:5), 'R', 0.60, 0.70, YBOT, YTOP)
         WRITE (LNTID, '(F8.3)') PDEW
         CALL VISLAB (LNTID(1:8), 'R', 0.70, 0.85, YBOT, YTOP)
         WRITE (LNTID, '(I5)') PDCI
         CALL VISLAB (LNTID(1:5), 'R', 0.85, 0.95, YBOT, YTOP)
600      CONTINUE

      IF (DYN ('PREDEFINED EDGE BUNDLES: Does the appearance ' //
     1         'of each edge agree with the displayed aspect ' //
     2         'values for that bundle?')) THEN
         CALL DYNPF ('PREDEFINED EDGE BUNDLES: If the implementor ' //
     1               'provides external documentation, is it '      //
     2               'consistent with the edge appearance and '     //
     3               'displayed aspect values for every bundle '    //
     4               'identifier?', 'Y')

      ELSE
         CALL OPFAIL
      ENDIF

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
