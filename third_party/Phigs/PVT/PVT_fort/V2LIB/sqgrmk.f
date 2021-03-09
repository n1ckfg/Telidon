      SUBROUTINE SQGRMK (START, FINISH, STEP)

C  SQGRMK draws a square grid of polymarkers.  They are drawn one
C  row at a time to avoid array overflow.

C  Input parameters:
C    START  : First x and y locations
C    FINISH : Upper limit for x and y locations
C    STEP   : Distance between markers

      INTEGER    SIZ, ARRSIZ
      PARAMETER (ARRSIZ=200)

      REAL    XLOC,YLOC, START, FINISH, STEP, XA(ARRSIZ),YA(ARRSIZ)

      IF ((FINISH-START)/STEP .GT. ARRSIZ) THEN
         CALL UNMSG ('Number of polymarkers exceeds array size in ' //
     1               'SQGRMK.')
      ENDIF

      DO 215 XLOC = START, FINISH, STEP
         SIZ = 0
         DO 210 YLOC = START, FINISH, STEP
            SIZ = SIZ + 1
            XA(SIZ) = XLOC
            YA(SIZ) = YLOC
210      CONTINUE
         CALL PPM (SIZ, XA, YA)
215   CONTINUE

      END
