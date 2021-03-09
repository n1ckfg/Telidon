C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.02.03.02/drwtxt                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE DRWTXT (NUMBUN, BUNDIS, BUNDIF)

C  DRWTXT draws a set of text primitives where the actual texts
C  are drawn using the specified bundle values, and a set of
C  expected text primitives are drawn using the attribute values
C  returned by <inquire predefined text representation>.
C  It draws the expected text primitive incorrectly at the specified
C  position.
C
C  Input parameters:
C    NUMBUN : number of entries in BUNDIS
C    BUNDIS : list of text bundle indices to be displayed
C    BUNDIF : position of text to be drawn incorrectly

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
      INTEGER     PTXFN,    PTXPR,    PCHXP,    PCHSP,     PTXCI
      PARAMETER  (PTXFN= 6, PTXPR= 7, PCHXP= 8, PCHSP= 9,  PTXCI= 10)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER  NUMBUN, BUNDIS(NUMBUN), ERRIND, PDFN, PDPR, PDCI,
     1         BUNDIF, IX

      REAL     YINCR,YLOC, PDEX, PDSP

C  use bundled attributes
      CALL SETASF (PBUNDL)

C  draw and label actual
      YINCR = 0.8/NUMBUN
      YLOC  = 0.9
      CALL PSCHH (0.03)
      CALL PSTXAL (PALEFT, PAHALF)
      CALL NUMLAB (NUMBUN, 0.15, YLOC, YINCR)
      DO 100 IX = 1,NUMBUN
         CALL PSTXI (BUNDIS(IX))
         CALL PTX (0.25, YLOC, 'Phigs')
         YLOC  = YLOC-YINCR
100   CONTINUE

C  now draw expected results - with individual attributes from WDT
C  use individual attributes
      CALL SETASF (PINDIV)
      YLOC  = 0.9
      DO 200 IX = 1, NUMBUN
         CALL PQPTXR (SPECWT, BUNDIS(IX), ERRIND, PDFN, PDPR, PDEX,
     1                PDSP, PDCI)
         CALL CHKINQ ('pqptxr', ERRIND)
         IF (IX .EQ. BUNDIF) THEN
            IF (PDFN .EQ. 1) THEN
               PDFN = 2
            ELSE
               PDFN = 1
            ENDIF
         ENDIF
         CALL PSTXFN (PDFN)
         CALL PSTXPR (PDPR)
         CALL PSCHXP (PDEX)
         CALL PSCHSP (PDSP)
         CALL PSTXCI (PDCI)
         CALL PTX (0.6, YLOC, 'Phigs')
         YLOC  = YLOC-YINCR
200   CONTINUE
      END
