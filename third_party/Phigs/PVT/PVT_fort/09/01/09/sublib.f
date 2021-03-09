C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.09/e09401                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E09401 (USEPRM)
 
C  E09401 tests the handling of error 401.
 
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
 
      INTEGER    USEPRM, IX, MAXARF, ARNM, NUMARF
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6,IDUM7
      LOGICAL    STREQ
 
      CURCON = 'opening this archive file would exceed the maximum '//
     1         'number of simultaneously open archive files'
      CALL SETVS ('401', EXPERR, EXPSIZ)
      ERRSRS = '2'
      CALL ESETUP (USEPRM)
 
      CALL PQPHF (IDUM1,ERRIND,IDUM2,MAXARF,IDUM3,IDUM4,IDUM5,IDUM6,
     1            IDUM7)
      CALL CHKINQ ('pqphf', ERRIND)
 
      DO 100 IX = 1, MAXARF
         CALL AVARNM (ARNM)
         CALL POPARF (IX, ARNM)
100   CONTINUE
 
      CALL AVARNM (ARNM)
      CALL ROPARF (MAXARF+1, ARNM)
      CALL PQARF (0, ERRIND, NUMARF, IDUM1, IDUM2)
      CALL CHKINQ ('pqarf', ERRIND)
      CALL TSTIGN (STREQ('O**O') .AND. NUMARF.EQ.MAXARF)
 
      DO 150 IX = 1, MAXARF
         CALL PCLARF (IX)
150   CONTINUE
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.09/e09402                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E09402 (USEPRM)
 
C   E09402 tests the handling of error 402.
 
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

      INTEGER    USEPRM, ARID, ARNM1, ARNM2, NARF, QARID,QARNM
      LOGICAL    STREQ
 
      CURCON = 'the archive file identifier is already in use'
      CALL SETVS ('402', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)
 
      ARID = 11
      CALL AVARNM (ARNM1)
      CALL POPARF (ARID, ARNM1)
      CALL AVARNM (ARNM2)
      CALL ROPARF (ARID, ARNM2)
 
      CALL PQARF (1, ERRIND, NARF, QARID, QARNM)
      CALL TSTIGN (STREQ('O**O')   .AND.
     1             ERRIND.EQ.0     .AND.
     2             NARF .EQ.1      .AND.
     3             QARID.EQ.ARID   .AND.
     4             QARNM.EQ.ARNM1)
 
      CALL PCLARF (ARID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.09/e09404                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E09404 (USEPRM)
 
C  E09404 tests the handling of error 404.
 
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
 
      INTEGER   USEPRM,ARID,ARID1,ARNM,ISIZ,STLIST(10)
      INTEGER   OSIZ,OTLIST(10), NARF, QARID, QARNM
      LOGICAL   STREQ
 
      CURCON = 'the specified archive file is not open'
      CALL SETVS ('404,7',EXPERR,EXPSIZ)
      ERRSRS = '5'
      CALL ESETUP (USEPRM)
 
      ARID = 11
      CALL CREST
      CALL SETVS ('100,101', STLIST, ISIZ)
 
      CALL RCLARF (ARID)
      CALL TSTIGN (STREQ('O**C'))

      CALL RARST (ARID, ISIZ, STLIST)
      CALL TSTIGN (STREQ('O**C'))
 
      CALL RRSID (ARID, 10, OSIZ, OTLIST)
 
      CALL RREST (ARID, ISIZ, STLIST)
 
      CALL RRAST (ARID)
      CALL TSTIGN (STREQ('O**C'))
 
      CALL RDSTAR (ARID, ISIZ, STLIST)
 
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
      ARID1 = ARID + 1
 
      CALL RARSN (ARID1, ISIZ, STLIST)
 
      CALL RARAST (ARID1)
 
      CALL RRESN (ARID1, ISIZ, STLIST)
 
      CALL RDSNAR (ARID1, ISIZ, STLIST)
 
      CALL RDASAR (ARID1)
 
      CALL PQARF (1, ERRIND, NARF, QARID, QARNM)
      CALL TSTIGN (STREQ('O**O')   .AND.
     1             ERRIND.EQ.0     .AND.
     2             NARF .EQ.1      .AND.
     3             QARID.EQ.ARID   .AND.
     4             QARNM.EQ.ARNM)
 
      CALL PCLARF (ARID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.09/e09405                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E09405 (USEPRM)
 
C  E09405 tests the handling of error 405.
 
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
 
C  conflict resolution
      INTEGER      PCRMNT,    PCRABA,     PCRUPD
      PARAMETER   (PCRMNT=0,  PCRABA=1,   PCRUPD=2)
C  structure network source
      INTEGER      PCSS,      PARCHV
      PARAMETER   (PCSS=0,    PARCHV=1)
 
      INTEGER   USEPRM,IX,ISIZ,ARID,ARNM,IDUM1,STLIST(10)
      INTEGER   NSTCFT,STCFLT(10), NST,STRID
      LOGICAL   STREQ
 
      CURCON = 'name conflict occurs while conflict ' //
     2         'resolution flag has value ABANDON'
      CALL SETVS ('405', EXPERR, EXPSIZ)
      ERRSRS = '6'
      CALL ESETUP (USEPRM)
 
      ARID = 11
      CALL CREST
      CALL PSCNRS (PCRABA, PCRABA)
 
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
 
      CALL SETVS ('100',  STLIST, ISIZ)
 
      CALL RARST (ARID, ISIZ, STLIST)
      CALL PQCST (ARID, 0, ERRIND, NSTCFT, IDUM1)
      CALL CHKINQ ('pqcst', ERRIND)
      DO 100 IX = 1, NSTCFT
         CALL PQCST (ARID, IX, ERRIND, IDUM1,STCFLT(IX))
         CALL CHKINQ ('pqcst', ERRIND)
100   CONTINUE
      CALL SRTIAR (2, STCFLT)
      CALL TSTIGN (STREQ('O**O')      .AND.
     1             NSTCFT.EQ.2        .AND.
     2             STCFLT(1).EQ.100   .AND.
     3             STCFLT(2).EQ.101)
 
      CALL RARSN (ARID, ISIZ, STLIST)
 
      CALL RARAST (ARID)
 
      CALL RREST (ARID, ISIZ, STLIST)
 
      CALL RRESN (ARID, ISIZ, STLIST)
      CALL PQCSTN (ARID, 100, PARCHV, 0,ERRIND,NSTCFT,IDUM1)
      CALL CHKINQ ('pqcstn', ERRIND)
      DO 150 IX =1 , NSTCFT
         CALL PQCSTN (ARID,100,PARCHV,IX, ERRIND,IDUM1,STCFLT(IX))
         CALL CHKINQ ('pqcstn', ERRIND)
150   CONTINUE
      CALL SRTIAR (2, STCFLT)
      CALL TSTIGN (STREQ('O**O')      .AND.
     1             NSTCFT.EQ.2        .AND.
     2             STCFLT(1).EQ.100   .AND.
     2             STCFLT(2).EQ.101)

      CALL PDST (100)
      CALL RRAST (ARID)

      CALL PQSID (1, ERRIND, NST, STRID)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL TSTIGN (STREQ('O**O') .AND. NST.EQ.1 .AND. STRID.EQ.101)

      CALL PCLARF (ARID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.09/e09407                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E09407 (USEPRM)
 
C   E09407 tests the handling of error 407.
 
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
 
      INTEGER     USEPRM, ISIZ, IDUM1,ARID,ARNM,NSTID,STLIST(10)
      LOGICAL     STREQ
      CHARACTER   MSG*100
 
      CURCON = 'some of the specified structures do not exist on '//
     1         'the archive file'
      MSG = 'it should ignore the structures that do not exist.'
      CALL SETVS ('407', EXPERR, EXPSIZ)
      ERRSRS = '8'
      CALL ESETUP (USEPRM)
 
      ARID = 11
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
      CALL PDASAR (ARID)
      CALL CREST
 
      CALL PARAST (ARID)
      CALL SETVS ('100,102,101', STLIST, ISIZ)
 
      CALL RDSTAR (ARID, ISIZ, STLIST)
 
      CALL PDST (100)
      CALL PDST (101)
      CALL PRAST (ARID)
      CALL PQSID (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL TSTWAN (STREQ('O**O') .AND. NSTID.EQ.0, MSG)
 
      CALL CREST
 
      CALL PARAST (ARID)
      CALL SETVS ('100,102', STLIST, ISIZ)
 
      CALL RDSNAR (ARID, ISIZ, STLIST)
 
      CALL PCLARF (ARID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.09/e09408                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E09408 (USEPRM)
 
C   E09408 tests the handling of error 408.
 
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
 
C  structure status indicator
      INTEGER     PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER  (PSNOEX=0,   PSEMPT=1,   PSNEMP=2)
 
      INTEGER     USEPRM, IX, IDUM1, ISIZ,ARID,ARNM,STLIST(10)
      INTEGER     STATUS, NSTID, STIDS(10)
      LOGICAL     STREQ, SETEQ
      CHARACTER   MSG*100
 
      CURCON = 'some of the specified structures do not exist '//
     1         'on the archive file'
      MSG = 'it should create empty structures in their place.'
      CALL SETVS ('408', EXPERR, EXPSIZ)
      ERRSRS = '9'
      CALL ESETUP (USEPRM)
 
      ARID = 11
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
 
      CALL CREST
 
      CALL PARAST (ARID)
      CALL PDAS
      CALL SETVS ('100,102,101', STLIST, ISIZ)
 
      CALL RREST (ARID, ISIZ, STLIST)
      CALL PQSID (0, ERRIND, NSTID, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      DO 100 IX = 1, NSTID
         CALL PQSID (IX,ERRIND, IDUM1, STIDS(IX))
         CALL CHKINQ ('pqsid', ERRIND)
100   CONTINUE
      CALL PQSTST (102, ERRIND, STATUS)
      CALL CHKINQ ('pqstst', ERRIND)
      CALL TSTWAN (STREQ('O**O')             .AND.
     1             NSTID.EQ.3                .AND.
     2             SETEQ(3, STIDS, STLIST)   .AND.
     3             STATUS.EQ.PSEMPT, MSG)
 
      CALL PDAS
 
      CALL RRESN (ARID, ISIZ, STLIST)
 
      CALL PCLARF (ARID)
 
      CALL ENDERR
 
      END

