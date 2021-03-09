C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/05                        *
C  *    TEST TITLE : WSL interior bundles initialized      *
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

      INTEGER   NPE, II, SIBT, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5
      INTEGER   IDUM6, IDUM7, DIN, PDIN, DSI, PDSI, DCI, PDCI,
     1          NEWENT, MINBTE

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      CHARACTER MSG*300, MSGSUF*30

      CALL INITGL ('04.02.05.02/05')

      MSGSUF = 'opening workstation.'

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  perform loop twice - once for open, once for re-open
50    CONTINUE
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  npe = number of predefined entries in WDT
      CALL PQIF (SPECWT, 0, 0, ERRIND, IDUM1, IDUM2, IDUM3,
     1            IDUM4, NPE)
      CALL CHKINQ ('pqif', ERRIND)
C   sibt = size of WSL interior bundle table
      CALL PQEII (WKID, 0, ERRIND, SIBT, IDUM1)
      CALL CHKINQ ('pqeii', ERRIND)

      CALL SETMSG ('25 26', 'WSL interior bundle table should be ' //
     1             'the same size as the predefined interior '     //
     2             'bundle table after ' // MSGSUF)
      IF (SIBT .NE. NPE) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'PHIGS reported ', NPE,
     1          ' WDT predefined interior bundles, but ', SIBT,
     2          ' WSL interior bundles.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('21 24 25', 'Each WSL interior entry should have '//
     1             'the same attributes as the corresponding '       //
     2             'predefined interior entry after ' // MSGSUF)
      DO 100 II = 1, MIN(NPE,SIBT)
C  pdin = predefined interior style
C  pdsi = predefined interior style index
C  pdci   = predefined interior color index
         CALL PQPIR (SPECWT, II, ERRIND, PDIN, PDSI, PDCI)
         CALL CHKINQ ('pqpir', ERRIND)
C  inquire defined attributes, as set
C  din = defined interior style
C  dsi = defined interior style index
C  dci = defined interior color index
C    inquire as SET
         CALL PQIR (WKID, II, PSET, ERRIND, DIN, DSI, DCI)
         CALL CHKINQ ('pqir', ERRIND)

         IF (DIN .EQ. PDIN  .AND.
     1       DSI .EQ. PDSI  .AND.
     3       DCI .EQ. PDCI) THEN
C  OK so far - do nothing
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I5,A,A)') 'WSL interior bundle #', II,
     1             ' is not initialized from corresponding WDT ',
     2             'predefined bundle.'
            CALL INMSG (MSG)
            GOTO 110
         ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE

C now alter bundle table - either add entry or change it

C maximum number of interior bundle table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3, MINBTE,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MINBTE .GT. SIBT) THEN
C room for additional entries
         NEWENT = SIBT+1
      ELSE
         NEWENT = SIBT
      ENDIF
      CALL PSIR (WKID, NEWENT, 0, 1, 87)

C close workstation
      CALL PCLWK (WKID)

C check if this is 2nd time thru
      IF (MSGSUF .EQ. 'opening workstation.') THEN
C this is first time thru
         MSGSUF = 're-opening workstation.'
         GOTO 50
      ENDIF

666   CONTINUE
      CALL ENDIT
      END
