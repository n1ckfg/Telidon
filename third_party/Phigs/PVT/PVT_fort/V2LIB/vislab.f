      SUBROUTINE VISLAB (TXT, ALIGN, XLO,XHI,YLO,YHI)

C  VISLAB draws a text label within a specified box.  Labels are
C  drawn in stroke precision.  The text label is scaled uniformly
C  (aspect ratio preserved) so that it just fits in the box, and
C  then aligned as requested.  Thus, there may be empty space left
C  within the box. A new structure is used as a substructure if
C  there is a currently open structure, otherwise it is used as the
C  main structure.  If used as a substructure, an <execute
C  structure> element is inserted in the main structure. Most text
C  attributes are set explicitly, but text colour index is
C  inherited.

C  Input parameters:
C    TXT     : Contents of text label to be written
C    ALIGN   : alignment code: L,R,T,B,C for left,right,top,bottom,center
C    XLO,XHI : horizontal location for label
C    YLO,YHI : vertical location for label

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
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

      INTEGER    ERRIND, EDITMO, OPSTAT, OPID, ELPTR, LABSTR
      INTEGER    TXFNT, ALDEX, ALH(5), ALV(5)

      REAL       XLO,XHI, YLO,YHI, Z,U, CHXP,CHHT,CHSP
      REAL       XLOC,YLOC
      REAL       TXX(2),TXY(2), CCX,CCY, TXH,TXV

      CHARACTER  TXT*(*), ALIGN*1

      DATA  ALH / PALEFT,PARITE,PACENT,PACENT,PACENT /
      DATA  ALV / PAHALF,PAHALF,PATOP, PABOTT,PAHALF /

      ALDEX = INDEX('LRTBC', ALIGN)
      IF (ALDEX .LE. 0) THEN
         CALL UNMSG ('Invalid alignment code in VISLAB: ' // ALIGN)
      ENDIF

C  save edit state, open-structure state
      CALL PQEDM  (ERRIND, EDITMO)
      CALL CHKINQ ('pqedm', ERRIND)
      CALL PQOPST (ERRIND, OPSTAT, OPID)
      CALL CHKINQ ('pqopst', ERRIND)
C  If a structure is open, save element-pointer and close structure
      IF (OPSTAT .EQ. POPNST) THEN
         CALL PQEP (ERRIND, ELPTR)
         CALL CHKINQ ('pqep', ERRIND)
         CALL PCLST
      ENDIF

C  set up new structure for labels
      CALL NEWSTR (950, LABSTR)
      CALL PSEDM (PINSRT)
      CALL POPST (LABSTR)
      CALL PEMST (LABSTR)

C  set all aspects to individual
      CALL SETASF (PINDIV)

CUSERMOD  text attributes for labels
      Z = 0.0
      U = 1.0
      TXFNT = 1
      CHHT  = 1.0
      CHSP  = 0.1
      CHXP  = 0.8
      CALL PSTXFN (TXFNT)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (CHXP)
      CALL PSCHSP (CHSP)
      CALL PSCHUP (Z,U)
      CALL PSTXP  (PRIGHT)
      CALL PSTXAL (ALH(ALDEX), ALV(ALDEX))

C  adjust character height according to text-extent
      CALL PQTXX (SPECWT, TXFNT, CHXP, CHSP, CHHT, PRIGHT,
     1            PALEFT,PABOTT, TXT, ERRIND, TXX,TXY, CCX,CCY)
      CALL CHKINQ ('pqtxx', ERRIND)
      TXH = ABS(TXX(1) - TXX(2))
      TXV = ABS(TXY(1) - TXY(2))

C  scale vertically and horizontally by same amount to fit within box.
      CHHT = MIN((XHI-XLO)/TXH, (YHI-YLO)/TXV)
      CALL PSCHH (CHHT)
C  get correct alignment point - assume centered and then move
      XLOC = (XLO+XHI)/2
      YLOC = (YLO+YHI)/2
      IF (ALDEX .EQ. 1) XLOC = XLO
      IF (ALDEX .EQ. 2) XLOC = XHI
      IF (ALDEX .EQ. 3) YLOC = YHI
      IF (ALDEX .EQ. 4) YLOC = YLO

      CALL PTX (XLOC, YLOC, TXT)
      CALL PCLST

C  restore edit state, open-structure state
      CALL PSEDM (EDITMO)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL POPST (OPID)
         CALL PSEP  (ELPTR)
         CALL PEXST (LABSTR)
      ENDIF

      END
