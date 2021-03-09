      LOGICAL FUNCTION SETIS (ARR, ST)

C  setis compares the contents of the integer array ARR with the set
C  of integers encoded in the character string ST and returns .true.
C  iff the leading elements of ARR contain exactly those values *in
C  any order*.  ST contains integer-like strings separated by
C  commas, e.g. "3, +4, -5".

      INTEGER    ARRSIZ
      PARAMETER (ARRSIZ = 500)
      INTEGER    ARR(*), WK(ARRSIZ), NSZ

      CHARACTER ST*(*)
      LOGICAL   SETEQ

C  store ST values in WK array; NSZ is number of values
      CALL SETVS (ST, WK, NSZ)
      IF (NSZ .GT. ARRSIZ) THEN
         CALL UNMSG ('Number of values in string passed to SETIS ' //
     1               'exceeds size of work area.')
      ENDIF
C  compare the two arrays
      SETIS = SETEQ (NSZ, ARR, WK)

      END
