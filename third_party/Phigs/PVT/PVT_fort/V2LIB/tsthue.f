      INTEGER FUNCTION TSTHUE (PRMPT, FILMOD, NUMSET, LSCOLI)

C  TSTHUE displays NUMSET colors, starting with #2, using LSCOLI as
C  color indices.  It then asks the operator to identify these and
C  issues 1 (pass), -1 (fail), or -2 (fail with comment), as a result.
C
C  Input parameters:
C    PRMPT  : prompt for the operator
C    FILMOD : fill mode for rectangle; true for solid fill area,
C             false for polylines
C    NUMSET : number of colored rectangles to be drawn
C    LSCOLI : list of identifiers from color palette

      INTEGER   NUMSET, LSCOLI(*), IX, ANSSIZ, ANSLIS(20)

      REAL      YTOP, YINCR, YVAL

      LOGICAL   FILMOD, IAREQL

      CHARACTER PRMPT*(*)

      YINCR = 1.0 /(NUMSET+1)
      YTOP  = 1-YINCR
      YVAL  = YTOP - 0.25*YINCR

      DO 120 IX = 1,NUMSET
         CALL COLPCH (FILMOD, IX+1, .25,YVAL, .75,YVAL + 0.5*YINCR)
         CALL PSPLCI (1)
         CALL DRWREC (.25,.75, YVAL,YVAL + 0.5*YINCR)
         YVAL = YVAL-YINCR
120   CONTINUE

      CALL DILIST (PRMPT, ANSSIZ, ANSLIS)
      IF (ANSSIZ.EQ.1 .AND. ANSLIS(1).EQ.0) THEN
         TSTHUE = -2
      ELSEIF (IAREQL (ANSSIZ,ANSLIS, NUMSET,LSCOLI)) THEN
         TSTHUE = 1
      ELSE
         TSTHUE = -1
      ENDIF

      CALL PEMST (102)

      END
