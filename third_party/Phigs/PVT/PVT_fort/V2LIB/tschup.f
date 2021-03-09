      SUBROUTINE TSCHUP (TXFONT, TXPATH, TXSTR, NUMOUT, NGSTR)

C  TSCHUP draws a text string with various values for character up
C  and for text alignment.  The text strings are displayed along
C  radii of a circle and are enclosed by a text extent rectangle
C  (except for one which is deliberately drawn incorrectly).

C  Input parameters:
C    TXFONT : Text font to be used
C    TXPATH : Text path to be used
C    TXSTR  : Text string to be used
C  Output parameters:
C    NUMOUT : Number of text primitives drawn
C    NGSTR  : Identifier of incorrect text primitive

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

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
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

      INTEGER    IX, RNDINT, NUMSTR, NUMOUT, NGSTR
C  numstr = number of strings to display
      PARAMETER (NUMSTR = 7)
      INTEGER    TXFONT, TXPATH, ERRIND, ALGNH(NUMSTR), ALGNV(NUMSTR)

      REAL       NTXWD,NTXHT, ORAD,IRAD, PI, XF(3,3), XA(9),YA(9)
      REAL       VTAB(PATOP:PABOTT), HTAB(PALEFT:PARITE), Z
      REAL       TXANG, SINT,COST, TXPOSX,TXPOSY, SCF, RECLNG,RECSHT
      REAL       XRT,YRT, XUP,YUP, XVEC,YVEC, INTSP, XB(2),YB(2), LABRAD
      PARAMETER (PI = 3.14159265)

      LOGICAL    VERT

      CHARACTER  TXSTR*(*), DIG2*2

      NUMOUT = NUMSTR
      VERT = TXPATH.EQ.PUP .OR. TXPATH.EQ.PDOWN

      CALL PSTXFN (TXFONT)
C  use <inquire text extent> on txstr to determine:
C    ntxwd  = nominal width of text extent rectangle
C    ntxht  = nominal height of text extent rectangle
C    vtab,htab = normalized heights and widths
      CALL TXEXAL (TXFONT, TXPATH, TXSTR, NTXWD, NTXHT, HTAB, VTAB)
      IF (VERT) THEN
         RECLNG = NTXHT
         RECSHT = NTXWD
      ELSE
         RECLNG = NTXWD
         RECSHT = NTXHT
      ENDIF

C  ngstr = incorrect string identifier
      NGSTR = RNDINT(1,7)
C  irad = inner radius of circle for display of text strings
      IRAD = 1.1 * (NUMSTR*RECSHT) / (2*PI)
C  orad = outer radius of circle for display of text strings
      ORAD = IRAD + RECLNG

C  set up transform to fit text circle on screen, from MC centered at
C  origin, with radius orad to WC radius=0.4, centered at 0.5,0.5
      Z = 0.0
C  label radius factor
      LABRAD = 1.2
      SCF = 0.45 / (LABRAD*ORAD)
      CALL PBLTM  (Z,Z, 0.5,0.5, Z, SCF,SCF, ERRIND, XF)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT  (XF, PCPRE)

C  text alignments to be used:
C     algnh    algnv
C     ------   ------
C  1: center   base
C  2: left     cap
C  3: right    top
C  4: left     bottom
C  5: center   half
C  6: right    half
C  7: left     cap
      CALL SETVAL ('2,1,3,1,2,3,1', ALGNH)
      CALL SETVAL ('4,2,1,5,3,3,2', ALGNV)

C first draw labels and expected rectangles
      CALL PSPLCI (2)
      CALL PSTXCI (1)
      CALL PSTXAL (PACENT, PAHALF)
      CALL PSTXP (PRIGHT)

      DO 100 IX = 1,NUMSTR
C  txang = angle for text string
         TXANG = IX*2*PI / NUMSTR
         COST = COS(TXANG)
         SINT = SIN(TXANG)
C  draw rectangle for expected position of text string, based on
C     txang, ntxwd,ntxht
C  first draw bottom line along radius
         XA(1) = IRAD * COST
         XA(5) = XA(1)
         XA(4) = (IRAD + RECLNG) * COST

         YA(1) = IRAD * SINT
         YA(5) = YA(1)
         YA(4) = (IRAD + RECLNG) * SINT
C  unit up vector for rectangle  - this keeps left-bottom corner
C  on the radius for either horizontal or vertical path
         IF (VERT) THEN
            XVEC =  SINT
            YVEC = -COST
            INTSP = 0.5
         ELSE
            XVEC = -SINT
            YVEC =  COST
            INTSP = VTAB(PABASE) / VTAB(PATOP)
         ENDIF

         XA(2) = XA(1) + RECSHT*XVEC
         XA(3) = XA(4) + RECSHT*XVEC
         YA(2) = YA(1) + RECSHT*YVEC
         YA(3) = YA(4) + RECSHT*YVEC

         CALL PSLN (PLDOT)
         CALL PPL (5, XA,YA)

C  do baseline or centerline
         XB(1) = XA(1) + INTSP*RECSHT*XVEC
         XB(2) = XA(4) + INTSP*RECSHT*XVEC
         YB(1) = YA(1) + INTSP*RECSHT*YVEC
         YB(2) = YA(4) + INTSP*RECSHT*YVEC

         CALL PSLN (PLDASH)
         CALL PPL (2, XB, YB)

C  label each spoke
         WRITE (DIG2, '(A,I1)') '#', IX
         CALL PTX ( LABRAD*XA(4), LABRAD*YA(4), DIG2)
100   CONTINUE

      CALL PSTXP (TXPATH)
      DO 200 IX = 1,NUMSTR
C  txang = angle for text string
         TXANG = IX*2*PI / NUMSTR
         COST = COS(TXANG)
         SINT = SIN(TXANG)
C  txpos = requested text position, based on txang,irad, and
C    text alignment to be requested.
C  first get unit up,right direction
         IF (VERT) THEN
            XUP =  COST
            YUP =  SINT
            XRT =  SINT
            YRT = -COST
         ELSE
            XUP = -SINT
            YUP =  COST
            XRT =  COST
            YRT =  SINT
         ENDIF

         TXPOSX = IRAD * COST + HTAB(ALGNH(IX)) * XRT
     1                        + VTAB(ALGNV(IX)) * XUP
         TXPOSY = IRAD * SINT + HTAB(ALGNH(IX)) * YRT
     1                        + VTAB(ALGNV(IX)) * YUP
         CALL PSTXAL (ALGNH(IX), ALGNV(IX))

         IF (IX .EQ. NGSTR) THEN
            TXANG = TXANG + (RNDINT(0,1)-0.5) * 0.5*PI/NUMSTR
            COST = COS(TXANG)
            SINT = SIN(TXANG)
            IF (VERT) THEN
               XUP =  COST
               YUP =  SINT
            ELSE
               XUP = -SINT
               YUP =  COST
            ENDIF
         ENDIF
         CALL PSCHUP (XUP, YUP)
         CALL PTX (TXPOSX, TXPOSY, TXSTR)
C  next ix
200   CONTINUE

      END
