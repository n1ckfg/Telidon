      SUBROUTINE PARLIN (RCX,RCY, PARITY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1                   XA,YA, A,B,C, STEP)

C  PARLIN accepts a reference point and 2 vectors and computes a
C  side of the smallest parallelogram containing a specified
C  rectangle.  The side is found in the direction specified by
C  parity.

C  Input parameters
C    RCX,RCY       : reference point within rectangle
C    PARITY        : +1 to search in direction of 1st vector, -1 to
C                    search in opposite direction
C    PRVC1X,PRVC1Y : first vector: used to increment/decrement reference point
C    PRVC2X,PRVC2Y : second vector: indicate direction (slope) of side
C    XA,YA         : 4 corners of rectangle to be contained
C  Output parameters
C    A,B,C         : coefficients of side
C    STEP          : number of steps taken from reference point

      INTEGER  PARITY, IX, STEP

      REAL     RCX,RCY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y, XA(4),YA(4), A,B,C
      REAL     CURX,CURY, CHK

      CURX = RCX
      CURY = RCY
      STEP = 0

100   CONTINUE
      STEP = STEP+1
      CURX = CURX + PARITY*PRVC1X
      CURY = CURY + PARITY*PRVC1Y
C  candidate line coefficients
      CALL PARCOF (CURX,CURY, PRVC2X,PRVC2Y, A,B,C)
      CHK = A*XA(1) + B*YA(1) + C
C  check if all on same side
      DO 200 IX = 2,4
C  if not on same side, go back and take another step
         IF (CHK * (A*XA(IX) + B*YA(IX) + C) .LE. 0) GOTO 100
200   CONTINUE

      END
