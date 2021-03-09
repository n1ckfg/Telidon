      SUBROUTINE TSTCOR  (VWIND, PRVWPT, PROJTY, PRP, VPD,BPD,FPD,
     1                    TRNF, VWCENT)

C  TSTCOR tests the pevmm3 function by applying the transform
C  returned by it to the eight corners of the view volume and
C  checking that they are reasonably close to the corners of the
C  projection viewport.
C
C  ------- INPUT PARAMETERS
C  vwind (4)  : view window limits
C  prvwpt (6) : projection viewport limits
C  projty     : projection type
C  prp (3)    : projection reference point
C  vpd        : view plane distance (n-coordinate value)
C  bpd        : back plane distance (n-coordinate value)
C  fpd        : front plane distance (n-coordinate value)
C
C  ------- OUTPUT PARAMETERS:
C  trnf (4,4) : transformation returned by pevmm3
C  vwcent (3) : view window center

      REAL     VWIND(4), PRVWPT(6), PRP(3), VPD,BPD,FPD
      REAL     BAS(4,3), DLT(4,3), ACTPR(3)
      REAL     VWCENT(3), ACTVV(8,3), NVAL
      REAL     EXPPR(8,3), TRNF(4,4), UPARM
      INTEGER  PROJTY, IPROJ, ICOR, ICORX,ICORY,ICORZ, ERRIND, IXYZ
      LOGICAL  APPEQ

C viewtype
      INTEGER    PPARL,     PPERS
      PARAMETER (PPARL = 0, PPERS = 1)

      CHARACTER  MSG*300, XYZ*3

      XYZ = 'XYZ'
C get view window center
      VWCENT(1) = (VWIND(1)+VWIND(2))/2
      VWCENT(2) = (VWIND(3)+VWIND(4))/2
      VWCENT(3) = VPD

C determine BASE and DELTA for 4 corner projectors - each line in
C parametric form:
C   x = BASx + uparm*DLTx
C   y = BASy + uparm*DLTy
C   z = BASz + uparm*DLTz

C  Order of projectors is:
C     1: left,  bottom
C     2: left,  top
C     3: right, bottom
C     4: right, top

      IF (PROJTY .EQ. PPARL) THEN
C deltas for all 4 projectors are the same - parallel projectors
         DO 110 IPROJ = 1,4
         DO 120 IXYZ  = 1,3
            DLT (IPROJ, IXYZ) = VWCENT(IXYZ) - PRP(IXYZ)
120      CONTINUE
110      CONTINUE
      ELSEIF (PROJTY .EQ. PPERS) THEN
C delta based on PRP and *corners* of view window
         DO 210 ICORX = 1,2
         DO 215 ICORY = 3,4
C which projector?
            IPROJ = 2*ICORX + ICORY - 4
            DLT (IPROJ, 1) = VWIND(ICORX) - PRP(1)
            DLT (IPROJ, 2) = VWIND(ICORY) - PRP(2)
            DLT (IPROJ, 3) = VPD          - PRP(3)
215      CONTINUE
210      CONTINUE
      ELSE
         WRITE (MSG, '(A,I5)')
     1      'Illegal projection type passed to TSTCOR:', PROJTY
         CALL UNMSG (MSG)
      ENDIF

C use 4 corners of view window as bases - these are valid
C for either parallel or perspective
      DO 310 ICORX = 1,2
      DO 315 ICORY = 3,4
C which projector?
         IPROJ = 2*ICORX + ICORY - 4
         BAS (IPROJ, 1) = VWIND(ICORX)
         BAS (IPROJ, 2) = VWIND(ICORY)
         BAS (IPROJ, 3) = VPD
315   CONTINUE
310   CONTINUE

C calculate all 8 view volume corners
C labeling of corners: (left, bottom, back = 1, left, bottom, front = 2...
C    right, top, front = 8)
      DO 350 ICOR = 1,8
C which projector
         IPROJ = (ICOR+1) / 2
         IF (MOD(ICOR,2) .EQ. 1) THEN
            NVAL = BPD
         ELSE
            NVAL = FPD
         ENDIF

C calculate value of UPARM for parametric lines
         UPARM = (NVAL - BAS (IPROJ,3)) / DLT (IPROJ,3)
C get coordinates for the corner
         DO 360 IXYZ = 1,3
            ACTVV(ICOR,IXYZ) = BAS(IPROJ,IXYZ) + UPARM*DLT(IPROJ,IXYZ)
360      CONTINUE
350   CONTINUE

C expected values for projection:
      DO 410 ICORX = 1,2
      DO 420 ICORY = 3,4
      DO 430 ICORZ = 5,6
C which corner
         ICOR = 4*ICORX + 2*ICORY + ICORZ - 14
         EXPPR(ICOR,1) = PRVWPT(ICORX)
         EXPPR(ICOR,2) = PRVWPT(ICORY)
         EXPPR(ICOR,3) = PRVWPT(ICORZ)
430   CONTINUE
420   CONTINUE
410   CONTINUE

      CALL PEVMM3 (VWIND, PRVWPT, PROJTY, PRP(1),PRP(2),PRP(3),
     1             VPD,BPD,FPD, ERRIND, TRNF)
      IF (ERRIND .NE. 0) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5)')
     1         'Non-zero error code in TSTCOR from PEVMM3:', ERRIND
         CALL INMSG (MSG)
         RETURN
      ENDIF

C transform view volume corners to projection corners
      DO 510 ICOR = 1,8
         CALL ETP3 (ACTVV(ICOR,1), ACTVV(ICOR,2), ACTVV(ICOR,3), TRNF,
     1              ACTPR(     1), ACTPR(     2), ACTPR(     3))
         DO 520 IXYZ = 1,3
            IF ( .NOT. APPEQ( ACTPR(     IXYZ),
     1                        EXPPR(ICOR,IXYZ), 1E-7, 1E-4)) THEN
               CALL FAIL
               WRITE (MSG, '(A,I5,A)') 'Failed on corner #',
     1                ICOR, ', coordinate ' // XYZ(IXYZ:IXYZ)
               CALL INMSG (MSG)
               RETURN
            ENDIF
520      CONTINUE
510   CONTINUE
      CALL PASS

      END
