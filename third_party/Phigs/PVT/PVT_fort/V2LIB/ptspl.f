      SUBROUTINE PTSPL (ILIM, X,Y,Z, A,B,C,D)

C  Given a set of supposedly co-planar points, find containing
C  plane.  Idea here is to find 2 points at greatest separation
C  along a principal axis (x, y, or z) and then select 3rd point
C  as the one with greatest distance from the line connecting
C  these 2 points.  This is an attempt to find 3 "good" (widely
C  separated, highly non-colinear) points for computing the plane.
C  If there are 3 non-colinear points, this will find them.

      INTEGER   IA, ILIM, IXMAX,IXMIN,IYMAX,IYMIN,IZMAX,IZMIN
      INTEGER   ILO,IHI, IBEST

      REAL      X(ILIM),Y(ILIM),Z(ILIM), XT(3),YT(3),ZT(3)
      REAL      A,B,C,D, XSEP,YSEP,ZSEP, SEP, AL,BL,CL,XL,YL,ZL
      REAL      DISTMX,DIST, XN,YN,ZN

      IXMAX = 1
      IXMIN = 1
      IYMAX = 1
      IYMIN = 1
      IZMAX = 1
      IZMIN = 1

C  find min,max points for x,y,z
      DO 100 IA = 2,ILIM
         IF (X(IA) .GT. X(IXMAX)) IXMAX = IA
         IF (X(IA) .LT. X(IXMIN)) IXMIN = IA

         IF (Y(IA) .GT. Y(IYMAX)) IYMAX = IA
         IF (Y(IA) .LT. Y(IYMIN)) IYMIN = IA

         IF (Z(IA) .GT. Z(IZMAX)) IZMAX = IA
         IF (Z(IA) .LT. Z(IZMIN)) IZMIN = IA
100   CONTINUE

      XSEP = X(IXMAX) - X(IXMIN)
      YSEP = Y(IYMAX) - Y(IYMIN)
      ZSEP = Z(IZMAX) - Z(IZMIN)

C  take largest of the three separations:
      IF (XSEP .GT. YSEP) THEN
         IHI = IXMAX
         ILO = IXMIN
         SEP = XSEP
      ELSE
         IHI = IYMAX
         ILO = IYMIN
         SEP = YSEP
      ENDIF

      IF (ZSEP .GT. SEP) THEN
         IHI = IZMAX
         ILO = IZMIN
      ENDIF

C  use two widely separated points as axis for plane
      XT(1) = X(ILO)
      YT(1) = Y(ILO)
      ZT(1) = Z(ILO)

      XT(2) = X(IHI)
      YT(2) = Y(IHI)
      ZT(2) = Z(IHI)

C  Parameters for axis
      AL = XT(2) - XT(1)
      BL = YT(2) - YT(1)
      CL = ZT(2) - ZT(1)

      XL = XT(1)
      YL = YT(1)
      ZL = ZT(1)

C  as 3rd point, use one with greatest distance from line
      DISTMX = -1.1
      DO 200 IA = 1,ILIM
         CALL PTLNDS (X(IA),Y(IA),Z(IA), AL,BL,CL, XL,YL,ZL,
     1                XN,YN,ZN, DIST)
         IF (DIST .GT. DISTMX) THEN
            DISTMX = DIST
            IBEST  = IA
         ENDIF
200   CONTINUE

      XT(3) = X(IBEST)
      YT(3) = Y(IBEST)
      ZT(3) = Z(IBEST)

      CALL PT3PL (XT,YT,ZT, A,B,C,D)

      END
