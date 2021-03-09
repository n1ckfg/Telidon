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
