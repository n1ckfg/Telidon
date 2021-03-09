      SUBROUTINE GEOTXT (USENEG, NUMLIN, NGLINE)

C  GEOTXT generates a display of NUMLIN text primitives, whose
C  geometric aspects have been highly randomized.  It then outlines
C  their expected position, except for the one in line #NGLINE.
C
C  Input parameters:
C    USENEG : whether to use negative values for character expansion
C             factor, character spacing, and character height
C    NUMLIN : number of text primitives to generate
C  Output parameter:
C    NGLINE : position of the incorrectly outlined primitive

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

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

      INTEGER    NUMLIN, NGLINE, ERRIND, IX, NCHAR
      INTEGER    TXP, TXALH,TXALV, RNDINT
      INTEGER    RNTXP(20), RNALH(20),RNALV(20)

      REAL       VTAB(PATOP:PABOTT), NOMWID, NOMBHT
      REAL       CHSIZ, TXRX(2),TXRY(2), YINCR,YPOS,YTOP, XLO,XHI
      REAL       TPX,TPY,TPZ, TDX(2),TDY(2),TDZ(2), CHXP,CHSP,CHHT
      REAL       CHUPX,CHUPY, RNDRL, VECANG, PI, VANG, ACHXP,ACHHT
      REAL       LLEX,LLEY,LLEZ, NXTCX,NXTCY,NXTCZ, UPCHX,UPCHY,UPCHZ
      REAL       RTCHX,RTCHY,RTCHZ, HINC,VINC, HSIZ,VSIZ, CHMULT
      REAL       XF2D(3,3), XF3D(4,4), SATAN2, TX,TY,TZ, Z,U, XMID
      REAL       CORX,CORY,CORZ, CLNGX,CLNGY,CLNGZ, CSHTX,CSHTY,CSHTZ
      REAL       MA(4,4),MB(4,4),MC(4,4), VECL, MCMIDX,MCMIDY,MCMIDZ
      REAL       RDUM1,RDUM2
      PARAMETER (PI = 3.14159265, Z = 0.0, U = 1.0)

      LOGICAL    USENEG, EXCHSP

      CHARACTER  CHSTR*3

C  values assigned to RNALV assume at least 5 lines
      IF (NUMLIN .LT. 5) CALL UNMSG ('GEOTXT called with #lines < 5.')

      CALL PEMST (102)

C  Throughout, use text string "ELF", because letters are simple to
C  outline, and asymmetric (to reveal reversals).
      CHSTR = 'ELF'
      NCHAR = LEN(CHSTR)

C  Use <inquire text extent> to determine
C    nomwid = nominal character width for font #1
C    nombht = nominal character body height for font #1
C    vtab   = list of nominal offsets for the various vertical
C             text alignments, relative to BASE.
C  nominal quantities are for char-ht=1, char-sp=0, char-xp=1
      CALL PQTXX (SPECWT, 1, 1.,0.,1., PRIGHT, PALEFT,PABASE, CHSTR,
     1            ERRIND, TXRX,TXRY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      NOMWID = ABS(TXRX(2) - TXRX(1)) / NCHAR
      NOMBHT = ABS(TXRY(2) - TXRY(1))

      VTAB(PATOP)  = TXRY(2)
      VTAB(PACAP)  = 1.0
      VTAB(PABASE) = 0.0
      VTAB(PABOTT) = TXRY(1)
      CALL PQTXX (SPECWT, 1, 1.,0.,1., PRIGHT, PALEFT,PAHALF, CHSTR,
     1            ERRIND, TXRX,TXRY, RDUM1,RDUM2)
      CALL CHKINQ ('pqtxx', ERRIND)
      VTAB(PAHALF) = VTAB(PABOTT) - TXRY(1)

C  ngline = random integer from 1 to NUMLIN
      NGLINE = RNDINT(1,NUMLIN)
      YINCR  = 1.0/(NUMLIN+1)
      YTOP   = 1 - YINCR
      YPOS   = YTOP
C  display text between 0.2 and 1.0
      XLO = 0.2
      XHI = 1.0
      XMID = (XLO+XHI)/2
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)

C  random order for text paths, alignments - make sure each possible
C  value is chosen at least once
      CALL RNBSET (4, PRIGHT,PDOWN,  RNTXP)
      CALL RNBSET (3, PALEFT,PARITE, RNALH)
      CALL RNBSET (5, PATOP, PABOTT, RNALV)

C  display NUMLIN text strings
      DO 100 IX = 1,NUMLIN

C  random choices for text path, text alignment
         IF (NUMLIN .LE. 4) THEN
            TXP = RNTXP(NUMLIN)
         ELSE
            TXP = RNDINT(PRIGHT,PDOWN)
         ENDIF

         IF (NUMLIN .LE. 3) THEN
            TXALH = RNALH(NUMLIN)
         ELSE
            TXALH = RNDINT(PALEFT,PARITE)
         ENDIF

         IF (NUMLIN .LE. 5) THEN
            TXALV = RNALV(NUMLIN)
         ELSE
            TXALV = RNDINT(PATOP,PABOTT)
         ENDIF

C  random values for character up vector
         CHUPX = RNDRL(-1.0, 1.0)
         CHUPY = RNDRL(-1.0, 1.0)

C  pick random positive values for character expansion factor,
C  character spacing, and character height.
         CHXP = RNDRL(0.5,  1.5)
         CHSP = RNDRL(0.1,  1.0)
         CHHT = RNDRL(0.1, 10.0)
C  is character spacing so excessive as to reverse order of characters?
         EXCHSP = .FALSE.

         IF (USENEG) THEN
C  set up some negative values for character expansion factor,
C  character spacing, and character height.
            IF (RNDINT(1,4) .GT. 1) CHHT = -CHHT
            IF (RNDINT(1,4) .GT. 1) CHXP = -CHXP
            IF (TXP.EQ.PRIGHT .OR. TXP.EQ.PLEFT) THEN
               CHSIZ = CHXP
            ELSE
               CHSIZ = NOMBHT
            ENDIF
            IF (IX .LE. 2) THEN
C  slight overlap
               CHSP = -ABS(CHSIZ * RNDRL(0.1,0.3))
            ELSEIF (IX .LE. 4) THEN
C  Very negative character spacing to reverse normal text path
               CHSP = -ABS(CHSIZ * RNDRL(2.0,3.5))
               EXCHSP = .TRUE.
            ENDIF
         ENDIF
C  effective character height and expansion factor; only magnitude
C  should be used
         ACHHT = ABS(CHHT)
         ACHXP = ABS(CHXP)
C  distort expected outline for NGLINE
         IF (IX.EQ.NGLINE) ACHHT = ACHHT * (RNDINT(1,2) - 0.5)

C  Represent position of text primitive in MC as follows:
C    LLE  : 3D location of lower-left corner (LEFT,BASE) of "E"
C    NXTC : vector to next character
C    UPCH : character up 3D vector (direction and length)
C    RTCH : character right 3D vector (direction and length)
C    COR  : 3D location of (LEFT,BASE) corner of text extent rectangle
C    CLNG : vector from corner along long dimension of rectangle
C    CSHT : vector from corner along short dimension of rectangle

C  Calculate expected TLC position of text primitive: apply
C  attributes in this order:
C     1: character expansion, character spacing, and text path
C     2: text alignment
C     3: character up
C     4: character height

C  First, assume alignment of LEFT,BASE, character height = 1,
C  and apply character expansion, character spacing, and text path.
C  Default LLE, NXTC, UPCH, RTCH
         LLEX  = 0.0
         LLEY  = 0.0
         LLEZ  = 0.0

         NXTCX = 0.0
         NXTCY = 0.0
         NXTCZ = 0.0

         UPCHX = 0.0
         UPCHY = 1.0
         UPCHZ = 0.0

         RTCHX = NOMWID*ACHXP
         RTCHY = 0.0
         RTCHZ = 0.0

         CLNGX  = 0.0
         CLNGY  = 0.0
         CLNGZ  = 0.0

         CSHTX  = 0.0
         CSHTY  = 0.0
         CSHTZ  = 0.0

C  character increment for RIGHT path
         HINC = RTCHX + CHSP
C  character increment for UP path
         VINC = NOMBHT + CHSP

C  set NXTC and LLE within text rectangle, based on text path and
C  character increment
         IF (TXP .EQ. PRIGHT) THEN
            NXTCX = HINC
            IF (EXCHSP) LLEX = ABS(HINC * (NCHAR-1))
         ELSEIF (TXP .EQ. PLEFT) THEN
            NXTCX = -HINC
            IF (.NOT. EXCHSP) LLEX = ABS(HINC * (NCHAR-1))
         ELSEIF (TXP .EQ. PUP) THEN
            NXTCY = VINC
            IF (EXCHSP) LLEY = ABS(VINC * (NCHAR-1))
         ELSEIF (TXP .EQ. PDOWN) THEN
            NXTCY = -VINC
            IF (.NOT. EXCHSP) LLEY = ABS(VINC * (NCHAR-1))
         ELSE
            CALL UNMSG ('Illegal text path generated in GEOTXT.')
         ENDIF

C  step 2: compute location of corner (LEFT,BASE of rectangle)
C  based on text alignment.  HSIZ,VSIZ is size of rectangle
C  from baseline to capline.
         IF (TXP .EQ. PRIGHT .OR. TXP .EQ. PLEFT) THEN
C  horizontal path
            HSIZ = RTCHX + ABS(HINC) * (NCHAR-1)
            VSIZ = UPCHY
            CORY = -VTAB(TXALV)
         ELSE
C  vertical path
            HSIZ = RTCHX
            VSIZ = UPCHY + ABS(VINC) * (NCHAR-1)
            IF (TXALV .EQ. PATOP .OR. TXALV .EQ. PACAP) THEN
C  align relative to top character
               CHMULT = NCHAR-1
            ELSEIF (TXALV .EQ. PAHALF) THEN
C  align relative to middle character
               CHMULT = (NCHAR-1)/2.0
            ELSE
C  align relative to bottom character
               CHMULT = 0
            ENDIF
            CORY = -CHMULT*ABS(VINC) - VTAB(TXALV)
         ENDIF
         CORX = -HSIZ * (TXALH - 1.0)/2.0
         CORZ = 0.0

C  offset LLE by location of corner
         LLEX = LLEX + CORX
         LLEY = LLEY + CORY

C  find long, short axis of rectangle
         IF (HSIZ .GT. VSIZ) THEN
            CLNGX = HSIZ
            CSHTY = VSIZ
         ELSE
            CLNGY = VSIZ
            CSHTX = HSIZ
         ENDIF

C  step 3 and 4: apply 2D character-up rotation and character height scaling
C  to rotate parameters within TLC plane.
         CALL EBLTM (Z,Z, Z,Z, SATAN2(-CHUPX,CHUPY), ACHHT,ACHHT, XF2D)
         CALL ETP (LLEX +Z, LLEY +Z, XF2D, LLEX, LLEY)
         CALL ETP (NXTCX+Z, NXTCY+Z, XF2D, NXTCX,NXTCY)
         CALL ETP (UPCHX+Z, UPCHY+Z, XF2D, UPCHX,UPCHY)
         CALL ETP (RTCHX+Z, RTCHY+Z, XF2D, RTCHX,RTCHY)
         CALL ETP (CORX +Z, CORY +Z, XF2D, CORX, CORY)
         CALL ETP (CLNGX+Z, CLNGY+Z, XF2D, CLNGX,CLNGY)
         CALL ETP (CSHTX+Z, CSHTY+Z, XF2D, CSHTX,CSHTY)

C  Correct TLC values for LLE, NXTC, UPCH, RTCH, COR, CLNG, CSHT
C  now computed;

C  pick random values for text position and direction vectors
         TPX = RNDRL(-5.0, 5.0)
         TPY = RNDRL(-5.0, 5.0)
         TPZ = RNDRL(-5.0, 5.0)

105      CONTINUE
         TDX(1) = RNDRL(-5.0, 5.0)
         TDY(1) = RNDRL(-5.0, 5.0)
         TDZ(1) = RNDRL(-5.0, 5.0)
110      CONTINUE
         TDX(2) = RNDRL(-5.0, 5.0)
         TDY(2) = RNDRL(-5.0, 5.0)
         TDZ(2) = RNDRL(-5.0, 5.0)

C  get fairly stable vectors - not too parallel - check angle
C  between vectors.
         VANG = VECANG(TDX(1),TDY(1),TDZ(1), TDX(2),TDY(2),TDZ(2))
     1          * 180 / PI
         IF (ABS(VANG-90) .GT. 87.0) GOTO 110

C  set up matrix to do TLC -> MC rotation; start with identity matrix
         CALL IDMAT (4, XF3D)

C  compute unit vectors expressing TLC directions within MC -
C  build these into columns of transformation matrix.

C  TLC X-direction = 1st vector, scaled to unit size
         CALL VEC1 (TDX(1),TDY(1),TDZ(1), XF3D(1,1),XF3D(2,1),XF3D(3,1))
C  TLC Z-direction = 1st x 2nd vector, scaled to unit size
         CALL CROSSP (TDX(1),TDY(1),TDZ(1), TDX(2),TDY(2),TDZ(2),
     1                TX,TY,TZ)
         CALL VEC1 (TX,TY,TZ, XF3D(1,3),XF3D(2,3),XF3D(3,3))
C  make sure not too oblique (check z-component of TLC z-vector);
C  if so, retry
         IF (XF3D(3,3)**2 .LT. 0.5) GOTO 105
C  TLC Y-direction = Z-direction x X-direction
         CALL CROSSP (XF3D(1,3),XF3D(2,3),XF3D(3,3),
     1                XF3D(1,1),XF3D(2,1),XF3D(3,1),
     2                XF3D(1,2),XF3D(2,2),XF3D(3,2))

C  Now, calculate expected MC position of text primitive.

C  rotate vectors from TLC to MC (rotate only, not shift):
         CALL ETP3 (NXTCX+Z,NXTCY+Z,NXTCZ+Z, XF3D, NXTCX,NXTCY,NXTCZ)
         CALL ETP3 (UPCHX+Z,UPCHY+Z,UPCHZ+Z, XF3D, UPCHX,UPCHY,UPCHZ)
         CALL ETP3 (RTCHX+Z,RTCHY+Z,RTCHZ+Z, XF3D, RTCHX,RTCHY,RTCHZ)
         CALL ETP3 (CLNGX+Z,CLNGY+Z,CLNGZ+Z, XF3D, CLNGX,CLNGY,CLNGZ)
         CALL ETP3 (CSHTX+Z,CSHTY+Z,CSHTZ+Z, XF3D, CSHTX,CSHTY,CSHTZ)

C  add in shift to text position
         XF3D(1,4) = TPX
         XF3D(2,4) = TPY
         XF3D(3,4) = TPZ

C  transform points from TLC to MC:
         CALL ETP3 (LLEX-Z,LLEY-Z,LLEZ-Z, XF3D, LLEX, LLEY, LLEZ)
         CALL ETP3 (CORX-Z,CORY-Z,CORZ-Z, XF3D, CORX, CORY, CORZ)

C  Correct MC values for LLE, NXTC, UPCH, RTCH, COR, CLNG, CSHT
C  now computed

C  compute global modelling transform to re-locate text extent
C  rectangle (in MC) to display area for this line (in WC).
         MCMIDX = CORX + CLNGX/2 + CSHTX/2
         MCMIDY = CORY + CLNGY/2 + CSHTY/2
         MCMIDZ = CORZ + CLNGZ/2 + CSHTZ/2

C  use MC midpoint as fixed point.
C  1st, rotate around Z-axis so as to make long axis horizontal

         CALL EBLTM3 (MCMIDX,MCMIDY,MCMIDZ, Z,Z,Z,
     2      Z,Z, -SATAN2(CLNGY,CLNGX), U,U,U, MB)

C  2nd, scale to fit in line area
C  3rd, shift to WC midpoint (= XMID,YPOS,0.5)
         CALL EBLTM3 (MCMIDX,MCMIDY,MCMIDZ,
     1      XMID - MCMIDX, YPOS - MCMIDY, 0.5 - MCMIDZ, Z,Z,Z,
     2      (XHI-XLO) * 0.8 / VECL(CLNGX,CLNGY,Z),
     4      YINCR     * 0.7 / VECL(CSHTX,CSHTY,Z), Z, MC)
         CALL ECOM3 (MC,MB, MA)
         CALL PSGMT3 (MA)

C  re-set local transformation to identity; only global applies to
C  actual text primitive.
         CALL IDMAT (4,MA)
         CALL PSLMT3 (MA, PCREPL)

C  generate text primitive, with chosen attributes and geometry
         CALL PSCHXP (CHXP)
         CALL PSCHSP (CHSP)
         CALL PSCHH  (CHHT)
         CALL PSCHUP (CHUPX,CHUPY)
         CALL PSTXP  (TXP)
         CALL PSTXAL (TXALH,TXALV)
         CALL PTX3   (TPX,TPY,TPZ, TDX,TDY,TDZ, CHSTR)

C  draw outline, using local transformations:
C    same scale, rotate and initial shift for all 3 letters -
C    use to transform nominal ELF outline to MC text locations.

C  after local transformations move outlines to MC, global
C  transformation, still in effect from above, will move them along
C  with text to correct WC display area.
         CALL IDMAT (4,MA)
C  rotate and scale nominal as per RTCH and UPCH.
         MA(1,1) = RTCHX
         MA(2,1) = RTCHY
         MA(3,1) = RTCHZ
         MA(1,2) = UPCHX
         MA(2,2) = UPCHY
         MA(3,2) = UPCHZ
C  shift to position of "E"
         MA(1,4) = LLEX
         MA(2,4) = LLEY
         MA(3,4) = LLEZ

C  set up transformation for E:
         CALL PSLMT3 (MA, PCREPL)
         CALL PEXST (201)

C  set up shift over for next letter, as per NXTC
         CALL ETR3 (NXTCX, NXTCY, NXTCZ, MA)

C  set up transformation for L:
         CALL PSLMT3 (MA, PCPOST)
         CALL PEXST (202)
C  set up transformation for F:
         CALL PSLMT3 (MA, PCPOST)
         CALL PEXST (203)

C  next line
         YPOS = YPOS-YINCR
100   CONTINUE

      END
