C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.02/05                        *
C  *    TEST TITLE : WSL text bundles initialized          *
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

      INTEGER   NPE, TXI, STBT, IDUM1, IDUM2, IDUM3, IDUM4, IDUM5,
     1          IDUM6, IDUM7
      INTEGER   DFN, PDFN, DPR, PDPR, DCI, PDCI, NEWENT, MTXBTE
      INTEGER    PSET
      PARAMETER (PSET=0)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, RDUM4
      REAL      DXP, PDXP, DSP, PDSP

      CHARACTER MSG*300, MSGSUF*30

      CALL INITGL ('04.02.03.02/05')

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
      CALL PQTXF (SPECWT, 1, ERRIND, IDUM1, IDUM2, IDUM3,
     1            IDUM4, RDUM1, RDUM2, IDUM5, RDUM3, RDUM4,
     2            NPE)
      CALL CHKINQ ('pqtxf', ERRIND)
C   stbt = size of WSL text bundle table
      CALL PQETXI (WKID, 0, ERRIND, STBT, IDUM1)
      CALL CHKINQ ('pqetxi', ERRIND)

      CALL SETMSG ('24 25', 'WSL text bundle table should be ' //
     1             'the same size as the predefined text '     //
     2             'bundle table after ' // MSGSUF)
      IF (STBT .NE. NPE) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'PHIGS reported ', NPE,
     1          ' WDT predefined text bundles, but ', STBT,
     2          ' WSL text bundles.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 23 24', 'Each WSL text entry should have ' //
     1             'the same attributes as the corresponding '    //
     2             'predefined text entry after ' // MSGSUF)
      DO 100 TXI = 1, MIN(NPE,STBT)
C  pdfn = predefined font
C  pdpr = predefined precision
C  pdxp = predefined character expansion factor
C  pdsp = predefined character spacing
C  pdci = predefined text color index
         CALL PQPTXR (SPECWT, TXI, ERRIND, PDFN, PDPR, PDXP,
     1                PDSP, PDCI)
         CALL CHKINQ ('pqptxr', ERRIND)
C  inquire defined attributes, as set
C  dfn = defined font
C  dpr = defined precision
C  dxp = defined character expansion factor
C  dsp = defined character spacing
C  dci = defined text color index
C    inquire as SET
         CALL PQTXR (WKID, TXI, PSET, ERRIND, DFN, DPR, DXP,
     1               DSP, DCI)
         CALL CHKINQ ('pqtxr', ERRIND)

         IF (DFN .EQ. PDFN .AND.
     1       DPR .EQ. PDPR .AND.
     2       DXP .EQ. PDXP .AND.
     3       DSP .EQ. PDSP .AND.
     4       DCI .EQ. PDCI)    THEN
C  OK so far - do nothing
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I5,A,A)') 'WSL text bundle #', TXI,
     1             ' is not initialized from corresponding WDT ',
     2             'predefined bundle.'
            CALL INMSG (MSG)
            GOTO 110
        ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE

C now alter bundle table - either add entry or change it

C maximum number of text bundle table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, MTXBTE, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MTXBTE .GT. STBT) THEN
C room for additional entries
         NEWENT = STBT+1
      ELSE
         NEWENT = STBT
      ENDIF
      CALL PSTXR (WKID, NEWENT, 1, 0, 2.3, 4.5, 87)

C close workstation
      CALL PCLWK (WKID)

C check if this is 2nd time thru
      IF (MSGSUF .EQ. 'opening workstation.') THEN
C this is first time thru
         MSGSUF = 're-opening workstation.'
         GOTO 50
      ENDIF


666   CONTINUE
C wrap it up
      CALL ENDIT
      END

