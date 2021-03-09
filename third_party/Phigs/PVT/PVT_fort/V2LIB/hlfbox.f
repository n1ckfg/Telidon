      SUBROUTINE HLFBOX (X1ST,Y1ST, XINC,YINC, XY)

C  HLFBOX draws a half-box.

C  Input parameters:
C    X1ST,Y1ST : starting point
C    XINC,YINC : x,y increments
C    XY        : switch to determine which increment is to be applied
C                first.  X creates a box open at the side, Y creates
C                a box open at the top or bottom.

      INTEGER    IXY
      REAL       X1ST,Y1ST, XINC,YINC, XA(5),YA(5)

      CHARACTER  XY*1

      IF (XY .EQ. 'X') THEN
         IXY = 2
      ELSEIF (XY .EQ. 'Y') THEN
         IXY = 4
      ELSE
         CALL UNMSG ('HLFBOX called with invalid XY: ' // XY // '.')
      ENDIF

      XA(1) = X1ST
      YA(1) = Y1ST
      XA(3) = X1ST + XINC
      YA(3) = Y1ST + YINC
      XA(IXY) = XA(3)
      YA(IXY) = YA(1)
      XA(6 - IXY) = XA(1)
      YA(6 - IXY) = YA(3)

      CALL PPL (4,XA,YA)

      END
