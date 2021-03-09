      SUBROUTINE SETSTR (STRID, STRG)

C  Setstr is used to set the contents of a single structure.
C
C  Strid is the identifier of the structure to be set.
C  Strg is a string representing a list of letter-integer pairs,
C  separated by commas, which are interpreted as type-content pairs.
C  A blank string may be used to designate an empty structure.  The
C  only two valid letters are L (for LABEL) and E (for EXECUTE
C  STRUCTURE). E.g. the string "L11,E101,L901" indicates that the
C  structure is to contain 3 elements: LABEL 11, EXECUTE STRUCTURE
C  101 and LABEL 901.  Blanks are ignored.

C  The specified structure is left closed.  If another structure is
C  originally open, it is closed.

C  open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

      INTEGER    STRID, ERRIND, OPSTAT, OPSTID, WLEN, NCOMMA
      INTEGER    IVAL, IERR

      CHARACTER  STRG*(*), WSTR*700

C de-blank string
      CALL DEBLNK (STRG, WSTR, WLEN)
      WLEN = WLEN+1
      WSTR(WLEN:WLEN) = ','

C  check open structure
      CALL PQOPST (ERRIND, OPSTAT, OPSTID)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (OPSTAT .EQ. POPNST) CALL PCLST

C  set up empty structure
      CALL PEMST (STRID)
      CALL POPST (STRID)

100   CONTINUE
      IF (WSTR .EQ. ' ') GOTO 600
      NCOMMA = INDEX(WSTR, ',')
      CALL PRSINT (WSTR(2:NCOMMA-1), IVAL, IERR)
      IF (IERR .NE. 0) THEN
         WRITE (WSTR, '(A,I4,A)') 'SETSTR got error code ', IERR,
     1          ' from PRSINT.'
         CALL UNMSG (WSTR)
      ENDIF

      IF     (WSTR(1:1) .EQ. 'L') THEN
         CALL PLB (IVAL)
      ELSEIF (WSTR(1:1) .EQ. 'E') THEN
         CALL PEXST (IVAL)
      ELSE
         CALL UNMSG ('Illegal code: ' // WSTR(1:1) //
     1               ' passed to SETSTR.')
      ENDIF
      WSTR = WSTR (NCOMMA+1:)
      GOTO 100

600   CONTINUE
      CALL PCLST

      END
