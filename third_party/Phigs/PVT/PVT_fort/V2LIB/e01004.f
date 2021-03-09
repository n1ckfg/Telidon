      SUBROUTINE E01004 (USEPRM)

C  E01004 tests the handling of error number 4: function requires
C  state (PHOP,WSCL,STCL,ARCL) when PHIGS is open.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

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

      INTEGER   USEPRM, ARNM

      LOGICAL   STREQ

      CALL SETVS ('4', EXPERR,EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CURCON = 'PHIGS is open and a workstation is open'
      CALL RCLPH
      CALL TSTIGN (STREQ('OO**'))

      CALL PCLWK (WKID)
      CALL POPST (101)
      CURCON = 'PHIGS is open and a structure is open'
      CALL RCLPH
      CALL TSTIGN (STREQ('OCO*'))

      CALL PCLST
      CALL AVARNM (ARNM)
      CALL POPARF (11, ARNM)
      CURCON = 'PHIGS is open and an archive file is open'
      CALL RCLPH
      CALL TSTIGN (STREQ('OCCO'))

      CALL PCLARF (11)
      CALL ENDERR

      END
