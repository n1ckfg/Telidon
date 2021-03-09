      SUBROUTINE ARCPTS (NUMPTS, XMID,YMID,RAD, ANG1, ANGINC, XA,YA,ZA)

C  ARCPTS fills in an array with points on an arc in x and y, on
C  an oblique plane (z = (x+y)/2)

C  Input parameters:
C    NUMPTS    : number of points to fill in
C    XMID,YMID : center of circle
C    RAD       : radius of circle
C    ANG1      : first angle
C    ANGINC    : angle increment
C  Output parameters:
C    XA,YA,ZA  : arc points returned

      INTEGER    NUMPTS, IX

      REAL       ANG, ANG1, ANGINC, XMID,YMID,RAD, XA(*),YA(*),ZA(*)

      ANG = ANG1
      DO 100 IX = 1,NUMPTS
         XA(IX) = XMID + RAD*COS(ANG)
         YA(IX) = YMID + RAD*SIN(ANG)
         ZA(IX) = 0.5*XA(IX) + 0.5*YA(IX)
         ANG = ANG + ANGINC
100   CONTINUE

      END
