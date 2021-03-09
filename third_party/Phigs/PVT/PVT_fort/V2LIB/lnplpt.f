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
