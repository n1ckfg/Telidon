      SUBROUTINE E03116 (USEPRM)

C   E03116 tests the handling of error 116.

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

C  type of returned value
      INTEGER      PSET,    PREALI
      PARAMETER   (PSET=0,  PREALI=1)

      INTEGER   USEPRM, COL(2,3), COLIA(2,3), COLIA1(2,3)
      INTEGER   DX,DY,DX1,DY1, SPECWT, PSIZ
      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM7,IDUM8

      LOGICAL   STREQ, IAREQ

      DATA COL/0,1,1,1,0,1/, COLIA/1,0,0,0,1,0/

      CURCON = 'one of the dimensions of pattern colour index array ' //
     1         'is less than one'
      CALL SETVS ('116', EXPERR, EXPSIZ)
      ERRSRS = '15'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,PSIZ,
     1             IDUM7,IDUM8)
      CALL CHKINQ ('pqwksl', ERRIND)
      IF (PSIZ .LT. 1) THEN
         CALL INMSG ('Skipping test for invalid pattern because ' //
     1               'workstation pattern table size is zero.')
         RETURN
      ENDIF

      DX = 0
      DY = 2
      CALL PSPAR (WKID, 1, 2,3,1,1,2,3,COL)
      CALL RSPAR (WKID, 1, DX,DY,1,1,2,3,COLIA)
      CALL PQPAR (WKID,1,PSET,2,3,ERRIND,DX1,DY1,COLIA1)
      CALL CHKINQ ('pqpar', ERRIND)
      CALL TSTIGN (STREQ('OO**')               .AND.
     1             DX1.EQ.2                    .AND.
     1             DY1.EQ.3                    .AND.
     1             IAREQ(6, COLIA1, COL))

      CALL RSPAR (WKID, 1, 2,3, 1,1, 2,0, COLIA)

      DX = 2
      DY = 0
      CALL RSPAR (WKID, 1, DX,DY, 1,1,2,3,COLIA)

      CALL PCLWK (WKID)

      CALL ENDERR

      END
