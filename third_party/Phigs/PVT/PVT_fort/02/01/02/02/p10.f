 
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/10                        *
C  *    TEST TITLE : Deletion of a structure network with  *
C  *                 the reference flag set to keep and    *
C  *                 references are made to the open       *
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
 
 
C parameter for structure status, reference flag, structure empty
 
      INTEGER PKEEP, POPNST, PSEMPT
 
      PARAMETER (PKEEP = 1, POPNST = 1, PSEMPT = 1)
 
C PHIGS parameter types
 
      INTEGER REFFG, SPECF, STYPE, STRREF, STRSTI, PSTNUM, IDUM1
 
      LOGICAL CSSEQ
 
      REAL RDUM1
 
      CALL INITGL ('02.01.02.02/10')
 
C open PHIGS
 
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL DELCSS
 
      CALL SETMSG ('5 7 8', 'When the reference handling flag is '   //
     1             'set to keep and the open specified structure is '//
     2             'referenced outside the structure network the '   //
     3             'following changes should occur to the CSS: All ' //
     4             'closed non-specified structures all of whose '   //
     5             'maximal ancestor paths contain the specified '   //
     6             'structure are removed. The specified structure ' //
     7             'is OPEN and EMPTY. All non-specified structures '//
     8             'one of whose maximal ancestor paths does not '   //
     9             'contain the specified structure remain AS IS.')
 
C specf = open specified structure (and posted specified structure)
 
      SPECF = 102
      REFFG = PKEEP
      CALL POPST (SPECF)
      CALL PPOST (WKID, SPECF, 0.)
      CALL PDSN (SPECF, REFFG)
      CALL IFPF (CSSEQ ('100, 1, 101, 1, 103, 0/'                   //
     1                  '100, 1, 101, 2, 103, 0/'                   //
     2                  '102, 0/'                                   //
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
     2             'specified structure which is referenced outside ' //
     3             'the structure network should cause that '         //
     4             'structure to exist in the CSS as an open '        //
     5             'structure.')
 
C use <inquire open structure to determine
C stype  = the structure status open or close
C strref = structure id
 
      CALL PQOPST (ERRIND, STYPE, STRREF)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .EQ. POPNST .AND.
     1    SPECF .EQ. STRREF)    THEN
          CALL PASS
          CALL PCLST
      ELSE
          CALL FAIL
      ENDIF
 
      CALL SETMSG ('5', '<Delete structure network> with the '        //
     1             'reference flag set to keep and an open '        //
     2             'specified structure which is referenced outside ' //
     3             'the structure network should cause that '         //
     4             'structure to exist in the CSS as an empty '       //
     5             'structure.')
 
C use <inquire structure status> on specified structure to determine
C strsti = structure status identifier
 
      CALL PQSTST (SPECF, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STRSTI .EQ. PSEMPT)
 
      CALL SETMSG ('10', '<Delete structure network> should cause '   //
     1             'the open specified structure referenced outside ' //
     2             'the structure network to become unposted from '   //
     3             'the workstation when the reference handling '     //
     4             'flag is set to keep.')
 
C use <inquire posted structures> to determine
C pstnum = number of posted structures
 
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      CALL IFPF (PSTNUM .EQ. 0)
 
      CALL ENDIT
      END
