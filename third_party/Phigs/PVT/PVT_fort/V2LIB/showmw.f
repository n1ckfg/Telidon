      SUBROUTINE SHOWMW (HDING, MKST, PMCOL, REQMW, EXPMW, NOMMW, PFSW)

C  SHOWMW tests the rendering of a given marker size, and returns the
C  pass/fail result.  The actual marker is drawn using the indicated
C  marker type and color.  Only marker types 2, 3, and 4 are accepted.
C
C  Input parameters:
C    HDING : Title for this test
C    MKST  : Marker type to be used for actual marker
C    PMCOL : Polymarker color index to be used for actual marker
C    REQMW : The marker size (in DC) to be requested.
C    EXPMW : The expected marker size (in DC) - the one which should
C            be realized in order to pass.
C    NOMMW : The nominal marker size
C  Output parameters:
C    PFSW  : Result of the test - P for pass, F for fail, A for abort.

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    IX, NUMALT, ANS, PERM(20), MKST, PMCOL, ERRIND, COMARK
      INTEGER    IDUM1,IDUM2,IDUM3

      REAL       XLOC,YBASE, YLOC, XINCR, MSIZE, PI
      REAL       REQMW, EXPMW, NOMMW, XA(60),YA(60), ALT(10)
      REAL       PMX(1),PMY(1), YGAP, CENTX,CENTY
      REAL       SCRSIZ, SCRX,SCRY, MKRAD

      PARAMETER (PI = 3.14159265)

      LOGICAL    DYN

      CHARACTER  PFSW*1, HDING*(*), MSG*300, DIGIT*1

C  can we fit 4 across in the picture area?
      IF (EXPMW * WCPDC .LT. 0.25) GOTO 50

C  can we fit on the screen as a whole? - if not, quit
      CALL PQDSP (SPECWT, ERRIND, IDUM1, SCRX,SCRY, IDUM2,IDUM3)
      CALL CHKINQ ('pqdsp', ERRIND)
      SCRSIZ = MIN(SCRX,SCRY)
      IF (EXPMW .GT. SCRSIZ) THEN
         PFSW = 'A'
         RETURN
      ENDIF

C  draw on full screen - override view #1
      CALL PSVWI (3)
C  attributes for actual marker
      CALL PSMKSC (REQMW/NOMMW)
      CALL PSMK   (MKST)
      CALL PSPMCI (PMCOL)
      XA(1) = .5
      YA(1) = SYXRAT/2
      CALL PPM (1, XA,YA)

C  MKRAD is simulated marker radius - this works because in
C  view #3, in x-dimension, WC:1 = DC:SCRX
      MKRAD = EXPMW / (2 * SCRX)
      CENTX = .5
      CENTY = SYXRAT/2

C pick comparison marker
      IF (MKST .EQ. POMARK) THEN
         COMARK = PPLUS
      ELSE
         COMARK = POMARK
      ENDIF

      CALL SIMARK (COMARK, PMCOL, MKRAD, CENTX,CENTY)

      MSG = HDING // ': Does the marker fit exactly within the circle?'

      IF (DYN(MSG)) THEN
         PFSW = 'P'
      ELSE
         PFSW = 'F'
      ENDIF
      GOTO 666

50    CONTINUE

C  alt = list of alternative operator choices for marker size
C  numalt = total number of alternative marker sizes generated
      CALL ALTSIZ (EXPMW, QVIS, 0.25 / WCPDC, 4, NUMALT,ALT)

      CALL RNPERM (NUMALT, PERM)

C  draw actual markers and simulate markers of various sizes
      XINCR = 1.0 / NUMALT
      XLOC  = XINCR/2
      YBASE = 0.375
      PMY(1) = YBASE
      YGAP = MAX(1.5 * EXPMW * WCPDC, 0.1)
      YLOC  = YBASE + YGAP
C  attributes for actual marker
      CALL PSMKSC (REQMW/NOMMW)
      CALL PSMK   (MKST)
      CALL PSPMCI (PMCOL)

C  attributes for label
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)

      DO 500 IX = 1,NUMALT
C draw actual marker
         PMX(1) = XLOC
         CALL PPM (1, PMX,PMY)

C  simulate various markers (+,*,o) with polylines
         MSIZE = ALT(PERM(IX)) * WCPDC
         MKRAD = MSIZE / 2
         CALL SIMARK (MKST, PMCOL, MKRAD, XLOC,YLOC)

C  now label
         WRITE (DIGIT, '(I1)') IX
         CALL PTX (XLOC, 0.175, DIGIT)

         XLOC = XLOC + XINCR
500   CONTINUE

      MSG = HDING // ': Which pair of markers has the same size?'
      CALL DCHOIC (MSG, 0,NUMALT, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPCOFL
         PFSW = 'F'
      ELSEIF (PERM(ANS) .EQ. 1) THEN
         PFSW = 'P'
      ELSE
         PFSW = 'F'
      ENDIF
666   CONTINUE
C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      END
