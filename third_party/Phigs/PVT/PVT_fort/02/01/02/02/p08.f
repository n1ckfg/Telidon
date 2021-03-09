 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/08                        *
C  *    TEST TITLE : Deletion of a structure network with  *
C  *                 the reference flag set to keep and    *
C  *                 references are made to the closed     *
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
 
      CALL INITGL ('02.01.02.02/08')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL DELCSS
 
      CALL SETMSG ('7 8', 'When the reference handling flag is '     //
     1             'set to keep and the closed specified structure ' //
     2             'is referenced outside the structure network the '//
     3             'following changes should occur to the CSS: The ' //
     4             'specified and all closed non-specified '         //
     5             'structures all of whose maximal ancestor paths ' //
     6             'contain the specified structure are removed. '   //
     7             'All non-specified structures one of whose '      //
     8             'maximal ancestor path does not contain the '     //
     9             'specified structure remain AS IS.')
 
C specf = open specified structure (and posted specified structure)
 
      SPECF = 108
      REFFG = PKEEP
      CALL PDSN (SPECF, REFFG)
      CALL IFPF (CSSEQ ('100, 1, 101, 1, 103, 0/'                //
     1                  '100, 1, 101, 2, 103, 0/'                //
     2                  '100, 2, 102, 1, 104, 1, 109, 0/'        //
     3                  '100, 2, 102, 1, 104, 2, 109, 0/'        //
     4                  '100, 2, 102, 2, 105, 1, 110, 0/'        //
     5                  '100, 2, 102, 2, 105, 2, 114, 0/'        //
     6                  '100, 2, 102, 3, 106, 0/'                //
     7                  '120, 1, 106, 0/'                        //
     8                  '130, 1, 106, 0/'                        //
     9                  '130, 2, 107, 1, 113, 0/'                //
     1                  '140, 1, 142, 0/'))
 
      CALL ENDIT
      END
