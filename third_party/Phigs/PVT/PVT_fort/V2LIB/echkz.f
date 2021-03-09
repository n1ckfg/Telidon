      SUBROUTINE ECHKZ (FUNCID)

C  ECHKZ does post-processing after an error-signalling function has
C  been called.

C  Input parameter:
C    FUNCID: numeric identifier of function that signalled error

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW,  MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE,GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL   DUMRL(20)

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150

      INTEGER    EESC,       EPREC,      EUREC
      PARAMETER (EESC  =180, EPREC =181, EUREC =182 )

      INTEGER    FUNCID, ITRIM

      IF (USRERR.EQ.1 .OR. USRERR.EQ.3) THEN
C  user-defined error handling
C  make bogus entry in error table to mark end of function effect
         CALL PERHND (2, EESC, -666)
      ELSE
C  system-defined error handling
C  make bogus entry in error file to mark end of function effect
         CALL PERLOG (2, EESC, ERRFIL)
      ENDIF

C  fill table of expected error-signalling function identifiers
      EFCNT = EFCNT+1
      EFID(EFCNT) = FUNCID

      IF (ITRIM(CURCON) .GT. 150) THEN
         CALL UNMSG ('ECHKZ detected CURCON of excessive length.')
      ENDIF

      IF (EFCNT .GT. 40) THEN
         CALL UNMSG ('ECHKZ detected CONTAB table overflow.')
      ENDIF
C  fill table of condition descriptions
      CONTAB(EFCNT) = CURCON

      END
