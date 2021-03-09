C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/03                        *
C  *    TEST TITLE : Text bundle table length              *
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

      INTEGER   MTBE, NDE, MTXI, NEMP, TXI, N
      INTEGER   MTXBTE, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300

      CALL INITGL ('04.02.03.02/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, MTXBTE, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of text bundle table entries
      MTBE = MTXBTE

      CALL SETMSG ('17 18', '<Inquire workstation state table '     //
     1             'lengths> should report at least 20 entries as ' //
     2             'maximum size of text bundle table.')

      CALL IFPF (MTBE .GE. 20)

      CALL PQETXI (WKID, 0, ERRIND, NDE, IDUM1)
      CALL CHKINQ ('pqetxi', ERRIND)
      MTXI = -9999
      DO 100 N = 1, NDE
         CALL PQETXI (WKID, N, ERRIND, IDUM1, TXI)
         CALL CHKINQ ('pqetxi', ERRIND)
         IF (TXI .GT. MTXI) MTXI = TXI
100   CONTINUE

      NEMP = MTBE - NDE

C  nde  = number of defined entries
C  mtxi = maximum defined text index
C  nemp = number of empty entries

      CALL SETMSG ('17', 'The program should be able to define ' //
     1             'additional text bundle entries, up to the '  //
     2             'maximum.')
C  set new entries
      CALL ERRCTL (.TRUE.)
      DO 150 TXI = MTXI+1, MTXI+NEMP
         CALL PSTXR (WKID, TXI, 1, 0, 1.0, 0.0, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I6,A)')
     1      'Unable to fill text bundle slot #', NDE+TXI-MTXI, '.'
            CALL INMSG (MSG)
            GOTO 200
         ENDIF
150   CONTINUE
      CALL PASS

200   CONTINUE
      CALL ERRCTL (.FALSE.)

666   CONTINUE
C wrap it up
      CALL ENDIT
      END
