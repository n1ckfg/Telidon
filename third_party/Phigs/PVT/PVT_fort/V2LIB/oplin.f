      SUBROUTINE OPLIN (ANS)

C  OPLIN gets a single-line response from the operator.

      CHARACTER ANS*(*)

      READ (*, 800) ANS
800   FORMAT(A)

      END
