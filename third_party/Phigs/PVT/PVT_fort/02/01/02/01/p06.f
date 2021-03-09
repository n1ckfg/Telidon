C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.01/06                        *
C  *    TEST TITLE : Effect of <delete structure> on       *
C  *                 element pointer                       *
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
 
C  Declare program-specific variables
      INTEGER   STRID
 
C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)
 
      CALL INITGL ('02.01.02.01/06')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  Set up CSS as:
C
C                                  100
C                                   |
C                                   |
C    ----------------------------------------------------------------------
C    | |       | |       | |       | |       | |       | |       | |      |
C    | |       | |       | |       | |       | |       | |       | |      |
C  2 | | 3   1 | | 6   4 | | 5   7 | | 11  8 | | 12  9 | | 13 10 | | 14   | 15
C    | |       | |       | |       | |       | |       | |       | |      |
C    101       102       103       104       105       106       107     108
 
      STRID = 100
      CALL POPST (STRID)
 
      CALL PEXST (102)
      CALL PEXST (101)
      CALL PEXST (101)
      CALL PEXST (103)
      CALL PEXST (103)
      CALL PEXST (102)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PEXST (106)
      CALL PEXST (107)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PEXST (106)
      CALL PEXST (107)
      CALL PEXST (108)
 
C  Throughout, expected state is shown as the sequence of
C  references within structure #100, with the current element
C  marked by an asterisk.  Thus the first state is:
C  (102, 101, 101, 103, 103, 102, 104, 105, 106, 107,
C   104, 105, 106, 107, 108*)
 
C  set edit mode to INSERT
      CALL PSEDM (PINSRT)
      CALL INMSG ('Following test cases run in INSERT mode.')
 
C  set element pointer to 5 and delete structure #107
      CALL PSEP (5)
      CALL PDST (107)
      CALL SETMSG ('6', 'When <delete structure> causes deletion of ' //
     1             'references following the current element, the '   //
     2             'element pointer should be unchanged.')
      CALL CHKELP (5)
C  (102, 101, 101, 103, 103*, 102, 104, 105, 106, 104, 105, 106, 108)
 
C  delete structure #101
      CALL PDST (101)
      CALL SETMSG ('6', 'When <delete structure> causes deletion of ' //
     1             'references preceding the current element, the '   //
     2             'element pointer should be changed so as to '      //
     3             'point to the same element.')
      CALL CHKELP (3)
C  (102, 103, 103*, 102, 104, 105, 106, 104, 105, 106, 108)
 
C  delete structure #103
      CALL PDST (103)
      CALL SETMSG ('7', 'When <delete structure> causes deletion of ' //
     1             'references at the current element, the element '  //
     2             'pointer should be changed so as to point to the ' //
     3             'preceding element.')
      CALL CHKELP (1)
C  (102*, 102, 104, 105, 106, 104, 105, 106, 108)
 
C  delete structure #102
      CALL PDST (102)
      CALL SETMSG ('7', 'When <delete structure> causes deletion of ' //
     1             'references at the current element, and no '       //
     2             'preceding element exists, the element pointer '   //
     3             'should be changed to point to zero.')
      CALL CHKELP (0)
C  (* 104, 105, 106, 104, 105, 106, 108)
 
C  set edit mode to REPLACE
      CALL PSEDM (PREPLC)
      CALL INMSG ('Following test cases run in REPLACE mode.')
 
C  delete structure #108
      CALL PDST (108)
      CALL SETMSG ('6', 'When <delete structure> causes deletion of ' //
     1             'references and the element pointer is zero, it '  //
     2             'should remain at zero.')
      CALL CHKELP (0)
C  (* 104, 105, 106, 104, 105, 106)
 
C  set element pointer to 4 and delete structure #105
      CALL PSEP (4)
      CALL PDST (105)
      CALL SETMSG ('6', 'When <delete structure> causes deletion of ' //
     1             'references surrounding the current element, the ' //
     2             'element pointer should be changed so as to '      //
     3             'point to the same element.')
      CALL CHKELP (3)
C  (104, 106, 104*, 106)
 
C  set element pointer to 4 and delete structure #106
      CALL PSEP (4)
      CALL PDST (106)
      CALL SETMSG ('7', 'When <delete structure> causes deletion of ' //
     1             'references at the current element, which is the ' //
     2             'last element, the element pointer should be '     //
     3             'changed so as to point to the preceding '         //
     4             'element.')
      CALL CHKELP (2)
C  (104, 104*)
 
C  delete structure #104
      CALL PDST (104)
      CALL SETMSG ('7', 'When <delete structure> causes deletion of ' //
     1             'references at the current element thereby '       //
     2             'emptying the structure, the element pointer '     //
     3             'should be changed to point to zero.')
      CALL CHKELP (0)
 
666   CONTINUE
      CALL ENDIT
      END
