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
