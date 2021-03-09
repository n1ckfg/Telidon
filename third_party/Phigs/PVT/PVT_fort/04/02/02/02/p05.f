C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.02.02/05                        *
C  *    TEST TITLE : WSL polymarker bundles initialized    *
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

      INTEGER   NPE, PMI, SPBT, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5
      INTEGER   DMT, PDMT, DCI, PDCI, NEWENT, MPMBTE, IDUM6, IDUM7

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, DMS, PDMS

      CHARACTER MSG*300, MSGSUF*30

      CALL INITGL ('04.02.02.02/05')

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
      CALL PQPMF (SPECWT, 1, ERRIND, IDUM1, IDUM2, IDUM3,
     1            RDUM1, RDUM2, RDUM3, NPE)
      CALL CHKINQ ('pqpmf', ERRIND)
C   spbt = size of WSL polymarker bundle table
      CALL PQEPMI (WKID, 1, ERRIND, SPBT, IDUM1)
      CALL CHKINQ ('pqepmi', ERRIND)

      CALL SETMSG ('24 25', 'WSL polymarker bundle table should be ' //
     1             'the same size as the predefined polymarker '     //
     2             'bundle table after ' // MSGSUF)
      IF (SPBT .NE. NPE) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'PHIGS reported ', NPE,
     1         ' WDT predefined polymarker bundles, but ', SPBT,
     2         ' WSL polymarker bundles.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 23 24', 'Each WSL polymarker entry should '  //
     1             'have the same attributes as the corresponding ' //
     2             'predefined polymarker entry after ' // MSGSUF)

      DO 100 PMI = 1, MIN(NPE,SPBT)
C  pdmt = predefined marker type
C  pdms = predefined marker size scale factor
C  pdci = predefined polymarker color index
         CALL PQPPMR (SPECWT, PMI, ERRIND, PDMT, PDMS, PDCI)
         CALL CHKINQ ('pqppmr', ERRIND)
C inquire defined attributes, as set
C  dmt = defined marker type
C  dms = defined marker size scale factor
C  dci = defined polymarker color index
C   inquire as SET
         CALL PQPMR (WKID, PMI, PSET, ERRIND, DMT, DMS, DCI)
         CALL CHKINQ ('pqpmr', ERRIND)

         IF (DMT .EQ. PDMT .AND.
     1       DMS .EQ. PDMS .AND.
     2       DCI .EQ. PDCI)    THEN
C  OK so far - do nothing
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'WSL polymarker bundle #', PMI,
     1        ' is not initialized from corresponding WDT ' //
     2        'predefined bundle.'
            CALL INMSG (MSG)
            GOTO 110
        ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE

C now alter bundle table - either add entry or change it

C maximum number of polymarker bundle table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, MPMBTE, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MPMBTE .GT. SPBT) THEN
C room for additional entries
         NEWENT = SPBT+1
         CALL PSPMR (WKID, NEWENT, 1, 37.89, 87)
      ENDIF
      NEWENT = SPBT
      CALL PSPMR (WKID, NEWENT, 2, 17.89, 27)

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
