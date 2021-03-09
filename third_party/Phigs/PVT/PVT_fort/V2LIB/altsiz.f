      SUBROUTINE ALTSIZ (EXPDC, MINSIZ,MAXSIZ, MAXALT, NUMALT,ALT)

C  ALTSIZ finds nearby alternate sizes, to the expected size, and
C  returns them to the caller.  The alternates fulfill all these
C  conditions: 1) each differs from all the others by at least 25%
C  (relative) and by MINSIZ (absolute), and 2) each is no less than
C  MINSIZ, and no greater than MAXSIZ.

C  Input parameters:
C    EXPDC  : Expected size; always the first entry in ALT
C    MINSIZ : Minimum size for an entry and for difference between entries
C    MAXSIZ : Maximum size for an entry
C    MAXALT : Maximum number of alternatives to be returned (including EXPDC)
C  Output parameters:
C    NUMALT : Actual number of alternatives returned
C    ALT    : List of alternative sizes

      INTEGER   MAXALT, NUMALT, IX

      REAL      NXL1,NXL2,NXS1,NXS2
      REAL      EXPDC, MINSIZ,MAXSIZ, ALT(MAXALT)

      NUMALT = 1
      ALT(NUMALT) = EXPDC
      NXL1 = EXPDC
      NXS1 = EXPDC

C  generate alternative sizes - must differ by at least 25% *and* MINSIZ
      DO 100 IX = 1,MAXALT
C  generate larger choices
         NXL2 = 1.25 * NXL1
         IF (NXL2-NXL1 .LT. MINSIZ) THEN
            NXL2 = NXL1 + MINSIZ
         ENDIF
         IF (NXL2 .LE. MAXSIZ) THEN
            NUMALT = NUMALT+1
            ALT(NUMALT) = NXL2
            IF (NUMALT .GE. MAXALT) RETURN
            NXL1 = NXL2
         ENDIF
C  generate smaller choices
         NXS2 = NXS1/1.25
         IF (NXS1-NXS2 .LT. MINSIZ) THEN
            NXS2 = NXS1 - MINSIZ
         ENDIF
         IF (NXS2 .GE. MINSIZ) THEN
            NUMALT = NUMALT+1
            ALT(NUMALT) = NXS2
            IF (NUMALT .GE. MAXALT) RETURN
            NXS1 = NXS2
         ENDIF
100   CONTINUE

      END
