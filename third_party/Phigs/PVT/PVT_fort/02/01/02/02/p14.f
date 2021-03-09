 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/14                        *
C  *    TEST TITLE : Effect of deleting structure networks *
C  *                 on element pointer                    *
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
 
C reference handling flag
      INTEGER    PDELE,     PKEEP
      PARAMETER (PDELE = 0, PKEEP = 1)
 
C edit mode
      INTEGER    PINSRT,     PREPLC
      PARAMETER (PINSRT = 0, PREPLC = 1)
 
      CALL INITGL ('02.01.02.02/14')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  Set up CSS as:
C
C                                 40
C                                  |       50
C                               D:41      /  \
C                                  |     /    \
C                                 42   100   D:51
C                                  |  / |\    / |
C                                 43 /  | \4 /  |
C      20                          |/3  |  511  |
C     /  \                        44    |       |
C    /    \                             |       |
C  21    D:22   -----------------------/ \     /
C         /  \ 1|       2|            /   \6  /
C        /    \ |        |  D:60     /     \ /
C       /      \|      D:30    \    /\     512
C     221      222       / \    \ 5/  \7    |
C               |       /   \    \/    \    |
C               |     31     32  61    70  5121
C              2221
C
C
C  The nodes of the graph (20 and above) represent structures, and
C  the labelled edges are references to invoke (lower) structures.
C  The labels (1- 7) represent the element position of the <execute
C  structure> function within structure #100.  The structures that
C  are specified by <delete structure network> are prefaced by "D:".
 
      CALL POPST (20)
      CALL PEXST (21)
      CALL PEXST (22)
      CALL PCLST
 
      CALL POPST (22)
      CALL PEXST (221)
      CALL PEXST (222)
      CALL PCLST
 
      CALL POPST (222)
      CALL PEXST (2221)
      CALL PCLST
 
      CALL POPST (30)
      CALL PEXST (31)
      CALL PEXST (32)
      CALL PCLST
 
      CALL POPST (40)
      CALL PEXST (41)
      CALL PCLST
 
      CALL POPST (41)
      CALL PEXST (42)
      CALL PCLST
 
      CALL POPST (42)
      CALL PEXST (43)
      CALL PCLST
 
      CALL POPST (43)
      CALL PEXST (44)
      CALL PCLST
 
      CALL POPST (50)
      CALL PEXST (100)
      CALL PEXST (51)
      CALL PCLST
 
      CALL POPST (51)
      CALL PEXST (511)
      CALL PEXST (512)
      CALL PCLST
 
      CALL POPST (512)
      CALL PEXST (5121)
      CALL PCLST
 
      CALL POPST (60)
      CALL PEXST (61)
      CALL PCLST
 
      CALL POPST (100)
      CALL PEXST (222)
      CALL PEXST (30)
      CALL PEXST (44)
      CALL PEXST (511)
      CALL PEXST (61)
      CALL PEXST (512)
      CALL PEXST (70)
 
C  Structure 100 is left open.
C
C  Throughout, the expected state is shown as the sequence of
C  references within structure #100, with the current element
C  marked by an asterisk.  Thus the first state is:
C
C     (222, 30*, 44, 511, 61, 512, 70)
 
      CALL PSEDM (PREPLC)
      CALL INMSG ('Following test cases run in REPLACE mode.')
 
C  set element pointer to 2 and delete structure network #30
      CALL PSEP (2)
      CALL PDSN (30, PDELE)
      CALL SETMSG ('12', 'When <delete structure network> causes '    //
     1             'deletion of references at the current element, '  //
     2             'the element pointer should be changed so as to '  //
     3             'point to the preceding element.')
      CALL CHKELP (1)
C  (222*, 44, 511, 61, 512, 70)
 
C  delete structure network #22
      CALL PDSN (22, PDELE)
      CALL SETMSG ('12', 'When <delete structure network> causes '    //
     1             'deletion of references at the current element, '  //
     2             'the element pointer should be changed to zero '   //
     3             'when there is no preceding element.')
      CALL CHKELP (0)
C  (* 44, 511, 61, 512, 70)
 
      CALL PSEDM (PINSRT)
      CALL INMSG ('Following test cases run in INSERT mode.')
 
C  delete structure network #41
      CALL PDSN (41, PDELE)
      CALL SETMSG ('11', 'When <delete structure network> causes '    //
     1             'deletion of references following the current '    //
     2             'element, the element pointer should be '          //
     3             'unchanged.')
      CALL CHKELP (0)
C  (* 511, 61, 512, 70)
 
C  set element pointer to 2 and delete structure network #51
      CALL PSEP (2)
      CALL PDSN (51, PDELE)
      CALL SETMSG ('11', 'When <delete structure network> causes '    //
     1             'deletion of references surrounding the current '  //
     2             'element, the element pointer should be changed '  //
     3             'so as to point to the same element.')
      CALL CHKELP (1)
C  (61*, 70)
 
C  set element pointer to 2
C  delete structure network #60, ref-flag = KEEP
      CALL PSEP (2)
      CALL PDSN (60, PKEEP)
      CALL SETMSG ('11', 'When <delete structure network> does not '  //
     1             'cause deletion of a reference in the open '       //
     2             'structure because the reference flag is KEEP, '   //
     3             'the element pointer should be unchanged.')
      CALL CHKELP (2)
C  (61, 70*)
 
666   CONTINUE
      CALL ENDIT
      END
