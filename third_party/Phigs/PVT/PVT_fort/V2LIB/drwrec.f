      SUBROUTINE DRWREC (XL,XH, YL,YH)

C  DRWREC draws a rectangle as specified by x-low,x-high,y-low,y-high

      REAL     XL,XH, YL,YH, XA(5),YA(5)

      XA(1) = XL
      XA(2) = XL
      XA(3) = XH
      XA(4) = XH
      XA(5) = XL

      YA(1) = YL
      YA(2) = YH
      YA(3) = YH
      YA(4) = YL
      YA(5) = YL
      CALL PPL (5,XA,YA)

      END
