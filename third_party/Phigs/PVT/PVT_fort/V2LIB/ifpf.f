      SUBROUTINE IFPF (COND)

C  Ifpf simply provides a short form for the typical coding: if
C  (condition) then pass else fail.

      LOGICAL  COND

      IF (COND) THEN
         CALL PASS
      ELSE
         CALL FAIL
      ENDIF

      END
