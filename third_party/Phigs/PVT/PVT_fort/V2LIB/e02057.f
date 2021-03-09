      SUBROUTINE E02057 (USEPRM)

C  E02057 tests the handling of error number 57.

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

C workstation category
      INTEGER    POUTPT,     PINPUT,     POUTIN,     PMO,     PMI
      PARAMETER (POUTPT = 0, PINPUT = 1, POUTIN = 2, PMO = 3, PMI = 4)

C  relative input priority
      INTEGER     PHIGHR,   PLOWER
      PARAMETER  (PHIGHR=0, PLOWER=1)

      INTEGER   USEPRM, ISIZ, NWKMI,IDUM1,IDUM2,IDUM3
      INTEGER   OWKID,OCONID,OWTYPE, RNDINT
      CHARACTER*1   CDUM, OWCAT

      REAL  ROTMT2(3,3), MAPMT2(3,3), LIMIT2(6)

      LOGICAL  STREQ

      CURCON = 'the specified workstation is of category MI'
      CALL SETVS ('57', EXPERR, EXPSIZ)
      ERRSRS = '7'
      CALL ESETUP (USEPRM)

      CALL MULTWS (0, 'n',NWKMI,IDUM1,IDUM2,IDUM3,CDUM)
      IF (NWKMI .EQ. 0) THEN
         CALL INMSG ('There is no accessible workstation with '//
     1               'category of MI, the test is skipped.')
         RETURN
      ENDIF

      CALL MULTWS (RNDINT(1,NWKMI), 'n', IDUM1,OWKID,OCONID,OWTYPE,
     1             OWCAT)

C  **** Generate errors

      CALL POPWK (OWKID, OCONID, OWTYPE)

      CALL ETR (.4, .6, MAPMT2)
      CALL ETR (.5, .7, ROTMT2)
      CALL SETRVS ('0.1,0.9,0.2,0.9', LIMIT2, ISIZ)
      CALL RSVWR (OWKID, 1,ROTMT2,MAPMT2,LIMIT2,0)
      CALL TSTIGN (STREQ('OO**'))

      CALL RSVTIP (OWKID, 1, 1, 1)
      CALL RSWKW  (OWKID, 0.,1.,0.,1.)

      CALL RSWKV (OWKID, 0.,1.,0.,1.)
      CALL PCLWK (OWKID)

C  **** Examine saved errors

      CALL ENDERR

      END
