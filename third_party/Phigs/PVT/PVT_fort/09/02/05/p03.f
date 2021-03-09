C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.05/03                           *
C  *    TEST TITLE : Error indicator = 203                 *
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

      INTEGER      IVAL1, IRA210(2,10), IDUM, ISIZ, STPATH(2,1)
      INTEGER      I1(5),I2(5),I3(5),I4(5),I5(5),I6(5),I7(5),I8(5)
      REAL         PX(1),PY(1),PZ(1)
     
C   clipping indicator
      INTEGER      PNCLIP,     PCLIP
      PARAMETER   (PNCLIP=0,   PCLIP=1)

      DATA PX/1./,PY/1./,PZ/1./

      CALL INITGL ('09.02.05/03')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified starting path is not found in CSS'
      ERRSRS = '3'
      CALL SETVS ('203', EXPERR, EXPSIZ)

      CALL POPST (101)
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (102)
      CALL PPM3 (1, PX, PY, PZ)
      CALL PCLST

      CALL SETVS ('101,2', STPATH, ISIZ)
      CALL RISS3 (1.,1.,1., 0.1, 1, STPATH,PNCLIP,1,
     1            1,I1,I2,I3,I4,  1,I5,I6,I7,I8,
     2            10, ERRIND, IVAL1,IRA210)

      CALL SETVS ('102,2', STPATH, ISIZ)
      CALL RISS3 (1.,1.,1.,0.1,1,STPATH,PNCLIP,1,
     1            1,I1,I2,I3,I4,  1,I5,I6,I7,I8,
     2            10, ERRIND, IVAL1,IRA210)

      CALL SETVS ('103,1', STPATH, ISIZ)
      CALL RISS3 (1.,1.,1.,0.1,1,STPATH,PNCLIP,1,
     1            1,I1,I2,I3,I4,  1,I5,I6,I7,I8,
     2            10, ERRIND, IVAL1,IRA210)
 
      CALL PDST (102)
      CALL POPST (102)
      CALL PPM (1, PX, PY)
      CALL PCLST

      CALL SETVS ('101,2', STPATH, ISIZ)
      CALL RISS (1.,1.,0.1,1,STPATH,PNCLIP,1,
     1           1,I1,I2,I3,I4,  1,I5,I6,I7,I8,
     2           10,ERRIND,IVAL1,IRA210)

      CALL SETVS ('102,2', STPATH, ISIZ)
      CALL RISS (1.,1.,0.1,1,STPATH,PNCLIP,1,
     1           1,I1,I2,I3,I4,  1,I5,I6,I7,I8,
     2           10,ERRIND,IVAL1,IRA210)

      CALL SETVS ('103,1', STPATH, ISIZ)
      CALL RISS (1.,1.,0.1,1,STPATH,PNCLIP,1,
     1           1,I1,I2,I3,I4,  1,I5,I6,I7,I8,
     2           10,ERRIND,IVAL1,IRA210)

      CALL ENDIT

      END
