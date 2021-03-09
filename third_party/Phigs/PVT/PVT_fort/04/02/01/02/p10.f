C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/10                        *
C  *    TEST TITLE : Polyline bundle index                 *
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

C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)

C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)
C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   PICSTR, TXCI, BUNEL, UNDF(3), EXPLCT
      INTEGER   SZBT, BUNDIS, BUNDIF, IX, PERM(10), RNDINT

      REAL      YLOC, YINCR, RAD,CENTX,CENTY,PI,XA(9),YA(9)

      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7


      CALL INITGL ('04.02.01.02/10')

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
C  use bundled attributes
      CALL SETASF (PBUNDL)

C  szbt = maximum size of bundle table

      CALL PQWKSL (SPECWT, ERRIND, SZBT, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C *** *** *** *** polyline index

C  mark start of polyline bundles
      CALL PLB (1)

      CALL SETMSG ('3 4 5 6', 'A defined polyline index should '    //
     1             'cause the addressed entry in the bundle table ' //
     2             'to be used when rendering a polyline.')

C  bundis = # of bundles to be displayed
      BUNDIS = MIN(8, SZBT)
C  initialize bundis to linetype=1, linewidth=1.0, color index=1
      DO 60 IX = 1,BUNDIS
         CALL PSPLR (WKID, IX, 1, 1.0, 1)
60    CONTINUE

C  bundif = randomly selected bundle, set to
C           linetype=2, linewidth=2.0, color index = 2
      BUNDIF = RNDINT(1, BUNDIS)
      CALL PSPLR (WKID, BUNDIF, 2, 2.0, 2)

C  draw and label actual
      XA(1) = 0.3
      XA(2) = 0.55
      YINCR = 0.8/BUNDIS
      YLOC  = 0.9
      CALL NUMLAB (BUNDIS, 0.2, YLOC, YINCR)
      DO 100 IX = 1,BUNDIS
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PSPLI (IX)
         CALL PPL  (2, XA,YA)
         YLOC  = YLOC-YINCR
100   CONTINUE

C  mark end of linetypes
      CALL PLB (2)

      CALL DCHPFV ('DEFINED POLYLINE INDICES: Which line is ' //
     1             'different?', BUNDIS, BUNDIF)

C  clear out last display from structure
      CALL PSEP (1)
      CALL PDELLB (1,2)

      CALL SETMSG ('3 4 5 7', 'An undefined polyline index '       //
     1             'should cause bundle number 1 in the polyline ' //
     2             'bundle table to be used when rendering a '     //
     3             'polyline.')

C  set index #1 in bundle table to linetype=2, width=2.0, color index=2
      CALL PSPLR (WKID, 1, 2, 2.0, 2)

C  undf1,undf2,undf3 = 3 undefined polyline indices
      UNDF(1) = SZBT + 1
      UNDF(2) = SZBT + 10
      UNDF(3) = SZBT + 90

C  explct = number of explicit lines of bundle #1 = random integer
C  from 0 to 4
      EXPLCT = RNDINT(0,4)
      BUNDIS = EXPLCT+3
      CALL RNPERM (BUNDIS, PERM)

C  draw star with color #1
      RAD = .15
      CENTX = .5
      CENTY = .75
      PI = 3.14159265
      DO 400 IX = 1,6
         YA(IX) = CENTY + RAD*COS((4*PI*IX)/5)
         XA(IX) = CENTX + RAD*SIN((4*PI*IX)/5)
400   CONTINUE
      CALL PSPLI (1)
      CALL PPL (6,XA,YA)

C  display interleaved: three lines with bundles u1,u2,u3,
C    and explct lines with bundle #1
      YLOC  = 0.5
      YINCR = 0.5 / 8
      XA(1) = .1
      XA(2) = .9

      DO 500 IX = 1,BUNDIS
         BUNEL = PERM(IX)
         IF (BUNEL .LE. 3) THEN
            CALL PSPLI (UNDF(BUNEL))
         ELSE
            CALL PSPLI (1)
         ENDIF
         YA(1) = YLOC
         YA(2) = YLOC
         CALL PPL (2, XA,YA)
         YLOC  = YLOC-YINCR
500   CONTINUE

      CALL DCHPFV ('UNDEFINED POLYLINE INDICES: How many '  //
     1             'of the horizontal lines have the same ' //
     2             'attributes as the star?', 12, BUNDIS)

666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
