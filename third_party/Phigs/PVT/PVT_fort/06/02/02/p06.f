C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.02/06                           *
C  *    TEST TITLE : Update control of view table          *
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
 
C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C Current and Requested values.
      INTEGER    PCURVL,     PRQSVL
      PARAMETER (PCURVL = 0, PRQSVL = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND = 1)
C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)
C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
 
      INTEGER    TESTVW, VWTUPD, ROW, COL, IX, SVR, IVW, NDVI, NWVAL
      INTEGER    IDUM1, IDUM2, IDUM3
 
      LOGICAL    RAREQ, IAREQ
 
      REAL       ORVOM(4,4), OCVOM(4,4), CUVOM(4,4), NWVOM(4,4)
      REAL       ORVMM(4,4), OCVMM(4,4), CUVMM(4,4), NWVMM(4,4)
      REAL       ORVCLM(6),  OCVCLM(6),  CUVCLM(6),  NWVCLM(6)
      INTEGER    ORVCID(3),  OCVCID(3),  CUVCID(3),  NWVCID(3)
 
      CALL INITGL ('06.02.02/06')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
 
C  <Inquire list of view indices> to determine
C     ndvi = number of defined indices in the view table
      CALL PQEVWI (WKID, 0, ERRIND, NDVI, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
 
C  <Set display update state> to WAIT, NIVE to try to defer updates
      CALL PSDUS (WKID, PWAITD, PNIVE)
 
      TESTVW = NDVI/2
 
C  <inquire view representation> on testvw to determine original
C     requested and current state:
C     orvom(4,4) = orientation matrix
C     orvmm(4,4) = mapping matrix
C     orvclm(6)  = view clipping limits
C     orvcid(3)  = clipping indicators
C
C     ocvom(4,4) = orientation matrix
C     ocvmm(4,4) = mapping matrix
C     ocvclm(6)  = view clipping limits
C     ocvcid(3)  = clipping indicators
 
      CALL PQVWR (WKID, TESTVW, PRQSVL, ERRIND, VWTUPD,
     1            ORVOM,ORVMM,ORVCLM,ORVCID(1),ORVCID(2),ORVCID(3) )
      CALL CHKINQ ('pqvwr', ERRIND)
      CALL PQVWR (WKID, TESTVW, PCURVL, ERRIND, VWTUPD,
     1            OCVOM,OCVMM,OCVCLM,OCVCID(1),OCVCID(2),OCVCID(3) )
      CALL CHKINQ ('pqvwr', ERRIND)
 
C  generate different values:
C  nwvom  = orvom elements + 1.0
C  nwvmm  = orvmm elements + 1.0
      DO 100 ROW = 1,4
      DO 110 COL = 1,4
         NWVOM (ROW,COL) = ORVOM (ROW,COL) + 1.0
         NWVMM (ROW,COL) = ORVMM (ROW,COL) + 1.0
110   CONTINUE
100   CONTINUE
 
      DO 120 IX = 1,6
         NWVCLM (IX) = ORVCLM (IX) / 2 + 0.1
120   CONTINUE
      IF (ORVCID(1) .EQ. PCLIP) THEN
         NWVAL = PNCLIP
      ELSE
         NWVAL = PCLIP
      ENDIF
 
      DO 130 IX = 1,3
         NWVCID (IX) = NWVAL
130   CONTINUE
 
C  <set view representation 3> on testvw with
C     nwvom, nwvmm, nwvclm, nwvcid
      CALL PSVWR3 (WKID, TESTVW, NWVOM,NWVMM,NWVCLM,
     1             NWVCID(1),NWVCID(2),NWVCID(3) )
 
C  <inquire view representation> on testvw to determine new
C     current state:
C     vwtupd     = view transformation update state
C     cuvom(4,4) = current orientation matrix
C     cuvmm(4,4) = current mapping matrix
C     cuvclm(6)  = current view clipping limits
C     cuvcid(3)  = current clipping indicators
      CALL PQVWR (WKID, TESTVW, PCURVL, ERRIND, VWTUPD,
     1            CUVOM,CUVMM,CUVCLM,CUVCID(1),CUVCID(2),CUVCID(3) )
      CALL CHKINQ ('pqvwr', ERRIND)
 
      CALL SETMSG ('24', 'The view transformation update state '      //
     1             'returned by <inquire view representation> '       //
     2             'should be either PENDING or NOTPENDING.')
      IF (VWTUPD .EQ. PNPEND) THEN
         CALL PASS
         CALL INMSG ('Skipping PENDING test.')
         GOTO 300
      ELSEIF (VWTUPD .EQ. PPEND) THEN
         CALL PASS
      ELSE
         CALL FAIL
         GOTO 300
      ENDIF
 
C  pending_test:
      CALL SETMSG ('27', 'If the view transformation update state '   //
     1             'of an entry in the view table is PENDING, then '  //
     2             'the state of visual representation for that '     //
     3             'workstation should be DEFERRED.')
      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, IDUM3, SVR)
      CALL CHKINQ ('pqdus', ERRIND)
      CALL IFPF (SVR .EQ. PVRDFR)
 
      CALL SETMSG ('17 25', 'If the view transformation update '      //
     1             'state of an entry in the view table is PENDING, ' //
     2             'then the current values of that entry should be ' //
     3             'the same as they were before the requested '      //
     4             'values were last set.')
      CALL IFPF ( RAREQ(16, CUVOM,   OCVOM,  0.0, 0.0) .AND.
     1            RAREQ(16, CUVMM,   OCVMM,  0.0, 0.0) .AND.
     2            RAREQ( 6, CUVCLM,  OCVCLM, 0.0, 0.0) .AND.
     3            IAREQ( 3, CUVCID,  OCVCID ) )
 
C  notpending_test:
300   CONTINUE
 
C  <update workstation> to force update of view table
      CALL PUWK (WKID, PPERFO)
C  <inquire display update state> to determine
C     svr = state of visual representation
      CALL PQDUS (WKID, ERRIND, IDUM1, IDUM2, IDUM3, SVR)
      CALL CHKINQ ('pqdus', ERRIND)
      IF (SVR .EQ. PVROK) THEN
         CALL SETMSG ('28', 'If the state of visual representation '  //
     1                'for a workstation is CORRECT, then the view '  //
     2                'transformation update state of all entries '   //
     3                'should be NOTPENDING.')
         DO 400 IVW = 0,NDVI-1
            CALL PQVWR (WKID, IVW, PCURVL, ERRIND, VWTUPD,
     1           CUVOM,CUVMM,CUVCLM,CUVCID(1),CUVCID(2),CUVCID(3) )
            CALL CHKINQ ('pqvwr', ERRIND)
            IF (VWTUPD .EQ. PNPEND) THEN
C              OK so far
            ELSE
               CALL FAIL
               GOTO 490
            ENDIF
400      CONTINUE
         CALL PASS
      ELSE
         CALL INMSG ('Skipping test that CORRECT implies NOTPENDING.')
      ENDIF
 
C  end_correct:
490   CONTINUE
 
C  <inquire view representation> on testvw to determine new
C     current state:
C     vwtupd     = view transformation update state
C     cuvom(4,4) = current orientation matrix
C     cuvmm(4,4) = current mapping matrix
C     cuvclm(6)  = current view clipping limits
C     cuvcid(3)  = current clipping indicators
      CALL PQVWR (WKID, TESTVW, PCURVL, ERRIND, VWTUPD,
     1            CUVOM,CUVMM,CUVCLM,CUVCID(1),CUVCID(2),CUVCID(3) )
      CALL CHKINQ ('pqvwr', ERRIND)
 
      IF (VWTUPD .NE. PNPEND) THEN
         CALL INMSG ('Skipping NOTPENDING test.')
         GOTO 590
      ENDIF
 
      CALL SETMSG ('17 26', 'If the view transformation update '      //
     1             'state of an entry in the view table is '          //
     2             'NOTPENDING, then the current values of that '     //
     3             'entry should be the same as the most recently '   //
     4             'set requested values.')
 
      CALL IFPF ( RAREQ(16, CUVOM,   NWVOM,  0.0, 0.0) .AND.
     1            RAREQ(16, CUVMM,   NWVMM,  0.0, 0.0) .AND.
     2            RAREQ( 6, CUVCLM,  NWVCLM, 0.0, 0.0) .AND.
     3            IAREQ( 3, CUVCID,  NWVCID ) )
 
C  end_notpending_test:
590   CONTINUE
 
666   CONTINUE
      CALL ENDIT
      END
