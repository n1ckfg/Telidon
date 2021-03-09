      SUBROUTINE DRWEDB (NUMBUN, BUNDIS, BUNDIF, NUMET)

C  DRWEDB draws a set of actual edges using the specified bundle
C  values, and a set of expected edges, using the attribute
C  values returned by <inquire predefined edge representation>.
C  It draws the expected edge incorrectly at the specified
C  position.
C
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of edge bundle indices to be displayed
C    BUNDIF : position of edge to be drawn incorrectly
C    NUMET  : number of edge types

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDEF, PDET, PDCI
      INTEGER  BUNDIF, IX, NPTS(1), NUMET

      REAL     XA(4),YA(4), YINCR,YLOC, PDEW

C  draw triangles to display edge
      NPTS(1) = 3

C  draw and label actual
      CALL DRBUED (NUMBUN, BUNDIS)

C  now draw expected results - with individual attributes from WDT
C  use individual attributes
      CALL SETASF (PINDIV)
      XA(1) = .6
      XA(2) = .6
      XA(3) = .9
      YLOC  = .9
      YINCR = 0.8/NUMBUN

      DO 200 IX = 1, NUMBUN
         CALL PQPEDR (SPECWT, BUNDIS(IX), ERRIND,
     1                PDEF, PDET, PDEW, PDCI)
         CALL CHKINQ ('pqpedr', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            IF (NUMET .EQ. 1) THEN
C  switch edge flag
               IF (PDEF .EQ. PON) THEN
                  PDEF = POFF
               ELSE
                  PDEF = PON
               ENDIF
            ENDIF
            PDET = MOD(PDET, 4) + 1
            PDEW = PDEW * 1.3
            PDCI = MOD(PDCI, 5) + 1
         ENDIF
         CALL PSEDFG (PDEF)
         CALL PSEDT  (PDET)
         CALL PSEWSC (PDEW)
         CALL PSEDCI (PDCI)

         YA(1) = YLOC - 0.25*YINCR
         YA(2) = YLOC + 0.25*YINCR
         YA(3) = YLOC - 0.25*YINCR

         CALL PFAS  (1, NPTS, XA,YA)
         YLOC  = YLOC-YINCR
200   CONTINUE

      END
