C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.02/02                           *
C  *    TEST TITLE : Error indicator = 54                  *
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

      INTEGER    WKID1, IVAL1, IVAL2, IVAL3, IVAL4, IA(10), IB(10)
      INTEGER    IA1010(10,10)
      REAL   RVAL1, RA4(4), RB4(4), RC4(4), RD4(4), RA6(6), RB6(6)
      REAL   RC6(6), RD6(6), RA44(4,4), RB44(4,4), RA10(10)

      CALL INITGL ('09.02.02/02')
      CALL XPOPPH (ERRFIL, MEMUN)
      CURCON = 'the specified workstation is not open'
      CALL SETVS ('54,3', EXPERR, EXPSIZ)
      ERRSRS = '3'

C  no open workstation  
      CALL RQWKC (WKID, ERRIND, IVAL1, IVAL2)

      CALL RQVWR (WKID, 1, 0, ERRIND, IVAL1, RA44, RB44, RA6, IVAL2,
     1            IVAL3, IVAL4)

      CALL RQPOST (WKID, 0, ERRIND, IVAL1, IVAL2, RVAL1)

      CALL RQEPLI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQPMR (WKID, 1, 0, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQETXI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQIR (WKID, 1, 0, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQEPAI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQPAR (WKID, 1, 1, 10,10, ERRIND, IVAL1, IVAL2, IA1010)

      CALL RQCMD (WKID, ERRIND, IVAL1)

      CALL RQECI (WKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQHLFT (WKID, 10, 10, ERRIND, IVAL1, IA, IVAL2, IB)

      CALL RQWKT3 (WKID, ERRIND, IVAL1, RA6, RB6, RC6, RD6)

C  an open workstation exists
      CALL POPWK (WKID, CONID, WTYPE)
      WKID1 = WKID + 1
      CALL SETVS ('54', EXPERR, EXPSIZ)

      CALL RQEVWI (WKID1, 0, ERRIND, IVAL1, IVAL2)

      CALL RQHRM (WKID1, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQDUS (WKID1, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)

      CALL RQPLR (WKID1, 1, 0, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQEPMI (WKID1, 0, ERRIND, IVAL1, IVAL2)

      CALL RQPMR (WKID1, 1, 1, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQEII (WKID1, 0, ERRIND, IVAL1, IVAL2)

      CALL RQEEDI (WKID1, 0, ERRIND, IVAL1, IVAL2)

      CALL RQEDR (WKID1, 1, 1, ERRIND, IVAL1, IVAL2, RVAL1, IVAL3)

      CALL RQCR (WKID1, 1, 10, 0, ERRIND, IVAL1, RA10)

      CALL RQIVFT (WKID1, 10, 10, ERRIND, IVAL1, IA, IVAL2, IB)

      CALL RQWKT (WKID1, ERRIND, IVAL1, RA4, RB4, RC4, RD4)

      CALL ENDIT

      END
