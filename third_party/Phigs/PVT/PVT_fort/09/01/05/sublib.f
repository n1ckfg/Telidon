C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.05/e05200                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.05/e05201                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.05/e05205                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E05205 (USEPRM)
 
C  E05205 tests the handling of error 205.
 
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
 
      INTEGER     USEPRM, ELPNT1, ELPNT2
      REAL        XA(2), YA(2)
      LOGICAL     STREQ
 
      CURCON = 'the specified label does not exist '//
     1         'in the open structure between the element pointer '//
     2         'and the end of the structure'
      CALL SETVS ('205', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)
 
      CALL POPST (100)

      XA(1) = 0.
      XA(2) = 0.5
      YA(1) = 0.
      YA(2) = 0.5
      CALL PPL (2, XA, YA)
 
      CALL PQEP (ERRIND, ELPNT1)
      CALL CHKINQ ('pqep', ERRIND)
      CALL RSEPLB (1)
      CALL PQEP (ERRIND, ELPNT2)
      CALL CHKINQ ('pqep', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. ELPNT1.EQ.ELPNT2)
 
      CALL PLB (1)
      CALL PPL (2, XA, YA)
      CALL PLB (2)
      CALL POSEP (-1)
      CALL RSEPLB (1)
 
      CALL PCLST
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.05/e05206                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E05206 (USEPRM)
 
C  E05206 tests the handling of error 206.
 
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
 
      INTEGER     USEPRM,ELPNT1,ELPNT2
      REAL        XA(2), YA(2)
      LOGICAL     STREQ
 
      CURCON = 'one or both of the labels does not exist in the ' //
     1         'open structure between the element pointer and '  //
     2         'the end of the structure'
      CALL SETVS ('206', EXPERR, EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)
 
      XA(1) = 0.
      YA(1) = 0.5
      XA(2) = 1.
      YA(2) = 1.
 
      CALL POPST (100)
 
      CALL PQEP (ERRIND, ELPNT1)
      CALL CHKINQ ('pqep', ERRIND)
      CALL RDELLB (1, 2)
      CALL PQEP (ERRIND, ELPNT2)
      CALL CHKINQ ('pqep', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. ELPNT1.EQ.ELPNT2)
 
      CALL PPL (2, XA, YA)
      CALL PLB (1)
      CALL PPM (2, XA, YA)
      CALL PLB (2)
 
      CALL POSEP (-1)
      CALL PQEP (ERRIND, ELPNT1)
      CALL CHKINQ ('pqep', ERRIND)
      CALL RDELLB (1, 2)
      CALL PQEP (ERRIND, ELPNT2)
      CALL CHKINQ ('pqep', ERRIND)
      CALL TSTIGN (STREQ('O*O*') .AND. ELPNT1.EQ.ELPNT2)
 
      CALL PSEP (0)
      CALL RDELLB (2,4)
 
      CALL PCLST
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.05/e05207                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E05207 (USEPRM)
 
C   E05207 tests the handling of error 207.
 
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
      INTEGER   ARF, ARNM, NST, STRID
      LOGICAL   STREQ
 
      CURCON = 'the specified path depth is less than zero'
      CALL SETVS ('207', EXPERR, EXPSIZ)
      ERRSRS = '5'
      CALL ESETUP (USEPRM)

      ARF = 11
      CALL AVARNM (ARNM)
      CALL POPARF (ARF, ARNM)
 
      CALL CREST
 
      CALL PARAST (ARF)
      CALL PDAS
      CALL POPST (103)
 
      PATHOD = PPOBOT
      PATHDP = -1
      CALL RREPAN (ARF,100,PATHOD,PATHDP,10,0,OL,IDUM1,PATH)
 
C  check that state of CSS is unchanged
      CALL PQSID (1,ERRIND,NST,STRID)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL TSTIGN (STREQ('O**O') .AND. NST.EQ.1 .AND. STRID.EQ.103)
 
      PATHOD = PPOTOP
      PATHDP = -100
      CALL RREPDE (ARF,101,PATHOD,PATHDP,10,0,OL,IDUM1,PATH)
 
C  check that state of CSS is unchanged
      CALL PQSID (1,ERRIND,NST,STRID)
      CALL CHKINQ ('pqsid', ERRIND)
      CALL TSTIGN (STREQ('O**O') .AND. NST.EQ.1 .AND. STRID.EQ.103)
 
      CALL PCLARF (ARF)
      CALL PCLST

      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.05/e05208                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E05208 (USEPRM)
 
C   E05208 tests the handling of error 208.
 
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
 
      INTEGER     USEPRM, NUMBER, POSTST
      REAL        ORGPRI
      LOGICAL     STREQ, APPEQ
 
      CURCON = 'the specified display priority is out of range'
      CALL SETVS ('208', EXPERR, EXPSIZ)
      ERRSRS = '6'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL CREST
 
      CALL PPOST (WKID, 100, 0.5)
      CALL RPOST (WKID, 101, -0.1)
      CALL RPOST (WKID, 101, 1.1)
 
      CALL PQPOST (WKID, 1, ERRIND, NUMBER, POSTST, ORGPRI)
      CALL TSTIGN (STREQ('OO**') .AND. ERRIND.EQ.0 .AND.
     1             NUMBER.EQ.1   .AND.
     2             POSTST.EQ.100 .AND.
     3             APPEQ(ORGPRI, 0.5, .001,.001))
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END

