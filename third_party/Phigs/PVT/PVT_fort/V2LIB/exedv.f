      SUBROUTINE EXEDV (VXSTR, XEXP,YEXP)

C  EXEDV draws a polyline using the indicated elements of the
C  arrays of expected vertices.

C  Input parameters:
C    VXSTR     : Positions in array to use as vertices
C    XEXP,YEXP : Array of expected vertices from which values are taken

      INTEGER   VXSIZ,VX(20),IX

      REAL      XEXP(*),YEXP(*), XA(20),YA(20)

      CHARACTER VXSTR*(*)

      CALL SETVS (VXSTR, VX, VXSIZ)
      DO 100 IX = 1,VXSIZ
         XA(IX) = XEXP(VX(IX))
         YA(IX) = YEXP(VX(IX))
100   CONTINUE

      CALL PPL (VXSIZ, XA,YA)

      END
