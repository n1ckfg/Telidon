C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.02/07                           *
C  *    TEST TITLE : Update status of view table for INPUT *
C  *                 workstations                          *
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

C Current and Requested values.
      INTEGER    PCURVL,     PRQSVL
      PARAMETER (PCURVL = 0, PRQSVL = 1)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND = 1)

      INTEGER    MAXWK
      PARAMETER (MAXWK = 100)

      LOGICAL    RAREQ, IAREQ

      REAL       ORVOM(4,4), CUVOM(4,4), NWVOM(4,4)
      REAL       ORVMM(4,4), CUVMM(4,4), NWVMM(4,4)
      REAL       ORVCLM(6),  CUVCLM(6),  NWVCLM(6)
      INTEGER    ORVCID(3),  CUVCID(3),  NWVCID(3)

      INTEGER    NDVI, TESTVW, ROW,COL, IX, NWVAL, VWTUPD
      INTEGER    IDUM1
      INTEGER    IWK, ONWK, OWKID, OCONID, OWTYPE
      CHARACTER  OWCAT*1, MSG*300

      CALL INITGL ('06.02.02/07')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  Get list of accessible workstations of category INPUT,
C  one element at a time.  ONWK is number of elements in
C  list.
      CALL MULTWS (0, 'i', ONWK, OWKID, OCONID, OWTYPE, OWCAT)
      IF (ONWK .LE. 0) THEN
         CALL INMSG ('No INPUT workstations to be tested.')
         GOTO 666
      ENDIF

      CALL SETMSG ('26 29', 'For all workstations of category '       //
     1             'INPUT, the view transformation update state of '  //
     2             'all entries in the view table should always be '  //
     3             'NOTPENDING and reported as such.')

C  for each iwk in list of INPUT workstations:
      DO 100 IWK = 1,ONWK
         CALL MULTWS (IWK, 'i', IDUM1, OWKID, OCONID, OWTYPE, OWCAT)
         CALL POPWK (OWKID, OCONID, OWTYPE)

C     <Inquire list of view indices> to determine
C        ndvi = number of defined indices in the view table
         CALL PQEVWI (OWKID, 0, ERRIND, NDVI, IDUM1)
         CALL CHKINQ ('pqevwi', ERRIND)

C  <Set display update state> to WAIT, NIVE to try to defer updates
         CALL PSDUS (OWKID, PWAITD, PNIVE)
         TESTVW = NDVI/2

C     <inquire view representation> on testvw to determine original
C        requested state:
         CALL PQVWR (OWKID, TESTVW, PRQSVL, ERRIND, VWTUPD,
     1               ORVOM,ORVMM,ORVCLM,ORVCID(1),ORVCID(2),ORVCID(3) )
         CALL CHKINQ ('pqvwr', ERRIND)


C  generate different values:
C  nwvom  = orvom elements + 1.0
C  nwvmm  = orvmm elements + 1.0
         DO 120 ROW = 1,4
         DO 110 COL = 1,4
            NWVOM (ROW,COL) = ORVOM (ROW,COL) + 1.0
            NWVMM (ROW,COL) = ORVMM (ROW,COL) + 1.0
110      CONTINUE
120      CONTINUE

         DO 130 IX = 1,6
            NWVCLM (IX) = ORVCLM (IX) / 2 + 0.1
130      CONTINUE
         IF (ORVCID(1) .EQ. PCLIP) THEN
            NWVAL = PNCLIP
         ELSE
            NWVAL = PCLIP
         ENDIF

         DO 140 IX = 1,3
            NWVCID (IX) = NWVAL
140      CONTINUE


C     <set view representation 3> on testvw with
C        nwvom, nwvmm, nwvclm, nwvcid
         CALL PSVWR3 (OWKID, TESTVW, NWVOM,NWVMM,NWVCLM,
     1                NWVCID(1),NWVCID(2),NWVCID(3) )

C     <inquire view representation> on testvw to determine new
C        current state:
C        vwtupd     = view transformation update state
C        cuvom(4,4) = current orientation matrix
C        cuvmm(4,4) = current mapping matrix
C        cuvclm(6)  = current view clipping limits
C        cuvcid(3)  = current clipping indicators
         CALL PQVWR (OWKID, TESTVW, PCURVL, ERRIND, VWTUPD,
     1               CUVOM,CUVMM,CUVCLM,CUVCID(1),CUVCID(2),CUVCID(3) )
         CALL CHKINQ ('pqvwr', ERRIND)

         CALL PCLWK (OWKID)

         IF (VWTUPD .NE. PNPEND) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)')
     1            'Update state not= NOTPENDING:', VWTUPD
            CALL INMSG (MSG)
            GOTO 666
         ENDIF

         IF ( RAREQ(16, CUVOM,   NWVOM,  0.0, 0.0) .AND.
     1        RAREQ(16, CUVMM,   NWVMM,  0.0, 0.0) .AND.
     2        RAREQ( 6, CUVCLM,  NWVCLM, 0.0, 0.0) .AND.
     3        IAREQ( 3, CUVCID,  NWVCID ) )  THEN
C           OK so far
         ELSE
            CALL FAIL
            CALL INMSG ('Current values not those most recently set.')
            GOTO 666
         ENDIF

C  next iwk
100   CONTINUE
      CALL PASS

C  done:
666   CONTINUE
      CALL ENDIT
      END
