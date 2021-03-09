      LOGICAL FUNCTION RLZMS (MSSET, MSEXP)

C  RLZMS sets a requested marker size scale factor in the polymarker bundle
C  table, and checks to see that it is realized approximately equal to the
C  expected value.

C  Input parameters:
C    MSSET : Requested value for marker size scale factor
C    MSEXP : Expected value for realized marker size scale factor

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

      REAL     MSSET,MSEXP,RMS

      LOGICAL  APPEQ

      CALL PSPMR (WKID, 4, 1, MSSET, 1)
      CALL PQPMR (WKID, 4, PREALI, ERRIND, IDUM1, RMS, IDUM2)
      CALL CHKINQ ('pqpmr', ERRIND)
      RLZMS = APPEQ (RMS, MSEXP, 0.0, 0.02)

      END
