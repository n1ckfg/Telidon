C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.04.01/07                        *
C  *    TEST TITLE : Annotation text color index           *
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

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    PICSTR, TXCI, CDIM,CSIZ, SZCOLT, NUMLIN
      INTEGER    TXCOL(20), IX, VISDX,VISCOL, RNDINT, TXTCI, NUMCI
      INTEGER    MAXCOL, COLEL, UNDF(3), EXPLCT, PERM(10)
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7

      REAL       RAD, CENTX,CENTY, PI, Z
      PARAMETER (CSIZ = 6, PI = 3.14159265, Z = 0.0)
      REAL       BCKCOL(CSIZ), FORCOL(CSIZ), NEWCOL(CSIZ)
      REAL       YLOC,YINCR, XA(9),YA(9), CHHT, NPCX,NPCY,NPCPWC

      CALL INITGL ('04.02.04.01/07')

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
      CALL PEXST  (102)
      CALL PCLST

      CALL POPST  (102)

      CALL SETMSG ('5 37 38', 'A defined annotation text color '    //
     1             'index should cause the addressed entry in the ' //
     2             'color table to be used when rendering an '      //
     3             'annotation text relative primitive.')

      CALL PSCMD (WKID, PRGB)
C  bckcol = background color = realized color spec for entry #0
C  forcol = foreground color = realized color spec for entry #1
      CALL PQCR (WKID, 0, CSIZ, PREALI, ERRIND, CDIM, BCKCOL)
      CALL CHKINQ ('pqcr', ERRIND)
      CALL PQCR (WKID, 1, CSIZ, PREALI, ERRIND, CDIM, FORCOL)
      CALL CHKINQ ('pqcr', ERRIND)

C  szcolt = maximum size of color table (including entry #0)
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,
     1             SZCOLT, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)
C  how many lines to draw
      NUMLIN = MIN (8, SZCOLT)

C  txcol  = random permutation of #0,#1, and numlin-2 random choices
C           from entries #2 to #szcolt-1
C  from values 2 to SZCOLT-1, pick NUMLIN-2 entries
      CALL RNBSET (NUMLIN-2, 2, SZCOLT-1, TXCOL)
C  add in 0 and 1
      TXCOL(NUMLIN-1) = 1
      TXCOL(NUMLIN)   = 0
      CALL RNPERM (NUMLIN, PERM)

C  from txcol, randomly select entry #visdx, but not the one that
C    contains 0, since this may not be re-settable.
      VISDX  = RNDINT (1,NUMLIN-1)
      VISCOL = TXCOL(VISDX)

C  ensure dialogue and labels visible
      DTXCI  = VISCOL
      CALL PSTXCI (VISCOL)
      YLOC  = 0.9
      YINCR = 0.8 / (NUMLIN-1)
      CHHT = (MIN (0.35 * YINCR, 0.05))
      CALL PSATCH (CHHT * NPCPWC)
      CALL NUMLAB (NUMLIN, .15, YLOC + 0.5*CHHT, YINCR)

C  for each color entry - set to background color and draw line
      DO 2100 IX = 1,NUMLIN
C  set entry txcol(ix) to bckcol
         TXTCI = TXCOL(PERM(IX))
         CALL PSCR (WKID, TXTCI, CDIM, BCKCOL)
         CALL PSTXCI (TXTCI)
C  randomly pick and set a precision, to ensure no interaction
         CALL PSTXPR (RNDINT (PSTRP, PSTRKP))
C  draw text line #ix with text colour index = txcol(ix)
         CALL PATR (0.2, YLOC, Z,Z, 'Defined text color')
         YLOC  = YLOC-YINCR
2100  CONTINUE


C  set entry txcol(visdx) to forcol
      CALL PSCR (WKID, VISCOL, CDIM, FORCOL)

      CALL DCHPF ('DEFINED ANNOTATION TEXT COLOR INDICES: Which ' //
     1            'annotation text line is visible?',
     2            NUMLIN, VISDX, PERM)

C  clear out last display from structure
      CALL PEMST (102)

      CALL SETMSG ('5 37 39', 'An undefined annotation text '        //
     1             'color index should cause entry number 1 in the ' //
     2             'color table to be used when rendering an '       //
     3             'annotation text relative primitive.')

C  Try to set entry #1 opposite from BCKCOL
      DO 2150 IX = 1,3
         IF (BCKCOL(IX) .GT. 0.5) THEN
            NEWCOL(IX) = 0.0
         ELSE
            NEWCOL(IX) = 1.0
         ENDIF
2150  CONTINUE

C  set entry #1 different from FORCOL - make sure that the undefined
C    entries default to *current* color-rep of #1, not just a
C    predefined color.
      IF (FORCOL(3) .GT. 0.5) THEN
         NEWCOL(3) = 0.0
      ELSE
         NEWCOL(3) = 1.0
      ENDIF

      CALL PSCR  (WKID, 1, CDIM, NEWCOL)

      CALL PQECI (WKID, 0, ERRIND, NUMCI, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      MAXCOL = 0
      DO 2200 IX = 1,NUMCI
         CALL PQECI (WKID, IX, ERRIND, IDUM1, COLEL)
         CALL CHKINQ ('pqeci', ERRIND)
         MAXCOL = MAX(MAXCOL, COLEL)
2200  CONTINUE
C  undf1,undf2,undf3 = 3 undefined, positive color indices
      UNDF(1) = MAXCOL+1
      UNDF(2) = MAXCOL+10
      UNDF(3) = MAXCOL+90

C  explct = number of explicit lines of color #1 = random integer
C    from 0 to 4
      EXPLCT = RNDINT(0,4)
      NUMLIN = EXPLCT+3
      CALL RNPERM (NUMLIN, PERM)

C  draw star with color #1
      RAD = .15
      CENTX = .5
      CENTY = .75
      DO 2400 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
2400  CONTINUE
      CALL PSPLCI (1)
      CALL PPL (6,XA,YA)

      YLOC  = 0.5
      YINCR = 0.5 / 8
      CHHT = (MIN (0.35 * YINCR, 0.05))
      CALL PSATCH (CHHT * NPCPWC)

C  display interleaved:
C    three annotation text lines of color u1,u2,u3,
C    explct annotation text lines of color #1

C  for each color entry - set to background color and draw line
      DO 2300 IX = 1,NUMLIN
         COLEL = PERM(IX)
         IF (COLEL .LE. 3) THEN
            CALL PSTXCI (UNDF(COLEL))
         ELSE
            CALL PSTXCI (1)
         ENDIF
C  randomly pick and set a precision, to ensure no interaction
         CALL PSTXPR (RNDINT (PSTRP, PSTRKP))
         CALL PATR (.1, YLOC, Z,Z, 'Undefined color')
         YLOC  = YLOC-YINCR
2300  CONTINUE

      CALL DCHPFV ('UNDEFINED ANNOTATION TEXT COLOR INDICES: How '  //
     1             'many annotation text lines are the same color ' //
     2             'as the star?', 12, NUMLIN)

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END

