C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.03.03/05                           *
C  *    TEST TITLE : Inheritance of geometric attributes   *
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
 
C text alignment horizontal
      INTEGER    PAHNOR,     PALEFT,     PACENT,     PARITE
      PARAMETER (PAHNOR = 0, PALEFT = 1, PACENT = 2, PARITE = 3)
 
C text alignment vertical
      INTEGER    PAVNOR,     PATOP,      PACAP,     PAHALF,
     1           PABASE,     PABOTT
      PARAMETER (PAVNOR = 0, PATOP  = 1, PACAP = 2, PAHALF = 3,
     1           PABASE = 4, PABOTT = 5)
 
C text path
      INTEGER    PRIGHT,     PLEFT,     PUP,     PDOWN
      PARAMETER (PRIGHT = 0, PLEFT = 1, PUP = 2, PDOWN = 3)
 
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
 
C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON
 
      INTEGER    TXPATH, TXALH,TXALV
 
      REAL       TPOSX,TPOSY, CHUPX,CHUPY, CHHT
      REAL       EXXLO(0:10),EXYLO(0:10),EXXHI(0:10),EXYHI(0:10)
      LOGICAL    SPHDIS
 
      CHARACTER  STR*17
 
      CALL INITGL ('02.03.03/05')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      IF (.NOT. SPHDIS(123)) THEN
         CALL INMSG ('Skipping test because implementation '     //
     1               'apparently uses non-Euclidean metric for ' //
     2               'search distance.')
         GOTO 666
      ENDIF
 
C  The only geometric attributes which affect the size or position
C  of primitives are the text attributes:
C    chht   : character height
C    chup   : character up vector
C    txpath : text path
C    txal   : text alignment
C
C  All ISS done with search ceiling of 1, no modelling clipping, and
C  null filter lists.
C
C  Set up CSS:
C
C              101
C              / |
C            5/  |
C            /   |
C           /    |6
C        102     |
C           \    |
C           5\   |
C             \  |
C              \ |
C              103
C
C  Numbers 101-103 are structure identifiers.  Numbers on edges are
C  element positions of 'execute structure' elements.
 
C  tpos = text position = 3.1, 4.2
C  str  = character string = "PHIGS or bust ..."
      TPOSX = 3.1
      TPOSY = 4.2
      STR = 'PHIGS or bust ...'
 
C open workstation - get specific workstation type
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
C  Set up values as in PDT:
      CHUPX  = 0.0
      CHUPY  = 1.0
      CHHT   = 0.01
      TXPATH = PRIGHT
      TXALH  = PAHNOR
      TXALV  = PAVNOR
 
C  Calculate expected values for PDT in slot #0:
      CALL TX2DEX (SPECWT, CHUPX,CHUPY, CHHT, TXPATH, TXALH,TXALV,
     1             TPOSX,TPOSY,STR, 0, EXXLO,EXYLO,EXXHI,EXYHI)
 
C  Set up values for structure 101:
      CHUPX  = 1.0
      CHUPY  = 1.3
      CHHT   = 2.2
      TXPATH = PDOWN
      TXALH  = PARITE
      TXALV  = PATOP
 
C  Structure 101
      CALL POPST  (101)
      CALL PSCHUP (CHUPX,CHUPY)
      CALL PSCHH  (CHHT)
      CALL PSTXP  (TXPATH)
      CALL PSTXAL (TXALH,TXALV)
      CALL PEXST  (102)
      CALL PEXST  (103)
      CALL PSCHH  (CHHT/3)
      CALL PCLST
 
C  Calculate expected values for 101:
      CALL TX2DEX (SPECWT, CHUPX,CHUPY, CHHT, TXPATH, TXALH,TXALV,
     1             TPOSX,TPOSY,STR, 1, EXXLO,EXYLO,EXXHI,EXYHI)
 
C  Set up values for structure 102:
      CHUPX  = -1.0
      CHUPY  =  1.6
      CHHT   =  0.023
      TXPATH = PUP
      TXALH  = PALEFT
      TXALV  = PAHALF
 
C  Structure 102
      CALL POPST  (102)
      CALL PSCHUP (CHUPX,CHUPY)
      CALL PSCHH  (CHHT)
      CALL PSTXP  (TXPATH)
      CALL PSTXAL (TXALH,TXALV)
      CALL PEXST  (103)
      CALL PSCHH  (CHHT/3)
      CALL PCLST
 
C  Calculate expected values for 102:
      CALL TX2DEX (SPECWT, CHUPX,CHUPY, CHHT, TXPATH, TXALH,TXALV,
     1             TPOSX,TPOSY,STR, 2, EXXLO,EXYLO,EXXHI,EXYHI)
 
C  Structure 103
      CALL POPST  (103)
      CALL PSTXPR (PSTRP)
      CALL PTX    (TPOSX,TPOSY, STR)
      CALL PSCHH  (33.3)
      CALL PCLST
 
      CALL SETMSG ('1 2 3 4 5 6 7', 'Actual geometric attributes '   //
     1             'should be those set by the most recent '         //
     2             'ancestor, even if a more distant ancestor also ' //
     3             'set them.')
C  Test ISS for corners of text rectangle with:
C    starting path:         101,0
C    expected corner index: 2
C    expected found path:   101,5 102,5, 103,2
      CALL ISSGEO ('101,0', 2, EXXLO,EXYLO,EXXHI,EXYHI,
     1             '101,5, 102,5, 103,2')
 
      CALL SETMSG ('1 2 3 4 5 6 7', 'Actual geometric attributes '    //
     1             'should be re-stored after being changed by a '    //
     2             'descendant structure that precedes the starting ' //
     3             'path.')
C  Test ISS for corners of text rectangle with:
C    starting path:         101,6, 103,0
C    expected corner index: 1
C    expected found path:   101,6, 103,2
      CALL ISSGEO ('101,6, 103,0', 1, EXXLO,EXYLO,EXXHI,EXYHI,
     1             '101,6, 103,2')
 
      CALL SETMSG ('1 2 3 4 5 6 7', 'When not explicitly set by an '  //
     1             'ancestor or by itself, the geometric attributes ' //
     2             'for a structure should be as inherited from the ' //
     3             'PHIGS description table.')
C  Test ISS for corners of text rectangle with:
C    starting path:         103,0
C    expected corner index: 0
C    expected found path:   103,2
      CALL ISSGEO ('103,0', 0, EXXLO,EXYLO,EXXHI,EXYHI,
     1             '103,2')
 
 
C  Set up values for structure 103:
      CHUPX  = -1.0
      CHUPY  = -1.9
      CHHT   =  12.3
      TXPATH = PLEFT
      TXALH  = PACENT
      TXALV  = PABOTT
 
C  Insert in beginning of structure 103:
      CALL POPST  (103)
      CALL PSEP   (0)
      CALL PSCHUP (CHUPX,CHUPY)
      CALL PSCHH  (CHHT)
      CALL PSTXP  (TXPATH)
      CALL PSTXAL (TXALH,TXALV)
      CALL PCLST
 
C  old elements of 103:
C    5. set text precision to STRING
C    6. 2D text: str at tpos
C    7. set character height to 33.3
 
C  Calculate expected values for 103:
      CALL TX2DEX (SPECWT, CHUPX,CHUPY, CHHT, TXPATH, TXALH,TXALV,
     1             TPOSX,TPOSY,STR, 3, EXXLO,EXYLO,EXXHI,EXYHI)
 
      CALL SETMSG ('1 2 3 4 5 6 7', 'Actual geometric attributes ' //
     1             'should be as set in prior elements of the '    //
     2             'current structure, overriding the inherited '  //
     3             'attributes.')
C  Test ISS for corners of text rectangle with:
C    starting path:         101,0
C    expected corner index: 3
C    expected found path:   101,5, 102,5, 103,6
      CALL ISSGEO ('101,0', 3, EXXLO,EXYLO,EXXHI,EXYHI,
     1             '101,5, 102,5, 103,6')
 
      CALL SETMSG ('1 2 3 4 5 6 7', 'Actual geometric attributes '  //
     1             'should be as set in prior elements of the '     //
     2             'current structure when there are no inherited ' //
     3             'attributes.')
C  Test ISS for corners of text rectangle with:
C    starting path:         103,0
C    expected corner index: 3
C    expected found path:   103,6
      CALL ISSGEO ('103,0', 3, EXXLO,EXYLO,EXXHI,EXYHI,
     1             '103,6')
 
      CALL SETMSG ('1 2 3 4 5 6', 'Actual geometric attributes '      //
     1             'should be as set in prior elements of structure ' //
     2             'even when these precede the starting path.')
C  Test ISS for corners of text rectangle with:
C    starting path:         103,5
C    expected corner index: 3
C    expected found path:   103,6
      CALL ISSGEO ('103,5', 3, EXXLO,EXYLO,EXXHI,EXYHI,
     1             '103,6')
 
666   CONTINUE
      CALL ENDIT
      END
