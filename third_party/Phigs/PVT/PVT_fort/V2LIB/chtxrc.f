      SUBROUTINE CHTXRC (NOMW, NOMH, WKTYPE, FONT, STR, TXOR,
     1                   CHXP, CHSP, CHH, DIDTST, RECTOK, CCPOK)

C  CHTXRC computes expected results for various parameter values
C  which affect the size of the text extent rectangle and the
C  concatenation point.  Computation is based on deviation from
C  nominal width and length of entire string.  Therefore, CHTXRC may
C  be used for non-monospaced fonts.

C Input parameters:
C   nomw    : nominal width of string
C   nomh    : nominal height of string
C   wktype  : workstation type
C   font    : text font
C   str     : character string
C   txor    : text path orientation
C   chxp    : character expansion factor
C   chsp    : character spacing
C   chh     : character height
C
C Output parameters:
C   didtst  : was able to perform test
C   rectok  : text rectangle OK
C   ccpok   : concatenation point OK

      INTEGER    WKTYPE, FONT
      INTEGER    TXOR, HRIZNT, VERTIC, NCHAR

      PARAMETER (HRIZNT = 1, VERTIC = 2)

      REAL       NOMW, NOMH, CHXP, CHSP, CHH, MINSP
      REAL       ACHH, ACHXP, EXTXHI, EXTYHI, EXCCX, EXCCY

      CHARACTER  STR*(*)

      LOGICAL    DIDTST, RECTOK, CCPOK

      ACHH  = ABS (CHH)
      ACHXP = ABS (CHXP)

      IF (ACHH .LT.1.0E-37 .OR. ACHH .GT.1.0E+37 .OR.
     1    ACHXP.LT.1.0E-37 .OR. ACHXP.GT.1.0E+37) THEN
         CALL INMSG ('Magnitude of character height or expansion '  //
     1               'factor too high or low to allow computation ' //
     2               'of expected value; skipping test case.')
         DIDTST = .FALSE.
         RETURN
      ELSE
         DIDTST = .TRUE.
      ENDIF

      IF     (TXOR .EQ. HRIZNT) THEN
         MINSP = -0.1 * ACHXP
      ELSEIF (TXOR .EQ. VERTIC) THEN
         MINSP = -0.1
      ELSE
         CALL UNMSG ('Invalid text orientation passed to CHXTRC.')
      ENDIF

      IF (CHSP .LT. MINSP) THEN
         CALL UNMSG ('Cannot compute expected values because '   //
     1               'negative character spacing may overwhelm ' //
     2               'character width.')
      ENDIF

C  nchar = number of characters in str
      NCHAR = LEN (STR)

C calculate expected values for rectangle and concatenation point
      IF     (TXOR .EQ. HRIZNT) THEN
         EXTXHI = ACHH * (NOMW * ACHXP + CHSP * (NCHAR - 1))
         EXTYHI = ACHH * NOMH
         EXCCX  = EXTXHI + ACHH * CHSP
         EXCCY  = 0.0
      ELSEIF (TXOR .EQ. VERTIC) THEN
         EXTYHI = ACHH * (NOMH + CHSP * (NCHAR - 1))
         EXTXHI = ACHH * NOMW * ACHXP
         EXCCX  = 0.0
         EXCCY  = EXTYHI + ACHH * CHSP
      ENDIF

      CALL TXCOMP (WKTYPE, TXOR, FONT, CHXP, CHSP, CHH, STR,
     1             EXTXHI, EXTYHI, EXCCX, EXCCY, RECTOK, CCPOK)

      END
