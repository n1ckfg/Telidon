C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/03                        *
C  *    TEST TITLE : Deletion of a structure network with  *
C  *                 the reference flag set to delete and  *
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
 
C PHIGS parameter type for reference handling flag
 
      INTEGER PDELE
 
      PARAMETER (PDELE = 0)
 
C PHIGS parameter types
 
      INTEGER SPECF, REFFG
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.02/03')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL DELCSS
 
      CALL SETMSG ('3 4', 'When the reference handling flag is set '  //
     1             'to delete and the closed specified structure is ' //
     2             'not referenced outside the structure network '    //
     3             'the following changes should occur to the CSS: '  //
     4             'All closed structures contained in a structure '  //
     5             'network are removed.')
 
C specf = closed specified structure
 
      SPECF = 120
      REFFG = PDELE
      CALL PDSN (SPECF, REFFG)
      CALL IFPF (CSSEQ ('100, 1, 101, 1, 103, 0/'           //
     1                  '100, 1, 101, 2, 103, 0/'           //
     2                  '100, 2, 102, 1, 104, 1, 109, 0/'   //
     3                  '100, 2, 102, 1, 104, 2, 109, 0/'   //
     4                  '100, 2, 102, 2, 105, 1, 110, 0/'   //
     5                  '130, 1, 107, 1, 113, 0/'           //
     6                  '140, 1, 142, 0/'))
 
      CALL ENDIT
      END
