C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.04.02/tsthlf                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTHLF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C  TSTHLF tests that the appropriate primitives are highlighted for
C  a given inclusion and exclusion set used as the highlighting
C  filter.

C  Input parameters:
C    WKID          : workstation identifier
C    INCSIZ,INCSET : inclusion set
C    EXCSIZ,EXCSET : exclusion set

      INTEGER  WKID, INCSIZ,INCSET(*), EXCSIZ,EXCSET(*)
      INTEGER  TRUSIZ,TRULIS(8)

C  <set highlighting filter>:
      CALL PSHLFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  Compute expected subset of highlighted primitives from incl,excl
      CALL ELGPRM (INCSIZ,INCSET, EXCSIZ,EXCSET, TRUSIZ,TRULIS)

      CALL DLSTPF ('HIGHLIGHTING FILTER: For which pairs is the '  //
     1             'primitive on the left highlighted (n if none)?',
     2             TRUSIZ, TRULIS, 'S')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.04.02/tstivf                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTIVF (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)

C  TSTIVF tests that the appropriate primitives are invisible for
C  a given inclusion and exclusion set used as the invisibility
C  filter.

C  Input parameters:
C    WKID          : workstation identifier
C    INCSIZ,INCSET : inclusion set
C    EXCSIZ,EXCSET : exclusion set

      INTEGER  WKID, INCSIZ,INCSET(*), EXCSIZ,EXCSET(*)
      INTEGER  TRUSIZ,TRULIS(8)

C  <set invisibility filter>:
      CALL PSIVFT (WKID, INCSIZ,INCSET, EXCSIZ,EXCSET)
C  Compute expected subset of invisible primitives from incl,excl
      CALL ELGPRM (INCSIZ,INCSET, EXCSIZ,EXCSET, TRUSIZ,TRULIS)

      CALL DLSTPF ('INVISIBILITY FILTER: Which primitives are ' //
     1             'invisible (n if none)?', TRUSIZ, TRULIS, 'S')

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.04.02/nmscol                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.04.02/elgprm                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ELGPRM (INCSIZ,INCSET, EXCSIZ,EXCSET, TRUSIZ,TRULIS)

C  Subroutine ELGPRM determines the eligible primitives for the
C  given inclusion and exclusion set. The eligible primitives are
C  returned in TRULIS.

C  Input parameters:
C    INCSIZ,INCSET : inclusion set
C    EXCSIZ,EXCSET : exclusion set
C  Output parameters:
C    TRUSIZ,TRULIS : list of eligible primitives

      INTEGER INCSIZ,INCSET(*), EXCSIZ,EXCSET(*), TRUSIZ,TRULIS(*)

      INTEGER SVAL, IX, PRIMID, LIST(8)

C   Check the include and exclude sets to determine which
C   of the following primitives will be highlighted.

C   position  primitive        color   nameset
C     1       polyline           1      0, 1, 2
C     2       polymarker         2      3, 4, 5
C     3       fill area          3      6, 7, 8
C     4       cell array         4      9,10,11
C     5       text               1     12,13,14
C     6       polyline 3         2     15,16,17
C     7       annotation text    3     18,19,20
C     8       fill area set      4     21,22,23

C   First check the inclusion set, include any primitive that
C   appears, then check the exclusion set, removing any primitive
C   that appears, the set we are left with are the eligible ones.
C   Names outside of 0-23 are ignored.

      CALL SETVAL ('0,0,0,0,0,0,0,0', LIST)

      DO 100 IX = 1,INCSIZ
         SVAL = INCSET(IX) 
         IF (SVAL.GE.0 .AND. SVAL.LE.23) THEN
            PRIMID = SVAL/3 + 1
            LIST(PRIMID) =  1
         ENDIF
  100 CONTINUE

      DO 110 IX = 1,EXCSIZ
         SVAL = EXCSET(IX) 
         IF (SVAL.GE.0 .AND. SVAL.LE.23) THEN
            PRIMID = SVAL/3 + 1
            LIST(PRIMID) =  0
         ENDIF
  110 CONTINUE

      TRUSIZ = 0
      DO 120 IX = 1,8
         IF (LIST(IX) .EQ. 1) THEN
            TRUSIZ = TRUSIZ + 1
            TRULIS(TRUSIZ) = IX
         ENDIF
  120 CONTINUE

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 04.03.04.02/nmsprm                      *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE NMSPRM (HLIGHT)

C  Subroutine NMSPRM will draw the eight primitives for possible
C  invisibility or highlighting (2 copies of each for the latter)
C  down the screen and label each with the appropriate nameset.

      COMMON   /COLORS/ BLACK, GREEN, YELLOW, WHITE, BLUE
      INTEGER           BLACK, GREEN, YELLOW, WHITE, BLUE

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

      INTEGER      SETSIZ
      PARAMETER   (SETSIZ=3)

      INTEGER    NAMES(SETSIZ), COLIA(3,3), IXA(1)
      REAL       XVAL(4), YVAL(4), ZVAL(4), YTOP, YPOS8
      REAL       Y1, Y2, X1, X2, X3, X4, X5, X6, X7, X8, YINCR
      REAL       Z, NPCX,NPCY, NPCPWC
      PARAMETER (Z = 0.0)

      LOGICAL    HLIGHT

      DATA COLIA  /2,1,2,1,2,1,2,2,1/

C  Set up structure of primitives to be displayed, numbered 1-8 down
C  the screen:
C  number   primitive        color    nameset
C  ------   ---------        -----    -------
C     1     polyline           1      0, 1, 2
C     2     polymarker         2      3, 4, 5
C     3     fill area          3      6, 7, 8
C     4     cell array                9,10,11
C     5     text               1     12,13,14
C     6     polyline 3         2     15,16,17
C     7     annotation text    3     18,19,20
C     8     fill area set      4     21,22,23

      YINCR = 1 / (9.0)
      YTOP  = 1 - YINCR
      CALL PSTXCI (YELLOW)
      CALL NUMLAB (8, 0.15, YTOP, YINCR)

C  horizontal positions
      X1 = 0.2
      X2 = 0.5
      X3 = X1 + (X2 - X1)/3
      X4 = X1
      X5 = 0.6
      X6 = 0.9
      X7 = X5 + (X6 - X5)/3
      X8 = X5

C  #1  polyline, color = 1, nameset = 0,1,2
      CALL PSPLCI (GREEN)
      CALL SETVAL ('0,1,2', NAMES)
      CALL PADS (3, NAMES)
      XVAL (1) = X1
      XVAL (2) = X2
      YVAL (1) = YPOS8(1)
      YVAL (2) = YVAL(1)
      CALL PPL (2, XVAL, YVAL)
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy
         XVAL (1) = X5
         XVAL (2) = X6
         CALL PPL (2, XVAL, YVAL)
      ENDIF

C  #2  polymarker, color = 2, nameset = 3,4,5
      CALL PSPMCI (YELLOW)
      CALL SETVAL ('3,4,5', NAMES)
      CALL PADS (3, NAMES)
      XVAL (1) = X3
      YVAL (1) = YPOS8(2)
      CALL PPM (1, XVAL, YVAL)
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy
         XVAL (1) = X7
         CALL PPM (1, XVAL, YVAL)
      ENDIF

C  #3  fill area, color = 3, nameset = 6,7,8
      CALL PSICI (WHITE)
      CALL PSIS  (PSOLID)
      CALL SETVAL ('6,7,8', NAMES)
      CALL PADS (3, NAMES)
      XVAL (1) = X1
      XVAL (2) = X2
      XVAL (3) = X3
      YVAL (2) = YPOS8(3) - .02
      YVAL (3) = YVAL(2)
      YVAL (1) = YVAL(2) + .035
      IXA(1) = 3
      CALL PFAS (1, IXA, XVAL, YVAL)
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy
         XVAL (1) = X5
         XVAL (2) = X6
         XVAL (3) = X7
         CALL PFAS (1, IXA, XVAL, YVAL)
      ENDIF

C  #4  cell array, color = 4, nameset = 9,10,11
      CALL SETVAL ('9,10,11', NAMES)
      CALL PADS (3, NAMES)
      Y1 = YPOS8(4) - 0.02
      Y2 = Y1 + 0.05
      CALL PCA (X1,Y1, X2,Y2, 3,3,1,1,3,3,COLIA)
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy 
         CALL PCA (X5,Y1, X6,Y2, 3,3,1,1,3,3,COLIA)
      ENDIF

C  #5  text, color = 1, nameset = 12,13,14
      CALL PSTXCI (GREEN)
      CALL PSTXAL (PACENT, PAHALF)
      CALL PSCHH (0.2 * YINCR)
      CALL SETVAL ('12,13,14', NAMES)
      CALL PADS (3, NAMES)
      Y1 = YPOS8(5)
      CALL PTX ((X1+X2)/2, Y1, 'PHIGS')
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy
         CALL PTX ((X5+X6)/2, Y1, 'PHIGS')
      ENDIF

C  #6  polyline 3, color = 2, nameset = 15,16,17
      CALL PSPLCI (YELLOW)
      CALL SETVAL ('15,16,17', NAMES)
      CALL PADS (3, NAMES)
      YVAL (1) = YPOS8(6)
      YVAL (2) = YVAL(1)
      XVAL (1) = X1
      XVAL (2) = X2
      ZVAL (1) = 0.0
      ZVAL (2) = 1.0
      CALL PPL3 (2, XVAL, YVAL, ZVAL)
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy
         XVAL (1) = X5
         XVAL (2) = X6
         CALL PPL3 (2, XVAL, YVAL, ZVAL)
      ENDIF

C  #7  annotation text, color = 3, nameset = 18,19,20
      CALL PSTXCI (WHITE)
      CALL PSATAL (PACENT, PAHALF)
      CALL WCNPC (Z,Z, NPCX,NPCY, NPCPWC)
      CALL PSATCH (0.2 * YINCR * NPCPWC)
      CALL SETVAL ('18,19,20', NAMES)
      CALL PADS (3, NAMES)
      Y1 = YPOS8(7)
      CALL PATR ((X1+X2)/2, Y1, 0.0,0.0, 'Version #2' )
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy
         CALL PATR ((X5+X6)/2, Y1, 0.0,0.0, 'Version #2' )
      ENDIF

C  #8  fill area set, color = 4, nameset = 21,22,23
      CALL PSICI (BLUE)
      CALL SETVAL ('21,22,23', NAMES)
      CALL PADS (3, NAMES)
      Y1  = YPOS8(8)
      YVAL(1) = Y1 + 0.02
      YVAL(2) = Y1 - 0.02
      YVAL(3) = Y1 - 0.02
      YVAL(4) = Y1 + 0.02

      XVAL (1) = X1
      XVAL (2) = X2
      XVAL (3) = X3
      XVAL (4) = X4

      IXA(1) = 4
      CALL PFAS (1, IXA, XVAL,YVAL)
      CALL PRES (3, NAMES)
      IF (HLIGHT) THEN
C Comparison Copy
         XVAL (1) = X5
         XVAL (2) = X6
         XVAL (3) = X7
         XVAL (4) = X8
         CALL PFAS (1, IXA, XVAL,YVAL)
      ENDIF

      END

C  *********************************************************
C  *                                                       *
C  *    REAL FUNCTION 04.03.04.02/ypos8                    *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      REAL FUNCTION YPOS8 (YTH)

C  YPOS8 returns the appropriate y-coordinate in WC for element
C  number yth.

      INTEGER    YTH
      YPOS8 =  (9 - YTH) / 9.0

      END
