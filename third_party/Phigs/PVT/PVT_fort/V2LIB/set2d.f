      SUBROUTINE SET2D (VALS, MAXCOL, NOCOLS, COLLEN, ARR)

C  Set2d is used to initialize a ragged 2D array of integers, based
C  on an input string.
C
C  --- Input Parameter:
C  vals      : Input string, with integer values.  Values separated by
C              commas, array columns terminated by slashes.
C  maxcol    : Maximum column size = size of first dimension of 2D array.
C  --- Output parameters:
C  nocols    : Number of columns initialized
C  collen    : 1D array of lengths of each column
C  arr       : 2D array of integers

C  Syntax of vals:
C  vals         = column*
C  column       = col-values "/"
C  col-values   = " " | integer-list
C  integer-list = integer | integer "," integer-list

      CHARACTER  VALS*(*), WK*2000

      INTEGER    NOCOLS, MAXCOL, COLLEN(*), ARR(MAXCOL,*)
      INTEGER    ITRIM, SLPOS, LAST

      IF (LEN(VALS) .GT. 1998) THEN
         CALL UNMSG ('String passed to SET2D exceeds length of ' //
     1               'work area.')
      ENDIF

C no columns so far
      NOCOLS = 0

C blank means no columns at all
      IF (VALS .EQ. ' ') RETURN
C check for terminating slash
      LAST = ITRIM(VALS)
      IF (VALS(LAST:LAST) .NE. '/') THEN
         CALL UNMSG
     1        ('String sent to set2d does not terminate with slash.')
      ENDIF
      WK = ' ' // VALS

C begin a new column
100   CONTINUE
      SLPOS = INDEX (WK, '/')

C put next column and its length in arrays
      NOCOLS = NOCOLS+1
      CALL SETVS (WK(1:SLPOS-1), ARR(1, NOCOLS), COLLEN(NOCOLS))
      IF (COLLEN(NOCOLS) .GT. MAXCOL) THEN
          WK = 'Column passed to set2d exceeds maximum length: ' //
     1         WK(1:SLPOS-1)
          CALL UNMSG (WK)
      ENDIF
C delete encoded column - set up for next; ensure one blank
      WK = ' ' // WK (SLPOS+1: )
C any more columns ?
      IF (WK .NE. ' ') GOTO 100

      END
