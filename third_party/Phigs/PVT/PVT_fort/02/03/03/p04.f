C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.03/04                           *
C  *    TEST TITLE : Starting path and search ceiling      *
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
 
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
 
      INTEGER    NSZ
 
      REAL       XA(5),YA(5),ZA(5), SRX,SRY,SRZ, SDIST
 
      CALL INITGL ('02.03.03/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  Set up CSS:
C
C                101
C               /   \
C             1/     \2
C             /       \
C          102         105:1,3
C           |           |
C          1|           |2
C           |           |
C            \         106
C             \       /   \
C              \    3/     \5
C               \   /       \
C                103         107:3,4
C               /   \
C             1/     \2
C             /       \
C          108         104:2
C
C
C  Numbers 101-108 are structure identifiers.  Numbers on edges are
C  element positions of 'execute structure' elements.  Numbers
C  following colons are element positions of primitives to be found
C  by spatial search.  E.g. starting from 101, the first found path
C  should be: (101,1), (102,1), (103,2), (104,2).
C
C  All ISS done with same search reference point, search distance
C  (set so as to find all the primitives listed above), no modelling
C  clipping, and null filter lists.
 
      CALL SETRVS ('27.63, -6.263,  6.23',  XA,NSZ)
      CALL SETRVS ('12.01, 92.0191,-2.12',  YA,NSZ)
      CALL SETRVS ('-8.298,39.283, 28.293', ZA,NSZ)
      SRX = XA(2)
      SRY = YA(2)
      SRZ = ZA(2)
      SDIST = 1.0
 
      CALL POPST (101)
      CALL PEXST (102)
      CALL PEXST (105)
      CALL PCLST
 
      CALL POPST (102)
      CALL PEXST (103)
      CALL PCLST
 
      CALL POPST (103)
      CALL PEXST (108)
      CALL PEXST (104)
      CALL PCLST
 
      CALL POPST (104)
      CALL PLB   (41)
      CALL PPM3  (NSZ, XA,YA,ZA)
      CALL PCLST
 
      CALL POPST (105)
      CALL PPM3  (NSZ, XA,YA,ZA)
      CALL PEXST (106)
      CALL PPM3  (NSZ, XA,YA,ZA)
      CALL PCLST
 
      CALL POPST (106)
      CALL PLB   (61)
      CALL PLB   (62)
      CALL PEXST (103)
      CALL PLB   (64)
      CALL PEXST (107)
      CALL PCLST
 
      CALL POPST (107)
      CALL PLB   (71)
      CALL PLB   (72)
      CALL PPM3  (NSZ, XA,YA,ZA)
      CALL PPM3  (NSZ, XA,YA,ZA)
      CALL PCLST
 
      CALL SETMSG ('2 4 5 6 9', 'ISS should ignore a primitive at ' //
     1             'the starting path location, and commence the '  //
     2             'search at the element immediately following.')
 
C  <incremental spatial search> with
C     starting path  = (101,2), (105,2), (106,5), (107,3)
C     search ceiling = 1
C     expected path  = (101,2), (105,2), (106,5), (107,4)
      CALL ISPTHS (SRX,SRY,SRZ, SDIST, 1, PNCLIP,
     1             '101,2, 105,2, 106,5, 107,3',
     2             '101,2, 105,2, 106,5, 107,4/' )
 
      CALL SETMSG ('2 4 5 6 9', 'ISS should ignore an '              //
     1             'execute-structure element at the starting path ' //
     2             'location, and commence the search at the '       //
     3             'element immediately following.')
 
C  <incremental spatial search> with
C     starting path  = (101,1)
C     search ceiling = 1
C     expected path  = (101,2), (105,1)
 
      CALL ISPTHS (SRX,SRY,SRZ,SDIST,1,PNCLIP, '101,1', '101,2, 105,1/')
 
      CALL SETMSG ('2 4 5 6 7 8 9', 'Repeated incremental spatial ' //
     1             'search, starting with element zero of the '     //
     2             'root structure, using the found path as the '   //
     3             'next starting path, and a search ceiling of '   //
     4             '1, should find all qualifying primitives '      //
     5             'within a network.')
 
      CALL ISPTHS (SRX,SRY,SRZ, SDIST, 1, PNCLIP, '101,0',
     1             '101,1, 102,1, 103,2, 104,2 /'         //
     2             '101,2, 105,1 /'                       //
     3             '101,2, 105,2, 106,3, 103,2, 104,2 /'  //
     4             '101,2, 105,2, 106,5, 107,3 /'         //
     5             '101,2, 105,2, 106,5, 107,4 /'         //
     6             '101,2, 105,3 /'                       //
     7             ' /')
 
      CALL SETMSG ('2 4 5 6 9', 'ISS should be able to search a ' //
     1             'sub-network within a larger CSS network.')
 
      CALL ISPTHS (SRX,SRY,SRZ, SDIST, 1, PNCLIP, '106,1',
     1             '106,3, 103,2, 104,2 /'  //
     2             '106,5, 107,3 /'         //
     3             '106,5, 107,4 /'         //
     4             ' /')
 
      CALL SETMSG ('2 4 5 6 8 9', 'A search ceiling greater than 1 ' //
     1             'should limit the search to the network of the '  //
     2             'indicated structure.')
 
 
      CALL ISPTHS (SRX,SRY,SRZ, SDIST, 4, PNCLIP,
     1             '101,2, 105,2, 106,3, 103,1, 108,0',
     2             '101,2, 105,2, 106,3, 103,2, 104,2 / /')
 
      CALL SETMSG ('2 4 5 6 8 9', 'Any search ceiling up to the end ' //
     1             'of the starting path should be valid.')
 
      CALL ISPTHS (SRX,SRY,SRZ, SDIST, 4, PNCLIP,
     1             '101,1, 102,1, 103,2, 104,1',
     2             '101,1, 102,1, 103,2, 104,2 / /')
 
666   CONTINUE
      CALL ENDIT
      END
