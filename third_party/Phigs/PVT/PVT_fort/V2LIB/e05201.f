      SUBROUTINE E05201 (USEPRM)

C  E05201 tests the handling of error 201.

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

C   path order
      INTEGER      PPOTOP,      PPOBOT
      PARAMETER   (PPOTOP=0,    PPOBOT=1)

      INTEGER   USEPRM, IDUM1, PATHOD, PATHDP, OL, PATH(2,10)
      INTEGER   ARF, ARNM, EXPST(10), LSTST(10), NST, IX
      LOGICAL   STREQ, SETEQ

      CURCON = 'the specified structure does not exist'
      CALL SETVS ('201', EXPERR, EXPSIZ)
      ERRSRS = '2'
      CALL ESETUP (USEPRM)

      ARF = 11

C  set up empty archive file
      CALL AVARNM (ARNM)
      CALL POPARF (ARF, ARNM)
      CALL PDASAR (ARF)

C  create structure network #100 - 101
      CALL CREST

C  archive all structures
      CALL PARAST (ARF)
      PATHOD = PPOTOP
      PATHDP = 0

C  retrieve ancestors of non-existent structure
      CALL RREPAN (ARF,102,PATHOD,PATHDP,10,0,OL,IDUM1,PATH)
C  check that state of CSS is unchanged
      CALL SETVAL ('101,100', EXPST)
      CALL PQSID (0,ERRIND,NST,IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      DO 110 IX = 1, NST
         CALL PQSID (IX,ERRIND,IDUM1,LSTST(IX))
         CALL CHKINQ ('pqsid', ERRIND)
110   CONTINUE
      CALL TSTIGN (STREQ('O**O') .AND. NST.EQ.2 .AND.
     1             SETEQ(2, LSTST, EXPST))

C  clear archive and CSS
      CALL PDAS
      CALL PDASAR (ARF)

C  create structure network #100 - 101
      CALL CREST

C  archive all structures
      CALL PARAST (ARF)
      PATHOD = PPOBOT
      PATHDP = 0

C  retrieve descendants of non-existent structure
      CALL RREPDE (ARF,102,PATHOD,PATHDP,10,0,OL,IDUM1,PATH)
C  check that state of CSS is unchanged
      CALL SETVAL ('101,100', EXPST)
      CALL PQSID (0,ERRIND,NST,IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      DO 120 IX = 1, NST
         CALL PQSID (IX,ERRIND,IDUM1,LSTST(IX))
         CALL CHKINQ ('pqsid', ERRIND)
120   CONTINUE
      CALL TSTIGN (STREQ('O**O') .AND. NST.EQ.2 .AND.
     1             SETEQ(2, LSTST, EXPST))

C  clear archive and CSS
      CALL PDAS
      CALL PDASAR (ARF)

      CALL PCLARF (ARF)

      CALL ENDERR

      END
