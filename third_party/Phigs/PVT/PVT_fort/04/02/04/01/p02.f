C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/02                        *
C  *    TEST TITLE : Appearance of text fonts 1 and 2      *
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
C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)
C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    GRPSIZ
      PARAMETER (GRPSIZ = 6)

      INTEGER    FONT,PREC, GRPBAS, IX,IY, PERM(50), RNDINT, PICSTR
      INTEGER    SRTANS(20), ITRIM, ICX, ANSSIZ,ANSLIS(20), NUMLFT, TXCI
      INTEGER    FONTA,FONTB, NUMLIN,NGLINE, NUMCH,NUMNAR

      REAL       YPOS,YINCR, TXRX(2), TXRY(2), RDUM1,RDUM2
      REAL       NCWH, CHHT,CHEXP,CHSP, CHSIZ, RNDRL, XPOS, XBASE
      REAL       OFFACT, XA(5), YA(5), Z,U, NPCX,NPCY,NPCPWC
      PARAMETER (Z=0.0, U=1.0)

      CHARACTER  ASCCH(33)*1, ASCNM(33)*30, UPPER*26, LOWER*26
      CHARACTER  DIGIT*10, PROMPT*500, NONMEM*6, MSG*300
      CHARACTER  DISTRG*40, NARCH*40, WIDCH*40

      LOGICAL    FPAVL, DYN, DCHFLV, DISTNG

C  set up array for ASCII characters:
      DATA  ASCCH /
     1  ' ','!','"','#','$','%','&','''','(',')','*','+',',','-','.',
     1  '/',':',';','<','=','>','?','@','[','\',']','^','_','`','{',
     1  '|','}','~'  /

      CALL INITGL ('04.02.04.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL WCNPC (Z,Z, NPCX,NPCY, NPCPWC)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  set up array for ASCII names:
      ASCNM(01) = 'space'
      ASCNM(02) = 'exclamation point'
      ASCNM(03) = 'double quotation marks'
      ASCNM(04) = 'number sign'
      ASCNM(05) = 'dollar sign'
      ASCNM(06) = 'percent sign'
      ASCNM(07) = 'ampersand'
      ASCNM(08) = 'apostrophe'
      ASCNM(09) = 'opening parenthesis'
      ASCNM(10) = 'closing parenthesis'
      ASCNM(11) = 'asterisk'
      ASCNM(12) = 'plus'
      ASCNM(13) = 'comma'
      ASCNM(14) = 'hyphen'
      ASCNM(15) = 'period'
      ASCNM(16) = 'slant'
      ASCNM(17) = 'colon'
      ASCNM(18) = 'semicolon'
      ASCNM(19) = 'less than'
      ASCNM(20) = 'equals'
      ASCNM(21) = 'greater than'
      ASCNM(22) = 'question mark'
      ASCNM(23) = 'commercial at'
      ASCNM(24) = 'opening bracket'
      ASCNM(25) = 'reverse slant'
      ASCNM(26) = 'closing bracket'
      ASCNM(27) = 'circumflex'
      ASCNM(28) = 'underline'
      ASCNM(29) = 'opening single quotation mark'
      ASCNM(30) = 'opening brace'
      ASCNM(31) = 'vertical line'
      ASCNM(32) = 'closing brace'
      ASCNM(33) = 'tilde'

      CALL SETMSG ('5 6 7 14 18 19', 'Fonts 1 and 2 should both '  //
     1             'contain all the ASCII special characters, in ' //
     2             'any precision.')

      YINCR = 1.0 / (GRPSIZ+1)
      CALL PSATAL (PALEFT, PAHALF)
      CALL PSATCH (NPCPWC * 0.5*YINCR)
C  label 1 just before font-precision setting
      CALL PLB (1)
C  label 2,3 just before,after character display
      CALL PLB (2)
      CALL PLB (3)
      CALL PSEP (1)
      CALL PSEPLB (1)

C  loop thru fonts and precisions
      DO 200 FONT = 1,2
      DO 210 PREC = PSTRP, PSTRKP
C        skip unavailable font-precision pairs
         IF (.NOT. FPAVL (WKID, 2, FONT, PREC)) THEN
            WRITE (MSG,'(A,2I3)') 'Unavailable (font,precision) pair: ',
     1                             FONT,PREC
            CALL INMSG (MSG)
            GOTO 190
         ENDIF
         CALL PSTXFN (FONT)
         CALL PSTXPR (PREC)
         CALL PSEPLB (2)
C  perm = array to randomize order of the 33 characters
         CALL RNPERM (33,PERM)
C  loop thru GRPSIZ characters at a time; display next GRPSIZ
C  randomly ordered characters.
         DO 220 GRPBAS = 0,32,GRPSIZ
            YPOS  = 1 - YINCR
            NUMLFT = MIN(GRPSIZ, 33-GRPBAS)
            CALL NUMLAB (NUMLFT, 0.4, YPOS, YINCR)
            DO 230 ICX = 1, NUMLFT
               IY = ICX + GRPBAS
               CALL PATR (0.5, YPOS, Z,Z, ASCCH(PERM(IY)))
               SRTANS(ICX) = PERM(IY)
               YPOS = YPOS - YINCR
230         CONTINUE

C  sort answers
            CALL SRTIAR (NUMLFT, SRTANS)
C  form prompt and get response
            PROMPT = 'ASCII SPECIAL CHARACTERS: Identify, in order, ' //
     1               'the following characters: <' // ASCNM(SRTANS(1))
            DO 240 ICX = 2,NUMLFT
               PROMPT(ITRIM(PROMPT) + 1:) = '>, <' // ASCNM(SRTANS(ICX))
240         CONTINUE
            PROMPT(ITRIM(PROMPT) + 1:) = '>.'
245         CONTINUE
            CALL DILIST (PROMPT, ANSSIZ,ANSLIS)
C  check response
            IF (ANSSIZ.EQ.1 .AND. ANSLIS(1).EQ.0) THEN
               CALL OPFAIL
               GOTO 290
            ENDIF
            IF (ANSSIZ .NE. NUMLFT) GOTO 255
            DO 250 ICX = 1,NUMLFT
               IF (PERM(ANSLIS(ICX)+GRPBAS) .NE. SRTANS(ICX) ) GOTO 255
250         CONTINUE
C           OK so far
C  clear display
            CALL PSEP (1)
            CALL PDELLB (2,3)
            GOTO 220

C  apparent failure
255         CONTINUE
            IF (DYN('Incorrect response; do you wish to re-try?')) THEN
               GOTO 245
            ELSE
               CALL FAIL
               GOTO 290
            ENDIF

220      CONTINUE
C  clear font and precision
         CALL PSEP (1)
         CALL PDELLB (1,2)
C  end_fp_spec:
190      CONTINUE

210   CONTINUE
200   CONTINUE
      CALL PASS

C  end_ascii_special:
290   CONTINUE

C  clear out everything
      CALL PSEP (1)
      CALL PDELLB (1,3)

      CALL SETMSG ('5 6 7 14 18 19', 'Fonts 1 and 2 should both '     //
     1             'contain all the ASCII uppercase letters, in any ' //
     2             'precision.')

      UPPER  = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
      NONMEM = 'bdfhkt'
      IX     = RNDINT(1,6)
      CALL TSTASC ('ASCII UPPERCASE LETTERS: Which character is ' //
     1             'NOT an uppercase letter?',
     2             NONMEM(IX:IX) // UPPER, 'A')

      CALL SETMSG ('5 6 7 14 18 19', 'Fonts 1 and 2 should both '     //
     1             'contain all the ASCII lowercase letters, in any ' //
     2             'precision.')

      LOWER = 'abcdefghijklmnopqrstuvwxyz'
295   CONTINUE
      IX    = RNDINT(1,26)
      IF (IX.EQ.9) GOTO 295
      CALL TSTASC ('ASCII LOWERCASE LETTERS: Which character is ' //
     1             'NOT a lowercase letter?',
     2             UPPER(IX:IX) // LOWER, 'A')

      CALL SETMSG ('5 6 7 14 18 19', 'Fonts 1 and 2 should both '    //
     1             'contain all the ASCII digit characters, in any ' //
     2             'precision.')
      DIGIT  = '0123456789'
      NONMEM = 'CEISZ'
      IX     = RNDINT(1,5)
      CALL TSTASC ('ASCII DIGITS: Which character is NOT a digit?',
     1             NONMEM(IX:IX) // DIGIT, 'A')

C  clear out everything
      CALL PSEP (1)
      CALL PDELLB (1,3)

      CALL SETMSG ('5 6 8 14 18 19', 'Text fonts 1 and 2 should be ' //
     1             'visually distinguishable in any precision.')

      FONTA = RNDINT(1,2)
      FONTB = 3 - FONTA

      YINCR = 0.15
      CALL PSATAL (PALEFT, PAHALF)
      CALL PSATCH (NPCPWC * 0.5 * YINCR)
      CALL PLB (21)
      CALL PLB (22)
      CALL POSEP (-1)
      NUMLIN = 5

      DO 310 PREC = PSTRP, PSTRKP
         CALL PSTXPR (PREC)
C  switch fonts
         FONTA = 3 - FONTA
         FONTB = 3 - FONTB
         CALL PSTXFN (FONTA)
C  perm = array to randomize order of 5 entries
         CALL RNPERM (NUMLIN,PERM)
         CALL NUMLAB (NUMLIN, 0.25, 1-YINCR, YINCR)
         DO 320 IX = 1,NUMLIN
C           display "Test" at location perm(ix)
            ICX = PERM(IX)
            YPOS = 1 - ICX*YINCR
            IF (IX .GE. NUMLIN) CALL PSTXFN (FONTB)
            CALL PATR (0.3, YPOS, Z,Z, 'Test')
320      CONTINUE
         DISTNG = DCHFLV ('DISTINGUISHABILITY OF FONTS 1 AND 2: ' //
     1                    'Which line has a different font?',
     2                    NUMLIN, PERM(NUMLIN))
C  clear out display for this precision
         CALL PSEP (1)
         CALL PDELLB (21,22)

         IF (DISTNG) GOTO 390
C  next precision
310   CONTINUE
      CALL PASS

C  end_distin:
390   CONTINUE

      CALL SETMSG ('5 6 9 10 11 23 27 33 49 50', 'In text font 1, '  //
     1             'all character bodies affected by the same '      //
     2             'annotation text character height, character '    //
     3             'expansion factor, and character spacing should ' //
     4             'have the same width.')
C  Use <inquire text extent> to determine
C    ncwh = nominal character width/height ratio for font 1
      CALL PQTXX  (SPECWT, 1, 1., 0., 1., PRIGHT, PALEFT, PABOTT,
     1             'Testing 123', ERRIND, TXRX,TXRY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      NCWH = ABS(TXRX(2) - TXRX(1)) / 11
C  number of lines to be displayed
      NUMLIN = 6
C  ngline = incorrect line = random number from 1 to numlin
      NGLINE = RNDINT (1,NUMLIN)

C  text font,precision = 1,STROKE, character spacing = 0,
C  text alignment = LEFT,HALF
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PSATAL (PALEFT,PAHALF)
      CALL PSCHSP (0.0)
C  try to paint text and polylines different colors
      CALL PSTXCI (1)
      CALL PSPLCI (2)

C  narrow characters
      NARCH = '.,;:`1lij|"[]{}'
C  wide characters
      WIDCH = 'WHAZMOQRFEGBXNS'
      XBASE = 0.3

C  display labels for all numlin lines to be shown
      YINCR = 1.0 / (NUMLIN+1)
      YPOS  = 1-YINCR
      CALL NUMLAB (NUMLIN, XBASE-0.05, YPOS, YINCR)

C  set up room for separators
      CHSP = 0.2
      CALL PSCHSP (CHSP)

      DO 420 IX = 1,NUMLIN
422      CONTINUE
C  CHHT,CHSIZ expressed in WC
         CHHT   = RNDRL (.2/NUMLIN, .6/NUMLIN)
         CHEXP  = RNDRL (0.3, 3.0)
C  horizontal distance per character
         CHSIZ = CHHT * (NCWH*CHEXP + CHSP)
C  number of characters this string
         NUMCH  = 0.6 / CHSIZ
         IF (NUMCH.LT.4 .OR. NUMCH.GT.25) GOTO 422
C  number of narrow characters
         NUMNAR = NUMCH/2
         DISTRG = NARCH(1:NUMNAR) // WIDCH(1:NUMCH-NUMNAR)
         CALL PSATCH (NPCPWC * CHHT)
         CALL PSCHXP (CHEXP)
         CALL PATR (XBASE, YPOS, Z,Z, DISTRG(1:NUMCH))

C  draw vertical lines between characters
         YA(1) = YPOS - CHHT/2
         YA(2) = YPOS + CHHT/2

C  if this is "incorrect" line, fiddle with separators by plus or minus 20%
         IF (IX .EQ. NGLINE) THEN
            OFFACT = RNDINT(2,3) * 0.4
         ELSE
            OFFACT = 1.0
         ENDIF

C  start in middle of character space between 1st and 2nd characters
         DO 430 XPOS = XBASE + CHSIZ - CHSP*CHHT/2,
     1                 XBASE + (NUMCH-0.5)*CHSIZ, CHSIZ*OFFACT
            XA(1) = XPOS
            XA(2) = XPOS
            CALL PPL (2, XA,YA)
430      CONTINUE
         YPOS = YPOS-YINCR
420   CONTINUE

      CALL DCHPFV ('FONT 1 MONOSPACED: In which line are the ' //
     1     'characters NOT located between the separators?',
     2     NUMLIN, NGLINE)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

