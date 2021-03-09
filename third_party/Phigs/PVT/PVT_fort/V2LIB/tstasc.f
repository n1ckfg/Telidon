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
