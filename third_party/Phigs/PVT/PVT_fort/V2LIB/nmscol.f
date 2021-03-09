      SUBROUTINE NMSCOL (WKID)

C  Subroutine NMSCOL sets the workstation color indices for the
C  specified colors.  If the station does not support color, all
C  indices are set to 1 (the foreground color).
C
C  Input parameter:
C    WKID:  workstation identifier

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      COMMON    /COLORS/ BLACK, GREEN, YELLOW, WHITE, BLUE
      INTEGER    BLACK, GREEN, YELLOW, WHITE, BLUE

      INTEGER    WKID, MAXCOL, ERRIND
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C Colors
      REAL       BLCK(3), GRN(3), YELLW(3), WHT(3), BLU(3)

      DATA BLCK  / 0., 0., 0./
      DATA GRN   / 0., 1., 0./
      DATA YELLW / 1., 1., 0./
      DATA WHT   / 1., 1., 1./
      DATA BLU   / 0., 0., 1./

C  maxcol = maximum size of color table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             MAXCOL, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  If workstation allows, set up its color table with entries:
C  color index   RGB        color
C  -----------   ---        -----
C     0          0,0,0      black
C     1          0,1,0      green
C     2          1,1,0      yellow
C     3          1,1,1      white
C     4          0,0,1      blue
C
      IF (MAXCOL .GT. 4) THEN
C  set color model = rgb
         CALL PSCMD (WKID, PRGB)
C  Set representation for workstation
         BLACK   = 0
         GREEN   = 1
         YELLOW  = 2
         WHITE   = 3
         BLUE    = 4
         CALL PSCR (WKID, BLACK,  3, BLCK)
         CALL PSCR (WKID, GREEN,  3, GRN)
         CALL PSCR (WKID, YELLOW, 3, YELLW)
         CALL PSCR (WKID, WHITE,  3, WHT)
         CALL PSCR (WKID, BLUE,   3, BLU)

      ELSE

C  MONO set for only 2 colors
         BLACK   = 0
         GREEN   = 1
         YELLOW  = 1
         WHITE   = 1
         BLUE    = 1
      ENDIF

      END
