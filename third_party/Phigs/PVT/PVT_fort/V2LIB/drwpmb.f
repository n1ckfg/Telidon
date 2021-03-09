      SUBROUTINE DRWPMB (NUMBUN, BUNDIS, BUNDIF)

C  DRWPMB draws a set of actual polymarkers using the specified bundle
C  values, and a set of expected polymarkers, using the attribute
C  values returned by <inquire predefined polymarker representation>.
C  It draws the expected polymarker incorrectly at the specified
C  position.
C
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of polymarker bundle indices to be displayed
C    BUNDIF : position of polymarker to be drawn incorrectly

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

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDMT,PDCI, BUNDIF, IX

      REAL     XA(1),YA(1), YINCR,YLOC, PDMW

C  draw and label actual; use ASFs bundle
      CALL SETASF (PBUNDL)
      XA(1) = 0.4
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.2, YLOC, YINCR)
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC
         CALL PSPMI (BUNDIS(IX))
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
100   CONTINUE

C  now draw expected  results - with individual attributes from WDT
      CALL SETASF (PINDIV)
      XA(1) = .7
      YLOC  = .9

      DO 200 IX = 1, NUMBUN
         CALL PQPPMR (SPECWT, BUNDIS(IX), ERRIND, PDMT, PDMW, PDCI)
         CALL CHKINQ ('pqppmr', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            PDMT = MOD(PDMT,5) + 1
            PDMW = PDMW * 1.5
            PDCI = MOD(PDCI,5) + 1
         ENDIF
         CALL PSMK   (PDMT)
         CALL PSMKSC (PDMW)
         CALL PSPMCI (PDCI)
         YA(1) = YLOC
         CALL PPM  (1, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

      END
