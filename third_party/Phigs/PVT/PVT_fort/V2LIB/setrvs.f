      SUBROUTINE SETRVS (ST, ARR, NSZ)

C  setrvs initializes the real array ARR, based on the
C  value-representations in ST and also returns the number
C  of values in NSZ.

      CHARACTER ST*(*), STWK*700, TMPMSG*730
      INTEGER   NSZ, LST, NC, IERR
      REAL      ARR(*), RVAL

      NSZ = 0

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
         CALL UNMSG ('Adjacent commas passed to SETRVS.')
      ENDIF
C parse up to comma
      CALL PRSRL (STWK(1:NC-1), RVAL, IERR)
      IF (IERR .NE. 0) THEN
         TMPMSG = 'Invalid string sent to SETRVS: ' // ST
         CALL UNMSG (TMPMSG)
      ENDIF
      NSZ = NSZ+1
      ARR(NSZ) = RVAL
C delete thru comma
      STWK = STWK(NC+1:)
      IF (STWK .NE. ' ') GOTO 400

      END
