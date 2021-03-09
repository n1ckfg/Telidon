      SUBROUTINE TXEXAL (TXFONT, TXPATH, TXSTR,
     1                   NTXWD, NTXHT, HTAB, VTAB)

C  TXEXAL returns not only the size of the nominal text extent
C  rectangle, but also the location within it of the various text
C  alignment positions.

C  Input parameters:
C    TXFONT : text font to be used for inquiry
C    TXPATH : text path to be used for inquiry
C    TXSTR  : text string to be used for inquiry
C  Output parameters:
C    NTXWD  : nominal width of text rectangle
C    NTXHT  : nominal height of text rectangle
C    HTAB   : nominal position of horizontal text alignments
C    VTAB   : nominal position of vertical text alignments

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)

      INTEGER    TXFONT, TXPATH, ERRIND, IX

      REAL       NTXWD, NTXHT, HTAB(PALEFT:PARITE), VTAB(PATOP:PABOTT)
      REAL       TXRX(2),TXRY(2), RDUM1,RDUM2

      CHARACTER  TXSTR*(*)

      CALL PQTXX  (SPECWT, TXFONT, 1.,0.,1., TXPATH, PALEFT, PABOTT,
     1             TXSTR, ERRIND, TXRX,TXRY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      NTXWD = ABS(TXRX(2) - TXRX(1))
      NTXHT = ABS(TXRY(2) - TXRY(1))

C  save normalized heights in table:
      DO 100 IX = PATOP, PABOTT
         CALL PQTXX  (SPECWT, TXFONT, 1.,0.,1., TXPATH, PALEFT, IX,
     1                TXSTR, ERRIND, TXRX,TXRY, RDUM1,RDUM2)
         CALL CHKINQ ('pqtxx', ERRIND)
         VTAB(IX) = NTXHT - TXRY(2)
100   CONTINUE

C  save normalized widths in table:
      HTAB(PALEFT) = 0.0
      HTAB(PACENT) = NTXWD/2
      HTAB(PARITE) = NTXWD

      END
