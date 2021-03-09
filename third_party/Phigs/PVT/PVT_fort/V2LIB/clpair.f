      SUBROUTINE CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, IWX, DELTA, ZVAL)

C  CLPAIR draws a double polymarker in the middle of the requested
C  window, one just in front and one just behind a given z-value, so
C  that exactly one of the pair will be clipped.

C  Input parameters:
C    XWINLO,YWINLO : List of locations of lower-left window corners
C    XSIZE,YSIZE   : Window size
C    IWX           : Index into window list; which window to draw in
C    DELTA         : offset in X and Z dimension from nominal window center
C    ZVAL          : nominal Z location = z-value of expected clipping plane

      INTEGER  IWX
      REAL     XWINLO(*),YWINLO(*),XSIZE,YSIZE, DELTA, ZVAL
      REAL     XA(2), YA(2), ZA(2)

      XA(1) =  XWINLO(IWX) + XSIZE/2 - DELTA
      YA(1) =  YWINLO(IWX) + YSIZE/2
      ZA(1) =  ZVAL - DELTA

      XA(2) =  XWINLO(IWX) + XSIZE/2 + DELTA
      YA(2) =  YWINLO(IWX) + YSIZE/2
      ZA(2) =  ZVAL + DELTA

      CALL PPM3 (2, XA,YA,ZA)

      END
