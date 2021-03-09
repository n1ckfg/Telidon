C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.03.02/tstels                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTELS (STRID, STPOS, DIR, ISZ,ELINC, ESZ,ELEXC, 
     1                   EXPSTA, EXPPOS)

C  TSTELS is used to test element search.  It accepts input parameters to
C  be passed to <element search> and the expected result.  It then issues
C  pass or fail depending on whether the actual values returned from the
C  function match those expected.

C  Input parameters
C    STRID     : structure id to be passed to PELS
C    STPOS     : starting position to be passed to PELS
C    DIR       : search direction to be passed to PELS
C    ISZ,ELINC : inclusion set to be passed to PELS
C    ESZ,ELEXC : exclusion set to be passed to PELS
C    EXPSTA    : expected status (SUCCESS, FAILURE)
C    EXPPOS    : expected found position

C search success
      INTEGER    PFAIL,     PSUCC
      PARAMETER (PFAIL = 0, PSUCC = 1) 

      INTEGER  STRID, STPOS, DIR, ISZ,ELINC(*), ESZ,ELEXC(*)
      INTEGER  EXPSTA, EXPPOS, ERRIND, ACTSTA, ACTPOS

      CALL PELS (STRID, STPOS, DIR, ISZ,ELINC, ESZ,ELEXC,
     1           ERRIND, ACTSTA, ACTPOS)

      IF (EXPSTA.EQ.PFAIL) ACTPOS = EXPPOS
      CALL IFPF (ERRIND .EQ. 0        .AND.
     1           ACTSTA .EQ. EXPSTA   .AND.
     2           ACTPOS .EQ. EXPPOS)

      END
