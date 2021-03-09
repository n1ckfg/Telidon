      LOGICAL FUNCTION UNDCMD (NUMMOD,MODLIS,HICOL,PROMPT)

C  UNDCMD tests the list of color models passed in by requesting
C  dimensions and drawing color patches using those dimensions.
C  The operator is asked if the displayed color matches the
C  randomly chosen color coordinates.

C  Input parameters:
C    NUMMOD :  Size of list of color models
C    MODLIS :  Entire list of color models which may be tested
C    HICOL  :  Highest color index to be used
C    PROMPT :  String for prompt, indicating documentation to
C              be used for reference

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C  interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C     type of returned values set, realized
      INTEGER    PSET,   PREALI
      PARAMETER (PSET=0, PREALI=1)

      INTEGER   CMDIM, NUMCM, COLIX, NUMCL, RANLIS(8), NUMTST
      INTEGER   CM, ICM, II, IX, ITRIM, POS1, NUMMOD, MODLIS(*), HICOL

      REAL      LO(8), HI(8), ACTCOL(8), COLARY(8)
      REAL      YLO,YHI, YTOP, YINCR, RNDRL

      CHARACTER CVAL*5, MSG*200, PROMPT*(*), RVALS*80

      LOGICAL   DYN, FILMOD, INTSTY, LOMAG

C  Determine how to fill in rectangles, use solid style
C  if it is available, otherwise use dense polyline cross-hatch
      FILMOD = INTSTY(SPECWT, PSOLID)
C  number of models to test
      NUMTST = MIN(8, NUMMOD)
C  Test a random subset of the models if > 8
      CALL RNSET (NUMTST,NUMMOD,RANLIS)

      DO 140 ICM = 1,NUMTST
         CALL PEMST (102)
C  Set Color Model
         CM = MODLIS(RANLIS(ICM))
         CALL PSCMD (WKID, CM)

         WRITE (CVAL, '(I5)') CM
         CALL DCHOIC ('DIMENSION OF COLOUR MODEL: How many '   //
     1                'dimensions are there for colour model ' //
     2                CVAL // '?', 0,100, CMDIM)

         IF (CMDIM .EQ. 0) THEN
            CALL INMSG ('Operator reported zero dimensions for a ' //
     1                  'color model.')
            UNDCMD = .FALSE.
            RETURN
         ENDIF

C  determine format for displaying color coordinates
         LOMAG = .TRUE.
         DO 100 IX = 1, CMDIM
            WRITE(CVAL, '(I5)') IX
            CALL DRLVAL('DIMENSION BOUNDS: Enter the LOWER limit ' //
     1                  'for valid values for dimension # '        //
     2                  CVAL, LO(IX))
            CALL DRLVAL('DIMENSION BOUNDS: Enter the UPPER limit ' //
     1                  'for valid values for dimension # '        //
     2                  CVAL, HI(IX))
            IF (ABS (LO(IX)) .GE. 10.0) LOMAG = .FALSE.
            IF (ABS (HI(IX)) .GE. 10.0) LOMAG = .FALSE.
100      CONTINUE

C  Draw color patches down left side of screen:
         NUMCM = HICOL - 1
         YINCR = 1.0 / (NUMCM + 1.0)
         YTOP  = 1 - YINCR
         YLO   = YTOP - 0.25*YINCR
         YHI   = YTOP + 0.25*YINCR
         CALL NUMLAB (NUMCM, 0.15, YTOP, YINCR)

         DO 130, COLIX = 2, HICOL
            DO 110 IX = 1, CMDIM
               COLARY(IX) = RNDRL(LO(IX),HI(IX))
110         CONTINUE

            CALL PSCR (WKID, COLIX, CMDIM, COLARY)
C  determine actual colval
            CALL PQCR (WKID,COLIX, CMDIM, PREALI, ERRIND, NUMCL,ACTCOL)
            CALL CHKINQ ('pqcr', ERRIND)

            IF (NUMCL .NE. CMDIM) THEN
               WRITE (MSG, '(A,I5,A,I5,A,I5,A)') 'Reported ' //
     1                'dimensionality for color model #', CM, ' is ',
     2                NUMCL, '; does not match value specified by ' //
     3                'operator = ', CMDIM, '.'
               CALL INMSG (MSG)
               UNDCMD = .FALSE.
               RETURN
            ENDIF

            CALL COLPCH (FILMOD, COLIX, 0.2, YLO, 0.5, YHI)
C  format color coordinates for printing
            RVALS = ' '
            DO 120 II = 1, NUMCL
               IF (LOMAG) THEN
                  POS1 = 6*II - 5
                  WRITE (RVALS(POS1:POS1+5), '(A,F5.2)') ',', ACTCOL(II)
               ELSE
                  POS1 = 10*II - 9
                  WRITE (RVALS(POS1:POS1+9), '(A,E9.2)') ',', ACTCOL(II)
               ENDIF
120         CONTINUE
            CALL VISLAB (RVALS(2:ITRIM(RVALS)), 'L', 0.55,0.95, YLO,YHI)

            YLO = YLO-YINCR
            YHI = YHI-YINCR

C  next random color within color model
130      CONTINUE

         WRITE (MSG, '(A,I5,A,A,A)') 'ACCURACY OF COLOUR MODEL: '  //
     1          'Are the colours of the rectangles compatible '    //
     2          'with the corresponding colour coordinate values ' //
     3          'within colour model #', CM, ', according to the ',
     4          PROMPT, '?'

         IF (DYN (MSG)) THEN
C           OK so far
         ELSE
            WRITE (CVAL, '(I5)') CM
            CALL INMSG ('Color Model #' // CVAL // ' caused failure.')
            UNDCMD = .FALSE.
            RETURN
         ENDIF
C  next color model
140   CONTINUE
      UNDCMD = .TRUE.

      END
