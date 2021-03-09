      SUBROUTINE CLDIAG (X1,Y1, X2,Y2, A,B,C,D, XL,YL, XF)

C  CLDIAG accepts the x-y coordinates of 2 MC points, the
C  coefficients of a fill area plane, and a transformation from MC
C  to WC, and draws the resulting (slightly shrunken) 3D line segment.
C
C  Input parameters:
C    X1,Y1, X2,Y2 : MC coordinates of 1st,2nd point
C    A,B,C,D      : fill area plane is: a*x + b*y + c*z + d = 0
C    XL,YL        : border of fill area in MC - an aligned rectanlge
C    XF           : transformation from MC to WC

      REAL   X1,Y1, X2,Y2, XW1,YW1, XW2,YW2, A,B,C,D, XF(4,4), SHRINK
      REAL   XL(4), YL(4), XLO,XHI,YLO,YHI, XA(2),YA(2),ZA(2), ZT

      XLO = XL(1)
      XHI = XL(3)
      YLO = YL(3)
      YHI = YL(1)

      SHRINK = .80
      XW1 = SHRINK*X1 + (1-SHRINK)*X2
      XW2 = SHRINK*X2 + (1-SHRINK)*X1
      YW1 = SHRINK*Y1 + (1-SHRINK)*Y2
      YW2 = SHRINK*Y2 + (1-SHRINK)*Y1

      IF ((XW1.LT.XLO .OR. XW1.GT.XHI .OR.
     1     YW1.LT.YLO .OR. YW1.GT.YHI) .OR.
     2    (XW2.LT.XLO .OR. XW2.GT.XHI .OR.
     3     YW2.LT.YLO .OR. YW2.GT.YHI))  THEN
         RETURN
      ENDIF

      ZT = -(A*XW1 + B*YW1 + D) / C
      CALL ETP3 (XW1,YW1,ZT, XF, XA(1),YA(1),ZA(1))
      ZT = -(A*XW2 + B*YW2 + D) / C
      CALL ETP3 (XW2,YW2,ZT, XF, XA(2),YA(2),ZA(2))

C  since simulated projection is flat, put in z=0.999 plane
      ZA(1) = 0.999
      ZA(2) = 0.999
      CALL PPL3 (2, XA,YA,ZA)

      END
