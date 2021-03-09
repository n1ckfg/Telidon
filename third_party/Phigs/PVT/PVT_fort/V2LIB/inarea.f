      INTEGER FUNCTION INAREA (PX,PY, ILIM, X, Y)

C    Given a 2D point and fill area, determine whether point
C    is within the area, on edge, or outside.

C  Input parameters:
C    PX,PY  : 2D point
C    ILIM   : Number of vertices of fill area
C    X,Y    : vertices of fill area

C   Function returns:
C       1 : inside
C       2 : on an edge
C       3 : outside

C  Idea here is to generate a ray straight up from px,py (positive
C  y-direction), and see how many times it crosses the border.

      INTEGER   ILIM, CURSGN, IA,IB, IX, IPREV, ICROSS, ICT,ICUR

      REAL      PX,PY, X(*), Y(*), XA,YA,XB,YB, A,B,C
      REAL      XCUR,YCUR, XPREV,YPREV, YINT

C  First see if px,py is on any edge:
      DO 100 IA = 1,ILIM
         IB = MOD(IA,ILIM) + 1
         XA = X(IA)
         YA = Y(IA)
         XB = X(IB)
         YB = Y(IB)
C Given two points, calculate line coefficients
         CALL PT2COF (XA,YA, XB,YB, A,B,C)
C if not co-linear, skip
         IF (A*PX + B*PY + C .NE. 0.0) GOTO 100
C if px,py between points, it's on edge:
         IF ((XA-PX)*(XB-PX) .LE. 0 .AND.
     1       (YA-PY)*(YB-PY) .LE. 0)   THEN
            INAREA = 2
            RETURN
         ENDIF
100   CONTINUE

C OK, assume from here on that point is not on an edge;
C get point off y-axis
      DO 200 IX = 1,ILIM
         IF (X(IX) .EQ. PX) GOTO 200
         IF (X(IX) .LT. PX) THEN
            CURSGN = -1
         ELSE
            CURSGN = +1
         ENDIF
         IPREV = IX
         GOTO 210
200   CONTINUE
      INAREA = 3
      RETURN

210   CONTINUE
      ICROSS = 0
      XPREV = X(IPREV)
      YPREV = Y(IPREV)

C start of loop for checking edge segments
      DO 300 ICT = 0,ILIM-1
         ICUR = MOD(IPREV+ICT, ILIM) + 1
         XCUR = X(ICUR)
         YCUR = Y(ICUR)
C if not a definite crossing of y-axis (equal doesn't count),
C save last point and keep going ...
         IF ( (XCUR-PX)*CURSGN .GE. 0) GOTO 290

C crossed y-axis
         CURSGN = -CURSGN

C last two points (cur and prev) determine whether crossing above
C or below px,py:
         CALL PT2COF (XCUR,YCUR, XPREV,YPREV, A,B,C)

C formula for y-intercept of line:a,b,c and line:x=px
         YINT = -(A*PX + C) / B

         IF     (YINT .GT. PY) THEN
            ICROSS = ICROSS+1
         ELSEIF (YINT .EQ. PY) THEN
C aha - on edge after all ..
            INAREA = 2
            RETURN
         ENDIF

290      CONTINUE
         XPREV = XCUR
         YPREV = YCUR
300   CONTINUE
      INAREA = 3 - 2*MOD(ICROSS,2)

      END
