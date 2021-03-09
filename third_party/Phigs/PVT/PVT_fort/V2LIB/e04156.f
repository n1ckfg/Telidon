      SUBROUTINE E04156 (USEPRM)

C   E04156 tests the handling of error 156.

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

      INTEGER    USEPRM, ISIZ,IDUM1
      REAL       WKWN(6),WKWN0(6),WKWN1(6),WKWN4(4)
      REAL       RDUMA(6),RDUMB(6),RDUMC(6),RDUMD(4),RDUME(4),RDUMF(4)
      LOGICAL    STREQ, RAREQ, APPEQ

      CURCON = 'the specified workstation window limits are not ' //
     1         'within NPC range'
      CALL SETVS ('156', EXPERR, EXPSIZ)
      ERRSRS = '6'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)

C  3D
      CALL SETRVS ('.1,.9,.1,.9,.1,.9', WKWN0, ISIZ)
      CALL PSWKW3 (WKID, WKWN0)

      CALL SETRVS ('-.1,1.,0.,1.,0.,1.', WKWN, ISIZ)
      CALL RSWKW3 (WKID, WKWN)
      CALL SETRVS ('0.,1.,0.,1.1,0.,1.', WKWN, ISIZ)
      CALL RSWKW3 (WKID, WKWN)
      CALL SETRVS ('0.,1.,0.,1.,-0.1,1.1', WKWN, ISIZ)
      CALL RSWKW3 (WKID, WKWN)

      CALL PQWKT3 (WKID,ERRIND,IDUM1, WKWN1,RDUMA,RDUMB,RDUMC)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. RAREQ(6,WKWN0,WKWN1,0.01,0.01))

C  2D
      CALL PSWKW (WKID, 0.1,0.9,0.1,0.9)

      CALL RSWKW (WKID, -0.1,1.,0.,1.)
      CALL RSWKW (WKID, 0.1,1.,0.,1.1)
      CALL RSWKW (WKID, -0.1,1.,0.,1.1)

      CALL PQWKT (WKID, ERRIND,IDUM1,WKWN4,RDUMD,RDUME,RDUMF)
      CALL CHKINQ ('pqwkt',ERRIND)
      CALL TSTIGN (STREQ('OO**')       .AND.
     1             APPEQ(WKWN4(1) , 0.1,0.01,0.01) .AND.
     2             APPEQ(WKWN4(2) , 0.9,0.01,0.01) .AND.
     3             APPEQ(WKWN4(3) , 0.1,0.01,0.01) .AND.
     4             APPEQ(WKWN4(4) , 0.9,0.01,0.01))

      CALL PCLWK (WKID)

      CALL ENDERR

      END
