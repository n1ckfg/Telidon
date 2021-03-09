C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/03                        *
C  *    TEST TITLE : Polymarker bundle table length        *
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

      INTEGER   MPBE, NDE, MPMI, NEMP, PMI, N
      INTEGER   MPMBTE, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300

      CALL INITGL ('04.02.02.02/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1, MPMBTE, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of polymarker bundle table entries
      MPBE = MPMBTE

      CALL SETMSG ('17 18', '<Inquire workstation state table '     //
     1             'lengths> should report at least 20 entries as ' //
     2             'maximum size of polymarker bundle table.')
      CALL IFPF (MPBE .GE. 20)

      CALL PQEPMI (WKID, 1, ERRIND, NDE, IDUM1)
      CALL CHKINQ ('pqepmi', ERRIND)
      MPMI = -9999
      DO 100 N = 1, NDE
         CALL PQEPMI (WKID, N, ERRIND, IDUM1, PMI)
         CALL CHKINQ ('pqepmi', ERRIND)
         IF (PMI .GT. MPMI) MPMI = PMI
100   CONTINUE

      NEMP = MPBE - NDE

C  nde  = number of defined entries
C  mpmi = maximum defined polymarker index
C  nemp = number of empty entries

      CALL SETMSG ('17', 'The program should be able to define ' //
     1             'additional polymarker bundle entries, up '   //
     2             'to the maximum.')
C  set new entries
      CALL ERRCTL (.TRUE.)
      DO 150 PMI = MPMI+1, MPMI+NEMP
         CALL PSPMR (WKID, PMI, 1, 1.0, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I6,A)')
     1      'Unable to fill polymarker bundle slot #', NDE+PMI-MPMI, '.'
            CALL INMSG (MSG)
            GOTO 200
         ENDIF
150   CONTINUE
      CALL PASS

200   CONTINUE
      CALL ERRCTL (.FALSE.)

666   CONTINUE
      CALL ENDIT
      END
