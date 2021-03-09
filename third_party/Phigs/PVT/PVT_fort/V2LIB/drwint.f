      SUBROUTINE DRWINT (NUMBUN, BUNDIS, BUNDIF)

C  DRWINT draws a set of rectangles where the actual interiors
C  are drawn using the specified bundle values, and a set of
C  expected interiors are drawn using the attribute values
C  returned by <inquire predefined interior representation>.
C  It draws the expected interior incorrectly at the specified
C  position.
C
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of interior bundle indices to be displayed
C    BUNDIF : position of interior to be drawn incorrectly

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
C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDIS, PDISI,
     1         PDCI, BUNDIF, IX, SIZ, NPTS(1)

      REAL     XA(5),YA(5), YINCR,YLOC

C  use bundled attributes, except for edge attributes
      CALL SETASF (PBUNDL)
C  to ensure edges predictable - set ASF individual:
C  set edge flag (pedfg=14) = off
      CALL PSIASF (14, PINDIV)
      CALL PSEDFG (0)

C  draw and label actual
      CALL SETRVS ('0.2, 0.2, 0.45, 0.45', XA, SIZ)
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL NUMLAB (NUMBUN, 0.15, YLOC, YINCR)
      NPTS(1) = 4
      DO 100 IX = 1,NUMBUN
         YA(1) = YLOC - 0.3*YINCR
         YA(2) = YLOC + 0.3*YINCR
         YA(3) = YA(2)
         YA(4) = YA(1)
         YA(5) = YA(1)
         CALL PSII (BUNDIS(IX))
C switch between fill area and fill area set
         IF (MOD(IX,2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (4, XA, YA)
         ENDIF
         YLOC  = YLOC-YINCR
100   CONTINUE

C  now draw expected results - with individual attributes from WDT
C  use individual attributes
      CALL SETASF (PINDIV)
      CALL SETRVS ('0.6, 0.6, 0.85, 0.85', XA, SIZ)
      YLOC  = .9
      DO 200 IX = 1, NUMBUN
         CALL PQPIR (SPECWT, BUNDIS(IX), ERRIND, PDIS, PDISI, PDCI)
         CALL CHKINQ ('pqpir', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            IF (PDIS .EQ. PHOLLO) THEN
               PDIS = PISEMP
            ELSE
               PDIS = MOD(PDIS,4) + 1
            ENDIF
            PDISI = MOD(PDISI,4) +1
            PDCI = MOD(PDCI,5) + 1
         ENDIF
         CALL PSIS   (PDIS)
         CALL PSISI (PDISI)
         CALL PSICI (PDCI)
         YA(1) = YLOC - 0.3*YINCR
         YA(2) = YLOC + 0.3*YINCR
         YA(3) = YA(2)
         YA(4) = YA(1)
C switch between fill area and fill area set
         IF (MOD(IX, 2) .EQ. 0) THEN
            CALL PFAS (1, NPTS, XA, YA)
         ELSE
            CALL PFA (4, XA, YA)
         ENDIF
         YLOC  = YLOC-YINCR
200   CONTINUE

      END
