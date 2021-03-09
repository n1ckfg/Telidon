      SUBROUTINE CHMONO (NOMCSZ, NOMSTH, WKTYPE, FONT, STR,
     1                   TXOR, CHXP, CHSP, CHH, RECTOK, CCPOK)

C  CHMONO computes expected results for various parameter values
C  which affect the size of the text extent rectangle and the
C  concatenation point.  Computation is based on deviation from
C  nominal character size in text path dimension and thickness of
C  entire string in other dimension.  Therefore, CHMONO is valid
C  only when every character in the string has the same size.

C Input parameters:
C   nomcsz  : nominal character size, in dimension of
C             text orientation
C   nomsth  : nominal thickness of string, in dimension
C             perpendicular to text orientation
C   wktype  : workstation type
C   font    : text font
C   str     : character string
C   txor    : text path orientation
C   chxp    : character expansion factor
C   chsp    : character spacing
C   chh     : character height
C
C Output parameters:
C   rectok  : text rectangle OK
C   ccpok   : concatenation point OK

      INTEGER    HRIZNT,     VERTIC,     FONT, WKTYPE, TXOR, NCHAR
      PARAMETER (HRIZNT = 1, VERTIC = 2)

      REAL      EXTXHI, EXTYHI, XPCW, EXCCX, EXCCY
      REAL      CHXP, CHSP, CHH, ACHH, ACHXP, CHRINC, NOMCSZ, NOMSTH

      CHARACTER STR*(*)

      LOGICAL   RECTOK, CCPOK

      ACHH  = ABS(CHH)
      ACHXP = ABS(CHXP)

C     nchar = number of characters in str
      NCHAR = LEN (STR)

C calculate expected values for rectangle and concatenation point
      IF (TXOR .EQ. HRIZNT) THEN
         XPCW   =  ACHXP * NOMCSZ
C  chrinc = character increment
         CHRINC =  XPCW + CHSP
         EXTXHI =  ACHH * (XPCW + (NCHAR - 1) * ABS(CHRINC))
         EXTYHI =  ACHH * NOMSTH
         IF (CHRINC .LE. 0.0) THEN
            EXCCX = ACHH * CHRINC
         ELSE
            EXCCX = ACHH * CHRINC * NCHAR
         ENDIF
         EXCCY  = 0.0
      ELSE IF (TXOR .EQ. VERTIC) THEN
C  chrinc = character increment
         CHRINC = NOMCSZ + CHSP
         EXTXHI = ACHH * NOMSTH * ACHXP
         EXTYHI = ACHH * (NOMCSZ + (NCHAR - 1) * ABS(CHRINC))
         EXCCX  = 0.0
         IF (CHRINC .LE. 0.0) THEN
            EXCCY = ACHH * CHRINC
         ELSE
            EXCCY = ACHH * CHRINC * NCHAR
         ENDIF
      ELSE
         CALL UNMSG ('Invalid text orientation passed to CHMONO.')
      ENDIF

      CALL TXCOMP (WKTYPE, TXOR, FONT, CHXP, CHSP, CHH, STR,
     1             EXTXHI, EXTYHI, EXCCX, EXCCY, RECTOK, CCPOK)

      END
