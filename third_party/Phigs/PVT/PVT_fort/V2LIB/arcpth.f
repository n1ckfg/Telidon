      SUBROUTINE ARCPTH (ARID, ADSW, STRID, PTHORD, PTHDEP,
     1                   RETCOD, EXPCTD)

C  Arcpth obtains a set of ancestor or descendant paths from the
C  specified archive file and compares the reported set to an
C  expected value to test for set-equality, where each element of
C  the set is a path. The result is returned in retcod, which is
C  zero if the sets are equal.  If the sets are not equal, arcpth
C  writes out an informative message explaining the conditions of
C  failure.

C  --- Input Parameters:
C  arid    : archive file identifier
C  adsw    : A/D switch to indicate ancestor or descendant paths
C  strid   : structure identifier for start of path
C  pthord  : path order
C  pthdep  : path depth
C  expctd  : expected value, encoded as string; ER paths are terminated
C            by slashes, elements separated by commas.  The sequence of
C            integers is interpreted as: structure-id, execute-position,
C            ...
C  --- Output Parameters:
C  retcod  : return code, indicating result of test

C maximum path size, number of paths, and array length
      INTEGER     PSIZE,      MXNPTH,      ARLEN
      PARAMETER  (PSIZE = 25, MXNPTH = 20, ARLEN = PSIZE*2)

      INTEGER     ARID, STRID, PTHORD, PTHDEP, RETCOD
      INTEGER     IPATH, IDUM, IEXP, ERRIND

C these are variables to represent expected paths
      INTEGER     EXPNUM, EXPLEN (MXNPTH), EXPPTH (ARLEN, MXNPTH)

C these are variables to hold paths as reported by inquire
      INTEGER     REPNUM, REPLEN, REPPTH (ARLEN)

      LOGICAL     ANCEST, IAREQ

      CHARACTER   ADSW*1, EXPCTD*(*), MSG*300

C First, parse expctd to set up 2D ragged array of expected paths.
      CALL SET2D (EXPCTD, ARLEN, EXPNUM, EXPLEN, EXPPTH)

C check adsw validity
      IF (ADSW .EQ. 'a' .OR. ADSW .EQ. 'A') THEN
         ANCEST = .TRUE.
      ELSEIF (ADSW .EQ. 'd' .OR. ADSW .EQ. 'D') THEN
         ANCEST = .FALSE.
      ELSE
C invalid adsw
         CALL UNMSG ('Invalid adsw in ARCPTH:' // ADSW)
      ENDIF

C now get actual paths and compare them to expected;
C first get number of paths = repnum
      IF (ANCEST) THEN
         CALL PREPAN (ARID, STRID, PTHORD, PTHDEP, PSIZE, 0,
     1                REPNUM, REPLEN, REPPTH)
      ELSE
         CALL PREPDE (ARID, STRID, PTHORD, PTHDEP, PSIZE, 0,
     1                REPNUM, REPLEN, REPPTH)
      ENDIF

C if number of paths unequal, whole set is unequal
      IF (REPNUM .NE. EXPNUM) THEN
         RETCOD = 2
         WRITE (MSG, '(A,I4,A,I4,A,A,A, 3I5)')
     1          'Number of reported paths (', REPNUM,
     2          ') not equal to expected number (', EXPNUM, '), ',
     3          'resulting from retrieve with structure-id, path ',
     4          'order, path depth = ', STRID, PTHORD, PTHDEP
         CALL INMSG (MSG)
         RETURN
      ENDIF

C go thru set of actual paths, one at a time and compare.
      DO 100 IPATH = 1,REPNUM
C get next path
         IF (ANCEST) THEN
            CALL PREPAN (ARID, STRID, PTHORD, PTHDEP, PSIZE, IPATH,
     1                   IDUM, REPLEN, REPPTH)
         ELSE
            CALL PREPDE (ARID, STRID, PTHORD, PTHDEP, PSIZE, IPATH,
     1                   IDUM, REPLEN, REPPTH)
         ENDIF

C look for a match among expected
         DO 200 IEXP = 1, EXPNUM
C seek matching length;
C multiply by 2, because paths have 2 integers per element -
C structure id and element ref
            IF (REPLEN*2 .NE. EXPLEN(IEXP)) GOTO 200
C check contents
            IF (IAREQ (REPLEN*2, REPPTH, EXPPTH(1, IEXP))) THEN
C got a match - mark out length to prevent re-matching same column
               EXPLEN(IEXP) = -1
               GOTO 100
            ENDIF
200      CONTINUE
C no match found - fail
         RETCOD = 3
         WRITE (MSG, '(A,A,A, 3I5)')
     1          'Reported path unmatched within set of expected paths ',
     2          'resulting from retrieve with structure-id, path ',
     3          'order, path depth = ', STRID, PTHORD, PTHDEP
         CALL INMSG (MSG)
         RETURN
100   CONTINUE

C every reported path found a match - success
      RETCOD = 0

      END
