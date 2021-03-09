C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.03/04                              *
C  *    TEST TITLE : Update status of INPUT workstation    *
C  *                 transformation                        *
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
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND = 1)
 
      INTEGER    IWK, ONWK, OWKID, OCONID, OWTYPE, WTUPD, IDUM1,IX
      CHARACTER  OWCAT*1, MSG*300
      REAL       OCWIN(6), OCVWP(6), RQWIN(6), RQVWP(6)
      REAL       NWWIN(6), NWVWP(6), CUWIN(6), CUVWP(6)
      LOGICAL    RAREQ
 
      CALL INITGL ('06.03/04')
 
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
 
      CALL SETMSG ('15 20', 'For all workstations of category '       //
     1             'INPUT, the workstation transformation update '    //
     2             'state should always be NOTPENDING and reported '  //
     3             'as such.')
 
C  for each iwk in list of INPUT workstations:
      DO 100 IWK = 1,ONWK
         CALL MULTWS (IWK, 'i', IDUM1, OWKID, OCONID, OWTYPE, OWCAT)
         CALL POPWK (OWKID, OCONID, OWTYPE)
 
C  <Set display update state> to WAIT, NIVE to try to defer updates
         CALL PSDUS (OWKID, PWAITD, PNIVE)
 
C     <inquire workstation representation 3> to determine original
C        current state: ocwin = 3D window
C                       ocvwp = 3D viewport
         CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, OCWIN, RQVWP, OCVWP)
         CALL CHKINQ ('pqwkt3', ERRIND)
 
C  alter workstation transformation:
C  <set workstation window 3>   = nwwin = ocwin / 2
C  <set workstation viewport 3> = nwvwp = ocvwp / 2
         DO 300 IX=1,6
            NWWIN(IX) = OCWIN(IX) / 2.0
            NWVWP(IX) = OCVWP(IX) / 2.0
300      CONTINUE
 
C  <set workstation window 3>
         CALL PSWKW3 (WKID, NWWIN)
C  <set workstation viewport 3>
         CALL PSWKV3 (WKID, NWVWP)
 
C     <inquire workstation representation 3> to determine new
C        current state: wtupd = workstation transformation update state
C                       cuwin = current 3D window
C                       cuvwp = current 3D viewport
         CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
         CALL CHKINQ ('pqwkt3', ERRIND)
 
         CALL PCLWK (OWKID)
 
         IF (WTUPD .NE. PNPEND) THEN
            CALL FAIL
            WRITE (MSG, '(A,I5)')
     1            'Update state not= NOTPENDING:', WTUPD
            CALL INMSG (MSG)
            GOTO 666
         ENDIF
 
         IF ( RAREQ(6, CUWIN,   NWWIN,  0.0, 0.0) .AND.
     1        RAREQ(6, CUVWP,   NWVWP,  0.0, 0.0) )  THEN
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
