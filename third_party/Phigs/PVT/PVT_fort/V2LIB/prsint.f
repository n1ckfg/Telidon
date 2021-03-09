      SUBROUTINE PRSINT (STR, IVAL, IERR)

C  Prsint parses a possibly signed integer.  Assumes no leading spaces.
C  The value is returned in IVAL, and IERR gets a non-zero code if
C  something goes wrong.

      CHARACTER  STR*(*)
      INTEGER    IVAL, IERR, ISIGN, LST

      ISIGN = INDEX ('+-', STR(1:1))
      LST = LEN(STR)
      IF (ISIGN .EQ. 0) THEN
C unsigned
         CALL PRSUIN (STR, IVAL, IERR)
      ELSE
C signed
         IF (LST .LE. 1) THEN
C no digits
            IERR = 50
         ELSE
            CALL PRSUIN (STR(2:), IVAL, IERR)
            IF (ISIGN .EQ. 2) IVAL = -IVAL
         ENDIF
      ENDIF

      END
