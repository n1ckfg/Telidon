      SUBROUTINE EXSVRS (SEVRTY, DEFMOD, MODMD, OLDSVR,
     1                   SVRLST, EXPLBL)

C  EXSVRS returns a string that represents the expected state(s) of visual
C  representation.  It contains c, d, and/or s to indicate that the allowed
C  state(s) are correct, deferred, or simulated, respectively.  It also
C  returns a English label to describe the states.  This function applies
C  only to defer mode WAIT, PBNIL, PBNIG, and ASTI.

C  Input parameters:
C    SEVRTY : severity code for the category of picture change (IRG,IMM,CBS)
C    DEFMOD : deferral mode (WAIT,ASTI,BNIL,BNIG)
C    MODMD  : modification mode (UWOR,UQUM)
C    OLDSVR : original state of visual representation (CORRECT, DEFERRED,
C             SIMULATED)
C  Output parameters:
C    SVRLST : 3-character code, containing some combination of c,d,s for
C             CORRECT, DEFERRED, SIMULATED
C    EXPLBL : English label corresponding to SVRLST

C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)

      INTEGER    SEVRTY, DEFMOD, MODMD, OLDSVR, SVRX, NXTPOS, ITRIM

      LOGICAL    SVRST(PVROK:PVRSIM), NONF

      CHARACTER  SVRLAB(PVROK:PVRSIM)*10, EXPLBL*(*)
      CHARACTER  SVRCOD(PVROK:PVRSIM)*1, SVRLST*3

      DATA SVRCOD / 'c', 'd', 's' /
      DATA SVRLAB / 'CORRECT', 'DEFERRED', 'SIMULATED' /

      IF (DEFMOD.LT.PBNIG .OR. DEFMOD.GT.PWAITD) THEN
         CALL UNMSG ('Illegal deferral mode passed to EXSVRS.')
      ENDIF

      IF (MODMD.EQ.PUWOR .OR. MODMD.EQ.PUQUM) THEN
C        OK
      ELSE
         CALL UNMSG ('Illegal modification mode passed to EXSVRS.')
      ENDIF

      IF (OLDSVR.EQ.PVROK  .OR.
     1    OLDSVR.EQ.PVRDFR .OR.
     2    OLDSVR.EQ.PVRSIM) THEN
C        OK
      ELSE
         CALL UNMSG ('Illegal SVR passed to EXSVRS.')
      ENDIF

C  so much for validity checking - now compute expected state(s)
      SVRST(PVROK)  = .FALSE.
      SVRST(PVRDFR) = .FALSE.
      SVRST(PVRSIM) = .FALSE.

      SVRST(OLDSVR) = .TRUE.
      IF (SEVRTY .EQ. PIMM) THEN
C        OK as is
      ELSEIF (SEVRTY .EQ. PIRG) THEN
         SVRST(PVRDFR) = .TRUE.
         IF (MODMD.EQ.PUQUM .AND. OLDSVR.EQ.PVROK) THEN
            SVRST(PVRSIM) = .TRUE.
         ENDIF
      ELSEIF (SEVRTY .EQ. PCBS) THEN
         IF (MODMD.EQ.PUQUM) THEN
            IF (OLDSVR.EQ.PVROK) THEN
               SVRST(PVRSIM) = .TRUE.
            ENDIF
         ELSE
C           MODMD.EQ.PUWOR
            SVRST(PVRDFR) = .TRUE.
         ENDIF
      ELSE
         CALL UNMSG ('Illegal severity code passed to EXSVRS.')
      ENDIF

      IF (DEFMOD.EQ.PASTI .OR. DEFMOD.EQ.PBNIG .OR. DEFMOD.EQ.PBNIL)
     1    SVRST(PVROK) = .TRUE.

      SVRLST = '   '

      IF (SVRST(PVROK)  ) SVRLST(1:1) = 'c'
      IF (SVRST(PVRDFR) ) SVRLST(2:2) = 'd'
      IF (SVRST(PVRSIM) ) SVRLST(3:3) = 's'

      NONF = .FALSE.
      NXTPOS = 1

      DO 98 SVRX = PVROK,PVRSIM
         IF (SVRST(SVRX)) THEN
            IF (NONF) THEN
               EXPLBL(NXTPOS:) = ' or '
               NXTPOS = NXTPOS + 4
            ELSE
               NONF = .TRUE.
            ENDIF
            EXPLBL(NXTPOS:) = SVRLAB(SVRX)
            NXTPOS = ITRIM(EXPLBL) + 1
         ENDIF
98    CONTINUE

      END
