 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/13                        *
C  *    TEST TITLE : Deletion of a structure network with  *
C  *                 the reference flag set to keep and    *
C  *                 references are not made to the open   *
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
 
      INTEGER PKEEP, POPNST, PSEMPT
 
      PARAMETER (PKEEP = 1, POPNST = 1, PSEMPT = 1)
 
C PHIGS parameter types
 
      INTEGER REFFG, SPECF, NOSPEC, STYPE, STRREF, STRSTI, PSTNUM,
     1        STRID, PSPEC
 
      REAL RDUM1
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.02/13')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL DELCSS
 
      CALL SETMSG ('5 7 8', 'When the reference handling flag is '   //
     1             'set to keep and an open non-specified structure '//
     2             'is not referenced outside the structure network '//
     3             'the following changes should occur in the CSS: ' //
     4             'The specified and closed non-specified '         //
     5             'structures all of whose maximal ancestor paths ' //
     6             'contain the specified structure are removed. An '//
     7             'open non-specified structure one of whose '      //
     8             'maximal ancestor paths contain the specified '   //
     9             'structure remains OPEN and EMPTY. Closed '       //
     1             'non-specified structures one of whose maximal '  //
     2             'ancestor paths does not contain the specified '  //
     3             'structure remain AS IS.')
 
C specf  = open specified structure (and posted specified structure)
C nospec = non-specified structure
 
      SPECF  = 102
      NOSPEC = 105
      PSPEC  = 108
      REFFG = PKEEP
      CALL POPST (NOSPEC)
      CALL PPOST (WKID, SPECF, 0.)
      CALL PPOST (WKID, PSPEC, 0.)
      CALL PDSN (SPECF, REFFG)
      CALL IFPF (CSSEQ ('100, 1, 101, 1, 103, 0/'                   //
     1                  '100, 1, 101, 2, 103, 0/'                   //
     2                  '105, 0/'                                   //
     3                  '120, 1, 106, 1, 108, 1, 111, 1, 114, 0/'   //
     4                  '120, 1, 106, 1, 108, 1, 111, 2, 115, 0/'   //
     5                  '130, 1, 106, 1, 108, 1, 111, 1, 114, 0/'   //
     6                  '130, 1, 106, 1, 108, 1, 111, 2, 115, 0/'   //
     7                  '130, 2, 107, 1, 108, 1, 111, 1, 114, 0/'   //
     8                  '130, 2, 107, 1, 108, 1, 111, 2, 115, 0/'   //
     9                  '130, 2, 107, 2, 108, 1, 111, 1, 114, 0/'   //
     1                  '130, 2, 107, 2, 108, 1, 111, 2, 115, 0/'   //
     2                  '130, 2, 107, 3, 113, 0/'                   //
     3                  '140, 1, 142, 0/'))
 
      CALL SETMSG ('5', '<Delete structure network> with the '        //
     1             'reference flag set to keep and an open '          //
     1             'non-specified structure present in the network '  //
     2             'and not referenced outside the structure '        //
     3             'network should cause that structure to exist in ' //
     4             'the CSS as an open structure.')
 
C use <inquire open structure to determine
C stype = the structure status open or close
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
 
      CALL SETMSG ('5', '<Delete structure network> with the '        //
     1             'reference flag set to keep and an open '          //
     2             'non-specified structure present in the network '  //
     3             'and not referenced outside the structure '        //
     4             'network should cause that structure to exist in ' //
     5             'the CSS as an empty structure.')
 
C use <inquire structure status> on the non-specified structure to determine
C strsti = structure status identifier
 
      CALL PQSTST (NOSPEC, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STRSTI .EQ. PSEMPT)
 
      CALL SETMSG ('10', '<Delete structure network> should cause '   //
     1             'a closed posted non-specified structure '         //
     2             'referenced outside the structure network to '     //
     3             'remain posted and the closed posted specified '   //
     4             'structure to become unposted from the '           //
     5             'workstation when the reference handling flag is ' //
     6             'set to keep.')
 
C use <inquire posted structures> to determine
C pstnum = number of posted structures
C strid = Nth identifier of the posted structure
 
      CALL PQPOST (WKID, 1, ERRIND, PSTNUM, STRID, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      CALL IFPF (PSTNUM .EQ. 1 .AND.
     1           STRID  .EQ. PSPEC)
 
      CALL ENDIT
      END
