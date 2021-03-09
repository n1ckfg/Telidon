      SUBROUTINE E05200 (USEPRM)

C   E05200 tests the handling of error 200.

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

      INTEGER     USEPRM, ISIZ,IDUM1,LSTST(100), NUMARC, ARF, ARNM
      INTEGER     OUTST(10), NUMCSS
      LOGICAL     STREQ, SETEQ
      CHARACTER   MSG*100

      CURCON = 'some of specified structures do not exist in CSS'
      MSG = 'it should ignore the non-existent structures.'
      ERRSRS = '1'
      CALL SETVS ('200', EXPERR, EXPSIZ)
      CALL ESETUP (USEPRM)

      ARF = 11
C  set up empty archive file
      CALL AVARNM (ARNM)
      CALL POPARF (ARF, ARNM)
      CALL PDASAR (ARF)

      LSTST(1) = 100
      LSTST(2) = 101

C  test <archive structures>

C  archive two non-existent structures
      CALL RARST (ARF, 2, LSTST)
C  check state of archive file and CSS
      CALL PQSID (0, ERRIND, NUMCSS, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL PRSID (ARF, 10, NUMARC, OUTST)
      CALL TSTWAN (STREQ('O*CO') .AND. NUMCSS.EQ.0 .AND.
     1             NUMARC.EQ.0, MSG)

C  create structure #100
      CALL POPST (100)
      CALL PTX (0.5,0.5,'TEXT')
      CALL PCLST
C  archive one existing and one non-existing structure
      CALL RARST (ARF, 2, LSTST)
C  check state of archive
      CALL PRSID (ARF, 10, NUMARC, OUTST)
      CALL TSTWAN (STREQ('O*CO') .AND. NUMARC.EQ.1 .AND.
     1             OUTST(1).EQ.100, MSG)
C  clear archive and CSS
      CALL PDAS
      CALL PDASAR (ARF)

C  test <archive structure networks>
C  archive two non-existent structures
      CALL RARSN (ARF, 2, LSTST)

C  check state of archive file and CSS
      CALL PQSID (0, ERRIND, NUMCSS, IDUM1)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL PRSID (ARF, 10, NUMARC, OUTST)
      CALL TSTWAN (STREQ('O*CO') .AND. NUMCSS.EQ.0 .AND.
     1             NUMARC.EQ.0, MSG)

C  create structure network #100 - 101
      CALL CREST

C  archive one existing and one non-existing structure network
      CALL SETVS ('102,100', LSTST, ISIZ)
      CALL RARSN (ARF, 2, LSTST)
      CALL PRSID (ARF, 10, NUMARC, OUTST)

C  check state of archive
      CALL SETVS ('100,101', LSTST, ISIZ)
      CALL TSTWAN (STREQ('O*CO') .AND. NUMARC.EQ.2 .AND.
     1             SETEQ(2, OUTST, LSTST), MSG)

      CALL PCLARF (ARF)

      CALL ENDERR

      END
