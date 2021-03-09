C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.03/05                        *
C  *    TEST TITLE : WSL edge bundles initialized          *
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

      INTEGER   NPE, EDI, SEBT, IDUM1, IDUM2, IDUM3
      INTEGER   IDUM4, IDUM5, IDUM6, IDUM7, NEWENT, MEDBTE

C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      INTEGER   DEF, DET, PDEF, PDET, DCI, PDCI
C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      REAL      RDUM1, RDUM2, RDUM3, DEW, PDEW

      CHARACTER MSG*300, MSGSUF*30

      CALL INITGL ('04.02.05.03/05')

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
      CALL PQEDF (SPECWT, 1, ERRIND, IDUM1, IDUM2, IDUM3,
     1            RDUM1, RDUM2, RDUM3, NPE)
      CALL CHKINQ ('pqedf', ERRIND)
C   sebt = size of WSL edge bundle table
      CALL PQEEDI (WKID, 0, ERRIND, SEBT, IDUM1)
      CALL CHKINQ ('pqeedi', ERRIND)

      CALL SETMSG ('24 25', 'WSL edge bundle table should be the '  //
     1             'same size as the predefined edge bundle table ' //
     2             'after ' // MSGSUF)

      IF (SEBT .NE. NPE) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)') 'PHIGS reported ', NPE,
     1          ' WDT predefined edge bundles, but ', SEBT,
     2          ' WSL edge bundles.'
         CALL INMSG (MSG)
      ELSE
         CALL PASS
      ENDIF

      CALL SETMSG ('20 23 24', 'Each WSL edge entry should have ' //
     1             'the same attributes as the corresponding '    //
     2             'predefined edge entry after ' // MSGSUF)

      DO 100 EDI = 1, MIN(NPE, SEBT)
C  pdef = predefined edge flag
C  pdet = predefined edgetype
C  pdew = predefined edgewidth scale factor
C  pdci = predefined edge color index
         CALL PQPEDR (SPECWT, EDI, ERRIND, PDEF, PDET, PDEW, PDCI)
         CALL CHKINQ ('pqpedr', ERRIND)
C  inquire defined attributes, as set
C  def = defined edge flag
C  det = defined edgetype
C  dew = defined edgewidth scale factor
C  dci = defined edge color index
C    inquire as SET
         CALL PQEDR (WKID, EDI, PSET, ERRIND, DEF, DET, DEW, DCI)
         CALL CHKINQ ('pqedr', ERRIND)

         IF (DEF .EQ. PDEF .AND.
     1       DET .EQ. PDET .AND.
     2       DEW .EQ. PDEW .AND.
     3       DCI .EQ. PDCI)    THEN
C  OK so far - do nothing
         ELSE
            CALL FAIL
            WRITE (MSG, '(A,I5,A)') 'WSL edge bundle #', EDI,
     1             ' is not initialized from corresponding WDT ',
     2             'predefined bundle.'
            CALL INMSG (MSG)
            GOTO 110
        ENDIF
100   CONTINUE
      CALL PASS
110   CONTINUE

C now alter bundle table - either add entry or change it

C maximum number of edge bundle table entries
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, MEDBTE, IDUM5, IDUM6, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MEDBTE .GT. SEBT) THEN
C room for additional entries
         NEWENT = SEBT+1
      ELSE
         NEWENT = SEBT
      ENDIF
      CALL PSEDR (WKID, NEWENT, 0, 1, 2.3, 87)

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
