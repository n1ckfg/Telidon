C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/11                           *
C  *    TEST TITLE : Visual effect of modelling clipping   *
C  *                 facilities                            *
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
      INTEGER    PMCREP,     PMCINT
      PARAMETER (PMCREP = 1, PMCINT = 2)
C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)
C composition type
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
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
 
C maximum number of planes to be tested
      INTEGER    TSTMAX
      PARAMETER (TSTMAX = 500)
 
      REAL       PI
      PARAMETER (PI = 3.14159265)
 
      INTEGER    PICSTR, TXCI, IX, MAXPL, I, MCLPOP,  NLRMCT, LRMCOP(50)
      INTEGER    NOL, NLIMCT,  LIMCOP(50), VISCT, LISOP(6),NMCLHS
      INTEGER    NUMPL, MINMRK, MAXMRK, RNDINT, NSIZ
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, NUMOP
 
      REAL       RAD, ANG, COSANG, SINANG, MC2D(4,1)
      REAL       HS(6,TSTMAX), RNDRL, X(15),Y(15), RDUM1, RDUM2
      REAL       IDXF(4,4), XF(4,4), NOMMS, MSCF
 
      LOGICAL    DYN
 
      CHARACTER  TXSTR*23, THISOP*3
 
      CALL INITGL ('06.01.02/11')
 
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
C
C  adjust polymarker size
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS, RDUM1,
     1            RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
      MSCF = .02 / (NOMMS*WCPDC)
      CALL PSMKSC (MSCF)
 
      CALL PEXST(102)
      CALL PCLST
      CALL POPST(102)
 
C    <inquire modelling clipping facilities> to determine
C      maxpl  = maximum# of planes
C      NOL    = # of operators
      CALL  PQMCLF (0, ERRIND, MAXPL, NOL, MCLPOP)
      CALL  CHKINQ ('pqmclf', ERRIND)
 
C    lrmcop = list of registered modelling clipping combination
C             operators > 2
C    limcop = list of implementor modelling clipping combination
C             operators < 1
      NLIMCT = 0
      NLRMCT = 0
      DO 100 I=1,NOL
         CALL PQMCLF ( I, ERRIND, NMCLHS, NOL, MCLPOP )
         CALL CHKINQ ('pqmclf', ERRIND)
 
         IF ( MCLPOP .GT. 2) THEN
            NLRMCT = NLRMCT + 1
            LRMCOP(NLRMCT) = MCLPOP
         ELSE IF ( MCLPOP .LT. 1) THEN
            NLIMCT = NLIMCT + 1
            LIMCOP(NLIMCT) = MCLPOP
         ENDIF
100   CONTINUE
 
C  *** *** ***  Specified volume with Max Planes  *** *** ***
 
C  numpl = actual number of planes to be tested
C  minmrk = minimum number of visible markers = 2
C  maxmrk = maximum number of visible markers = min(12, 0.75*numpl)
C  rad = WC radius of prism = 0.4
      NUMPL = MIN(MAXPL,TSTMAX)
      MINMRK = 2
      MAXMRK = MIN(12, (3*NUMPL)/4)
      RAD = 0.4
 
      CALL SETMSG ('23 35 40 41 42 43 59', 'The program should be '   //
     1             'able to replace the current modelling clipping '  //
     2             'volume by a specified modelling clipping volume ' //
     3             'that uses up to the reported maximum number of '  //
     4             'distinct planes.')
 
C  set local transformation:
      CALL EBLTM3 (0.,0.,0., 0.5,0.5,0.5, PI/2.,0.,0., RAD,RAD,RAD, XF)
      CALL PSLMT3 (XF,PCREPL)
 
      DO 110 IX = 1,NUMPL
         ANG = IX*2*PI / NUMPL
         COSANG = COS(ANG)
         SINANG = SIN(ANG)
 
         HS(1,IX) = COSANG
         HS(2,IX) = RNDRL(-5.,5.)
         HS(3,IX) = SINANG
         HS(4,IX) = -COSANG
         HS(5,IX) = 0.
         HS(6,IX) = -SINANG
  110 CONTINUE
 
C  set up current MCV to be replaced by next <Set MCV>:
      MC2D(1,1) = -.5
      MC2D(2,1) = 0.0
      MC2D(3,1) = 1.
      MC2D(4,1) = 0.
      CALL PSMCV ( PMCREP, 1, MC2D )
 
C  set 3D MCV
      CALL PSMCV3 ( PMCREP, NUMPL, HS )
 
C  set local transformation back to identity
      CALL IDMAT (4,IDXF)
      CALL PSLMT3 (IDXF,PCREPL)
 
C  set modelling clipping indicator = CLIP
      CALL PSMCLI ( PCLIP )
 
C  number of unclipped markers
      VISCT = RNDINT(MINMRK,  MAXMRK)
 
      CALL CLPGON (VISCT,NUMPL,RAD)
 
      CALL DCHPFV ('MAXIMUM NUMBER OF SPECIFIED DISTINCT PLANES: ' //
     1             'How many markers are visible?', NUMPL, VISCT)
 
C  *** *** ***  Current volume with Max Planes  *** *** ***
 
      CALL PEMST (102)
 
      CALL SETMSG ('23 35 40 41 42 43 59', 'The intersection '       //
     1             'operator should be able to construct a current ' //
     2             'modelling clipping volume that uses up to the '  //
     3             'reported maximum number of distinct planes.')
 
C  set local transformation:
      CALL PSLMT3 (XF,PCREPL)
 
C  construct current MCV
      DO 130 IX = 1,NUMPL
         CALL PSMCV3 ( PMCINT, 1, HS(1,IX) )
  130 CONTINUE
 
C  set local transformation back to identity
      CALL IDMAT (4,IDXF)
      CALL PSLMT3 (IDXF,PCREPL)
C  set modelling clipping indicator = CLIP
      CALL PSMCLI ( PCLIP )
C  number of unclipped markers
      VISCT = RNDINT(MINMRK,  MAXMRK)
 
      CALL CLPGON (VISCT,NUMPL,RAD)
 
      CALL DCHPFV ('MAXIMUM NUMBER OF CURRENT DISTINCT PLANES: ' //
     1             'How many markers are visible?', NUMPL, VISCT)
 
C  *** *** *** implementor defined or registered operators   *** *** ***
      IF ((NLRMCT .EQ. 0) .AND. ( NLIMCT .EQ. 0)) THEN
         CALL INMSG ('No registered or implementor defined '    //
     1               'combination operators are supported for ' //
     2               'setting modelling clipping volume.')
         GOTO 170
      ENDIF
 
      CALL PEMST (102)
 
      TXSTR = 'WHERE''S THE REST OF ME?'
 
C  Set up four square areas
      CALL PSPLCI (3)
      CALL SETRVS ('.01,.01,.99,.99,.01', X, NSIZ)
      CALL SETRVS ('.01,.99,.99,.01,.01', Y, NSIZ)
      CALL PPL (NSIZ, X,Y)
 
C  Cross
      X(1) = 0.5
      Y(1) = 0.99
      X(2) = 0.5
      Y(2) = 0.01
      CALL PPL (2,X,Y)
      X(1) = 0.01
      Y(1) = 0.5
      X(2) = 0.99
      Y(2) = 0.5
      CALL PPL (2,X,Y)
 
C  Label each quadrant
      CALL VISLAB ('inside previous MCV',  'L', 0.03,.3,.9, .95)
      CALL VISLAB ('outside new MCV',      'L', 0.03,.3,.85,.9)
      CALL VISLAB ('outside previous MCV', 'L', 0.53,.8,.9, .95)
      CALL VISLAB ('outside new MCV',      'L', 0.53,.8,.85,.9)
      CALL VISLAB ('inside previous MCV',  'L', 0.03,.3,.08,.13)
      CALL VISLAB ('inside new MCV',       'L', 0.03,.3,.03,.08)
      CALL VISLAB ('outside previous MCV', 'L', 0.53,.8,.08,.13)
      CALL VISLAB ('inside new MCV',       'L', 0.53,.8,.03,.08)
 
C  set previous MCV
      MC2D(1,1) = 0.5
      MC2D(2,1) = 0.5
      MC2D(3,1) = -1.
      MC2D(4,1) = 0.
      CALL PSMCV ( PMCREP, 1, MC2D )
C  label element 101
      CALL PLB (101)
C  set dummy MCV
      CALL PSMCV ( PMCREP, 1, MC2D )
C  set clipping on
      CALL PSMCLI ( PCLIP )
 
C  text centered at 0.5,0.5
      CALL PSCHH  (0.03)
      CALL PSTXAL (PACENT,PAHALF)
      CALL PSTXFN (1)
      CALL PSTXPR (PSTRKP)
      CALL PTX (0.5,0.5, TXSTR)
 
C Position element pointer at  top
      CALL PSEP (1)
C  edit mode = replace
      CALL PSEDM (PREPLC)
C  position element pointer at label 101
      CALL PSEPLB (101)
C  increment element pointer by 1 to allow replacement
C     of second <set MCV>
      CALL POSEP (1)
C  clipping plane for operator to be tested
      MC2D(1,1) = 0.5
      MC2D(2,1) = 0.5
      MC2D(3,1) = 0.
      MC2D(4,1) = -1.0
 
C  *** *** *** *** Registered Operators  *** *** *** ***
 
      IF (NLRMCT .EQ. 0) THEN
         CALL INMSG ('No registered combination operators ' //
     1               'are supported for setting modelling ' //
     2               'clipping volume.')
         GOTO 160
      ENDIF
 
      CALL SETMSG ('35 40 44 57', 'The effect of combination '  //
     1             'operators > 2 in <set modelling clipping '  //
     2             'volume> should be as described in the ISO ' //
     3             'register.')
 
      NUMOP = MIN(NLRMCT, 8)
      CALL RNSET (NUMOP,NLRMCT,LISOP)
      DO 150 I=1,NUMOP
         CALL PSMCV ( LRMCOP(LISOP(I)), 1, MC2D )
         WRITE (THISOP, '(I3)') LRMCOP(LISOP(I))
 
         IF (.NOT. DYN ('REGISTERED OPERATORS: Is the clipping of ' //
     1                  'the centered text primitive "' // TXSTR    //
     2                  '" consistent with the description of '     //
     3                  'combination operator #' // THISOP          //
     4                  ', as documented in the ISO register?')) THEN
            CALL FAIL
            GOTO 160
         ENDIF
150   CONTINUE
      CALL PASS
 
160   CONTINUE
 
C  *** *** *** Implementor-defined Operators *** *** ***
 
      IF (NLIMCT .EQ. 0) THEN
           CALL INMSG ('No implementor-defined combination '  //
     1                 'operators are supported for setting ' //
     2                 'modelling clipping volume.')
         GOTO 170
      ENDIF
C
      CALL SETMSG ('35 40 45 57', 'The effect of combination '  //
     1             'operators < 1 in <set modelling clipping '  //
     2             'volume> should be as described in the '     //
     3             'implementor''s documentation.')
 
      NUMOP = MIN(NLIMCT, 8)
      CALL RNSET (NUMOP,NLIMCT,LISOP)
      DO 180 I=1,NUMOP
         CALL PSMCV ( LIMCOP(LISOP(I)), 1, MC2D )
         WRITE (THISOP, '(I3)') LIMCOP(LISOP(I))
 
         IF (.NOT. DYN ('IMPLEMENTATION OPERATORS: Is the clipping ' //
     1                  'of the centered text primitive "' // TXSTR  //
     2                  '" consistent with the description of '     //
     3                  'combination operator #' // THISOP          //
     4                  ', as documented by the implementor?')) THEN
            CALL FAIL
            GOTO 170
         ENDIF
180   CONTINUE
      CALL PASS
 
170   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
