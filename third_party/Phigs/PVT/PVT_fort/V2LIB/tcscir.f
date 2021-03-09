      SUBROUTINE TCSCIR (OPSTRA, STRSTA, PSTSTA, STRST, INTP)

C     Input Parameters:
C     INTEGER opstra     open structure indicator (NOEXE, NOPEN, NCLOS)
C     INTEGER strsta     structure status indicator (NOEXE, NEMP,  NORG )
C     INTEGER pststa     posted structure indicator (NOEXE, NNPT, NPSTR, NPSTO)

C     Output Parameters:
C     CHARACTER strst    string indicating a structure's state as
C                        determined by the input parameters
C     INTEGER intp       the actual length of the string

C Tcscir returns a string and its length indicating the state of a
C structure.  The structure can be: open or closed, referenced or not
C referenced, empty or with original contents, and posted or not posted.

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

C Enumeration values for subroutine parameters:
C   structure state: non-existent   opened       closed
      INTEGER        NOEXE,         NOPEN,       NCLOS
      PARAMETER     (NOEXE = -1,    NOPEN = 0,   NCLOS = 1)

C   structure posted state:
C                    not posted   posted:priority=R,   posted:priority=O
      INTEGER        NNPT,        NPSTR,               NPSTO
      PARAMETER     (NNPT = 1,    NPSTR = 4,           NPSTO = 5)

C   structure contents:
C                    empty     original
      INTEGER        NEMP,     NORG
      PARAMETER     (NEMP = 0, NORG = 1)

      INTEGER OPSTRA, PSTSTA, STRSTA, INTP, ITRIM

      CHARACTER STRST*(*)

      CHARACTER OPSTAB (NOPEN:NCLOS)*30, STRTAB (NOEXE:NORG)*30,
     1          PSTTAB (NNPT:NPSTO)*50
      DATA OPSTAB / 'OPEN', 'CLOSED' /

      DATA STRTAB / ' ', ', EMPTY,', ', ORIGINAL,' /

      DATA PSTTAB / 'and NOT-POSTED', ' ', ' ',
     1              'and POSTED with old resulting priority',
     2              'and POSTED with old original priority' /

      IF (OPSTRA .EQ. NOEXE) THEN
          IF (PSTSTA .EQ. NOEXE   .AND.
     1        STRSTA .EQ. NOEXE)    THEN
             STRST = 'NON-EXISTENT'
             GOTO 250
          ELSE
             CALL UNMSG ('Problem with the structure state being '//
     1                   'non-existent in subroutine TCSCIR.')
          ENDIF
      ENDIF

      STRST        = OPSTAB (OPSTRA)
      INTP  = ITRIM (STRST) + 1
      STRST(INTP:) = STRTAB (STRSTA)
      INTP  = ITRIM (STRST) + 2
      STRST(INTP:) = PSTTAB (PSTSTA)

 250  CONTINUE
      INTP = ITRIM (STRST)

      END
