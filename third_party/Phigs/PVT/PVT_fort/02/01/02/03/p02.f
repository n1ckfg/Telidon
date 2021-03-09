C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.03/02                        *
C  *    TEST TITLE : Deletion of all structures with an    *
C  *                 open structure                        *
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

      INTEGER POPNST, PSEMPT
      PARAMETER (POPNST = 1, PSEMPT = 1)

C PHIGS parameter types

      INTEGER NSTID, NSTR, STRID, STRREF, STRSTI,
     1        STYPE

      CALL INITGL ('02.01.02.03/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C creation of structures
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
      CALL POPST (106)
      CALL PEXST (107)
      CALL PEXST (108)
      CALL PCLST
      CALL POPST (102)
      CALL PEXST (106)
      CALL PEXST (109)
      CALL PCLST
      CALL POPST (109)
      CALL PEXST (108)
      CALL PEXST (110)
      CALL PCLST

      CALL SETMSG ('1', '<Delete all structures> with an open ' //
     1             'structure should remove all closed '        //
     2             'structures from the CSS.')

      STRID = 106
      CALL POPST (STRID)
      CALL PDAS

C nstid = number of structure identifiers
      CALL PQSID (1, ERRIND, NSTID, NSTR)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL IFPF (NSTID .EQ. 1 .AND. NSTR .EQ. STRID)

      CALL SETMSG ('2', '<Delete all structures> with an open ' //
     1             'structure should cause that structure to '  //
     2             'exist in the CSS as an open structure.')

C use <inquire open structure> to determine
C    stype  = structure status
C    strref = structure id

      CALL PQOPST (ERRIND, STYPE, STRREF)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .NE. POPNST .OR.
     1    STRID .NE. STRREF)   THEN
         CALL FAIL
      ELSE
         CALL PASS
         CALL PCLST
      ENDIF

      CALL SETMSG ('2', '<Delete all structures> with an open ' //
     1             'structure should cause that structure to '  //
     2             'exist in the CSS as an empty structure.')

C strsti = structure status identifier
      CALL PQSTST (STRID, ERRIND, STRSTI)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF   (STRSTI .EQ. PSEMPT)

      CALL ENDIT
      END
