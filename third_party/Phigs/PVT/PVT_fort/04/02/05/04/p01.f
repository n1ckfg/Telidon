C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.04/01                        *
C  *    TEST TITLE : Simple setting and inquiring          *
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

      INTEGER    DIMX, DIMY, ISC, ISR, DX, DY, DX2, DY2, PAI
      PARAMETER  (DIMX = 100, DIMY = 100)
      INTEGER    COLIA(DIMX,DIMY), COLIA2(DIMX, DIMY)

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

      LOGICAL    ARREQ, PATAVL

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      CALL INITGL ('04.02.05.04/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      IF (.NOT. PATAVL(SPECWT)) THEN
         CALL INMSG ('Skipping all tests because pattern interior ' //
     1               'style is not supported on this workstation.')
         GOTO 666
      ENDIF

C setup index #1, colia(3 x 2) starting at col 5, row 5
      PAI = 1
      ISC = 5
      ISR = 5
      DX  = 3
      DY  = 2
      COLIA (5,5) = 11
      COLIA (6,5) = 21
      COLIA (7,5) = 31
      COLIA (5,6) = 41
      COLIA (6,6) = 41
      COLIA (7,6) = 51
C  <set pattern representation> for index #1
      CALL PSPAR (WKID, PAI, DIMX, DIMY, ISC, ISR, DX, DY, COLIA)

C  <inquire pattern representation> for index #1, as set
      CALL PQPAR (WKID, PAI, PSET, DIMX, DIMY, ERRIND, DX2, DY2, COLIA2)
      CALL CHKINQ ('pqpar', ERRIND)

      CALL SETMSG ('2 5', 'Pattern attributes should be returned as ' //
     1             'set.')
      CALL IFPF ( ERRIND .EQ. 0    .AND.
     1            DX2    .EQ. DX   .AND.
     2            DY2    .EQ. DY   .AND.
     3            ARREQ (DIMX, DIMY, ISC, ISR, DX, DY, COLIA, COLIA2))

666   CONTINUE
      CALL ENDIT
      END
