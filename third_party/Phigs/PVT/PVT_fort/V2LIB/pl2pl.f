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
