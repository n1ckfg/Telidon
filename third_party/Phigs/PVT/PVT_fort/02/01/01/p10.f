C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.01/10                           *
C  *    TEST TITLE : Multiple structure creation           *
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
 
      INTEGER    IDST
      PARAMETER (IDST = 10)
 
C PHIGS parameter types
      INTEGER  NSTID, STRID, IDUM1, STARR(IDST), ACTUAL(IDST), NIDST, I

      REAL     RDUM1
 
      LOGICAL  SETEQ
 
      CALL INITGL ('02.01.01/10')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
 
C creation of multiple structures
      RDUM1 = 0.02
      STRID = 1
      DO 100 NIDST = 1, 5
         STARR(NIDST) = STRID
         STRID = STRID + 3
 100  CONTINUE
 
      CALL PEMST  (STARR(1))
      CALL PCSTID (100, STARR(2))
      CALL PPOST  (WKID, STARR(3), RDUM1)
      CALL POPST  (STARR(4))
      CALL PEXST  (STARR(5))
 
      CALL SETMSG ('9 10', 'The CSS should be able to hold ' //
     1             'multiple structures.')
 
C nstid = number of structure identifiers
      CALL PQSID (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
 
      IF (NSTID .EQ. 5) THEN
         DO 200 I = 1, 5
            CALL PQSID (I, ERRIND, IDUM1, ACTUAL(I))
            CALL CHKINQ ('pqsid', ERRIND)
 200     CONTINUE
         CALL IFPF (SETEQ (5, ACTUAL, STARR))
      ELSE
         CALL FAIL
      ENDIF
 
      CALL ENDIT
      END
