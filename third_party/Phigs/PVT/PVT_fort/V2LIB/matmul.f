      SUBROUTINE MATMUL (M,N,P, A,B, C)

C general purpose matrix multiply - multiplies an MxN array (A)
C by a NxP array (B) to yield an MxP array (C).

      INTEGER   I,J,K, M,N,P
      REAL      A(M,N), B(N,P), C(M,P), TOT

      DO 100 I = 1,M
      DO 200 J = 1,P
         TOT = 0.0
         DO 300 K = 1,N
            TOT = TOT + A(I,K) * B(K,J)
300      CONTINUE
         C(I,J) = TOT
200   CONTINUE
100   CONTINUE

      END
