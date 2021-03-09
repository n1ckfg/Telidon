C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/08                        *
C  *    TEST TITLE : Annotation text alignment             *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

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

      INTEGER    PICSTR, TXCI, IX, NUMLIN, ALGNH(6),ALGNV(6),ALGNTP(6)
      INTEGER    RALGNH(6),RALGNV(6), EALGNH(6),EALGNV(6), IDUM1
      INTEGER    PERM(20), RNDINT

      REAL       NTXWD,NTXHT, CHHT, YMID, NPCX,NPCY,NPCPWC
      REAL       VTAB(PATOP:PABOTT), HTAB(PALEFT:PARITE), YTOP,YINCR
      REAL       YLO,YHI, YHALF, TXPOSX,TXPOSY, XINCR,XLEFT,XMID
      REAL       XLO,XHI, XHALF, XA(2),YA(2), Z
      PARAMETER (Z = 0.0)

      CHARACTER  TXSTR*8, DIG2*2

      CALL INITGL ('04.02.04.01/08')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL WCNPC (0.0, 0.0, NPCX,NPCY, NPCPWC)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)

C  set text font = 2, text precision = STROKE
      CALL PSTXFN (2)
      CALL PSTXPR (PSTRKP)
      CALL PEXST (102)
      CALL PCLST

C  try for 2 distinct colors
      CALL DISCOL (2, WKID, IDUM1)

      CALL POPST (102)

C  txstr = annotation text string to be used for test = "Widget!?"
      TXSTR = 'Widget!?'

C  use <inquire text extent> on horizontal txstr to determine:
C    ntxwd  = nominal width of text extent rectangle
C    ntxht  = nominal height of text extent rectangle
C    vtab,htab = normalized heights and widths
      CALL TXEXAL (2, PRIGHT, TXSTR, NTXWD, NTXHT, HTAB, VTAB)

C  table of alignments and paths to be tested:
C
C       hor-align  vert-align  annotation text path
C       algnh      algnv       algntp
C       ---------  ----------  ---------
C    1: left       top         left
C    2: center     cap         right
C    3: right      half        left
C    4: right      base        right
C    5: center     bottom      left
C    6: left       bottom      right
      CALL SETVAL ('1,2,3,3,2,1', ALGNH)
      CALL SETVAL ('1,2,3,4,5,5', ALGNV)
      CALL SETVAL ('1,0,1,0,1,0', ALGNTP)

      NUMLIN = 6
      CALL RNPERM (NUMLIN, PERM)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR
C  scale to fit
      CHHT = MIN (0.7/NTXWD, (0.8*YINCR)/NTXHT)
      CALL PSATCH (CHHT * NPCPWC)

C  draw and label 6 identical horizontal text rectangles,
C    using dotted lines, distinct color, dashed baseline
C    stacked vertically, and labelled 1-6
      CALL PSTXCI (1)
      CALL PSPLCI (2)
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      XLO = 0.2
      XHI = XLO + CHHT*NTXWD
      YHALF = CHHT*NTXHT / 2
      XA(1) = XLO
      XA(2) = XHI
      DO 200 YMID = YTOP, YINCR/2, -YINCR
         CALL PSLN (PLDOT)
         CALL DRWREC (XLO,XHI, YMID-YHALF, YMID+YHALF)
         CALL PSLN (PLDASH)
         YA(1) = YMID - YHALF + CHHT*VTAB(PABASE)
         YA(2) = YA(1)
         CALL PPL (2,XA,YA)
200   CONTINUE

C  draw in annotation text
      DO 300 IX = 1,NUMLIN
C  set desired y-location based on perm(ix); find bottom of rectangle
         YLO  = YTOP - YHALF - (YINCR*(PERM(IX)-1))
C  calculate txpos = annotation text position, so as to fit annotation text
C    into expected box, using values from algnh(ix),algnv(ix)
         TXPOSX = XLO + CHHT * HTAB(ALGNH(IX))
         TXPOSY = YLO + CHHT * VTAB(ALGNV(IX))

C  if ix=6 then change txpos to generate incorrect result
         IF (IX .EQ. NUMLIN) THEN
            TXPOSX = TXPOSX + 0.1 * (RNDINT(0,1) - 0.5)
         ENDIF
C  set annotation text alignment = algnh(ix), algnv(ix)
         CALL PSATAL (ALGNH(IX), ALGNV(IX))
C  set annotation text path = algntp(ix)
         CALL PSATP (ALGNTP(IX))
C  draw annotation text at txpos
         CALL PATR (TXPOSX,TXPOSY, Z,Z, TXSTR)
300   CONTINUE

      CALL SETMSG ('1 2 5 9 19 23 56 57 58 63 64 65 66', 'Explicit ' //
     1             'annotation text alignment attributes should '    //
     2             'affect the position of a horizontal annotation ' //
     3             'text rectangle in accordance with the values '   //
     4             'returned by <inquire text extent>.')

      CALL DCHPFV ('EXPLICIT ALIGNMENT FOR HORIZONTAL ANNOTATION ' //
     1             'TEXT: Which annotation text primitive is NOT ' //
     2             'aligned within the dotted annotation text '    //
     3             'extent rectangle on the dashed baseline?',
     4             NUMLIN, PERM(NUMLIN))
      CALL PEMST (102)

C  table of requested and expected alignments and paths to be tested:
C
C                  requested:             | expected:
C       text path  hor-align  vert-align  | hor-align  vert-align
C       algntp     ralgnh     ralgnv      | ealgnh     ealgnv
C       ---------  ---------  ----------  | ---------  ----------
C    1: left       normal     normal      | right      base
C    2: right      normal     normal      | left       base
C    3: left       center     normal      | center     base
C    4: right      normal     top         | left       top
C    5: left       normal     normal      | right      base
      CALL SETVAL ('0,0,2,0,0', RALGNH)
      CALL SETVAL ('0,0,0,1,0', RALGNV)
      CALL SETVAL ('3,1,2,1,3', EALGNH)
      CALL SETVAL ('4,4,4,1,4', EALGNV)

      NUMLIN = 5
C  set up PERM to randomize position
      CALL RNPERM (NUMLIN, PERM)
      YINCR = 1.0 / (NUMLIN+1)
      YTOP  = 1-YINCR

C  scale to fit
      CHHT = MIN (0.7/NTXWD, (0.8*YINCR)/NTXHT)
      CALL PSATCH (CHHT * NPCPWC)

      CALL PSTXCI (1)
      CALL PSPLCI (2)
      CALL NUMLAB (NUMLIN, 0.15, YTOP, YINCR)
      XLO = 0.2
      XHI = XLO + CHHT*NTXWD
      YHALF = CHHT*NTXHT / 2
      XA(1) = XLO
      XA(2) = XHI

C  draw and label 5 identical horizontal annotation text rectangles,
C    using dotted lines, distinct color, dashed baseline,
C    stacked vertically, and labelled 1-5
      DO 500 YMID = YTOP, YINCR/2, -YINCR
         CALL PSLN (PLDOT)
         CALL DRWREC (XLO,XHI, YMID-YHALF, YMID+YHALF)
         CALL PSLN (PLDASH)
         YA(1) = YMID - YHALF + CHHT*VTAB(PABASE)
         YA(2) = YA(1)
         CALL PPL (2,XA,YA)
500   CONTINUE

C  draw in annotation text
      DO 600 IX = 1,NUMLIN
C  set desired y-location based on perm(ix); find bottom of rectangle
         YLO  = YTOP - YHALF - (YINCR*(PERM(IX)-1))
C  calculate txpos = text position, so as to fit annotation text
C  into expected box, using values from ealgnh(ix),ealgnv(ix)
         TXPOSX = XLO + CHHT * HTAB(EALGNH(IX))
         TXPOSY = YLO + CHHT * VTAB(EALGNV(IX))
C  if ix=5 then change txpos to generate incorrect result
         IF (IX .EQ. NUMLIN) THEN
            TXPOSX = TXPOSX + 0.1 * (RNDINT(0,1) - 0.5)
         ENDIF
C  set annotation text alignment = ralgnh(ix), ralgnv(ix)
         CALL PSATAL (RALGNH(IX), RALGNV(IX))
C  set annotation text path = algntp(ix)
         CALL PSATP (ALGNTP(IX))
C  draw annotation text at txpos
         CALL PATR (TXPOSX,TXPOSY, Z,Z, TXSTR)
600   CONTINUE

      CALL SETMSG ('1 2 5 9 19 23 57 58 63 64 65 66 67', 'Implicit ' //
     1             'annotation text alignment attributes should '    //
     2             'affect the position of a horizontal annotation ' //
     3             'text rectangle in accordance with the values '   //
     4             'returned by <inquire text extent>.')

      CALL DCHPFV ('IMPLICIT ALIGNMENT FOR HORIZONTAL ANNOTATION ' //
     1             'TEXT: Which annotation text primitive is NOT ' //
     2             'aligned within the dotted annotation text '    //
     3             'extent rectangle on the dashed baseline?',
     4             NUMLIN, PERM(NUMLIN))
      CALL PEMST (102)

C  use <inquire text extent> on vertical txstr to determine:
C    ntxwd  = nominal width of text extent rectangle
C    ntxht  = nominal height of text extent rectangle
C    vtab,htab = normalized heights and widths
      CALL TXEXAL (2, PDOWN, TXSTR, NTXWD, NTXHT, HTAB, VTAB)

C  table of alignments and paths to be tested:
C
C       hor-align  vert-align  annotation text path
C       algnh      algnv       algntp
C       ---------  ----------  ---------
C    1: right      top         up
C    2: left       cap         down
C    3: center     half        up
C    4: center     base        down
C    5: left       bottom      up
C    6: right      bottom      down
      CALL SETVAL ('3,1,2,2,1,3', ALGNH)
      CALL SETVAL ('1,2,3,4,5,5', ALGNV)
      CALL SETVAL ('2,3,2,3,2,3', ALGNTP)

      NUMLIN = 6
      CALL RNPERM (NUMLIN, PERM)
      XINCR = 1.0 / (NUMLIN+1)
      XLEFT = XINCR
C  scale to fit
      CHHT = MIN (0.7/NTXHT, (0.8*XINCR)/NTXWD)

C  draw and label 6 identical vertical annotation text rectangles,
C    using dotted lines, distinct color,
C    placed adjacent left-to-right and labelled 1-6
      CALL PSTXCI (1)
      CALL PSTXAL (PACENT, PABOTT)
      CALL PSPLCI (2)
      YHI = 0.85
      YLO = YHI - CHHT*NTXHT
      XHALF = CHHT*NTXWD / 2
      YA(1) = YLO
      YA(2) = YHI
C  char height for label
      CALL PSCHH (0.05)
      DO 700 IX = 1,NUMLIN
         XMID = XLEFT + (IX-1)*XINCR
         CALL PSLN (PLDOT)
         CALL DRWREC (XMID-XHALF, XMID+XHALF, YLO,YHI)
         CALL PSLN (PLDASH)
         XA(1) = XMID
         XA(2) = XA(1)
         CALL PPL (2,XA,YA)
         WRITE (DIG2, '(I1,A)') IX, ':'
         CALL PTX (XMID, 0.90, DIG2)
700   CONTINUE

C  char height for annotation text under test
      CALL PSATCH (CHHT * NPCPWC)

C  draw in annotation text
      DO 800 IX = 1,NUMLIN
C  set desired x-location based on perm(ix); find left of rectangle
         XLO  = XLEFT - XHALF + (XINCR*(PERM(IX)-1))
C  calculate txpos = text position, so as to fit annotation text
C    into expected box, using values from algnh(ix),algnv(ix)
         TXPOSX = XLO + CHHT * HTAB(ALGNH(IX))
         TXPOSY = YLO + CHHT * VTAB(ALGNV(IX))

C  if ix=6 then change txpos to generate incorrect result
         IF (IX .EQ. NUMLIN) THEN
            TXPOSY = TXPOSY + 0.1 * (RNDINT(0,1) - 0.5)
         ENDIF
C  set annotation text alignment = algnh(ix), algnv(ix)
         CALL PSATAL (ALGNH(IX), ALGNV(IX))
C  set annotation text path = algntp(ix)
         CALL PSATP (ALGNTP(IX))
C  draw annotation text at txpos
         CALL PATR (TXPOSX,TXPOSY, Z,Z, TXSTR)
800   CONTINUE

      CALL SETMSG ('1 2 5 9 19 23 56 57 58 63 64 65 66', 'Explicit ' //
     1             'annotation text alignment attributes should '    //
     2             'affect the position of a vertical annotation '   //
     3             'text rectangle in accordance with the values '   //
     4             'returned by <inquire text extent>.')
      CALL DCHPFV ('EXPLICIT ALIGNMENT FOR VERTICAL ANNOTATION '   //
     1             'TEXT: Which annotation text primitive is NOT ' //
     2             'aligned within the dotted annotation text '    //
     3             'extent rectangle on the dashed centerline?',
     4             NUMLIN, PERM(NUMLIN))
      CALL PEMST (102)

C  table of requested and expected alignments and paths to be tested:
C
C                  requested:             | expected:
C       text path  hor-align  vert-align  | hor-align  vert-align
C       algntp     ralgnh     ralgnv      | ealgnh     ealgnv
C       ---------  ---------  ----------  | ---------  ----------
C    1: up         normal     normal      | center     base
C    2: down       normal     normal      | center     top
C    3: up         right      normal      | right      base
C    4: down       normal     half        | center     half
C    5: up         normal     normal      | center     base
      CALL SETVAL ('0,0,3,0,0', RALGNH)
      CALL SETVAL ('0,0,0,3,0', RALGNV)
      CALL SETVAL ('2,2,3,2,2', EALGNH)
      CALL SETVAL ('4,1,4,3,4', EALGNV)

      NUMLIN = 5
      CALL RNPERM (NUMLIN, PERM)
      XINCR = 1.0 / (NUMLIN+1)
      XLEFT = XINCR
C  scale to fit
      CHHT = MIN (0.7/NTXHT, (0.8*XINCR)/NTXWD)

C  draw and label 5 identical vertical annotation text rectangles,
C    using dotted lines, distinct color,
C    placed adjacent left-to-right and labelled 1-5
      CALL PSTXCI (1)
      CALL PSTXAL (PACENT, PABOTT)
      CALL PSPLCI (2)
      YHI = 0.85
      YLO = YHI - CHHT*NTXHT
      XHALF = CHHT*NTXWD / 2
C  char height for label
      CALL PSCHH (0.05)
      DO 900 IX = 1,NUMLIN
         XMID = XLEFT + (IX-1)*XINCR
         CALL PSLN (PLDOT)
         CALL DRWREC (XMID-XHALF, XMID+XHALF, YLO,YHI)
         CALL PSLN (PLDASH)
         XA(1) = XMID
         XA(2) = XA(1)
         CALL PPL (2,XA,YA)
         WRITE (DIG2, '(I1,A)') IX, ':'
         CALL PTX (XMID, 0.90, DIG2)
900   CONTINUE

C  char height for annotation text under test
      CALL PSATCH (CHHT * NPCPWC)

C  draw in annotation text
      DO 1000 IX = 1,NUMLIN
C  set desired x-location based on perm(ix); find left of rectangle
         XLO  = XLEFT - XHALF + (XINCR*(PERM(IX)-1))
C  calculate txpos = text position, so as to fit annotation text
C    into expected box, using values from ealgnh(ix),ealgnv(ix)
         TXPOSX = XLO + CHHT * HTAB(EALGNH(IX))
         TXPOSY = YLO + CHHT * VTAB(EALGNV(IX))
C  if ix=5 then change txpos to generate incorrect result
         IF (IX .EQ. NUMLIN) THEN
            TXPOSY = TXPOSY + 0.1 * (RNDINT(0,1) - 0.5)
         ENDIF
C  set annotation text alignment = ralgnh(ix), ralgnv(ix)
         CALL PSATAL (RALGNH(IX), RALGNV(IX))
C  set annotation text path = algntp(ix)
         CALL PSATP (ALGNTP(IX))
C  draw annotation text at txpos
         CALL PATR (TXPOSX,TXPOSY, Z,Z, TXSTR)
1000  CONTINUE

      CALL SETMSG ('1 2 5 9 19 23 57 58 63 64 65 66 67', 'Implicit ' //
     1             'annotation text alignment attributes should '    //
     2             'affect the position of a vertical annotation '   //
     3             'text rectangle in accordance with the values '   //
     4             'returned by <inquire text extent>.')
      CALL DCHPFV ('IMPLICIT ALIGNMENT FOR VERTICAL ANNOTATION '   //
     1             'TEXT: Which annotation text primitive is NOT ' //
     2             'aligned within the dotted annotation text '    //
     3             'extent rectangle on the dashed centerline?',
     4             NUMLIN, PERM(NUMLIN))
      CALL PEMST (102)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

