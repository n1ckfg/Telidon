C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/09                        *
C  *    TEST TITLE : Deletion of a structure network with  *
C  *                 the reference flag set to keep and    *
C  *                 references are not made to the closed *
C  *                 specified structure                   *
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
 
 
C parameter for structure status
 
      INTEGER PKEEP
 
      PARAMETER (PKEEP = 1)
 
C PHIGS parameter types
 
      INTEGER REFFG, SPECF
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.02/09')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL DELCSS
 
      CALL SETMSG ('7 8', 'When the reference handling flag is '      //
     1             'set to keep and the closed specified structure '  //
     2             'is not referenced outside the structure network ' //
     3             'the following changes should occur to the CSS: '  //
     4             'All closed network structures all of whose '      //
     5             'maximal ancestor paths contain the specified '    //
     6             'structure are removed. All non-specified '        //
     7             'structures one of whose maximal ancestor path '   //
     8             'does not contain the specified structure remain ' //
     9             'AS IS.')
 
C specf = open specified structure (and posted specfied structure)
 
      SPECF = 100
      REFFG = PKEEP
      CALL PDSN (SPECF, REFFG)
      CALL IFPF (CSSEQ ('120, 1, 106, 1, 108, 1, 111, 1, 114, 0/'  //
     1                  '120, 1, 106, 1, 108, 1, 111, 2, 115, 0/'  //
     2                  '130, 1, 106, 1, 108, 1, 111, 1, 114, 0/'  //
     3                  '130, 1, 106, 1, 108, 1, 111, 2, 115, 0/'  //
     4                  '130, 2, 107, 1, 108, 1, 111, 1, 114, 0/'  //
     5                  '130, 2, 107, 1, 108, 1, 111, 2, 115, 0/'  //
     6                  '130, 2, 107, 2, 108, 1, 111, 1, 114, 0/'  //
     7                  '130, 2, 107, 2, 108, 1, 111, 2, 115, 0/'  //
     8                  '130, 2, 107, 3, 113, 0/'                  //
     9                  '140, 1, 142, 0/'))
 
      CALL ENDIT
      END
