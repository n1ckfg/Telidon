C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/15                           *
C  *    TEST TITLE : Network inheritance and               *
C  *                 initialization of modelling clipping  *
C  *                 volume                                *
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

C composition type
C                preconcatenate     postconcatenate    replace
      INTEGER    PCPRE,             PCPOST,            PCREPL
      PARAMETER (PCPRE = 0,         PCPOST = 1,        PCREPL = 2)

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

C modelling clipping operator
C                replace     intersect
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)

C marker type
      INTEGER    PPOINT,    PPLUS,     PAST,    POMARK,    PXMARK
      PARAMETER (PPOINT=1,  PPLUS=2,   PAST=3,  POMARK=4,  PXMARK=5)

      INTEGER    PICSTR, TXCI, IX, PERM(14), SIZ, OP
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, EXPVAL(14)

      REAL       NOMMW, Z, U, XFORM(3,3), YLOCEL
      REAL       XLOC(5), MCV(4,2), MCV3(6,1)
      REAL       RDUM1, RDUM2, FXPTY, SHIFTY

      Z = 0.0
      U = 1.0

      CALL INITGL ('06.01.02/15')
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
      CALL PSVWI (1)
      CALL SETASF (PINDIV)

C  use <inquire polymarker facilities> to determine :
C     nommw = nominal marker-size  (DC)
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3,
     1            NOMMW, RDUM1, RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)

C  *** *** *** ***   modelling clipping volume   *** *** *** ***
C
C  set up PERM to randomize position of polymarkers
      CALL RN1SHF (14, PERM)
C  set up CSS:

      CALL SETRVS ('0.2,0.25,0.3,0.35,0.4', XLOC, SIZ)

C  structure #101 ----------
      CALL PSMCLI (PCLIP)
      CALL PSMK (PPLUS)
C  set marker size scale factor equivalent to WC = 0.03
      CALL PSMKSC (0.025 / (NOMMW * WCPDC))

      CALL LOCNPM (5,PERM(1), XLOC)
      CALL PEXST (102)
      CALL LOCNPM (5,PERM(9), XLOC)

C  set MCV: point = 0.22,0; vector = -1,0
      OP = PMCREP
      MCV(1,1) = 0.22
      MCV(2,1) = 0.
      MCV(3,1) = -1.
      MCV(4,1) = 0.
      CALL PSMCV (OP, 1, MCV)

      CALL LOCNPM (5,PERM(10), XLOC)

C  set local transformation to make markers #11,12 distinguishable
      FXPTY = YLOCEL(PERM(5))
      SHIFTY = YLOCEL(PERM(11)) - YLOCEL(PERM(5))
      CALL PBLTM (Z, FXPTY, Z, SHIFTY, Z, U, U, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)

      CALL PEXST (104)
C  re-set local transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)

      CALL LOCNPM (5,PERM(13), XLOC)
      CALL LOCNPM (5,PERM(14), XLOC)
      CALL PEXST (105)
      CALL PCLST

C  structure #102 ----------
      CALL POPST (102)
      CALL LOCNPM (5,PERM(2), XLOC)

C  set MCV: point = 0.27,0; vector = -1,0
      OP = PMCREP
      MCV(1,1) = 0.27
      MCV(2,1) = 0.
      MCV(3,1) = -1.
      MCV(4,1) = 0.
      CALL PSMCV (OP, 1, MCV)

      CALL PEXST (103)
      CALL LOCNPM (5,PERM(8), XLOC)
      CALL PCLST

C  structure #103 ----------
      CALL POPST (103)
      CALL LOCNPM (5,PERM(3), XLOC)

C  set MCV3: point = 0.32,0,0; vector = -1,0,1
      OP = PMCREP
      MCV3(1,1) = 0.32
      MCV3(2,1) = 0.
      MCV3(3,1) = 0.
      MCV3(4,1) = -1.
      MCV3(5,1) = 0.
      MCV3(6,1) = 1.
      CALL PSMCV3 (OP, 1, MCV3)

      CALL LOCNPM (5,PERM(4), XLOC)
      CALL PEXST (104)
      CALL LOCNPM (5,PERM(7), XLOC)
      CALL PCLST

C  structure #104 ----------
      CALL POPST (104)
      CALL LOCNPM (5,PERM(5), XLOC)

C  set MCV: point = 0.37,0; vector = -1,0
      OP = PMCREP
      MCV(1,1) = 0.37
      MCV(2,1) = 0.
      MCV(3,1) = -1.
      MCV(4,1) = 0.
      CALL PSMCV (OP, 1, MCV)

      CALL LOCNPM (5,PERM(6), XLOC)
      CALL PCLST

C  structure #105 ----------
      CALL POPST (105)
      CALL PSMCLI (PNCLIP)
      CALL PSMK (PXMARK)
      CALL NUMLAB (14, .10, YLOCEL(1), 1.0/15)
      CALL SETRVS ('0.5,0.55,0.6,0.65,0.7', XLOC, SIZ)

C  Expected number of markers (except #14, deliberately incorrect):
      CALL SETVS ('5,5,2,3,3,4,3,2,5,1,1,4,1,2', EXPVAL, SIZ)
      DO 300 IX = 1, 14
         CALL LOCNPM (EXPVAL(IX), PERM(IX), XLOC)
300   CONTINUE
      CALL PCLST

      CALL SETMSG ('23 26 40 41 42 43 49 50 51 57 58 59', 'The '  //
     1             'current modelling clipping volume should be ' //
     2             'saved and restored by <execute structure> '   //
     3             'during traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR MCV: On '    //
     1             'which line is the number of plus-markers NOT ' //
     2             'equal to that of the cross-markers?',
     3              14, PERM(14))

C  *** *** *** ***   modelling clipping indicator   *** *** *** ***

      DO 400 IX = 101, 105
         CALL PEMST (IX)
400   CONTINUE

C  set up PERM to randomize position of polymarkers
      CALL RN1SHF (14, PERM)

      XLOC(1) = 0.2

C  structure #101 ----------
      CALL POPST (101)
      CALL PSVWI (1)
      CALL SETASF (PINDIV)

C  set MCV, clip out all of MC-space:
      OP = PMCREP
      MCV(1, 1) = XLOC(1) - 0.01
      MCV(2, 1) = Z
      MCV(3, 1) = -U
      MCV(4, 1) = Z
      MCV(1, 2) = XLOC(1) + 0.01
      MCV(2, 2) = Z
      MCV(3, 2) = U
      MCV(4, 2) = Z
      CALL PSMCV (OP, 1, MCV)

      CALL PSMK (PPLUS)

C  set marker size scale factor equivalent to WC = 0.03
      CALL PSMKSC (0.03 / (NOMMW * WCPDC))
      CALL LOCPPM (PERM(1), XLOC)
      CALL PEXST (102)
      CALL LOCPPM (PERM(9), XLOC)
      CALL PSMCLI (PCLIP)
      CALL LOCPPM (PERM(10), XLOC)

C  set local transformation to make markers #11,12 distinguishable
      FXPTY = YLOCEL (PERM(5))
      SHIFTY = YLOCEL (PERM(11)) - YLOCEL(PERM(5))
      CALL PBLTM(Z, FXPTY, Z, SHIFTY, Z, U, U, ERRIND, XFORM)
      CALL CHKINQ ('pbltm', ERRIND)
      CALL PSLMT (XFORM, PCREPL)

      CALL PEXST (104)

C  re-set local transformation to identity
      CALL IDMAT (3, XFORM)
      CALL PSLMT (XFORM, PCREPL)
      CALL LOCPPM (PERM(13), XLOC)
      CALL LOCPPM (PERM(14), XLOC)
      CALL PEXST (105)
      CALL PCLST

C  structure #102 ----------
      CALL POPST (102)
      CALL LOCPPM (PERM(2), XLOC)
      CALL PSMCLI (PCLIP)
      CALL PEXST (103)
      CALL LOCPPM (PERM(8), XLOC)
      CALL PCLST

C  structure #103 ----------
      CALL POPST (103)
      CALL LOCPPM (PERM(3), XLOC)
      CALL PSMCLI (PNCLIP)
      CALL LOCPPM (PERM(4), XLOC)
      CALL PEXST (104)
      CALL LOCPPM (PERM(7), XLOC)
      CALL PCLST

C  structure #104 ----------
      CALL POPST (104)
      CALL LOCPPM (PERM(5), XLOC)
      CALL PSMCLI (PCLIP)
      CALL LOCPPM (PERM(6), XLOC)
      CALL PCLST

C  structure #105 ----------
      CALL POPST (105)
      CALL PSMCLI (PNCLIP)
      CALL NUMLAB (14, .10, YLOCEL(1), 1.0/15)

      XLOC(1) = XLOC(1) + 0.1

C  All y-locations correspond to PERM as above.
      CALL SETVS ('0,0,1,0,0,1,0,1,0,1,1,1,1,0', EXPVAL, SIZ)
      DO 500 IX = 1, 14
         IF (EXPVAL(IX) .EQ. 1) CALL LOCPPM (PERM(IX), XLOC)
500   CONTINUE

      CALL SETMSG ('29 52 53 54 55 57 58 59', 'The current '       //
     1             'modelling clipping indicator should be saved ' //
     2             'and restored by <execute structure> during '   //
     3             'traversal.')

      CALL DCHPFV ('STRUCTURE NETWORK INHERITANCE FOR CLIPPING '     //
     1             'INDICATOR: Which line does NOT contain exactly ' //
     2             'one marker?', 14, PERM(14))

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
