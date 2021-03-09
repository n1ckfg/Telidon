      SUBROUTINE LBEDTY (WKID, NUMDIS, PERM, LEDTYP)

C  LBEDTY is used to display a list of edgetypes, under bundled control.
C
C  Input parameters:
C    WKID   : Workstation identifier for edge bundles
C    NUMDIS : Number of edgetypes to be selected and displayed
C    PERM   : List of positions of selected edgetypes within LEDTYP
C    LEDTYP : List of edgetypes from which selection is made

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER   WKID, IX, NUMDIS, PERM(NUMDIS), LEDTYP(*), NPTS(1)
      INTEGER   THISET

      REAL      YLOC, YINCR, YBOT,YTOP, XA(3),YA(3)

      CHARACTER LNTID*20

C  display in order and label bundles 1 thru numdis
      XA(1) = 0.5
      XA(2) = 0.5
      XA(3) = 0.9
      YINCR = 0.8/NUMDIS
      YLOC =  0.9
      NPTS(1) = 3

      DO 300 IX = 1,NUMDIS
         YBOT = YLOC - 0.3*YINCR
         YTOP = YLOC + 0.3*YINCR
         YA(1) = YBOT
         YA(2) = YTOP
         YA(3) = YBOT
         THISET = LEDTYP(PERM(IX))
         WRITE (LNTID, '(A, I4, A)') 'Type#', THISET, ':'
         CALL VISLAB (LNTID(1:10), 'R', 0.05, 0.45, YBOT,YTOP)
         CALL PSEDI (IX)
         CALL PFAS (1, NPTS, XA, YA)
         CALL PSEDR (WKID, IX, PON, THISET, 1.0, 1)
         YLOC = YLOC - YINCR
300   CONTINUE

      END
