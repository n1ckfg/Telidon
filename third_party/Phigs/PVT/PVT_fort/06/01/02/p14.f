C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/14                           *
C  *    TEST TITLE : Restore MCV                           *
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
C
C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
 
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
 
C modelling clipping operator
C                replace     intersect
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)
 
C  marker type   '.',   '+',  '*',  'o',  'x'
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)
 
      INTEGER    IDUM1,IDUM2,IDUM3, IDUM4
      INTEGER    PICSTR, TXCI, IX, RANWIN(6)
 
      REAL       HLOC(6), MCV3D(6,1), XWINLO(6), YWINLO(6)
      REAL       NOMMS, MSCF, XSIZE, YSIZE
      REAL       RDUM1,RDUM2, DELTA
 
      CALL INITGL ('06.01.02/14')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C set-up of workstation and dialogue area
      PICSTR = 111
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL POPST (PICSTR)
 
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
 
C  Adjust polymarker size and color
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS,
     1            RDUM1,RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
      MSCF = .02 / (NOMMS*WCPDC)
      CALL PSMKSC (MSCF)
      CALL PSMK   (PXMARK)
      CALL PSPMCI (3)
 
C  set modelling clipping indicator = CLIP
      CALL PSMCLI (PCLIP)
 
C  Set up structure 106 to label 6 windows
      CALL PEXST (106)
      CALL PEXST (101)
      CALL PCLST
 
C  Divide screen up into 6 square labelled areas for all test cases
      CALL WIN6 (106, 2, XSIZE, YSIZE, XWINLO, YWINLO)
 
C  *** *** *** ***   Restore MCV    *** *** *** ***
 
      DELTA = 0.05
      DO 10 IX = 1,5
         HLOC(IX) = IX*3*DELTA + 0.1
10    CONTINUE
 
      CALL RNPERM (6,RANWIN)
 
C Set up constant values for MC plane
      MCV3D(1,1) = 0.0
      MCV3D(2,1) = 0.0
      MCV3D(4,1) = 0.
      MCV3D(5,1) = 0.
      MCV3D(6,1) = 1.
 
C  *** *** *** ***  Structure 101  *** *** *** ***
 
      CALL POPST (101)
C  draw visible double polymarker
      CALL CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, RANWIN(6), DELTA, 0.5)
 
C  set MCV #1
      MCV3D(3,1) = HLOC(1)
      CALL PSMCV3 (PMCREP, 1, MCV3D)
      CALL PEXST (102)
      CALL PCLST
 
C  *** *** *** ***  Structure 102  *** *** *** ***
 
      CALL POPST (102)
C  inherit MCV #1
 
C  set MCV #2
      MCV3D(3,1) = HLOC(2)
      CALL PSMCV3 (PMCREP, 1, MCV3D)
 
C  restore MCV #1
      CALL PRMCV
 
C  draw half-visible double polymarker
      CALL CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, RANWIN(1), DELTA, HLOC(1))
 
C  set MCV #3
      MCV3D(3,1) = HLOC(3)
      CALL PSMCV3 (PMCREP, 1, MCV3D)
      CALL PEXST (103)
 
C  draw half-visible double polymarker
      CALL CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, RANWIN(2), DELTA, HLOC(3))
 
C  restore MCV #1
      CALL PRMCV
 
C  draw half-visible double polymarker
      CALL CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, RANWIN(3), DELTA, HLOC(1))
 
      CALL PCLST
 
C  *** *** *** ***  Structure 103   *** *** *** ***
 
      CALL POPST (103)
C  inherit MCV#3
 
C  set MCV #4
      MCV3D(3,1) = HLOC(4)
      CALL PSMCV3 (PMCREP, 1, MCV3D)
 
C  draw half-visible double polymarker
      CALL CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, RANWIN(4), DELTA, HLOC(4))
 
C  restore MCV #3
      CALL PRMCV
 
C  draw half-visible double polymarker
      CALL CLPAIR (XWINLO,YWINLO,XSIZE,YSIZE, RANWIN(5), DELTA, HLOC(3))
 
C  set MCV #5
      MCV3D(3,1) = HLOC(5)
      CALL PSMCV3 (PMCREP, 1, MCV3D)
      CALL PCLST
 
      CALL SETMSG ('23 40 43 51 56', '<Restore modelling clipping ' //
     1             'volume> should cause the current modelling '    //
     2             'clipping volume to be reset to the value '      //
     3             'inherited by the structure being traversed.')
 
      CALL DCHPFV ('RESTORE MCV: Which box does NOT contain ' //
     1             'exactly one marker? ', 6, RANWIN(6))
 
666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
