      SUBROUTINE XFINH (PERM)

C  More special-purpose code here for testing inheritance.
C  Since structure 104 is re-invoked, it generates polyline #5,6 on
C  first invocation, and 11,12 on 2nd.  But 11,12 would simply
C  overlay 5,6, so we must also pass down a transformation which
C  maps locations 5,6 to locations 11,12, respectively.

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER   PERM(14), ERRIND

      REAL      Z,U,YLOCEL,FXPTY, SHIFTY,SCALEY, XFORM(3,3)

      Z = 0.0
      U = 1.0
      FXPTY  =  YLOCEL(PERM(5))
      SHIFTY =  YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      SCALEY = (YLOCEL(PERM(12)) - YLOCEL(PERM(11))) /
     1         (YLOCEL(PERM(06)) - YLOCEL(PERM(05)))
      CALL PBLTM (Z,FXPTY, Z,SHIFTY, Z, U,SCALEY, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)

      END
