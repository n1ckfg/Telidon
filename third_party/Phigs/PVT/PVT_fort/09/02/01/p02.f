C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.01/02                           *
C  *    TEST TITLE : Error indicator = 3                   *
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

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

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


      INTEGER   IVAL1, IVAL2, IVAL3, IVAL4, IA10(10), IB10(10)
      INTEGER   IA1010(10,10)
      REAL   RVAL1, RVAL2, RA4(4), RB4(4), RC4(4), RD4(4), RA44(4,4)
      REAL   RB44(4,4), RA6(6), RB6(6), RC6(6), RD6(6), RA10(10)

      CALL INITGL ('09.02.01/02')

      CURCON = 'PHIGS is closed'
      CALL SETVS ('3', EXPERR, EXPSIZ)
      ERRSRS = '2'

      CALL RQEVWI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQHRM (WKID, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQDUS (WKID, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)

      CALL RQPLR (WKID, 1, 0, ERRIND, IVAL1, RVAL1, IVAL2) 

      CALL RQEPMI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQTXR (WKID, 1, 0, ERRIND, IVAL1, IVAL2, RVAL1, RVAL2,IVAL3)        

      CALL RQEII (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQEDR (WKID, 1, 0, ERRIND, IVAL1, IVAL2, RVAL1, IVAL3)

      CALL RQEPAI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQCMD (WKID, ERRIND, IVAL1)

      CALL RQCR (WKID, 1,10, 0, ERRIND, IVAL1, RA10)

      CALL RQHLFT (WKID, 10, 10, ERRIND, IVAL1, IA10, IVAL2, IB10)

      CALL RQWKT (WKID, ERRIND, IVAL1, RA4, RB4, RC4, RD4)

      CALL XPOPPH (ERRFIL, MEMUN)
      CURCON = 'PHIGS is open but no workstation is open'

      CALL RQWKC (WKID, ERRIND, IVAL1, IVAL2)

      CALL RQVWR (WKID, 1, 0, ERRIND, IVAL1, RA44, RB44, RA6,
     1            IVAL2, IVAL3, IVAL4)

      CALL RQPOST (WKID, 0, ERRIND, IVAL1, IVAL2, RVAL1)

      CALL RQEPLI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQPMR (WKID, 1, 1, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQETXI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQIR (WKID, 1, 0, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQEEDI (WKID, 0, ERRIND, IVAL1, IVAL2) 

      CALL RQPAR (WKID, 1, 1, 10, 10, ERRIND, IVAL1, IVAL2, IA1010)

      CALL RQECI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQIVFT (WKID, 10, 10, ERRIND, IVAL1, IA10, IVAL2, IB10)

      CALL RQWKT3 (WKID, ERRIND, IVAL1, RA6, RB6, RC6, RD6)

      CALL ENDIT
      END

