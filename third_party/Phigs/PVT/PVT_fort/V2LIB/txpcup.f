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
