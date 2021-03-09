C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.03/03                           *
C  *    TEST TITLE : Error indicator = 102                 *
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

      INTEGER    IVAL1, IVAL2, NINDEX, SPECWT
      INTEGER    IA1010(10, 10), IVAL3, IVAL4, IVAL5
      REAL       RVAL1, RVAL2, RA10(10), RA44(4,4), RB44(4,4), RA6(6)
      REAL       RA9(9), RVAL3, RVAL4

      CALL INITGL ('09.02.03/03')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified representation has not been ' //
     1         'predefined on this workstation'
      CALL SETVS ('102', EXPERR, EXPSIZ)
      ERRSRS = '3'

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQVWF (SPECWT, ERRIND, NINDEX)
      CALL CHKINQ ('pqvwf', ERRIND)
      CALL RQPVWR (SPECWT, NINDEX+1, ERRIND,RA44,RB44,RA6,IVAL1,IVAL2,
     1             IVAL3)

      CALL PQPLF (SPECWT, 0, ERRIND, IVAL1, IVAL2, IVAL3, RVAL1, RVAL2,
     1            RVAL3, NINDEX)
      CALL CHKINQ ('pqplf', ERRIND)
      CALL RQPPLR (SPECWT, NINDEX+1, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL PQPMF (SPECWT, 0, ERRIND, IVAL1, IVAL2, IVAL3, RVAL1, RVAL2,
     1            RVAL3, NINDEX)
      CALL CHKINQ ('pqpmf', ERRIND)
      CALL RQPPMR (SPECWT, NINDEX+1, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL PQTXF (SPECWT, 0, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4,
     1            RVAL1, RVAL2, IVAL5, RVAL3, RVAL4, NINDEX)
      CALL CHKINQ ('pqtxf', ERRIND)
      CALL RQPTXR (SPECWT, NINDEX+1, ERRIND, IVAL1, IVAL2, RVAL1, RVAL2,
     1             IVAL3)

      CALL PQIF (SPECWT, 0, 0, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4,
     1           NINDEX)
      CALL CHKINQ ('pqif', ERRIND)
      CALL RQPIR (SPECWT, NINDEX+1, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL PQEDF (SPECWT, 0, ERRIND, IVAL1, IVAL2, IVAL3, RVAL2, RVAL2,
     1            RVAL3, NINDEX)
      CALL CHKINQ ('pqedf', ERRIND)
      CALL RQPEDR (SPECWT, NINDEX+1, ERRIND, IVAL1, IVAL2, RVAL1, IVAL3)

      CALL PQPAF (SPECWT, ERRIND, NINDEX)
      CALL CHKINQ ('pqpaf', ERRIND)
      CALL RQPPAR (SPECWT, NINDEX+2, 10,10, ERRIND, IVAL1,IVAL2, IA1010)

      CALL PQCF (SPECWT, ERRIND, IVAL1, IVAL2, NINDEX, RA9)
      CALL CHKINQ ('pqcf', ERRIND)
      CALL RQPCR (SPECWT, NINDEX+10, 10, ERRIND, IVAL1, RA10)

      CALL ENDIT

      END
