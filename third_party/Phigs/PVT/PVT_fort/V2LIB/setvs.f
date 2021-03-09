      SUBROUTINE SETVS (ST, ARR, NSZ)

C  SETVS initializes the integer array ARR, based on the
C  value-representations in ST and also returns the number
C  of values in NSZ.  SETVS is meant to be called to parse
C  strings generated directly by other PVT code, and thus
C  aborts on invalid strings.  To handle strings from operator,
C  use INIARI directly.

      CHARACTER ST*(*), TMPMSG*300
      INTEGER   ARR(*), NSZ, IERR

      CALL INIARI (ST, ARR, NSZ, IERR)

      IF (IERR .NE. 0) THEN
         TMPMSG = 'Invalid string sent to SETVS: ' // ST
         CALL UNMSG (TMPMSG)
      ENDIF

      END
