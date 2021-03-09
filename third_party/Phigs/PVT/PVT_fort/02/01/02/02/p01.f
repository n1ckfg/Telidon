C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/01                        *
C  *    TEST TITLE : Deletion of a structure network using *
C  *                 a non-existent structure identifier   *
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
      INTEGER    PDELE,     PKEEP
      PARAMETER (PDELE = 0, PKEEP = 1)
 
C PHIGS paramter types
 
      INTEGER NOSTID, REFFG
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.02/01')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
C creation of a structure network
 
      CALL POPST (100)
      CALL PEXST (103)
      CALL PEXST (104)
      CALL PCLST
      CALL POPST (103)
      CALL PEXST (105)
      CALL PEXST (105)
      CALL PCLST
      CALL POPST (104)
      CALL PEXST (106)
      CALL PCLST
      CALL POPST (102)
      CALL PEXST (106)
      CALL PEXST (109)
      CALL PCLST
      CALL POPST (106)
      CALL PEXST (107)
      CALL PEXST (108)
      CALL PCLST
      CALL POPST (109)
      CALL PEXST (108)
      CALL PEXST (110)
      CALL PCLST
 
      CALL SETMSG ('9', '<Delete structure network> with a '          //
     1             'non-existent structure identifier and the '       //
     2             'reference handling flag set to delete should '    //
     3             'have no effect on the contents of the CSS.')
 
C nostid = non-existent structure identifier
 
      NOSTID = 25
      REFFG = PDELE
      CALL PDSN (NOSTID, REFFG)
      CALL IFPF (CSSEQ ('100, 1, 103, 1, 105, 0/'          //
     1                  '100, 1, 103, 2, 105, 0/'          //
     2                  '100, 2, 104, 1, 106, 1, 107, 0/'  //
     3                  '100, 2, 104, 1, 106, 2, 108, 0/'  //
     4                  '102, 1, 106, 1, 107, 0/'          //
     5                  '102, 1, 106, 2, 108, 0/'          //
     6                  '102, 2, 109, 1, 108, 0/'          //
     7                  '102, 2, 109, 2, 110, 0/'))
 
      CALL SETMSG ('9', '<Delete structure network> with a '          //
     1             'non-existent structure identifier and the '       //
     2             'reference handling flag set to keep should have ' //
     3             'no effect on the contents of the CSS.')
 
      NOSTID = 40
      REFFG = PKEEP
      CALL PDSN (NOSTID, REFFG)
      CALL IFPF (CSSEQ ('100, 1, 103, 1, 105, 0/'          //
     1                  '100, 1, 103, 2, 105, 0/'          //
     2                  '100, 2, 104, 1, 106, 1, 107, 0/'  //
     3                  '100, 2, 104, 1, 106, 2, 108, 0/'  //
     4                  '102, 1, 106, 1, 107, 0/'          //
     5                  '102, 1, 106, 2, 108, 0/'          //
     6                  '102, 2, 109, 1, 108, 0/'          //
     7                  '102, 2, 109, 2, 110, 0/'))
 
      CALL ENDIT
      END
