C  FILE: TRANS_SUBLIB.FOR

C  Overview of transformation subroutine library:

C  SUBROUTINE etr3 (dx,dy,dz, xfrmt)  : 3D translate
C  SUBROUTINE etr (dx,dy, xfrmt)      : 2D translate
C  SUBROUTINE esc3 (fx,fy,fz, xfrmt)  : 3D scale
C  SUBROUTINE esc (fx,fy, xfrmt)      : 2D scale
C  SUBROUTINE erox (rotang, xfrmt)    : 3D rotate X axis
C  SUBROUTINE eroy (rotang, xfrmt)    : 3D rotate Y axis
C  SUBROUTINE eroz (rotang, xfrmt)    : 3D rotate Z axis
C  SUBROUTINE ero (rotang, xfrmt)     : 2D rotate Z axis
C  SUBROUTINE ecom3 (xfrmta, xfrmtb, xfrmto)   : 3D composition
C  SUBROUTINE ecom (xfrmta, xfrmtb, xfrmto)    : 2D composition
C  SUBROUTINE etp3 (xi,yi,zi, xfrmt, xo,yo,zo) : 3D transform point
C  SUBROUTINE etp (xi,yi, xfrmt, xo,yo)        : 2D transform point
C  SUBROUTINE ebltm3 (x0,y0,z0, dx,dy,dz, phix,phiy,phiz, fx,fy,fz, xfrmt)
C                : 3D build transform
C  SUBROUTINE ebltm (x0,y0, dx,dy, phi, fx,fy, xfrmt)
C                : 2D build transform
C  SUBROUTINE ecotm3 (xfrmti, x0,y0,z0, dx,dy,dz, phix,phiy,phiz, fx,fy,fz, xfrmto)
C                : 3D compose transform
C  SUBROUTINE ecotm (xfrmti, x0,y0, dx,dy, phi, fx,fy, xfrmto)
C                : 2D compose transform
C  SUBROUTINE eevom3 (vwrx,vwry,vwrz, vpnx,vpny,vpnz, vupx,vupy,vupz, vwormt)
C                : 3D view orientation
C  SUBROUTINE eevom (vwrx,vwry, vupx,vupy, vwormt)
C                : 2D view orientation
C  SUBROUTINE eevmm (umin, umax, vmin, vmax, xmin, xmax, ymin, ymax)
C                : 2D view mapping
C *** *** *** *** ***   End of PHIGS-mimicking routines;  *** *** *** *** ***

C *** *** *** *** ***   General-purpose PVT math routines   *** *** *** *** ***
C  SUBROUTINE matmul (m,n,p, a,b, c)           : matrix multiply
C  SUBROUTINE idmat (sz, mat)                  : generate identity matrix
C  SUBROUTINE arrtp3 (nsz, xi,yi,zi, xfrmt, xo,yo,zo)
C                                              : transforms a list of 3D points
C  SUBROUTINE red43 (m4, m3)                   : reduce 4x4 matrix to 3x3
C  SUBROUTINE exp34 (m3, m4)                   : expand 3x3 matrix to 4x4
C  LOGICAL FUNCTION trnseq (sz, actmat,expmat) : test transformations equal
C  REAL FUNCTION satan2 (y,x)                  : safe arctan
C  REAL FUNCTION vecl2 (vx,vy,vz)              : squared length of vector
C  REAL FUNCTION vecl (vx,vy,vz)               : length of vector
C  SUBROUTINE vec1 (vx,vy,vz, vx1,vy1,vz1)     : scale vector to unit length
C  REAL FUNCTION dotprd (vx1,vy1,vz1, vx2,vy2,vz2)
C                                              : dot product of vectors
C  REAL FUNCTION vecang (vx1,vy1,vz1, vx2,vy2,vz2)
C                                              : angle between vectors
C  SUBROUTINE crossp (vx1,vy1,vz1, vx2,vy2,vz2, vx3,vy3,vz3)
C                                              : cross product of vectors
C  SUBROUTINE prpv1 (vx1,vy1,vz1, vx2,vy2,vz2) : get perpendicular 3D vector
C  SUBROUTINE pervec (vx1,vy1,vz1, vx2,vy2,vz2, vx3,vy3,vz3)
C                                              : perpendicular projection
C  SUBROUTINE ptplds (px,py,pz, a,b,c,d, xn,yn,zn, dist)
C                                              : point-plane projection,distance
C  SUBROUTINE lnplpt (lx,ly,lz, al,bl,cl, ap,bp,cp,dp, xi,yi,zi)
C                                              : point of intersection of
C                                              : line and plane
C  SUBROUTINE pt3pl (xarr,yarr,zarr, a,b,c,d)  : plane containing 3 points
C  SUBROUTINE ptspl (ilim, x,y,z, a,b,c,d)     : plane containing n points
C  SUBROUTINE pl2pl (ar,br,cr,dr, ax,bx,cx,dx, ap,bp,cp,dp)
C                                              : plane perpendicular
C                                              : to reference plane
C  SUBROUTINE pl2ln (a1,b1,c1,d1, a2,b2,c2,d2, a,b,c, px,py,pz)
C                                              : line as intersection of
C                                              : two planes
C  INTEGER function abest3 (aa,ba,ca)          : greatest magnitude
C  SUBROUTINE ptlnds (px,py,pz, a,b,c,lx,ly,lz, xn,yn,zn, dist)
C                                              : distance from point to line
C  SUBROUTINE lintpt (a,b,c, d,e,f, x,y)       : intersection of 2 lines
C  SUBROUTINE pt2cof (x1,y1, x2,y2, a,b,c)     : calculate 2D line coefficients
C  SUBROUTINE parcof (x0,y0, xcoeff,ycoeff, a,b,c)
C                                              : line coefficients
C  REAL FUNCTION ptregd (px,py,pz, nsz, xa,ya,za)
C                                              : minimum distance from 3D
C                                              : point to planar 3D region.
C  INTEGER FUNCTION ceilng (x)                 : integer ceiling for x
C  INTEGER FUNCTION mod1 (x,m)                 : x between 1 and m
C  SUBROUTINE invol (px,py,pz, ilim, arx,ary,arz, side, pldist)
C                                              : is point inside volume
C  INTEGER FUNCTION inarea (px,py, ilim, x, y) : is point inside area
C  SUBROUTINE issdis (sisrpx,sisrpy,sisrpz, sdist, xfrmt, mclipi, expath)
C             : ISS for structure 101, varying search distance
C  SUBROUTINE issab (srpx,srpy,srpz, sdist, stpath, mclipi, sceil, expath)
C             : ISS with varying search distance
C  SUBROUTINE ispths (srpx,srpy,srpz, sdist, sceil, mclipi, stpth, expths)
C             : ISS for multiple expected found paths

C  This set of subroutines is a simple implementation of some of
C  the matrix utility functions of PHIGS.  They are not meant
C  to be terribly robust or numerically stable in all cases, just
C  adequate to generate expected values which may then be compared
C  with the actual values returned by the implementation under test.
C  They have the same names as the corresponding PHIGS function
C  except that the leading "P" is replaced by "E" (for Expected).
C  Also, there is no parameter for error indicator.

C  Note that the Fortran binding to PHIGS specifies that the
C  first index addresses the row and the second index the column
C  of a transformation matrix.

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/etr3                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ETR3 (DX,DY,DZ, XFRMT)

      REAL DX,DY,DZ, XFRMT (4,4)

      CALL IDMAT (4, XFRMT)
      XFRMT (1,4) = DX
      XFRMT (2,4) = DY
      XFRMT (3,4) = DZ

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/etr                                  *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ETR (DX,DY, XFRMT)

      REAL DX,DY, XFRMT (3,3)

      CALL IDMAT (3, XFRMT)
      XFRMT (1,3) = DX
      XFRMT (2,3) = DY

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/esc3                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ESC3 (FX,FY,FZ, XFRMT)

      REAL FX,FY,FZ, XFRMT (4,4)

      CALL IDMAT (4, XFRMT)
      XFRMT (1,1) = FX
      XFRMT (2,2) = FY
      XFRMT (3,3) = FZ

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/esc                                  *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ESC (FX,FY, XFRMT)

      REAL FX,FY, XFRMT (3,3)

      CALL IDMAT (3, XFRMT)
      XFRMT (1,1) = FX
      XFRMT (2,2) = FY

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/erox                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EROX (ROTANG, XFRMT)

      REAL XFRMT (4,4), SN, CS, ROTANG

      CALL IDMAT (4, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (2,2) =  CS
      XFRMT (3,3) =  CS
      XFRMT (2,3) = -SN
      XFRMT (3,2) =  SN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/eroy                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EROY (ROTANG, XFRMT)

      REAL XFRMT (4,4), SN, CS, ROTANG

      CALL IDMAT (4, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (1,1) =  CS
      XFRMT (3,3) =  CS
      XFRMT (1,3) =  SN
      XFRMT (3,1) = -SN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/eroz                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EROZ (ROTANG, XFRMT)

      REAL XFRMT (4,4), SN, CS, ROTANG

      CALL IDMAT (4, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (1,1) =  CS
      XFRMT (2,2) =  CS
      XFRMT (1,2) = -SN
      XFRMT (2,1) =  SN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ero                                  *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ERO (ROTANG, XFRMT)

      REAL XFRMT (3,3), SN, CS, ROTANG

      CALL IDMAT (3, XFRMT)
      SN = SIN(ROTANG)
      CS = COS(ROTANG)
      XFRMT (1,1) =  CS
      XFRMT (2,2) =  CS
      XFRMT (1,2) = -SN
      XFRMT (2,1) =  SN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ecom3                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ECOM3 (XFRMTA, XFRMTB, XFRMTO)

      REAL XFRMTA(4,4), XFRMTB(4,4), XFRMTO(4,4)

      CALL MATMUL (4,4,4, XFRMTA, XFRMTB, XFRMTO)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ecom                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ECOM (XFRMTA, XFRMTB, XFRMTO)

      REAL XFRMTA(3,3), XFRMTB(3,3), XFRMTO(3,3)

      CALL MATMUL (3,3,3, XFRMTA, XFRMTB, XFRMTO)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/etp3                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ETP3 (XI,YI,ZI, XFRMT, XO,YO,ZO)

      REAL XFRMT (4,4), PTI(4,1), PTO(4,1)
      REAL XI,YI,ZI, XO,YO,ZO, W

      PTI(1,1) = XI
      PTI(2,1) = YI
      PTI(3,1) = ZI
      PTI(4,1) = 1.0

      CALL MATMUL (4,4,1, XFRMT, PTI, PTO)
      W  = PTO(4,1)
      XO = PTO(1,1) / W
      YO = PTO(2,1) / W
      ZO = PTO(3,1) / W

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/etp                                  *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ETP (XI,YI, XFRMT, XO,YO)

      REAL XFRMT (3,3), PTI(3,1), PTO(3,1)
      REAL XI,YI, XO,YO, W

      PTI(1,1) = XI
      PTI(2,1) = YI
      PTI(3,1) = 1.0

      CALL MATMUL (3,3,1, XFRMT, PTI, PTO)
      W  = PTO(3,1)
      XO = PTO(1,1) / W
      YO = PTO(2,1) / W

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ebltm3                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EBLTM3 (X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1                   XFRMT)

      REAL   X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1       XFRMT (4,4), WKA(4,4), WKB(4,4), WKC(4,4)

C shift so that fixed point is at origin
      CALL ETR3  (-X0,-Y0,-Z0, WKA)
C scale
      CALL ESC3  ( FX, FY, FZ, WKB)
      CALL ECOM3 (WKB, WKA, WKC)
C rotations
      CALL EROX  (PHIX, WKA)
      CALL ECOM3 (WKA, WKC, WKB)
      CALL EROY  (PHIY, WKA)
      CALL ECOM3 (WKA, WKB, WKC)
      CALL EROZ  (PHIZ, WKA)
      CALL ECOM3 (WKA, WKC, WKB)
C do specified shift and undo fixed-point shift
      CALL ETR3  (X0+DX, Y0+DY, Z0+DZ, WKA)
      CALL ECOM3 (WKA, WKB, XFRMT)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ebltm                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EBLTM (X0,Y0, DX,DY, PHI, FX,FY, XFRMT)

      REAL   X0,Y0, DX,DY, PHI, FX,FY,
     1       XFRMT (3,3), WKA(3,3), WKB(3,3), WKC(3,3)

C shift so that fixed point is at origin
      CALL ETR  (-X0,-Y0, WKA)
C scale
      CALL ESC  ( FX, FY, WKB)
      CALL ECOM (WKB, WKA, WKC)
C rotation
      CALL ERO  (PHI, WKA)
      CALL ECOM (WKA, WKC, WKB)
C do specified shift and undo fixed-point shift
      CALL ETR  (X0+DX, Y0+DY, WKA)
      CALL ECOM (WKA, WKB, XFRMT)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ecotm3                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ECOTM3 (XFRMTI, X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ,
     1                   FX,FY,FZ, XFRMTO)

      REAL   X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1       XFRMTI (4,4), XFRMTO (4,4), WKA(4,4)

      CALL EBLTM3 (X0,Y0,Z0, DX,DY,DZ, PHIX,PHIY,PHIZ, FX,FY,FZ,
     1             WKA)
      CALL ECOM3 (XFRMTI, WKA, XFRMTO)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ecotm                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ECOTM (XFRMTI, X0,Y0, DX,DY, PHI,
     1                  FX,FY, XFRMTO)

      REAL   X0,Y0, DX,DY, PHI, FX,FY,
     1       XFRMTI (3,3), XFRMTO (3,3), WKA(3,3)

      CALL EBLTM (X0,Y0, DX,DY, PHI, FX,FY, WKA)
      CALL ECOM  (XFRMTI, WKA, XFRMTO)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/eevom3                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EEVOM3 (VWRX,VWRY,VWRZ, VPNX,VPNY,VPNZ,
     1                   VUPX,VUPY,VUPZ, VWORMT)

      REAL     VWRX,VWRY,VWRZ, VPNX,VPNY,VPNZ, VUPX,VUPY,VUPZ
      REAL     TVX,TVY,TVZ, SATAN2
      REAL     VWORMT(4,4), TRMT(4,4), WK(4,4)
      REAL     XROT(4,4), YROT(4,4), ZROT(4,4), XYROT(4,4)

C calculate Y-rotation (longitude shift), ie swing VPN around
C into the VN plane of the UVN system.
      CALL EROY (-SATAN2(VPNX, VPNZ), YROT)

C transformed VPN:
      CALL ETP3 (VPNX,VPNY,VPNZ, YROT, TVX,TVY,TVZ)

C calculate X-rotation (latitude shift), ie swing VPN down
C to coincide with N axis
      CALL EROX (-SATAN2(-TVY,TVZ), XROT)

C calculate composite 1st Y, then X rotation:
      CALL ECOM3 (XROT, YROT, XYROT)

C calculate transformed view-up vector
      CALL ETP3 (VUPX,VUPY,VUPZ, XYROT, TVX,TVY,TVZ)

C calculate Z-rotation so as to swing view-up vector into
C vn plane, pointing up.
      CALL EROZ (-SATAN2(-TVX, TVY), ZROT)

C calculate shift for view ref pt
      CALL ETR3 ( -VWRX,-VWRY,-VWRZ, TRMT)

C compose into one matrix
      CALL ECOM3 (XYROT, TRMT, WK)
      CALL ECOM3 (ZROT, WK, VWORMT)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/eevom                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EEVOM (VWRX,VWRY, VUPX,VUPY, VWORMT)

      REAL   VWRX,VWRY, VUPX,VUPY, VWORMT(3,3)
      REAL   WK(4,4), ZZ,U

      ZZ = 0.0
      U  = 1.0
      CALL EEVOM3 (VWRX,VWRY,ZZ, ZZ,ZZ,U, VUPX,VUPY,ZZ, WK)
      CALL RED43 (WK, VWORMT)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/eevmm                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EEVMM (VWWNLM, PJVPLM, VWMPMT)

C note: no 3D version (eevmm3) because standard does not specify
C a unique transformation.

      REAL   VWMPMT(3,3), VWWNLM(4), PJVPLM(4)

      CALL EBLTM (VWWNLM(1),VWWNLM(3),
     1             PJVPLM(1)-VWWNLM(1), PJVPLM(3)-VWWNLM(3), 0.0,
     2            (PJVPLM(2)-PJVPLM(1))/(VWWNLM(2)-VWWNLM(1)),
     3            (PJVPLM(4)-PJVPLM(3))/(VWWNLM(4)-VWWNLM(3)),  VWMPMT)

      END

C *** *** *** *** ***   End of PHIGS-mimicking routines;  *** *** *** *** ***


C *** *** *** *** ***   General-purpose PVT math routines   *** *** *** *** ***

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/matmul                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE MATMUL (M,N,P, A,B, C)

C general purpose matrix multiply - multiplies an MxN array (A)
C by a NxP array (B) to yield an MxP array (C).

      INTEGER   I,J,K, M,N,P
      REAL      A(M,N), B(N,P), C(M,P), TOT

      DO 100 I = 1,M
      DO 200 J = 1,P
         TOT = 0.0
         DO 300 K = 1,N
            TOT = TOT + A(I,K) * B(K,J)
300      CONTINUE
         C(I,J) = TOT
200   CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/idmat                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE IDMAT (SZ, MAT)

C General purpose routine to initialize a square matrix to
C the identity matrix.

      INTEGER   SZ, I,J
      REAL      MAT(SZ, SZ)

      DO 100 I = 1,SZ
      DO 200 J = 1,SZ
         IF (I .EQ. J) THEN
            MAT (I,J) = 1.0
         ELSE
            MAT (I,J) = 0.0
         ENDIF
200   CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/arrtp3                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/red43                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE RED43 (M4, M3)

C General purpose routine to reduce a 4x4 matrix to 3x3, by
C suppressing 3rd row and column

      REAL     M4(4,4), M3(3,3)
      INTEGER  I,J, IR,JR

      DO 100 I = 1,4
         IR = MIN(I,3)
         DO 200 J = 1,4
            JR = MIN(J,3)
            M3(IR,JR) = M4(I,J)
200      CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/exp34                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE EXP34  (MAT3, MAT4)

C  Expand a 3x3 matrix into a 4x4 matrix.

      INTEGER  I,J, IRECV,JRECV

      REAL   MAT3(3,3), MAT4(4,4)

      CALL IDMAT (4,MAT4)
      DO 100 I = 1,3
         IF (I.EQ.3) THEN
            IRECV = 4
         ELSE
            IRECV = I
         ENDIF
         DO 200 J = 1,3
            IF (J.EQ.3) THEN
               JRECV = 4
            ELSE
               JRECV = J
            ENDIF
            MAT4 (IRECV, JRECV) = MAT3 (I, J)
200      CONTINUE
100   CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    LOGICAL FUNCTION TR/trnseq                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      LOGICAL FUNCTION TRNSEQ (SZ, ACTMAT,EXPMAT)

C  Test two square matrices to see if they represent the same homogeneous
C  transformation.  Each transformation has an infinite number of
C  representations, because the matrix is scaled by element (sz,sz).

      INTEGER   SZ, I,J
      REAL      ACTMAT(SZ,SZ), EXPMAT(SZ,SZ), ASCALE, BSCALE
      LOGICAL   APPEQ

      ASCALE = ACTMAT(SZ,SZ)
      BSCALE = EXPMAT(SZ,SZ)

      IF (ASCALE*BSCALE .EQ. 0.0) THEN
C at least one is zero
         IF (ASCALE .EQ. BSCALE) THEN
C both are zero - set to 1.0 - both matrices represent transformation to
C points at infinity
            ASCALE = 1.0
            BSCALE = 1.0
         ELSE
C one zero and one not -
            TRNSEQ = .FALSE.
            RETURN
         ENDIF
      ENDIF

      DO 100 I = 1,SZ
      DO 200 J = 1,SZ
         IF (.NOT. APPEQ(ACTMAT(I,J)/ASCALE,
     1                   EXPMAT(I,J)/BSCALE, 1E-7, 1E-4)) THEN
            TRNSEQ = .FALSE.
            RETURN
         ENDIF
200   CONTINUE
100   CONTINUE

      TRNSEQ = .TRUE.

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION TR/satan2                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION SATAN2 (Y, X)

C  Safe version of arctan-2 function; returns zero when both x and y
C  are zero.

      REAL  X,Y

      IF (X .EQ. 0.0 .AND. Y .EQ. 0.0) THEN
         SATAN2 = 0.0
      ELSE
         SATAN2 = ATAN2(Y,X)
      ENDIF

      END


C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION TR/vecl2                             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION VECL2 (VX,VY,VZ)

C  This function returns the squared length of a 3D vector.

      REAL  VX,VY,VZ

      VECL2 = VX*VX + VY*VY + VZ*VZ

      END


C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION TR/vecl                              *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION VECL (VX,VY,VZ)

C  This function returns the length of a 3D vector.

      REAL  VX,VY,VZ, VECL2

      VECL = SQRT (VECL2 (VX,VY,VZ) )

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/vec1                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE VEC1 (VX,VY,VZ, VX1,VY1,VZ1)

C  This subroutine accepts an arbitrary 3D vector and returns a
C  parallel vector normalized to unit size.

      REAL  VX,VY,VZ, VX1,VY1,VZ1, D, VECL

      D = VECL(VX,VY,VZ)
      VX1 = VX/D
      VY1 = VY/D
      VZ1 = VZ/D

      END


C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION TR/dotprd                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION DOTPRD (VX1,VY1,VZ1, VX2,VY2,VZ2)

C  This function accepts two 3D vectors and returns their dot product.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2

      DOTPRD = VX1*VX2 + VY1*VY2 + VZ1*VZ2

      END


C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION TR/vecang                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION VECANG (VX1,VY1,VZ1, VX2,VY2,VZ2)

C  This function accepts two 3D vectors and returns the
C  angle between them.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, VECL, DOTPRD, VL, COSVAL

      VL = VECL(VX1,VY1,VZ1) * VECL(VX2,VY2,VZ2)

      IF (VL .EQ. 0) THEN
         VECANG = 0.0
      ELSE
         COSVAL = DOTPRD (VX1,VY1,VZ1, VX2,VY2,VZ2) / VL
         IF (ABS(COSVAL) .GT. 1.0) THEN
            CALL UNMSG ('Unstable parameters passed to VECANG.')
         ENDIF
         VECANG = ACOS (COSVAL)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/crossp                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE CROSSP (VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3)

C  This subroutine accepts two 3D vectors and returns their
C  cross product.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3

      VX3 = VY1*VZ2 - VZ1*VY2
      VY3 = VZ1*VX2 - VX1*VZ2
      VZ3 = VX1*VY2 - VY1*VX2

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/prpv1                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PRPV1 (VX1,VY1,VZ1, VX2,VY2,VZ2)

C  PRPV1 accepts a 3D vector and returns another 3D vector
C  perpendicular to it.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, Z

      Z = 0.0
      VX2 = Z
      VY2 = Z
      VZ2 = Z
      IF (VX1 .EQ. Z) THEN
         VX2 = 1.0
      ELSEIF (VY1 .EQ. Z) THEN
         VY2 = 1.0
      ELSEIF (VZ1 .EQ. Z) THEN
         VZ2 = 1.0
      ELSE
         VX2 =  VY1
         VY2 = -VX1
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/pervec                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PERVEC (VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3)

C  This subroutine accepts two 3D vectors and returns a vector
C  orthogonal to the first, in the plane of the first two vectors,
C  whose dot product with the second vector is positive, hence
C  the angle between them is < 90 degrees.  I.e. the 2nd vector
C  minus the 3rd results in a vector with the same direction (but
C  not length) as the 1st.  K is the factor by which V1 is 
C  multiplied and then subtracted from V2 - i.e.
C  
C       V3 = V2 - K*V1


C                     _ 
C                     /|A 
C                   /   | 
C                 /     | 
C            V2 /       | V3
C             /         | 
C           /           | 
C         /             | 
C       /               | 
C      ----------->.....| 
C          V1
C      \________________/
C           V2 - V3

C  Or, V1 can be thought of as the attitude numbers for a plane, and
C  then V3 is the result of the normal projection of V2 into the plane.
C  
C  Closely related to PTPLDS, which is a slightly more general case.

      REAL  VX1,VY1,VZ1, VX2,VY2,VZ2, VX3,VY3,VZ3, K, DOTPRD, VECL2

      K = DOTPRD (VX1,VY1,VZ1, VX2,VY2,VZ2) / VECL2 (VX1, VY1, VZ1)
      VX3 = VX2 - K*VX1
      VY3 = VY2 - K*VY1
      VZ3 = VZ2 - K*VZ1

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ptplds                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PTPLDS (PX,PY,PZ, A,B,C,D, XN,YN,ZN, DIST)

C Given a point and plane-coefficients, find nearest
C point on plane and distance from plane to point.

      REAL   PX,PY,PZ, A,B,C,D, XN,YN,ZN, DIST, SQ,SOL,U, VECL2

      SQ   = VECL2 (A,B,C)
      SOL  = A*PX + B*PY + C*PZ + D
      DIST = ABS(SOL) / SQRT(SQ)
      U    = - SOL / SQ
      XN = PX + A*U
      YN = PY + B*U
      ZN = PZ + C*U

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/lnplpt                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LNPLPT (LX,LY,LZ, AL,BL,CL, AP,BP,CP,DP, XI,YI,ZI)

C  Given a line and a plane, find point of intersection.

C  Input parameters
C    LX,LY,LZ    : point on the line
C    AL,BL,CL    : direction of line
C    AP,BP,CP,DP : co-efficients of plane
C  Output parameters
C    XI,YI,ZI    : point of intersection

      REAL   U, LX,LY,LZ, AL,BL,CL, AP,BP,CP,DP, XI,YI,ZI, DOTPRD

      U = - (DOTPRD (AP,BP,CP, LX,LY,LZ) + DP) /
     1       DOTPRD (AP,BP,CP, AL,BL,CL)

      XI = LX + AL*U
      YI = LY + BL*U
      ZI = LZ + CL*U

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/pt3pl                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PT3PL (X,Y,Z, A,B,C,D)

      REAL   X(3),Y(3),Z(3), A,B,C,D

C Given 3 points, find containing plane
      A = Y(2)*Z(3) + Y(3)*Z(1) + Y(1)*Z(2)
     1  - Y(1)*Z(3) - Y(2)*Z(1) - Y(3)*Z(2)
      B = Z(2)*X(3) + Z(3)*X(1) + Z(1)*X(2)
     1  - Z(1)*X(3) - Z(2)*X(1) - Z(3)*X(2)
      C = X(2)*Y(3) + X(3)*Y(1) + X(1)*Y(2)
     1  - X(1)*Y(3) - X(2)*Y(1) - X(3)*Y(2)

      D = - (A*X(1) + B*Y(1) + C*Z(1) +
     1       A*X(2) + B*Y(2) + C*Z(2) +
     2       A*X(3) + B*Y(3) + C*Z(3)) / 3

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ptspl                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/pl2pl                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PL2PL (AR,BR,CR,DR, AX,BX,CX,DX, AP,BP,CP,DP)

C  Given a reference plane (R) and an intersecting crossing plane
C  (X), find the perpendicular plane (P), which contains the line of
C  intersection of R and X, and is perpendicular to R.

      REAL  AR,BR,CR,DR, AX,BX,CX,DX, AP,BP,CP,DP
      REAL  AL,BL,CL, PX,PY,PZ

C  get line of intersection of R and X
      CALL PL2LN (AR,BR,CR,DR, AX,BX,CX,DX, AL,BL,CL, PX,PY,PZ)
C  cross-prod of line and ref plane is attitude of P-plane
      CALL CROSSP ( AR,BR,CR, AL,BL,CL, AP,BP,CP)
C  solve for dp, given point on line:
      DP = -(AP*PX + BP*PY + CP*PZ)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/pl2ln                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PL2LN (A1,B1,C1,D1, A2,B2,C2,D2, A,B,C, PX,PY,PZ)

C  Given two planes, return line-intersection

      INTEGER  IXYZ, ABEST3
      REAL     A1,B1,C1,D1, A2,B2,C2,D2, A,B,C, PX,PY,PZ

C  Direction of line is cross-product of normal vectors
      CALL CROSSP (A1,B1,C1, A2,B2,C2, A,B,C)

C  use most stable variable as basis - effectively, use x=0, y=0,
C  or z=0 as 3rd plane.
      IXYZ = ABEST3 (A,B,C)
      IF (IXYZ .EQ. 1) THEN
         PX = 0
         CALL LINTPT (B1,C1,D1, B2,C2,D2, PY,PZ)
      ELSEIF (IXYZ .EQ. 2) THEN
         PY = 0
         CALL LINTPT (A1,C1,D1, A2,C2,D2, PX,PZ)
      ELSE
         PZ = 0
         CALL LINTPT (A1,B1,D1, A2,B2,D2, PX,PY)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION TR/abest3                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION ABEST3 (AA,BA,CA)

      REAL  A,B,C,BEST, AA,BA,CA

C  function to pick greatest magnitude of 3 numbers

      A = ABS(AA)
      B = ABS(BA)
      C = ABS(CA)

      IF (A .GT. B) THEN
         ABEST3 = 1
         BEST=A
      ELSE
         ABEST3 = 2
         BEST=B
      ENDIF

      IF (C .GT. BEST) THEN
         ABEST3 = 3
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ptlnds                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PTLNDS (PX,PY,PZ, A,B,C,LX,LY,LZ, XN,YN,ZN, DIST)

C  Given a point and a line, find nearest point on line and
C  distance from line to point.

      REAL   PX,PY,PZ, A,B,C,LX,LY,LZ, XN,YN,ZN, DIST, VECL2, VECL
      REAL   DX,DY,DZ, D2ABC, DP, U, DOTPRD

      DX = PX-LX
      DY = PY-LY
      DZ = PZ-LZ
      D2ABC = VECL2 (A,B,C)

      DP = DOTPRD (A,B,C, DX,DY,DZ)
      U  = DP / D2ABC
      XN = LX + A*U
      YN = LY + B*U
      ZN = LZ + C*U

      DIST = VECL (PX-XN, PY-YN, PZ-ZN)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/lintpt                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE LINTPT (A,B,C, D,E,F, X,Y)

C Given two sets of line-coefficients, find intersection point

      REAL  A,B,C,D,E,F,X,Y, DEN

      DEN = D*B - A*E
      X = (C*E - F*B) / DEN
      Y = (F*A - C*D) / DEN

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/pt2cof                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PT2COF (X1,Y1, X2,Y2, A,B,C)
C Given two points, calculate line coefficients.

      REAL   X1,Y1, X2,Y2, A,B,C

      A = Y1-Y2
      B = X2-X1
      C = X1*Y2 - Y1*X2

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/parcof                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE PARCOF (X0,Y0, XCOEFF,YCOEFF, A,B,C)
C  given parametric form, find line coefficients

      REAL  X0,Y0, XCOEFF,YCOEFF, A,B,C

      A =  YCOEFF
      B = -XCOEFF
      C =  XCOEFF*Y0 - YCOEFF*X0

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION TR/ptregd                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION PTREGD (PX,PY,PZ, NSZ, XA,YA,ZA)

C  PTREGD computes the minimum distance from a 3D point to a planar
C  3D region.

C Input parameters:
C   PX,PY,PZ : point for which distance is found.
C   NSZ      : number of points in region.
C   XA,YA,ZA : coordinates of planar region.

      INTEGER    NSZ, IA, IB, SIDE

      REAL       PX,PY,PZ, XA(NSZ),YA(NSZ),ZA(NSZ)
      REAL       XN,YN,ZN, PTMIN, EDGMIN
      REAL       SEGA,SEGB,SEGC, D1,D2, ABCP, DTMP,VECL, PLDIST

      IF (NSZ .LT. 3) THEN
         CALL UNMSG ('Degenerate region passed to PTREGD.')
      ENDIF

      CALL INVOL (PX,PY,PZ, NSZ, XA,YA,ZA, SIDE, PLDIST)
      IF (SIDE .LE. 2) THEN
C  Distance is simply distance of point from containing plane
         PTREGD = PLDIST
         RETURN
      ENDIF

C  Distance is minimum of distances from points and from individual edges

C  Get point minimum:
      PTMIN = 1E38
      DO 100 IA = 1,NSZ
         DTMP = VECL (PX-XA(IA), PY-YA(IA), PZ-ZA(IA) )
         IF (DTMP .LT. PTMIN) PTMIN = DTMP
100   CONTINUE

C  Get edge minimum:
      EDGMIN = 1E38
      DO 200 IA = 1,NSZ
         IB = MOD(IA, NSZ) + 1
C  Determine if point is between the two planes that contain the
C  endpoints of the segment, and are normal to it.  If not, ignore -
C  handled by point minimum.  If so, distance is that from point to
C  containing line.

C  attitude of planes:
         SEGA = XA(IA) - XA(IB)
         SEGB = YA(IA) - YA(IB)
         SEGC = ZA(IA) - ZA(IB)
C  d-coefficient of each plane:
         D1 = -(SEGA*XA(IA) + SEGB*YA(IA) + SEGC*ZA(IA))
         D2 = -(SEGA*XA(IB) + SEGB*YA(IB) + SEGC*ZA(IB))
C  ABC terms for px,py,pz:
         ABCP = SEGA*PX + SEGB*PY + SEGC*PZ
         IF ( (ABCP + D1) * (ABCP + D2) .LT. 0.0 ) THEN
C  Opposite signs imply point is between planes - get distance from
C  point to line.
            CALL PTLNDS (PX,PY,PZ, SEGA,SEGB,SEGC,
     1                   XA(IA),YA(IA),ZA(IA), XN,YN,ZN, DTMP)
            IF (DTMP .LT. EDGMIN) EDGMIN = DTMP
         ENDIF
200   CONTINUE

      PTREGD = MIN (PTMIN, EDGMIN)

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION TR/ceilng                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION CEILNG (X)

C  CEILNG returns the integer ceiling for x, i.e. the lowest
C  integer .ge. x

      INTEGER    IX
      REAL       X

      IX = INT(X)
      IF (REAL(IX).EQ.X .OR. X.LE.0) THEN
         CEILNG = IX
      ELSE
         CEILNG = IX + 1
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION TR/mod1                           *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      INTEGER FUNCTION MOD1 (X,M)

C  MOD1 returns X mod M, but coerced between 1 and M, not between
C  0 and M-1.

      INTEGER    X,M, XW

      IF (X.LT.0) THEN
         XW = X - (X/M - 2) * M
      ELSE
         XW = X
      ENDIF
      MOD1 = MOD(XW,M)
      IF (MOD1.LE.0) MOD1 = M

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/invol                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE INVOL (PX,PY,PZ, ILIM, ARX,ARY,ARZ, SIDE, PLDIST)

C  Given a 3D point and planar fill area, determine whether point
C  is within normal projection of the area, and distance of point
C  from the plane.

C  Input parameters:
C    PX,PY,PZ     : 3D point
C    ILIM         : Number of vertices of fill area
C    ARX,ARY,ARZ  : vertices of fill area

C  Output parameters:
C    SIDE         : location of point within volume -
C                 : 1 if inside, 2 if on an edge, 3 if outside
C    PLDIST       : distance of point from the plane.

      INTEGER   ILIM, INAREA, IDIM, SIDE

      REAL      PX,PY,PZ, ARX(*),ARY(*),ARZ(*)
      REAL      A,B,C,D, XN,YN,ZN, PLDIST, BEST

      IF (ILIM .LT. 3) THEN
         CALL UNMSG ('Degenerate fill area passed to INVOL.')
      ENDIF

C get plane from set of points
      CALL PTSPL (ILIM, ARX,ARY,ARZ, A,B,C,D)

C Given a point and plane-coefficients, find nearest
C point on plane and distance from plane to point.
      CALL PTPLDS (PX,PY,PZ, A,B,C,D, XN,YN,ZN, PLDIST)

C  Now project the planar points (fill area, plus the normal
C  projected point xn,yn,zn) to the "best" plane: x=0, y=0, or z=0,
C  depending on largest attitude number.
      IF (ABS(A) .GT. ABS(B)) THEN
         IDIM = 1
         BEST=ABS(A)
      ELSE
         IDIM = 2
         BEST=ABS(B)
      ENDIF

      IF (ABS(C) .GT. BEST) THEN
         IDIM = 3
      ENDIF

      IF     (IDIM .EQ. 1) THEN
C project to x=0
         SIDE = INAREA (YN,ZN, ILIM, ARY,ARZ)
      ELSEIF (IDIM .EQ. 2) THEN
C project to y=0
         SIDE = INAREA (XN,ZN, ILIM, ARX,ARZ)
      ELSE
C project to z=0
         SIDE = INAREA (XN,YN, ILIM, ARX,ARY)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    INTEGER FUNCTION TR/inarea                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/issdis                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ISSDIS (SISRPX,SISRPY,SISRPZ, SDIST, XFRMT,
     1                   MCLIPI, EXPATH)

C  This subroutine invokes the 3D spatial search routine with the
C  search distance set just below and above the theoretically
C  correct distance.  The search always begins at the start of
C  structure #101.  Thus, the search should first be unsuccessful,
C  and then successful.  ISSDIS issues pass or fail as a result
C  of these two searches.

C  Input parameters:
C    SISRPX,Y,Z : untransformed search reference point
C    SDIST      : correct search distance
C    XFRMT      : matrix used to transform search reference point
C    MCLIPI     : clipping indicator to be used
C    EXPATH     : expected found path

      INTEGER    MCLIPI

      REAL       SISRPX,SISRPY,SISRPZ, COSRPX,COSRPY,COSRPZ, SDIST
      REAL       XFRMT(4,4)

      CHARACTER  EXPATH*(*)

C  transform search reference point
      CALL ETP3 (SISRPX,SISRPY,SISRPZ, XFRMT, COSRPX,COSRPY,COSRPZ)

      CALL ISSAB (COSRPX,COSRPY,COSRPZ, SDIST, '101,0', MCLIPI, 1,
     1            EXPATH)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/issab                                *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ISSAB (SRPX,SRPY,SRPZ, SDIST, STPATH, MCLIPI, SCEIL,
     1                  EXPATH)

C  This subroutine invokes the 3D spatial search routine with the
C  search distance set just below and above the theoretically
C  correct distance.  Thus, the search should first be unsuccessful,
C  and then successful.  ISSAB issues pass or fail as a result
C  of these two searches.

C  Input parameters:
C    SRPX,Y,Z   : search reference point
C    SDIST      : correct search distance
C    STPATH     : starting path
C    MCLIPI     : modelling clipping indicator
C    SCEIL      : search ceiling
C    EXPATH     : expected found path

      REAL       SRPX,SRPY,SRPZ, SDIST

      INTEGER    IPTHSZ
      PARAMETER (IPTHSZ = 100)

      INTEGER    ISTPTH(2,IPTHSZ),ISTLEN, IDUM(2),ERRIND, MCLIPI, SCEIL
      INTEGER    IEXPTH(2,IPTHSZ), IEXLEN, FPATH(2,IPTHSZ), FPTHSZ

      LOGICAL    IAREQL

      CHARACTER  MSG*200, EXPATH*(*), STPATH*(*)

      CALL SETVS (STPATH, ISTPTH, ISTLEN)
      CALL SETVS (EXPATH, IEXPTH, IEXLEN)

      CALL PISS3 (SRPX,SRPY,SRPZ, 0.98*SDIST, ISTLEN/2, ISTPTH, MCLIPI,
     1            SCEIL, 0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND. FPTHSZ .EQ. 0) THEN
C OK so far
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'ISS did not return null ' //
     1      'path as expected; error indicator = ', ERRIND, '.'
         CALL INMSG (MSG)
         RETURN
      ENDIF

      CALL PISS3 (SRPX,SRPY,SRPZ, 1.02*SDIST, ISTLEN/2, ISTPTH, MCLIPI,
     1            SCEIL, 0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND.
     1    IAREQL (2*FPTHSZ, FPATH, IEXLEN, IEXPTH)) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'ISS did not return correct ' //
     1      'found path; error indicator = ', ERRIND, '.'
         CALL INMSG (MSG)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE TR/ispths                               *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ISPTHS (SRPX,SRPY,SRPZ, SDIST, SCEIL, MCLIPI,
     1                   STPTH, EXPTHS)

C  This subroutine repeatedly invokes spatial search, using the
C  found path of one search as the starting path for the next, and
C  issues pass or fail, depending on whether the actual paths match
C  those expected.

C  Input parameters:
C    SRPX,Y,Z : search reference point to be used in ISS's
C    SDIST    : search distance to be used in ISS's
C    SCEIL    : search ceiling to be used in ISS's
C    MCLIPI   : modelling clipping indicator
C    STPTH    : starting path for first ISS
C    EXPTHS   : sequence of expected found paths for ISS's

      INTEGER    EXDIM,IPTHSZ
      PARAMETER (EXDIM = 30, IPTHSZ = 30)

      INTEGER    EXNUM, EXLEN(EXDIM), EXPATH(EXDIM, EXDIM)
      INTEGER    SPSIZ,  SPATH(2,IPTHSZ), SCEIL, IDUM(2), IPATH, IX
      INTEGER    FPTHSZ, FPATH(2,IPTHSZ), ERRIND, MCLIPI

      REAL       SRPX,SRPY,SRPZ, SDIST

      LOGICAL    IAREQL

      CHARACTER  EXPTHS*(*), STPTH*(*)

      CALL SETVS (STPTH, SPATH, SPSIZ)
      SPSIZ = SPSIZ/2
      CALL SET2D (EXPTHS, EXDIM, EXNUM,EXLEN,EXPATH)

      DO 100 IPATH = 1,EXNUM
         CALL PISS3 (SRPX,SRPY,SRPZ, SDIST, SPSIZ, SPATH, MCLIPI, SCEIL,
     1               0,IDUM,IDUM,IDUM,IDUM, 0,IDUM,IDUM,IDUM,IDUM,
     2               IPTHSZ, ERRIND, FPTHSZ, FPATH)
         IF (ERRIND .EQ. 0 .AND.
     1       IAREQL (FPTHSZ*2,FPATH, EXLEN(IPATH),EXPATH(1,IPATH))) THEN
C OK so far - copy found path to next starting path
            SPSIZ = FPTHSZ
            DO 110 IX = 1,SPSIZ
               SPATH(1,IX) = FPATH(1,IX)
               SPATH(2,IX) = FPATH(2,IX)
110         CONTINUE
         ELSE
            CALL FAIL
            RETURN
         ENDIF
100   CONTINUE
      CALL PASS

      END
