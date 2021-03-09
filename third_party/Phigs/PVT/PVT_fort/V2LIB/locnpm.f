      SUBROUTINE LOCNPM (NPPM, YPOS, XLOC)

C  LOCNPM draws a polymarker with NPPM markers at the real y-location
C  corresponding to the integer index given in YPOS.

      INTEGER  IX,YPOS, NPPM

      REAL     YLOCEL, XLOC(*), YA(5), YVAL

      YVAL = YLOCEL(YPOS)
      DO 10 IX = 1,NPPM
         YA(IX) = YVAL
10    CONTINUE
      CALL PPM (NPPM, XLOC, YA)

      END
