C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/03                        *
C  *    TEST TITLE : Interior bundle table length          *
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

      INTEGER   MIBE, NDE, MII, NEMP, II, N
      INTEGER   MINBTE, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300

      CALL INITGL ('04.02.05.02/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, MINBTE,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C maximum number of interior bundle table entries
      MIBE = MINBTE

C  nde  = number of defined entries
C  mii = maximum defined interior index
C  nemp = number of empty entries

      CALL SETMSG ('18 19', '<Inquire workstation state table '     //
     1             'lengths> should report at least 20 entries as ' //
     2             'maximum size of interior bundle table.')

      CALL IFPF (MIBE .GE. 20)

      CALL PQEII (WKID, 0, ERRIND, NDE, IDUM1)
      CALL CHKINQ ('pqeii', ERRIND)
      MII = -9999
      DO 100 N = 1, NDE
         CALL PQEII (WKID, N, ERRIND, IDUM1, II)
         CALL CHKINQ ('pqeii', ERRIND)
         IF (II .GT. MII) MII = II
100   CONTINUE

      NEMP = MIBE - NDE

      CALL SETMSG ('18', 'The program should be able to define ' //
     1             'additional interior bundle entries, up to '  //
     2             'the maximum.')
C  set new entries
      CALL ERRCTL (.TRUE.)
      DO 150 II = MII+1, MII+NEMP
         CALL PSIR (WKID, II, PHOLLO, 1, 1)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I6,A)')
     1      'Unable to fill interior bundle slot #', NDE+II-MII,'.'
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
