C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.04/06                           *
C  *    TEST TITLE : Error indicator = 160                 *
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

      REAL    VRPX, VRPY, VRPZ, VPNX, VPNY, VPNZ, VUPX, VUPY, VUPZ
      REAL    RA44(4,4), RA33(3,3)      

      CALL INITGL ('09.02.04/06')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the view up vector has length zero'
      ERRSRS = '6'
      CALL SETVS ('160', EXPERR, EXPSIZ)

      VRPX = -3.24
      VRPY = 37.737
      VRPZ = 11.2
      VPNX = 62.21
      VPNY = 45.67
      VPNZ = -25.98
      VUPX = 0.
      VUPY = 0.
      VUPZ = 0.
      CALL REVOM3 (VRPX,VRPY,VRPZ, VPNX,VPNY,VPNZ, VUPX,VUPY,VUPZ, 
     1             ERRIND, RA44)

      VRPX = -3.24
      VRPY = 37.737
      CALL REVOM (VRPX,VRPY, VUPX,VUPY, ERRIND, RA33)

      CALL ENDIT

      END

