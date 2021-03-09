C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/e04150                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/e04151                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/e04152                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E04152 (USEPRM)
 
C    E04152 tests the handling of error 152
 
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
 
      INTEGER   SPECWT, USEPRM, IDUM1,IDUM2,IDUM3, IDUM4
      REAL      WKVP(6),WKVP0(6),WKVP1(6),RDUMA(6),RDUMB(6),RDUMC(6)
      REAL      WKVP4(4),RDUMD(4),RDUME(4),RDUMF(4)
      REAL      DX,DY,DZ,XX,YY,ZZ
      LOGICAL   STREQ, APPEQ, RAREQ
 
      CURCON = 'the specified workstation viewport limits are '//
     1         'invalid: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX'
      CALL SETVS ('152', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQDSP3 (SPECWT,ERRIND,IDUM1,DX,DY,DZ,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqdsp3', ERRIND)
      XX = DX/2.
      YY = DY/2.
      ZZ = DZ/2.
 
      CALL DS3 (0.,XX,0.,YY,0.,ZZ,WKVP0)
      CALL PSWKV3 (WKID, WKVP0)
 
      CALL DS3 (XX,0.,0.,DY,0.,DZ,WKVP)
      CALL RSWKV3 (WKID, WKVP)
 
      CALL DS3 (DX,DX,0.,YY,0.,DZ,WKVP)
      CALL RSWKV3 (WKID, WKVP)
 
      CALL DS3 (0.,DX,0.,DY,ZZ,0.,WKVP)
      CALL RSWKV3 (WKID, WKVP)
 
      CALL DS3 (0.,DX,YY,YY,ZZ,ZZ,WKVP)
      CALL RSWKV3 (WKID, WKVP)
 
      CALL PQWKT3 (WKID,ERRIND,IDUM1,RDUMA,RDUMB,WKVP1,RDUMC)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL TSTIGN (STREQ('OO**')      .AND.
     1             RAREQ(6,WKVP1,WKVP0,0.01,0.01))
 
      CALL PQDSP (SPECWT,ERRIND,IDUM1,DX,DY,IDUM2,IDUM3)
      CALL CHKINQ ('pqdsp', ERRIND)
      XX = DX/2.
      YY = DY/2.
 
      CALL PSWKV (WKID, 0.,XX,0.,YY)
 
      CALL RSWKV (WKID, XX,0.,0.,DY)
      CALL RSWKV (WKID, 0.,DX,YY,0.)
      CALL RSWKV (WKID, 0.,XX,YY,YY)
 
      CALL PQWKT (WKID,ERRIND,IDUM1,RDUMD,RDUME,WKVP4,RDUMF)
      CALL CHKINQ ('pqwkt', ERRIND)
      CALL TSTIGN (STREQ('OO**')     .AND.
     1             APPEQ(WKVP4(1),0.,0.01,0.001)    .AND.
     2             APPEQ(WKVP4(2),XX,0.01,0.001)    .AND.
     3             APPEQ(WKVP4(3),0.,0.01,0.001)    .AND.
     4             APPEQ(WKVP4(4),YY,0.01,0.001))
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/e04153                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E04153 (USEPRM)
 
C    E04153 tests the handling of error 153.
 
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
 
C  clipping indicator
      INTEGER     PNCLIP,     PCLIP
      PARAMETER  (PNCLIP=0,   PCLIP=1)
C
      INTEGER     PCURVL,     PRQSVL
      PARAMETER  (PCURVL=0,   PRQSVL=1)

      INTEGER   USEPRM, ISIZ,IDUM1, PCL1,PCL2,PCL3
      REAL      ROTMT(3,3), ROTMT3(4,4), MAPMT(3,3), MAPMT3(4,4)
      REAL      QROTMT(4,4), QMAPMT(4,4)
      REAL      VWCP0(6), VWCP1(6), VWCP(6)
      REAL      VWCP4(4), VWCP40(6)
      LOGICAL   STREQ, RAREQ
 
      CURCON = 'the specified view clipping limits are '//
     1         'invalid: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX'
      CALL SETVS ('153', EXPERR, EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
 
C  try 3D cases first
 
      CALL ETR3 (.5,.6,.7, ROTMT3)
      CALL ETR3 (.8,.9,.1, MAPMT3)
 
      CALL SETRVS ('.1,.9,.1,.9,.1,.9', VWCP0, ISIZ)
      CALL PSVWR3 (WKID,1,ROTMT3,MAPMT3,VWCP0,PCLIP,PCLIP,PCLIP)
 
      CALL ETR3 (.2,.3,.4, ROTMT3)
      CALL ETR3 (.3,.4,.5, MAPMT3)
 
      CALL SETRVS ('.6,.3,0.,1.,0.,1.', VWCP, ISIZ)
      CALL RSVWR3 (WKID, 1, ROTMT3,MAPMT3,VWCP,PNCLIP,PNCLIP,PNCLIP)
 
      CALL SETRVS ('0.,1.,.6,.6,0.,1.', VWCP, ISIZ)
      CALL RSVWR3 (WKID, 1, ROTMT3,MAPMT3,VWCP,PNCLIP,PNCLIP,PNCLIP)
 
      CALL SETRVS ('0.,1.,0.,1.,.6,.3', VWCP, ISIZ)
      CALL RSVWR3 (WKID, 1, ROTMT3,MAPMT3,VWCP,PNCLIP,PNCLIP,PNCLIP)
 
      CALL SETRVS ('0.,1.,.6,.3,0.,0.', VWCP, ISIZ)
      CALL RSVWR3 (WKID, 1, ROTMT3,MAPMT3,VWCP,PNCLIP,PNCLIP,PNCLIP)
 
      CALL ETR3 (.5,.6,.7, ROTMT3)
      CALL ETR3 (.8,.9,.1, MAPMT3)
 
      CALL PQVWR (WKID,1,PRQSVL,ERRIND,IDUM1,QROTMT,QMAPMT,VWCP1,
     1            PCL1,PCL2,PCL3)
      CALL CHKINQ ('pqvwr',ERRIND)
      CALL TSTIGN (STREQ('OO**')                         .AND.
     1             RAREQ(16, QROTMT, ROTMT3, 0.01, 0.01) .AND.
     2             RAREQ(16, QMAPMT, MAPMT3, 0.01, 0.01) .AND.
     3             RAREQ( 6, VWCP1,  VWCP0,  0.01, 0.01) .AND.
     4             PCL1.EQ.PCLIP.AND.PCL2.EQ.PCLIP.AND.PCL3.EQ.PCLIP)
 
C  now test 2D cases
 
      CALL ETR  (.1,.2, ROTMT)
      CALL ETR  (.3,.4, MAPMT)
 
      CALL SETRVS ('.1,.9,.1,.9,.0,1.0', VWCP40, ISIZ)
      CALL PSVWR (WKID, 1, ROTMT,MAPMT,VWCP40,PCLIP)
 
      CALL ETR  (.5,.6, ROTMT)
      CALL ETR  (.7,.8, MAPMT)
 
      CALL SETRVS ('.6,.3,0.,1.', VWCP4, ISIZ)
      CALL RSVWR (WKID, 1, ROTMT,MAPMT,VWCP4,PNCLIP)
 
      CALL SETRVS ('0.,1.,.6,.3', VWCP4, ISIZ)
      CALL RSVWR (WKID, 1, ROTMT,MAPMT,VWCP4,PNCLIP)
 
      CALL SETRVS ('.44,.44, .5,.6', VWCP4, ISIZ)
      CALL RSVWR (WKID, 1, ROTMT,MAPMT,VWCP4,PNCLIP)
 
      CALL ETR3 (.1,.2,0.0, ROTMT3)
      CALL ETR3 (.3,.4,0.0, MAPMT3)
 
      CALL PQVWR (WKID,1,PRQSVL,ERRIND,IDUM1,QROTMT,QMAPMT,VWCP1,
     1            PCL1,PCL2,PCL3)
      CALL CHKINQ ('pqvwr',ERRIND)
      CALL TSTIGN (STREQ('OO**')                         .AND.
     1             RAREQ(16, QROTMT, ROTMT3, 0.01, 0.01) .AND.
     2             RAREQ(16, QMAPMT, MAPMT3, 0.01, 0.01) .AND.
     3             RAREQ( 6, VWCP1,  VWCP40, 0.01, 0.01) .AND.
     4             PCL1.EQ.PCLIP.AND.PCL2.EQ.PCLIP.AND.PCL3.EQ.PCLIP)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/e04154                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E04154 (USEPRM)
 
C   E04154 tests the handling of error 154.
 
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

C  clipping indicator
      INTEGER     PNCLIP,     PCLIP
      PARAMETER  (PNCLIP=0,   PCLIP=1)

C  current/requested values
      INTEGER     PCURVL,     PRQSVL
      PARAMETER  (PCURVL=0,   PRQSVL=1)

      INTEGER   USEPRM, ISIZ,IDUM1, PCL1, PCL2, PCL3

      REAL      ROTMT(3,3), ROTMT3(4,4), MAPMT(3,3), MAPMT3(4,4)
      REAL      QROTMT(4,4), QMAPMT(4,4)
      REAL      VWCP0(6),VWCP(6),VWCP1(6)
      REAL      VWCP4(4),VWCP40(6)

      LOGICAL   STREQ, RAREQ
 
      CURCON = 'the specified view clipping limits are not within '//
     1         'NPC range'
      CALL SETVS ('154', EXPERR, EXPSIZ)
      ERRSRS = '5'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
 
C  try 3D cases first
 
      CALL ETR3 (.5,.6,.7, ROTMT3)
      CALL ETR3 (.8,.9,.1, MAPMT3)
 
      CALL SETRVS ('.1,.9,.1,.9,.1,.9', VWCP0, ISIZ)
      CALL PSVWR3 (WKID,1,ROTMT3,MAPMT3,VWCP0,PNCLIP,PNCLIP,PNCLIP)
 
      CALL ETR3 (.2,.3,.4, ROTMT3)
      CALL ETR3 (.3,.4,.5, MAPMT3)
 
      CALL SETRVS ('-.1,1.,0.,1.,0.,1.', VWCP, ISIZ)
      CALL RSVWR3 (WKID,1,ROTMT3,MAPMT3,VWCP,PCLIP,PCLIP,PCLIP)
 
      CALL SETRVS ('0.,1.,0.,1.1,0.,1.', VWCP, ISIZ)
      CALL RSVWR3 (WKID,1,ROTMT3,MAPMT3,VWCP,PCLIP,PCLIP,PCLIP)
 
      CALL SETRVS ('0.,1.,0.,1.,-0.1,1.1', VWCP, ISIZ)
      CALL RSVWR3 (WKID,1,ROTMT3,MAPMT3,VWCP,PCLIP,PCLIP,PCLIP)
 
      CALL ETR3 (.5,.6,.7, ROTMT3)
      CALL ETR3 (.8,.9,.1, MAPMT3)
 
      CALL PQVWR (WKID,1,PRQSVL,ERRIND,IDUM1,QROTMT,QMAPMT,VWCP1,
     1            PCL1,PCL2,PCL3)
      CALL CHKINQ ('pqvwr',ERRIND)
      CALL TSTIGN (STREQ('OO**')                         .AND.
     1             RAREQ(16, QROTMT, ROTMT3, 0.01, 0.01) .AND.
     2             RAREQ(16, QMAPMT, MAPMT3, 0.01, 0.01) .AND.
     3             RAREQ( 6, VWCP1,  VWCP0,  0.01, 0.01) .AND.
     4             PCL1.EQ.PNCLIP.AND.PCL2.EQ.PNCLIP.AND.PCL3.EQ.PNCLIP)
 
C  now test 2D cases
 
      CALL ETR  (.1,.2, ROTMT)
      CALL ETR  (.3,.4, MAPMT)
 
      CALL SETRVS ('.1,.9,.1,.9,.0,1.0', VWCP40, ISIZ)
      CALL PSVWR (WKID,1,ROTMT,MAPMT,VWCP40,PCLIP)
 
      CALL ETR  (.5,.6, ROTMT)
      CALL ETR  (.7,.8, MAPMT)
 
      CALL SETRVS ('-0.1,1.,0.,1.', VWCP4, ISIZ)
      CALL RSVWR (WKID,1,ROTMT,MAPMT,VWCP4,PNCLIP)
 
      CALL SETRVS ('0.1,1.,0.,1.1', VWCP4, ISIZ)
      CALL RSVWR (WKID,1,ROTMT,MAPMT,VWCP4,PNCLIP)
 
      CALL SETRVS ('-.1,1.,0.,1.1', VWCP4, ISIZ)
      CALL RSVWR (WKID,1,ROTMT,MAPMT,VWCP4,PNCLIP)
 
      CALL ETR3 (.1,.2,0.0, ROTMT3)
      CALL ETR3 (.3,.4,0.0, MAPMT3)
 
      CALL PQVWR (WKID,1,PRQSVL,ERRIND,IDUM1,QROTMT,QMAPMT,VWCP1,
     1            PCL1,PCL2,PCL3)
      CALL CHKINQ ('pqvwr',ERRIND)
      CALL TSTIGN (STREQ('OO**')                         .AND.
     1             RAREQ(16, QROTMT, ROTMT3, 0.01, 0.01) .AND.
     2             RAREQ(16, QMAPMT, MAPMT3, 0.01, 0.01) .AND.
     3             RAREQ( 6, VWCP1,  VWCP40, 0.01, 0.01) .AND.
     4             PCL1.EQ.PCLIP.AND.PCL2.EQ.PCLIP.AND.PCL3.EQ.PCLIP)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/e04156                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/e04157                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E04157 (USEPRM)
 
C   E04157 tests the handling of error 157.
 
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
 
      INTEGER    SPECWT, USEPRM, IDUM1, IDUM2, IDUM3, IDUM4
      REAL       DX3,DY3,DZ3,DX2,DY2,XX,YY,ZZ,RDUMA(6),RDUMB(6)
      REAL       RDUMC(6),RDUMD(4),RDUME(4),RDUMF(4)
      REAL       WKVP0(6),WKVP1(6),WKVP(6),WKVP4(4)
      LOGICAL    STREQ, APPEQ, RAREQ
 
      CURCON = 'the specified workstation viewport is not within '//
     1         'display space'
      CALL SETVS ('157', EXPERR, EXPSIZ)
      ERRSRS = '7'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQDSP3 (SPECWT,ERRIND,IDUM1,DX3,DY3,DZ3,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqdsp3', ERRIND)
      CALL PQDSP  (SPECWT,ERRIND,IDUM1,DX2,DY2,IDUM2,IDUM3)
      CALL CHKINQ ('pqdsp', ERRIND)
 
      XX = DX3/2.
      YY = DY3/2.
      ZZ = DZ3/2.
 
C 3D
      CALL DS3 (0.,XX,0.,YY,0.,ZZ,WKVP0)
      CALL PSWKV3 (WKID, WKVP0)
 
      CALL DS3 (-0.1,DX3,0.,DY3,0.,DZ3,WKVP)
      CALL RSWKV3 (WKID, WKVP)
 
      CALL DS3 (0.,DX3,0.,DY3+0.1,0.,DZ3,WKVP)
      CALL RSWKV3 (WKID, WKVP)
 
      CALL DS3 (0.,DX3,0.,DY3,-0.1,DZ3+0.1, WKVP)
      CALL RSWKV3 (WKID, WKVP)
 
      CALL PQWKT3 (WKID,ERRIND,IDUM1,RDUMA,RDUMB,WKVP1,RDUMC)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. RAREQ(6,WKVP1,WKVP0,0.01,0.01))
 
C 2D
      XX = DX2/2.
      YY = DY2/2.
      CALL PSWKV (WKID, 0.,XX,0.,YY)
 
      CALL RSWKV (WKID, -0.1,DX2,0.,DY2)
      CALL RSWKV (WKID, 0.,DX2,0.,DY2+0.1)
      CALL RSWKV (WKID, -0.1,DX2,0.,DY2+0.1)
 
      CALL PQWKT (WKID,ERRIND,IDUM1,RDUMD,RDUME,WKVP4,RDUMF)
      CALL CHKINQ ('pqwkt',ERRIND)
      CALL TSTIGN (STREQ('OO**')                .AND.
     1             APPEQ(WKVP4(1),0.,0.01,0.01) .AND.
     2             APPEQ(WKVP4(2),XX,0.01,0.01) .AND.
     3             APPEQ(WKVP4(3),0.,0.01,0.01) .AND.
     4             APPEQ(WKVP4(4),YY,0.01,0.01))
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.04/ds3                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE DS3 (R1,R2,R3,R4,R5,R6, ARRAY)
 
C  Set an array with six real numbers
 
      REAL R1,R2,R3,R4,R5,R6,ARRAY(6)
 
      ARRAY(1) = R1
      ARRAY(2) = R2
      ARRAY(3) = R3
      ARRAY(4) = R4
      ARRAY(5) = R5
      ARRAY(6) = R6
 
      END
