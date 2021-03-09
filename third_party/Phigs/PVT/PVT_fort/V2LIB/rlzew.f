      LOGICAL FUNCTION RLZEW (EWSET, EWEXP)

C  RLZEW sets a requested edgewidth scale factor in the edge bundle
C  table, and checks to see that it is realized approximately equal to the
C  expected value.

C  Input parameters:
C    EWSET : Requested value for edgewidth scale factor
C    EWEXP : Expected value for realized edgewidth scale factor

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER  IDUM1,IDUM2

      REAL     EWSET,EWEXP,REW

      LOGICAL  APPEQ

      CALL PSEDR (WKID, 4, POFF, 1, EWSET, 1)
      CALL PQEDR (WKID, 4, PREALI, ERRIND, IDUM1, IDUM2, REW, IDUM2)
      CALL CHKINQ ('pqedr', ERRIND)
      RLZEW = APPEQ (REW, EWEXP, 0.0, 0.02)

      END
