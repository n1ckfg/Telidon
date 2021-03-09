      SUBROUTINE TSTPRJ (PRP, TRNF, VWCENT)

C  TSTPRJ tests that two arbitrary points on a projector are both
C  mapped to the same x-y values in NPC space.

C  ------- INPUT PARAMETERS
C  prp (3)    : projection reference point
C  trnf (4,4) : transformation returned by pevmm3
C  vwcent (3) : view window center

      REAL     PRP(3), VWCENT(3), TRNF(4,4), DLT(3), UPARM
      REAL     VRCPT(3), NPCPT(2,3)
      INTEGER  IXYZ, WHICH
      LOGICAL  APPEQ

C   compute VRC projector passing thru view window center
      DO 110 IXYZ = 1,3
         DLT(IXYZ) = VWCENT(IXYZ) - PRP(IXYZ)
110   CONTINUE

C   pick two points on projector
      DO 210 WHICH = 1,2
C   compute point based on uparm - 3.3 units on each side of PRP
         UPARM = 3.3 * (WHICH*2 - 3)
         DO 220 IXYZ = 1,3
            VRCPT(IXYZ) = PRP(IXYZ) + UPARM * DLT(IXYZ)
220      CONTINUE
C   apply trnf to VRC point to determine transformed NPC point
         CALL ETP3 (VRCPT(      1), VRCPT(      2), VRCPT(      3),
     1        TRNF, NPCPT(WHICH,1), NPCPT(WHICH,2), NPCPT(WHICH,3))
210   CONTINUE

C   pass/fail projector test depending on
C     (cent1x approx= cent2x and cent1y approx= cent2y)
      CALL IFPF (APPEQ( NPCPT(1,1), NPCPT(2,1), 1E-7, 1E-4) .AND.
     1           APPEQ( NPCPT(1,2), NPCPT(2,2), 1E-7, 1E-4))

      END
