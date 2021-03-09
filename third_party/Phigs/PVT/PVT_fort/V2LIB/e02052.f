      SUBROUTINE E02052 (USEPRM)

C  E02052 tests the handling of error number 52

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

      INTEGER      USEPRM, IX, IDUM1, NMTYPE, MXTYPE, THISTY

      LOGICAL      STREQ

      CURCON  = 'the workstation type is not recognized ' //
     1          'by the implementation'
      CALL SETVS ('52,55', EXPERR, EXPSIZ)
      ERRSRS = '2'
      CALL ESETUP (USEPRM)

      CALL PQEWK (1, ERRIND, NMTYPE, MXTYPE)
      CALL CHKINQ ('pqewk', ERRIND)
      DO 50 IX = 1, NMTYPE
         CALL PQEWK (IX, ERRIND, IDUM1, THISTY)
         CALL CHKINQ ('pqewk', ERRIND)
         IF (THISTY .GT. MXTYPE) THISTY = MXTYPE
50    CONTINUE

      CALL ROPWK (WKID, CONID, MXTYPE+1)
      CALL TSTIGN (STREQ('OC**'))

C  **** Examine saved errors

      CALL ENDERR

      END
