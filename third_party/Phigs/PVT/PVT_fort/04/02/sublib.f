C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/altsiz                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ALTSIZ (EXPDC, MINSIZ,MAXSIZ, MAXALT, NUMALT,ALT)

C  ALTSIZ finds nearby alternate sizes, to the expected size, and
C  returns them to the caller.  The alternates fulfill all these
C  conditions: 1) each differs from all the others by at least 25%
C  (relative) and by MINSIZ (absolute), and 2) each is no less than
C  MINSIZ, and no greater than MAXSIZ.

C  Input parameters:
C    EXPDC  : Expected size; always the first entry in ALT
C    MINSIZ : Minimum size for an entry and for difference between entries
C    MAXSIZ : Maximum size for an entry
C    MAXALT : Maximum number of alternatives to be returned (including EXPDC)
C  Output parameters:
C    NUMALT : Actual number of alternatives returned
C    ALT    : List of alternative sizes

      INTEGER   MAXALT, NUMALT, IX

      REAL      NXL1,NXL2,NXS1,NXS2
      REAL      EXPDC, MINSIZ,MAXSIZ, ALT(MAXALT)

      NUMALT = 1
      ALT(NUMALT) = EXPDC
      NXL1 = EXPDC
      NXS1 = EXPDC

C  generate alternative sizes - must differ by at least 25% *and* MINSIZ
      DO 100 IX = 1,MAXALT
C  generate larger choices
         NXL2 = 1.25 * NXL1
         IF (NXL2-NXL1 .LT. MINSIZ) THEN
            NXL2 = NXL1 + MINSIZ
         ENDIF
         IF (NXL2 .LE. MAXSIZ) THEN
            NUMALT = NUMALT+1
            ALT(NUMALT) = NXL2
            IF (NUMALT .GE. MAXALT) RETURN
            NXL1 = NXL2
         ENDIF
C  generate smaller choices
         NXS2 = NXS1/1.25
         IF (NXS1-NXS2 .LT. MINSIZ) THEN
            NXS2 = NXS1 - MINSIZ
         ENDIF
         IF (NXS2 .GE. MINSIZ) THEN
            NUMALT = NUMALT+1
            ALT(NUMALT) = NXS2
            IF (NUMALT .GE. MAXALT) RETURN
            NXS1 = NXS2
         ENDIF
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/hlfbox                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE HLFBOX (X1ST,Y1ST, XINC,YINC, XY)

C  HLFBOX draws a half-box.

C  Input parameters:
C    X1ST,Y1ST : starting point
C    XINC,YINC : x,y increments
C    XY        : switch to determine which increment is to be applied
C                first.  X creates a box open at the side, Y creates
C                a box open at the top or bottom.

      INTEGER    IXY
      REAL       X1ST,Y1ST, XINC,YINC, XA(5),YA(5)

      CHARACTER  XY*1

      IF (XY .EQ. 'X') THEN
         IXY = 2
      ELSEIF (XY .EQ. 'Y') THEN
         IXY = 4
      ELSE
         CALL UNMSG ('HLFBOX called with invalid XY: ' // XY // '.') 
      ENDIF

      XA(1) = X1ST
      YA(1) = Y1ST
      XA(3) = X1ST + XINC
      YA(3) = Y1ST + YINC
      XA(IXY) = XA(3)
      YA(IXY) = YA(1)
      XA(6 - IXY) = XA(1)
      YA(6 - IXY) = YA(3)

      CALL PPL (4,XA,YA)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/simark                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SIMARK (MKST, COLI, MKRAD, CX,CY)

C  SIMARK uses polyline to simulate markers of various styles.
C
C  Input parameters:
C    MKST   : Marker style (either plus, asterick, or circle)
C    COLI   : Color to be used in simulation = index #1
C    MKRAD  : Marker radius in WC
C    CX,CY  : Marker center in WC

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

      INTEGER    MKST, NOSEG, SIZ, COLI
      REAL       MKRAD, CX,CY, XA(60),YA(60), PI, ANG,ANG2
      PARAMETER (PI = 3.14159265)
      CHARACTER  MSG*100

C  use ASFs individual 
      CALL SETASF (PINDIV) 
C  use polyline to simulate polymarker 
      CALL PSLN   (PLSOLI)
      CALL PSPLCI (COLI)
      CALL PSLWSC (0.0)

      IF (MKST .EQ. PPLUS) THEN
C  simulate plus
         XA(1) = CX - MKRAD
         XA(2) = CX + MKRAD
         YA(1) = CY
         YA(2) = CY
         CALL PPL (2, XA,YA)
         XA(1) = CX
         XA(2) = CX
         YA(1) = CY + MKRAD
         YA(2) = CY - MKRAD
         CALL PPL (2, XA,YA)
      ELSEIF (MKST .EQ. PAST) THEN
C simulate asterisk
         DO 100 SIZ = 0,2
            ANG   = SIZ * PI / 3
            XA(1) = CX + MKRAD * COS(ANG)
            YA(1) = CY + MKRAD * SIN(ANG)
            ANG2  = ANG + PI
            XA(2) = CX + MKRAD * COS(ANG2)
            YA(2) = CY + MKRAD * SIN(ANG2)
            CALL PPL (2,XA,YA)
100      CONTINUE
      ELSEIF (MKST .EQ. POMARK) THEN
C mkst = 4, simulate circle
         NOSEG = 40
         DO 200 SIZ = 1, NOSEG+1
            ANG = SIZ * 2 * PI / NOSEG
            XA(SIZ) = CX + MKRAD * COS(ANG)
            YA(SIZ) = CY + MKRAD * SIN(ANG)
200      CONTINUE
         CALL PPL (NOSEG+1, XA, YA)
      ELSE
C  invalid marker type
         WRITE (MSG, '(A,I5,A)') 'Invalid marker style passed ' //
     1         'to SIMARK: ', MKST, '.'
         CALL UNMSG (MSG)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION 04.02/basbot                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION BASBOT (WKTYPE, FONT)

C  BASBOT returns the nominal distance (i.e. for character height =
C  1.0) between the baseline and bottom of characters for a given
C  workstation type and font.

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

      INTEGER    WKTYPE,FONT, ERRIND

      REAL       XB(2),YB(2),CCX,CCY

      CHARACTER  STR*7
      DATA       STR / 'ISO Wg2' /

      CALL PQTXX (WKTYPE, FONT, 1.0,0.0,1.0,PRIGHT,PALEFT,PABASE,
     1            STR, ERRIND, XB,YB,CCX,CCY)
      CALL CHKINQ ('pqtxx', ERRIND)

      BASBOT = -YB(1)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/tstasc                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTASC (PROMPT, TSTCHS, PRIM)

C  TSTASC accepts a prompt and a test string whose leading character
C  is NOT a member of the set being tested.  The rest of the string
C  has characters in the expected set.  The characters are displayed
C  in random order and the operator must identify the one which
C  doesn't belong to the set.  PRIM indicates whether text or
C  annotation text is to be tested, and whether individually or bundled.

C  Input parameters:
C    PROMPT : String with which to prompt the operator
C    TSTCHS : String containing a set of similar characters, except the first
C    PRIM   : Indicates which primitive and mode of test
C             T - text/individual
C             U - text/bundled
C             A - annotation text/individual
C             B - annotation text/bundled

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

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

      INTEGER    FONT, PREC, PERM(100), CHLEN, MAXCH, LASTCH, ICX
      PARAMETER (MAXCH = 8)

      REAL       YINCR, YPOS, NPCX,NPCY, NPCPWC

      CHARACTER  PROMPT*(*), TSTCHS*(*), NLABEL*6, RANCHS*100, PRIM*1

      LOGICAL    FPAVL, CHARNG, DCHFL

      CHLEN = LEN(TSTCHS)
      YINCR = .1
      IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
         CALL PSCHH  (YINCR/2)
         CALL PSTXAL (PALEFT, PAHALF)
      ELSEIF (PRIM.EQ.'A' .OR. PRIM.EQ.'B') THEN
C  in Y-direction, NPC/WC ratio
         CALL WCNPC (0.0,0.0, NPCX,NPCY, NPCPWC)
         CALL PSATCH (NPCPWC * YINCR/2)
         CALL PSATAL (PALEFT, PAHALF)
      ELSE
         CALL UNMSG ('TSTASC called with invalid PRIM: ' // PRIM)
      ENDIF

C  mark off start, end of structure to be changed
      CALL PLB (11)
      CALL PLB (12)
      CALL POSEP (-1)

C  loop thru fonts and precisions
      DO 200 FONT = 1, 2
      DO 210 PREC = PSTRP, PSTRKP
C        skip unavailable font-precision pairs
         IF (.NOT. FPAVL (WKID, 5, FONT, PREC)) GOTO 190
         IF (PRIM.EQ.'T' .OR. PRIM.EQ.'A') THEN
            CALL PSTXFN (FONT)
            CALL PSTXPR (PREC)
         ELSE
            CALL PSTXR (WKID, 2, FONT,PREC, 1.0,0.2,1)
            CALL PSTXI (2)
         ENDIF

C  scramble TSTCHS into RANCHS:
         CALL RNPERM (CHLEN, PERM)
         DO 110 ICX = 1,CHLEN
            RANCHS(ICX:ICX) = TSTCHS(PERM(ICX):PERM(ICX))
110      CONTINUE

C  display all characters in TSTCHS in random order, MAXCH at a time
         YPOS  = 1-YINCR
         DO 220 ICX = 1,CHLEN,MAXCH
            LASTCH = MIN (ICX + MAXCH - 1, CHLEN)
            WRITE (NLABEL, '(I2,A,I2,A)') ICX, '-', LASTCH, ':'
            CALL VISLAB (NLABEL, 'R',
     1                   .05,.35, YPOS-0.3*YINCR, YPOS+0.3*YINCR)
            IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
               CALL PTX (.4, YPOS, RANCHS(ICX:LASTCH))
            ELSE
               CALL PATR (.4, YPOS, 0.0,0.0, RANCHS(ICX:LASTCH))
            ENDIF
            YPOS = YPOS-YINCR
220      CONTINUE
         CHARNG = DCHFL (PROMPT, CHLEN, 1, PERM)
C  clear display
         CALL PSEP (1)
         CALL PDELLB (11,12)
         IF (CHARNG) GOTO 290

190      CONTINUE
210   CONTINUE
200   CONTINUE
      CALL PASS

290   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.02/fpavl                       *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION FPAVL (WKID, TXI, FONT, PREC)

C  Tests whether a given font and precision will be realized exactly
C  as such on the workstation type.  If a requested font is realized
C  in a higher precision, it is not considered to be directly
C  available.

C  Input parameters:
C    WKID : Workstation identifier
C    TXI  : Identifier for a text bundle which may be altered
C    FONT : font whose availability is at issue
C    PREC : precision whose availability is at issue

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER  WKID, TXI, NFPP, FONT, PREC, QFONT, QPREC, ERRIND
      INTEGER  IX, CONID, WTYPE, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL     RDUM1,RDUM2,RDUM3,RDUM4

      CALL PQWKC (WKID, ERRIND, CONID, WTYPE)
      CALL CHKINQ ('pqwkc', ERRIND)
C  check if font,prec claimed in available list
      CALL PQTXF (WTYPE, 0, ERRIND, NFPP, IDUM1,IDUM2,
     1            IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
      DO 100 IX = 1,NFPP
         CALL PQTXF (WTYPE, IX, ERRIND, IDUM1, QFONT,QPREC,
     1               IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf', ERRIND)
         IF (QFONT.EQ.FONT .AND. QPREC.GE.PREC) THEN
            GOTO 110
         ENDIF
100   CONTINUE
C  font not claimed in list - give up
      FPAVL = .FALSE.
      RETURN

C  check if realized exactly as requested
110   CONTINUE
      CALL PSTXR (WKID, TXI, FONT,PREC, 1.0,0.0,1)
      CALL PQTXR (WKID, TXI, PREALI,
     1            ERRIND, QFONT,QPREC, RDUM1,RDUM2,IDUM1)
      CALL CHKINQ ('pqtxr', ERRIND)
      FPAVL = QFONT.EQ.FONT .AND. QPREC.EQ.PREC

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/prpfnt                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PRPFNT (SPECWT, BESTFN)

C  PRPFNT looks for a stroke text font other than 1, preferably not
C  #2 and not monospaced.

C  Input parameters:
C    SPECWT : workstation type
C  Output parameters:
C    BESTFN : selected font

      INTEGER   SPECWT, BESTFN
      REAL      RDUM1,RDUM2,RDUM3,RDUM4

      CALL SUBFNT (SPECWT, BESTFN, RDUM1,RDUM2,RDUM3,RDUM4)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/varfnt                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE VARFNT (BESTFN, NCBHTW, NCBWDW, NCBHTI, NCBWDI)

C  VARFNT looks for a stroke text font other than 1, preferably not
C  #2 and not monospaced, and returns nominal size for "W" and "i".

C  Output parameters:
C    BESTFN        : selected font
C    NCBHTW,NCBWDW : nominal height, width of "W" in selected font
C    NCBHTI,NCBWDI : nominal height, width of "i" in selected font

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER    BESTFN
      REAL       NCBHTW, NCBWDW, NCBHTI, NCBWDI

      CALL SUBFNT (SPECWT, BESTFN, NCBHTW, NCBWDW, NCBHTI, NCBWDI)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/subfnt                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SUBFNT (SPECWT, BESTFN, NCBHTW,NCBWDW,NCBHTI,NCBWDI)

C  SUBFNT looks for a stroke text font other than 1, preferably not
C  #2 and not monospaced, and returns nominal size for "W" and "i".

C  Input parameters:
C    SPECWT : workstation type
C  Output parameters:
C    BESTFN        : selected font
C    NCBHTW,NCBWDW : nominal height, width of "W" in selected font
C    NCBHTI,NCBWDI : nominal height, width of "i" in selected font

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

      INTEGER    NFPP, IX, THISFN,THISPR, BESTFN, BESTSC, FNSCOR
      INTEGER    ERRIND, PERM(400), SPECWT
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL       TCBHTI,TCBWDI, TCBHTW,TCBWDW 
      REAL       NCBHTI,NCBWDI, NCBHTW,NCBWDW 
      REAL       TXRX(2),TXRY(2)
      REAL       RDUM1,RDUM2,RDUM3,RDUM4

      LOGICAL    APPEQ

      CALL PQTXF (SPECWT, 0, ERRIND, NFPP, IDUM1,IDUM2,
     1            IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
      BESTSC = -1
      BESTFN =  1
C  go thru the fonts, in random order, looking for a good one
      CALL RNPERM (NFPP, PERM)
      DO 300 IX = 1,NFPP
         CALL PQTXF (SPECWT, PERM(IX), ERRIND, IDUM1, THISFN,THISPR,
     1               IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf', ERRIND)
C  must be non-1 stroke font
         IF (THISFN.EQ.1 .OR. THISPR.NE.PSTRKP) GOTO 300

C  determine
C    tcbhtw = nominal character body height for W
C    tcbwdw = nominal character body width for W
         CALL PQTXX  (SPECWT, THISFN, 1.,0.,1., PRIGHT, PALEFT,PABOTT,
     1                'WWW', ERRIND, TXRX,TXRY, RDUM1,RDUM2)
         CALL CHKINQ ('pqtxx', ERRIND)
         TCBHTW = ABS(TXRY(2) - TXRY(1))
         TCBWDW = ABS(TXRX(2) - TXRX(1)) / 3
C  determine
C    tcbhti = nominal character body height for i
C    tcbwdi = nominal character body width for i
         CALL PQTXX  (SPECWT, THISFN, 1.,0.,1., PRIGHT, PALEFT,PABOTT,
     1                'iii', ERRIND, TXRX,TXRY, RDUM1,RDUM2)
         CALL CHKINQ ('pqtxx', ERRIND)
         TCBHTI = ABS(TXRY(2) - TXRY(1))
         TCBWDI = ABS(TXRX(2) - TXRX(1)) / 3

C  "goodness" score for this font
         IF (THISFN .EQ. 2) THEN
            FNSCOR = 0
         ELSE
            FNSCOR = 1
         ENDIF
C  add 2 to score if not monospaced
         IF (.NOT. APPEQ(TCBWDW, TCBWDI, 0.0, 0.02)) FNSCOR = FNSCOR+2

         IF (FNSCOR .GT. BESTSC) THEN
C  best font so far
            BESTSC = FNSCOR
            BESTFN = THISFN
            NCBHTW = TCBHTW
            NCBWDW = TCBWDW
            NCBHTI = TCBHTI
            NCBWDI = TCBWDI
C  got a non-2, non-monospaced font
            IF (FNSCOR .GE. 3) GOTO 310
         ENDIF
300   CONTINUE

C  got_font:
310   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/chkfnt                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CHKFNT (LX,LFN,LPR, MAXENT, CHSTR, SUBPRE, PRIM)

C  CHKFNT accepts a list of fonts and precisions, and randomly picks
C  some of them to be illustrated using the specified character
C  string.
C
C  Input parameters:
C    LX     : size of font and precision lists
C    LFN    : list of text fonts to be shown
C    LPR    : list of precisions to be used with corresponding font
C    MAXENT : maximum number of entries to be illustrated
C    CHSTR  : character string to be used when displaying fonts
C    SUBPRE : logical switch to control whether sub-available
C             precisions are requested.
C    PRIM   : indicates primitive and mode to be tested:
C             T - text/individual
C             A - annotation text/individual
C             U - text/bundled
C             B - annotation text/bundled

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    LX,LFN(*),LPR(*), MAXENT, LCC(20), LDISP(20), LENCH
      INTEGER    IX, NUMLIN, ACTPRE, ITRIM, RNDINT

      REAL       YPOS,YINCR,YTOP, XA(5),YA(5), NPCX,NPCY, NPCPWC

      CHARACTER  CHSTR*(*), CHCODS*100, FNTLAB*5, PRIM*1

      LOGICAL    SUBPRE

      LENCH = LEN(CHSTR)
C  lcc = list of character codes = codes for chstr
      DO 110 IX = 1, LENCH
         LCC(IX) = ICHAR(CHSTR(IX:IX))
         WRITE (CHCODS(4*IX-3:4*IX), '(I3,A)') LCC(IX), ','
110   CONTINUE
      CHCODS(4*LENCH:) = ' '
C  ldisp = list of fonts to be displayed - pointers into LPOSFN
      IF (LX .GT. MAXENT) THEN
C  pick a random subset to show
         CALL RNSET (MAXENT, LX, LDISP)
         NUMLIN = MAXENT
      ELSE
C  show all of them
         CALL RNPERM (LX, LDISP)
         NUMLIN = LX
      ENDIF
      CALL SRTIAR (NUMLIN, LDISP)

C  display lcc - list of character codes
      YPOS  = .97
      YINCR = .08
      CALL VISLAB ('Text below composed from character codes:', 'L',
     1             .05,.9, YPOS-0.6*YINCR, YPOS)
      YPOS = YPOS-YINCR
      CALL VISLAB (CHCODS(:ITRIM(CHCODS)), 'L',
     1             .05,.9, YPOS-0.6*YINCR, YPOS)
      YPOS = YPOS-YINCR
      YA(1) = YPOS
      YA(2) = YPOS
      XA(1) = .05
      XA(2) = .95
      CALL PPL (2, XA,YA)

C  display and label chstr for each font in ldisp, using that
C  font's associated precision - labels first
      YTOP = YPOS-YINCR
      YPOS = YTOP
      YINCR = MIN (YPOS/7, YPOS/(MAXENT + 1))
      DO 100 IX = 1,NUMLIN
         WRITE (FNTLAB, '(I5)') LFN(LDISP(IX))
         CALL VISLAB ('Font ' // FNTLAB // ':', 'R',
     1                .05, .3, YPOS-0.6*YINCR, YPOS)
         YPOS = YPOS-YINCR
100   CONTINUE

      YPOS = YTOP
      IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
         CALL PSCHH  (0.5*YINCR)
         CALL PSTXAL (PALEFT,PATOP)
      ELSEIF (PRIM.EQ.'A' .OR. PRIM.EQ.'B') THEN
         CALL WCNPC  (0.0,0.0, NPCX,NPCY, NPCPWC)
         CALL PSATCH (0.5*YINCR * NPCPWC)
         CALL PSATAL (PALEFT,PATOP)
      ELSE
         CALL UNMSG ('CHKFNT called with PRIM = ' // PRIM)
      ENDIF

      DO 200 IX = 1,NUMLIN
         ACTPRE = LPR(LDISP(IX))
         IF (SUBPRE) THEN
            ACTPRE = ACTPRE - RNDINT(1,2)
            ACTPRE = MAX (ACTPRE, PSTRP)
         ENDIF
         IF (PRIM.EQ.'T' .OR. PRIM.EQ.'A') THEN
            CALL PSTXFN (LFN(LDISP(IX)))
            CALL PSTXPR (ACTPRE)
            CALL PSCHSP (0.2)
         ELSE
            CALL PSTXR (WKID, IX, LFN(LDISP(IX)), ACTPRE, 1.0, 0.2, 1)
            CALL PSTXI (IX)
         ENDIF

         IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
            CALL PTX  (.35, YPOS, CHSTR)
         ELSE
            CALL PATR (.35, YPOS, 0.0,0.0, CHSTR)
         ENDIF

         YPOS = YPOS-YINCR
200   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/unrep                             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE UNREP (FNTID, UNRPSZ, UNRPLS, PRIM, RESULT)

C  UNREP displays some unrepresentable character codes in the
C  requested font and then reports whether these were correctly
C  identified by the operator.

C  Input parameters:
C    FNTID  : Font identifier to be used in displayed text
C    UNRPSZ : Size of list of unrepresentable character codes
C    UNRPLS : List of unrepresentable character codes
C    PRIM   : indicates primitive and mode to be tested:
C             T - text/individual
C             A - annotation text/individual
C             U - text/bundled
C             B - annotation text/bundled
C  Output parameters:
C    RESULT : pass/fail result: P or F

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    FNTID, UNRPSZ, UNRPLS(UNRPSZ), PREC, NUNREP
      INTEGER    UPTR,RPTR, ULS(10), RLS(10), ANSSIZ, ANSLIS(20)
      INTEGER    TRUANS(10), RNDINT, PERM(20), IX

      REAL       NPCX,NPCY, NPCPWC

      CHARACTER  RESULT*1, STR*10, REPCH(10)*1, PRIM*1

      LOGICAL    IAREQL

      DATA  REPCH / '*','@','&','#','^','%','$','!','?','}' /

      IF (FNTID.LT.1 .OR. FNTID.GT.2) THEN
         CALL UNMSG ('UNREP called with illegal font identifier.')
      ENDIF
      
      CALL PSTXI (2)
      DO 100 PREC = PSTRP, PSTRKP
         IF (PRIM.EQ.'U' .OR. PRIM.EQ.'B') THEN
            CALL PSTXR (WKID, 2, FNTID, PREC, 1.0, 0.2, 1)
         ELSEIF (PRIM.EQ.'T' .OR. PRIM.EQ.'A') THEN
            CALL PSTXFN (FNTID)
            CALL PSTXPR (PREC)
            CALL PSCHSP (0.15)
         ELSE
            CALL UNMSG ('UNREP called with PRIM = ' // PRIM)
         ENDIF

         IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
            CALL PSCHH  (0.04)
         ELSE
            CALL WCNPC  (0.0,0.0, NPCX,NPCY, NPCPWC)
            CALL PSATCH (0.04 * NPCPWC)
         ENDIF

C  number unrepresented
         NUNREP = MIN(UNRPSZ, RNDINT (2,6))
C  str = random mix of ASCII and unrepresented character codes
         CALL RNSET (10-NUNREP, 10,     RLS)
         CALL RNSET (NUNREP,    UNRPSZ, ULS)
         CALL RNPERM (10, PERM)
         UPTR = 0
         RPTR = 0
         DO 110 IX = 1,10
            IF (PERM(IX) .LE. NUNREP) THEN
               UPTR = UPTR+1
               STR(IX:IX) = CHAR(UNRPLS(ULS(UPTR)))
               TRUANS(UPTR) = IX
            ELSE
               RPTR = RPTR+1
               STR(IX:IX) = REPCH(RLS(RPTR))
            ENDIF
110      CONTINUE

         IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
            CALL PTX  (.05, .5, '1-10: ' // STR)
         ELSE
            CALL PATR (.05, .5, 0.0,0.0, '1-10: ' // STR)
         ENDIF

         CALL DILIST ('APPEARANCE OF UNREPRESENTED CHARACTER '     //
     1                'CODES: The implementation should have a '   //
     2                'special symbol to indicate the presence '   //
     3                'of a non-representable character code '     //
     4                'within a character string.  List, in '      //
     5                'order, all the character positions '        //
     6                'containing this special symbol.',  
     7                ANSSIZ, ANSLIS)
         CALL PEMST (102)
         IF (IAREQL (ANSSIZ,ANSLIS, NUNREP,TRUANS)) THEN
C           OK so far
         ELSE
            IF (ANSSIZ.EQ.1 .AND. ANSLIS(1).EQ.0) CALL OPCOFL
            RESULT = 'F'
            RETURN
         ENDIF
100   CONTINUE
      RESULT = 'P'

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/ngtxat                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE NGTXAT (PRIM)

C  NGTXAT tests the effect of negative values for the character
C  height and expansion factor attributes.
   
C  Input parameters:
C    PRIM : indicates primitive and mode to be tested:
C           T - text/individual
C           A - annotation text/individual

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

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

      INTEGER    PERM(5), IX, THIS, ERRIND, STYPE,STRID

      REAL       YTOP,YLOC,YINCR, CHMAG,CXMAG, CHHT,CHXP
      REAL       YUP, XLOC, NPCX,NPCY, NPCPWC

      CHARACTER  PRIM*1, CHSTR*7

      CALL PQOPST (ERRIND, STYPE, STRID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .EQ. POPNST) THEN
C        press on
      ELSE
         CALL UNMSG ('NGTXAT aborting, called with no structure open.')
      ENDIF

      CALL WCNPC (0.0,0.0, NPCX,NPCY, NPCPWC)

C  permute 1 thru 5
      CALL RNPERM (5, PERM)
      YINCR = 0.15
      YTOP  = 1 - YINCR
C  magnitude of character height
      CHMAG = 0.45 * YINCR
C  magnitude of character expansion factor
      CXMAG = 0.8
C  some non-symmetric characters
      CHSTR = '2P4Q5R7'
C  label text lines
      CALL NUMLAB (5, 0.15, YTOP, YINCR)
      XLOC = 1.15 / 2
      YLOC = YTOP

C  default attributes
      CALL PSTXFN (2)
      CALL PSTXPR (PSTRKP)
      CALL PSTXAL (PACENT, PAHALF)
      CALL PSATAL (PACENT, PAHALF)

      DO 100 IX = 1,5
         THIS = PERM(IX)
         IF (THIS .LT. 3) THEN
            CHHT = -CHMAG
         ELSE
            CHHT = +CHMAG
         ENDIF

         IF (MOD(THIS,2) .EQ. 0) THEN
            CHXP = -CXMAG
         ELSE
            CHXP = +CXMAG
         ENDIF

         IF (THIS .EQ. 5) THEN
C  reverse up and down
            YUP = -1.0
         ELSE
            YUP =  1.0
         ENDIF

         CALL PSCHXP (CHXP)
         IF (PRIM .EQ. 'T') THEN
            CALL PSCHUP (0.0, YUP)
            CALL PSCHH  (CHHT)
            CALL PTX (XLOC,YLOC, CHSTR)
         ELSEIF (PRIM .EQ. 'A') THEN
            CALL PSATCU (0.0, YUP)
            CALL PSATCH (NPCPWC * CHHT)
            CALL PATR (XLOC,YLOC, 0.0, 0.0, CHSTR)
         ELSE
            CALL UNMSG ('NGTXAT aborting, called with PRIM = ' //
     1                  PRIM // '.')
         ENDIF

         YLOC = YLOC-YINCR
C  next ix
100   CONTINUE

      CALL DCHPF ('NEGATIVE CHARACTER HEIGHT AND EXPANSION '   //
     1            'FACTOR: Which line does NOT have normally ' //
     2            'oriented characters?', 5,5,PERM)
      CALL PEMST (STRID)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/txpcup                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TXPCUP (PRIM)

C  TXPCUP tests the interaction of various text path and character
C  up combinations for text and annotation text.  A structure must
C  be open and available for emptying.

C  Input parameters:
C    PRIM : indicates primitive and mode to be tested:
C           T - text/individual
C           A - annotation text/individual
          
C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER    STRID, ROTPER(4), TXPPER(4), CHG, CHPOS, IX, ERRIND
      INTEGER    TXP, ROT, OPANS, DIR, HDLEN, ITRIM, STYPE

      REAL       XUP,YUP, NPCX,NPCY, NPCPWC

      CHARACTER  PRIM*1, CHSTR*4, OPSTR*80, SUFFIX*19, PRMTHD*40

      CALL PQOPST (ERRIND, STYPE, STRID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .EQ. POPNST) THEN
C        press on
      ELSE
         CALL UNMSG ('TXPCUP aborting, called with no structure open.')
      ENDIF

C  mostly non-symmetrical characters 
      CHSTR = 'SPQR'
      CALL RNPERM (4,ROTPER)
      CALL RNPERM (4,TXPPER)
      CALL WCNPC (0.0,0.0, NPCX,NPCY, NPCPWC)

      DO 50 IX = 1,4
         TXP = TXPPER(IX) - 1
C  rotation amount = random 0,90,180,270 degrees
         ROT = ROTPER(IX) - 1
C  0 for horizontal, 1 for vertical
         DIR = MOD (TXP/2 + ROT, 2)

         XUP = 0.0
         YUP = 0.0
         IF (MOD(ROT,2) .EQ. 0) THEN
            YUP = 1.0 - ROT
         ELSE
            XUP = ROT - 2.0
         ENDIF

         CALL PSTXFN (2)

         IF (PRIM .EQ. 'T') THEN
            CALL PSCHH  (0.1)
            CALL PSTXP  (TXP)
            CALL PSTXAL (PACENT,PAHALF)
            CALL PSCHUP (XUP,YUP)
            CALL PTX (0.5,0.5, CHSTR)
            PRMTHD = 'TEXT PATH AND CHARACTER UP:'
         ELSEIF (PRIM .EQ. 'A') THEN
            CALL PSATCH (NPCPWC * 0.1)
            CALL PSATP  (TXP)
            CALL PSATAL (PACENT,PAHALF)
            CALL PSATCU (XUP,YUP)
            CALL PATR   (0.5,0.5, 0.0,0.0, CHSTR)
            PRMTHD = 'ANNOTATION TEXT PATH AND CHARACTER UP:'
         ELSE
            CALL UNMSG ('TXPCUP aborting, called with PRIM = ' // 
     1                  PRIM // '.')
         ENDIF
         HDLEN = ITRIM(PRMTHD) + 1

         CALL DCHOIC (PRMTHD(:HDLEN) // 'Is text string as a whole ' //
     1                'oriented horizontally (1) or vertically (2)?', 
     2                0,2, OPANS)
         IF (OPANS .EQ. 0) THEN
            CALL OPFAIL
            GOTO 60
         ELSEIF (DIR+1 .NE. OPANS) THEN
            CALL FAIL
            GOTO 60
         ENDIF

         CALL DCHOIC (PRMTHD(:HDLEN) // 'Is the character up '     //
     1                'direction to the left (1), top (2), right ' //
     2                '(3), or bottom (4)?', 0,4, OPANS)
         IF (OPANS .EQ. 0) THEN
            CALL OPFAIL
            GOTO 60
         ELSEIF (MOD((ROT+OPANS),4) .NE. 2) THEN
            CALL FAIL
            GOTO 60
         ENDIF

         IF (DIR .EQ. 0) THEN
            SUFFIX = 'left of the screen.'
         ELSE
            SUFFIX = 'top of the screen.'
         ENDIF

         CALL DLINE (PRMTHD(:HDLEN) // 'Identify the character ' //
     1               'nearest the ' // SUFFIX, OPSTR)
         IF (OPSTR .EQ. '0') THEN
            CALL OPFAIL
            GOTO 60
         ELSE

C  CHG = odd  if rotation changes "first" character of text path
C        even if rotation does not change it
            CHG = (ROT + 1 - TXP/2) / 2

C  0 for 1st character, 1 for last
            CHPOS = MOD( CHG + (TXP+1)/2, 2)
            CHPOS = CHPOS*3 + 1

            IF (OPSTR .NE. CHSTR(CHPOS:CHPOS)) THEN
               CALL FAIL
               GOTO 60
            ENDIF
         ENDIF

         CALL PEMST (STRID)
C  next txp
50    CONTINUE
      CALL PASS

C  end_text_path:
60    CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02/distxb                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DISTXB (SAMP, START, UNIV, SUBSET)

C  DISTXB selects SAMP predefined bundles at random from the
C  text bundle table which are distinct in all their attributes.
C  If there are not SAMP completely distinct bundles, DISTXB tries
C  to maximize the number of different attributes.
C
C  Input parameters:
C    SAMP        : number of predefined bundles to be picked
C    START       : starting index
C    UNIV        : last element in universe to pick from
C  Output parameters:
C    SUBSET      : array containing the selected distinct bundles

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT, ERRIND
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER    SAMP, START, UNIV, SUBSET(SAMP), I,J,JJ,K, OT
      INTEGER    ATRCNT, MAXATR,MAXLOC, JFONT, JPREC, JCOLI
      REAL       JCHXP, JCHSP, KCHXP, KCHSP
      INTEGER    KFONT, KPREC, KCOLI
      INTEGER    RNDINT, OPTATR
C  total number of attributes
      INTEGER    TOTATR
      PARAMETER (TOTATR=5)

      LOGICAL    ATRNEW(TOTATR)

      IF (UNIV+1-START .LT. SAMP) THEN
         CALL UNMSG ('Abort in DISTXB because size of universe ' //
     1               'is less than requested sample.')
      ENDIF

C  OPTATR is the best possible number of attributes that can be distinct
      OPTATR = TOTATR

C  this loop picks out samp elements
      DO 500 I = 1, SAMP
C  number of new attribute values so far
         MAXATR = -1
C  look at entire universe each time, starting at random location
         J = RNDINT(START, UNIV)
         DO 400 JJ = START, UNIV
            IF (J.GE.UNIV) THEN
C  cycle around to beginning
               J = START
            ELSE
               J = J+1
            ENDIF
            DO 50 OT = 1,TOTATR
               ATRNEW(OT) = .TRUE.
50          CONTINUE
C  get attributes of next candidate
            CALL PQPTXR (SPECWT, J, ERRIND, JFONT, JPREC, JCHXP,
     1                   JCHSP, JCOLI)
            CALL CHKINQ ('pqptxr', ERRIND)

C  check against all those picked so far;
            DO 300 K = 1, I-1
C  if already picked, get another j
               IF (J .EQ. SUBSET(K)) GOTO 400
               CALL PQPTXR (SPECWT, SUBSET(K), ERRIND, KFONT,
     1                      KPREC, KCHXP, KCHSP, KCOLI)
               CALL CHKINQ ('pqptxr', ERRIND)
C  check all attributes
               IF (JFONT .EQ. KFONT) ATRNEW(1) = .FALSE.
               IF (JPREC .EQ. KPREC) ATRNEW(2) = .FALSE.
               IF (JCHXP .EQ. KCHXP) ATRNEW(3) = .FALSE.
               IF (JCHSP .EQ. KCHSP) ATRNEW(4) = .FALSE.
               IF (JCOLI .EQ. KCOLI) ATRNEW(5) = .FALSE.
300         CONTINUE
C  count # of trues
            ATRCNT = 0
            DO 75 OT = 1,TOTATR
               IF (ATRNEW(OT)) ATRCNT = ATRCNT + 1
75          CONTINUE
C  take the best so far
            IF (ATRCNT .GT. MAXATR) THEN
               MAXATR = ATRCNT
               MAXLOC = J
            ENDIF
C  cannot get better than OPTATR
            IF (MAXATR .GE. OPTATR) GOTO 410
400      CONTINUE

C  put best one on the list
410      CONTINUE
         SUBSET(I) = MAXLOC
C  remember greatest number of distinct attributes
         OPTATR = MAXATR
500   CONTINUE

      END
