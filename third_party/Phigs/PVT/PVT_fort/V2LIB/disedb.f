      SUBROUTINE DISEDB (SAMP, START, UNIV, SUBSET)

C  DISEDB selects SAMP predefined bundles at random from the
C  edge bundle table which are distinct in all their attributes.
C  If there are not SAMP completely distinct bundles, DISEDB tries
C  to maximize the number of different attributes.
C
C  Input parameters:
C    SAMP        : number of predefined bundles to be picked
C    START       : starting index
C    UNIV        : last element in universe to pick from
C  Output parameters:
C    SUBSET      : array containing the selected distinct bundles

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT, ERRIND
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C  total number of attributes
      INTEGER    TOTATR
      PARAMETER (TOTATR=4)

      INTEGER    SAMP, START, UNIV, SUBSET(SAMP), I,J,JJ,K, OT
      INTEGER    ATRCNT, MAXATR,MAXLOC, JEF, JET,  JECI,
     1           KEF, KET, KECI, RNDINT, OPTATR

      REAL       JEW,KEW

      LOGICAL    ATRNEW(TOTATR)

      IF (UNIV+1-START .LT. SAMP) THEN
         CALL UNMSG ('Abort in DISEDB because size of universe ' //
     1               'is less than requested sample.')
      ENDIF

C  OPTATR is the best possible number of attributes that can be distinct
      OPTATR = TOTATR

C  this loop picks out samp elements
      DO 500 I = 1, SAMP
C  number of new attribute values so far
         MAXATR = -1
C  look at entire universe each time, starting at random location
         J = RNDINT(START, UNIV)
         DO 400 JJ = START, UNIV
            IF (J.GE.UNIV) THEN
C  cycle around to beginning
               J = START
            ELSE
               J = J+1
            ENDIF
            DO 50 OT = 1,TOTATR
               ATRNEW(OT) = .TRUE.
50          CONTINUE
C  get attributes of next candidate
            CALL PQPEDR (SPECWT, J, ERRIND, JEF, JET, JEW, JECI)
            CALL CHKINQ ('pqpedr', ERRIND)

C  check against all those picked so far;
            DO 300 K = 1, I-1
C  if already picked, get another j
               IF (J .EQ. SUBSET(K)) GOTO 400
               CALL PQPEDR (SPECWT, SUBSET(K),ERRIND,KEF,KET,KEW,KECI)
               CALL CHKINQ ('pqpedr', ERRIND)
C  check all attributes
               IF (JEF .EQ. KEF) THEN
                  IF (JEF .EQ. POFF) THEN
C  edge flag off implies all other attributes indistinguishable
                     ATRCNT = 0
                     GOTO 80
                  ELSE
                     ATRNEW(1) = .FALSE.
                  ENDIF
               ENDIF
               IF (JET .EQ. KET) ATRNEW(2) = .FALSE.
               IF (JEW .EQ. KEW) ATRNEW(3) = .FALSE.
               IF (JECI .EQ. KECI) ATRNEW(4) = .FALSE.
300         CONTINUE
C  count # of trues = # of distinct attributes
            ATRCNT = 0
            DO 75 OT = 1,TOTATR
               IF (ATRNEW(OT)) ATRCNT = ATRCNT + 1
75          CONTINUE
80          CONTINUE
C  take the best so far
            IF (ATRCNT .GT. MAXATR) THEN
               MAXATR = ATRCNT
               MAXLOC = J
            ENDIF
C  cannot get better than OPTATR
            IF (MAXATR .GE. OPTATR) GOTO 410
400      CONTINUE

C  put best one on the list
410      CONTINUE
         SUBSET(I) = MAXLOC
C  remember greatest number of distinct attributes
         OPTATR = MAXATR
500   CONTINUE

      END
