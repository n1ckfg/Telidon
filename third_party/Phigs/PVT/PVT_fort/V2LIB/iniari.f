      SUBROUTINE INIARI (ST, ARR, NSZ, IERR)

C  INIARI initializes the integer array ARR, based on the
C  value-representations in ST and also returns the number
C  of values in NSZ.  INIARI does not abort when faced with
C  an invalid string, just returns a non-zero error code in IERR.

      CHARACTER ST*(*), STWK*700
      INTEGER   ARR(*), NSZ, LST, NC, IVAL, IERR

      NSZ = 0
      IERR = 0

C blank means zero entries
      IF (ST .EQ. ' ') RETURN

C get rid of leading, internal blanks
      CALL DEBLNK (ST, STWK, LST)

300   CONTINUE
C add trailing comma
      LST = LST+1
      STWK(LST:LST) = ','

C now sitting at alleged number
400   CONTINUE
C find next comma
      NC = INDEX(STWK, ',')
      IF (NC .LE. 1) THEN
         IERR = 1
         RETURN
      ENDIF
C parse up to comma
      CALL PRSINT (STWK(1:NC-1), IVAL, IERR)
      IF (IERR .NE. 0) THEN
         IERR = 100 + IERR
         RETURN
      ENDIF
C add new entry to array
      NSZ = NSZ+1
      ARR(NSZ) = IVAL
C delete thru comma
      STWK = STWK(NC+1:)
      IF (STWK .NE. ' ') GOTO 400

      END
