C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.02/04                           *
C  *    TEST TITLE : Error indicator = 59                  *
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

      INTEGER  NWKNO, TWKID, TCONID, TWTYPE
      INTEGER  IDUM1, IDUM2, IDUM3, IA10(10), IB10(10), IA5(5)
      INTEGER  IVAL1, IVAL2, IVAL3, IVAL4, IVAL5,IVAL6,IVAL7,IVAL8

      REAL     RVAL1, RVAL2, RVAL3, RVAL4, RVAL5
      REAL     RA9(9), RA10(10)

      CHARACTER*1 OWCAT, CDUM

      CALL INITGL ('09.02.02/04')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified workstation does not have output ' //
     1         'capabilities'
      CALL SETVS ('59', EXPERR, EXPSIZ)
      ERRSRS = '5'

      CALL MULTWS (0,'in',NWKNO,IDUM1,IDUM2,IDUM3,CDUM)
      IF (NWKNO .EQ. 0) THEN
         CALL INMSG ('There is no workstation without output ' //
     1               'capabilities, this test is skipped.')
         GOTO 666
      ENDIF
    
      CALL MULTWS ((NWKNO+1)/2, 'in', IDUM1, TWKID, TCONID, TWTYPE, 
     1              OWCAT)

      CALL POPWK (TWKID, TCONID, TWTYPE)
      CALL PQWKC (TWKID, ERRIND, TCONID, TWTYPE)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL RQPOST (TWKID, 0, ERRIND, IVAL1, IVAL2, RVAL1) 
                                                           
      CALL RQDUS (TWKID, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4)

      CALL RQEPLI (TWKID, 1, ERRIND, IVAL1, IVAL2)

      CALL RQPMR (TWKID, 1, 1, ERRIND, IVAL1, RVAL1, IVAL2)

      CALL RQETXI (TWKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQTXR (TWKID, 1, 0, ERRIND, IVAL1, IVAL2, RVAL1, RVAL2, 
     1               IVAL3)

      CALL RQIR (TWKID, 1, 1, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQEEDI (TWKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQEPAI (TWKID, 0, ERRIND, IVAL1, IVAL2)

      CALL RQCMD (TWKID, ERRIND, IVAL1)
      CALL RQCR (TWKID, 1, 10, 1, ERRIND, IVAL1, RA10)

      CALL RQIVFT (TWKID, 10,10, ERRIND, IVAL1, IA10, IVAL2,
     1                IB10)

      CALL RQWKCL (TWTYPE, ERRIND, IVAL1)

      CALL RQDDUS (TWTYPE, ERRIND, IVAL1, IVAL2)

      CALL RQPLF (TWTYPE, 0, ERRIND, IVAL1, IVAL2, IVAL3, RVAL1, 
     1               RVAL2, RVAL3, IVAL4)

      CALL RQPPMR (TWTYPE, 1, ERRIND, IVAL1, RVAL1, IVAL2) 

      CALL RQTXF (TWTYPE, 0, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4,
     1               RVAL1, RVAL2, IVAL5, RVAL4, RVAL5, IVAL6)

      CALL RQANF (TWKID, 0, ERRIND, IVAL1, IVAL2, IVAL3, RVAL1, 
     1               RVAL2)        

      CALL RQIF (TWKID, 0, 0, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4, 
     1              IVAL5)

      CALL RQPEDR (TWTYPE, 1, ERRIND, IVAL1, IVAL2, RVAL1, IVAL3)

      CALL RQCMDF (TWTYPE, 1, ERRIND, IVAL1, IVAL2, IVAL3)

      CALL RQCF (TWTYPE, ERRIND, IVAL1, IVAL2, IVAL3, RA9)

      CALL RQEGD3 (TWTYPE, 0, ERRIND, IVAL1, IVAL2)

      CALL RQGDP (TWTYPE, 1, ERRIND, IVAL1, IA5)

      CALL RQEGSE (TWTYPE, 0, ERRIND, IVAL1, IVAL2)
      CALL RQDP (TWTYPE, ERRIND, IVAL1)

      CALL RQWKSL (TWTYPE, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4, IVAL5,
     1                IVAL6, IVAL7, IVAL8)

      CALL RQDSTR (TWTYPE, ERRIND, IVAL1, IVAL2, IVAL3, IVAL4, IVAL5)

      CALL PCLWK (TWKID)
666   CONTINUE
      CALL ENDIT

      END
