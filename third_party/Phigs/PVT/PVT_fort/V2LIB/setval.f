      SUBROUTINE SETVAL (ST, ARR)

C  setval initializes the integer array ARR, based on the
C  value-representations in ST.

      CHARACTER ST*(*)
      INTEGER   ARR(*), NSZ

      CALL SETVS (ST, ARR, NSZ)

      END
