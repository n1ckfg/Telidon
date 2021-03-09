      SUBROUTINE COLPCH (FILMOD, CLOR, XLO,YLO,XHI,YHI)

C  COLPCH will generate a rectangular color patch with the specified
C  diagonal vertices.  It will use solid interior fill area or
C  polylines based on the specified filling mode.

C  Input parameters:
C    FILMOD          : use fill area if true, otherwise polyline
C    CLOR            : color index to use
C    XLO,YLO,XHI,YHI : extent of the rectangle

      INTEGER    CLOR

      REAL       FILX(4), FILY(4), YINC, XLO,XHI,YLO,YHI, YVAL

      LOGICAL    FILMOD

C  interior style hollow, solid,    pattern,  hatch,    empty
      INTEGER   PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER(PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)
C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

      FILX(1) = XLO
      FILX(2) = XHI
      FILX(3) = XHI
      FILX(4) = XLO

      IF (FILMOD) THEN
         FILY(1) = YLO
         FILY(2) = YLO
         FILY(3) = YHI
         FILY(4) = YHI

         CALL PSIS  (PSOLID)
         CALL PSICI (CLOR)
         CALL PFA   (4, FILX,FILY)
      ELSE
         CALL PSLN   (PLSOLI)
         CALL PSPLCI (CLOR)
C  paint lines at the rate of about 400/screen
         YINC = 1.0/400
         DO 100 YVAL = YLO, YHI, YINC
           FILY(1) = YVAL
           FILY(2) = YVAL
           CALL PPL (2, FILX,FILY)
  100    CONTINUE
      ENDIF

      END
