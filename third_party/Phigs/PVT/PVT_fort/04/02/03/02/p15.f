C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/15                        *
C  *    TEST TITLE : Appearance of character expansion     *
C  *                 factor and character spacing          *
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
      INTEGER    PLN,        PPLCI
      PARAMETER (PLN = 0,    PPLCI = 2)

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

      INTEGER    NUMLIN, NGLINE, NUMCOL, NGCOL, RNDINT, IX, ICX
      INTEGER    BESTFN, IPAR, PICSTR, TXCI

      REAL       NCBHT,NCBWD, NCBHTI,NCBWDI, NCBHTW,NCBWDW
      REAL       RNDRL,XLO,XHI
      REAL       TXRX(2),TXRY(2), YINCR, YTOP, YPOS, CHHT,CHSP,CHXP
      REAL       B2, BOXHT,BOXWD,BOXINC, XINCR,XCENT,XPOS, YHI
      REAL       BOXHTW,BOXWDW, BOXHTI,BOXWDI, XA(5),YA(5), BASBOT, BB
      REAL       RDUM1,RDUM2

      CHARACTER  TXSTR*6, PTXSTR*6, DIG2*2, MSG*200

      CALL INITGL ('04.02.03.02/15')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use bundle attributes
      CALL SETASF (PBUNDL)
      CALL PSIASF (PLN, PINDIV)
      CALL PSIASF (PPLCI, PINDIV)

C  set up 102 as sub-structure
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (102)

C  use <inquire text extent> to determine, for font #1:
C    ncbht = nominal character body height
C    ncbwd = nominal character body width
      TXSTR = 'WWiig!'
      CALL PQTXX  (SPECWT, 1, 1., 0., 1., PRIGHT, PALEFT, PABOTT,
     1             TXSTR, ERRIND, TXRX,TXRY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      NCBHT = ABS(TXRY(2) - TXRY(1))
      NCBWD = ABS(TXRX(2) - TXRX(1)) / 6

C  set text path = RIGHT, font = 1
      CALL PSTXP  (PRIGHT)

      BB = BASBOT(SPECWT, 1)
C  numlin = number of lines = 6
      NUMLIN = 6
C  ngline = random number from 1 to numlin
      NGLINE = RNDINT (1,NUMLIN)

C  display and box each line, doing NGLINE incorrectly
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1 - 1.5*YINCR
      CALL NUMLAB (NUMLIN, 0.1, YTOP + 0.4*YINCR, YINCR)
      CALL PSTXAL (PALEFT, PABOTT)
      YPOS = YTOP
      DO 100 IX = 1,NUMLIN
C  ensure various character spacings
         CHSP = .3*IX - 0.7
C  randomly select a character height and expansion factor
C  to fit on one line
110      CONTINUE
         CHHT = RNDRL( 0.5, 0.9) * YINCR / NCBHT
C  as character spacings get larger, range of expansion factors
C  shifts to lower values
         CHXP = RNDRL( 1.5 - .2*IX, 2.2 - .2*IX)
C  calculate expected character boxes
         BOXHT  = CHHT * NCBHT
         BOXWD  = CHHT * NCBWD * ABS(CHXP)
         BOXINC = BOXWD + CHHT*CHSP
C  check line fit
         IF (6*BOXINC .GT. 0.8) GOTO 110
C  only the magnitude of character expansion should affect text
         IF (MOD(IX,2) .EQ. 1) CHXP = -CHXP
         CALL PSCHH  (CHHT)
         CALL PSTXI (IX)
C  set text representation ix: font=1, expansion factor=chxp
         CALL PSTXR (WKID, IX, 1, PSTRKP, CHXP, CHSP, 1)
C  if (ix = ngline) distort character boxes
         IF (IX .EQ. NGLINE) BOXINC = BOXINC * 0.8

C  draw in character boxes, using dotted line style, color #2
         CALL PSLN   (PLDOT)
         CALL PSPLCI (2)
         IPAR = 1
         B2 = BOXHT/2
         DO 120 XLO = 0.15, 0.15 + 5.5*BOXINC, BOXINC
            IF (CHSP .GE. 0) THEN
               CALL DRWREC (XLO, XLO+BOXWD, YPOS, YPOS+BOXHT)
            ELSE
               IPAR  = -IPAR
               CALL HLFBOX (XLO, YPOS + B2, BOXWD, IPAR*B2, 'Y')
            ENDIF
120      CONTINUE

C  draw in base line, using dashed line style, color #3
         CALL PSLN   (PLDASH)
         CALL PSPLCI (3)
         XA(1) = 0.15
         XA(2) = 0.15 + 5*BOXINC + BOXWD
         YA(1) = YPOS + CHHT * BB
         YA(2) = YA(1)
         CALL PPL (2,XA,YA)
C  display text on line ix
         CALL PTX (0.15, YPOS, TXSTR)
C  next ix
         YPOS = YPOS-YINCR
100   CONTINUE

      CALL SETMSG ('3 5 6 45 50 57 58 59 61 62', 'The size and '     //
     1             'shape of a text string displayed with STROKE '   //
     2             'precision in a monospaced font on a horizontal ' //
     3             'text path should conform exactly to the '        //
     4             'character height, expansion factor, and '        //
     5             'spacing in effect.')

      CALL DCHPFV ('CHARACTER EXPANSION AND SPACING IN HORIZONTAL ' //
     1             'TEXT: In which line are the characters of the ' //
     2             'text string NOT aligned within dotted '         //
     3             'character boxes and on the dashed baseline?',
     4             NUMLIN, NGLINE)

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  numcol = number of columns = 6
      NUMCOL = 6
C  ngcol  = random number from 1 to numcol
      NGCOL = RNDINT (1,NUMCOL)

C  display and box each column, doing NGCOL incorrectly
      XINCR = 1.0 / (NUMCOL+1)
      XCENT = XINCR
C  draw labels across top of columns
      CALL PSTXAL (PACENT, PABASE)
      CALL PSCHH  (0.04)
      CALL PSTXI (NUMCOL+1)
      CALL PSTXR (WKID, NUMCOL+1, 1, PSTRKP, 0.8, 0.2, 1)
      XPOS = XCENT
      DO 190 IX = 1,NUMCOL
         WRITE (DIG2, '(I1,A)') IX, ':'
         CALL PTX (XPOS, 0.9, DIG2)
         XPOS = XPOS + XINCR
190   CONTINUE

C  set text path = DOWN
      CALL PSTXP  (PDOWN)
      CALL PSTXAL (PACENT, PATOP)
      XPOS = XCENT
      DO 200 IX = 1,NUMCOL
C  ensure various character spacings
         CHSP = .3*IX - 0.7
C  randomly select a character height, expansion factor, and
C  spacing, to fit in one column
210      CONTINUE
C  as character spacings get larger, range of character heights
C  shifts to lower values
         CHHT = RNDRL( MAX(0.3, 1.0 - 0.2*IX), 1.0) / (6*NCBHT)
         CHXP = RNDRL( 0.5, 3.0)
C  calculate expected character boxes
         BOXWD = NCBWD * CHHT * CHXP
         BOXHT = CHHT * NCBHT
         BOXINC = CHHT * (NCBHT + CHSP)
C  check column fit
         IF (BOXWD .GT. 0.9*XINCR) GOTO 210
         IF (6*BOXINC .GT. 0.8) GOTO 210

C  only the magnitude of character expansion should affect text
         IF (MOD(IX,2) .EQ. 1) CHXP = -CHXP
         CALL PSCHH  (CHHT)
         CALL PSTXI (IX)
C  set text representation ix: font=1, expansion factor=chxp
         CALL PSTXR (WKID, IX, 1, PSTRKP, CHXP, CHSP, 1)
C  if (ix = ngcol) distort character boxes
         IF (IX .EQ. NGCOL) BOXINC = BOXINC * 0.8

C  draw in character boxes, using dotted line style, color #2
         CALL PSLN   (PLDOT)
         CALL PSPLCI (2)
         IPAR = 1
         B2 = BOXWD/2
         DO 220 YHI = 0.85, 0.85 - 5.5*BOXINC, -BOXINC
            IF (CHSP .GE. 0) THEN
               CALL DRWREC (XPOS-B2, XPOS+B2, YHI-BOXHT, YHI)
            ELSE
               IPAR  = -IPAR
               CALL HLFBOX (XPOS, YHI, IPAR*B2, -BOXHT, 'X')
            ENDIF
220      CONTINUE

C  draw in center line, using dashed line style, color #3
         CALL PSLN   (PLDASH)
         CALL PSPLCI (3)
         XA(1) = XPOS
         XA(2) = XPOS
         YA(1) = 0.85
         YA(2) = 0.85 - 5*BOXINC - BOXHT
         CALL PPL (2,XA,YA)
C  display text in column ix
         CALL PTX (XPOS, 0.85, TXSTR)
C  next ix
         XPOS = XPOS+XINCR
200   CONTINUE

      CALL SETMSG ('3 5 6 45 50 57 58 59 61 62', 'The size and '   //
     1             'shape of a text string displayed with STROKE ' //
     2             'precision in a monospaced font on a vertical ' //
     3             'text path should conform exactly to the '      //
     4             'character height, expansion factor, and '      //
     5             'spacing in effect.')

      CALL DCHPFV ('CHARACTER EXPANSION AND SPACING IN VERTICAL ' //
     1             'TEXT: In which column are the characters of ' //
     2             'the text string NOT aligned within dotted '   //
     3             'character boxes and on the dashed centerline?',
     4             NUMCOL, NGCOL)

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  bestfn = a stroke text font other than 1, preferably not #2 and
C     not monospaced
      CALL VARFNT (BESTFN, NCBHTW, NCBWDW, NCBHTI, NCBWDI)

      IF (BESTFN .EQ. 1) THEN
         CALL INMSG ('Skipping tests for fonts other than #1; ' //
     1               'none available.')
         GOTO 666
      ELSE
         WRITE (MSG, '(A,I6,A)') 'Using #', BESTFN,
     1         ' as alternative font for horizontal text path.'
         CALL INMSG (MSG)
      ENDIF

C  set text path = LEFT
      CALL PSTXP  (PLEFT)
      BB = BASBOT(SPECWT, BESTFN)
C  numlin = number of lines = 6
      NUMLIN = 6
C  ngline = random number from 1 to numlin
      NGLINE = RNDINT (1,NUMLIN)

C  display and box each line, doing NGLINE incorrectly
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1 - 1.5*YINCR
      CALL NUMLAB (NUMLIN, 0.1, YTOP + 0.4*YINCR, YINCR)
      CALL PSTXAL (PALEFT, PABOTT)
      YPOS = YTOP
      PTXSTR = 'WWiiiW'
      DO 400 IX = 1,NUMLIN
C  ensure various character spacings
         CHSP = .3*IX - 0.7
C  randomly select a character height, expansion factor, and
C  spacing, to fit on one line
410      CONTINUE
         CHHT = RNDRL( 0.5, 0.9) * YINCR / NCBHTW
C  as character spacings get larger, range of expansion factors
C  shifts to lower values
         CHXP = RNDRL( 1.5 - .2*IX, 2.2 - .2*IX)
C  calculate expected character boxes
         BOXHTW  = CHHT * NCBHTW
         BOXWDW  = CHHT * NCBWDW * ABS(CHXP)
         BOXHTI  = CHHT * NCBHTI
         BOXWDI  = CHHT * NCBWDI * ABS(CHXP)
C  check line fit
         IF (3*(BOXWDW+BOXWDI) + (5*CHHT*CHSP) .GT. 0.8) GOTO 410

C  only the magnitude of character expansion should affect text
         IF (MOD(IX,2) .EQ. 1) CHXP = -CHXP
         CALL PSCHH  (CHHT)
         CALL PSTXI (IX)
C  set text representaion ix: font = bestfn
         CALL PSTXR (WKID, IX, BESTFN, PSTRKP, CHXP, CHSP, 1)
C  if (ix = ngline) distort character boxes
         IF (IX .EQ. NGLINE) BOXWDW = BOXWDW * 0.7

C  draw in character boxes, using dotted line style, color #2
         CALL PSLN   (PLDOT)
         CALL PSPLCI (2)
         XLO = 0.15
         IPAR = 1
C  backwards, because path is to the left
         DO 420 ICX = 6,1,-1
            IF (PTXSTR(ICX:ICX) .EQ. 'W') THEN
               BOXWD = BOXWDW
               BOXHT = BOXHTW
            ELSE
               BOXWD = BOXWDI
               BOXHT = BOXHTI
            ENDIF
            XHI = XLO+BOXWD
            IF (CHSP .GE. 0) THEN
               CALL DRWREC (XLO, XHI, YPOS, YPOS+BOXHT)
            ELSE
               B2 = BOXHT/2
               IPAR  = -IPAR
               CALL HLFBOX (XLO, YPOS + B2, BOXWD, IPAR*B2, 'Y')
            ENDIF
            XLO = XLO + BOXWD + CHHT*CHSP
420      CONTINUE

C  draw in base line, using dashed line style, color #3
         CALL PSLN   (PLDASH)
         CALL PSPLCI (3)
         XA(1) = 0.15
         XA(2) = XHI
         YA(1) = YPOS + CHHT * BB
         YA(2) = YA(1)
         CALL PPL (2,XA,YA)
C  display text on line ix
         CALL PTX (0.15, YPOS, PTXSTR)
C  next ix
         YPOS = YPOS-YINCR
400   CONTINUE

      CALL SETMSG ('3 5 6 50 57 58 59 61 62', 'The size and shape ' //
     1             'of a text string displayed with STROKE '        //
     2             'precision in any font on a horizontal text '    //
     3             'path should conform exactly to the character '  //
     4             'height, expansion factor, and spacing in '      //
     5             'effect.')

      CALL DCHPFV ('CHARACTER EXPANSION AND SPACING IN HORIZONTAL ' //
     1             'TEXT: In which line are the characters of the ' //
     2             'text string NOT aligned within dotted '         //
     3             'character boxes and on the dashed baseline?',
     4             NUMLIN, NGLINE)

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  bestfn = a stroke text font other than 1, preferably not #2 and
C     not monospaced
      CALL VARFNT (BESTFN, NCBHTW, NCBWDW, NCBHTI, NCBWDI)
      WRITE (MSG, '(A,I6,A)') 'Using #', BESTFN,
     1      ' as alternative font for vertical text path.'
      CALL INMSG (MSG)

C  numcol = number of columns = 6
      NUMCOL = 6
C  ngcol  = random number from 1 to numcol
      NGCOL = RNDINT (1,NUMCOL)

C  display and box each column, doing NGCOL incorrectly
      XINCR = 1.0 / (NUMCOL+1)
      XCENT = XINCR
C  draw labels across top of columns
      CALL PSTXAL (PACENT, PABASE)
      CALL PSCHH  (0.04)
      CALL PSTXI (NUMCOL+1)
      CALL PSTXR (WKID, NUMCOL+1, 1, PSTRKP, 0.8, 0.2, 1)
      XPOS = XCENT
      DO 490 IX = 1,NUMCOL
         WRITE (DIG2, '(I1,A)') IX, ':'
         CALL PTX (XPOS, 0.9, DIG2)
         XPOS = XPOS + XINCR
490   CONTINUE

C  set text path = UP
      CALL PSTXP (PUP)
      CALL PSTXAL (PACENT, PATOP)

      XPOS = XCENT
      DO 500 IX = 1,NUMCOL
C  ensure various character spacings
         CHSP = .3*IX - 0.7
C  randomly select a character height, expansion factor, and
C  spacing, to fit in one column
510      CONTINUE
C  as character spacings get larger, range of character heights
C  shifts to lower values
         CHHT = RNDRL( MAX(0.3, 1.0 - 0.2*IX), 1.0) / (6*NCBHTW)
         CHXP = RNDRL( 0.5, 3.0)
C  calculate expected character boxes
         BOXHTW  = CHHT * NCBHTW
         BOXWDW  = CHHT * NCBWDW * ABS(CHXP)
         BOXHTI  = CHHT * NCBHTI
         BOXWDI  = CHHT * NCBWDI * ABS(CHXP)
C  check column fit
         IF (BOXWDW .GT. 0.9*XINCR .OR. BOXWDI .GT. 0.9*XINCR) GOTO 510
         IF (3*(BOXHTW+BOXHTI) + (5*CHHT*CHSP) .GT. 0.8) GOTO 510
C  only the magnitude of character expansion should affect text
         IF (MOD(IX,2) .EQ. 1) CHXP = -CHXP
         CALL PSCHH  (CHHT)
         CALL PSTXI (IX)
C  set text representation ix: font=bestfn
         CALL PSTXR (WKID, IX, BESTFN, PSTRKP, CHXP, CHSP, 1)
C  if (ix = ngcol) distort character boxes
         IF (IX .EQ. NGCOL) BOXHTW = BOXHTW * 0.7

C  draw in character boxes, using dotted line style, color #2
         CALL PSLN   (PLDOT)
         CALL PSPLCI (2)
         YHI = 0.85
         IPAR = 1
C  backwards, because path is to the left
         DO 520 ICX = 6,1,-1
            IF (PTXSTR(ICX:ICX) .EQ. 'W') THEN
               BOXWD = BOXWDW
               BOXHT = BOXHTW
            ELSE
               BOXWD = BOXWDI
               BOXHT = BOXHTI
            ENDIF

            B2 = BOXWD/2
            IF (CHSP .GE. 0) THEN
               CALL DRWREC (XPOS-B2, XPOS+B2, YHI-BOXHT, YHI)
            ELSE
               IPAR  = -IPAR
               CALL HLFBOX (XPOS, YHI, IPAR*B2, -BOXHT, 'X')
            ENDIF
            YHI = YHI - BOXHT - CHHT*CHSP
520      CONTINUE

C  draw in center line, using dashed line style, color #3
         CALL PSLN   (PLDASH)
         CALL PSPLCI (3)
         XA(1) = XPOS
         XA(2) = XPOS
         YA(1) = 0.85
         YA(2) = YHI + CHHT*CHSP
         CALL PPL (2,XA,YA)
C  display text in column ix
         CALL PTX (XPOS, 0.85, PTXSTR)
C  next ix
         XPOS = XPOS+XINCR
500   CONTINUE

      CALL SETMSG ('3 5 6 50 57 58 59 61 62', 'The size and shape ' //
     1             'of a text string displayed with STROKE '        //
     2             'precision in any font on a vertical text path ' //
     3             'should conform exactly to the character '       //
     4             'height, expansion factor, and spacing in '      //
     5             'effect.')

      CALL DCHPFV ('CHARACTER EXPANSION AND SPACING IN VERTICAL ' //
     1             'TEXT: In which column are the characters of ' //
     2             'the text string NOT aligned within dotted '   //
     3             'character boxes and on the dashed '           //
     4             'centerline?', NUMCOL, NGCOL)

      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
