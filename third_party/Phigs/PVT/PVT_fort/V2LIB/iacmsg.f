      SUBROUTINE IACMSG (MSGTXT)

C  IACMSG sends a character string (MSGTXT) to the operator in
C  accordance with DOUTYP.  For DOUTYP 3 IACMSG formats MSGTXT
C  into structure #DSTRID. For DOUTYP 1 OR 2 IACMSG simply breaks up
C  MSGTXT into the specified line-length and sends out each line
C  via PRINT or MESSAGE, respectively.

C  If the MSGTXT looks like a topical heading for a test case (caps
C  followed by ":"), then the heading is saved in a common area
C  shared with OPCO, so the operator's comments are tagged.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      COMMON /OPCOMM/ OPHEAD
      CHARACTER  OPHEAD*300

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C open-structure status
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)

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

C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)

      INTEGER    LINMAX
      PARAMETER (LINMAX = 90)

      INTEGER    ITRIM, EDITMO, OPSTAT, OPID, ELPTR
      INTEGER    ERR, NUMLIN, LINPOS(LINMAX), OUTL, MA,MB, ILINE
      INTEGER    COLLOC, IX, TXFNT

      REAL       XA(10),YA(10), EXTX(2),EXTY(2),COPX,COPY
      REAL       Z,U, TM3(3,3), YPOS,XMAX, XSIZE,YSIZE, SCF, LOGHW
      REAL       CHWRAT, RDUM, CHSP

      PARAMETER (Z=0.0, U=1.0)

      CHARACTER  MSGTXT*(*), MSG*300

C  put MSGTXT in OPHEAD if it's a topical header for a test case.
C  look for colon location
      COLLOC = INDEX(MSGTXT, ':')
      IF (COLLOC .LE. 0) GOTO 100

      DO 50 IX = 1, MIN(10, LEN(MSGTXT))
C  treat as non-header if first 10 chars not all caps or digits or spaces
         IF (INDEX('ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789',
     1             MSGTXT(IX:IX)) .LE. 0) GOTO 100
50    CONTINUE
      OPHEAD = MSGTXT(:COLLOC)

100   CONTINUE

      IF (DOUTYP.EQ.1 .OR. DOUTYP.EQ.2) THEN
C  if direct output, skip initialization of structure (DSTRID)
C  for dialogue.
         GOTO 110
      ELSEIF (DOUTYP.EQ.3) THEN
C        OK - do nothing
      ELSE
         WRITE (MSG, '(A,I5)') 'Invalid output type in IACMSG: ', DINTYP
         CALL UNMSG (MSG)
      ENDIF

C  save edit state, open-structure state
      CALL PQEDM  (ERRIND, EDITMO)
      CALL CHKINQ ('pqedm', ERRIND)
      CALL PQOPST (ERRIND, OPSTAT, OPID)
      CALL CHKINQ ('pqopst', ERRIND)
C  If a structure is open, save element-pointer and close structure
      IF (OPSTAT .EQ. POPNST) THEN
         IF (OPID .EQ. DSTRID) THEN
            CALL UNMSG ('IACMSG found dialogue structure open.')
         ENDIF
         CALL PQEP (ERRIND, ELPTR)
         CALL CHKINQ ('pqep', ERRIND)
         CALL PCLST
      ENDIF

      CALL PSEDM (PINSRT)
      CALL POPST (DSTRID)
      CALL PEMST (DSTRID)
      CALL PSVWI (2)

C  set all aspects to individual
      CALL SETASF (PINDIV)

C  outline dialogue area
      CALL PSPLCI (DTXCI)
      CALL SETRVS ('0,0,1,1,0', XA, OUTL)
      CALL SETRVS ('0,0,0,0,0', YA, OUTL)
      YA(2) = DYXRAT
      YA(3) = DYXRAT
      CALL PPL (5,XA,YA)
C  mark start of text elements in structure
      CALL PLB (101)

CUSERMOD  text attributes for dialogue
      TXFNT = 1
      CHSP  = 0.1
      CALL PSTXFN (TXFNT)
      CALL PSTXPR (PSTRKP)
      CALL PSCHXP (U)
      CALL PSCHSP (CHSP)
      CALL PSTXCI (DTXCI)
      CALL PSCHH  (U)
      CALL PSCHUP (Z,U)
      CALL PSTXP  (PRIGHT)
      CALL PSTXAL (PALEFT,PATOP)

CUSERMOD  Control character height/width ratio for dialogue here: if
CUSERMOD  characters too skinny, decrease, if too fat, increase.
      CHWRAT = 2.5
C  calculate line-size, for a paragraph based on desired
C  character body height/width ratio
      CALL FITPAR (MSGTXT, CHWRAT, DYXRAT, DTCLIM)
      YPOS = 0.0
      XMAX = 0.0

110   CONTINUE

C  break up MSGTXT into DTCLIM-size chunks - get array of
C  line starting positions
      CALL LINBRK (MSGTXT, DTCLIM, ERR, NUMLIN, LINPOS)
      IF (NUMLIN .GE. LINMAX) THEN
         CALL UNMSG ('Too many lines computed by IACMSG.')
      ENDIF

C  send each line to screen or print or message, as specified
      DO 200 ILINE = 1,NUMLIN
C  MA and MB point to substring within MSGTXT to be output
         MA = LINPOS(ILINE)
         MB = ITRIM(MSGTXT(1:LINPOS(ILINE+1) - 1))
         IF (DOUTYP .EQ. 1) THEN
            PRINT *, MSGTXT(MA:MB)
         ELSEIF (DOUTYP .EQ. 2) THEN
            CALL PMSG (WKID, MSGTXT(MA:MB))
         ELSE
C  write MSGTXT into prompt area - WC = x:0-1, y:0-DYXRAT
            CALL PTX (0.0, YPOS, MSGTXT(MA:MB))
C  keep track of widest line and vertical position
            CALL PQTXX (SPECWT, TXFNT,U,CHSP,U,PRIGHT,PALEFT,PATOP,
     1                  MSGTXT(MA:MB), ERRIND, EXTX,EXTY,COPX,COPY)
            CALL CHKINQ ('pqtxx', ERRIND)
            XSIZE = ABS(EXTX(1)-EXTX(2))
            YSIZE = ABS(EXTY(1)-EXTY(2))
            XMAX = MAX(XMAX, XSIZE)
CUSERMOD  Control separation of dialogue lines here - if too crowded,
CUSERMOD  increase coefficient of YSIZE, if too sparse, decrease.
            YPOS = YPOS - 1.02*YSIZE
         ENDIF
200   CONTINUE

      IF (SCRMOD .EQ. 3) THEN
C  make sure dialogue is posted
         CALL PSTCTL (2)
      ELSEIF (SCRMOD .EQ. 0) THEN
C  post picture only
         CALL PSTCTL (1)
      ELSE
C  split screen - post dialogue and picture
         CALL PSTCTL (3)
      ENDIF

C  if direct output, we're done
      IF (DOUTYP .NE. 3) RETURN

C  Text written into rectangle with x-bounds = 0:xmax,
C  y-bounds = ypos:0. Must transform to fit into 0:1, 0:dyxrat
C  rectangle, with scaling adjusted for CHWRAT = character
C  height/width ratio.

      CALL SCAPAR (DTCLIM,CHWRAT,DYXRAT,NUMLIN,LINPOS, RDUM,LOGHW)
      SCF = 0.94 * MIN(1.0, DYXRAT/LOGHW)

      CALL PBLTM (Z,Z, .03,DYXRAT, Z, SCF/XMAX,-SCF*LOGHW/YPOS,
     1            ERRIND, TM3)
      CALL CHKINQ ('pbltm', ERRIND)
C  insert transformation just before text elements
      CALL PSEP   (1)
      CALL PSEPLB (101)
      CALL PSLMT  (TM3, PCREPL)
      CALL PCLST

C  restore edit state, open-structure state
      CALL PSEDM (EDITMO)
      IF (OPSTAT .EQ. POPNST) THEN
         CALL POPST (OPID)
         CALL PSEP  (ELPTR)
      ENDIF

      END
