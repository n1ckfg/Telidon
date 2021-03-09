C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/03                        *
C  *    TEST TITLE : Edge bundle table length              *
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

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

      INTEGER   MEBE, NDE, MDEI, NEMP, EDI, N
      INTEGER   MEDBTE, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.03/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, MEDBTE, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of edge bundle table entries
      MEBE = MEDBTE

      CALL SETMSG ('17 18', '<Inquire workstation state table '  //
     1             'lengths> should report at least 20 entries ' //
     2             'as maximum size of edge bundle table.')

      CALL IFPF (MEBE .GE. 20)

C  nde  = number of defined entries
C  mdei = maximum defined edge index
C  nemp = number of empty entries
      CALL PQEEDI (WKID, 0, ERRIND, NDE, IDUM1)
      CALL CHKINQ ('pqeedi', ERRIND)
      MDEI = -9999
      DO 100 N = 1, NDE
         CALL PQEEDI (WKID, N, ERRIND, IDUM1, EDI)
         CALL CHKINQ ('pqeedi', ERRIND)
         IF (EDI .GT. MDEI) MDEI = EDI
100   CONTINUE

      NEMP = MEBE - NDE
      CALL SETMSG ('17', 'The program should be able to define ' //
     1             'additional edge bundle entries, up to the '  //
     2             'maximum.')

C  set new entries
      CALL ERRCTL (.TRUE.)
      DO 150 EDI = MDEI+1, MDEI+NEMP
         CALL PSEDR (WKID, EDI, PON, 1, 1.0, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I6,A)')
     1      'Unable to fill edge bundle slot #', NDE+EDI-MDEI, '.'
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
