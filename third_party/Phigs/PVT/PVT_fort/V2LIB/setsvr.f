      SUBROUTINE SETSVR (WKID, REQSVR)

C  SETSVR: attempts to set the SVR of the specified workstation
C  to requested state.  There is no error report; the caller must
C  determine success.

C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
C clear control flag
C                conditionally  always
      INTEGER    PCONDI,        PALWAY
      PARAMETER (PCONDI = 0,    PALWAY = 1)
C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)

      INTEGER   WKID, REQSVR, ACTSEV, ACTPCC

      CALL PSDUS (WKID, PWAITD, PUQUM)
C make SVR correct
      CALL PRST  (WKID, PCONDI)

      IF (REQSVR .EQ. PVRDFR) THEN
C  attempt IRG-type picture change
         CALL PICCHG (WKID, '0', '13,14,15,16,17,9,8,1,2,3,4,5,6,7,' //
     1                '10,11,12', ACTSEV, ACTPCC)
      ELSEIF (REQSVR .EQ. PVRSIM) THEN
C  attempt CBS-type picture change
         CALL PICCHG (WKID, '2', '13,14,15,16,17,9,8,1,2,3,4,5,6,7,' //
     1                '10,11,12', ACTSEV, ACTPCC)
      ENDIF

      END
