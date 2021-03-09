      LOGICAL FUNCTION ARREQ (SZX, SZY, IAX, IAY, DX, DY, A, B)

C Input parameters -
C    szx, szy: declared size of 2D INTEGER arrays a and b;
C    iax, iay: initial column and row for array a;
C    dx,  dy:  number of columns and rows used;
C    a,   b:   2D INTEGER arrays.

C  Arreq compares the (DX x DY) contents of the two arrays,
C  A starting at (iax, iay) and B starting at (1,1).
C  If they contain the same elements in exact order, arreq
C  returns .true. else .false.

      INTEGER SZX, SZY, IAX, IAY, DX, DY
      INTEGER A(SZX, SZY), B(SZX, SZY)
C  local variables to control loops
      INTEGER I, J

      DO 200 I = 1, DX
         DO 199 J = 1, DY
            IF ( A(IAX+I-1, IAY+J-1) .NE. B(I,J) )THEN
               ARREQ = .FALSE.
               RETURN
            ENDIF
199      CONTINUE
200   CONTINUE
      ARREQ = .TRUE.

      END
