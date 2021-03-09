C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/03                        *
C  *    TEST TITLE : WSL colour table initialized          *
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

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)
C NOTE:  INTEGER rather than enumeration type.  Explicitly defined and
C required portion of conceptually unbounded range defined here.

C colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC=0, PCOLOR=1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   SPECWT,SPECON, NPE,SCT, CI, NEWENT, MCOLI, NPREDF,NINIT
      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7

      REAL      DCS(6), PDCS(6), RDUM(9), RNDRL

      LOGICAL   RAREQ

      CHARACTER MSG*300, MSGSUF*30

      CALL INITGL ('04.03.02.02/03')

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
      CALL PQCF (SPECWT, ERRIND, IDUM1, IDUM2, NPE, RDUM)
      CALL CHKINQ ('pqcf', ERRIND)
C   sct = size of WSL colour table
      CALL PQECI (WKID, 0, ERRIND, SCT, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)

      CALL SETMSG ('13 14', 'WSL colour table should be the '  //
     1             'same size as the predefined colour table ' //
     2             'after ' // MSGSUF)
      IF (SCT .NE. NPE) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'PHIGS reported ', NPE,
     1          ' WDT predefined colour indices, but ', SCT,
     2          ' WSL colour indices.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('9 10 13', 'Each WSL colour index should have the '//
     1             'same color specification as the corresponding '   //
     2             'predefined colour index after ' // MSGSUF)
      DO 100 CI = 0, MIN(NPE,SCT)-1
C  pdcs(1-3) = predefined colour specification parameters
         CALL PQPCR (SPECWT, CI, 6, ERRIND, NPREDF, PDCS)
         CALL CHKINQ ('pqpcr', ERRIND)
C  inquire defined attributes, as set
C  dcs(1-3)  = defined colour specification parameters
C  inquire as SET
         CALL PQCR (WKID, CI, 6, PSET, ERRIND, NINIT, DCS)
         CALL CHKINQ ('pqcr', ERRIND)
         IF (NPREDF .EQ. NINIT  .AND.
     1       RAREQ (NPREDF, DCS,PDCS, 0.0, 0.0)) THEN
C  OK so far - do nothing
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I5,A,A)') 'WSL colour index #', CI,
     1             ' is not initialized from corresponding WDT ',
     2             'predefined index.'
            CALL INMSG (MSG)
            GOTO 110
         ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE

C now alter colour table - either add entry or change it

C maximum number of colour bundle table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, MCOLI, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MCOLI .GT. SCT) THEN
C room for additional entries
         NEWENT = SCT
      ELSE
         NEWENT = SCT-1
      ENDIF
      DO 300 CI = 1,NINIT
         DCS(CI) = RNDRL(0.1,0.9)
300   CONTINUE
      CALL PSCR (WKID, NEWENT, NINIT, DCS)

C close workstation
      CALL PCLWK (WKID)

C check if this is 2nd time thru
      IF (MSGSUF .EQ. 'opening workstation.') THEN
C this is first time thru
         MSGSUF = 're-opening workstation.'
         GOTO 50
      ENDIF

666   CONTINUE
C close PHIGS
      CALL ENDIT
      END
