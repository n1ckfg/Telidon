      LOGICAL FUNCTION APPEQ (ACT,EXP, ABSERR, RELERR)

C  General purpose routine for approximate equality of two real-numbers.
C  The 1st parameter is the actual value, the 2nd, the expected value.
C  Tests as true iff:
C     1. absolute error of act wrt exp .le. abserr, OR
C     2. relative error of act wrt exp .le. relerr

      REAL ACT,EXP, ABSERR, RELERR, ABDIF

      IF (ABSERR .LT. 0.0 .OR. RELERR .LT. 0.0) THEN
         CALL UNMSG ('Negative tolerance passed to APPEQ.')
      ENDIF

      ABDIF = ABS(ACT-EXP)

C note that this expression is "safe" even if act or exp is zero.

      APPEQ = (ABDIF .LE. ABSERR)   .OR.
     1        (ABDIF .LE. ABS(RELERR*EXP) )

      END
