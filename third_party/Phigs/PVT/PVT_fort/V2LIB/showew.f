      SUBROUTINE SHOWEW (HDING, REQEW, EXPEW, NOMEW,
     1                   MINLW, PFSW)

C  SHOWEW tests the rendering of a given edgewidth, and returns the
C  pass/fail result, or an abort signal if the requested edge is
C  too wide to be tested.

C
C  Input parameters:
C    HDING : Title for this test
C    REQEW : The edgewidth (in DC) to be requested.
C    EXPEW : The expected edgewidth (in DC) - the one which should
C            be realized in order to pass.
C    NOMEW : The nominal edgewidth
C    MINLW : The minimum linewidth (used for simulation)
C  Output parameters:
C    PFSW  : Result of the test - P:pass, F:fail, A:abort.

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C edge-, line-type
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C edge flag indicator
      INTEGER    POFF,    PON
      PARAMETER (POFF=0, PON=1)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    IX, NUMALT, ANS, PERM(20)
      INTEGER    NPTS(1)

      REAL       REQEW, EXPEW, NOMEW, MINLW, XA(5),YA(5),ZA(5)
      REAL       XLOC,YBASE, XINCR, FSIZE, XMARG,XLEN,XGAP,  ALT(10)

      CHARACTER  PFSW*1, HDING*(*), MSG*300, DIGIT*1

      YBASE = 0.2
C  can we fit in top of picture area? - if not, quit
      IF (EXPEW * WCPDC .GT. 1-YBASE) THEN
         PFSW = 'A'
         RETURN
      ENDIF

C  get list of alternate sizes
      CALL ALTSIZ (EXPEW, QVIS, (1.0-YBASE) / WCPDC, 4, NUMALT,ALT)
      CALL RNPERM (NUMALT, PERM)

C  draw actual and simulated edges of various widths

C  first simulated
      CALL PSLN (PLSOLI)
      CALL PSPLCI (1)
      CALL PSLWSC (0.0)
      XINCR = 1.0 / NUMALT
      XLOC  = 0.0
      XGAP  = XINCR/25
      XMARG = 3*XGAP
      XLEN  = (XINCR - XGAP - 2*XMARG) / 2
      YA(2) = YBASE + MINLW * WCPDC / 2
      YA(3) = YA(2)
      DO 500 IX = 1,NUMALT
C  size of linewidth to be simulated - allow for thickness
C  of simulating edge by subtracting minimum edgewidth.
         FSIZE = (ALT(PERM(IX))-MINLW) * WCPDC
         YA(1) = YA(2) + FSIZE
         YA(4) = YA(1)
         YA(5) = YA(1)
         XA(1) = XLOC + XMARG
         XA(2) = XA(1)
         XA(5) = XA(1)
         XA(3) = XA(1) + XLEN
         XA(4) = XA(3)
         CALL PPL (5, XA,YA)
         XLOC = XLOC + XINCR
500   CONTINUE
C  now actual
      CALL PSEWSC (REQEW/NOMEW)
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)
      XLOC = 0.0
      ZA(1) = 0.5
      ZA(2) = 0.9
      ZA(3) = ZA(2)
      ZA(4) = ZA(1)
      YA(1) = YBASE + EXPEW * WCPDC/2
      YA(2) = YA(1)
      YA(3) = YA(1)
      YA(4) = YA(1)
      NPTS(1) = 4

      DO 600 IX = 1,NUMALT
C  offset 2nd and 4th point slightly so that Z-oriented edges (1-2 and
C  3-4) project to a short horizontal line, rather than to a point.
         XA(1) = XLOC + XMARG + XGAP + XLEN
         XA(2) = XA(1) + XLEN/100
         XA(3) = XA(1) + XLEN
         XA(4) = XA(3) - XLEN/100
         CALL PFAS3 (1, NPTS, XA,YA,ZA)
         WRITE (DIGIT, '(I1)') IX
         CALL PTX (XLOC + XINCR/2, YBASE - 0.05, DIGIT)
         XLOC = XLOC + XINCR
600   CONTINUE

      MSG = HDING // ': Which pair has the same vertical thickness?'

      CALL DCHOIC (MSG, 0,NUMALT, ANS)
      IF (ANS .EQ. 0) THEN
         CALL OPCOFL
         PFSW = 'F'
      ELSEIF (PERM(ANS) .EQ. 1) THEN
         PFSW = 'P'
      ELSE
         PFSW = 'F'
      ENDIF

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      END
