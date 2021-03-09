C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.01/03                        *
C  *    TEST TITLE : Setting and inquiring colour model    *
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
      INTEGER    CURMOD, INIMOD, NEWMOD

C colour model
      INTEGER    PRGB,   PCIE,   PHSV,   PHLS
      PARAMETER (PRGB=1, PCIE=2, PHSV=3, PHLS=4)
C NOTE:  INTEGER rather than enumeration type.  Explicitly defined and
C required potion of conceptually unbounded range defined here.

C parameters for <inquire workstation connection and type>
      INTEGER    SPECWT, SPECON

      CALL INITGL ('04.03.02.01/03')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C *** *** *** *** Initial Colour Model *** *** *** ***

      CALL SETMSG ('10', '<Inquire colour model> should be able to '//
     1             'determine the initial colour model.')
      CALL PQCMD (WKID, ERRIND, INIMOD)
      CALL IFPF  (ERRIND .EQ. 0)

C set different colour model
      IF (INIMOD .EQ. PRGB) THEN
         NEWMOD = PCIE
      ELSE
         NEWMOD = PRGB
      ENDIF
      CALL PSCMD (WKID, NEWMOD)
      CALL PQCMD (WKID, ERRIND, CURMOD)
      CALL CHKINQ ('pqcmd', ERRIND)

      CALL SETMSG ('9 10', '<Set colour model> should be able to '   //
     1             'change colour model from its default setting.')
      CALL IFPF (NEWMOD .EQ. CURMOD)

C *** *** *** *** Redefined Colour Model *** *** *** ***

C get new colour model
      IF (CURMOD .EQ. PRGB) THEN
         NEWMOD = PCIE
      ELSE
         NEWMOD = PRGB
      ENDIF
      CALL PSCMD (WKID, NEWMOD)
      CALL PQCMD (WKID, ERRIND, CURMOD)
      CALL CHKINQ ('pqcmd', ERRIND)
      CALL SETMSG ('9 10', '<Set colour model> should be able to '   //
     1             'set colour model and then re-set it.')
      CALL IFPF (NEWMOD .EQ. CURMOD)

C wrap it up
      CALL ENDIT
      END
