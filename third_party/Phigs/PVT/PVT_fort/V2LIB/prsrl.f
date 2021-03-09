      SUBROUTINE PRSRL (STR, RVAL, IERR)

C  Prsrl parses a real number.  Assumes no leading spaces.
C  The value is returned in RVAL, and IERR gets a non-zero code
C  if something goes wrong.

      CHARACTER   STR*(*), WSTR*18
      INTEGER     POSDEC, POSEXP, ITRIM, SZSTR, IERR
      REAL        RVAL

      SZSTR = ITRIM(STR)
      RVAL  = -666.666
      IF (SZSTR .GT. 15) THEN
         IERR = -3
         RETURN
      ENDIF

      POSDEC = INDEX(STR, '.')
      IF (POSDEC .LE. 0) THEN
C No explicit decimal
         POSEXP = INDEX(STR, 'E')
         IF (POSEXP .LE. 0) THEN
C No explicit exponent
            WSTR = STR(1:SZSTR) // '.0'
         ELSE
            WSTR = STR(1:POSEXP-1) // '.0' // STR(POSEXP:SZSTR)
         ENDIF
         SZSTR = SZSTR + 2
      ELSE
C Explicit decimal
         WSTR = STR
      ENDIF

      READ (WSTR, '(F18.2)', IOSTAT = IERR) RVAL

      END
