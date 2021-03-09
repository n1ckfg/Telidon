C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.01/02                           *
C  *    TEST TITLE : Selective control of primitive        *
C  *                 aspects                               *
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

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

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
      INTEGER    PEDT,     PEWSC,    PEDCI
      PARAMETER (PEDT=15,  PEWSC=16, PEDCI=17)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C aspect visibility
      INTEGER    DISPLY,     SUPPRS
      PARAMETER (DISPLY = 0, SUPPRS = 1)

C alternative values for all attributes:
      INTEGER    VLN  (DISPLY:SUPPRS), VPLCI(DISPLY:SUPPRS)
      INTEGER    VMK  (DISPLY:SUPPRS), VPMCI(DISPLY:SUPPRS)
      INTEGER    VTXFN(DISPLY:SUPPRS), VTXPR(DISPLY:SUPPRS)
      INTEGER    VTXCI(DISPLY:SUPPRS), VIS  (DISPLY:SUPPRS)
      INTEGER    VISI (DISPLY:SUPPRS), VICI (DISPLY:SUPPRS)
      INTEGER    VEDFG(DISPLY:SUPPRS), VEDT (DISPLY:SUPPRS)
      INTEGER    VEDCI(DISPLY:SUPPRS)

      INTEGER    PICSTR, TXCI, IX, NDISCT, NUMLIN,NGPRIM, RNDINT
      INTEGER    TYPSRC, WIDSRC, COLSRC, NSIZ, IPRIM, IBSW, NIS,THISIS
      INTEGER    FNTSRC, PRCSRC, EXPSRC, SPCSRC, FLGSRC, ED1,ED2
      INTEGER    IIX1,IIX2, COLIA(2,2), NPTS(1), NEDTYP,NEDWID
      INTEGER    P1(10),P2(10),P3(10),P4(10),P5(10), NEXT
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6

C alternative values for all attributes:
      REAL       VLWSC(DISPLY:SUPPRS), VMKSC(DISPLY:SUPPRS)
      REAL       VCHXP(DISPLY:SUPPRS), VCHSP(DISPLY:SUPPRS)
      REAL       VEWSC(DISPLY:SUPPRS)
      REAL       MINCHX,MAXCHX,CXP1,CXP2
      REAL       XA(10),YA(10),ZA(10), YTOP,YLOC,YINCR, NOMSIZ
      REAL       NPCX,NPCY,NPCPWC, TDX(2),TDY(2),TDZ(2), XPOS
      REAL       RDUM1,RDUM2,RDUM3

      LOGICAL    DCHFLV, STYAVL(PHOLLO:PISEMP)

      CHARACTER  TXT*14

      DATA  STYAVL / 5 * .FALSE. /

      CALL INITGL ('04.03.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (102)

C  try to set color table with #1,2,3 distinct
      CALL DISCOL (3, WKID, NDISCT)
C  use IBSW to switch individual/bundled
      IBSW = PINDIV+PBUNDL

C  *** *** *** ***   polyline   *** *** *** ***

      CALL SETMSG ('1 4 5 6 7 8 9', 'The program should be able to ' //
     1             'specify each of the non-geometric aspects of '   //
     2             'polyline primitives using either individual or ' //
     3             'bundled control.')
      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMSIZ,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)

C  aspects to be displayed:
C  linetype = 2, linewidth = 0.05 in WC, linecolor = 2
      VLN  (DISPLY) = 2
      VLWSC(DISPLY) = 0.05 / (NOMSIZ * WCPDC)
      VPLCI(DISPLY) = 2
C  aspects to be suppressed:
C  linetype = 1, linewidth = 0.0001 in WC, linecolor = 1
      VLN  (SUPPRS) = 1
      VLWSC(SUPPRS) = 0.0001 / (NOMSIZ * WCPDC)
      VPLCI(SUPPRS) = 1

C  set individual color indices for other primitives to 3, to make
C    sure they don't interact with polyline.
      CALL PSPMCI (3)
      CALL PSTXCI (3)
      CALL PSICI  (3)
      CALL PSEDCI (3)

C  number of lines to be displayed
      NUMLIN = 6
C  primitive to be drawn incorrectly
      NGPRIM = RNDINT (1,NUMLIN)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      XA(1) = 0.2
      XA(2) = 0.8
      ZA(1) = 0.5
      ZA(2) = 0.5
C  ensure both individual and bundle are picked for each aspect
      CALL RNPERM (NUMLIN, P1)
      CALL RNPERM (NUMLIN, P2)
      CALL RNPERM (NUMLIN, P3)

C  loop to draw primitives
      DO 100 IX = 1,NUMLIN
C  randomly pick source for aspects:
C  assume here that bundle/individ represented by 0/1
         TYPSRC = MOD (P1(IX), 2)
         WIDSRC = MOD (P2(IX), 2)
         COLSRC = MOD (P3(IX), 2)

C  set bundle #ix to displayed aspects, for BUNDLED source
C               and suppressed aspects, for INDIVIDUAL source
         CALL PSPLR (WKID, IX, VLN(TYPSRC),VLWSC(WIDSRC),VPLCI(COLSRC))
         CALL PSPLI (IX)
C  set individual attributes
C                 to displayed aspects, for INDIVIDUAL source
C               and suppressed aspects, for BUNDLED source
         CALL PSLN   (VLN  (IBSW-TYPSRC))
         CALL PSLWSC (VLWSC(IBSW-WIDSRC))
         CALL PSPLCI (VPLCI(IBSW-COLSRC))
C  set ASF flags in accordance with typsrc,widsrc,colsrc
         CALL PSIASF (PLN,   TYPSRC)
         CALL PSIASF (PLWSC, WIDSRC)
         CALL PSIASF (PPLCI, COLSRC)

         IF (IX .EQ. NGPRIM) THEN
C  set ASF flag NOT in accordance with typsrc
            CALL PSIASF (PLN,   IBSW-TYPSRC)
            CALL PSIASF (PLWSC, IBSW-WIDSRC)
            CALL PSIASF (PPLCI, IBSW-COLSRC)
         ENDIF
         YA(1) = YLOC
         YA(2) = YLOC
         IF (IX .LE. NUMLIN/2) THEN
            CALL PPL (2, XA,YA)
         ELSE
            CALL PPL3 (2, XA,YA,ZA)
         ENDIF
         YLOC = YLOC-YINCR
C  next ix
100   CONTINUE
      CALL DCHPFV ('ASF CONTROL OF POLYLINE: Which line is different?',
     1             NUMLIN, NGPRIM)
      CALL PEMST (102)

C  *** *** *** ***   polymarker   *** *** *** ***

      CALL SETMSG ('1 4 5 6 7 8 9', 'The program should be able to ' //
     1             'specify each of the non-geometric aspects of '   //
     2             'polymarker primitives using either individual '  //
     3             'or bundled control.')
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMSIZ,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)

C  aspects to be displayed:
C  markertype = 4, markerwidth = 0.05 in WC, markercolor = 2
      VMK  (DISPLY) = 4
      VMKSC(DISPLY) = 0.05 / (NOMSIZ * WCPDC)
      VPMCI(DISPLY) = 2
C  aspects to be suppressed:
C  markertype = 5, markerwidth = 0.03 in WC, markercolor = 1
      VMK  (SUPPRS) = 5
      VMKSC(SUPPRS) = 0.03 / (NOMSIZ * WCPDC)
      VPMCI(SUPPRS) = 1

C  set individual color indices for other primitives to 3, to make
C    sure they don't interact with polymarker.
      CALL PSPLCI (3)
      CALL PSTXCI (3)
      CALL PSICI  (3)
      CALL PSEDCI (3)

C  number of lines to be displayed
      NUMLIN = 6
C  primitive to be drawn incorrectly
      NGPRIM = RNDINT (1,NUMLIN)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      CALL SETRVS ('0.4,0.6,0.8', XA, NSIZ)
      CALL SETRVS ('0.5,0.5,0.5', ZA, NSIZ)
C  ensure both individual and bundle are picked for each aspect
      CALL RNPERM (NUMLIN, P1)
      CALL RNPERM (NUMLIN, P2)
      CALL RNPERM (NUMLIN, P3)

C  loop to draw primitives
      DO 200 IX = 1,NUMLIN
C  randomly pick source for aspects:
C  assume here that bundle/individ represented by 0/1
         TYPSRC = MOD (P1(IX), 2)
         WIDSRC = MOD (P2(IX), 2)
         COLSRC = MOD (P3(IX), 2)

C  set bundle #ix to displayed aspects, for BUNDLED source
C               and suppressed aspects, for INDIVIDUAL source
         CALL PSPMR (WKID, IX, VMK(TYPSRC),VMKSC(WIDSRC),VPMCI(COLSRC))
         CALL PSPMI (IX)

C  set individual attributes
C                 to displayed aspects, for INDIVIDUAL source
C               and suppressed aspects, for BUNDLED source
         CALL PSMK   (VMK  (IBSW-TYPSRC))
         CALL PSMKSC (VMKSC(IBSW-WIDSRC))
         CALL PSPMCI (VPMCI(IBSW-COLSRC))

C  set ASF flags in accordance with typsrc,widsrc,colsrc
         CALL PSIASF (PMK,   TYPSRC)
         CALL PSIASF (PMKSC, WIDSRC)
         CALL PSIASF (PPMCI, COLSRC)

         IF (IX .EQ. NGPRIM) THEN
C  set ASF flags NOT in accordance with typsrc, etc.
            CALL PSIASF (PMK,   IBSW-TYPSRC)
            CALL PSIASF (PMKSC, IBSW-WIDSRC)
            CALL PSIASF (PPMCI, IBSW-COLSRC)
         ENDIF

         YA(1) = YLOC
         YA(2) = YLOC
         YA(3) = YLOC

         IF (IX .LE. NUMLIN/2) THEN
            CALL PPM (3, XA,YA)
         ELSE
            CALL PPM3 (3, XA,YA,ZA)
         ENDIF
         YLOC = YLOC-YINCR
C  next ix
200   CONTINUE
      CALL DCHPFV ('ASF CONTROL OF POLYMARKER: Which marker is ' //
     1             'different?', NUMLIN, NGPRIM)
      CALL PEMST (102)

C  *** *** *** ***   text   *** *** *** ***

      CALL SETMSG ('1 4 5 6 7 8 9', 'The program should be able to ' //
     1             'specify each of the non-geometric aspects of '   //
     2             'text and annotation text primitives using '      //
     3             'either individual or bundled control.')

C  aspects to be displayed: font = 2, precision = STROKE,
C  expansion = 0.5, spacing = 0.3, textcolor = 2
      VTXFN(DISPLY) = 2
      VTXPR(DISPLY) = PSTRKP
      VCHSP(DISPLY) = 0.3
      VTXCI(DISPLY) = 2

C  try to pick two distinct values for char-exp within the limits
C  of the workstation.
      CALL PQTXF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1            RDUM1, RDUM2, IDUM5, MINCHX, MAXCHX, IDUM6)
      CALL CHKINQ ('pqtxf', ERRIND)
      IF (MAXCHX .LE. 2.5*MINCHX) THEN
C        range of factors small - use whole range
         CXP1 = MINCHX
         CXP2 = MAXCHX
      ELSEIF (MAXCHX .LE. 1) THEN
         CXP2 = MAXCHX
         CXP1 = CXP2 / 2.5
      ELSEIF (MINCHX .GE. 1) THEN
         CXP1 = MINCHX
         CXP2 = 2.5 * CXP1
      ELSE
         CXP1 = MAX(0.5, MINCHX)
         CXP2 = MIN(1.2, MAXCHX)
      ENDIF

      VCHXP(DISPLY) = CXP1

C  aspects to be suppressed: font = 1, precision = STRING,
C  expansion = 1.2, spacing = -0.3, textcolor = 1
      VTXFN(SUPPRS) = 1
      VTXPR(SUPPRS) = PSTRP
      VCHSP(SUPPRS) = -0.3
      VTXCI(SUPPRS) = 1
      VCHXP(SUPPRS) = CXP2

C  set individual color indices for other primitives to 3, to make
C    sure they don't interact with text.
      CALL PSPLCI (3)
      CALL PSPMCI (3)
      CALL PSICI  (3)
      CALL PSEDCI (3)

C  number of lines to be displayed
      NUMLIN = 6
C  primitive to be drawn incorrectly
      NGPRIM = RNDINT (1,NUMLIN)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
C  use iprim to pick out different primitives
      IPRIM = 1
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)
      CALL PSCHH  (0.4*YINCR)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PSATCH (0.4*YINCR * NPCPWC)
      CALL PSATAL (PALEFT, PAHALF)
      XPOS = 0.2
      TXT  = 'Who''s special?'
C  ensure both individual and bundle are picked for each aspect
      CALL RNPERM (NUMLIN, P1)
      CALL RNPERM (NUMLIN, P2)
      CALL RNPERM (NUMLIN, P3)
      CALL RNPERM (NUMLIN, P4)
      CALL RNPERM (NUMLIN, P5)

C  loop to draw primitives
      DO 300 IX = 1,NUMLIN
C  randomly pick source for aspects:
C  assume here that bundle/individ represented by 0/1
         FNTSRC = MOD (P1(IX), 2)
         PRCSRC = MOD (P2(IX), 2)
         EXPSRC = MOD (P3(IX), 2)
         SPCSRC = MOD (P4(IX), 2)
         COLSRC = MOD (P5(IX), 2)

C  set bundle #ix to displayed aspects, for BUNDLED source
C               and suppressed aspects, for INDIVIDUAL source
         CALL PSTXR (WKID, IX, VTXFN(FNTSRC), VTXPR(PRCSRC),
     1               VCHXP(EXPSRC), VCHSP(SPCSRC), VTXCI(COLSRC))
         CALL PSTXI (IX)

C  set individual attributes
C                 to displayed aspects, for INDIVIDUAL source
C               and suppressed aspects, for BUNDLED source
         CALL PSTXFN (VTXFN(IBSW-FNTSRC))
         CALL PSTXPR (VTXPR(IBSW-PRCSRC))
         CALL PSCHXP (VCHXP(IBSW-EXPSRC))
         CALL PSCHSP (VCHSP(IBSW-SPCSRC))
         CALL PSTXCI (VTXCI(IBSW-COLSRC))

C     set ASF flags in accordance with
C       fntsrc, prcsrc, expsrc, spcsrc, colsrc
         CALL PSIASF (PTXFN, FNTSRC)
         CALL PSIASF (PTXPR, PRCSRC)
         CALL PSIASF (PCHXP, EXPSRC)
         CALL PSIASF (PCHSP, SPCSRC)
         CALL PSIASF (PTXCI, COLSRC)

         IF (IX .EQ. NGPRIM) THEN
C  set ASF flags NOT in accordance with xxxsrc
            CALL PSIASF (PTXFN, IBSW-FNTSRC)
            CALL PSIASF (PTXPR, IBSW-PRCSRC)
            CALL PSIASF (PCHXP, IBSW-EXPSRC)
            CALL PSIASF (PCHSP, IBSW-SPCSRC)
            CALL PSIASF (PTXCI, IBSW-COLSRC)
            NEXT = IPRIM
         ELSE
C  iprim ensures that each primitive is drawn correctly at least once
            NEXT = IPRIM + 1
         ENDIF

         IF (IPRIM .EQ. 1) THEN
            CALL PTX (XPOS, YLOC, TXT)
         ELSEIF (IPRIM .EQ. 2) THEN
            CALL SETRVS ('1,0', TDX, NSIZ)
            CALL SETRVS ('0,1', TDY, NSIZ)
            CALL SETRVS ('0,0', TDZ, NSIZ)
            CALL PTX3 (XPOS, YLOC, 0.5, TDX,TDY,TDZ, TXT)
         ELSEIF (IPRIM .EQ. 3) THEN
            CALL PATR (XPOS, YLOC, 0.0,0.0, TXT)
         ELSEIF (IPRIM .EQ. 4) THEN
            CALL PATR3 (XPOS, YLOC, 0.5, 0.0,0.0,0.0, TXT)
         ELSE
            CALL PTX (XPOS, YLOC, TXT)
         ENDIF
         YLOC = YLOC-YINCR
         IPRIM = NEXT
C  next ix
300   CONTINUE
      CALL DCHPFV ('ASF CONTROL OF TEXT: Which text is different?',
     1             NUMLIN, NGPRIM)
      CALL PEMST (102)

C  *** *** *** ***   interior bundle   *** *** *** ***

      CALL SETMSG ('1 4 5 6 7 8 9', 'The program should be able to ' //
     1             'specify each of the non-geometric aspects in '   //
     2             'the interior bundle using either individual or ' //
     3             'bundled control.')

C  set individual color indices for other primitives to 3, to make
C    sure they don't interact with interior.
      CALL PSPLCI (3)
      CALL PSPMCI (3)
      CALL PSTXCI (3)
      CALL PSEDCI (3)

C  *** *** *** ***   interior style   *** *** *** ***
C
C  aspects to be displayed:
C  interior style = HOLLOW, interior index = 1, interior-color = 2
      VIS (DISPLY) = PHOLLO
      VISI(DISPLY) = 1
      VICI(DISPLY) = 2
C  aspects to be suppressed:
C  interior style = EMPTY, interior index = 1, interior-color = 1
      VIS (SUPPRS) = PISEMP
      VISI(SUPPRS) = 1
      VICI(SUPPRS) = 1

      CALL ASFINT (VIS, VISI, VICI, NUMLIN, NGPRIM)

      IF (DCHFLV ('ASF CONTROL OF INTERIOR STYLE: Which interior ' //
     1            'is different?', NUMLIN, NGPRIM)) THEN
         CALL INMSG ('Failure occurred for interior style.')
         GOTO 490
      ENDIF
      CALL PEMST (102)

C  *** *** *** ***   interior index   *** *** *** ***

C  check available interior styles
      CALL PQIF (SPECWT, 0,0, ERRIND, NIS, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
      DO 410 IX = 1,ABS(NIS)
         CALL PQIF (SPECWT, IX,0, ERRIND, IDUM1, THISIS,
     1              IDUM2,IDUM3,IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS.GE.PHOLLO .AND. THISIS.LE.PISEMP) THEN
            STYAVL(THISIS) = .TRUE.
         ENDIF
410   CONTINUE

      IF (STYAVL(PHATCH)) THEN
C  using HATCH - get hatch styles
         THISIS = PHATCH
         CALL PQIF (SPECWT, 0,1, ERRIND, IDUM1,IDUM2,IDUM3, IIX1, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         CALL PQIF (SPECWT, 0,2, ERRIND, IDUM1,IDUM2,IDUM3, IIX2, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
      ELSEIF (STYAVL(PPATTR)) THEN
C  using PATTERN
         THISIS = PPATTR
         CALL PSPA (0.1, 0.05)
         IIX1 = 1
         IIX2 = 2
C  set up two distinct patterns
         CALL SETVAL ('1,1,1,0', COLIA)
         CALL PSPAR (WKID,1, 2,2, 1,1, 2,2, COLIA)
         CALL SETVAL ('0,0,1,0', COLIA)
         CALL PSPAR (WKID,2, 2,2, 1,1, 2,2, COLIA)
      ELSE
C  no style sensitive to interior style index is available
         GOTO 450
      ENDIF

C  interior indices now set;
C  aspects to be displayed:
C  interior style = int-style, interior index = iix1, interior-color = 2
      VIS (DISPLY) = THISIS
      VISI(DISPLY) = IIX1
      VICI(DISPLY) = 2
C  aspects to be suppressed:
C  interior style = int-style, interior index = iix2, interior-color = 1
      VIS (SUPPRS) = THISIS
      VISI(SUPPRS) = IIX2
      VICI(SUPPRS) = 1

      CALL ASFINT (VIS, VISI, VICI, NUMLIN, NGPRIM)

      IF (DCHFLV ('ASF CONTROL OF INTERIOR STYLE INDEX: Which ' //
     1            'interior is different?', NUMLIN, NGPRIM))   THEN
         CALL INMSG ('Failure occurred for interior style index.')
         GOTO 490
      ENDIF
      CALL PEMST (102)

C  end_int_index:
450   CONTINUE

C  *** *** *** ***   interior color   *** *** *** ***

C  if (number of distinct colors < 2) no color test
      IF (NDISCT .LT. 2) THEN
         CALL PASS
         GOTO 490
      ENDIF

      IF (STYAVL(PSOLID)) THEN
         THISIS = PSOLID
      ELSE
         THISIS = PHOLLO
      ENDIF

C  aspects to be displayed:
C  interior style = int-style, interior index = 1, interior-color = 2
      VIS (DISPLY) = THISIS
      VISI(DISPLY) = 1
      VICI(DISPLY) = 2
C  aspects to be suppressed:
C  interior style = int-style, interior index = 1, interior-color = 1
      VIS (SUPPRS) = THISIS
      VISI(SUPPRS) = 1
      VICI(SUPPRS) = 1

      CALL ASFINT (VIS, VISI, VICI, NUMLIN, NGPRIM)

      IF (DCHFLV ('ASF CONTROL OF INTERIOR COLOR: Which interior ' //
     1            'color is different?', NUMLIN, NGPRIM)) THEN
         CALL INMSG ('Failure occurred for interior color index.')
      ELSE
         CALL PASS
      ENDIF

C  end_int:
490   CONTINUE
      CALL PEMST (102)

C  *** *** *** ***   edge bundle   *** *** *** ***

      CALL SETMSG ('1 4 5 6 7 8 9', 'The program should be able to ' //
     1             'specify each of the non-geometric aspects in '   //
     2             'the edge bundle using either individual or '     //
     3             'bundled control.')

C  set individual color indices for other primitives to 3, to make
C    sure they don't interact with edge color.
      CALL PSPLCI (3)
      CALL PSPMCI (3)
      CALL PSTXCI (3)
      CALL PSICI  (3)

      CALL PQEDF (SPECWT, 0, ERRIND, NEDTYP, IDUM1, NEDWID, NOMSIZ,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqedf', ERRIND)
      NEDTYP = ABS(NEDTYP)

C  ed1,ed2 = two available edge types
      CALL PQEDF (SPECWT, 1, ERRIND, IDUM1, ED1, IDUM2,
     1            RDUM1,RDUM2,RDUM3, IDUM4)
      CALL CHKINQ ('pqedf', ERRIND)
      IF (NEDTYP .GT. 1) THEN
         CALL PQEDF (SPECWT, 2, ERRIND, IDUM1, ED2, IDUM2,
     1               RDUM1,RDUM2,RDUM3, IDUM4)
         CALL CHKINQ ('pqedf', ERRIND)
      ELSE
         ED2 = ED1
      ENDIF

C  *** *** *** ***   edge flag   *** *** *** ***
C
C  aspects to be displayed:
C  edge flag = ON, edgetype = ed2, edgewidth = 0.02 in WC, edgecolor = 2
      VEDFG(DISPLY) = PON
      VEDT (DISPLY) = ED2
      VEWSC(DISPLY) = 0.02 / (NOMSIZ * WCPDC)
      VEDCI(DISPLY) = 2
C  aspects to be suppressed:
C  edge flag = OFF, edgetype = ed1, edgewidth = 0.001 in WC, edgecolor = 1
      VEDFG(SUPPRS) = POFF
      VEDT (SUPPRS) = ED1
      VEWSC(SUPPRS) = 0.001 / (NOMSIZ * WCPDC)
      VEDCI(SUPPRS) = 1

C  set interior style = EMPTY
      CALL PSIASF (PIS, PINDIV)
      CALL PSIS   (PISEMP)

C  number of lines to be displayed
      NUMLIN = 6
C  primitive to be drawn incorrectly
      NGPRIM = RNDINT (1,NUMLIN)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      XA(1) = 0.2
      XA(2) = 0.2
      XA(3) = 0.8
      ZA(1) = 0.5
      ZA(2) = 0.5
      ZA(3) = 0.5
      NPTS(1) = 3
C  ensure both individual and bundle are picked for each aspect
      CALL RNPERM (NUMLIN, P1)
      CALL RNPERM (NUMLIN, P2)
      CALL RNPERM (NUMLIN, P3)
      CALL RNPERM (NUMLIN, P4)

      DO 500 IX = 1,NUMLIN

C  randomly pick source for aspects:
C  assume here that bundle/individ represented by 0/1
         FLGSRC = MOD (P1(IX), 2)
         TYPSRC = MOD (P2(IX), 2)
         WIDSRC = MOD (P3(IX), 2)
         COLSRC = MOD (P4(IX), 2)

C     set bundle #ix to displayed aspects, for BUNDLED source
C                  and suppressed aspects, for INDIVIDUAL source
         CALL PSEDR (WKID, IX, VEDFG(FLGSRC), VEDT(TYPSRC),
     1                         VEWSC(WIDSRC), VEDCI(COLSRC))
         CALL PSEDI (IX)
C     set individual attributes
C                    to displayed aspects, for INDIVIDUAL source
C                  and suppressed aspects, for BUNDLED source
         CALL PSEDFG (VEDFG(IBSW-FLGSRC))
         CALL PSEDT  (VEDT (IBSW-TYPSRC))
         CALL PSEWSC (VEWSC(IBSW-WIDSRC))
         CALL PSEDCI (VEDCI(IBSW-COLSRC))

C     set ASF flags in accordance with: flgsrc,typsrc,widsrc,colsrc
         CALL PSIASF (PEDFG, FLGSRC)
         CALL PSIASF (PEDT,  TYPSRC)
         CALL PSIASF (PEWSC, WIDSRC)
         CALL PSIASF (PEDCI, COLSRC)

         IF (IX .EQ. NGPRIM) THEN
C  set ASF flag NOT in accordance with sources
            CALL PSIASF (PEDFG, IBSW-FLGSRC)
            CALL PSIASF (PEDT,  IBSW-TYPSRC)
            CALL PSIASF (PEWSC, IBSW-WIDSRC)
            CALL PSIASF (PEDCI, IBSW-COLSRC)
         ENDIF

         YA(1) = YLOC + 0.3*YINCR
         YA(2) = YLOC - 0.3*YINCR
         YA(3) = YLOC - 0.3*YINCR

         IF (IX .LE. NUMLIN/2) THEN
            CALL PFAS (1, NPTS, XA,YA)
         ELSE
            CALL PFAS3 (1, NPTS, XA,YA,ZA)
         ENDIF
         YLOC = YLOC-YINCR
C  next ix
500   CONTINUE

      IF (DCHFLV ('ASF CONTROL OF EDGE FLAG: Which edge is different?',
     1            NUMLIN, NGPRIM)) THEN
         CALL INMSG ('Failure occurred for edge flag.')
         GOTO 590
      ENDIF
      CALL PEMST (102)

C  *** *** *** ***   edge type,width,color   *** *** *** ***

C  any other distinguishing aspects?

      IF (NEDTYP.EQ.1 .AND. NEDWID.EQ.1 .AND. NDISCT.EQ.1) THEN
C  only one edge type,width,color available
         CALL PASS
         GOTO 590
      ENDIF

C  aspects to be displayed:
C  edge flag = ON, edgetype = ed2, edgewidth = 0.02 in WC, edgecolor = 2
      VEDFG(DISPLY) = PON
      VEDT (DISPLY) = ED2
      VEWSC(DISPLY) = 0.02 / (NOMSIZ * WCPDC)
      VEDCI(DISPLY) = 2
C  aspects to be suppressed:
C  edge flag = ON, edgetype = ed1, edgewidth = 0.001 in WC, edgecolor = 1
      VEDFG(SUPPRS) = PON
      VEDT (SUPPRS) = ED1
      VEWSC(SUPPRS) = 0.001 / (NOMSIZ * WCPDC)
      VEDCI(SUPPRS) = 1

C  set interior style = EMPTY
      CALL PSIASF (PIS, PINDIV)
      CALL PSIS   (PISEMP)

C  number of lines to be displayed
      NUMLIN = 6
C  primitive to be drawn incorrectly
      NGPRIM = RNDINT (1,NUMLIN)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR
      YLOC = YTOP
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      XA(1) = 0.2
      XA(2) = 0.2
      XA(3) = 0.8
      ZA(1) = 0.5
      ZA(2) = 0.5
      ZA(3) = 0.5
      NPTS(1) = 3
C  ensure both individual and bundle are picked for each aspect
      CALL RNPERM (NUMLIN, P1)
      CALL RNPERM (NUMLIN, P2)
      CALL RNPERM (NUMLIN, P3)
      CALL RNPERM (NUMLIN, P4)

      DO 600 IX = 1,NUMLIN

C  randomly pick source for aspects:
C  assume here that bundle/individ represented by 0/1
         FLGSRC = MOD (P1(IX), 2)
         TYPSRC = MOD (P2(IX), 2)
         WIDSRC = MOD (P3(IX), 2)
         COLSRC = MOD (P4(IX), 2)

C     set bundle #ix to displayed aspects, for BUNDLED source
C                  and suppressed aspects, for INDIVIDUAL source
         CALL PSEDR (WKID, IX, VEDFG(FLGSRC), VEDT(TYPSRC),
     1                         VEWSC(WIDSRC), VEDCI(COLSRC))
         CALL PSEDI (IX)
C     set individual attributes
C                    to displayed aspects, for INDIVIDUAL source
C                  and suppressed aspects, for BUNDLED source
         CALL PSEDFG (VEDFG(IBSW-FLGSRC))
         CALL PSEDT  (VEDT (IBSW-TYPSRC))
         CALL PSEWSC (VEWSC(IBSW-WIDSRC))
         CALL PSEDCI (VEDCI(IBSW-COLSRC))

C     set ASF flags in accordance with: flgsrc,typsrc,widsrc,colsrc
         CALL PSIASF (PEDFG, FLGSRC)
         CALL PSIASF (PEDT,  TYPSRC)
         CALL PSIASF (PEWSC, WIDSRC)
         CALL PSIASF (PEDCI, COLSRC)

         IF (IX .EQ. NGPRIM) THEN
C  set ASF flag NOT in accordance with sources
            CALL PSIASF (PEDFG, IBSW-FLGSRC)
            CALL PSIASF (PEDT,  IBSW-TYPSRC)
            CALL PSIASF (PEWSC, IBSW-WIDSRC)
            CALL PSIASF (PEDCI, IBSW-COLSRC)
         ENDIF

         YA(1) = YLOC + 0.3*YINCR
         YA(2) = YLOC - 0.3*YINCR
         YA(3) = YLOC - 0.3*YINCR

         IF (IX .LE. NUMLIN/2) THEN
            CALL PFAS (1, NPTS, XA,YA)
         ELSE
            CALL PFAS3 (1, NPTS, XA,YA,ZA)
         ENDIF
         YLOC = YLOC-YINCR

C  next ix
600   CONTINUE

      IF (DCHFLV ('ASF CONTROL OF EDGE ASPECTS: Which edge is ' //
     1            'different?', NUMLIN, NGPRIM))    THEN
         CALL INMSG ('Failure occurred for edge aspects.')
      ELSE
         CALL PASS
      ENDIF

C  end_edge:
590   CONTINUE
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
