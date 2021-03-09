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
