C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.10/03                           *
C  *    TEST TITLE : Error indicator = 2002                *
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

      INTEGER   SPECWT, ARNM, NUMBER, NUMHAT, IA210(2,10)
      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4,IDUM5
      REAL      RDUM1,RDUM2

      CALL INITGL ('09.02.10/03')

      CALL XPOPPH (ERRFIL, MEMUN)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CURCON = 'list or set element is not available'
      CALL SETVS ('2002', EXPERR,EXPSIZ)
      ERRSRS = '3'

      CALL PQEWK (0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqewk', ERRIND)
      CALL RQEWK (NUMBER+1, ERRIND, IDUM1, IDUM2)

      CALL RQPHF (-1, ERRIND, IDUM1, IDUM1, IDUM1, IDUM1, IDUM2,
     1            IDUM1, IDUM1)

      CALL PQMCLF (0, ERRIND, IDUM1, NUMBER, IDUM1)
      CALL CHKINQ ('pqmclf', ERRIND)
      CALL RQMCLF (NUMBER+10, ERRIND, IDUM1, IDUM1, IDUM1)

      CALL RQOPWK (-1, ERRIND, IDUM1, IDUM1)

      CALL POPST (100)
      CALL PTX (0.5, 0.5, 'TEXT100')
      CALL PEXST (102)
      CALL PCLST
      CALL POPST (102)
      CALL PTX (0.3,0.3, 'TEXT102')
      CALL PCLST
      CALL RQSID (3, ERRIND, IDUM1, IDUM2)

      CALL AVARNM (ARNM)
      CALL POPARF (11, ARNM)
      CALL RQARF (-1, ERRIND, IDUM1, IDUM1, IDUM1)

      CALL PARAST (11)
      CALL PQCST (11, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqcst', ERRIND)
      CALL RQCST (11, NUMBER+1, ERRIND, IDUM1, IDUM1)

      CALL PCLARF (11)

      CALL PQEVWI (WKID, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
      CALL RQEVWI (WKID, NUMBER+1, ERRIND, IDUM1, IDUM2)

      CALL PPOST  (WKID, 100, 0.5)
      CALL RQPOST (WKID, 2, ERRIND, IDUM1, IDUM2, RDUM1)

      CALL PQEPLI (WKID, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqepli', ERRIND)
      CALL RQEPLI (WKID, NUMBER+1, ERRIND, IDUM1, IDUM2)

      CALL PQETXI (WKID, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqetxi', ERRIND)
      CALL RQETXI (WKID, NUMBER+1, ERRIND, IDUM1, IDUM2)

      CALL RQEEDI (WKID, -2, ERRIND, IDUM1, IDUM2)

      CALL PQECI (WKID, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      CALL RQECI (WKID, NUMBER+1, ERRIND, IDUM1, IDUM2)

      CALL PQHRIF (SPECWT, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqhrif', ERRIND)
      CALL RQHRIF (SPECWT, NUMBER+1, ERRIND, IDUM1, IDUM2)

      CALL RQHRMF (SPECWT, -1, ERRIND, IDUM1, IDUM2)

      CALL RQPMF (SPECWT, -1, ERRIND, IDUM1, IDUM2, IDUM3,
     1            RDUM1, RDUM1, RDUM1, IDUM4)

      CALL PQANF (SPECWT, 0, ERRIND, NUMBER, IDUM1, IDUM2, 
     1            RDUM1, RDUM2)
      CALL CHKINQ ('pqanf', ERRIND)
      CALL RQANF (SPECWT, NUMBER+1, ERRIND, IDUM1,IDUM2,IDUM3, 
     1            RDUM1, RDUM2)

      CALL PQIF (SPECWT, 0, 0, ERRIND, NUMBER, IDUM1, NUMHAT, IDUM2,
     1           IDUM3)
      CALL CHKINQ ('pqif', ERRIND)
      CALL RQIF (SPECWT, -1, 0, ERRIND, IDUM1, IDUM2, IDUM3, IDUM4,
     1           IDUM5)
      CALL RQIF (SPECWT, 0, NUMHAT+1, ERRIND, IDUM1, IDUM2, 
     1           IDUM3, IDUM4, IDUM5)

      CALL PQCMDF (SPECWT, 0, ERRIND, NUMBER, IDUM1, IDUM2)
      CALL CHKINQ ('pqcmdf', ERRIND)
      CALL RQCMDF (SPECWT, NUMBER+1, ERRIND, IDUM1, IDUM2, IDUM3)

      CALL PQEGDP (SPECWT, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqegdp', ERRIND)
C  error 2002 applies only to non-empty lists and sets
      IF (NUMBER .GT. 0) THEN
         CALL RQEGDP (SPECWT, NUMBER+1, ERRIND, IDUM1, IDUM2)
      ENDIF
                                                 
      CALL PQWKPO (100, 0, ERRIND, NUMBER, IDUM1)
      CALL CHKINQ ('pqwkpo', ERRIND)
      CALL RQWKPO (100, NUMBER+1, ERRIND, IDUM1, IDUM2)
                                                             
      CALL PQPDE (100,0,0,10,0, ERRIND, NUMBER, IDUM2, IA210)
      CALL CHKINQ ('pqpde', ERRIND)
      CALL RQPDE (100,0,0,10,NUMBER+1, ERRIND, IDUM1, IDUM2, IA210)

      CALL ENDIT

      END

