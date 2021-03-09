      SUBROUTINE PARPT (RCX,RCY, PARITY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1                  XA,YA, X,Y, STEP1,STEP2)

C  PARPT accepts a reference point and 2 vectors and computes a
C  corner of the smallest parallelogram containing a specified
C  rectangle. The corner is found in the direction specified by
C  parity.

C  Input parameters
C    RCX,RCY       : reference point within rectangle
C    PARITY        : +1 to search in direction of vectors, -1 to
C                    search in opposite direction
C    PRVC1X,PRVC1Y : first vector to increment reference point
C    PRVC2X,PRVC2Y : second vector to increment reference point
C    XA,YA         : 4 corners of rectangle to be contained
C  Output parameters
C    X,Y           : corner of parallelogram
C    STEP1,STEP2   : number of steps taken from reference point in
C                    direction of 1st,2nd vector

      INTEGER  PARITY, STEP1, STEP2

      REAL     RCX,RCY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y, XA(4),YA(4), X,Y
      REAL     A1,B1,C1, A2,B2,C2

C  find first, second boundary lines
      CALL PARLIN (RCX,RCY, PARITY, PRVC1X,PRVC1Y, PRVC2X,PRVC2Y,
     1             XA,YA, A1,B1,C1, STEP1)
      CALL PARLIN (RCX,RCY, PARITY, PRVC2X,PRVC2Y, PRVC1X,PRVC1Y,
     1             XA,YA, A2,B2,C2, STEP2)
C  intersection of lines is corner
      CALL LINTPT (A1,B1,C1, A2,B2,C2, X,Y)

      END
