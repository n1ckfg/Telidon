C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.01.02/05                        *
C  *    TEST TITLE : WSL polyline bundles initialized      *
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

      INTEGER   IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7
      INTEGER   DLT, PDLT, DCI, PDCI, MPLBTE, NPE, PLI, SPBT, NEWENT

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, DLW, PDLW

      CHARACTER MSG*300, MSGSUF*30

      CALL INITGL ('04.02.01.02/05')

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
      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1, IDUM2, IDUM3,
     1            RDUM1, RDUM2, RDUM3, NPE)
      CALL CHKINQ ('pqplf', ERRIND)
C   spbt = size of WSL polyline bundle table
      CALL PQEPLI (WKID, 0, ERRIND, SPBT, IDUM1)
      CALL CHKINQ ('pqepli', ERRIND)

      CALL SETMSG ('24 25', 'WSL polyline bundle table should be ' //
     1             'the same size as the predefined polyline '    //
     2             'bundle table after ' // MSGSUF)

      IF (SPBT .NE. NPE) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'PHIGS reported ', NPE,
     1         ' WDT predefined polyline bundles, but ', SPBT,
     2         ' WSL polyline bundles.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 23 24', 'Each WSL polyline entry should ' //
     1             'have the same attributes as the corresponding '//
     2             'predefined polyline entry after ' // MSGSUF)

      DO 100 PLI = 1, MIN(NPE, SPBT)
C  pdlt = predefined linetype
C  pdlw = predefined linewidth scale factor
C  pdci = predefined polyline color index
         CALL PQPPLR (SPECWT, PLI, ERRIND, PDLT, PDLW, PDCI)
         CALL CHKINQ ('pqpplr', ERRIND)
C  inquire defined attributes, as set
C  dlt = defined linetype
C  dlw = defined linewidth scale factor
C  dci = defined polyline color index
C    inquire as SET
         CALL PQPLR (WKID, PLI, 0, ERRIND, DLT, DLW, DCI)
         CALL CHKINQ ('pqplr', ERRIND)

         IF (DLT .EQ. PDLT .AND.
     1       DLW .EQ. PDLW .AND.
     2       DCI .EQ. PDCI)    THEN
C  OK so far - do nothing
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'WSL polyline bundle #', PLI,
     1        ' is not initialized from corresponding WDT ' //
     2        'predefined bundle.'
            CALL INMSG (MSG)
            GOTO 110
        ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE

C now alter bundle table - either add entry or change it

C maximum number of polyline bundle table entries
      CALL PQWKSL (SPECWT, ERRIND, MPLBTE, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MPLBTE .GT. SPBT) THEN
C room for additional entries
         NEWENT = SPBT+1
      ELSE
         NEWENT = SPBT
      ENDIF
      CALL PSPLR (WKID, NEWENT, 1, 37.89, 87)

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
