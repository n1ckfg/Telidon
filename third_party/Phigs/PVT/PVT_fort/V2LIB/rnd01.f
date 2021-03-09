      REAL FUNCTION RND01 ()

C  RND01 returns a random real number, X, uniformly distributed,
C  such that 0 .LE. X .LT. 1.

C  This is a very low-grade random number generator; it should be
C  portable except for the call to SECNDS.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /RANCTL/ RLSEED
      REAL            RLSEED

      SAVE

      INTEGER  IX

      REAL     SECNDS
      DOUBLE PRECISION  X, FACTOR, ADDEND
      LOGICAL  FIRST

      DATA     FIRST  / .TRUE. /
      DATA     FACTOR / .53736255218 /
      DATA     ADDEND / .63535248281 /

      IF (FIRST) THEN
         FIRST = .FALSE.
         IF (RLSEED .LT. 0.1 .OR. RLSEED .GT. 0.9) THEN

C *********************************************************
C
CUSERMOD  put in a time function to initialize X (true randomization)
C
C *********************************************************

            X = SECNDS(0.0)

C *********************************************************
C
CUSERMOD  End of customization
C
C *********************************************************

         ELSE
C  pseudo-random sequence - seed taken from configuration file
            X = RLSEED
         ENDIF
      ENDIF

      X  = 97.8272 * (X * FACTOR + ADDEND)
      IX = INT(X)
      X  = X - IX
      RND01 = X

      END
