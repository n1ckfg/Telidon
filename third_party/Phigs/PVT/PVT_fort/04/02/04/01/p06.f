C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/06                        *
C  *    TEST TITLE : Annotation text path, character       *
C  *                 height, expansion factor, spacing,    *
C  *                 and up vector                         *
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
      REAL       NPCX,NPCY,NPCPWC, XF(3,3), Z,U
      REAL       RDUM1,RDUM2

      PARAMETER (Z=0.0, U=1.0)

      CHARACTER  TXSTR*6, PTXSTR*6, DIG2*2, MSG*200

      CALL INITGL ('04.02.04.01/06')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  always use STROKE
      CALL PSTXPR (PSTRKP)
C  set up 102 as sub-structure
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (102)

      CALL SETMSG ('5 7 23 55 56 57 58 70 71 72', 'Annotation '     //
     1             'text path should specify the direction in '     //
     1             'which successive characters are generated and ' //
     1             'annotation text character up vector should '    //
     1             'rotate the resulting primitive.')
      CALL TXPCUP ('A')
      CALL PEMST (102)

C  use <inquire text extent> to determine, for font #1:
C    ncbht = nominal character body height
C    ncbwd = nominal character body width
      TXSTR = 'WWiig!'
      CALL PQTXX  (SPECWT, 1, 1., 0., 1., PRIGHT, PALEFT, PABOTT,
     1             TXSTR, ERRIND, TXRX,TXRY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      NCBHT = ABS(TXRY(2) - TXRY(1))
      NCBWD = ABS(TXRX(2) - TXRX(1)) / 6

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  set annotation text path = RIGHT, font = 1
      CALL PSATP  (PRIGHT)
      CALL PSTXFN (1)
      BB = BASBOT(SPECWT, 1)
C  numlin = number of lines = 6
      NUMLIN = 6
C  ngline = random number from 1 to numlin
      NGLINE = RNDINT (1,NUMLIN)

C  display and box each line, doing NGLINE incorrectly
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1 - 1.5*YINCR
      CALL NUMLAB (NUMLIN, 0.1, YTOP + 0.3*YINCR, YINCR)
      CALL PSATAL (PALEFT, PABOTT)
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
         CHXP = ABS(CHXP)

         CALL PSATCH (CHHT * NPCPWC)
         CALL PSCHSP (CHSP)
         CALL PSCHXP (CHXP)
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

C  set non-unit scaling modelling transform to show that size of
C  annotation-text is unaffected, even though location is affected.
         CALL PBLTM (0.15,YPOS, Z,Z, 1.33, 1.5,0.6, ERRIND, XF)
         CALL CHKINQ ('pbltm', ERRIND)
         CALL PSGMT (XF)

C  try to confuse the issue
         CALL PSCHH (22.3)
         CALL PSCHUP (2., 3.)
         CALL PSTXP  (PLEFT)        
         CALL PSTXAL (PALEFT, PABOTT)

C  display annotation text "WWiig!" on line ix
         CALL PATR (0.15, YPOS, Z,Z, TXSTR)
C  restore identity modelling transform
         CALL IDMAT (3, XF)
         CALL PSGMT (XF)
C  next ix
         YPOS = YPOS-YINCR
100   CONTINUE

      CALL SETMSG ('1 2 5 11 23 26 27 28 32 33 34 48 49 50 51 52 ' //
     1             '57 58 60',
     1             'The size and shape of an annotation text string ' //
     2             'displayed with STROKE precision in a monospaced ' //
     3             'font on a horizontal annotation text path '       //
     4             'should conform exactly to the annotation text '   //
     5             'character height, expansion factor, and spacing ' //
     6             'in effect.')

      CALL DCHPFV ('ANNOTATION TEXT CHARACTER HEIGHT, EXPANSION, '   //
     1             'AND SPACING IN HORIZONTAL PATHS: In which line ' //
     2             'are the characters of the annotation text '      //
     3             'string NOT aligned within dotted character '     //
     4             'boxes and on the dashed baseline?', NUMLIN, NGLINE)

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

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
      XPOS = XCENT
      DO 190 IX = 1,NUMCOL
         WRITE (DIG2, '(I1,A)') IX, ':'
         CALL PTX (XPOS, 0.9, DIG2)
         XPOS = XPOS + XINCR
190   CONTINUE

C  set annotation text path = DOWN, font = 1
      CALL PSATP  (PDOWN)
      CALL PSTXFN (1)
      CALL PSATAL (PACENT, PATOP)
      XPOS = XCENT
      YTOP = 0.85

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
         CALL PSATCH (CHHT * NPCPWC)
         CALL PSCHSP (CHSP)
         CALL PSCHXP (CHXP)
C  if (ix = ngcol) distort character boxes
         IF (IX .EQ. NGCOL) BOXINC = BOXINC * 0.8

C  draw in character boxes, using dotted line style, color #2
         CALL PSLN   (PLDOT)
         CALL PSPLCI (2)
         IPAR = 1
         B2 = BOXWD/2
         DO 220 YHI = YTOP, YTOP - 5.5*BOXINC, -BOXINC
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
         YA(1) = YTOP
         YA(2) = YTOP - 5*BOXINC - BOXHT
         CALL PPL (2,XA,YA)

C  set non-unit scaling modelling transform to show that size of
C  annotation-text is unaffected, even though location is affected.
         CALL PBLTM (XPOS,YTOP, Z,Z, 0.66, 1.5,0.6, ERRIND, XF)
         CALL CHKINQ ('pbltm', ERRIND)
         CALL PSGMT (XF)

C  try to confuse the issue
         CALL PSCHH (22.3)
         CALL PSCHUP (2., 3.)
         CALL PSTXP  (PLEFT)        
         CALL PSTXAL (PALEFT, PABOTT)

C  display text in column ix
         CALL PATR (XPOS, YTOP, Z,Z, TXSTR)

C  restore identity modelling transform
         CALL IDMAT (3, XF)
         CALL PSGMT (XF)
C  next ix
         XPOS = XPOS+XINCR
200   CONTINUE

      CALL SETMSG ('1 2 5 11 23 26 27 28 32 33 34 48 49 50 51 52 ' //
     1             '57 58 59',
     1             'The size and shape of an annotation text string ' //
     2             'displayed with STROKE precision in a monospaced ' //
     3             'font on a vertical annotation text path should '  //
     4             'conform exactly to the annotation text '          //
     5             'character height, expansion factor, and spacing ' //
     6             'in effect.')

      CALL DCHPFV ('ANNOTATION TEXT CHARACTER HEIGHT, EXPANSION, '    //
     1             'AND SPACING IN VERTICAL PATHS: In which column '  //
     2             'are the characters of the annotation text '       //
     3             'string NOT aligned within dotted character '      //
     4             'boxes and on the dashed centerline?',
     5             NUMLIN, NGCOL)

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

C  bestfn = a stroke text font other than 1, preferably not #2 and
C     not monospaced
      CALL VARFNT (BESTFN, NCBHTW, NCBWDW, NCBHTI, NCBWDI)

      IF (BESTFN .EQ. 1) THEN
         CALL INMSG ('Skipping tests for fonts other than #1; ' //
     1               'none available.')
         GOTO 666
      ELSE
         WRITE (MSG, '(A,I6,A)') 'Using #', BESTFN,
     1                           ' as alternative font.'
         CALL INMSG (MSG)
      ENDIF

C  set text path = LEFT
      CALL PSATP  (PLEFT)
      CALL PSTXFN (BESTFN)
      BB = BASBOT(SPECWT, BESTFN)
C  numlin = number of lines = 6
      NUMLIN = 6
C  ngline = random number from 1 to numlin
      NGLINE = RNDINT (1,NUMLIN)

C  display and box each line, doing NGLINE incorrectly
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1 - 1.5*YINCR
      CALL NUMLAB (NUMLIN, 0.1, YTOP + 0.3*YINCR, YINCR)
      CALL PSATAL (PALEFT, PABOTT)
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
         CALL PSATCH (CHHT * NPCPWC)
         CALL PSCHSP (CHSP)
         CALL PSCHXP (CHXP)
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

C  try to confuse the issue
         CALL PSCHH (22.3)
         CALL PSCHUP (2., 3.)
         CALL PSTXP  (PLEFT)        
         CALL PSTXAL (PALEFT, PABOTT)
C  display text on line ix
         CALL PATR (0.15, YPOS, Z,Z, PTXSTR)
C  next ix
         YPOS = YPOS-YINCR
400   CONTINUE

      CALL SETMSG ('1 2 5 11 23 26 27 28 32 33 34 48 49 50 51 52 ' //
     1             '57 58 60',
     1             'The size and shape of an annotation text string ' //
     2             'displayed with STROKE precision in any font on '  //
     3             'a horizontal annotation text path should '        //
     4             'conform exactly to the annotation text '          //
     5             'character height, expansion factor, and spacing ' //
     6             'in effect.')

      CALL DCHPFV ('ANNOTATION TEXT CHARACTER HEIGHT, EXPANSION, '   //
     1             'AND SPACING IN HORIZONTAL PATHS: In which line ' //
     2             'are the characters of the annotation text '      //
     3             'string NOT aligned within dotted character '     //
     4             'boxes and on the dashed baseline?', NUMLIN, NGLINE)

      CALL PEMST (102)

C  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

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
      XPOS = XCENT
      DO 490 IX = 1,NUMCOL
         WRITE (DIG2, '(I1,A)') IX, ':'
         CALL PTX (XPOS, 0.9, DIG2)
         XPOS = XPOS + XINCR
490   CONTINUE

C  set text path = UP
      CALL PSATP  (PUP)
      CALL PSTXFN (BESTFN)
      CALL PSATAL (PACENT, PATOP)

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
         CALL PSATCH (CHHT * NPCPWC)
         CALL PSCHSP (CHSP)
         CALL PSCHXP (CHXP)
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

C  try to confuse the issue
         CALL PSCHH (22.3)
         CALL PSCHUP (2., 3.)
         CALL PSTXP  (PLEFT)        
         CALL PSTXAL (PALEFT, PABOTT)
C  display text in column ix
         CALL PATR (XPOS, 0.85, Z,Z, PTXSTR)
C  next ix
         XPOS = XPOS+XINCR
500   CONTINUE

      CALL SETMSG ('1 2 5 11 19 23 26 27 29 32 33 34 48 49 50 52 ' //
     1             '57 58 59',
     1             'The size and shape of an annotation text string ' //
     2             'displayed with STROKE precision in any font on '  //
     3             'a vertical annotation text path should conform '  //
     4             'exactly to the annotation text character '        //
     5             'height, expansion factor, and spacing in effect.')

      CALL DCHPFV ('ANNOTATION TEXT CHARACTER HEIGHT, EXPANSION, '    //
     1             'AND SPACING IN VERTICAL PATHS: In which column '  //
     2             'are the characters of the annotation text '       //
     3             'string NOT aligned within dotted character '      //
     4             'boxes and on the dashed centerline?',
     5             NUMLIN, NGCOL)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

