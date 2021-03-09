C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.01/01                           *
C  *    TEST TITLE : Error indicator = 2                   *
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
 
      INTEGER   IVAL1, IVAL2, IVAL3, IVAL4, IVAL5, IVAL6
      INTEGER   IVAL7,IVAL8,ISIZ,IA5(5), IA1010(10,10)
      INTEGER   IA6(6), IB6(6), IA2(2), IB2(2)
      REAL      RVAL1, RVAL2, RVAL3, RVAL4, RA4(4), RB4(4)
      REAL      RA33(3,3), RB33(3,3), RC44(4,4)
      REAL      RA44(4,4), RB44(4,4), RA6(6), RA2(2), RB2(2),RA9(9)
      CHARACTER CHRA6(6)*10
 
      CALL INITGL ('09.02.01/01')
 
      CURCON = 'PHIGS is closed'
      CALL SETVS ('2', EXPERR,EXPSIZ)
      ERRSRS = '1'
 
      CALL RRO (0., ERRIND, RA33)
 
      CALL IDMAT (4, RA44)
      CALL IDMAT (4, RB44)
      CALL RCOM3 (RA44, RB44, ERRIND, RC44)
 
      CALL IDMAT (3, RA33)
      CALL RTP (0.5, 0.5, RA33, ERRIND, RVAL1, RVAL2)
 
      CALL RBLTM3 (0.5, 0.5, 0.5, 0.1, -0.1, 0., 0., 1.57, -0.3,
     1             1.,2.,0.1, ERRIND, RA44)
      CALL IDMAT (4, RA44)
      CALL RCOTM (RA33, 0.5, 0.5, 0.1, -0.1, 0.3, 1., 0.1, ERRIND,
     1            RB33)
 
      CALL REVOM3 (0., 0., 0., 0., 1., 0., 1., 0., 0., ERRIND, RA44)
 
      CALL SETRVS ('0.,1.,0.,1.', RA4, ISIZ)
      CALL SETRVS ('0.,0.5, 0.,0.5', RB4, ISIZ)
      CALL REVMM (RA4, RB4, ERRIND, RA33)
 
      CALL RQEWK  (0, ERRIND, IVAL1, IVAL2)
 
      CALL RQPHF  (0, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4, IVAL5,
     1             IVAL6, IVAL7)
 
      CALL RQMCLF (0, ERRIND, IVAL1, IVAL2, IVAL3)
 
      CALL RQEDM  (ERRIND, IVAL1)
 
      CALL RQOPWK (0, ERRIND, IVAL1, IVAL2)
 
      CALL RQSID  (0, ERRIND, IVAL1, IVAL2)
 
      CALL RQARF  (0, ERRIND, IVAL1, IVAL2, IVAL3)
 
      CALL RQCNRS (ERRIND, IVAL1, IVAL2)
 
      CALL RQWKCA (WTYPE, ERRIND, IVAL1)
 
      CALL RQDSP3 (WTYPE, ERRIND, IVAL1, RVAL1, RVAL2, RVAL3, IVAL2,
     1             IVAL3, IVAL4)
 
      CALL RQVWF  (WTYPE, ERRIND, IVAL1)
 
      CALL RQPVWR (WTYPE, 0, ERRIND, RA44, RB44, RA6,IVAL1, IVAL2,
     1             IVAL3)
 
      CALL RQWKCL (WTYPE, ERRIND, IVAL1)
 
      CALL RQDDUS (WTYPE, ERRIND, IVAL1, IVAL2)
 
      CALL RQPMF  (WTYPE, 0, ERRIND, IVAL1, IVAL2, IVAL3, RVAL1,
     1             RVAL2, RVAL3, IVAL4)
 
      CALL RQTXF  (WTYPE, 0, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4,
     1             RVAL1, RVAL2, IVAL5, RVAL3, RVAL4, IVAL6)
 
      CALL RQTXX  (WTYPE, 1, 0.5, 0.1, 0.5, 1, 1, 1, 'TEXT',
     1             ERRIND, RA2, RB2, RVAL1, RVAL2)
 
      CALL RQIF   (WTYPE, 0, 0, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4,
     1             IVAL5)
 
      CALL RQEDF  (WTYPE, 0, ERRIND, IVAL1, IVAL2, IVAL3, RVAL1,
     1             RVAL2, RVAL3, IVAL4)
 
      CALL RQPPAR (WTYPE, 1, 10,10, ERRIND, IVAL1, IVAL2, IA1010)
      CALL RQCMDF (WTYPE, 0, ERRIND, IVAL1, IVAL2, IVAL3)
 
      CALL RQCF   (WTYPE, ERRIND, IVAL1, IVAL2, IVAL3, RA9)
 
      CALL RQGDP  (WTYPE, 1, ERRIND, IVAL1, IA5)
 
      CALL RQEGSE (WTYPE, 0, ERRIND, IVAL1, IVAL2)
 
      CALL RQDP   (WTYPE, ERRIND, IVAL1)
 
      CALL RQWKSL (WTYPE, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4, IVAL5,
     1             IVAL6, IVAL7, IVAL8)
 
      CALL RQDSTR (WTYPE, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4, IVAL5)
 
      CALL RQOPST (ERRIND, IVAL1, IVAL2)
 
      CALL RQETS  (100, 1, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)
 
      CALL RQECO  (100,1,6,6,6, ERRIND, IVAL1, IA6, IVAL2, RA6,
     1             IVAL3, IB6, CHRA6)
 
      CALL RQSTST (100, ERRIND, IVAL1)
 
      CALL RQPAN  (100, 1, 1, 6, 1, ERRIND, IVAL1, IVAL2, IA6)
      CALL RELS   (100, 1,1,2,IA2,2,IB2, ERRIND, IVAL1, IVAL2)
 
      CALL ENDIT
 
      END
 
