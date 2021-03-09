      SUBROUTINE ELSTR (STRID, STRG)

C     Input Parameter:
C     INTEGER strid              structure identifier

C     Output Parameter:
C     CHARACTER strg             string identifying element types
C                                and contents for strid

C  Elstr returns the character string STRG which contains integer-like
C  substrings separated by commas. The substrings of STRG represent an
C  ordered listing of label identifiers and execute structure identifiers
C  used to indicate the structure element positions of a particular
C  structure in the network.

C  e.g. The structure 110 creates STRG = "66, 111, 66, 120, 67, 901"
C             <open structure> 110
C             <execute structure> 111
C             <execute structure> 120
C             <label> 901
C             <close structure>

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

C PHIGS enumeration parameter for PEEXST and PELB
      INTEGER    PEEXST,      PELB
      PARAMETER (PEEXST = 66, PELB = 67)

C structure status indicator   non-existent, empty,      non-empty
      INTEGER                  PSNOEX,       PSEMPT,     PSNEMP
      PARAMETER               (PSNOEX = 0,   PSEMPT = 1, PSNEMP = 2)

C array length parameter values
      INTEGER    LINT,      LRL,      LSTR
      PARAMETER (LINT = 50, LRL = 50, LSTR = 50)

      INTEGER   ELPOS, ELTYPE, INTG, INTLEN, RL, RLLEN, STLEN, STR,
     1          STRID, INTAR(LINT), STRL(LSTR), NXCHAR, IEXIST

      REAL      RLAR(LRL)

      CHARACTER STRG*(*), STRAR(LSTR)*80

C initialize values
      STRG    = ' '
      NXCHAR  = 1
      ELPOS   = 1

C check the status of the structure
      CALL PQSTST (STRID, ERRIND, IEXIST)
      CALL CHKINQ ('pqstst', ERRIND)
      IF (IEXIST .EQ. PSNOEX  .OR.
     1    IEXIST .EQ. PSEMPT)    RETURN

C create the string STRG for the network structure STRID
900   CONTINUE
      CALL PQETS (STRID, ELPOS, ERRIND, ELTYPE, INTLEN, RLLEN, STLEN)
      IF (ERRIND .NE. 0) GOTO 950
      CALL PQECO (STRID, ELPOS, LINT, LRL, LSTR, ERRIND, INTG,
     1            INTAR, RL, RLAR, STR, STRL, STRAR)
      CALL CHKINQ ('pqeco', ERRIND)

      IF (ELTYPE .EQ. PEEXST .OR.
     1    ELTYPE .EQ. PELB)      THEN
         WRITE (STRG(NXCHAR : NXCHAR + 2), '(I2, A)') ELTYPE, ','
         NXCHAR = NXCHAR + 3
      ELSE
         CALL NCMSG ('Problem with the element type ' //
     1               'in subroutine elstr.')
      ENDIF

      WRITE (STRG(NXCHAR:NXCHAR+3),'(I3, A)') INTAR(1), ','
      NXCHAR = NXCHAR + 4

      ELPOS = ELPOS + 1
      GOTO 900

 950  CONTINUE
      STRG(NXCHAR-1:) = ' '

      END
