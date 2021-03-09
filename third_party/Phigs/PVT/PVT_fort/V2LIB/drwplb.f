      SUBROUTINE DRWPLB (NUMBUN, BUNDIS, BUNDIF)

C  DRWPLB draws a set of actual polylines using the specified bundle
C  values, and a set of expected polylines, using the attribute
C  values returned by <inquire predefined polyline representation>.
C  It draws the expected polyline incorrectly at the specified
C  position.
C
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of polyline bundle indices to be displayed
C    BUNDIF : position of polyline to be drawn incorrectly

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

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDLT,PDCI, BUNDIF, IX

      REAL     XA(2),YA(2), YINCR,YLOC, PDLW

C  draw and label actual; use individual attributes
      CALL SETASF (PBUNDL)
      XA(1) = 0.25
      XA(2) = 0.55
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.2, YLOC, YINCR)
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PSPLI (BUNDIS(IX))
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
100   CONTINUE

C  now draw expected results - with individual attributes from WDT
C  use individual attributes
      CALL SETASF (PINDIV)
      XA(1) = .6
      XA(2) = .9
      YLOC  = .9

      DO 200 IX = 1, NUMBUN
         CALL PQPPLR (SPECWT, BUNDIS(IX), ERRIND, PDLT, PDLW, PDCI)
         CALL CHKINQ ('pqpplr', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            PDLT = MOD(PDLT,4) + 1
            PDLW = PDLW * 1.5
            PDCI = MOD(PDCI,5) + 1
         ENDIF
         CALL PSLN   (PDLT)
         CALL PSLWSC (PDLW)
         CALL PSPLCI (PDCI)
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

      END
