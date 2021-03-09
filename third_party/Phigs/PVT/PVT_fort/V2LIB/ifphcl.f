      SUBROUTINE IFPHCL (USEPRM)

C  IFPHCL initializes things for the special case where error
C  handling is to be tested in the state where PHIGS is closed.
C  This requires special handling, since ordinarily the error
C  file will not be available for writing.

C  Input parameters:
C    USEPRM : Handling mode: 1 for user, 2 for system

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

      INTEGER   USEPRM

      CURCON = 'PHIGS is closed'
C  add 2 to "normal" USRERR value to signify PHCL
      CALL ESETUP (USEPRM+2)
      CALL PCLPH

      END
