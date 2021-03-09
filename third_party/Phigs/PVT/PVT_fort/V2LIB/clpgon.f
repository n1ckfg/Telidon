      SUBROUTINE CLPGON (VISCT, NUMPL, RAD)

C  CLPGON draws a set of markers some of which are just inside the
C  clipping region shaped like a regular polygon, and the rest just
C  outside it.

C  Input parameters:
C    VISCT : number of markers to be drawn inside clipping region
C    NUMPL : total number of markers to be drawn = #sides of polygon
C    RAD   : radius of polygon (distance from center to face, not vertex)

      INTEGER    VISCT, NUMPL, VISLIS(50), IX, IARFND
C maximum number of planes to be tested
      INTEGER    TSTMAX
      PARAMETER (TSTMAX = 500)

      REAL       XLOC(TSTMAX), YLOC(TSTMAX), ZLOC(TSTMAX)
      REAL       RAD, THSRAD, RNDRL, ANG, PI
      PARAMETER (PI = 3.14159265)

C  Choose visct markers to be inside
      CALL RNSET (VISCT, NUMPL, VISLIS)

C  calculate coordinates of polymarker:
      DO 100 IX = 1,NUMPL
         IF ( IARFND (IX, VISCT, VISLIS) .GT. 0) THEN
C  Inside:
            THSRAD = 0.99 * RAD
         ELSE
C  Outside:
            THSRAD = 1.01 * RAD
         ENDIF
         ANG = IX*2*PI / NUMPL
         XLOC (IX) = 0.5 + THSRAD * COS(ANG)
         YLOC (IX) = 0.5 + THSRAD * SIN(ANG)
         ZLOC (IX) = RNDRL(0.,1.0)
  100 CONTINUE
      CALL PPM3 (NUMPL, XLOC,YLOC,ZLOC)

      END
