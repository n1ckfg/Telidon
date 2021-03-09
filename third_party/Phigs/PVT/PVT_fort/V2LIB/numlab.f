      SUBROUTINE NUMLAB (HINUM, RTMARG, YTOP, YINCR)

C  NUMLAB draws a sequence of numeric labels down a vertical column.
C  Labels are drawn in stroke precision.  A non-existent structure
C  is used as a substructure if there is a currently open structure,
C  otherwise it is used as the main structure.  If used as a
C  substructure, an <execute structure> element is inserted in the
C  main structure.  Most text attributes are set explicitly, but
C  text colour index is inherited.

C  Input parameters:
C    HINUM  : highest number; labels 1-HINUM are drawn.
C    RTMARG : right-hand margin for labels
C    YTOP   : vertically centered location of top label (#1)
C    YINCR  : vertical increment for labels

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

      INTEGER    HINUM, ERRIND, EDITMO, OPSTAT, OPID, ELPTR, LABSTR
      INTEGER    TXFNT, IX

      REAL       RTMARG, YTOP, YINCR, Z,U, CHXP,CHHT,CHSP, YPOS
      REAL       TXX(2),TXY(2), CCX,CCY, TXH,TXV

      CHARACTER  D2*3

      IF (HINUM.LT.1 .OR. HINUM.GT.99) THEN
         CALL UNMSG ('Invalid value for HINUM in NUMLAB.')
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

C  get a new structure identifier
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
      CHSP  = 0.0
      CHXP  = 0.8
      CALL PSTXFN (TXFNT)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (CHXP)
      CALL PSCHSP (CHSP)
      CALL PSCHUP (Z,U)
      CALL PSTXP  (PRIGHT)
      CALL PSTXAL (PARITE, PAHALF)

C  adjust character height according to text-extent
      CALL PQTXX (SPECWT, TXFNT, CHXP, CHSP, 1., PRIGHT, PALEFT,PABOTT,
     1            '88:', ERRIND, TXX,TXY, CCX,CCY)
      CALL CHKINQ ('pqtxx', ERRIND)
      TXH = ABS(TXX(1) - TXX(2))
      TXV = ABS(TXY(1) - TXY(2))

C  scale down vertically or horizontally, to lower size
      CHHT = MIN (0.9*RTMARG/TXH, 0.65*YINCR / TXV)
      CALL PSCHH  (CHHT)
      YPOS = YTOP

      DO 100 IX = 1,HINUM
         WRITE (D2, '(I2,A)') IX, ':'
         CALL PTX (RTMARG, YPOS, D2)
         YPOS = YPOS-YINCR
100   CONTINUE
      CALL PCLST

C  restore edit state, open-structure state
      CALL PSEDM (EDITMO)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL POPST (OPID)
         CALL PSEP  (ELPTR)
         CALL PEXST (LABSTR)
      ENDIF

      END
