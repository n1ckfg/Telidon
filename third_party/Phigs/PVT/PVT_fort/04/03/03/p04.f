C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.03/04                           *
C  *    TEST TITLE : Updating of HLHSR modes               *
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
      INTEGER UPSTAT, CURMOD, REQMOD
      INTEGER IDUM1, IDUM2
C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
C update state
      INTEGER    PNPEND,     PPEND
      PARAMETER (PNPEND = 0, PPEND =1)

      LOGICAL    STATOK


C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      REAL       XP(2),YP(2)

      DATA  XP /0.0, 1.0/
      DATA  YP /0.0, 1.0/

      CALL INITGL ('04.03.03/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
C get this workstation type
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C <inquire HLHSR mode> to determine
C  upstat = HLHSR update state
C  curmod = current HLHSR mode
C  reqmod = requested HLHSR mode
      UPSTAT = -6
      CURMOD = -6
      REQMOD = -6
      CALL PQHRM (WKID, ERRIND, UPSTAT, CURMOD, REQMOD)
      CALL CHKINQ ('pqhrm', ERRIND)

C check upstat is valid upon <open workstation>
      STATOK = (UPSTAT .EQ. PNPEND .OR. UPSTAT .EQ. PPEND)

      CALL SETMSG ('12', 'Immediately after <open workstation>, '   //
     1             'the HLHSR update state should be NOTPENDING.')
      CALL IFPF (UPSTAT .EQ. PNPEND)

      CALL SETMSG ('13', 'Immediately after <open workstation>, '   //
     1             'the current HLHSR mode should be 0.')
      CALL IFPF (CURMOD .EQ. 0)

      CALL SETMSG ('14', 'Immediately after <open workstation>, '   //
     1             'the requested HLHSR mode should be 0.')
      CALL IFPF (REQMOD .EQ. 0)

C Try to cause HLHSR update state to be PENDING by making
C   surface NOT EMPTY:
      CALL POPST (10)
      CALL PPL   (2,XP,YP)
      CALL PCLST
      CALL PPOST (WKID, 10, 0.5)
      CALL PUWK  (WKID, PPERFO)

      CALL SETMSG ('15', 'The HLHSR update state should be either '   //
     1             'PENDING or NOTPENDING.')
C re-set HLHSR mode
      CALL PSHRM (WKID, 0)
      UPSTAT = -66
      CALL PQHRM (WKID, ERRIND, UPSTAT, IDUM1,IDUM2)
      CALL CHKINQ ('pqhrm', ERRIND)
      CALL IFPF ((UPSTAT .EQ. PNPEND .OR. UPSTAT .EQ. PPEND) .AND.
     1            STATOK)

C  close workstation and re-open
      CALL PCLWK (WKID)
      CALL POPWK (WKID, CONID, WTYPE)

      CALL SETMSG ('12', 'Immediately after re-opening the '   //
     1             'workstation, the HLHSR update state should ' //
     2             'be NOTPENDING.')
      UPSTAT = -66
      CALL PQHRM (WKID, ERRIND, UPSTAT, IDUM1, IDUM2)
      CALL CHKINQ ('pqhrm', ERRIND)
      CALL IFPF (UPSTAT .EQ. PNPEND)

666   CONTINUE
      CALL ENDIT
      END
