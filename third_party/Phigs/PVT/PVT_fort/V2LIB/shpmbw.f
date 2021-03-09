      SUBROUTINE SHPMBW (HDING, WKID, REQMW, EXPMW, NOMMW, PFSW)

C  SHPMBW tests the rendering of a given marker size, and returns the
C  pass/fail result.
C
C  Input parameters:
C    HDING : Title for this test
C    WKID  : Workstation identifier
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

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

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

      INTEGER    IX, NUMALT, RNDINT, ANS, PERM(20), WKID
      INTEGER    MKST, ERRIND, IDUM1,IDUM2,IDUM3

      REAL       REQMW, EXPMW, NOMMW, XA(60),YA(60), ALT(10)
      REAL       XLOC,YBASE, YLOC, XINCR, MSIZE
      REAL       PMX(1),PMY(1), YGAP, CENTX,CENTY
      REAL       SCRSIZ, SCRX,SCRY, MKRAD

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
C  use ASFs bundled
      CALL SETASF (PBUNDL)
C  attributes for actual marker, use index #13
      CALL PSPMR (WKID, 13, PPLUS, REQMW/NOMMW, 1)
      XA(1) = .5
      YA(1) = SYXRAT/2
      CALL PSPMI (13)
      CALL PPM (1, XA,YA)

C  MKRAD is simulated marker radius - this works because in
C  view #3, in x-dimension, WC:1 = DC:SCRX
      MKRAD = EXPMW / (2 * SCRX)
      CENTX = .5
      CENTY = SYXRAT/2
C  simulate circle to surround non-circle marker
      CALL SIMARK (POMARK, 1, MKRAD, CENTX,CENTY)

      IF (DYN('Does the marker fit exactly within the circle?')) THEN
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
C  bundle for actual marker, use bundle 17
C  pick a marker between 2 and 4
      MKST = RNDINT(2,4)
      CALL PSPMR (WKID, 17, MKST, REQMW/NOMMW, 1)
      CALL PSPMI (17)
C  attributes for label
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)

      DO 500 IX = 1,NUMALT
C  reset  to bundled, since SIMARK uses individual
         CALL SETASF (PBUNDL)
C draw actual marker
         PMX(1) = XLOC
         CALL PPM (1, PMX,PMY)

C  simulate marker with polylines
         MSIZE = ALT(PERM(IX)) * WCPDC
         MKRAD = MSIZE / 2
         CALL SIMARK (MKST, 1, MKRAD, XLOC,YLOC)
C  now label
         WRITE (DIGIT, '(I1)') IX
         CALL PTX (XLOC, 0.175, DIGIT)

         XLOC = XLOC + XINCR
500   CONTINUE

      MSG = HDING // ': Which pair of markers has the same size?'
      CALL DCHOIC (MSG, 0,NUMALT, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPCOMT
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
