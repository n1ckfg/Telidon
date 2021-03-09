      SUBROUTINE E04150 (USEPRM)

C   E04150 tests the handling of error 150

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

C   clipping indicator
      INTEGER     PNCLIP,     PCLIP
      PARAMETER  (PNCLIP=0,   PCLIP=1)

      INTEGER  USEPRM, IX, ISIZ, IDUM1,IDUM2,IDUM3,IDUM4
      INTEGER  IDUM5,IDUM6,IDUM7, MAXVW, NVWIX, SPECWT
      REAL     ROTMT3(3,3), MAPMT3(3,3), ROTMT4(4,4),MAPMT4(4,4),
     1         CLPLM3(4), CLPLM4(6)
      LOGICAL  STREQ

      CURCON = 'setting this view table entry would exceed the ' //
     1         'maximum number of entries allowed in the '//
     2         'workstation view table'
      CALL SETVS ('150', EXPERR, EXPSIZ)
      ERRSRS = '1'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT,ERRIND,IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,
     1             IDUM6,IDUM7,MAXVW)
      CALL CHKINQ ('pqwksl', ERRIND)

      CALL IDMAT (3, ROTMT3)
      CALL IDMAT (3, MAPMT3)
      CALL IDMAT (4, ROTMT4)
      CALL IDMAT (4, MAPMT4)
      CALL SETRVS ('0.,1.,0.,1.', CLPLM3, ISIZ)
      CALL SETRVS ('0.,1.,0.,1.,0.,1.', CLPLM4, ISIZ)

C  valid entries are 0 (unsettable) thru MAXVW-1
      DO 100 IX = 1, MAXVW-1
         CALL PSVWR (WKID, IX,ROTMT3,MAPMT3,CLPLM3, PCLIP)
100   CONTINUE

      CALL RSVWR (WKID, MAXVW, ROTMT3,MAPMT3,CLPLM3,PCLIP)

      CALL PQEVWI (WKID, 0, ERRIND, NVWIX, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. NVWIX.EQ.MAXVW)

      CALL RSVWR3 (WKID,MAXVW,ROTMT4,MAPMT4,CLPLM4,PCLIP,PCLIP,
     1             PCLIP)

      CALL PCLWK (WKID)

      CALL ENDERR

      END
