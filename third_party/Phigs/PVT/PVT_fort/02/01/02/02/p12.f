
C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.02/12                        *
C  *    TEST TITLE : Deletion of a structure network with  *
C  *                 the reference flag set to keep and    *
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

      INTEGER PKEEP, POPNST, PSEMPT

      PARAMETER (PKEEP = 1, POPNST = 1, PSEMPT = 1)

C PHIGS parameter types

      INTEGER REFFG, SPECF, NOSPEC, STYPE, STRREF, PSTNUM,
     1        STRID

      REAL RDUM1

      LOGICAL CSSEQ

      CALL INITGL ('02.01.02.02/12')

C open PHIGS

      CALL XPOPPH (ERRFIL, MEMUN)

C open workstation

      CALL POPWK (WKID, CONID, WTYPE)

      CALL DELCSS

      CALL SETMSG ('6 7 8', 'When the reference handling flag is '    //
     1             'set to keep and the open non-specified '          //
     2             'structure is referenced outside the structure '   //
     3             'network the following changes should occur to '   //
     4             'the CSS: The specified and all closed '           //
     5             'non-specified structures all of whose maximal '   //
     6             'ancestor paths contain the specified structure '  //
     7             'are removed. All non-specified opened or closed ' //
     8             'structures one of whose maximal ancestor path '   //
     9             'does not contain the specified structure remain ' //
     1             'AS IS.')

C specf = open specified structure (and posted specified structure)
C nospec = non-specified structure

      SPECF  = 100
      NOSPEC = 108
      REFFG = PKEEP
      CALL POPST (NOSPEC)
      CALL PPOST (WKID, SPECF, 0.)
      CALL PPOST (WKID, NOSPEC, 0.)
      CALL PDSN (SPECF, REFFG)
      CALL IFPF (CSSEQ ('120, 1, 106, 1, 108, 1, 111, 1, 114, 0/'   //
     1                  '120, 1, 106, 1, 108, 1, 111, 2, 115, 0/'   //
     2                  '130, 1, 106, 1, 108, 1, 111, 1, 114, 0/'   //
     3                  '130, 1, 106, 1, 108, 1, 111, 2, 115, 0/'   //
     4                  '130, 2, 107, 1, 108, 1, 111, 1, 114, 0/'   //
     5                  '130, 2, 107, 1, 108, 1, 111, 2, 115, 0/'   //
     6                  '130, 2, 107, 2, 108, 1, 111, 1, 114, 0/'   //
     7                  '130, 2, 107, 2, 108, 1, 111, 2, 115, 0/'   //
     8                  '130, 2, 107, 3, 113, 0/'                   //
     9                  '140, 1, 142, 0/'))

      CALL SETMSG ('6','<Delete structure network> with the '     //
     1             'reference flag set to keep and an open '      //
     2             'non-specified structure which is '            //
     3             'referenced outside the structure network '    //
     4             'should cause that structure to exist in '     //
     5             'the CSS as an open structure.')

C Use <inquire open structure> to determine:
C stype  = the structure status open or closed
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


      CALL SETMSG ('10', '<Delete structure network> should cause '   //
     1             'the open posted non-specified structure '         //
     2             'referenced outside the structure network to '     //
     3             'remain posted and the closed posted specified '   //
     4             'to become unposted from the workstation when '    //
     5             'the reference handling flag is set to keep.')

C use <inquire posted structures> to determine
C pstnum = number of posted structures

      CALL PQPOST (WKID, 1, ERRIND, PSTNUM, STRID, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      CALL IFPF (PSTNUM .EQ. 1 .AND.
     1           STRID  .EQ. NOSPEC)

      CALL ENDIT
      END
