      LOGICAL FUNCTION TRNSEQ (SZ, ACTMAT,EXPMAT)

C  Test two square matrices to see if they represent the same homogeneous
C  transformation.  Each transformation has an infinite number of
C  representations, because the matrix is scaled by element (sz,sz).

      INTEGER   SZ, I,J
      REAL      ACTMAT(SZ,SZ), EXPMAT(SZ,SZ), ASCALE, BSCALE
      LOGICAL   APPEQ

      ASCALE = ACTMAT(SZ,SZ)
      BSCALE = EXPMAT(SZ,SZ)

      IF (ASCALE*BSCALE .EQ. 0.0) THEN
C at least one is zero
         IF (ASCALE .EQ. BSCALE) THEN
C both are zero - set to 1.0 - both matrices represent transformation to
C points at infinity
            ASCALE = 1.0
            BSCALE = 1.0
         ELSE
C one zero and one not -
            TRNSEQ = .FALSE.
            RETURN
         ENDIF
      ENDIF

      DO 100 I = 1,SZ
      DO 200 J = 1,SZ
         IF (.NOT. APPEQ(ACTMAT(I,J)/ASCALE,
     1                   EXPMAT(I,J)/BSCALE, 1E-7, 1E-4)) THEN
            TRNSEQ = .FALSE.
            RETURN
         ENDIF
200   CONTINUE
100   CONTINUE

      TRNSEQ = .TRUE.

      END
