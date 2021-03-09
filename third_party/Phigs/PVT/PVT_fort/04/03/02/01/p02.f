C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.01/02                        *
C  *    TEST TITLE : Colour table length                   *
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

      INTEGER   MCTE, NDE, MDCI, NEMP, CI, COLI
      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)
C NOTE:  INTEGER rather than enumeration type.  Explicitly defined and
C required portion of conceptually unbounded range defined here.

      INTEGER    PSET,   PREALI
      PARAMETER (PSET=0, PREALI=1)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300

      REAL      COLSPC(3)
      DATA      COLSPC / 1.0, 1.0, 1.0 /

      CALL INITGL ('04.03.02.01/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C set colour model RGB
C This statement is necessary to give meaningful value to the
C colour specifications used in <set colour representation>.
      CALL PSCMD (WKID, PRGB)

C mcte = maximum number of colour table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1             IDUM5, IDUM6, MCTE, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

C  nde  = number of defined entries
C  mdci = maximum defined colour index
C  nemp = number of empty entries

      CALL SETMSG ('7 8', '<Inquire workstation state table '       //
     1             'lengths> should report at least 2 entries as '  //
     2             'maximum size of colour table.')

      CALL IFPF (MCTE .GE. 2)

      CALL PQECI(WKID, 0, ERRIND, NDE, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      MDCI = -9999
      DO 100 CI = 1, NDE
         CALL PQECI (WKID, CI, ERRIND, IDUM1, COLI)
         CALL CHKINQ ('pqeci', ERRIND)
         IF (COLI .GT. MDCI) MDCI = COLI
100   CONTINUE
      NEMP = MCTE - NDE

      CALL SETMSG ('7', 'The program should be able to define '  //
     1             'additional colour table entries, up to the ' //
     2             'maximum.')
C  set new entries
      CALL ERRCTL (.TRUE.)
      DO 250 COLI = MDCI+1, MDCI+NEMP
         CALL PSCR (WKID, COLI, 3, COLSPC)
         IF (ERRSIG .NE. 0) THEN
            CALL FAIL
            WRITE (MSG, '(A,I6,A)')
     1             'Unable to fill colour table slot #',
     2             NDE+COLI-MDCI,'.'
            CALL INMSG (MSG)
            GOTO 300
         ENDIF
250   CONTINUE
      CALL PASS

300   CONTINUE
      CALL ERRCTL (.FALSE.)

666   CONTINUE
C wrap it up
      CALL ENDIT
      END
