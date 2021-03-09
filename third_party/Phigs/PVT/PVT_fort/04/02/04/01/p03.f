C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/03                        *
C  *    TEST TITLE : Appearance of all text fonts          *
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

      INTEGER     NFPP, IX, THISFN,THISPR, LPOSFN(200),LPOSPR(200),LPOSX
      INTEGER     LNEGFN(200),LNEGPR(200),LNEGX, LSTRK(200),LSTRKX
      INTEGER     IARFND, ELLOC, TXFNT
      INTEGER     PICSTR, TXCI, NUMCOL, NGCOL, RNDINT
      INTEGER     NUMCH, NUMSHT, CURFNT, NUMLIN, NGLINE, CAPIX(3)
      INTEGER     UNR1SZ,UNR1LS(20), UNR2SZ,UNR2LS(20), PERM(20)
      INTEGER     MINSTR,MAXSTR, ALFSIZ, ALFONT(300)
      INTEGER     LUNX, LUNSFN(20), LUNSPR(20), MAXFNT, PARITY
      INTEGER     IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL        XLEFT, XPOS, XINCR, YPOS, YINCR, NCSH, RNDRL
      REAL        YTOP, CHSP, CHHT, CHEXP, CHSIZ, OFFACT, XA(5),YA(5)
      REAL        TXRX(2),TXRY(2), CAPY, XB(5), LBOX,RBOX
      REAL        NPCX,NPCY,NPCPWC
      REAL        RDUM1,RDUM2,RDUM3,RDUM4

      CHARACTER   CHSTR*10, VLBL*2, DISTRG*60, RESULT*1
      CHARACTER   SHRTCH*15, TALLCH*15, CAPS(26)*1, STR*3, MSG*300

      DATA  CAPS / 'A','B','C','D','E','F','G','H','I','J','K','L','M',
     1             'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' /

      CALL INITGL ('04.02.04.01/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  use structure 102 to hold changeable stuff
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (102)

C  use <inquire text facilities> to determine
C    lposfn = list of positive fonts and highest available precision
C             for each, other than fonts 1 and 2
C    lnegfn = list of non-positive fonts and highest available precision
C             for each
C    lstrk  = list of fonts available in STROKE precision
      CALL PQTXF (SPECWT, 0, ERRIND, NFPP, IDUM1,IDUM2,
     1            IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
      LPOSX  = 0
      LNEGX  = 0
      LSTRKX = 0
      DO 100 IX = 1,NFPP
         CALL PQTXF (SPECWT, IX, ERRIND, IDUM1, THISFN,THISPR,
     1               IDUM3,RDUM1,RDUM2, IDUM4,RDUM3,RDUM4, IDUM5)
         CALL CHKINQ ('pqtxf', ERRIND)
C  build list of stroke fonts
         IF (THISPR .EQ. PSTRKP) THEN
            LSTRKX = LSTRKX+1
            LSTRK(LSTRKX) = THISFN
         ENDIF
         IF (THISFN .GT. 2) THEN
            ELLOC = IARFND (THISFN, LPOSX, LPOSFN)
            IF (ELLOC .EQ. 0) THEN
               LPOSX = LPOSX+1
               LPOSFN(LPOSX) = THISFN
               LPOSPR(LPOSX) = THISPR
            ELSE
               IF (THISPR .GT. LPOSPR(ELLOC)) THEN
                  LPOSPR(ELLOC) = THISPR
               ENDIF
            ENDIF
         ELSEIF (THISFN .LT. 1) THEN
            ELLOC = IARFND (THISFN, LNEGX, LNEGFN)
            IF (ELLOC .EQ. 0) THEN
               LNEGX = LNEGX+1
               LNEGFN(LNEGX) = THISFN
               LNEGPR(LNEGX) = THISPR
            ELSE
               IF (THISPR .GT. LNEGPR(ELLOC)) THEN
                  LNEGPR(ELLOC) = THISPR
               ENDIF
            ENDIF
         ENDIF
100   CONTINUE

      MAXFNT = 8
      CHSTR = 'AaZz09$;^}'

      IF (LPOSX .LE. 0) THEN
         CALL INMSG ('No non-mandatory registered text fonts are ' //
     1               'supported.')
         GOTO 190
      ENDIF

      MSG = 'NON-MANDATORY REGISTERED TEXT FONTS: Do all '   //
     1      'displayed, labelled text fonts agree with the ' //
     2      'corresponding description in the ISO register?'

      CALL SETMSG ('5 6 12 14', 'All positive text fonts should ' //
     1             'appear as specified in the ISO register.')

      CALL INMSG ('SR 12 is indirectly confirmed in the following '  //
     1     'test case since this test must be run against all '      //
     1     'workstation types, and the ISO register documentation '  //
     1     'must be correct for all of them.')

C  call routine to handle display
      CALL CHKFNT (LPOSX,LPOSFN,LPOSPR, MAXFNT, CHSTR, .FALSE., 'A')
      CALL DYNPF (MSG, 'y')
      CALL PEMST (102)

      CALL SETMSG ('5 6 12 14 21', 'All positive text fonts should ' //
     1             'appear as specified in the ISO register, even '  //
     2             'when less precision is requested than is '       //
     3             'available for the font.')

C  call routine to handle display
      CALL CHKFNT (LPOSX,LPOSFN,LPOSPR, MAXFNT, CHSTR, .TRUE., 'A')
      CALL DYNPF (MSG, 'y')
      CALL PEMST (102)

C  end_pos:
190   CONTINUE

      IF (LNEGX .LE. 0) THEN
         CALL INMSG ('No implementor defined text fonts are ' //
     1               'supported.')
         GOTO 290
      ENDIF

      MSG = 'IMPLEMENTOR DEFINED TEXT FONTS: Answer y if '    //
     1      'both are true, otherwise n: 1) the implementor ' //
     1      'provides accurate documentation for all these '  //
     1      'fonts, and 2) the documentation indicates that ' //
     1      'a font identifier denotes the same font on all ' //
     1      'workstation types which support that identifier.'

      CALL SETMSG ('5 6 12 14', 'All non-positive text fonts should ' //
     1             'be workstation independent and appear as '        //
     2             'specified in the implementor''s documentation.')

C  call routine to handle display
      CALL CHKFNT (LNEGX,LNEGFN,LNEGPR, MAXFNT, CHSTR, .FALSE., 'A')
      CALL DYNPF (MSG, 'y')
      CALL PEMST (102)

      CALL SETMSG ('5 6 12 14 21', 'All non-positive text fonts '     //
     1             'should be workstation independent and appear as ' //
     2             'specified in the implementor''s documentation, '  //
     3             'even when less precision is requested than is '   //
     4             'available for the font.')

C  call routine to handle display
      CALL CHKFNT (LNEGX,LNEGFN,LNEGPR, MAXFNT, CHSTR, .TRUE., 'A')
      CALL DYNPF (MSG, 'y')
      CALL PEMST (102)

C  end_font_id:
290   CONTINUE

      CALL SETMSG ('5 6 9 10 23 27 33 49', 'In each text font, all '  //
     1             'character bodies affected by the same '           //
     2             'annotation text character height, character '     //
     3             'expansion factor, and character spacing should '  //
     4             'have the same height.')

      CALL PSTXPR (PSTRKP)
      CALL PSCHH  (.04)
      CALL PSTXAL (PALEFT,PATOP)

C  numcol = number of columns to display = 6
      NUMCOL = 6
C  ngcol  = incorrect column = random number from 1 to numcol
      NGCOL = RNDINT (1,NUMCOL)
C  display labels for all numcol columns to be shown
      XLEFT = .05
      XPOS  = XLEFT
      XINCR = .90 / NUMCOL
      DO 500 IX = 1,NUMCOL
         WRITE (VLBL, '(I1,A)') IX, ':'
         CALL PTX (XPOS, .95, VLBL)
         XPOS = XPOS + XINCR
500   CONTINUE

C  set up short, tall characters
      SHRTCH = ',''_~;`."-=+*^@#'
      TALLCH = 'W|j(g!)Q[]/\IMH'

C  display vertical text
      XPOS = XLEFT
      CHSP = 0.2
      CALL PSCHSP (CHSP)
      CALL PSATP  (PDOWN)
      YTOP = 0.85
C  try to paint text and polylines different colors
      CALL PSTXCI (1)
      CALL PSPLCI (2)
      CALL PSATAL (PALEFT,PATOP)
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

      DO 600 IX = 1,NUMCOL
C  txfnt = random value from lstrk
         TXFNT = LSTRK(RNDINT(1,LSTRKX))

C  Use <inquire text extent> to determine
C  ncsh = (nominal vertical character body size /
C          requested character height)  for txfnt
         CALL PQTXX  (SPECWT, TXFNT, 1., 0., 1., PDOWN, PALEFT, PABOTT,
     1                'Testing 123', ERRIND, TXRX,TXRY, RDUM1,RDUM2)
         CALL CHKINQ ('pqtxx', ERRIND)
         NCSH = ABS(TXRY(2) - TXRY(1)) / 11
610      CONTINUE
         CHHT  = RNDRL(.2/NUMCOL, .6/NUMCOL)
         CHEXP = RNDRL(.3, 3.0)
C  don't exceed column width
         IF (CHHT*CHEXP .GE. 0.8*XINCR) GOTO 610
C  chsiz  = vertical distance per character
         CHSIZ = CHHT * (NCSH + CHSP)
C  numch  = number of characters this string
         NUMCH  = INT( (YTOP-.05) / CHSIZ)
C  make sure numch between 4 and 25, else pick new values
         IF (NUMCH.LT.4 .OR. NUMCH.GT.25) GOTO 610
C  numsht = number of short characters = numch/2
         NUMSHT = NUMCH/2
         DISTRG = SHRTCH(:NUMSHT) // TALLCH(:NUMCH-NUMSHT)
         CALL PSTXFN (TXFNT)
         CALL PSATCH (CHHT * NPCPWC)
         CALL PSCHXP (CHEXP)
C  display distrg at location ix
         CALL PATR (XPOS, YTOP, 0.0,0.0, DISTRG(:NUMCH))
C  set offset factor to distort separators if this column no good
         IF (IX .EQ. NGCOL) THEN
            OFFACT = 0.4 * RNDINT(2,3)
         ELSE
            OFFACT = 1.0
         ENDIF

C  draw horizontal lines between characters, assuming that chht,
C     chsp, and chexp are in effect, distorted by offact
         XA(1) = XPOS
         XA(2) = XPOS + CHHT*CHEXP
C  start in middle of character space between 1st and 2nd characters
         DO 650 YPOS = YTOP - CHSIZ + CHSP*CHHT/2,
     1                 YTOP - (NUMCH-0.5)*CHSIZ, -CHSIZ*OFFACT
            YA(1) = YPOS
            YA(2) = YPOS
            CALL PPL (2, XA,YA)
650      CONTINUE
         XPOS = XPOS + XINCR
C  next ix
600   CONTINUE

      CALL DCHPFV ('UNIFORM HEIGHT FOR CHARACTER BODIES: In which ' //
     1             'column are the characters NOT aligned between ' //
     2             'the separators?', NUMCOL, NGCOL)
      CALL PEMST (102)

      CALL SETMSG ('1 2 5 7 9 10 23 48 49 66', 'Annotation text '   //
     1             'character height magnitude should specify the ' //
     2             'nominal height, in TLC, from baseline to '      //
     3             'capline, of all capital letters within a font.')

      CALL DILIST ('ANNOTATION TEXT CHARACTER HEIGHT FOR SIZE OF ' //
     1             'CAPITAL LETTERS: Enter list of font '          //
     2             'identifiers available in stroke precision, '   //
     3             'other than 1 and 2, which support alphabetic ' //
     4             'characters (n if none).', ALFSIZ, ALFONT)

C  add 1 and 2
      ALFONT(ALFSIZ+1) = 1
      ALFONT(ALFSIZ+2) = 2
      ALFSIZ = ALFSIZ+2

C  set number of lines, no-good line
      NUMLIN = 6
      NGLINE = RNDINT (1, NUMLIN)
      YINCR = 1.0 / (NUMLIN + 1)
      YPOS  = 1-YINCR
C  try to paint text and polylines different colors
      CALL PSTXCI (1)
      CALL PSPLCI (2)

      PARITY = -1
      LBOX = 0.3
      RBOX = 0.9

C  draw labels
      CALL NUMLAB (NUMLIN, LBOX-.05, YPOS+0.25*YINCR, YINCR)
      CALL PSTXPR (PSTRKP)
      CALL PSATAL (PALEFT, PABASE)

      XA(1) = LBOX
      XA(2) = RBOX
      XB(1) = LBOX
      XB(2) = LBOX
      XB(3) = RBOX
      XB(4) = RBOX
      DO 700 IX = 1,NUMLIN
C  str = 3 random capital letters
         CALL RNSET (3, 26, CAPIX)
         STR (1:1) = CAPS(CAPIX(1))
         STR (2:2) = CAPS(CAPIX(2))
         STR (3:3) = CAPS(CAPIX(3))
C  chht = random value between .2*YINCR AND .8*YINCR
         CHHT = RNDRL (.2*YINCR, .8*YINCR)
         PARITY = -PARITY
         CALL PSATCH (PARITY*CHHT * NPCPWC)
         IF (IX .EQ. NGLINE) THEN
C  draw incorrect base, cap lines
            IF (CHHT .LT. 0.5*YINCR) THEN
C  draw lines too far apart
               CAPY = YPOS + 1.25*CHHT
            ELSE
C  draw lines too close
               CAPY = YPOS + 0.75*CHHT
            ENDIF

         ELSE
C  draw correct base, cap lines
            CAPY = YPOS + CHHT
         ENDIF
         YA(1) = YPOS
         YA(2) = YPOS
         CALL PSLN (PLDASH)
         CALL PPL (2, XA,YA)
         YA(2) = CAPY
         YA(3) = CAPY
         YA(4) = YPOS
         CALL PSLN (PLDOT)
         CALL PPL (4, XB,YA)
C  curfnt = random pick from alfont
         CURFNT = ALFONT (RNDINT(1,ALFSIZ))
C  display and label str, using chht and curfnt
         CALL PSTXFN (CURFNT)
         CALL PATR (LBOX+0.1, YPOS, 0.0,0.0, STR)
         YPOS = YPOS - YINCR
C  next ix
700   CONTINUE

      CALL DCHPFV ('ANNOTATION TEXT CHARACTER HEIGHT FOR SIZE OF ' //
     1             'CAPITAL LETTERS: In which line do the '        //
     2             'upper-case letters NOT fit exactly between '   //
     3             'the dashed baseline and the dotted capline?',
     4             NUMLIN, NGLINE)
      CALL PEMST (102)

      CALL DILIST ('IDENTIFY UNREPRESENTED CHARACTER CODES: Enter ' //
     1             'list of 6 or fewer character codes for which '  //
     2             'font 1 has no representation (n if none).',
     3             UNR1SZ, UNR1LS)

      CALL DILIST ('IDENTIFY UNREPRESENTED CHARACTER CODES: Enter ' //
     1             'list of 6 or fewer character codes for which '  //
     2             'font 2 has no representation (n if none).',
     3             UNR2SZ, UNR2LS)

      IF (UNR1SZ.EQ.0 .AND. UNR2SZ.EQ.0) THEN
         CALL INMSG ('Cannot test SR14, because there are no '     //
     1               'unrepresentable character codes in fonts 1 ' //
     2               'or 2.')
         GOTO 890
      ENDIF

      CALL SETMSG ('6 7 13', 'There should be a implementation '   //
     1             'dependent way to depict a character code for ' //
     2             'which a font has no graphic representation.')

C  skip font 1 if empty
      IF (UNR1SZ .EQ. 0) GOTO 850
C  check font 1 - if no good, fail and skip out
      CALL UNREP (1, UNR1SZ, UNR1LS, 'A', RESULT)
      IF (RESULT .EQ. 'F') THEN
         CALL FAIL
         GOTO 890
      ENDIF

      IF (UNR2SZ .EQ. 0) THEN
         CALL PASS
         GOTO 890
      ENDIF

C  do_f2:
850   CONTINUE
      CALL UNREP (2, UNR2SZ, UNR2LS, 'A', RESULT)
      CALL IFPF (RESULT .EQ. 'P')

C  end_unrep:
890   CONTINUE

      CALL SETMSG ('5 6 8 15 19', 'If annotation text relative '    //
     1             'primitive requests an unavailable font or '     //
     2             'precision, font=1 and precision=STRING should ' //
     3             'be used.')

C  lunsfn,lunspr = lists of unsupported font, precision pairs
C
C  within lposfn, find at most 2 fonts in non-STROKE precision.
C  for each such add entry to lunsup: font and lowest unavailable
C  precision.
      LUNX = 0
      DO 900 IX = 1,LPOSX
C  skip stroke precisions
         IF (LPOSPR(IX) .GE. PSTRKP) GOTO 900
         LUNX = LUNX+1
         LUNSFN(LUNX) = LPOSFN(IX)
         LUNSPR(LUNX) = LPOSPR(IX) + 1
         IF (LUNX .GE. 2) GOTO 910
900   CONTINUE

910   CONTINUE

C  within lnegfn, find at most 2 fonts in non-STROKE precision.
C  for each such add entry to lunsup: font and lowest unavailable
C    precision.
      DO 920 IX = 1,LNEGX
C  skip stroke precisions
         IF (LNEGPR(IX) .GE. PSTRKP) GOTO 920
         LUNX = LUNX+1
         LUNSFN(LUNX) = LNEGFN(IX)
         LUNSPR(LUNX) = LNEGPR(IX) + 1
         IF (LUNX .GE. 4) GOTO 930
920   CONTINUE

930   CONTINUE

C  (minstr, maxstr) = (minimum, maximum) font identifier in lstrk
      MINSTR = 1
      MAXSTR = 1
      DO 940 IX = 1,LSTRKX
         MINSTR = MIN (MINSTR, LSTRK(IX))
         MAXSTR = MAX (MAXSTR, LSTRK(IX))
940   CONTINUE

C  add to list of unsupported:
C  minstr -   1, STRING
C  minstr - 100, STRING
C  maxstr +   1, STRING
C  maxstr + 100, STRING
      LUNSFN(LUNX+1) = MINSTR-1
      LUNSFN(LUNX+2) = MINSTR-100
      LUNSFN(LUNX+3) = MAXSTR+1
      LUNSFN(LUNX+4) = MAXSTR+100

      LUNSPR(LUNX+1) = PSTRP
      LUNSPR(LUNX+2) = PSTRKP
      LUNSPR(LUNX+3) = PSTRKP
      LUNSPR(LUNX+4) = PSTRP
      LUNX = LUNX+4

C  add (1,STRING) to lunsup and
C  as last entry add (2,STRING) to lunsup
      LUNSFN(LUNX+1) = 1
      LUNSFN(LUNX+2) = 2

      LUNSPR(LUNX+1) = PSTRP
      LUNSPR(LUNX+2) = PSTRP
      LUNX = LUNX+2

C  numlin = size of lunsup
      NUMLIN = LUNX
C  perm = array to randomize order of lunsup
      CALL RNPERM (NUMLIN, PERM)
C  label all lines from 1 to numlin
      YINCR = 1.0 / (NUMLIN + 1)
      YPOS  = 1-YINCR
C  draw labels
      CALL NUMLAB (NUMLIN, .25, YPOS,YINCR)
      CALL PSATAL (PALEFT, PAHALF)

C  allow room within picture square = (x-space - 0.1) / #characters
      CALL PSATCH (MIN (YINCR/2, 0.5/11) * NPCPWC)
      DO 970 IX = 1,NUMLIN
         CALL PSTXFN (LUNSFN(PERM(IX)))
         CALL PSTXPR (LUNSPR(PERM(IX)))
         CALL PATR (.3, YPOS, 0.0,0.0, 'AaMnZz09@#Q')
         YPOS = YPOS-YINCR
970   CONTINUE

C  pass/fail depending on (operator picks text written with (2,STRING))
      CALL DCHPF ('UNSUPPORTED TEXT FONT AND PRECISION PAIRS: ' //
     1            'Which line is different?', NUMLIN, NUMLIN, PERM)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

