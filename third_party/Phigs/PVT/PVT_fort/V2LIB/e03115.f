      SUBROUTINE E03115 (USEPRM)

C  E03115 tests the handling of error 115.

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

C additional in the FORTRAN binding, to be used with PHIGS inquiry functions
C that return both Current and Requested values.
      INTEGER    PCURVL,     PRQSVL
      PARAMETER (PCURVL = 0, PRQSVL = 1)

C   clipping indicator
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP=0,   PCLIP=1)

      INTEGER  USEPRM,CPINDT,ISIZ, CL1,CL2,CL3, IDUM1
      REAL     ROTMT3(3,3),ROTMT4(4,4),MAPMT3(3,3),MAPMT4(4,4)
      REAL     CPLMT3(4),CPLMT4(6), XF1(4,4),XCL(6)
      LOGICAL  STREQ, RAREQ

      CURCON = 'the view index value is less than one'
      CALL SETVS ('115', EXPERR, EXPSIZ)
      ERRSRS = '14'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)

      CALL IDMAT (3, ROTMT3)
      CALL IDMAT (3, MAPMT3)
      CALL SETRVS ('0.,1.,0.,1.', CPLMT3, ISIZ)
      CPINDT = PCLIP
      CALL RSVWR (WKID, -1, ROTMT3, MAPMT3, CPLMT3, CPINDT)

      CALL ETR3 (.1,.2,.3, ROTMT4)
      CALL ETR3 (.4,.5,.6, MAPMT4)
      CALL SETRVS ('0.1, 0.9, 0.1, 0.9, 0.1, 0.9',CPLMT4, ISIZ)
      CALL RSVWR3 (WKID, 0, ROTMT4,MAPMT4,CPLMT4,PNCLIP,PNCLIP,PNCLIP)
      CALL PQVWR (WKID, 0, PRQSVL, ERRIND, IDUM1, ROTMT4,MAPMT4,
     1            CPLMT4, CL1,CL2,CL3)
      CALL CHKINQ ('pqvwr', ERRIND)
      CALL IDMAT (4, XF1)
      CALL SETRVS ('0,1,0,1,0,1', XCL, IDUM1)
      CALL TSTIGN (STREQ('OO**')                      .AND.
     1             RAREQ(16, ROTMT4,XF1, 0.001,0.001) .AND.
     2             RAREQ(16, MAPMT4,XF1, 0.001,0.001) .AND.
     3             RAREQ( 6, CPLMT4,XCL, 0.001,0.001) .AND.
     4             CL1.EQ.PCLIP .AND. CL2.EQ.PCLIP .AND. CL3.EQ.PCLIP)

      CALL PCLWK (WKID)

      CALL ENDERR

      END
