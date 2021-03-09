      SUBROUTINE PRSUIN (STR, IVAL, IERR)

C  Prsuin parses an unsigned integer.  Assumes no leading spaces.
C  The value is returned in IVAL, and IERR gets a non-zero code if
C  something goes wrong.

      CHARACTER  STR*(*)
      INTEGER    IVAL, IERR, LST, ITOT, I, IDIG, ITRIM

      LST = ITRIM(STR)
      IF (LST .LE. 0) THEN
         IERR = 2
         RETURN
      ENDIF
      ITOT = 0
      DO 100 I = 1,LST
         IDIG = INDEX('0123456789', STR(I:I)) - 1
         IF (IDIG .GE. 0 .AND. IDIG .LE. 9) THEN
            ITOT = 10*ITOT + IDIG
         ELSE
            IERR = 1
            RETURN
         ENDIF
100   CONTINUE
      IERR = 0
      IVAL = ITOT

      END
