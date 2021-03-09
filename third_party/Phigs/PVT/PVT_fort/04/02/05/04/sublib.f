C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.02.05.04/patavl                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION PATAVL (SPECWT)

C  PATAVL tests whether the PATTERN interior style is available for
C  a given workstation type.
 
C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER   SPECWT, ISI, THISIS, NAINTS, ERRIND
      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4

C <inquire interior facilities> to determine if pattern is supported:
C  naints = number of available interior styles
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)

C loop thru list of available interior styles till find PPATTR
      DO 100 ISI = 1, NAINTS
         CALL PQIF (SPECWT, ISI, 0, ERRIND, IDUM1, THISIS, IDUM2,
     1              IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS .EQ. PPATTR) THEN
            PATAVL = .TRUE.
            RETURN
         ENDIF
100   CONTINUE
      PATAVL = .FALSE.

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION 04.02.05.04/arreq                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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
