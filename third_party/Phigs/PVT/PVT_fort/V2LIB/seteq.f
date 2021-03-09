      LOGICAL FUNCTION SETEQ (N, A, B)

C  seteq compares the contents of the first N elements of two
C  arrays, A and B.  If they contain the same elements *in any
C  order*, seteq returns .true., else .false.

      INTEGER    ARRSIZ
      PARAMETER (ARRSIZ = 5000)
      INTEGER    N, I,J, A(*), B(*), WK(ARRSIZ), WKLEFT

      IF (N .GT. ARRSIZ) THEN
         CALL UNMSG ('Size of array passed to SETEQ exceeds size ' //
     1               'of work area.')
      ENDIF

C save contents of B in WK, so as not to clobber B
      DO 50 I = 1,N
         WK(I) = B(I)
50    CONTINUE

      WKLEFT = N
C check all elements of A
      DO 100 I = 1,N
C against remaining elements of WK
      DO 200 J = 1,WKLEFT
         IF (A(I) .EQ. WK(J)) THEN
            WK(J) = WK(WKLEFT)
            WKLEFT = WKLEFT - 1
            GOTO 100
         ENDIF
200   CONTINUE
      SETEQ = .FALSE.
      RETURN
100   CONTINUE
      SETEQ = .TRUE.

      END
