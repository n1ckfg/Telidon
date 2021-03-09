C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.02/01                              *
C  *    TEST TITLE : Setting and inquiring display update  *
C  *                 state                                 *
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

C  Declare program-specific variables
      INTEGER   DDEF, DMOD, ADEF, AMOD, DSURF, SVR, DM, MM,
     1          RDM, RMM, IDUM1, IDUM2, LENOP, ITRIM

      CHARACTER OPSTAT*10

C parameters used in posting a structure
      REAL  XP(2),YP(2)

C deferral mode
      INTEGER    PASAP,   PBNIG,   PBNIL,   PASTI,   PWAITD
      PARAMETER (PASAP=0, PBNIG=1, PBNIL=2, PASTI=3, PWAITD=4)
C modification mode
      INTEGER    PNIVE,   PUWOR,   PUQUM
      PARAMETER (PNIVE=0, PUWOR=1, PUQUM=2)
C display surface empty
      INTEGER    PNEMPT,   PEMPTY
      PARAMETER (PNEMPT=0, PEMPTY=1)
C dynamic modification
      INTEGER    PIRG,   PIMM,   PCBS
      PARAMETER (PIRG=0, PIMM=1, PCBS=2)
C state of visual representation
      INTEGER    PVROK,   PVRDFR,   PVRSIM
      PARAMETER (PVROK=0, PVRDFR=1, PVRSIM=2)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      DATA  XP /0.0, 1.0/
      DATA  YP /0.0, 1.0/

      CALL INITGL ('05.02/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  DESIGN:
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL SETMSG ('1 2 5', '<Inquire default display update state> ' //
     1             'should report a valid default deferral and '      //
     2             'modification mode.')
C  <inquire default display update state> to determine
C     ddef = default deferral mode
C     dmod = default modification mode
      DDEF = -6
      DMOD = -6
      CALL PQDDUS (SPECWT, ERRIND, DDEF, DMOD)
      CALL IFPF (ERRIND .EQ. 0                            .AND.
     1           (DDEF .GE. PASAP .AND. DDEF .LE. PWAITD) .AND.
     2           (DMOD .GE. PNIVE .AND. DMOD .LE. PUQUM))

      OPSTAT = 'opening'
C  open_test:
100   CONTINUE
      LENOP = ITRIM(OPSTAT)

      CALL SETMSG ('4 8', '<Inquire display update state> should '   //
     1             'report the current deferral and modification '   //
     2             'mode to be the same as the default after '       //
     3             OPSTAT (1:LENOP) // ' the workstation, but '      //
     4             'before they are explicitly set.')
C  <inquire display update state> to determine
C     adef  = actual deferral mode
C     amod  = actual modification mode
C     dsurf = display surface
C     svr   = state of visual representation
      CALL PQDUS (WKID, ERRIND, ADEF, AMOD, DSURF, SVR)
      CALL IFPF (ERRIND .EQ. 0          .AND.
     1           ADEF   .EQ. DDEF       .AND.
     2           AMOD   .EQ. DMOD)

      CALL SETMSG ('4 9 13', 'Immediately after ' // OPSTAT (1:LENOP) //
     1             ' the workstation, <inquire display update state> '//
     2             'should report the display surface as EMPTY '      //
     3             'and the state of visual representation as '       //
     4             'CORRECT.')
      CALL IFPF (ERRIND   .EQ. 0         .AND.
     1           DSURF    .EQ. PEMPTY    .AND.
     2           SVR      .EQ. PVROK)

      IF (OPSTAT .EQ. 'opening') THEN
         IF (DDEF .EQ. PASAP) THEN
            DM = PASTI
         ELSE
            DM = PASAP
         ENDIF
         IF (DMOD .EQ. PUQUM) THEN
            MM = PUWOR
         ELSE
            MM = PUQUM
         ENDIF
C <set display update state> dm,mm
         CALL PSDUS (WKID, DM, MM)
C post visible structure to workstation
         CALL POPST (10)
         CALL PPL   (2,XP,YP)
         CALL PCLST
         CALL PPOST (WKID, 10, 0.5)
C <close workstation>
         CALL PCLWK (WKID)
C <open workstation>
         CALL POPWK (WKID, CONID, WTYPE)
C opstat = "re-opening"
         OPSTAT = 're-opening'
         GOTO 100
      ENDIF

      CALL SETMSG ('1 2 3 4', '<Set display update state> should be ' //
     1             'able to set any valid deferral and modification ' //
     2             'mode.')
      DO 250 DM = PASAP, PWAITD
         DO 200 MM = PNIVE, PUQUM
            CALL PSDUS (WKID, DM, MM)
C <set display update state> dm,mm
C <inquire display update state> to determine
C   rdm = reported deferral mode
C   rmm = reported modification mode
            CALL PQDUS (WKID, ERRIND, RDM, RMM, IDUM1, IDUM2)
            IF (ERRIND .NE. 0     .OR.
     1          RDM    .NE. DM    .OR.
     2          RMM    .NE. MM)   THEN
               CALL FAIL
               GOTO 300
            ENDIF
200      CONTINUE
250   CONTINUE
      CALL PASS

300   CONTINUE

      CALL ENDIT
      END
