      SUBROUTINE ARRTP3 (NSZ, XI,YI,ZI, XFRMT, XO,YO,ZO)

C  This subroutine transforms a list of 3D points according to the
C  given matrix.

C  Input parameters:
C    NSZ      : number of points
C    XI,YI,ZI : points to be transformed
C    XFRMT    : matrix containing transformation
C  Output parameters:
C    XO,YO,ZO : points after being transformed

      INTEGER     NSZ,IX

      REAL        XI(NSZ),YI(NSZ),ZI(NSZ), XFRMT(4,4),
     1            XO(NSZ),YO(NSZ),ZO(NSZ)

      DO 100 IX = 1,NSZ
         CALL ETP3 (XI(IX),YI(IX),ZI(IX), XFRMT, XO(IX),YO(IX),ZO(IX))
100   CONTINUE

      END
