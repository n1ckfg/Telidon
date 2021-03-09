      SUBROUTINE LOCANS (YLOC, XVAL)

C  LOCANS draws an annotation text primitive with a distinct
C  annotation point and reference point, at the real y-location
C  corresponding to the integer index given in YLOC.

      INTEGER   YLOC
      REAL      XVAL, YLOCEL, XOFF,YOFF, NPCX,NPCY,NPCPWC

      DATA XOFF /-0.15/, YOFF /0.05/

      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)
      CALL PATR (XVAL-XOFF, YLOCEL(YLOC)-YOFF,
     1           XOFF*NPCPWC,YOFF*NPCPWC, 'Hiho')

      END
