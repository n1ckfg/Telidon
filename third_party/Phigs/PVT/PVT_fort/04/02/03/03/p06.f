C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.03/06                        *
C  *    TEST TITLE : Appearance of text extent rectangle   *
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

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    PICSTR, TXCI, IX, FONT, TXP, TXALH,TXALV
      INTEGER    TXPLEN, NUMREC, RNDINT, NGREC, DTXALH,DTXALV
      INTEGER    LNALGN(PACAP:PABASE), SLEN,SHALF

      REAL       RNDRL, CHHT,CHXP,CHSP, TX(2),TY(2), CCPX,CCPY, XF(3,3)
      REAL       XL,XH,XC, YL,YH,YC, VALOC(PACAP:PABASE), XA(5),YA(5)
      REAL       NPCX,NPCY,NPCPWC, Z,U, XYINCR, YTOP, XLEFT, DSTORT
      PARAMETER (Z = 0.0, U = 1.0, DSTORT = 0.15)
      REAL       RDUM1,RDUM2, HDST,VDST

      CHARACTER  TESTR*14, TESTV*10, TESTC*12
      CHARACTER  NAMTXP*5, LBL*2

      LOGICAL    HORIZ

C  linetypes for various vertical alignments
      DATA       LNALGN / PLDOT, PLDASD, PLDASH /

      CALL INITGL ('04.02.03.03/06')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
C  Establish specwt = specific primary workstation type
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  Message to operator
      CALL OPMSGW ('The tests in this program require careful '    //
     1             'visual inspection.  If you are not familiar '  //
     1             'with the requirements for text extent and '    //
     1             'alignment, please see the OPERATOR SCRIPT in ' //
     1             'the documentation for this program.')

      TESTR = 'Phigs...rules!'
      TESTV = 'UPPER CASE'
      TESTC = 'HXHXHXHXHXHX'

C  global attributes
C  font (ASCII, possibly non-monospaced)
      FONT = 2
      CALL PSTXFN (FONT)
      CALL PSTXPR (PSTRKP)
C  default alignment
      DTXALH = PACENT
      DTXALV = PATOP
      CALL PSTXAL (DTXALH,DTXALV)
      CALL PSPLCI (2)
      CALL PSTXCI (1)
      CALL PSLWSC (0.0)
      CALL PSATAL (PACENT,PAHALF)
      CALL PSATCH (0.035 * NPCPWC)
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (102)

C  numrec = number of text extent rectangles per screen
      NUMREC = 6
      XYINCR = 1.0 / (NUMREC+1)
      YTOP  = 1 - XYINCR
      XLEFT = XYINCR

C  for all text paths, txp = RIGHT,LEFT,UP,DOWN
      DO 100 TXP = PRIGHT,PDOWN
         IF (TXP.EQ.PRIGHT) THEN
            HORIZ  = .TRUE.
            NAMTXP = 'RIGHT'
            TXPLEN = 5
         ELSEIF (TXP.EQ.PLEFT) THEN
            HORIZ  = .TRUE.
            NAMTXP = 'LEFT'
            TXPLEN = 4
         ELSEIF (TXP.EQ.PUP) THEN
            HORIZ  = .FALSE.
            NAMTXP = 'UP'
            TXPLEN = 2
         ELSE
            HORIZ  = .FALSE.
            NAMTXP = 'DOWN'
            TXPLEN = 4
         ENDIF

         XL = 0.2
         XH = 0.9
         YL = 0.1
         YH = 0.8
         XC = 0.1
         YC = 0.9

C  *** *** *** *** ***   text extent rectangle   *** *** *** *** ***

C  incorrect entry
         NGREC = RNDINT(1,NUMREC)
C  set text path
         CALL PSTXP (TXP)

         IF (HORIZ) THEN
            SLEN = 14
         ELSE
            SLEN = 5
         ENDIF

C  draw and label text extent rectangles, with text
         DO 200 IX = 1,NUMREC

C  chht,chxp,chsp = some random values for character height,
C    expansion factor, and spacing
            CHHT = 10.0 ** RNDRL(-2.0, 2.0)
            CHXP = 10.0 ** RNDRL(-1.0, 1.0)

            IF (IX .LE. 2) THEN
               CHSP = RNDRL(-3.0, -2.0)
            ELSE
               CHSP = RNDRL(-0.2, 3.0)
            ENDIF

            IF (HORIZ) THEN
               YC = YTOP - (IX-1)*XYINCR
               YL = YC - 0.25*XYINCR
               YH = YC + 0.25*XYINCR
               CHSP = CHSP*CHXP
            ELSE
               XC = XLEFT + (IX-1)*XYINCR
               XL = XC - 0.25*XYINCR
               XH = XC + 0.25*XYINCR
            ENDIF
            CALL DRWREC (XL,XH, YL,YH)
            WRITE (LBL, '(I1,A)') IX, ':'
            CALL PSCHXP (0.8)
            CALL PSCHSP (0.0)
            CALL PATR (XC,YC, Z,Z, LBL)

            CALL PSCHH  (CHHT)
            CALL PSCHXP (CHXP)
            CALL PSCHSP (CHSP)

C  determine actual rectangle:
            CALL PQTXX (SPECWT,FONT, CHXP,CHSP,CHHT, TXP, DTXALH,DTXALV,
     1                  TESTR(:SLEN), ERRIND, TX,TY, CCPX,CCPY)
            CALL CHKINQ ('pqtxx',ERRIND)

C  apply scale and shift transformation to put testr in next
C     text extent rectangle
            CALL PBLTM (TX(1),TY(1), XL-TX(1),YL-TY(1), Z,
     1                  (XH-XL)/(TX(2)-TX(1)), (YH-YL)/(TY(2)-TY(1)),
     2                  ERRIND, XF)
            CALL CHKINQ ('pbltm', ERRIND)
            CALL PSLMT (XF, PCREPL)

            IF (IX .EQ. NGREC) THEN
C  apply additional distorting transformation
               CALL PTR (DSTORT*XYINCR, -DSTORT*XYINCR, ERRIND, XF)
               CALL CHKINQ ('ptr', ERRIND)
               CALL PSLMT (XF, PCPOST)
            ENDIF
            CALL PTX (Z,Z, TESTR(:SLEN))

C  restore identity local transformation
            CALL IDMAT (3, XF)
            CALL PSLMT (XF, PCREPL)

200      CONTINUE

         CALL SETMSG ('2 6 7 8 10 15 16', '<Inquire text extent> '    //
     1                'should accurately report the size and '        //
     2                'position of text primitives when text path = ' //
     3                NAMTXP(:TXPLEN) // '.')
         CALL DCHPFV ('ACCURACY OF TEXT EXTENT: Which rectangle ' //
     1                'does NOT properly enclose a text primitive?',
     2                NUMREC, NGREC)
         CALL PEMST (102)

C  *** *** *** *** ***   vertical alignment   *** *** *** *** ***

C  incorrect entry
         NGREC = RNDINT(1,NUMREC)
C  set text path
         CALL PSTXP (TXP)

         IF (HORIZ) THEN
            SLEN = 10
         ELSE
            SLEN = 5
         ENDIF

C  draw and label vertical alignments with text
         DO 300 IX = 1,NUMREC

C  chht,chxp,chsp = some random values for character height,
C    expansion factor, and spacing
            CHHT = 10.0 ** RNDRL(-2.0, 2.0)
            CHXP = 10.0 ** RNDRL(-1.0, 1.0)
            CHSP = RNDRL(-0.2, 2.0)

            IF (HORIZ) THEN
               YC = YTOP - (IX-1)*XYINCR
               YL = YC - 0.35*XYINCR
               YH = YC + 0.35*XYINCR
               CHSP = CHSP*CHXP
            ELSE
               XC = XLEFT + (IX-1)*XYINCR
               XL = XC - 0.25*XYINCR
               XH = XC + 0.25*XYINCR
            ENDIF
            WRITE (LBL, '(I1,A)') IX, ':'
            CALL PSCHXP (0.8)
            CALL PSCHSP (0.0)
            CALL PATR (XC,YC, Z,Z, LBL)

            CALL PSCHH  (CHHT)
            CALL PSCHXP (CHXP)
            CALL PSCHSP (CHSP)

C  for txalv = TOP,CAP,HALF,BASE
            DO 350 TXALV = PATOP,PABASE
               CALL PQTXX (SPECWT,FONT, CHXP,CHSP,CHHT, TXP,
     1                     DTXALH,TXALV, TESTV(:SLEN),
     2                     ERRIND, TX,TY,CCPX,CCPY)
               CALL CHKINQ ('pqtxx',ERRIND)
               IF (TXALV .EQ. PATOP) THEN
C  apply scale and shift transformation to put testv in next
C     text extent rectangle
                  CALL PBLTM (TX(1),TY(1), XL-TX(1),YL-TY(1), Z,
     1                  (XH-XL)/(TX(2)-TX(1)), (YH-YL)/(TY(2)-TY(1)),
     2                  ERRIND, XF)
                  CALL CHKINQ ('pbltm', ERRIND)
                  CALL PSLMT (XF, PCREPL)
                  XA(1) = TX(1)
                  XA(2) = TX(2)
               ELSE
C  determine location of capline,halfline,baseline
                  VALOC(TXALV) = TY(2)
               ENDIF
C  next txalv
350         CONTINUE

C  draw expected capline,halfline,baseline
            DO 380 TXALV = PACAP,PABASE
               YA(1) = -VALOC(TXALV)
               YA(2) = YA(1)
               CALL PSLN (LNALGN(TXALV))
               CALL PPL (2, XA,YA)
380         CONTINUE

            IF (IX .EQ. NGREC) THEN
C  apply additional distorting transformation

               CALL PTR (Z, (RNDINT(0,1)*2-1) * DSTORT*XYINCR,
     1                   ERRIND, XF)
               CALL CHKINQ ('ptr', ERRIND)
               CALL PSLMT (XF, PCPOST)
            ENDIF

            CALL PTX (Z,Z, TESTV(:SLEN))

C  restore identity local transformation
            CALL IDMAT (3, XF)
            CALL PSLMT (XF, PCREPL)

300      CONTINUE

         CALL SETMSG ('2 6 7 8 10 11', '<Inquire text extent> '    //
     1                'should accurately report the vertical '     //
     2                'alignment values for text primitives when ' //
     3                'text path = ' // NAMTXP(:TXPLEN) // '.')
         CALL DCHPFV ('ACCURACY OF VERTICAL ALIGNMENTS: Which '  //
     1                'text primitive does NOT have a properly ' //
     1                'aligned capline (dotted), halfline '      //
     1                '(dashed-dotted), or baseline (dashed)?',
     1                NUMREC, NGREC)

         CALL PEMST (102)

C  *** *** *** *** ***   concatenation point   *** *** *** *** ***

C  incorrect entry
         NGREC = RNDINT(1,NUMREC)
C  set text path
         CALL PSTXP (TXP)

         TXALH = PAHNOR
         TXALV = PAVNOR
         HDST = Z
         VDST = Z
         IF (HORIZ) THEN
            SLEN = 12
            TXALV = PAHALF
            HDST = (RNDINT(0,1) - 0.5) * 3
         ELSE
            SLEN = 6
            TXALH = PARITE
            VDST = (RNDINT(0,1) - 0.5) * 4
         ENDIF
         CALL PSTXAL (TXALH,TXALV)

C  draw and label concatenated text
         DO 400 IX = 1,NUMREC

C  chht,chxp,chsp = some random values for character height,
C    expansion factor, and spacing
            CHHT = 10.0 ** RNDRL(-2.0, 2.0)
            CHXP = 10.0 ** RNDRL(-1.0, 1.0)
            CHSP = RNDRL(0.8, 1.5)

            IF (HORIZ) THEN
               YC = YTOP - (IX-1)*XYINCR
               YL = YC - 0.35*XYINCR
               YH = YC + 0.35*XYINCR
               SHALF = RNDINT(3,9)
               IF (IX.GT.3) CHSP = RNDRL(-0.3, -0.1)
               CHSP = CHSP*CHXP
            ELSE
               XC = XLEFT + (IX-1)*XYINCR
               XL = XC - 0.25*XYINCR
               XH = XC + 0.25*XYINCR
               SHALF = RNDINT(2,4)
               IF (IX.GT.3) CHSP = RNDRL(-0.8, -0.3)
            ENDIF
            WRITE (LBL, '(I1,A)') IX, ':'
            CALL PSCHXP (0.8)
            CALL PSCHSP (0.0)
            CALL PATR (XC,YC, Z,Z, LBL)

            CALL PSCHH  (CHHT)
            CALL PSCHXP (CHXP)
            CALL PSCHSP (CHSP)

C  determine text extent rectangle
            CALL PQTXX (SPECWT,FONT, CHXP,CHSP,CHHT, TXP, TXALH,TXALV,
     1                  TESTC(:SLEN), ERRIND, TX,TY, RDUM1,RDUM2)
            CALL CHKINQ ('pqtxx',ERRIND)

C  apply scale and shift transformation to put testr1 in next
C    labelled location
            CALL PBLTM (TX(1),TY(1), XL-TX(1),YL-TY(1), Z,
     1                  (XH-XL)/(TX(2)-TX(1)), (YH-YL)/(TY(2)-TY(1)),
     2                  ERRIND, XF)
            CALL CHKINQ ('pbltm', ERRIND)
            CALL PSLMT (XF, PCREPL)

            CALL PTX (Z,Z, TESTC(:SHALF))

            IF (IX .EQ. NGREC) THEN
C  apply additional distorting transformation
               CALL PTR (HDST*DSTORT*XYINCR, VDST*DSTORT*XYINCR,
     1                   ERRIND, XF)
               CALL CHKINQ ('ptr', ERRIND)
               CALL PSLMT (XF, PCPOST)
            ENDIF

C  determine concatenation point = ccpx,ccpy
            CALL PQTXX (SPECWT,FONT, CHXP,CHSP,CHHT, TXP, TXALH,TXALV,
     1                  TESTC(:SHALF), ERRIND, TX,TY,CCPX,CCPY)
            CALL CHKINQ ('pqtxx',ERRIND)

C  display text primitive = testr2 at ccpx,ccpy
            CALL PTX (CCPX,CCPY, TESTC(SHALF+1:SLEN))

C  restore identity local transformation
            CALL IDMAT (3, XF)
            CALL PSLMT (XF, PCREPL)
400      CONTINUE

         CALL SETMSG ('2 6 7 8 10 11 12 17 18', '<Inquire text ' //
     1                'extent> should accurately report the '    //
     2                'concatenation point when text path = '    //
     3                NAMTXP(:TXPLEN) //'.')
         CALL DCHPFV ('ACCURACY OF CONCATENATION POINT: In which ' //
     1                'text primitive are the characters NOT '     //
     1                'aligned and evenly separated?', NUMREC, NGREC)

         CALL PEMST (102)

C  next text path
100   CONTINUE

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
