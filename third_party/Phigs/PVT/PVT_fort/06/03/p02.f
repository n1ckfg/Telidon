C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.03/02                              *
C  *    TEST TITLE : Initialization of the workstation     *
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
 
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND = 1)
 
      CHARACTER  MSGSUF*25
      LOGICAL    RAREQ
      INTEGER    ADMAX(3), DCUN, SPECON,SPECWT
      REAL       DCMAX(6)
      INTEGER    WTUPD, IX
      REAL       RQWIN(6), CUWIN(6), RQVWP(6), CUVWP(6), NPC(6)
 
      DATA NPC   / 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 /
      DATA DCMAX / 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 /
 
      CALL INITGL ('06.03/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      MSGSUF = 'opening workstation.'
 
C  check_transform loop:
100   CONTINUE
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
C  <inquire workstation transformation 3> to determine
C     update state:          wtupd
C     requested 3D window:   rqwin
C     current   3D window:   cuwin
C     requested 3D viewport: rqvwp
C     current   3D viewport: cuvwp
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
 
      CALL SETMSG ('5 12', 'The workstation transformation update '   //
     1             'state should be initialized to NOTPENDING after ' //
     2             MSGSUF)
      CALL IFPF (WTUPD .EQ. PNPEND)
 
      CALL SETMSG ('5 12', 'The current and requested workstation '   //
     1             'window should be initialized to [0,1] in all '    //
     2             'three dimensions after ' // MSGSUF)
      CALL IFPF (RAREQ(6, RQWIN, NPC, 0.0,0.0)  .AND.
     1           RAREQ(6, CUWIN, NPC, 0.0,0.0))
 
      CALL SETMSG ('2 5 12', 'The current and requested workstation ' //
     1             'viewport should be initialized to the 3D '        //
     2             'maximum display volume size after ' // MSGSUF)
 
C  <inquire display space size 3> to determine
C     dcmax  = maximum size in DC units
      CALL PQDSP3 (SPECWT, ERRIND, DCUN, DCMAX(2),DCMAX(4),DCMAX(6),
     1                                   ADMAX(1),ADMAX(2),ADMAX(3))
      CALL CHKINQ ('pqdsp3', ERRIND)
 
      CALL IFPF (RAREQ(6, RQVWP, DCMAX, 0.0,0.0)  .AND.
     1           RAREQ(6, CUVWP, DCMAX, 0.0,0.0))
 
C  alter workstation transformation:
      DO 300 IX=1,6
         RQWIN(IX) = RQWIN(IX) / 2.0
         RQVWP(IX) = RQVWP(IX) / 2.0
300   CONTINUE
 
C  <set workstation window 3>
      CALL PSWKW3 (WKID, RQWIN)
C  <set workstation viewport 3>
      CALL PSWKV3 (WKID, RQVWP)
 
C  <close workstation>
      CALL PCLWK (WKID)
 
      IF (MSGSUF .EQ. 'opening workstation.') THEN
         MSGSUF = 're-opening workstation.'
         GOTO 100
      ENDIF
 
666   CONTINUE
      CALL ENDIT
      END
