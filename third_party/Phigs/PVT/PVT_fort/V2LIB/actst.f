      SUBROUTINE ACTST (ACSTID, STRG, EXPCON,
     1                  OPSTRA, CONTOK, PSTSTA, PSTPRI)

C     Input Parameters :
C     INTEGER   acstid   structure identifier
C     CHARACTER strg     string identifying expected element type
C                        and content for structure acstid
C     INTEGER   expcon   expected contents: (NOEXE, NORG, NEMP)

C     Output Parameters:
C     INTEGER opstra     open structure indicator     (NOEXE, NOPEN, NCLOS)
C     LOGICAL contok     structure contents as expected
C     INTEGER pststa     posted structure indicator   (NOEXE, NPST, NNPT)
C     INTEGER pstpri     posted structure priority

C ACTST returns values indicating if a structure is non-existent
C open, closed, empty, original, and posted, not posted.

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

C open-structure status:
C                none-open   open-structure
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C structure status indicator:
C                non-existent,  empty,      non-empty
      INTEGER    PSNOEX,        PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0,    PSEMPT = 1, PSNEMP = 2)

C Enumeration values for subroutine parameters:
C   structure state: non-existent   opened       closed
      INTEGER        NOEXE,         NOPEN,       NCLOS
      PARAMETER     (NOEXE = -1,    NOPEN = 0,   NCLOS = 1)

C   structure posted state:
C                    structure posted     structure not posted
      INTEGER         NPST,                NNPT
      PARAMETER      (NPST = 0,            NNPT = 1)

C   structure reference status:
C                    referenced  not referenced
      INTEGER        NREF,       NNRF
      PARAMETER     (NREF = 2,   NNRF = 3)

C   structure contents:
C                    empty     original  bad-contents
      INTEGER        NEMP,     NORG,     NBCON
      PARAMETER     (NEMP = 0, NORG = 1, NBCON = -66)

      CHARACTER STRG*(*)

      INTEGER IDSTR, STYPE, OPSTRA, EXPCON, PSTSTA, POSTNM,
     1        IEXIST, IDUM2, ACSTID, STRID, PSTLT

      REAL    RDUM1, PSTPRI

      LOGICAL STRCON, CONTOK

C determine if a structure is empty, non-existent, has the original
C contents, or none of these.
      CALL PQSTST (ACSTID, ERRIND, IEXIST)
      CALL CHKINQ ('pqstst', ERRIND)

      IF (IEXIST .EQ. PSNOEX) THEN
C non-existent
         OPSTRA = NOEXE
         CONTOK = (EXPCON .EQ. NOEXE)
         PSTSTA = NOEXE
         PSTPRI = 0.0
         RETURN
      ENDIF

C set CONTOK = contents OK
      CONTOK = ((EXPCON .EQ. NEMP) .AND. (IEXIST .EQ. PSEMPT)) .OR.
     1         ((EXPCON .EQ. NORG) .AND. (STRCON (ACSTID, STRG)))

C determine if a structure is opened or closed
      CALL PQOPST (ERRIND, STYPE, IDSTR)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .EQ. POPNST  .AND.
     1    IDSTR .EQ. ACSTID)   THEN
         OPSTRA = NOPEN
      ELSE
         OPSTRA = NCLOS
      ENDIF

C determine if a structure is posted or not
      PSTSTA = NNPT
      CALL PQPOST (WKID, 0, ERRIND, POSTNM, IDUM2, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      DO 200 PSTLT = 1, POSTNM
         CALL PQPOST (WKID, PSTLT, ERRIND, IDUM2, STRID, PSTPRI)
         CALL CHKINQ ('pqpost', ERRIND)
         IF (STRID .EQ. ACSTID) THEN
             PSTSTA = NPST
             GOTO 210
         ENDIF
200   CONTINUE
210   CONTINUE

      END
