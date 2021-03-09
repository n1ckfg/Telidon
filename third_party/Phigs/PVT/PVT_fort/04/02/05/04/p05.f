C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.04/05                        *
C  *    TEST TITLE : WSL pattern table initialized         *
C  *                 properly                              *
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

C set up pattern color array index values
      INTEGER    DIMX, DIMY, DDX, DDY, PDDX, PDDY
      PARAMETER  (DIMX = 100, DIMY = 100)
      INTEGER    PDCIA(DIMX, DIMY), DCIA(DIMX, DIMY)
      INTEGER    NPE, SPT, II, NEWENT, MPAI
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

      LOGICAL    ARREQ

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300, MSGSUF*30

      LOGICAL   PATMAT, PATAVL

      CALL INITGL ('04.02.05.04/05')

      MSGSUF = 'opening workstation.'

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  perform loop twice - once for open, once for re-open
50    CONTINUE
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      IF (.NOT. PATAVL(SPECWT)) THEN
         CALL INMSG ('Skipping all tests because pattern interior ' //
     1               'style is not supported on this workstation.')
         GOTO 666
      ENDIF

C  npe = number of predefined entries in WDT
      CALL PQPAF (SPECWT, ERRIND, NPE)
      CALL CHKINQ ('pqpaf', ERRIND)
C   spt = size of WSL interior bundle table
      CALL PQEPAI (WKID, 0, ERRIND, SPT, IDUM1)
      CALL CHKINQ ('pqepai', ERRIND)

      CALL SETMSG ('16 17', 'WSL pattern table should be the same '  //
     1             'size as the WDT predefined pattern table after ' //
     2             MSGSUF)
      IF (SPT .EQ. NPE) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'PHIGS reported ', NPE,
     1          ' WDT predefined pattern indices, but ', SPT,
     2          ' WSL pattern indices.'
         CALL INMSG (MSG)
      ENDIF

C patterns match so far
      PATMAT = .TRUE.

      DO 100 II = 1, MIN(NPE,SPT)

C  pdcia = predefined pattern color index array
C  pddx  = predefined dx -pattern array dimension
C  pddy  = predefined dy -pattern array dimension
         CALL PQPPAR (SPECWT, II, DIMX, DIMY, ERRIND, PDDX, PDDY, PDCIA)
         IF (ERRIND .EQ. 2001) THEN
            WRITE (MSG, '(A,A,2I5,A)') 'PQPPAR returned Fortran error ',
     1             '2001: declared array size of (', DIMX, DIMY,
     2             ') insufficient.'
            CALL INMSG (MSG)
            GOTO 666
         ENDIF
         CALL CHKINQ ('pqppar', ERRIND)

C  inquire defined attributes, as set
C  dcia = defined pattern color index array
C  ddx  = defined dx -pattern array dimension
C  ddy  = defined dy -pattern array dimension
C    inquire as SET
         CALL PQPAR (WKID, II, PSET, DIMX, DIMY, ERRIND, DDX, DDY, DCIA)
         IF (ERRIND .EQ. 2001) THEN
            WRITE (MSG, '(A,A,2I5,A)') 'PQPAR returned Fortran error ',
     1             '2001: declared array size of (', DIMX, DIMY,
     2             ') insufficient.'
            CALL INMSG (MSG)
            GOTO 666
         ENDIF
         CALL CHKINQ ('pqpar', ERRIND)

         IF (DDX .EQ. PDDX  .AND.
     1       DDY .EQ. PDDY  .AND.
     3       ARREQ (DIMX, DIMY, 1,1, DDX, DDY, DCIA, PDCIA)) THEN
C  OK so far - do nothing
         ELSE
            WRITE (MSG, '(A,I5,A,A)') 'WSL pattern index #', II,
     1             ' is not initialized from corresponding WDT ',
     2             'predefined index.'
            CALL INMSG (MSG)
            PATMAT = .FALSE.
            GOTO 110
         ENDIF
100   CONTINUE
110   CONTINUE

      CALL SETMSG ('11 15 16', 'Each WSL pattern table entry should ' //
     1             'have the same attributes as the corresponding '   //
     2             'predefined pattern table entry after ' // MSGSUF)
      CALL IFPF (PATMAT)

C now alter table - either add entry or change it

C maximum number of pattern table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, MPAI, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MPAI .GT. SPT) THEN
C room for additional entries
         NEWENT = SPT+1
      ELSE
         NEWENT = SPT
      ENDIF
C set up new pattern
      DCIA (5,5) = 11
      DCIA (6,5) = 21
      DCIA (7,5) = 31
      DCIA (5,6) = 41
      DCIA (6,6) = 41
      DCIA (7,6) = 51
      CALL PSPAR (WKID, NEWENT, DIMX, DIMY, 5, 5, 3, 2, DCIA)

C check if this is 2nd time thru
      IF (MSGSUF .EQ. 'opening workstation.') THEN
C this is first time thru
C close workstation and change msg
         CALL PCLWK (WKID)
         MSGSUF = 're-opening workstation.'
         GOTO 50
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
