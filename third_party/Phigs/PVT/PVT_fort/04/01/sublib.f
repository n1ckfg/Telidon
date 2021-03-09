C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.01/filrec                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE FILREC (XLO,XHI,YLO,YHI, XA,YA)

C  FILREC fills a rectangle based on selected points from an 
C  x-array and y-array

C  Input parameters:
C    XLO,XHI,YLO,YHI : index to points for x-low,high and y-low,high value
C    XA, YA          : array of 2D points from which rectangle
C                      bounds are selected

      INTEGER    XLO,XHI,YLO,YHI
      REAL       XA(*),YA(*), XV(10),YV(10)

      XV(1) = XA(XLO)
      XV(2) = XA(XHI)
      XV(3) = XV(2)
      XV(4) = XV(1)

      YV(1) = YA(YLO)
      YV(3) = YA(YHI)
      YV(2) = YV(1)
      YV(4) = YV(3)
      CALL PFA (4, XV,YV)

      END
