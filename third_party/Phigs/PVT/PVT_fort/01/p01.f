C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 01/01                                 *
C  *    TEST TITLE : Testing the system state value        *
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

C system state value
      INTEGER    PPHCL,     PPHOP
      PARAMETER (PPHCL = 0, PPHOP = 1)

      INTEGER SYSTRA

      CALL INITGL ('01/01')

C  Use <inquire system state value> to determine:
C      systra = system state value

      CALL SETMSG ('3', '<Inquire system state value> should return ' //
     1             'closed as the system state value before PHIGS '   //
     2             'is opened.')

      SYSTRA = -6
      CALL PQSYS (SYSTRA)
      CALL IFPF (SYSTRA .EQ. PPHCL)

      CALL SETMSG ('1 3', 'After opening PHIGS <inquire system '      //
     1             'state value> should return the system state '     //
     2             'value as open.')

      CALL XPOPPH (ERRFIL, MEMUN)
      CALL PQSYS (SYSTRA)
      CALL IFPF (SYSTRA .EQ. PPHOP)

      CALL SETMSG ('2 3', 'After closing PHIGS <inquire system '      //
     1             'state value> should return the system state '     //
     2             'value as closed.')

      CALL PCLPH
      CALL PQSYS (SYSTRA)
      CALL IFPF (SYSTRA .EQ. PPHCL)

      CALL SETMSG ('1 3', 'After reopening PHIGS <inquire system '    //
     1             'state value> should return the system state '     //
     2             'value as open.')

      CALL XPOPPH (ERRFIL, MEMUN)
      CALL PQSYS (SYSTRA)
      CALL IFPF (SYSTRA .EQ. PPHOP)

666   CONTINUE
C close PHIGS
      CALL PCLPH
      CALL WINDUP
      END
