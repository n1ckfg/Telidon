C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.03/02                           *
C  *    TEST TITLE : Basic spatial search for 3-D          *
C  *                 primitives                            *
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
     3        DUMINT(20)
      REAL    DUMRL(20)
 
      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20
 
C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
 
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)
 
C  Declare program-specific variables
      INTEGER    ARRSZ
      PARAMETER (ARRSZ = 100)
 
      INTEGER    NSZ, IX, ENDPTS(5), NPTS, COLIA(3,2)
 
      REAL       XA(ARRSZ), YA(ARRSZ), ZA(ARRSZ), ZVAL, XN,YN,ZN
      REAL       TDVI(2),TDVJ(2),TDVK(2), A,B,C,D, DIST2D
      REAL       TLCXI,TLCXJ,TLCXK, TLCYI,TLCYJ,TLCYK, TLCZI,TLCZJ,TLCZK
      REAL       TP1X,TP1Y,TP1Z, TP2X,TP2Y,TP2Z, TLCZI1,TLCZJ1,TLCZK1
      REAL       SRP2DX,SRP2DY, SRP3DX,SRP3DY,SRP3DZ
 
      LOGICAL    SPHDIS
 
C  Use plane: 3x + 4y - z - 7 = 0, so
C    z = f(x,y) = 3x + 4y - 7
 
      CALL INITGL ('02.03.03/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF
 
C  All ISS's from start of root (101,0), no modelling clipping,
C  null filter lists, search ceiling = 1.
      CALL POPST (101)
 
C  *** *** *** ***   polymarker 3   *** *** *** ***
C
C  Build structure 101:
C    1.  polymarker 3: (11,1,1), (12,2,2), (22,2,0.2), (13,2,3)
C    2.  polymarker 3: (21,1,6), (12.3,2.3,2.3), (22,2,-0.1), (23,2,5)
 
      CALL PEMST (101)
 
      CALL SETRVS ('11, 12, 22,  13', XA, NSZ)
      CALL SETRVS (' 1,  2,  2,   2', YA, NSZ)
      CALL SETRVS (' 1,  2,  0.2, 3', ZA, NSZ)
      CALL PPM3 (NSZ, XA,YA,ZA)
 
      CALL SETRVS ('21, 12.3, 22,   23', XA, NSZ)
      CALL SETRVS (' 1,  2.3,  2,    2', YA, NSZ)
      CALL SETRVS (' 6,  2.3, -0.1,  5', ZA, NSZ)
      CALL PPM3 (NSZ, XA,YA,ZA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 11', 'The points of a '         //
     1             'qualifying three-dimensional polymarker should ' //
     2             'be found by a two-dimensional spatial search.')
      CALL ISSPF (2, 22.1,2.1,666.6, 0.24, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 11', 'The points of a qualifying ' //
     1             'three-dimensional polymarker should be found by ' //
     2             'a three-dimensional spatial search.')
      CALL ISSPF (3, 12.2,2.2,2.2, 0.25, '101,2')
 
 
C  *** *** *** ***   polyline 3   *** *** *** ***
C
C  Build structure 101:
C    1.  polyline 3: (2.0,2.2,0.2), (3,3,3)
C    2.  polyline 3: (1,1,-0.1), (3,3,-0.3), (3,3,3.1)
 
      CALL PEMST (101)
 
      CALL SETRVS ('2.0, 3', XA, NSZ)
      CALL SETRVS ('2.2, 3', YA, NSZ)
      CALL SETRVS ('0.2, 3', ZA, NSZ)
      CALL PPL3 (NSZ, XA,YA,ZA)
 
      CALL SETRVS (' 1,    3,   3',   XA, NSZ)
      CALL SETRVS (' 1,    3,   3 ',  YA, NSZ)
      CALL SETRVS ('-0.1, -0.3, 3.1', ZA, NSZ)
      CALL PPL3 (NSZ, XA,YA,ZA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 12', 'The line segments of a '   //
     1             'qualifying three-dimensional polyline should be ' //
     2             'found by a two-dimensional spatial search.')
      CALL ISSPF (2, 2.0,2.0,666.6, 0.21, '101,2')
C
      CALL SETMSG ('2 4 5 6 7 9 10 12', 'The line segments of a '     //
     1             'qualifying three-dimensional polyline should be ' //
     2             'found by a three-dimensional spatial search.')
      CALL ISSPF (3, 3.0,3.0,3.2, 0.11, '101,2')
 
C  *** *** *** ***   fill area 3   *** *** *** ***
C
C  Use plane: 3x + 4y - z - 7 = 0, so
C    z = f(x,y) = 3x + 4y - 7
C
C  Build structure 101:
C    1.  fill area 3: (1.1,0,z), (1.1,2,z), (2,2,z), (2,0,z)
C    2.  fill area 3: (0,  0,z), (0,  2,z), (2,2,z), (2,0,z)
 
      CALL PEMST (101)
 
      CALL SETRVS ('1.1, 1.1, 2, 2', XA, NSZ)
      CALL SETRVS ('0,   2,   2, 0', YA, NSZ)
      DO 110 IX = 1,NSZ
         ZA(IX) = ZVAL(XA(IX), YA(IX))
110   CONTINUE
      CALL PFA3 (NSZ, XA,YA,ZA)
 
      CALL SETRVS ('0, 0, 2, 2', XA, NSZ)
      CALL SETRVS ('0, 2, 2, 0', YA, NSZ)
      DO 120 IX = 1,NSZ
         ZA(IX) = ZVAL(XA(IX), YA(IX))
120   CONTINUE
      CALL PFA3 (NSZ, XA,YA,ZA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 13', 'The interior of a '      //
     1             'qualifying three-dimensional fill area should ' //
     2             'be found by a two-dimensional spatial search.')
      CALL ISSPF (2, 1.0,1.0, 666.6, 0.1, '101,2')
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 13', 'The interior of a '      //
     1             'qualifying three-dimensional fill area should ' //
     2             'be found by a two-dimensional spatial search, ' //
     3             'even when the search distance is negative.')
      CALL ISSPF (2, 1.0,1.0, 666.6, -22.22, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 13', 'The interior of a '        //
     1             'qualifying three-dimensional fill area should ' //
     2             'be found by a three-dimensional spatial search.')
      CALL ISSPF (3, 1.0,2.0,4.0, 0.1, '101,2')
 
C  *** *** *** ***   fill area set 3   *** *** *** ***
C
C  Use plane: 3x + 4y - z - 7 = 0, so
C    z = f(x,y) = 3x + 4y - 7
C
C  Build structure 101:
C    1.  fill area set 3: (1,0,z), (0,1,z), (1,2,z) /
C                         (3,2,z), (4,1,z), (3,0,z)
C    2.  fill area set 3: (11,2,z), (13,2,z), (13,0,z), (11,0,z)  /
C                         ( 1,2,z), ( 3,2,z), ( 3,0,z), ( 1,0,z)
 
      CALL PEMST (101)
 
      CALL SETRVS ('1, 0, 1, 3, 4, 3', XA, NSZ)
      CALL SETRVS ('0, 1, 2, 2, 1, 0', YA, NSZ)
      DO 130 IX = 1,NSZ
         ZA(IX) = ZVAL(XA(IX), YA(IX))
130   CONTINUE
      CALL SETVS ('3,6', ENDPTS, NPTS)
      CALL PFAS3 (NPTS, ENDPTS, XA,YA,ZA)
 
      CALL SETRVS ('11, 13, 13, 11, 1, 3, 3, 1', XA, NSZ)
      CALL SETRVS (' 2,  2,  0,  0, 2, 2, 0, 0', YA, NSZ)
      DO 140 IX = 1,NSZ
         ZA(IX) = ZVAL(XA(IX), YA(IX))
140   CONTINUE
      CALL SETVS ('4,8', ENDPTS, NPTS)
      CALL PFAS3 (NPTS, ENDPTS, XA,YA,ZA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 14', 'The interiors of a '    //
     1             'qualifying three-dimensional fill area set '   //
     2             'should be found by a two-dimensional spatial ' //
     3             'search.')
      CALL ISSPF (2, 2.0,0.25,666.6, 0.1, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 14', 'The interiors of a '        //
     1             'qualifying three-dimensional fill area set '     //
     2             'should be found by a three-dimensional spatial ' //
     3             'search.')
      CALL ISSPF (3, 2.0,1.0,ZVAL(2.0,1.0), 0.1, '101,2')
 
C  *** *** *** ***   text 3   *** *** *** ***
C
C  tdv1 =  first text direction vector = 1, 0.1, 0.2
      TDVI(1) = 1.0
      TDVJ(1) = 0.1
      TDVK(1) = 0.2
C  tdv2 = second text direction vector = 0.1, 1, 0.2
      TDVI(2) = 0.1
      TDVJ(2) = 1.0
      TDVK(2) = 0.2
C  tlcx = text local cooordinate-x = tdv1
      TLCXI = TDVI(1)
      TLCXJ = TDVJ(1)
      TLCXK = TDVK(1)
C  tlcy = text local cooordinate-y = vector in tdv-plane,
C  perpendicular to tlcx, and such that tlcy . tdv2 > 0
      CALL PERVEC (TLCXI,TLCXJ,TLCXK, TDVI(2),TDVJ(2),TDVK(2),
     1             TLCYI,TLCYJ,TLCYK)
C  tlcz = perpendicular to text plane = tlcx X tlcy
      CALL CROSSP (TLCXI,TLCXJ,TLCXK, TLCYI,TLCYJ,TLCYK,
     1             TLCZI,TLCZJ,TLCZK)
C  tlcz1 = tlcz, normalized to unit length
      CALL VEC1 (TLCZI, TLCZJ, TLCZK, TLCZI1, TLCZJ1, TLCZK1)
C  tp2  = text position 2 = 3,4,0.1
      TP2X = 3.0
      TP2Y = 4.0
      TP2Z = 0.1
C  tp1  = text position 1 = tp2 + tlcz1 (1.0 away from tp2)
      TP1X  = TP2X + TLCZI1
      TP1Y  = TP2Y + TLCZJ1
      TP1Z  = TP2Z + TLCZK1
C  a,b,c,d = coefficients of text plane containing tp2: ax+by+cz+d=0
      A = TLCZI
      B = TLCZJ
      C = TLCZK
      D = - (A*TP2X +  B*TP2Y +  C*TP2Z)
C  srp2d   = 2D search reference point = (tp2x - 0.3, tp2y - 0.3)
      SRP2DX = TP2X - 0.3
      SRP2DY = TP2Y - 0.3
C  dist2d  = distance of srp2d from tp2 plane; since this plane is
C  close to z=0 plane, the 2D search reference point will be closer
C  to it than to the text plane of tp1, which is about z=1.
      CALL PTPLDS (SRP2DX,SRP2DY,0.0, A,B,C,D, XN,YN,ZN, DIST2D)
 
C  Build structure 101:
C    1.  set character height = 1.0
C    2.  set text alignment   = (CENTRE, HALF)
C    3.  text 3: "Viva PHIGS!" at tp1 with tdv1,tdv2
C    4.  text 3: "Viva PHIGS!" at tp2 with tdv1,tdv2
 
      CALL PEMST (101)
      CALL PSCHH (1.0)
      CALL PSTXAL (PACENT, PAHALF)
      CALL PTX3 (TP1X,TP1Y,TP1Z, TDVI,TDVJ,TDVK, 'Viva PHIGS!')
      CALL PTX3 (TP2X,TP2Y,TP2Z, TDVI,TDVJ,TDVK, 'Viva PHIGS!')
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 15', 'The text extent '      //
     1             'rectangle of a qualifying three-dimensional ' //
     2             'text primitive should be found by a '         //
     3             'two-dimensional spatial search.')
      CALL ISSPF (2, SRP2DX, SRP2DY, 666.6, DIST2D * 1.1, '101,4')
 
      CALL SETMSG ('2 4 5 6 7 9 10 15', 'The text extent rectangle ' //
     1             'of a qualifying three-dimensional text '         //
     2             'primitive should be found by a '                 //
     3             'three-dimensional spatial search.')
 
C  srp3d   = 3D search reference point = (tp2x + 0.3, tp2y + 0.3, z)
C            where z puts srp3d in a,b,c,d plane
      SRP3DX = TP2X + 0.3
      SRP3DY = TP2Y + 0.3
      SRP3DZ = -(A*SRP3DX + B*SRP3DY + D) / C
C  dist3d  = 0.95 (because text planes are 1.0 apart - see tp1 above)
      CALL ISSPF (3, SRP3DX,SRP3DY,SRP3DZ, 0.95, '101,4')
 
 
C  *** *** *** ***   annotation text 3   *** *** *** ***
C
C  Build structure 101:
C    1.  set annotation text character height = 1.0
C    2.  set annotation text alignment        = (RIGHT, TOP)
C    3.  annotation text relative 3: "Viva PHIGS!" at 5,0,0
C           with offset = 3,-2,1
C    4.  annotation text relative 3: "Viva PHIGS!" at 5,5,1
C           with offset = -1,2,-3
 
      CALL PEMST (101)
      CALL PSATCH (1.0)
      CALL PSATAL (PARITE, PATOP)
      CALL PATR3 (5.0,0.0,0.0,  0.0,5.0, 1.0, 'Viva PHIGS!')
      CALL PATR3 (5.0,5.0,1.0, -1.0,2.0,-3.0, 'Viva PHIGS!')
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 16', 'The annotation reference ' //
     1             'point of a qualifying three-dimensional '         //
     2             'annotation text should be found by a '            //
     3             'two-dimensional spatial search.')
      CALL ISSPF (2, 5.0,3.0, 666.6, 2.5, '101,4')
 
      CALL SETMSG ('2 4 5 6 7 9 10 16', 'The annotation reference ' //
     1             'point of a qualifying three-dimensional '       //
     2             'annotation text should be found by a '          //
     3             'three-dimensional spatial search.')
      CALL ISSPF (3, 5.0,3.0,1.0, 2.1, '101,4')
 
      CALL SETMSG ('2 4 5 6 7 9 10 16', 'The annotation reference ' //
     1             'point of a qualifying three-dimensional '       //
     2             'annotation text should be found by a '          //
     3             'three-dimensional spatial search, even when '   //
     4             'the search distance is zero.')
      CALL ISSPF (3, 5.0,5.0,1.0, 0.0, '101,4')
 
C  *** *** *** ***   cell array 3   *** *** *** ***
 
C  Use plane: 3x + 4y - z - 7 = 0, so
C    z = f(x,y) = 3x + 4y - 7
C
C  colia = color index array =  1 0 1
C                               0 1 1
      DATA  COLIA / 1,0,1,0,1,1 /
 
C  Build structure 101:
C    1.  cell array 3: colia with corners
C                      P=(1.1,1.1,z), Q=(0.6,2.0,z), R=(2.0,0.6,z)
C    2.  cell array 3: colia with corners
C                      P=(1.2,1.3,z), Q=(1.5,0.5,z), R=(0.5,1.5,z)
 
      CALL PEMST (101)
 
      CALL SETRVS ('1.1, 0.6, 2.0', XA, NSZ)
      CALL SETRVS ('1.1, 2.0, 0.6', YA, NSZ)
      DO 150 IX = 1,NSZ
         ZA(IX) = ZVAL(XA(IX), YA(IX))
150   CONTINUE
      CALL PCA3 (XA,YA,ZA, 3,2, 1,1, 3,2, COLIA)
 
      CALL SETRVS ('1.2, 1.5, 0.5', XA, NSZ)
      CALL SETRVS ('1.3, 0.5, 1.5', YA, NSZ)
      DO 160 IX = 1,NSZ
         ZA(IX) = ZVAL(XA(IX), YA(IX))
160   CONTINUE
      CALL PCA3 (XA,YA,ZA, 3,2, 1,1, 3,2, COLIA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 17', 'The parallelogram of a '  //
     1             'qualifying three-dimensional cell array should ' //
     2             'be found by a two-dimensional spatial search.')
      CALL ISSPF (2, 1.0,1.0, 666.6, 0.1, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 17', 'The parallelogram of a '    //
     1             'qualifying three-dimensional cell array should ' //
     2             'be found by a three-dimensional spatial search.')
      CALL ISSPF (3, 1.6,0.5,ZVAL(1.6,0.5), 0.11, '101,2')
 
666   CONTINUE
      CALL ENDIT
      END
 
