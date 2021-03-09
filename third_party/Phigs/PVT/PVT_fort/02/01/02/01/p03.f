C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.01/03                        *
C  *    TEST TITLE : Deletion of a non-existent structure  *
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
 
 
C PHIGS parameter types
 
      INTEGER NOSTID
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.01/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C creation of structures
      CALL POPST (100)
      CALL PEXST (105)
      CALL PEXST (110)
      CALL PCLST
 
      CALL SETMSG ('3', 'Deleting a non-existent structure ' //
     1             'should have no effect on the contents '  //
     2             'of the CSS.')
 
      NOSTID = 25
      CALL PDST (NOSTID)
 
      CALL IFPF (CSSEQ ('100,1, 105,0/ 100,2, 110,0/'))
 
      CALL ENDIT
      END
