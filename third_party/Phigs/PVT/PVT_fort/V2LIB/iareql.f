      LOGICAL FUNCTION IAREQL (SIZEA, ARRA, SIZEB, ARRB)

C  General purpose routine for equality of two variable-length
C  integer lists.
C  ------- Input parameters:
C  sizea   : size of first list
C  arra    : contents of first list
C  sizeb   : size of second list
C  arrb    : contents of second list

C  This will handle multi-dimensional arrays according to the usual
C  Fortran rules for overlaying arrays.

      INTEGER  SIZEA, ARRA(*), SIZEB, ARRB(*)
      LOGICAL  IAREQ

      IF (SIZEA .EQ. SIZEB) THEN
         IAREQL = IAREQ (SIZEA, ARRA, ARRB)
      ELSE
         IAREQL = .FALSE.
      ENDIF

      END
