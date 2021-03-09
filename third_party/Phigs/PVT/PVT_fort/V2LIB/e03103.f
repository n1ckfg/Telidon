      SUBROUTINE E03103 (USEPRM)

C  E03103 tests the handling of error number 103

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

C   edge flag
      INTEGER     POFF,        PON
      PARAMETER  (POFF=0,      PON=1)
C   test precision
      INTEGER     PSTRP,      PCHARP,     PSTRKP
      PARAMETER  (PSTRP=0,    PCHARP=1,   PSTRKP=2)

      INTEGER   USEPRM,MXPLY1,MXTXT1,MXEDG1,MXCOL1, TABSIZ, SPECWT
      INTEGER   IX, ISIZ, IDUM1,IDUM2,IDUM3,IDUM4
      REAL      SPEC(3)
      LOGICAL   STREQ

      CURCON = 'setting this bundle table entry would exceed the ' //
     1         'maximum number of entries allowed in the ' //
     2         'workstation bundle table'
      CALL SETVS ('103', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT,ERRIND,MXPLY1,IDUM1,MXTXT1,IDUM2,
     1             MXEDG1,IDUM3,MXCOL1,IDUM4)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (MXPLY1 .GE. 1000) THEN
         CALL OPMSG ('Initializing large polyline bundle table.')
      ENDIF

      DO 50 IX = 1, MXPLY1
         CALL PSPLR (WKID, IX, 1,1.,0)
50    CONTINUE
      CALL RSPLR (WKID, MXPLY1+1, 1, 1., 0)

      CALL PQEPLI (WKID, 0, ERRIND, TABSIZ, IDUM1)
      CALL CHKINQ ('pqepli', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. TABSIZ.EQ.MXPLY1)

      IF (MXTXT1 .GE. 1000) THEN
         CALL OPMSG ('Initializing large text bundle table.')
      ENDIF
      DO 100 IX = 1, MXTXT1
         CALL PSTXR (WKID, IX, 1, PSTRP, 1.,1.,0)
100   CONTINUE
      CALL RSTXR (WKID, MXTXT1+1, 1, PSTRP, 1.,1.,0)

      IF (MXEDG1 .GE. 1000) THEN
         CALL OPMSG ('Initializing large edge bundle table.')
      ENDIF
      DO 150 IX = 1, MXEDG1
         CALL PSEDR (WKID, IX, PON, 1,1.,0)
150   CONTINUE
      CALL RSEDR (WKID, MXEDG1+1, PON, 1, 1.,0)

      IF (MXCOL1 .GT. 1000) THEN
         CALL OPMSG ('Initializing large colour table.')
      ENDIF
      CALL SETRVS ('0.5,0.5,0.5', SPEC, ISIZ)
      DO 200 IX = 1, MXCOL1
         CALL PSCR (WKID, IX, ISIZ, SPEC)
200   CONTINUE
      CALL RSCR (WKID, MXCOL1+1, ISIZ, SPEC)

      CALL PQECI (WKID, 0, ERRIND, TABSIZ, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. TABSIZ.EQ.MXCOL1)

      CALL PCLWK (WKID)

      CALL ENDERR

      END
