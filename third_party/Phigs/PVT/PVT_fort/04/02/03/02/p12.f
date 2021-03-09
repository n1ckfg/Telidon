C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/12                        *
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
      INTEGER    TXDIF

      REAL       YPOS,YINCR, TXRX(2), TXRY(2), RDUM1,RDUM2
      REAL       NCWH, CHHT,CHEXP,CHSP, CHSIZ, RNDRL, XPOS, XBASE
      REAL       OFFACT, XA(5), YA(5)

      CHARACTER  ASCCH(33)*1, ASCNM(33)*30, UPPER*26, LOWER*26
      CHARACTER  DIGIT*10, PROMPT*500, NONMEM*6, MSG*300
      CHARACTER  DISTRG*40, NARCH*40, WIDCH*40

      LOGICAL    FPAVL, DYN, DCHFLV, DISTNG

C  set up array for ASCII characters:
      DATA  ASCCH /
     1  ' ','!','"','#','$','%','&','''','(',')','*','+',',','-','.',
     1  '/',':',';','<','=','>','?','@','[','\',']','^','_','`','{',
     1  '|','}','~'  /

      CALL INITGL ('04.02.03.02/12')

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

      CALL SETMSG ('3 5 6 34 38 39 40 41', 'Fonts 1 and 2 should '   //
     1             'both contain all the ASCII special characters, ' //
     2             'in any precision.')

      YINCR = 1.0 / (GRPSIZ+1)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PSCHH  (0.5 * YINCR)
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
         CALL PSTXR (WKID, 3, FONT, PREC, 1.0, 0.1, 1)
         CALL PSTXI (3)
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
               CALL PTX (0.5, YPOS, ASCCH(PERM(IY)))
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

      CALL SETMSG ('3 5 6 34 38 39 40 41', 'Fonts 1 and 2 should '  //
     1             'both contain all the ASCII uppercase letters, ' //
     2             'in any precision.')

      UPPER  = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
      NONMEM = 'bdfhkt'
      IX     = RNDINT(1,6)

      CALL TSTASC ('ASCII UPPERCASE LETTERS: Which character is NOT ' //
     1             'an uppercase letter?', NONMEM(IX:IX)//UPPER, 'U')

      CALL SETMSG ('3 5 6 34 38 39 40 41', 'Fonts 1 and 2 should '  //
     1             'both contain all the ASCII lowercase letters, ' //
     2             'in any precision.')

      LOWER = 'abcdefghijklmnopqrstuvwxyz'
395   CONTINUE
      IX    = RNDINT(1,26)
      IF (IX.EQ.9) GOTO 395

      CALL TSTASC ('ASCII LOWERCASE LETTERS: Which character is NOT ' //
     1             'a lowercase letter?', UPPER(IX:IX)//LOWER, 'U')

      CALL SETMSG ('3 5 6 34 38 39 40 41', 'Fonts 1 and 2 should ' //
     1             'both contain all the ASCII digit characters, ' //
     2             'in any precision.')

      DIGIT  = '0123456789'
      NONMEM = 'CEISZ'
      IX     = RNDINT(1,5)

      CALL TSTASC ('ASCII DIGITS: Which character is NOT a digit?',
     1             NONMEM(IX:IX) // DIGIT, 'U')

C  clear out everything
      CALL PSEP (1)
      CALL PDELLB (1,3)

      CALL SETMSG ('3 5 6 34 38 39 40 42', 'Text fonts 1 and 2 ' //
     1             'should be visually distinguishable in any '  //
     2             'precision.')

      FONTA = RNDINT(3,4)
      FONTB = 7 - FONTA

      YINCR = 0.15
      CALL PSTXAL (PALEFT, PAHALF)
      CALL PSCHH  (0.5 * YINCR)
      CALL PLB (21)
      CALL PLB (22)
      CALL POSEP (-1)
      NUMLIN = 5

      DO 610 PREC = PSTRP, PSTRKP
         TXDIF = RNDINT(1,NUMLIN)
C  switch fonts
         FONTA = 7 - FONTA
         FONTB = 7 - FONTB
         CALL PSTXR (WKID, 3, 1, PREC, 1.0, 0.1, 1)
         CALL PSTXR (WKID, 4, 2, PREC, 1.0, 0.1, 1)
         YPOS = 1-YINCR
         CALL NUMLAB (NUMLIN, 0.25, YPOS, YINCR)

         DO 620 IX = 1,NUMLIN
            IF (IX .EQ. TXDIF) THEN
               CALL PSTXI (FONTB)
            ELSE
               CALL PSTXI (FONTA)
            ENDIF
            CALL PTX (0.3, YPOS, 'Test')
            YPOS = YPOS - YINCR
620      CONTINUE
         DISTNG = DCHFLV ('DISTINGUISHABILITY OF FONTS 1 AND 2: ' //
     1                    'Which line has a different font?',
     2                    NUMLIN, TXDIF)
C  clear out display for this precision
         CALL PSEP (1)
         CALL PDELLB (21,22)

         IF (DISTNG) GOTO 690
C  next precision
610   CONTINUE
      CALL PASS

C  end_distin:
690   CONTINUE

      CALL SETMSG ('3 5 6 38 39 43 44 45 50 57 58 61 62', 'In text ' //
     2             'font 1, all character bodies affected by the '   //
     3             'same character height, character expansion '     //
     4             'factor, and character spacing should have the '  //
     5             'same width.')

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
C  text alignment = LEFT,BASE
      CALL PSTXAL (PALEFT,PAHALF)
C  try to paint text and polylines different colors
      CALL PSPLI (1)
      CALL PSPLR (WKID,1, 1,1.0,2)

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

      DO 720 IX = 1,NUMLIN
722      CONTINUE
         CHHT   = RNDRL (.2/NUMLIN, .6/NUMLIN)
         CHEXP  = RNDRL (0.3, 3.0)
C  horizontal distance per character
         CHSIZ = CHHT * (NCWH*CHEXP + CHSP)
C  number of characters this string
         NUMCH  = 0.6 / CHSIZ
         IF (NUMCH.LT.4 .OR. NUMCH.GT.25) GOTO 722
C  number of narrow characters
         NUMNAR = NUMCH/2
         DISTRG = NARCH(1:NUMNAR) // WIDCH(1:NUMCH-NUMNAR)
         CALL PSCHH  (CHHT)
         CALL PSTXI (IX)
         CALL PSTXR (WKID, IX, 1, PSTRKP, CHEXP, CHSP, 1)
         CALL PTX (XBASE, YPOS, DISTRG(1:NUMCH))

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
         DO 730 XPOS = XBASE + CHSIZ - CHSP*CHHT/2,
     1                 XBASE + (NUMCH-0.5)*CHSIZ, CHSIZ*OFFACT
            XA(1) = XPOS
            XA(2) = XPOS
            CALL PPL (2, XA,YA)
730      CONTINUE
         YPOS = YPOS-YINCR
720   CONTINUE

      CALL DCHPFV ('FONT 1 MONOSPACED: In which line are the ' //
     1             'characters NOT located between the separators?',
     2             NUMLIN, NGLINE)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
