      SUBROUTINE E04151 (USEPRM)

C   E0451 tests the handling of error 151.

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

      INTEGER   USEPRM, ISIZ, IDUM1
      REAL      WKWN0(6),WKWN(6),WKWN1(6),RDUMA(6),RDUMB(6),RDUMC(6)
      REAL      WKWN4(4),RDUMD(4),RDUME(4),RDUMF(4)
      LOGICAL   STREQ, RAREQ, APPEQ

      CURCON = 'the specified workstation window limits are '//
     1         'invalid: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, '//
     2         'UMIN>=UMAX, or VMIN>=VMAX'
      CALL SETVS ('151', EXPERR, EXPSIZ)
      ERRSRS = '2'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)

      CALL SETRVS ('.1,.9,.1,.9,.1,.9', WKWN0, ISIZ)
      CALL PSWKW3 (WKID, WKWN0)

      CALL SETRVS ('.6,.3,0.,1.,0.,1.', WKWN, ISIZ)
      CALL RSWKW3 (WKID, WKWN)

      CALL SETRVS ('0.,1.,.6,.6,0.,1.', WKWN, ISIZ)
      CALL RSWKW3 (WKID, WKWN)

      CALL SETRVS ('0.,1.,0.,1.,.6,.3', WKWN, ISIZ)
      CALL RSWKW3 (WKID, WKWN)

      CALL SETRVS ('0.,1.,.6,.3,0.,0.', WKWN, ISIZ)
      CALL RSWKW3 (WKID, WKWN)

      CALL RSWKW (WKID, 0.6,0.3,0.,1.)

      CALL RSWKW (WKID, 0.,1.,0.6,0.3)

      CALL PQWKT3 (WKID,ERRIND,IDUM1,WKWN1,RDUMA,RDUMB,RDUMC)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL TSTIGN (STREQ('OO**')      .AND.
     1             RAREQ(6,WKWN0,WKWN1,0.01,0.01))

      CALL PSWKW (WKID, 0.1,0.8,0.1,0.8)
      CALL RSWKW (WKID, 0.6,0.3,0.9,0.5)
      CALL PQWKT (WKID,ERRIND,IDUM1,WKWN4,RDUMD,RDUME,RDUMF)
      CALL CHKINQ ('pqwkt', ERRIND)
      CALL TSTIGN (STREQ('OO**')      .AND.
     1             APPEQ(WKWN4(1),0.1,0.01,0.001)   .AND.
     2             APPEQ(WKWN4(2),0.8,0.01,0.001)   .AND.
     3             APPEQ(WKWN4(3),0.1,0.01,0.001)   .AND.
     4             APPEQ(WKWN4(4),0.8,0.01,0.001))

      CALL PCLWK (WKID)

      CALL ENDERR

      END
