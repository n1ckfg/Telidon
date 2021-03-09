C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.03/01                           *
C  *    TEST TITLE : Basic spatial search for 2-D          *
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
 
      INTEGER    ARRSZ, NSZ, NPTS, IDUM1
      PARAMETER (ARRSZ = 100)
 
      REAL       XA(ARRSZ), YA(ARRSZ)
      INTEGER    ENDPTS(20), COLIA (3,2)
      LOGICAL    SPHDIS
 
      CALL INITGL ('02.03.03/01')
 
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
C
C  *** *** *** ***   polymarker   *** *** *** ***
C
C  Build structure 101:
C    1.  polymarker: (11,1), (12,2), (13,2), (22.3, 2.3)
C    2.  polymarker: (21,1), (22,2), (23,2)
 
      CALL PEMST (101)
 
      CALL SETRVS ('11, 12, 13,  22.3', XA, NSZ)
      CALL SETRVS (' 1,  2,  2,   2.3', YA, NSZ)
      CALL PPM (NSZ, XA,YA)
 
      CALL SETRVS ('21, 22, 23', XA, NSZ)
      CALL SETRVS (' 1,  2,  2', YA, NSZ)
      CALL PPM (NSZ, XA,YA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 11', 'The points of a '          //
     1             'qualifying two-dimensional polymarker should be ' //
     2             'found by a two-dimensional spatial search.')
      CALL ISSPF (2, 22.1,2.1,666.6, 0.2, '101,2')
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 11', 'The points of a '          //
     1             'qualifying two-dimensional polymarker should be ' //
     2             'found by a two-dimensional spatial search, '      //
     3             'even when the search distance is zero.')
      CALL ISSPF (2, 22.0,2.0,666.6, 0.0, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 11', 'The points of a qualifying ' //
     1             'two-dimensional polymarker should be found by a ' //
     2             'three-dimensional spatial search.')
      CALL ISSPF (3, 22.1,2.1,-0.1, 0.2, '101,2')
 
 
C  *** *** *** ***   polyline   *** *** *** ***
C
C  Build structure 101:
C    1.  polyline: (11,1), (12,2), (13,2), (21.5, 1.7)
C    2.  polyline: (21,1), (22,2), (23,2)
 
      CALL PEMST (101)
 
      CALL SETRVS ('11, 12, 13, 21.5', XA, NSZ)
      CALL SETRVS (' 1,  2,  2,  1.7', YA, NSZ)
      CALL PPL (NSZ, XA,YA)
 
      CALL SETRVS ('21, 22, 23',   XA, NSZ)
      CALL SETRVS (' 1,  2,  2 ',  YA, NSZ)
      CALL PPL (NSZ, XA,YA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 12', 'The line segments of a ' //
     1             'qualifying two-dimensional polyline should be ' //
     2             'found by a two-dimensional spatial search.')
      CALL ISSPF (2, 21.5,1.5,666.6, 0.1, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 12', 'The line segments of a '   //
     1             'qualifying two-dimensional polyline should be ' //
     2             'found by a three-dimensional spatial search.')
      CALL ISSPF (3, 21.5,1.5,0.1, 0.11, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 12', 'The line segments of a '   //
     1             'qualifying two-dimensional polyline should be ' //
     2             'found by a three-dimensional spatial search, '  //
     3             'even when the search distance is negative.')
      CALL ISSPF (3, 23.0,2.0,0.0, -33.3, '101,2')
 
 
C  *** *** *** ***   fill area   *** *** *** ***
C
C  Build structure 101:
C    1.  fill area: (20.5, 1), (21.5, 2), (21.5, 1)
C    2.  fill area: (21,   1), (22,   2), (22,   1)
C
      CALL PEMST (101)
 
      CALL SETRVS ('20.5, 21.5, 21.5', XA, NSZ)
      CALL SETRVS (' 1,    2,    1',   YA, NSZ)
      CALL PFA (NSZ, XA,YA)
 
      CALL SETRVS ('21, 22, 22',   XA, NSZ)
      CALL SETRVS (' 1,  2,  1 ',  YA, NSZ)
      CALL PFA (NSZ, XA,YA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 13', 'The interior of a '       //
     1             'qualifying two-dimensional fill area should be ' //
     2             'found by a two-dimensional spatial search.')
      CALL ISSPF (2, 21.7,1.3,666.6, 0.1, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 13', 'The interior of a '         //
     1             'qualifying two-dimensional fill area should be ' //
     2             'found by a three-dimensional spatial search.')
      CALL ISSPF (3, 21.7,1.3,0.1, 0.11, '101,2')
 
 
C  *** *** *** ***   fill area set   *** *** *** ***
C
C  Build structure 101:
C    1.  fill area set: (1,0), (0,1), (1,2)  / (3,2), (4,1), (3,0)
C    2.  fill area set: (11,2), (13,2), (13,0), (11,0)  /
C                       ( 1,2), ( 3,2), ( 3,0), ( 1,0)
 
      CALL PEMST (101)
 
      CALL SETRVS ('1, 0, 1, 3, 4, 3', XA, IDUM1)
      CALL SETRVS ('0, 1, 2, 2, 1, 0', YA, IDUM1)
      CALL SETVS ('3, 6', ENDPTS, NPTS)
      CALL PFAS (NPTS, ENDPTS, XA, YA)
 
      CALL SETRVS ('11, 13, 13, 11, 1, 3, 3, 1', XA, IDUM1)
      CALL SETRVS (' 2,  2,  0,  0, 2, 2, 0, 0', YA, IDUM1)
      CALL SETVS ('4, 8', ENDPTS, NPTS)
      CALL PFAS (NPTS, ENDPTS, XA, YA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 14', 'The interiors of a '       //
     1             'qualifying two-dimensional fill area set should ' //
     2             'be found by a two-dimensional spatial search.')
      CALL ISSPF (2, 2.0,1.0,666.6, 0.1, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 14', 'The interiors of a '         //
     1             'qualifying two-dimensional fill area set should ' //
     2             'be found by a three-dimensional spatial search.')
      CALL ISSPF (3, 2.0,1.0,0.1, 0.11, '101,2')
 
C  Build structure 101:
C    1.  fill area set: (1,4), (4,1), (4,4) / (3,6), (6,3), (3,3)
C    2.  fill area set: (3.4,3.4), (3.4,3.6), (3.6,3.6), (3.6,3.4)
 
      CALL PEMST (101)
 
      CALL SETRVS ('1, 4, 4, 3, 6, 3', XA, IDUM1)
      CALL SETRVS ('4, 1, 4, 6, 3, 3', YA, IDUM1)
      CALL SETVS ('3, 6', ENDPTS, NPTS)
      CALL PFAS (NPTS, ENDPTS, XA, YA)
 
      CALL SETRVS ('3.4, 3.4, 3.6, 3.6', XA, IDUM1)
      CALL SETRVS ('3.4, 3.6, 3.6, 3.4', YA, IDUM1)
      CALL SETVS ('4', ENDPTS, NPTS)
      CALL PFAS (NPTS, ENDPTS, XA, YA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 14', 'The interior of a '        //
     1             'qualifying two-dimensional fill area set should ' //
     2             'be found by a two-dimensional spatial search, '   //
     3             'but sub-areas overlapping an even number of '     //
     4             'times should not be found.')
      CALL ISSPF (2, 3.5,3.5,666.6, 0.1, '101,2')
C  *** *** *** ***   text   *** *** *** ***
C
C  Build structure 101:
C    1.  set character height = 1.0
C    2.  set text alignment   = (LEFT, BOTTOM)
C    3.  text: "Viva PHIGS!" at 5,0
C    4.  text: "Viva PHIGS!" at 5,5
 
      CALL PEMST (101)
 
      CALL PSCHH (1.0)
      CALL PSTXAL (PALEFT, PABOTT)
      CALL PTX (5.0, 0.0, 'Viva PHIGS!')
      CALL PTX (5.0, 5.0, 'Viva PHIGS!')
      CALL SETMSG ('1 2 4 5 6 7 9 10 15', 'The text extent '         //
     1             'rectangle of a qualifying two-dimensional text ' //
     2             'primitive should be found by a two-dimensional ' //
     3             'spatial search.')
      CALL ISSPF (2, 4.9,5.5,666.6, 0.3, '101,4')
 
      CALL SETMSG ('2 4 5 6 7 9 10 15', 'The text extent rectangle ' //
     1             'of a qualifying two-dimensional text primitive ' //
     2             'should be found by a three-dimensional spatial ' //
     3             'search.')
      CALL ISSPF (3, 4.9,5.5,-0.1, 0.3, '101,4')
 
 
C  *** *** *** ***   annotation text   *** *** *** ***
C
C  Build structure 101:
C    1.  set annotation text character height = 1.0
C    2.  set annotation text alignment        = (LEFT, BOTTOM)
C    3.  annotation text relative: "Viva PHIGS!" at 5,0 with offset = 0,0
C    4.  annotation text relative: "Viva PHIGS!" at 5,5 with offset = 0,0
 
      CALL PEMST (101)
 
      CALL PSATCH (1.0)
      CALL PSATAL (PALEFT, PABOTT)
      CALL PATR (5.0, 0.0, 0.0, 0.0, 'Viva PHIGS!')
      CALL PATR (5.0, 5.0, 0.0, 0.0, 'Viva PHIGS!')
      CALL SETMSG ('1 2 4 5 6 7 9 10 16', 'The annotation reference ' //
     1             'point of a qualifying two-dimensional '           //
     2             'annotation text should be found by a '            //
     3             'two-dimensional spatial search.')
      CALL ISSPF (2, 5.0,3.0,666.6, 2.5, '101,4')
 
      CALL SETMSG ('2 4 5 6 7 9 10 16', 'The annotation reference ' //
     1             'point of a qualifying two-dimensional '         //
     2             'annotation text should be found by a '          //
     3             'three-dimensional spatial search.')
      CALL ISSPF (3, 5.0,3.0,1.0, 2.5, '101,4')
 
 
C  *** *** *** ***   cell array   *** *** *** ***
C
C  colia = color index array =  1 0 1
C                               0 1 1
      DATA COLIA / 1,0,1,0,1,1 /
 
C  Build structure 101:
C    1.  cell array: colia between corners (0,0) and (2,2)
C    2.  cell array: colia between corners (1,1) and (3,3)
 
      CALL PEMST (101)
      CALL PCA (0.0,0.0, 2.0,2.0, 3,2, 1,1, 3,2, COLIA)
      CALL PCA (1.0,1.0, 3.0,3.0, 3,2, 1,1, 3,2, COLIA)
 
      CALL SETMSG ('1 2 4 5 6 7 9 10 17', 'The parallelogram of a '   //
     1             'qualifying two-dimensional cell array should be ' //
     2             'found by a two-dimensional spatial search.')
      CALL ISSPF (2, 2.0,2.5,666.6, 0.1, '101,2')
 
      CALL SETMSG ('2 4 5 6 7 9 10 17', 'The parallelogram of a '     //
     1             'qualifying two-dimensional cell array should be ' //
     2             'found by a three-dimensional spatial search.')
      CALL ISSPF (3, 2.0,2.5,0.1, 0.11, '101,2')
 
666   CONTINUE
      CALL ENDIT
 
      END
