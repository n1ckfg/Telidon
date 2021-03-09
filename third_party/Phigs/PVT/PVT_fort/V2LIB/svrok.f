      LOGICAL FUNCTION SVROK (WKID, EXPVLS)

C  SVROK: true iff current SVR is one of the expected values,
C  encoded by character: c-correct, s-simulated, d-deferred.
C  E.g. expvls = 'cd' means SVR must be either CORRECT or
C  DEFERRED.

C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)

      INTEGER   WKID, ERRIND, ACTSVR
      INTEGER   IDUM1, IDUM2, IDUM3
      CHARACTER EXPVLS*(*), SVRCOD(PVROK:PVRSIM)*1

      DATA SVRCOD /'c', 'd', 's'/

      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, IDUM3, ACTSVR)
      CALL CHKINQ ('pqdus', ERRIND)
      SVROK = INDEX(EXPVLS, SVRCOD(ACTSVR)) .GT. 0

      END
