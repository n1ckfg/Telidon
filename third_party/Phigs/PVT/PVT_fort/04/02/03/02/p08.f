C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/08                        *
C  *    TEST TITLE : Character spacing support             *
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

      INTEGER    PREALI, PSTRP, PCHARP, PSTRKP
      INTEGER    IDUM1, IDUM2, IDUM3
      PARAMETER  (PREALI=1, PSTRP=0, PCHARP=1, PSTRKP=2)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL       SPI, CHSP, RSP, RSP2, RDUM1

      CHARACTER  MSG*300

      CALL INITGL ('04.02.03.02/08')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL SETMSG ('60', 'All character spacing values should be ' //
     1             'accepted as valid.')
      CALL ERRCTL (.TRUE.)
      CHSP = -3.032
      CALL PSTXR (WKID, 3, 1, PSTRP, 1.0, CHSP, 1)
      IF (ERRSIG .NE. 0) GOTO 100
      CHSP = 0.35
      CALL PSTXR (WKID, 4, 1, PSTRP, 1.0, CHSP, 1)
      IF (ERRSIG .NE. 0) GOTO 100
      CHSP = 11.121
      CALL PSTXR (WKID, 5, 1, PSTRP, 1.0, CHSP, 1)
      IF (ERRSIG .NE. 0) GOTO 100
      CALL PASS
      GOTO 150

C  fail and informational message about character spacing
100   CONTINUE
      CALL FAIL
      WRITE (MSG, '(A,F11.2,A,I6,A)') 'Character spacing of ',
     1       CHSP, ' rejected with error code = ', ERRSIG, '.'
      CALL INMSG (MSG)

150   CONTINUE
      CALL ERRCTL (.FALSE.)

      CALL SETMSG ('15 49 50 60', 'For CHAR and STROKE precisions, ' //
     1             'a character spacing value should be realized '   //
     2             'as itself.')
      DO 200 SPI = -1.0, 2.0001, .25
         CALL PSTXR (WKID, 3, 1, PCHARP, 1.0, SPI, 1)
         CALL PQTXR (WKID, 3, PREALI, ERRIND, IDUM1, IDUM2, RDUM1,
     1               RSP, IDUM3)
         CALL CHKINQ ('pqtxr', ERRIND)
C  rsp = realized character spacing
         IF (RSP .NE. SPI) THEN
            CALL FAIL
            GOTO 666
         ENDIF

         CALL PSTXR (WKID, 6, 1, PSTRKP, 1.0, SPI, 1)
         CALL PQTXR (WKID, 6, PREALI, ERRIND, IDUM1, IDUM2, RDUM1,
     1               RSP2, IDUM3)
         CALL CHKINQ ('pqtxr', ERRIND)
         IF (RSP2 .NE. SPI) THEN
            CALL FAIL
            GOTO 666
         ENDIF
200   CONTINUE
      CALL PASS

666   CONTINUE
C wrap it up
      CALL ENDIT
      END

