C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.04/01                              *
C  *    TEST TITLE : Inquiring about structure identifiers *
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
     3        DUMINT(20)
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

C  Declare program-specific variables
      INTEGER    SCALE
      PARAMETER (SCALE = 50)
      INTEGER    ARID, ARNM, LASI(SCALE), EXPSTR(SCALE), LASLEN,
     1           EXPLEN
      LOGICAL    SETEQ

      CALL INITGL ('03.04/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  set up standard networks in CSS
      CALL STDCSS
C  open new archive file, with arid = archive identifier
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
C  <delete all structures from archive> to ensure empty file
      CALL PDASAR (ARID)
C  expstr = expected structures = 114,102,100,140,107
      CALL SETVS('114,102,100,140,107', EXPSTR, EXPLEN)
C  <archive structures> with expstr, arid
      CALL PARST (ARID, EXPLEN, EXPSTR)
C  <delete all structures> from CSS
      CALL PDAS

C  <retrieve structure identifiers> to determine
C     lasi = list of archive structure identifiers
      CALL PRSID (ARID, SCALE, LASLEN, LASI)
      CALL SETMSG ('1', '<Retrieve structure identifiers> should ' //
     1             'retrieve all identifiers as archived by '      //
     2             '<archive structures>.')
C  pass/fail depending on (lasi contains same identifiers as expstr)
      CALL IFPF (EXPLEN .EQ. LASLEN .AND. SETEQ (EXPLEN, EXPSTR, LASI))

C  close archive file
      CALL PCLARF (ARID)

666   CONTINUE
      CALL ENDIT
      END
