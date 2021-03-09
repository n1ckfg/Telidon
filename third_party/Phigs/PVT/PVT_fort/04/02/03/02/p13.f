C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/13                        *
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

C aspect identifier
      INTEGER    PLN,      PLWSC,    PPLCI,    PMK,      PMKSC
      PARAMETER (PLN  = 0, PLWSC= 1, PPLCI= 2, PMK  = 3, PMKSC= 4)

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
      INTEGER     NUMCH, NUMSHT
      INTEGER     UNR1SZ,UNR1LS(20), UNR2SZ,UNR2LS(20)
      INTEGER     MAXFNT
      INTEGER     IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL        XLEFT, XPOS, XINCR, YPOS, NCSH, RNDRL
      REAL        YTOP, CHSP, CHHT, CHEXP, CHSIZ, OFFACT, XA(5),YA(5)
      REAL        TXRX(2),TXRY(2)
      REAL        RDUM1,RDUM2,RDUM3,RDUM4

      CHARACTER   CHSTR*10, VLBL*2, DISTRG*60, RESULT*1
      CHARACTER   SHRTCH*15, TALLCH*15, MSG*300

      CALL INITGL ('04.02.03.02/13')

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
      CALL SETASF (PBUNDL)
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

      CALL SETMSG ('3 5 6 38 39 40', 'All positive text fonts ' //
     1             'should appear as specified in the ISO register.')

C  call routine to handle display
      CALL CHKFNT (LPOSX,LPOSFN,LPOSPR, MAXFNT, CHSTR, .FALSE.,'U')
      CALL DYNPF (MSG, 'Y')
      CALL PEMST (102)

      CALL SETMSG ('3 5 6 38 39 40 48 49', 'All positive text fonts ' //
     2             'should appear as specified in the ISO register, ' //
     3             'even when less precision is requested than is '   //
     4             'available for the font.')

C  call routine to handle display
      CALL CHKFNT (LPOSX,LPOSFN,LPOSPR, MAXFNT, CHSTR, .TRUE.,'U')
      CALL DYNPF (MSG, 'Y')
      CALL PEMST (102)

C  end_pos:
190   CONTINUE

      IF (LNEGX .LE. 0) THEN
         CALL INMSG ('No implementor defined text fonts are ' //
     1               'supported.')
         GOTO 390
      ENDIF

      MSG =  'IMPLEMENTOR DEFINED TEXT FONTS: Do all displayed, ' //
     1       'labelled text fonts agree with the corresponding '  //
     2       'description in the implementor documentation? '

      CALL SETMSG ('3 5 6 38 39 40', 'All non-positive text fonts ' //
     1             'should appear as specified in the '             //
     2             'implementor''s documentation.')

C  call routine to handle display
      CALL CHKFNT (LNEGX,LNEGFN,LNEGPR, MAXFNT, CHSTR,.FALSE.,'U')
      CALL DYNPF (MSG, 'Y')
      CALL PEMST (102)

      CALL SETMSG ('3 5 6 38 39 40 48 49','All non-positive text ' //
     1             'fonts should appear as specified in the '      //
     2             'implementor''s documentation, even when less ' //
     3             'precision is requested than is available for ' //
     4             'the font.')

C  call routine to handle display
      CALL CHKFNT (LNEGX,LNEGFN,LNEGPR, MAXFNT, CHSTR,.TRUE.,'U')
      CALL DYNPF (MSG, 'Y')
      CALL PEMST (102)

C  end_font_id:
390   CONTINUE

      CALL SETMSG ('3 5 6 38 39 43 44 50 57 58 61 62', 'In each '    //
     2             'text font, all character bodies affected by '    //
     3             'the same character height, character expansion ' //
     4             'factor, and character spacing should have the '  //
     5             'same height.')


C  numcol = number of columns to display = 6
      NUMCOL = 6
C  ngcol  = incorrect column = random number from 1 to numcol
      NGCOL = RNDINT (1,NUMCOL)
C  set up for labels
      CALL PSCHH  (.04)
      CALL PSTXAL (PALEFT,PATOP)
      CALL PSTXP (PRIGHT)
      CALL PSTXI (NUMCOL+1)
      CALL PSTXR (WKID,NUMCOL+1, 1,PSTRKP,1.0,0.0,1)
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
      CHSP = 0.4
      CALL PSTXP  (PDOWN)
      YTOP = 0.85
C  try to paint text and polylines different colors
      CALL PSIASF (PPLCI, PINDIV)
      CALL PSPLCI (2)

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
         CALL PSCHH  (CHHT)
C  display distrg at location ix
         CALL PSTXI (IX)
         CALL PSTXR (WKID, IX, TXFNT, PSTRKP, CHEXP, CHSP, 1)
         CALL PTX (XPOS, YTOP, DISTRG(:NUMCH))
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

      CALL DILIST ('IDENTIFY UNREPRESENTED CHARACTER CODES: Enter ' //
     1             'list of 6 or fewer character codes for which '  //
     2             'font 1 has no representation (n if none).',
     3             UNR1SZ, UNR1LS)

      CALL DILIST ('IDENTIFY UNREPRESENTED CHARACTER CODES: Enter ' //
     1             'list of 6 or fewer character codes for which '  //
     2             'font 2 has no representation (n if none).',
     3             UNR2SZ, UNR2LS)

      IF (UNR1SZ.EQ.0 .AND. UNR2SZ.EQ.0) THEN
         CALL INMSG ('Cannot test SR46, because there are no '     //
     1               'unrepresentable character codes in fonts 1 ' //
     2               'or 2.')
         GOTO 890
      ENDIF

      CALL SETMSG ('3 5 6 38 39 41 46', 'There should be an '  //
     2             'implementation dependent way to depict a ' //
     3             'character code for which a font has no '   //
     4             'graphic representation.')

C  skip font 1 if empty
      IF (UNR1SZ .EQ. 0) GOTO 850

C  check font 1 - if no good, fail and skip out
      CALL UNREP (1, UNR1SZ, UNR1LS, 'U', RESULT)
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
      CALL UNREP (2, UNR2SZ, UNR2LS, 'U', RESULT)
      CALL IFPF (RESULT .EQ. 'P')

C  end_unrep:
890   CONTINUE

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
