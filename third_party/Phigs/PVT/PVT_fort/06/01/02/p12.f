C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/12                           *
C  *    TEST TITLE : Geometry of modelling clipping        *
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
 
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
 
C modelling clipping operator
C                replace     intersect
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)
 
C marker type
      INTEGER    PPOINT,   PPLUS,   PAST,   POMARK,   PXMARK
      PARAMETER (PPOINT=1, PPLUS=2, PAST=3, POMARK=4, PXMARK=5)
 
C linetype
      INTEGER    PLSOLI,     PLDASH,     PLDOT,     PLDASD
      PARAMETER (PLSOLI = 1, PLDASH = 2, PLDOT = 3, PLDASD = 4)
 
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
      REAL       PI
      PARAMETER (PI = 3.14159265)
 
      INTEGER    PICSTR, TXCI, RNDINT, IX, JX, LVIS, RVIS, RNLOC(9)
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4
 
      REAL       MCVND(6,1), XROT,YROT, RNDRL, XA(20), YA(20)
      REAL       XF(4,4), NOMMS, MSCF, INXF(4,4), OUTXF(4,4)
      REAL       H,U,Z, RDUM1, RDUM2
      PARAMETER (H=0.5, U=1.0, Z=0.0)
 
      LOGICAL    DCHFLV
 
      CALL INITGL ('06.01.02/12')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
 
      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
 
C  Adjust polymarker size
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS, RDUM1,
     1            RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
      MSCF = .02 / (NOMMS*WCPDC)
      CALL PSMKSC (MSCF)
      CALL PEXST(102)
      CALL PCLST
      CALL POPST(102)
 
C  *** *** *** *** ***   Clipping 3D   *** *** *** *** ***
 
      CALL SETMSG ('23 29 40 41 42 52 53 58 59', 'A polymarker '      //
     1             'should be clipped if and only if (1) its WC '     //
     2             'position is outside the current WC modelling '    //
     3             'clipping volume as set by <set modelling '        //
     4             'clipping volume 3> and (2) the current clipping ' //
     5             'indicator = CLIP.')
 
C  set up transformation to change xy plane into a plane slightly
C  rotated about .5,.5,0 and then shifted so as to contain
C  (.5, .5, .5):
 
      XROT = RNDRL(-PI/9,PI/9)
      YROT = RNDRL(-PI/9,PI/9)
 
      CALL PBLTM3 (H,H,Z, Z,Z,H, XROT,YROT,Z, U,U,U, ERRIND, XF)
      CALL CHKINQ ('pbltm3', ERRIND)
 
C  set local transformation to xf
      CALL PSLMT3 (XF,PCREPL)
 
C  set modelling clipping volume to xy plane in MC:
C    point  = 0,0,0
C    vector = 0,0,1
      MCVND(1,1) = Z
      MCVND(2,1) = Z
      MCVND(3,1) = Z
      MCVND(4,1) = Z
      MCVND(5,1) = Z
      MCVND(6,1) = U
      CALL PSMCV3 (PMCREP, 1, MCVND)
 
C  Generate matrices to shift along Z axis (in or out)
      CALL ETR3 (0.,0., 0.01,INXF)
      CALL ETR3 (0.,0.,-0.01,OUTXF)
 
      CALL CLPMK5 ('3', MCVND, XF, INXF,OUTXF)
 
C  *** *** *** *** ***   Clipping 2D   *** *** *** *** ***
 
      CALL SETMSG ('23 29 40 41 42 49 52 53 58 59', 'A polymarker ' //
     1             'should be clipped if and only if (1) its WC '   //
     2             'position is outside the current WC modelling '  //
     3             'clipping volume as set by <set modelling '      //
     4             'clipping volume> and (2) the current clipping ' //
     5             'indicator = CLIP.')
 
C  set up transformation to change y=.5 plane into a plane slightly
C  rotated about .5,.5,0 and then shifted so as to contain
C  (.5, .5, .5):
 
      XROT = RNDRL(7*PI/18, 11*PI/18)
      YROT = RNDRL(-PI/9,PI/9)
 
      CALL PBLTM3 (H,H,Z, Z,Z,H, XROT,YROT,Z, U,U,U, ERRIND, XF)
      CALL CHKINQ ('pbltm3', ERRIND)
 
C  set local transformation to xf
      CALL PSLMT3 (XF,PCREPL)
 
C  Set Clipping plane
      MCVND(1,1) = Z
      MCVND(2,1) = H
      MCVND(3,1) = Z
      MCVND(4,1) = U
      CALL PSMCV (PMCREP, 1, MCVND)
 
      CALL CLPMK5 ('2', MCVND, XF, INXF,OUTXF)
 
C  *** *** *** *** ***  Zero Half Space  *** *** *** *** ***
 
      CALL SETMSG ('39 41 43', 'In <set modelling clipping volume>, ' //
     1             'an empty list of half-spaces should denote all '  //
     2             'of WC space.')
 
      XA(1) = 0.5
      YA(1) = 0.0
      XA(2) = 0.5
      YA(2) = 1.0
      CALL PSLN (PLDOT)
      CALL PPL  (2, XA,YA)
      CALL PSMK (PPLUS)
      CALL PSMCLI (PCLIP)
 
C  Set 2D Clipping plane
      MCVND(1,1) =  0.5
      MCVND(2,1) =  0.5
      MCVND(3,1) = -1.0
      MCVND(4,1) =  0.0
      CALL PSMCV (PMCREP, 1, MCVND)
 
C  Intersect with zero 3D Clipping planes
      MCVND(1,1) =  0.5
      MCVND(2,1) =  0.5
      MCVND(3,1) =  0.0
      MCVND(4,1) =  1.0
      MCVND(5,1) =  0.0
      MCVND(6,1) =  0.0
      CALL PSMCV3 (PMCINT, 0, MCVND)
 
C  MCV should be unchanged:
      CALL RNPERM (9, RNLOC)
      LVIS = RNDINT(2,4)
      RVIS = RNDINT(1, 9-LVIS)
 
C  draw pairs of markers, left visible, right clipped
      DO 300 IX = 1, LVIS
         JX = IX + LVIS
         XA(IX) = 0.4
         XA(JX) = 0.6
         YA(IX) = RNLOC(IX) / 10.0
         YA(JX) = YA(IX)
300   CONTINUE
      CALL PPM (2*LVIS,XA,YA)
 
C  Set 2D Clipping plane to all WC space
      MCVND(1,1) =  0.5
      MCVND(2,1) =  0.5
      MCVND(3,1) =  0.0
      MCVND(4,1) =  1.0
      CALL PSMCV (PMCREP, 0, MCVND)
 
C  draw pairs of markers, left visible, right clipped
      DO 310 IX = 1, RVIS
         JX = IX + RVIS
         XA(IX) = 0.4
         XA(JX) = 0.6
         YA(IX) = RNLOC(IX+LVIS) / 10.0
         YA(JX) = YA(IX)
310   CONTINUE
      CALL PPM (2*RVIS,XA,YA)
 
      LVIS = LVIS + RVIS
 
      IF (DCHFLV ('EMPTY LIST OF HALF-SPACES: How many markers are ' //
     1            'visible to the left of the dotted line?', 30, LVIS))
     3   GOTO 666
 
      CALL DCHPFV ('EMPTY LIST OF HALF-SPACES: How many markers ' //
     1             'are visible to the right of the dotted line?',
     2             30, RVIS)
 
666   CONTINUE
C  wrap it up.
      CALL ENDIT
 
      END
 
