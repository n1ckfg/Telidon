C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/11                        *
C  *    TEST TITLE : Text bundle index                     *
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

C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)

C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)

C text precision
      INTEGER    PSTRP,     PCHARP,    PSTRKP
      PARAMETER (PSTRP= 0,  PCHARP= 1, PSTRKP= 2)

      INTEGER   PICSTR, TXCI, BUNEL, UNDF(3), EXPLCT,  RNDINT
      INTEGER   SZBT, BUNDIS, BUNDIF, IX, PERM(10)

      REAL      YLOC, YINCR, X(2),Y(2)

      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7


      CALL INITGL ('04.02.03.02/11')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL PSCMD (WKID, PRGB)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
      CALL PSCHH (0.03)
      CALL PSTXAL (PALEFT, PAHALF)
C  use bundled attributes
      CALL SETASF (PBUNDL)

C  szbt = maximum size of bundle table
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, SZBT, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C *** *** ***   text  index   *** *** ***

C  mark start of text bundles
      CALL PLB (1)

      CALL SETMSG ('3 4 5 6', 'A defined text index should cause '  //
     1             'the addressed entry in the bundle table to be ' //
     2             'used when rendering a text primitive.')

C  bundis = number of bundles to be displayed
      BUNDIS = MIN(8, SZBT)
C  initialize bundis to font=1, precision=stroke, expansion=0.7,
C     spacing=0.1, color = 1
      DO 60 IX = 1,BUNDIS
         CALL PSTXR (WKID, IX, 1, PSTRKP, 0.7, 0.1, 1)
60    CONTINUE

C  bundif = randomly selected bundle, set to
C     font=2, precision=stroke, expansion=1.1, spacing=0.1, color=1
      BUNDIF = RNDINT(1, BUNDIS)
      CALL PSTXR (WKID, BUNDIF, 2, PSTRKP, 1.1, 0.1, 1)

C  draw and label actual
      YINCR = 0.8/BUNDIS
      YLOC  = 0.9
      CALL NUMLAB (BUNDIS, 0.2, YLOC, YINCR)
      DO 100 IX = 1,BUNDIS
         CALL PSTXI (IX)
         CALL PTX (0.4, YLOC, 'Phings')
         YLOC  = YLOC-YINCR
100   CONTINUE

C  mark end of linetypes
      CALL PLB (2)

      CALL DCHPFV ('DEFINED TEXT INDICES: Which text primitive is ' //
     1             'different?', BUNDIS, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 7', 'An undefined text index should ' //
     1             'cause bundle number 1 in the text bundle '  //
     2             'table to be used when rendering a text '    //
     3             'primitive.')

C  set index #1 in bundle table to:
C     font=2, precision=stroke, expansion=0.8, spacing=0.2, color=2
      CALL PSTXR (WKID, 1, 2, PSTRKP, 0.8, 0.2, 2)

C  undf1,undf2,undf3 = 3 undefined text indices
      UNDF(1) = SZBT + 1
      UNDF(2) = SZBT + 10
      UNDF(3) = SZBT + 90

C  explct = number of explicit text primitive using bundle #1 =
C     random integer from 0 to 4
      EXPLCT = RNDINT(0,4)
      BUNDIS = EXPLCT+3
      CALL RNPERM (BUNDIS, PERM)

      CALL PSCHH (0.05)
      CALL PSTXAL (PACENT, PABASE)
C  draw text with bundle #1
      CALL PSTXI (1)
      CALL PTX (0.5, 0.9, 'Test text')
      X(1) = 0.3
      X(2) = 0.7
      Y(1) = 0.8
      Y(2) = 0.8
      CALL PPL (2, X, Y)

C  display interleaved below line:
C    three text primitives with bundles u1,u2,u3,
C    explct  text primitive with bundle #1

      YLOC  = 0.7
      YINCR = 0.7 / 8

      DO 500 IX = 1,BUNDIS
         BUNEL = PERM(IX)
         IF (BUNEL .LE. 3) THEN
            CALL PSTXI (UNDF(BUNEL))
         ELSE
            CALL PSTXI (1)
         ENDIF
         CALL PTX (0.5, YLOC, 'Test text')
         YLOC  = YLOC-YINCR
500   CONTINUE

      CALL DCHPFV ('UNDEFINED TEXT INDICES: How many of the text ' //
     1             'primitives below the line have the same text ' //
     2             'attributes as the reference text primitive '   //
     3             'above it?', 12, BUNDIS)

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
