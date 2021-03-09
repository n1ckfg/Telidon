C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/13                           *
C  *    TEST TITLE : Invalid clipping specifications       *
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
C                preconcatenate  postconcatenate  replace
      INTEGER    PCPRE,          PCPOST,          PCREPL
      PARAMETER (PCPRE = 0,      PCPOST = 1,      PCREPL = 2)
 
C clipping indicator
C                noclip        cllip
      INTEGER    PNCLIP,       PCLIP
      PARAMETER (PNCLIP=0,     PCLIP=1)
 
C modelling clipping operator
C                replace,      intersect
      INTEGER    PMCREP,       PMCINT
      PARAMETER (PMCREP=1,     PMCINT=2)
 
      INTEGER    PICSTR, TXCI, IX, MAXPL, NSZ
      INTEGER    MCLPOP, OL, WINLIS(6), WINID, THISMC
      INTEGER    NGWIN, OP, MINOP, MAXOP, PGMMAX
      INTEGER    IDUM1, IDUM2
      PARAMETER (PGMMAX = 500)
 
      REAL       XA(10), YA(10), XWINLO(6), YWINLO(6), XSIZ, YSIZ
      REAL       MCV(4,PGMMAX), MCV3(6,PGMMAX), XF(4,4), H, Z
      REAL       ANG, PI, SANG,CANG
 
      PARAMETER (Z=0.0, H=0.5, PI=3.14159265)
 
      CALL INITGL ('06.01.02/13')
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801, TXCI)
 
      CALL POPST (PICSTR)
C  by convention, view #1  is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
 
      CALL PEXST (106)
      CALL PEXST (102)
      CALL PCLST
 
C  Set up 6 windows on the screen
      CALL WIN6 (106, 1, XSIZ, YSIZ, XWINLO, YWINLO)
 
      CALL POPST (102)
 
C  minop = minimum operator (lowest value)
C  maxop = maximum operator (highest value)
      CALL PQMCLF (0, ERRIND, MAXPL, OL, IDUM2)
      CALL CHKINQ ('pqmclf', ERRIND)
      MINOP =  1000
      MAXOP = -1000
      DO 100 IX = 1 , OL
         CALL PQMCLF (IX, ERRIND, IDUM1, IDUM2, MCLPOP)
         CALL CHKINQ ('pqmclf', ERRIND)
         IF (MCLPOP .LE. MINOP) MINOP = MCLPOP
         IF (MCLPOP .GE. MAXOP) MAXOP = MCLPOP
100   CONTINUE
 
C  coordinates for zigzag polyline:
      DO 110 IX = 1, 8
         XA(IX) = 0.2 + 0.6 * MOD(IX, 2)
         YA(IX) = IX / 9.0
110   CONTINUE
 
C *** *** *** ***   unsupported combination operator   *** *** *** ***
 
      CALL SETMSG ('23 26 38 40 43 46', 'If a <set modelling '  //
     1             'clipping volume> element specifies an '     //
     2             'unsupported combination operator, then it ' //
     3             'should be ignored upon traversal.')
 
C  set clip indicator on
      CALL PSMCLI (PCLIP)
C  winlis = randomized list of 1-6
      CALL RNPERM (6, WINLIS)
 
      DO 120 WINID = 1, 6
         THISMC = WINLIS(WINID)
         CALL EBLTM3 (Z,Z,Z, XWINLO(WINID),YWINLO(WINID),H,
     2                Z,Z,Z, XSIZ,XSIZ,XSIZ, XF)
         CALL PSLMT3 (XF, PCREPL)
 
C   <set modelling clipping volume> using:
C      operator = replace, point = 0.5,0.5, vector = -1,0
         OP = PMCREP
         CALL SETRVS ('0.5,0.5,-1,0', MCV(1,1), NSZ)
         CALL PSMCV (OP, 1, MCV)
 
C if (thismc = 1), <set modelling clipping volume> using:
C      operator = replace, point = 0.7,0.5, vector = -1,0
         IF (THISMC .EQ. 1) THEN
            OP = PMCREP
            CALL SETRVS ('0.7,0.5,-1,0', MCV(1,1), NSZ)
            NGWIN = WINID
            CALL PSMCV (OP, 1, MCV)
 
C if (thismc = 2), normal clip: do nothing
         ELSEIF (THISMC .EQ. 2) THEN
 
C if (thismc = 3), operator WAY too low:
         ELSEIF (THISMC .EQ. 3) THEN
            OP = MINOP - 303
            CALL SETRVS ('0.5,0.5,0.5,0,1,0', MCV3(1,1), NSZ)
            CALL PSMCV3 (OP, 1, MCV3)
 
C if (thismc = 4), operator way too high:
         ELSEIF (THISMC .EQ. 4) THEN
            OP = MAXOP + 1000
            CALL SETRVS ('0.5,0.5,0,-1', MCV(1,1), NSZ)
            CALL PSMCV (OP, 1, MCV)
 
C if (thismc = 5) operator slightly too low:
         ELSEIF (THISMC .EQ. 5) THEN
            OP = MINOP - 1
            CALL SETRVS ('0.5,0.5,0.5,1,1,0', MCV3(1,1), NSZ)
            CALL PSMCV3 (OP, 1, MCV3)
 
C if (thismc = 6) operator slightly too high:
         ELSEIF (THISMC .EQ. 6) THEN
            OP = MAXOP + 1
            CALL SETRVS ('0.5,0.5,1,-1', MCV(1,1), NSZ)
            CALL PSMCV (OP, 1, MCV)
         ENDIF
 
C  draw polyline using xa, ya
         CALL PPL (8, XA, YA)
120   CONTINUE
 
C pass/fail depending on (operator response = ngwin)
      CALL DCHPFV ('UNSUPPORTED COMBINATION OPERATOR: In which ' //
     1             'square is the polyline clipped differently?',
     2              6, NGWIN)
 
      CALL PEMST (102)
 
C *** *** *** ***   # distinct planes exceed maximum   *** *** *** ***
 
      IF (MAXPL .GE. PGMMAX) THEN
         CALL INMSG ('Skipping test of effect of exceeding maximum '  //
     1               'number of distinct planes, because of program ' //
     2               'storage limits.')
         GOTO 400
      ENDIF
 
      CALL SETMSG ('23 26 38 40 43 47', 'If a <set modelling '   //
     1             'clipping volume> element attempts to '       //
     2             'generate a current MCV with more distinct '  //
     3             'planes than the maximum supported, then it ' //
     4             'should be ignored upon traversal.')
 
C  set clip indicator on
      CALL PSMCLI (PCLIP)
C  winlis = randomized list of 1-6
      CALL RNPERM (6, WINLIS)
 
      DO 130 WINID = 1, 6
         THISMC = WINLIS(WINID)
         CALL EBLTM3 (Z,Z,Z, XWINLO(WINID),YWINLO(WINID),H,
     2                Z,Z,Z, XSIZ,XSIZ,XSIZ, XF)
         CALL PSLMT3 (XF, PCREPL)
 
C   <set modelling clipping volume> using:
C      operator = replace, point = 0.5,0.5, vector = -1,0
         OP = PMCREP
         CALL SETRVS ('0.5,0.5,-1,0', MCV(1,1), NSZ)
         CALL PSMCV (OP, 1, MCV)
 
C if (thismc = 1), <set modelling clipping volume> using:
C      operator = replace, point = 0.5,0.5; vector = -1,0
         IF (THISMC .EQ. 1) THEN
            OP = PMCREP
            CALL SETRVS ('0.5,0.5,0,-1', MCV(1,1), NSZ)
            NGWIN = WINID
            CALL PSMCV (OP, 1, MCV)
 
C if (thismc = 2), normal clip: do nothing
         ELSEIF (THISMC .EQ. 2) THEN
 
C if (thismc = 3), exceed maximum with 2D replace:
C half-spaces: polygon centered at 0.5,0.5, radius = 0.1,
C              with maxpl+1 sides
         ELSEIF (THISMC .EQ. 3) THEN
            DO 310 IX = 1,MAXPL+1
               ANG = IX*2*PI / (MAXPL+1)
               SANG = SIN(ANG)
               CANG = COS(ANG)
               MCV(1,IX) = .5 + 0.1*CANG
               MCV(2,IX) = .5 + 0.1*SANG
               MCV(3,IX) = -CANG
               MCV(4,IX) = -SANG
310         CONTINUE
 
            CALL PSMCV (PMCREP, MAXPL+1, MCV)
 
C if (thismc = 4), exceed maximum with 2D intersect:
C half-spaces: polygon centered at 0.5,0.5, radius = 0.1,
C              with maxpl sides
         ELSEIF (THISMC .EQ. 4) THEN
            DO 320 IX = 1,MAXPL
               ANG = IX*2*PI / MAXPL
               SANG = SIN(ANG)
               CANG = COS(ANG)
               MCV(1,IX) = .5 + 0.1*CANG
               MCV(2,IX) = .5 + 0.1*SANG
               MCV(3,IX) = -CANG
               MCV(4,IX) = -SANG
320         CONTINUE
 
            CALL PSMCV (PMCINT, MAXPL, MCV)
 
C if (thismc = 5), exceed maximum with 3D replace:
         ELSEIF (THISMC .EQ. 5) THEN
 
            DO 330 IX = 1,MAXPL+1
               ANG = IX*2*PI / (MAXPL+1)
               SANG = SIN(ANG)
               CANG = COS(ANG)
               MCV3(1,IX) = .5 + 0.1*CANG
               MCV3(2,IX) = .5 + 0.1*SANG
               MCV3(3,IX) = 0.0
               MCV3(4,IX) = -CANG
               MCV3(5,IX) = -SANG
               MCV3(6,IX) = 0.1
330         CONTINUE
 
            CALL PSMCV3 (PMCREP, MAXPL+1, MCV3)
 
C if (thismc = 6), exceed maximum with 3D intersect:
         ELSEIF (THISMC .EQ. 6) THEN
            DO 340 IX = 1,MAXPL
               ANG = IX*2*PI / MAXPL
               SANG = SIN(ANG)
               CANG = COS(ANG)
               MCV3(1,IX) = .5 + 0.1*CANG
               MCV3(2,IX) = .5 + 0.1*SANG
               MCV3(3,IX) = .7
               MCV3(4,IX) = -CANG
               MCV3(5,IX) = -SANG
               MCV3(6,IX) = 0.0
340         CONTINUE
 
            CALL PSMCV3 (PMCINT, MAXPL, MCV3)
 
         ENDIF
 
C  draw polyline using xa, ya
         CALL PPL (8, XA, YA)
130   CONTINUE
 
C pass/fail depending on (operator response = ngwin)
      CALL DCHPFV ('MAXIMUM CLIPPING PLANES EXCEEDED: In which ' //
     1             'square is the polyline clipped differently?',
     2              6, NGWIN)
 
      CALL PEMST (102)
 
C *** *** *** ***   degenerate half-space   *** *** *** ***
 
400   CONTINUE
 
      CALL SETMSG ('23 26 38 40 43 48', 'If a <set modelling '    //
     1             'clipping volume> element specifies a '        //
     2             'degenerate half-space (zero-length vector), ' //
     3             'then it should be ignored upon traversal.')
 
C  set clip indicator on
      CALL PSMCLI (PCLIP)
C  winlis = randomized list of 1-6
      CALL RNPERM (6, WINLIS)
 
      DO 140 WINID = 1, 6
         THISMC = WINLIS(WINID)
         CALL EBLTM3 (Z,Z,Z, XWINLO(WINID),YWINLO(WINID),H,
     2                Z,Z,Z, XSIZ,XSIZ,XSIZ, XF)
         CALL PSLMT3 (XF, PCREPL)
 
C   <set modelling clipping volume> using:
C      operator = replace, point = 0.5,0.5, vector = -1,0
         OP = PMCREP
         CALL SETRVS ('0.5,0.5,-1,0', MCV(1,1), NSZ)
         CALL PSMCV (OP, 1, MCV)
 
C if (thismc = 1), <set modelling clipping volume> using:
C      operator = replace, point = 0.6,0.5, vector = -1,-1
         IF (THISMC .EQ. 1) THEN
            OP = PMCREP
            CALL SETRVS ('0.6,0.5,-1,-1', MCV(1,1), NSZ)
            NGWIN = WINID
            CALL PSMCV (OP, 1, MCV)
 
C if (thismc = 2), normal clip: do nothing
         ELSEIF (THISMC .EQ. 2) THEN
 
C if (thismc = 3),
C      zero vector, 2D, operator=replace:
C      <set modelling clipping volume> using:
C         operator = replace
C         point  = 0.4,0.6; vector =  1, 1
C         point  = 0.4,0.6; vector =  0, 0
C         point  = 0.4,0.6; vector = -1,-1
         ELSEIF (THISMC .EQ. 3) THEN
            CALL SETRVS ('0.4,0.6, 1, 1', MCV(1,1), NSZ)
            CALL SETRVS ('0.4,0.6, 0, 0', MCV(1,2), NSZ)
            CALL SETRVS ('0.4,0.6,-1,-1', MCV(1,3), NSZ)
            CALL PSMCV (PMCREP, 3, MCV)
 
C if (thismc = 4),
C      zero vector, 3D, operator=intersect:
C      <set modelling clipping volume 3>, using:
C         operator = intersect
C         point  = 1,1,1; vector =  0,0,0
C         point  = 1,1,1; vector =  1,0,0
C         point  = 1,1,1; vector = -1,0,0
         ELSEIF (THISMC .EQ. 4) THEN
            CALL SETRVS ('1,1,1, 0,0,0', MCV3(1,1), NSZ)
            CALL SETRVS ('1,1,1, 1,0,0', MCV3(1,2), NSZ)
            CALL SETRVS ('1,1,1,-1,0,0', MCV3(1,3), NSZ)
            CALL PSMCV3 (PMCINT, 3, MCV3)
 
C if (thismc = 5)
C      zero vector, 2D, operator=intersect:
C      <set modelling clipping volume> using:
C         operator = intersect
C         point  = 0.4,0.6; vector =  1, 1
C         point  = 0.4,0.6; vector = -1,-1
C         point  = 0.4,0.6; vector =  0, 0
         ELSEIF (THISMC .EQ. 5) THEN
            CALL SETRVS ('0.4,0.6, 1, 1', MCV(1,1), NSZ)
            CALL SETRVS ('0.4,0.6,-1,-1', MCV(1,2), NSZ)
            CALL SETRVS ('0.4,0.6, 0, 0', MCV(1,3), NSZ)
            CALL PSMCV (PMCINT, 3, MCV)
 
C if (thismc = 6)
C      zero vector, 3D, operator=replace:
C      <set modelling clipping volume 3>, using:
C         operator = replace
C         point  = 1,1,1; vector =  1,0,0
C         point  = 1,1,1; vector =  0,0,0
C         point  = 1,1,1; vector = -1,0,0
         ELSEIF (THISMC .EQ. 6) THEN
            CALL SETRVS ('1,1,1, 1,0,0', MCV3(1,1), NSZ)
            CALL SETRVS ('1,1,1, 0,0,0', MCV3(1,2), NSZ)
            CALL SETRVS ('1,1,1,-1,0,0', MCV3(1,3), NSZ)
            CALL PSMCV3 (PMCREP, 3, MCV3)
 
         ENDIF
 
C  draw polyline using xa, ya
         CALL PPL (8, XA, YA)
140   CONTINUE
 
      CALL DCHPFV ('DEGENERATE HALF-SPACE: In which square is ' //
     1             'the polyline clipped differently?', 6, NGWIN)
 
      CALL PEMST (102)
 
666   CONTINUE
C  wrap it up
      CALL ENDIT
      END
