      SUBROUTINE DRBUED (NUMBUN, BUNDIS)

C  DRBUED draws a set of edges using the specified edge bundle
C  values.

C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of edge bundle indices to be displayed

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER  NUMBUN, BUNDIS(NUMBUN),IX, NPTS(1)

      REAL     XA(4),YA(4), YINCR,YLOC

      NPTS(1) = 3
      XA(1) = 0.25
      XA(2) = 0.25
      XA(3) = 0.55
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.2, YLOC, YINCR)
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC - 0.25*YINCR
         YA(2) = YLOC + 0.25*YINCR
         YA(3) = YLOC - 0.25*YINCR
         CALL PSEDI(BUNDIS(IX))
         CALL PFAS  (1, NPTS, XA, YA)
         YLOC  = YLOC-YINCR
100   CONTINUE

      END
