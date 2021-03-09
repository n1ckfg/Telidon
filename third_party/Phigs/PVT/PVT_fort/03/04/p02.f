C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.04/02                              *
C  *    TEST TITLE : Examine conflicting structures        *
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
 
C structure network source
      INTEGER    PCSS,     PARCHV
      PARAMETER (PCSS = 0, PARCHV = 1)
 
      INTEGER         SCALE
      PARAMETER      (SCALE = 50)
      INTEGER         ARID, ARNM, CSSNCS(SCALE), CSSLEN, ARCNCS(SCALE),
     1                ARCLEN, EXPSTR(SCALE), EXPLEN, ALLCFS(SCALE),
     2                ALLLEN, IDUM1, INTIND
      LOGICAL         SETEQ
 
      CALL INITGL ('03.04/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  open archive file = arid
      ARID = 30
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
 
C  set up structures as follows:
C
C     Archive =                         CSS =
C     ---------------------             ------------------
C     112   102    103  109             101    102     105
C           / \     |    |               |     /  \     |
C         104 105  108  114             119  104  106  107
C           \  |    |                         |  / |    |
C             110  113                       110  112  113
C
      CALL POPST (112)
      CALL PCLST
 
      CALL POPST (104)
      CALL PEXST (110)
      CALL PCLST
 
      CALL POPST (105)
      CALL PEXST (110)
      CALL PCLST
 
      CALL POPST (102)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PCLST
 
      CALL POPST (108)
      CALL PEXST (113)
      CALL PCLST
 
      CALL POPST (103)
      CALL PEXST (108)
      CALL PCLST
 
      CALL POPST (109)
      CALL PEXST (114)
      CALL PCLST
 
      CALL PARAST (ARID)
      CALL PDAS
 
      CALL POPST (101)
      CALL PEXST (119)
      CALL PCLST
 
      CALL POPST (104)
      CALL PEXST (110)
      CALL PCLST
 
      CALL POPST (106)
      CALL PEXST (110)
      CALL PEXST (112)
      CALL PCLST
 
      CALL POPST (102)
      CALL PEXST (104)
      CALL PEXST (106)
      CALL PCLST
 
      CALL POPST (107)
      CALL PEXST (113)
      CALL PCLST
 
      CALL POPST (105)
      CALL PEXST (107)
      CALL PCLST
 
C  *** ***   conflicting networks - root and descendants   *** ***
C
      CALL PQCSTN (ARID, 102, PCSS, 0, ERRIND, CSSLEN, IDUM1)
      CALL CHKINQ ('pqcstn', ERRIND)
      DO 100, INTIND = 1,  CSSLEN
         CALL PQCSTN (ARID, 102, PCSS, INTIND, ERRIND, IDUM1,
     1                CSSNCS(INTIND))
         CALL CHKINQ ('pqcstn', ERRIND)
100   CONTINUE
      CALL SETMSG ('3', 'If the CSS is the structure network source ' //
     1             'and the specified structure also exists and has ' //
     2             'descendants in the archive file, then <inquire '  //
     3             'conflicting structures in network> should '       //
     4             'return a list of identifiers which exist in '     //
     5             'both the archive and the CSS network whose root ' //
     6             'is the specified structure.')
      CALL SETVS ('102,104,110,112', EXPSTR, EXPLEN)
      CALL IFPF (SETEQ (EXPLEN, EXPSTR, CSSNCS) .AND.
     1           CSSLEN .EQ. EXPLEN)
 
 
      CALL PQCSTN (ARID, 105, PARCHV, 0, ERRIND, ARCLEN, IDUM1)
      CALL CHKINQ ('pqcstn', ERRIND)
      DO 200, INTIND = 1, ARCLEN
         CALL PQCSTN (ARID, 105, PARCHV, INTIND, ERRIND, IDUM1,
     1                ARCNCS(INTIND))
         CALL CHKINQ ('pqcstn', ERRIND)
200   CONTINUE
      CALL SETMSG ('4', 'If the archive is the structure network '    //
     1             'source and the specified structure also exists '  //
     2             'and has descendants in the CSS, then <inquire '   //
     3             'conflicting structures in network> should '       //
     4             'return a list of identifiers which exist in '     //
     5             'both the CSS and the archive network whose root ' //
     6             'is the specified structure.')
      CALL SETVS ('105,110', EXPSTR, EXPLEN)
      CALL IFPF (SETEQ (EXPLEN, EXPSTR, ARCNCS) .AND.
     1           ARCLEN .EQ. EXPLEN)
 
C  *** ***   conflicting networks - descendants only   *** ***
 
      CALL PQCSTN (ARID, 106, PCSS, 0, ERRIND, CSSLEN, IDUM1)
      CALL CHKINQ ('pqcstn', ERRIND)
      DO 300, INTIND = 1,  CSSLEN
         CALL PQCSTN (ARID, 106, PCSS, INTIND, ERRIND, IDUM1,
     1                CSSNCS(INTIND))
         CALL CHKINQ ('pqcstn', ERRIND)
300   CONTINUE
      CALL SETMSG ('3', 'If the CSS is the structure network source ' //
     1             'and the specified structure does not exist in '   //
     2             'the archive file (but some descendants do), '     //
     3             'then <inquire conflicting structures in '         //
     4             'network> should return a list of identifiers '    //
     5             'which exist in both the archive and the CSS '     //
     6             'network whose root is the specified structure.')
      CALL SETVS ('110,112', EXPSTR, EXPLEN)
      CALL IFPF (SETEQ (EXPLEN, EXPSTR, CSSNCS) .AND.
     1           CSSLEN .EQ. EXPLEN)
 
 
      CALL PQCSTN (ARID, 108, PARCHV, 0, ERRIND, ARCLEN, IDUM1)
      CALL CHKINQ ('pqcstn', ERRIND)
      DO 400, INTIND = 1,  ARCLEN
         CALL PQCSTN (ARID, 108, PARCHV, INTIND, ERRIND, IDUM1,
     1                ARCNCS(INTIND))
         CALL CHKINQ ('pqcstn', ERRIND)
400   CONTINUE
      CALL SETMSG ('4', 'If the archive is the structure network ' //
     1             'source and the specified structure does not '  //
     2             'exist in the CSS (but some descendants do), '  //
     3             'then <inquire conflicting structures in '      //
     4             'network> should return a list of identifiers ' //
     5             'which exist in both the CSS and the archive '  //
     6             'network whose root is the specified structure.')
      CALL SETVS ('113', EXPSTR, EXPLEN)
      CALL IFPF (SETEQ (EXPLEN, EXPSTR, ARCNCS) .AND.
     1           ARCLEN .EQ. EXPLEN)
 
C  *** *** *** ***   non-conflicting networks   *** *** *** ***
 
      CALL PQCSTN (ARID, 101, PCSS, 0, ERRIND, CSSLEN, IDUM1)
      CALL CHKINQ ('pqcstn', ERRIND)
      CALL SETMSG ('3', 'If the CSS is the structure network source ' //
     1             'and the specified structure neither exists nor '  //
     2             'has descendants in the archive file, then '       //
     3             '<inquire conflicting structures in network> '     //
     4             'should return an empty list.')
      CALL IFPF (CSSLEN .EQ. 0)
 
 
      CALL PQCSTN (ARID, 109, PARCHV, 0, ERRIND, ARCLEN, IDUM1)
      CALL CHKINQ ('pqcstn', ERRIND)
      CALL SETMSG ('4', 'If the archive is the structure network ' //
     1             'source and the specified structure neither '   //
     2             'exists nor has descendants in the CSS, then '  //
     3             '<inquire conflicting structures in network> '  //
     4             'should return an empty list.')
      CALL IFPF (ARCLEN .EQ. 0)
 
C  *** *** *** ***   structures conflict   *** *** *** ***
 
      CALL PQCST (ARID, 0, ERRIND, ALLLEN, IDUM1)
      CALL CHKINQ ('pqcst', ERRIND)
      DO 700, INTIND = 1,  ALLLEN
         CALL PQCST (ARID, INTIND, ERRIND, IDUM1, ALLCFS(INTIND))
         CALL CHKINQ ('pqcst', ERRIND)
700   CONTINUE
      CALL SETMSG ('2', 'If the same structure identifiers exist in ' //
     1             'both the CSS and archive file, then <inquire '    //
     2             'all conflicting structures> should return a '     //
     3             'list of all such identifiers.')
      CALL SETVS ('102,104,105,110,112,113', EXPSTR, EXPLEN)
      CALL IFPF (SETEQ (EXPLEN, EXPSTR, ALLCFS) .AND.
     1           ALLLEN .EQ. EXPLEN)
 
C  *** *** *** ***   disjoint structures   *** *** *** ***
 
C  <delete all structures from archive> to ensure empty archive
C  clear CSS
      CALL PDASAR (ARID)
      CALL PDAS
 
C  set up archive and CSS as follows:
C
C     Archive =                        CSS =
C     -----------------                ------------
C     101   102    103                 112   115
C           / \     |                         /\
C         104 105  108                     114  116
C
      CALL POPST (101)
      CALL PCLST
 
      CALL POPST (102)
      CALL PEXST (104)
      CALL PEXST (105)
      CALL PCLST
 
      CALL POPST (103)
      CALL PEXST (108)
      CALL PCLST
 
      CALL PARAST (ARID)
      CALL PDAS
 
      CALL POPST (112)
      CALL PCLST
 
      CALL POPST (115)
      CALL PEXST (114)
      CALL PEXST (116)
      CALL PCLST
 
      CALL PQCST (ARID, 0, ERRIND, ALLLEN, IDUM1)
      CALL CHKINQ ('pqcst', ERRIND)
      CALL SETMSG ('2', 'If there are no structure identifiers that ' //
     1             'exist in both the CSS and archive file, then '    //
     2             '<inquire all conflicting structures> should '     //
     3             'return an empty list.')
      CALL IFPF (ALLLEN .EQ. 0)
 
C  close archive file
      CALL PCLARF (ARID)
 
666   CONTINUE
      CALL ENDIT
      END
