      SUBROUTINE CLPMK5 (DIM, MCVND, XF, INXF,OUTXF)

C  CLPMK5 generates a 5x5 grid of polymarkers, some of which should be
C  clipped (X style) and some of which should be visible (+ style) and then
C  passes or fails based on operator response.

C  Input parameters:
C    DIM   : dimensionality of test (2 or 3)
C    XF    : transformation to be applied to clipping plane
C    INXF  : transformation to apply to marker to put it inside MCV
C    OUTXF : transformation to apply to marker to put it outside MCV
C    MCVND : half-space for MCV, in 3D or 2D format

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

C modelling clipping operator
C                replace     intersect
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)

C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER    IX, VISCT, RNDINT

      REAL       XF(4,4), INXF(4,4), OUTXF(4,4), PTXVEC(6)
      REAL       A,B,C,D, XX,YY, XA(3), YA(3), ZA(3), PI, MCVND(6,1)
      PARAMETER (PI = 3.14159265)

      LOGICAL    DYN, INMCV, NCLIPD

      CHARACTER  DIM*1

C  a,b,c,d = coefficients of transformed boundary plane
      DO 100 IX=1,6
         PTXVEC(IX) = MCVND(IX,1)
100   CONTINUE

      IF (DIM .EQ. '2') THEN
C  two-dimensionalize
         PTXVEC(6) = 0.0
         PTXVEC(5) = MCVND(4,1)
         PTXVEC(4) = MCVND(3,1)
         PTXVEC(3) = 0.0
      ELSEIF (DIM .EQ. '3') THEN
C        OK as is
      ELSE
         CALL UNMSG ('CLPMK5 called with DIM = ' // DIM // '.')
      ENDIF
      CALL TRANHS (PTXVEC, XF, A,B,C,D)

C  visct = number of polymarkers which should be visible
      VISCT = 0

      DO 10 XX = 0.1, 1.0, 0.2
      DO 20 YY = 0.1, 1.0, 0.2
         INMCV  = RNDINT(1,3) .EQ. 1
         NCLIPD = RNDINT(1,2) .EQ. 1
         XA(1) = XX
         YA(1) = YY
         ZA(1) = (-A*XX - B*YY - D) / C

         IF (INMCV) THEN
            CALL PSLMT3 (INXF,PCREPL)
         ELSE
            CALL PSLMT3 (OUTXF,PCREPL)
         ENDIF

         IF (NCLIPD) THEN
            CALL PSMCLI (PNCLIP)
         ELSE
            CALL PSMCLI (PCLIP)
         ENDIF

         IF (INMCV .OR. NCLIPD) THEN
C  should be visible
            CALL PSPMCI (2)
            CALL PSMK (PPLUS)
            VISCT = VISCT + 1
         ELSE
C  should be invisible
            CALL PSPMCI (3)
            CALL PSMK (PXMARK)
         ENDIF

         CALL PPM3 (1, XA,YA,ZA)
20    CONTINUE
10    CONTINUE

      IF (DYN (DIM // 'D GEOMETRY OF CLIPPING VOLUME: Is plus (+) ' //
     1         'the type of all visible markers?')) THEN
C        OK so far
      ELSE
         CALL FAIL
         GOTO 380
      ENDIF

      CALL DCHPFV (DIM // 'D GEOMETRY OF CLIPPING VOLUME: ' //
     1             'How many markers are visible?', 100, VISCT)

380   CONTINUE
      CALL PEMST (102)

      END
