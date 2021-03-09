C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.03/02                           *
C  *    TEST TITLE : Error indicator = 101                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

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

      INTEGER   IX, IVAL1, IVAL2, IVAL3, INDEX1, NINDEX, THIS
      REAL      RA10(10), RVAL1, RA6(6), RA44(4,4)
      REAL      RB44(4,4), RVAL2
      
      CALL INITGL ('09.02.03/02')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified representation has not been defined'
      ERRSRS = '2'
      CALL SETVS ('101', EXPERR, EXPSIZ)
  
      CALL POPWK (WKID, CONID,  WTYPE)

      CALL PQEVWI (WKID, 0, ERRIND, NINDEX, IVAL1)
      CALL CHKINQ ('pqevwi', ERRIND)
      INDEX1 = 1
      DO 50 IX = 1, NINDEX
         CALL PQEVWI (WKID, IX, ERRIND, IVAL1, THIS)
         CALL CHKINQ ('pqevwi', ERRIND)
         IF (THIS.GT.INDEX1) INDEX1=THIS
50    CONTINUE          
      INDEX1 = INDEX1 + 1
      CALL RQVWR (WKID, INDEX1, 0, ERRIND, IVAL1, RA44, RB44, RA6,
     1            IVAL1, IVAL2, IVAL3)

      CALL PQEPLI (WKID, 0, ERRIND, NINDEX, IVAL1)
      CALL CHKINQ ('pqepli', ERRIND)
      INDEX1 = 1
      DO 150 IX = 1, NINDEX
         CALL PQEPLI (WKID, IX, ERRIND, IVAL1, THIS)
         CALL CHKINQ ('pqepli', ERRIND)
         IF (THIS.GT.INDEX1) INDEX1=THIS
150   CONTINUE         
      INDEX1 = INDEX1+1
      CALL RQPLR (WKID, INDEX1, 0, ERRIND, IVAL1, RVAL1, IVAL2) 

      CALL PQEPMI (WKID, 0, ERRIND, NINDEX, IVAL1)
      CALL CHKINQ ('pqepmi', ERRIND)
      INDEX1 = 1
      DO 250 IX = 1, NINDEX
         CALL PQEPMI (WKID, IX, ERRIND, IVAL1, THIS)
         CALL CHKINQ ('pqepmi', ERRIND)
         IF (THIS.GT.INDEX1) INDEX1=THIS
250   CONTINUE
      INDEX1 = INDEX1+1
      CALL RQPMR (WKID, INDEX1, 0, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL PQETXI (WKID, 0, ERRIND, NINDEX, IVAL1)
      CALL CHKINQ ('pqetxi', ERRIND)
      INDEX1 = 1
      DO 350 IX = 1, NINDEX
         CALL PQETXI (WKID, IX, ERRIND, IVAL1, THIS)
         CALL CHKINQ ('pqetxi', ERRIND)
         IF (THIS.GT.INDEX1) INDEX1=THIS
350   CONTINUE
      INDEX1 = INDEX1+2
      CALL RQTXR (WKID, INDEX1, 0, ERRIND, IVAL1, IVAL2, RVAL1, RVAL2,
     1            IVAL3)

      CALL PQEII (WKID, 0, ERRIND, NINDEX, IVAL1)
      CALL CHKINQ ('pqeii', ERRIND)
      INDEX1 = 1
      DO 450 IX = 1, NINDEX
         CALL PQEII (WKID, IX, ERRIND, IVAL1, THIS)
         CALL CHKINQ ('pqeii', ERRIND)
         IF (THIS.GT.INDEX1) INDEX1=THIS
450   CONTINUE
      INDEX1 = INDEX1+10
      CALL RQIR (WKID, INDEX1, 0, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL PQEEDI (WKID, 0, ERRIND, NINDEX, IVAL1)
      CALL CHKINQ ('pqeedi', ERRIND)
      INDEX1 = 1
      DO 550 IX = 1, NINDEX
         CALL PQEEDI (WKID, IX, ERRIND, IVAL1, THIS)
         CALL CHKINQ ('pqeedi', ERRIND)
         IF (THIS.GT.INDEX1) INDEX1=THIS
550   CONTINUE
      INDEX1 = INDEX1+1
      CALL RQEDR (WKID, INDEX1, 0, ERRIND, IVAL1, IVAL2, RVAL1, IVAL3)

      CALL PQECI (WKID, 0, ERRIND, NINDEX, IVAL1)
      CALL CHKINQ ('pqeci', ERRIND)
      INDEX1 = 1
      DO 750 IX = 1, NINDEX
         CALL PQECI (WKID, IX, ERRIND, IVAL1, THIS)
         CALL CHKINQ ('pqeci', ERRIND)
         IF (THIS.GT.INDEX1) INDEX1=THIS
750   CONTINUE
      INDEX1 = INDEX1+1
      CALL RQCR (WKID, INDEX1, 10, 0, ERRIND, IVAL1, RA10)

      CALL ENDIT

      END
