      SUBROUTINE GTROOT (IROOT, ROOT)

C  gtroot gets all identifiers for root structures in the CSS and
C  returns them in the array root.  Iroot contains the number
C  of roots found.

      INTEGER    PSIZE
      PARAMETER (PSIZE = 50)

      INTEGER    ROOT(PSIZE), ERRIND, ERPATH (2,PSIZE)
      INTEGER    IXSTR, IDUM, IDSTR, NANPTH, IROOT, TOTSTR

C truncation method
      INTEGER    PHEAD,     PTAIL
      PARAMETER (PHEAD = 0, PTAIL = 1)

C totstr = how many structures?
      CALL PQSID  (0, ERRIND, TOTSTR, IDUM)
      CALL CHKINQ ('pqsid', ERRIND)
C number of roots so far
      IROOT = 0
C go thru all the structures, looking for roots
      DO 200 IXSTR = 1, TOTSTR
C idstr = next structure ID to check for rootedness
         CALL PQSID (IXSTR, ERRIND, IDUM, IDSTR)
         CALL CHKINQ ('pqsid', ERRIND)
C is idstr a root?  Ie, how many ancestor paths (nanpth) are there?
         CALL PQPAN (IDSTR, PTAIL, 1, PSIZE, 0,
     1               ERRIND, NANPTH, IDUM, ERPATH)
         CALL CHKINQ ('pqpan', ERRIND)
C if there are ancestor paths, then this is NOT a root.
         IF (NANPTH .GT. 0) GOTO 200
C check overflow
         IF (IROOT .GE. PSIZE) THEN
            CALL UNMSG ('Number of roots found by GTROOT ' //
     1                  'exceeds maximum.')
         ELSE
            IROOT = IROOT + 1
            ROOT (IROOT) = IDSTR
         ENDIF
200   CONTINUE

      END
