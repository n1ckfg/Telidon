C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.03/01                              *
C  *    TEST TITLE : Effects of posting on the structure   *
C  *                 state list and workstation state list *
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

C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)

      INTEGER     NUMSTR
      PARAMETER  (NUMSTR = 4)

      INTEGER     ACCOUT, STRID(NUMSTR), IWK, ISTR, NUMWKS, STST
      INTEGER     STINWK(NUMSTR, 3), STVSWK(NUMSTR, 3), LSIZ
      INTEGER     SIMOPW, ACWKID(3), OCONID(3), OWTYPE(3), THISTR
      INTEGER     IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7

      REAL        THISDP, DP,NP, RDUM1

      LOGICAL     UPSW, LWPCOD, LPSCOD

      CHARACTER   OWCAT*1

      CALL INITGL ('05.03/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  *** *** *** *** ***   Initialization   *** *** *** *** ***
C
C  workstation setup:
C  Use <inquire phigs facilities> to determine:
C     simopw = maximum number of simultaneously open workstations
C  accout = number of accessible workstations with output capabilities
C  acwkid = array containing the specified workstation identifiers
C  numwks = min (3, accout, simopw) = number of workstations open
      CALL PQPHF (1, ERRIND, SIMOPW,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7)
      CALL CHKINQ ('pqphf', ERRIND)
      CALL MULTWS (0, 'od', ACCOUT, ACWKID(1), OCONID(1),
     1             OWTYPE(1), OWCAT)
      NUMWKS = MIN (3, ACCOUT, SIMOPW)

C  table setup:
C  stvswk = all -1's, indicating unposted = 4 rows x 3 column array
C           indicating what structures (rows) are expected to be
C           posted to what workstations (columns).
C  stinwk = 4 rows x 3 column array indicating what structures
C           (rows) are initially posted to what workstations
C           (columns).

      DO 300 ISTR = 1,NUMSTR
      DO 310 IWK  = 1,NUMWKS
         STINWK(ISTR, IWK) = -1
         STVSWK(ISTR, IWK) = -1
310   CONTINUE
300   CONTINUE

C  open workstations:
      DO 100 IWK = 1,NUMWKS
         CALL MULTWS (IWK, 'od', ACCOUT, ACWKID(IWK), OCONID(IWK),
     1                OWTYPE(IWK), OWCAT)
         CALL POPWK (ACWKID(IWK), OCONID(IWK), OWTYPE(IWK))
100   CONTINUE

      CALL SETMSG ('11 14', 'Immediately after opening a '            //
     1             'workstation, its list of posted structures '      //
     2             'should be empty.')
      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL IFPF (LPSCOD)

C  structure setup:
C  numstr = 4 = number of structures
C  strid  = array containing the specified structure identifiers

C  create structures:
      DO 200 ISTR = 1,NUMSTR
         STRID(ISTR) = 100+ISTR
200   CONTINUE

      CALL POPST (STRID(1))
      CALL PEXST (STRID(2))
      CALL PEMST (STRID(3))
      CALL PCLST
      CALL POPST (STRID(4))

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('10 13', 'Immediately after a structure is '  //
     1             'created, its list of workstations to which ' //
     2             'posted should be empty.')
      CALL IFPF (LWPCOD)

      CALL SETMSG ('10 14', 'Immediately after a structure is ' //
     1             'created, no list of posted structures '     //
     2             'should contain it.')
      CALL IFPF (LPSCOD)

C  *** *** *** *** ***   Posting   *** *** *** *** ***
C
C  Loop posts structures as follows:
C     structure    workstations to which posted
C     ---------    ----------------------------
C         1        all
C         2        first and last
C         3        all but the last
C         4        all but the first

      DO 400 IWK  = 1, NUMWKS
      DO 410 ISTR = 1, NUMSTR
         IF ((ISTR .EQ. 1)                                         .OR.
     1       (ISTR .EQ. 2 .AND. (IWK .EQ. 1 .OR. IWK .EQ. NUMSTR)) .OR.
     2       (ISTR .EQ. 3 .AND.  IWK .NE. NUMSTR)                  .OR.
     3       (ISTR .EQ. 4 .AND.  IWK .NE. 1) )         THEN
            STINWK (ISTR, IWK) = 1
            STVSWK (ISTR, IWK) = 1
         ENDIF
410   CONTINUE
400   CONTINUE

C  post structures to workstations, according to stinwk
      CALL SETPST (NUMSTR, STRID, NUMWKS, ACWKID, STINWK)

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('1 13', '<Post structure> should add the '         //
     1             'workstation identifier to the list of '           //
     2             'workstations to which posted of the specified '   //
     3             'structure.')
      CALL IFPF (LWPCOD)

      CALL SETMSG ('2 14', '<Post structure> should add the '         //
     1             'structure identifier to the list of posted '      //
     2             'structures of the specified workstation.')
      CALL IFPF (LPSCOD)

C  Re-post 2nd structure to 1st workstation, with different priority = dp
      DP = 0.0
      CALL PPOST (ACWKID(1), STRID(2), DP)

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('4 13', '<Post structure> should leave unchanged ' //
     1             'the list of workstations to which posted of the ' //
     2             'specified structure when that structure has '     //
     3             'already been posted to the specified workstation.')
      CALL IFPF (LWPCOD)

      CALL SETMSG ('4 14', '<Post structure> should leave unchanged ' //
     1             'the list of posted structures of the specified '  //
     2             'workstation when the specified structure has '    //
     3             'already been posted to that workstation.')
      CALL IFPF (LPSCOD)

      CALL SETMSG ('4 14', '<Post structure> should change the '      //
     1             'relevant display priority in the list of posted ' //
     2             'structures when the specified structure has '     //
     3             'already been posted to the specified workstation.')

C  <inquire list of posted structures> for 2nd structure, 1st workstation
C  to determine new priority = np
      CALL PQPOST (ACWKID(1), 0, ERRIND, LSIZ, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      NP = DP + 100.0
C  find STRID(2) in list of posted structures
      DO 450 ISTR = 1, LSIZ
         CALL PQPOST (ACWKID(1), ISTR, ERRIND, IDUM1, THISTR, THISDP)
         CALL CHKINQ ('pqpost', ERRIND)
         IF (THISTR .EQ. STRID(2)) THEN
            NP = THISDP
            GOTO 460
         ENDIF
450   CONTINUE
460   CONTINUE
      CALL IFPF (NP .EQ. DP)

C  *** *** *** ***   Unposting a non-existent structure   *** *** *** ***

      CALL PUPOST (ACWKID(1), 99)

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('7 13', 'Unposting a non-existent structure '      //
     1             'should have no effect on any list of '            //
     2             'workstations to which posted.')
      CALL IFPF (LWPCOD)

      CALL SETMSG ('7 14', 'Unposting a non-existent structure '      //
     1             'should have no effect on any list of posted '     //
     2             'structures.')
      CALL IFPF (LPSCOD)

      CALL SETMSG ('7', 'Unposting a non-existent structure should ' //
     1             'not create the specified structure.')
      CALL PQSTST (99, ERRIND, STST)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL IFPF (STST .EQ. PSNOEX)

*** *** *** ***   Unposting an unposted existent structure   *** *** *** ***

C  make sure structure #99 exists
      CALL PEMST (99)

      CALL PUPOST (ACWKID(1), 99)

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('7 13', 'Unposting an unposted structure ' //
     1             'should have no effect on any list of '    //
     2             'workstations to which posted.')
      CALL IFPF (LWPCOD)

      CALL SETMSG ('7 14', 'Unposting an unposted structure '      //
     1             'should have no effect on any list of posted '  //
     2             'structures.')
      CALL IFPF (LPSCOD)

C  *** *** ***   Unposting individual structures  *** *** ***

C  unpost every other posting:
      UPSW = .FALSE.

      DO 500 ISTR = 1, NUMSTR
      DO 510 IWK  = 1, NUMWKS
         IF (STVSWK(ISTR, IWK) .EQ. 1) THEN
            UPSW = .NOT. UPSW
            IF (UPSW) THEN
               CALL PUPOST (ACWKID(IWK), STRID(ISTR))
               STVSWK(ISTR, IWK) = -1
            ENDIF
         ENDIF
510   CONTINUE
500   CONTINUE

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('5 13', '<Unpost structure> should remove the '    //
     1             'workstation identifier from the list of '         //
     2             'workstations to which posted of the specified '   //
     3             'structure.')
      CALL IFPF (LWPCOD)

      CALL SETMSG ('6 14', '<Unpost structure> should remove the '    //
     1             'structure identifier from the list of posted '    //
     2             'structures of the specified workstation.')
      CALL IFPF (LPSCOD)

C  *** *** ***   Unposting all structures  *** *** ***

C  post structures to workstations, according to stinwk
      CALL SETPST (NUMSTR, STRID, NUMWKS, ACWKID, STINWK)

      DO 600 ISTR = 1, NUMSTR
      DO 610 IWK  = 1, NUMWKS
         STVSWK(ISTR, IWK) = STINWK(ISTR, IWK)
610   CONTINUE
600   CONTINUE

C  <unpost all structures> acwkid(1) and note in stvswk
      CALL PUPAST (ACWKID(1))
      DO 650 ISTR = 1, NUMSTR
         STVSWK(ISTR, 1) = -1
650   CONTINUE

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('8 13', '<Unpost all structures> should remove '   //
     1             'the workstation identifier from the list of '     //
     2             'workstations to which posted in all the '         //
     3             'structure state lists.')
      CALL IFPF (LWPCOD)

      CALL SETMSG ('9 14', '<Unpost all structures> should remove '   //
     1             'all structure identifiers from the list of '      //
     2             'posted structures of the specified workstation.')
      CALL IFPF (LPSCOD)

C  *** *** *** *** ***   Close workstation   *** *** *** *** ***

C  post structures to workstations, according to stinwk
      CALL SETPST (NUMSTR, STRID, NUMWKS, ACWKID, STINWK)

      DO 700 ISTR = 1, NUMSTR
      DO 710 IWK  = 1, NUMWKS
         STVSWK(ISTR, IWK) = STINWK(ISTR, IWK)
710   CONTINUE
700   CONTINUE

C  <close workstation> acwkid(1) and note in stvswk
      CALL PCLWK (ACWKID(1))
      DO 750 ISTR = 1, NUMSTR
         STVSWK(ISTR, 1) = -1
750   CONTINUE

      CALL SETMSG ('12 13', '<Close workstation> should remove the '  //
     1             'workstation identifier from the list of '         //
     2             'workstations to which posted in all the '         //
     3             'structure state lists.')
      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL IFPF (LWPCOD)

C  *** *** *** *** ***   Re-opening  workstation   *** *** *** *** ***

      CALL POPWK (ACWKID(1), OCONID(1), OWTYPE(1))

      CALL CHKPST (NUMSTR, STRID, NUMWKS, ACWKID, STVSWK,
     1             LWPCOD, LPSCOD)
      CALL SETMSG ('11 14', 'Immediately after re-opening a '         //
     1             'workstation, its list of posted structures '      //
     2             'should be empty.')
      CALL IFPF (LPSCOD)

      CALL SETMSG ('11 13', 'Immediately after re-opening a '        //
     1             'workstation, no list of workstations to which '  //
     2             'posted should contain it.')
      CALL IFPF (LWPCOD)

C  <close structure>
      CALL PCLST

C  close all workstations
      DO 800 IWK = 1,NUMWKS
         CALL PCLWK (ACWKID(IWK))
800   CONTINUE

666   CONTINUE
      CALL ENDIT
      END
