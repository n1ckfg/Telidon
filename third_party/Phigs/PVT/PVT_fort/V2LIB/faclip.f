      SUBROUTINE FACLIP (ACL,BCL,CCL,DCL, XCO,YCO,ZCO, MCV3)

C  FACLIP accepts the co-efficients for two given clipping planes,
C  generates a plane for a fill area primitive and computes
C  another clipping plane, perpendicular to the primitive's
C  plane, but intersecting it the same way as does the given
C  clipping plane.

C  Input parameters:
C    ACL,BCL,CCL,DCL : co-efficients of given planes (CCL usually zero)
C  Output parameters:
C    XCO,YCO         : x,y co-efficients of primitive plane
C    MCV3            : computed planes, perpendicular to primitive plane

      INTEGER JX

      REAL    AF,BF,CF,DF, ACL(3),BCL(3),CCL(3),DCL(3), XCO,YCO,ZCO
      REAL    MCV3(6,2), RNDRL

C  randomize plane of fill area (in MC): xco*x + yco*y - z + zco = 0
      XCO = RNDRL(0.0, 0.4)
      YCO = RNDRL(0.0, 0.4)
      ZCO = 0.1

C  calculate 3D MCVs perpendicular to MC fill area plane, with negative
C  x-component.
      DO 330 JX = 1,2
         CALL PL2PL (XCO,YCO,-1.0,ZCO,
     1               ACL(JX),BCL(JX),CCL(JX),DCL(JX),
     2               AF,BF,CF,DF)
         IF (AF .EQ. 0) THEN
            CALL UNMSG ('Generated invalid clipping plane.')
         ELSEIF (AF .GT. 0) THEN
            AF = -AF
            BF = -BF
            CF = -CF
            DF = -DF
         ENDIF
         MCV3(1,JX) = -DF/AF
         MCV3(2,JX) = 0.0
         MCV3(3,JX) = 0.0
         MCV3(4,JX) = AF
         MCV3(5,JX) = BF
         MCV3(6,JX) = CF
330   CONTINUE

      END
