      LOGICAL FUNCTION RLZLW (LWSET, LWEXP)

C  RLZLW sets a requested linewidth scale factor in the polyline bundle
C  table, and checks to see that it is realized approximately equal to the
C  expected value.

C  Input parameters:
C    LWSET : Requested value for linewidth scale factor
C    LWEXP : Expected value for realized linewidth scale factor

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

      INTEGER  IDUM1,IDUM2

      REAL     LWSET,LWEXP,RLW

      LOGICAL  APPEQ

      CALL PSPLR (WKID, 4, 1, LWSET, 1)
      CALL PQPLR (WKID, 4, PREALI, ERRIND, IDUM1, RLW, IDUM2)
      CALL CHKINQ ('pqplr', ERRIND)
      RLZLW = APPEQ (RLW, LWEXP, 0.0, 0.02)

      END
