      SUBROUTINE SHPLBW (HDING, WKID, REQLW, EXPLW, NOMLW,
     1                   MINLW, PFSW)

C  SHPLBW tests the rendering of a given linewidth, and returns the
C  pass/fail result.
C
C  Input parameters:
C    HDING : Title for this test
C    WKID  : Workstation identifier
C    REQLW : The linewidth (in DC) to be requested.
C    EXPLW : The expected linewidth (in DC) - the one which should
C            be realized in order to pass.
C    NOMLW : The nominal linewidth
C    MINLW : The minimum linewidth
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

C aspect identifier
      INTEGER    PPMCI,    PTXFN,    PTXPR,    PCHXP,    PCHSP
      PARAMETER (PPMCI= 5, PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9)

      INTEGER    PTXCI,    PIS,      PISI,     PICI,     PEDFG
      PARAMETER (PTXCI=10, PIS  =11, PISI =12, PICI =13, PEDFG=14)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER    IX, NUMALT, ANS, PERM(20), WKID

      REAL       REQLW, EXPLW, NOMLW, MINLW, XA(5),YA(5), ALT(10)
      REAL       XLOC,YBASE, XINCR, FSIZE, XMARG,XLEN,XGAP

      CHARACTER  PFSW*1, HDING*(*), MSG*300, DIGIT*1

      YBASE = 0.2
C  can we fit in top of picture area? - if not, quit
      IF (EXPLW * WCPDC .GT. 1-YBASE) THEN
         PFSW = 'A'
         RETURN
      ENDIF

C  get list of alternate sizes
      CALL ALTSIZ (EXPLW, QVIS, (1.0-YBASE) / WCPDC, 4, NUMALT,ALT)
      CALL RNPERM (NUMALT, PERM)

C  draw actual and simulated lines of various widths
C  first simulated -use individual attributes
      CALL SETASF (PINDIV)
      CALL PSLN   (PLSOLI)
      CALL PSPLCI (1)
      CALL PSLWSC (0.0)
      XINCR = 1.0 / NUMALT
      XLOC  = 0.0
      XMARG =  3*XINCR/25
      XGAP  =    XINCR/25
      XLEN  = (XINCR - XGAP - 2*XMARG) / 2
      YA(2) = YBASE + MINLW * WCPDC / 2
      YA(3) = YA(2)
      DO 500 IX = 1,NUMALT
C  size of linewidth to be simulated - allow for thickness
C  of simulating polylines by subtracting minimum linewidth.
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

C  now actual - use bundle attributes
C  use bundle index #5
      CALL SETASF (PBUNDL)
      CALL PSPLR (WKID, 5, 1, REQLW/NOMLW, 1)
      CALL PSPLI (5)
C  set up text for individual attributes
      DO 110 IX = PTXFN,PTXCI
         CALL PSIASF (IX, PINDIV)
110   CONTINUE
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSCHH  (0.05)
      XLOC = 0.0
      YA(1) = YBASE + EXPLW * WCPDC / 2
      YA(2) = YA(1)
      DO 600 IX = 1,NUMALT
         XA(1) = XLOC + XMARG + XLEN + XGAP
         XA(2) = XA(1) + XLEN
         CALL PPL (2, XA,YA)
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
