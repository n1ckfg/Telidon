C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.02/03                           *
C  *    TEST TITLE : Error indicator = 57                  *
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

      INTEGER  NWKMI, TWKID, TCONID, TWTYPE
      INTEGER  IDUM1, IDUM2, IDUM3
      INTEGER  IVAL1, IVAL2, IVAL3, IVAL4, IVAL5
      REAL     RVAL1, RVAL2, RVAL3, RA4(4), RB4(4), RC4(4), RD4(6)
      REAL     RA6(6), RB6(6), RC6(6), RD6(6), RA44(4,4), RB44(4,4)
      CHARACTER*1 OWCAT, CDUM

      CALL INITGL ('09.02.02/03')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified workstation is of category MI'
      CALL SETVS ('57', EXPERR, EXPSIZ)
      ERRSRS = '4'

      CALL MULTWS (0,'n',NWKMI,IDUM1,IDUM2,IDUM3,CDUM)
      IF (NWKMI .EQ. 0) THEN
         CALL INMSG ('There is no workstation with category MI, ' //
     1               'this test is skipped.')
         GOTO 666
      ENDIF

      CALL MULTWS ((NWKMI+1)/2, 'n', IDUM1, TWKID,TCONID,TWTYPE, OWCAT)
      CALL POPWK (TWKID, TCONID, TWTYPE)
      CALL PQWKC (TWKID, ERRIND, TCONID, TWTYPE)
      CALL CHKINQ ('pqwkc', ERRIND)
      
      CALL RQEVWI (TWKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQVWR (TWKID, 1, 0, ERRIND, IVAL1, RA44, RB44, RA6,
     1               IVAL3, IVAL4, IVAL5)

      CALL RQHRM (TWKID, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQWKT3 (TWKID, ERRIND, IVAL1, RA6, RB6, RC6, RD6)

      CALL RQWKT (TWKID, ERRIND, IVAL1, RA4, RB4, RC4, RD4)

      CALL RQDSP3 (TWTYPE, ERRIND, IVAL1, RVAL1, RVAL2, RVAL3,
     1                IVAL2, IVAL3, IVAL4)

      CALL RQDSP (TWTYPE, ERRIND, IVAL1, RVAL1, RVAL2, IVAL2, IVAL3)

      CALL RQHRIF (TWTYPE, 0, ERRIND, IVAL1, IVAL2)

      CALL RQVWF (TWTYPE, ERRIND, IVAL1)

      CALL RQPVWR (TWTYPE, 1, ERRIND, RA44, RB44, RA6, IVAL1,
     1                IVAL2, IVAL3)

      CALL PCLWK (TWKID)
666   CONTINUE
      CALL ENDIT

      END
