 
 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/06                        *
C  *    TEST TITLE : Deletion of a structure network with  *
C  *                 the reference flag set to delete and  *
C  *                 references are made to the open       *
C  *                 non-specified structure               *
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
 
 
C parameter for structure status, reference flag, structure empty
 
      INTEGER PDELE, POPNST, PSEMPT
 
      PARAMETER (PDELE = 0, POPNST = 1, PSEMPT = 1)
 
C PHIGS parameter types
 
      INTEGER REFFG, SPECF, NOSPEC, STYPE, STRREF, STRSTI, PSTNUM, IDUM1
 
      REAL RDUM1
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.02/06')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL DELCSS
 
      CALL SETMSG ('2 3 4', 'When the reference handling flag is '    //
     1             'set to delete and the open non-specified '        //
     2             'structure is referenced outside the structure '   //
     3             'network the following changes should occur to '   //
     4             'the CSS: All closed structures contained in the ' //
     5             'structure network are removed. The '              //
     6             'non-specified structure is OPEN and EMPTY.')
 
 
C specf = open specified structure (and posted specified structure)
C nospec open non-specified structure
 
      SPECF  = 106
      NOSPEC = 108
      REFFG = PDELE
      CALL POPST (NOSPEC)
      CALL PPOST (WKID, SPECF, 0.)
      CALL PPOST (WKID, NOSPEC, 0.)
      CALL PDSN (SPECF, REFFG)
      CALL IFPF (CSSEQ ('100, 1, 101, 1, 103, 0/'            //
     1                  '100, 1, 101, 2, 103, 0/'            //
     2                  '100, 2, 102, 1, 104, 1, 109, 0/'    //
     3                  '100, 2, 102, 1, 104, 2, 109, 0/'    //
     4                  '100, 2, 102, 2, 105, 1, 110, 0/'    //
     5                  '108, 0/'                            //
     6                  '120, 0/'                            //
     7                  '130, 1, 107, 1, 113, 0/'            //
     8                  '140, 1, 142, 0/'))
 
 
      CALL SETMSG ('2', '<Delete structure network> with the '        //
     1             'reference flag set to delete and an open '        //
     2             'non-specified structure present in the network '  //
     3             'and referenced outside the structure network '    //
     4             'should cause that structure to exist in the CSS ' //
     5             'as an open structure.')
 
C use <inquire open structure> to determine
C stype  = the structure status open or close
C strref = structure id
 
      CALL PQOPST (ERRIND, STYPE, STRREF)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE  .EQ. POPNST .AND.
     1    NOSPEC .EQ. STRREF)    THEN
          CALL PASS
          CALL PCLST
      ELSE
          CALL FAIL
      ENDIF
 
      CALL SETMSG ('2', '<Delete structure network> with the '        //
     1             'reference flag set to delete and an open '        //
     2             'non-specified structure present in the network '  //
     3             'and referenced outside the structure network '    //
     4             'should cause that structure to exist in the CSS ' //
     5             'as an empty structure.')
 
C use <inquire structure status> on a non-specified structure to determine
C strsti = structure status identifier
 
      CALL PQSTST (NOSPEC, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STRSTI .EQ. PSEMPT)
 
      CALL SETMSG ('10', '<Delete structure network> should cause '   //
     1             'the closed posted specified and an open posted '  //
     2             'non-specified structure referenced outside the '  //
     3             'structure network to become unposted from a '     //
     4             'workstation when the reference handling flag is ' //
     5             'set to delete.')
 
C use <inquire posted structures> to determine
C pstnum = number of posted structures
 
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      CALL IFPF (PSTNUM .EQ. 0)
 
      CALL ENDIT
      END
