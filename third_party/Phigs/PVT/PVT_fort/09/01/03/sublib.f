C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03100                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03100 (USEPRM)
 
C  E03100 tests the handling of error number 100
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20)
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

C  type of returned value
      INTEGER      PSET,        PREALI
      PARAMETER   (PSET=0,      PREALI=1)
 
      INTEGER   USEPRM, RNDINT, INDEX, NENTR1, NENTR2, ERRIND, IDUM1
      LOGICAL   STREQ
 
      CURCON = 'the bundle index value is less than one'
      CALL SETVS ('100', EXPERR, EXPSIZ)
      ERRSRS = '1'
      CALL ESETUP (USEPRM)
 
      CALL POPST (101)
 
      CALL RSPLI (0)
      CALL TSTIGN (STREQ('O*O*'))
 
      CALL RSTXI (-1)
 
      INDEX = RNDINT(-1, 0)
      CALL RSEDI (INDEX)
 
      CALL PCLST
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL PQEPMI (WKID, 0, ERRIND, NENTR1, IDUM1)
      CALL CHKINQ ('pqepmi', ERRIND)
 
      CALL RSPMR (WKID, 0, 1, 1.0, 0)
 
      CALL PQEPMI (WKID, 0, ERRIND, NENTR2, IDUM1)
      CALL CHKINQ ('pqepmi', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. NENTR1.EQ.NENTR2)
 
      CALL RSIR (WKID, -1, 1,1,0)
 
      INDEX = RNDINT(-1, 0)
      CALL RSEDR (WKID, INDEX, 1,1,1.,0)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03101                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03101 (USEPRM)
 
C  E03101 tests the handling of error number 101
 
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
 
C  clipping indicator
      INTEGER     PNCLIP,     PCLIP
      PARAMETER  (PNCLIP=0,   PCLIP=1)
C  relative input priority
      INTEGER     PHIGHR,     PLOWER
      PARAMETER  (PHIGHR=0,   PLOWER=1)
 
      INTEGER   USEPRM, IDUM1, NUMVDX,ISIZ,IX, V1,V11,V2
      INTEGER   VWSIZ, VDX1(300), VDX2(300)
 
      REAL      ROTMAT(3,3), MAPMAT(3,3), CPLIMT(4)
      LOGICAL   STREQ, IAREQL
 
      CURCON = 'the specified representation has not been defined'
      CALL SETVS ('101', EXPERR, EXPSIZ)
      ERRSRS = '2'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL PQEVWI (WKID, 0, ERRIND, NUMVDX, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
      IF (NUMVDX .EQ. 0) THEN
         CALL IDMAT (3, ROTMAT)
         CALL IDMAT (3, MAPMAT)
         CALL SETRVS ('0.,1.,0.,1.',CPLIMT,ISIZ)
         CALL PSVWR (WKID,1,ROTMAT,MAPMAT,CPLIMT,PCLIP)
         V1 = 2
         V11 = 3
         V2 = 1
      ELSE
         DO 50 IX = 1, NUMVDX
            CALL PQEVWI (WKID,IX,ERRIND,IDUM1,VDX1(IX))
            CALL CHKINQ ('pqevwi', ERRIND)
50       CONTINUE
         CALL SRTIAR (NUMVDX, VDX1)
         V1 = VDX1(NUMVDX) + 1
         V11 = V1 + 10
         V2 = VDX1(1)
      ENDIF
 
C  V1 and V11 are undefined; V2 is defined
 
      CALL RSVTIP (WKID, V1, V11, PLOWER)
      CALL RSVTIP (WKID, V1, V2, PHIGHR)
      CALL RSVTIP (WKID, V2, V1, PLOWER)

      CALL PQEVWI (WKID, 0, ERRIND, VWSIZ, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
      DO 60 IX = 1, VWSIZ
         CALL PQEVWI (WKID, IX, ERRIND, IDUM1, VDX2(IX))
         CALL CHKINQ ('pqevwi', ERRIND)
60    CONTINUE
 
      CALL TSTIGN (STREQ('OO**') .AND. IAREQL(NUMVDX,VDX1, VWSIZ,VDX2))
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03103                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03103 (USEPRM)
 
C  E03103 tests the handling of error number 103
 
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
 
C   edge flag
      INTEGER     POFF,        PON
      PARAMETER  (POFF=0,      PON=1)
C   test precision
      INTEGER     PSTRP,      PCHARP,     PSTRKP
      PARAMETER  (PSTRP=0,    PCHARP=1,   PSTRKP=2)
 
      INTEGER   USEPRM,MXPLY1,MXTXT1,MXEDG1,MXCOL1, TABSIZ, SPECWT
      INTEGER   IX, ISIZ, IDUM1,IDUM2,IDUM3,IDUM4
      REAL      SPEC(3)
      LOGICAL   STREQ
 
      CURCON = 'setting this bundle table entry would exceed the ' //
     1         'maximum number of entries allowed in the ' //
     2         'workstation bundle table'
      CALL SETVS ('103', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQWKSL (SPECWT,ERRIND,MXPLY1,IDUM1,MXTXT1,IDUM2,
     1             MXEDG1,IDUM3,MXCOL1,IDUM4)
      CALL CHKINQ ('pqwksl', ERRIND)
 
      IF (MXPLY1 .GE. 1000) THEN
         CALL OPMSG ('Initializing large polyline bundle table.')
      ENDIF
 
      DO 50 IX = 1, MXPLY1
         CALL PSPLR (WKID, IX, 1,1.,0)
50    CONTINUE
      CALL RSPLR (WKID, MXPLY1+1, 1, 1., 0)
 
      CALL PQEPLI (WKID, 0, ERRIND, TABSIZ, IDUM1)
      CALL CHKINQ ('pqepli', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. TABSIZ.EQ.MXPLY1)
 
      IF (MXTXT1 .GE. 1000) THEN
         CALL OPMSG ('Initializing large text bundle table.')
      ENDIF
      DO 100 IX = 1, MXTXT1
         CALL PSTXR (WKID, IX, 1, PSTRP, 1.,1.,0)
100   CONTINUE
      CALL RSTXR (WKID, MXTXT1+1, 1, PSTRP, 1.,1.,0)
 
      IF (MXEDG1 .GE. 1000) THEN
         CALL OPMSG ('Initializing large edge bundle table.')
      ENDIF
      DO 150 IX = 1, MXEDG1
         CALL PSEDR (WKID, IX, PON, 1,1.,0)
150   CONTINUE
      CALL RSEDR (WKID, MXEDG1+1, PON, 1, 1.,0)
 
      IF (MXCOL1 .GT. 1000) THEN
         CALL OPMSG ('Initializing large colour table.')
      ENDIF
      CALL SETRVS ('0.5,0.5,0.5', SPEC, ISIZ)
      DO 200 IX = 1, MXCOL1
         CALL PSCR (WKID, IX, ISIZ, SPEC)
200   CONTINUE
      CALL RSCR (WKID, MXCOL1+1, ISIZ, SPEC)
 
      CALL PQECI (WKID, 0, ERRIND, TABSIZ, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. TABSIZ.EQ.MXCOL1)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03104                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03104 (USEPRM)
 
C   E03104 tests the handling of error number 104
 
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
 
C  type of retured value
      INTEGER      PSET,        PREALI
      PARAMETER   (PSET=0,      PREALI=1)
 
      INTEGER  USEPRM, IX, NLTYP1, MXTYPE, LINETY, LINECL
      INTEGER  IDUM1,IDUM2,IDUM3, UNTYPE, THISLT, SPECWT
      REAL     LINESC, RDUM1, RDUM2, RDUM3
      LOGICAL  STREQ, APPEQ
 
      CURCON = 'the specified linetype is not available on the '//
     1         'specified workstation'
      CALL SETVS ('104', EXPERR, EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQPLF (SPECWT, 1, ERRIND, NLTYP1, MXTYPE, IDUM2, RDUM1,
     1            RDUM2, RDUM3, IDUM3)
      CALL CHKINQ ('pqplf', ERRIND)
      DO 50 IX = 1, ABS(NLTYP1)
         CALL PQPLF (SPECWT, IX, ERRIND, IDUM1, THISLT, IDUM2,
     1                  RDUM1, RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqplf', ERRIND)
         IF (THISLT .GT. MXTYPE) MXTYPE = THISLT
50    CONTINUE
      UNTYPE = MXTYPE + 1
C
      CALL PSPLR (WKID, 1, THISLT, .9, 0)
      CALL RSPLR (WKID, 1, UNTYPE,   .5, 1)
      CALL PQPLR (WKID, 1, PSET, ERRIND, LINETY,LINESC,LINECL)
      CALL CHKINQ ('pqplr',ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. LINETY.EQ.THISLT .AND.
     1             APPEQ(LINESC,.9,0.01,0.01) .AND. LINECL.EQ.0)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03105                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03105 (USEPRM)
 
C  E03105 tests the handling of error number 105
 
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
 
C  type of returned value
      INTEGER    PSET,      PREALI
      PARAMETER (PSET=0,    PREALI=1)
 
      INTEGER    USEPRM, IX, NMTYP1, MXTYPE, MARKTY,MARKCL
      INTEGER    IDUM1,IDUM2,IDUM3,UNTYPE, THISMT, SPECWT
      REAL       RDUM1, RDUM2, RDUM3, MARKSC
      LOGICAL    STREQ, APPEQ
 
      CURCON = 'the specified marker type is not available '//
     1         'on the specified workstation'
      CALL SETVS ('105', EXPERR, EXPSIZ)
      ERRSRS = '5'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQPMF (SPECWT, 1, ERRIND, NMTYP1, MXTYPE,IDUM2,RDUM1,RDUM2,
     1            RDUM3, IDUM3)
      CALL CHKINQ ('pqpmf', ERRIND)
      DO 50 IX = 1, ABS(NMTYP1)
         CALL PQPMF (SPECWT,IX,ERRIND,IDUM1,THISMT,IDUM2,RDUM1,
     1               RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqpmf',ERRIND)
         IF (THISMT .GT. MXTYPE) MXTYPE = THISMT
50    CONTINUE
      UNTYPE = MXTYPE + 1
C
      CALL PSPMR (WKID, 1, THISMT, 1., 0)
      CALL RSPMR (WKID, 1, UNTYPE,  .5,  1)
      CALL PQPMR (WKID, 1, PSET, ERRIND, MARKTY,MARKSC,MARKCL)
      CALL CHKINQ ('pqpmr', ERRIND)
 
      CALL TSTIGN (STREQ('OO**')               .AND.
     1             MARKTY.EQ.THISMT            .AND.
     2             APPEQ(MARKSC,1.,0.01,0.01)  .AND.
     3             MARKCL.EQ.0)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03106                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03106 (USEPRM)
 
C   E03106 tests the handling of error number 106
 
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
 
C  type of returned value
      INTEGER     PSET,     PREALI
      PARAMETER  (PSET=0,   PREALI=1)
C  text precision
      INTEGER     PSTRP,    PCHARP,     PSTRKP
      PARAMETER  (PSTRP=0,  PCHARP=1,   PSTRKP=2)
 
      INTEGER  USEPRM, IX,II,IP,IR,NPAIR,TXTFNT(100),TXTPRC(100)
      INTEGER  FONTIP(100), UNFONT, UNPREC, FONT1,PREC1,COLOR1, SPECWT
      INTEGER  IDUM1,IDUM2,IDUM3,IDUM4,IDUM5
      REAL     EXPAN1,SPACE1,RDUM1,RDUM2,RDUM3,RDUM4
      LOGICAL  STREQ,APPEQ
 
      CURCON = 'the specified font is not available for the '//
     1         'requested text precision on the specified '//
     2         'workstation'
      CALL SETVS ('106', EXPERR, EXPSIZ)
      ERRSRS = '6'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQTXF (SPECWT,0,ERRIND,NPAIR,IDUM1,IDUM2,IDUM3,RDUM1,RDUM2,
     1            IDUM4,RDUM3,RDUM4,IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)
      DO 50 IX = 1, NPAIR
         CALL PQTXF (SPECWT,IX,ERRIND,IDUM1,TXTFNT(IX),TXTPRC(IX),
     1               IDUM2,RDUM1,RDUM2,IDUM3,RDUM3,RDUM4,IDUM4)
         CALL CHKINQ ('pqtxf',ERRIND)
50    CONTINUE
 
      CALL PSTXR (WKID, 1, TXTFNT(1), TXTPRC(1), 1.,1.,0)
 
      DO 150 IP = PSTRKP, PSTRP, -1
         II = 0
         DO 160 IR = 1, NPAIR
            IF (TXTPRC(IR) .EQ. IP) THEN
               II = II + 1
               FONTIP(II)=TXTFNT(IR)
            ENDIF
160      CONTINUE
         IF (II .EQ. 0) GOTO 150
         CALL SRTIAR (II, FONTIP)
         UNFONT = FONTIP(II) + 1
         UNPREC = IP
         GOTO 200
150   CONTINUE
 
200   CONTINUE
      CALL RSTXR (WKID, 1, UNFONT, UNPREC,.5, .5, 0)
      CALL PQTXR (WKID, 1, PSET, ERRIND,FONT1,PREC1,EXPAN1,SPACE1,
     1            COLOR1)
      CALL CHKINQ ('pqtxr', ERRIND)
      CALL TSTIGN (STREQ('OO**')              .AND.
     1             FONT1.EQ.TXTFNT(1)         .AND.
     2             PREC1.EQ.TXTPRC(1)         .AND.
     3             APPEQ(EXPAN1,1.,0.01,0.01) .AND.
     4             APPEQ(SPACE1,1.,0.01,0.01) .AND.
     5             COLOR1.EQ.0)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03107                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03107 (USEPRM)
 
C  E03107 tests the handling of error 107
 
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
 
C  type of returned value
      INTEGER     PSET,      PREALI
      PARAMETER  (PSET=0,    PREALI=1)
C   off/on switch for edge flag and error handling
      INTEGER     POFF,      PON
      PARAMETER  (POFF=0,    PON=1)
 
      INTEGER  USEPRM, NEDTP1, MXTYPE,IX,EDGEFG, EDGETY,EDGECL
      INTEGER  IDUM1,IDUM2,IDUM3, SPECWT, UNTYPE, THISED
      REAL     RDUM1, RDUM2, RDUM3, EDGESC
      LOGICAL  STREQ,APPEQ
 
      CURCON = 'the specified edgetype is not available on the '//
     1         'specified workstation'
      CALL SETVS ('107', EXPERR, EXPSIZ)
      ERRSRS = '7'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
      CALL PQEDF (SPECWT,1, ERRIND, NEDTP1, MXTYPE,IDUM2,RDUM1,RDUM2,
     1            RDUM3, IDUM3)
      CALL CHKINQ ('pqedf', ERRIND)
      DO 50 IX = 1, ABS(NEDTP1)
         CALL PQEDF (SPECWT, IX, ERRIND, IDUM1, THISED, IDUM2, RDUM1,
     1               RDUM2, RDUM3, IDUM3)
         CALL CHKINQ ('pqedf', ERRIND)
         IF (THISED .GT. MXTYPE) MXTYPE = THISED
50    CONTINUE
      UNTYPE = MXTYPE + 1

      CALL PSEDR (WKID, 1, POFF, THISED, 1., 0)
      CALL RSEDR (WKID, 1, PON,  UNTYPE,    0.5, 1)
      CALL PQEDR (WKID, 1,PSET, ERRIND, EDGEFG, EDGETY,EDGESC,EDGECL)
      CALL CHKINQ ('pqedr', ERRIND)
      CALL TSTIGN (STREQ('OO**')                .AND.
     1             EDGEFG.EQ.POFF               .AND.
     1             EDGETY.EQ.THISED             .AND.
     2             APPEQ(EDGESC,1.0,0.01,0.01)  .AND.
     3             EDGECL.EQ.0)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03108                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03108 (USEPRM)
 
C  E03108 tests the handling of error 108
 
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
 
C  interior style
      INTEGER    PHOLLO,     PSOLID,    PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0,   PSOLID=1,  PPATTR=2, PHATCH=3, PISEMP=4)
C  type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET=0,   PREALI=1)
 
      INTEGER   USEPRM,IX,NISTY1,ISTYLE,ISINDX,ISCOLO, THISIS
      INTEGER   SPECWT, UNTYPE,IDUM1,IDUM2,IDUM3,IDUM4,IDUM5
      LOGICAL   STREQ, ISAVL(PHOLLO:PISEMP)

      DATA      ISAVL / 5 * .FALSE. /

      CALL SETVS ('108', EXPERR, EXPSIZ)
      CURCON = 'the specified interior style is not available '//
     1         'on the specified workstation'
      ERRSRS = '8'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQIF (SPECWT, 0,0,ERRIND, NISTY1, IDUM1,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqif', ERRIND)
      DO 50 IX = 1, NISTY1
         CALL PQIF (SPECWT, IX, 0, ERRIND, IDUM2, THISIS,
     1              IDUM3, IDUM4, IDUM5)
         CALL CHKINQ ('pqif', ERRIND)
         IF (THISIS.GE.PHOLLO .AND. THISIS.LE.PISEMP) THEN
            ISAVL(THISIS) = .TRUE.
         ENDIF
50    CONTINUE

      DO 60 IX = PHOLLO, PISEMP
         IF (.NOT. ISAVL(IX)) THEN
            UNTYPE = IX
            GOTO 70
         ENDIF
60    CONTINUE
      CALL INMSG ('No unavailable interior styles; test is skipped.')
      RETURN

70    CONTINUE
      CALL PSIR (WKID, 1, THISIS, 1, 0)
      CALL RSIR (WKID, 1, UNTYPE, 2, 1)
      CALL PQIR (WKID, 1, PSET, ERRIND, ISTYLE,ISINDX,ISCOLO)
      CALL CHKINQ ('pqir', ERRIND)
      CALL TSTIGN (STREQ('OO**')      .AND.
     1             ISTYLE.EQ.THISIS   .AND.
     2             ISINDX.EQ.1        .AND.
     3             ISCOLO.EQ.0)

      CALL PCLWK (WKID)

      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03110                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03110 (USEPRM)
 
C  E03110 tests the handling of error 110
 
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
 
C  colour model
      INTEGER      PRGB,   PCIE,    PHSV,    PHLS
      PARAMETER   (PRGB=1, PCIE=2,  PHSV=3,  PHLS=4)
 
      INTEGER   USEPRM, IX, UNTYPE, NCOLMD,MXMOD,IDUM1,IDUM2
      INTEGER   CMODEL, SPECWT, THISMD
      LOGICAL   STREQ

      CURCON = 'the specified colour model is not available '//
     1         'on the workstation'
      CALL SETVS ('110', EXPERR, EXPSIZ)
      ERRSRS = '9'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQCMDF (SPECWT,1, ERRIND, NCOLMD, MXMOD,IDUM2)
      CALL CHKINQ ('pqcmdf', ERRIND)
      DO 50 IX = 1, NCOLMD
         CALL PQCMDF (SPECWT,IX, ERRIND, IDUM1,THISMD,IDUM2)
         CALL CHKINQ ('pqcmdf', ERRIND)
         IF (THISMD .GT. MXMOD) MXMOD=THISMD
50    CONTINUE

      UNTYPE = MXMOD + 1
 
      CALL PSCMD (WKID, THISMD)
      CALL RSCMD (WKID, UNTYPE)
      CALL PQCMD (WKID, ERRIND, CMODEL)
      CALL CHKINQ ('pqcmd', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. CMODEL.EQ.THISMD)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03111                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03111 (USEPRM)
 
C  E03111 tests the handling of error 111
 
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
 
      INTEGER   USEPRM, IX, UNTYPE,  MXH,THISH, NHLHMD
      INTEGER   SPECWT, CHHMOD, IDUM1, IDUM2
      LOGICAL   STREQ
 
      CURCON = 'the specified hlhsr mode is not available '//
     1         'on the specified workstation'
      CALL SETVS ('111', EXPERR, EXPSIZ)
      ERRSRS = '10'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQHRMF (SPECWT, 1, ERRIND, NHLHMD, MXH)
      CALL CHKINQ ('pqhrmf', ERRIND)
      DO 50 IX = 1, NHLHMD
        CALL PQHRMF (SPECWT, IX, ERRIND, IDUM1, THISH)
        CALL CHKINQ ('pqhrmf', ERRIND)
        IF (THISH .GT. MXH) MXH=THISH
50    CONTINUE
      UNTYPE = MXH + 1
 
      CALL PSHRM (WKID, THISH)
      CALL RSHRM (WKID, UNTYPE)
      CALL PQHRM (WKID, ERRIND, IDUM1,CHHMOD,IDUM2)
      CALL CHKINQ ('pqhrm', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. CHHMOD.EQ.THISH)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03112                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03112 (USEPRM)
 
C  E03112 tests the handling of error 112.
 
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
 
C  interior style
      INTEGER      PHOLLO,   PSOLID,    PPATTR,    PHATCH,   PISEMP
      PARAMETER   (PHOLLO=0, PSOLID=1,  PPATTR=2,  PHATCH=3, PISEMP=4)
 
      INTEGER  USEPRM, PTRARY(1,1), SPECWT
      LOGICAL  STREQ, INTSTY
 
      CURCON = 'the pattern index value is less than one'
      CALL SETVS ('112', EXPERR, EXPSIZ)
      ERRSRS = '11'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE) 
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
      
      IF (.NOT. INTSTY (SPECWT, PPATTR)) THEN
         CALL INMSG ('Pattern style not supported by this ' //
     1               'workstation; test skipped.')
         GOTO 666
      ENDIF

      CALL RSIR (WKID, 1, PPATTR, -1, 0)
      CALL TSTIGN (STREQ('OO**'))

      PTRARY(1,1) = 0
      CALL RSPAR (WKID,0,1,1,1,1,1,1,PTRARY)

666   CONTINUE
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03113                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03113 (USEPRM)
                                      
C  E03113 tests the handling of error 113.
 
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
 
C  interior styles
      INTEGER      PHOLLO,   PSOLID,    PPATTR,    PHATCH,   PISEMP
      PARAMETER   (PHOLLO=0, PSOLID=1,  PPATTR=2,  PHATCH=3, PISEMP=4)
C  type of return value
      INTEGER      PSET,     PREALI
      PARAMETER   (PSET=0,   PREALI=1)
 
      INTEGER   SIZB4,SIZAFT, USEPRM, COL(1,1), ISIZ,MKTYPE,MKCOLO
      INTEGER   SPECWT, IDUM1
      REAL      CSPEC(3), MKSCAL
      LOGICAL   STREQ, STRCON, APPEQ, INTSTY
 
      CURCON = 'the colour index value is less than zero'
      CALL SETVS ('113', EXPERR, EXPSIZ)
      ERRSRS = '12'
      CALL ESETUP (USEPRM)
 
      CALL POPST (101)
      CALL PLB   (801)
      CALL RSPLCI (-1)
      CALL TSTIGN (STREQ('O*O*') .AND. STRCON(101, '67,801'))
 
      CALL RSTXCI (-1)
 
      CALL RSEDCI (-1)
      CALL TSTIGN (STREQ('O*O*') .AND. STRCON(101, '67,801'))
 
      CALL PCLST
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
  
      CALL PSPMR (WKID, 2, 1,  .5,  1)
      CALL RSPMR (WKID, 2, 2, 1.0, -1)
      CALL PQPMR (WKID, 2,PSET,ERRIND,MKTYPE,MKSCAL,MKCOLO)
      CALL CHKINQ ('pqpmr', ERRIND)
      CALL TSTIGN (STREQ('OO**')               .AND.
     1             MKTYPE.EQ.1                 .AND.
     2             APPEQ(MKSCAL,0.5,0.01,0.01) .AND.
     3             MKCOLO.EQ.1)
 
      CALL RSIR (WKID, 1, PHOLLO, 1, -1)

      COL(1,1) = -1
      IF (INTSTY (SPECWT, PPATTR)) THEN
         CALL RSPAR (WKID, 1, 1,1,1,1,1,1, COL)
      ENDIF

      CALL PQECI (WKID, 0, ERRIND, SIZB4, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      CALL SETRVS ('0.5,0.5,0.5', CSPEC,ISIZ)
      CALL RSCR (WKID, -1, 3, CSPEC)
      CALL PQECI (WKID, 0, ERRIND, SIZAFT, IDUM1)
      CALL CHKINQ ('pqeci', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. SIZB4.EQ.SIZAFT)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03114                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03114 (USEPRM)
 
C   E03114 tests the handling of error 114
 
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
 
C   relative input priority
      INTEGER     PHIGHR,    PLOWER
      PARAMETER  (PHIGHR=0,  PLOWER=1)
 
C  clipping indicator
      INTEGER     PNCLIP,    PCLIP
      PARAMETER  (PNCLIP=0,  PCLIP=1)
 
      INTEGER   USEPRM, ISIZ, SIZB4,SIZAFT, IDUM1
      REAL      ROTMAT(3,3), MAPMAT(3,3), LIMIT(4)
      LOGICAL   STREQ, STRCON
 
      CURCON = 'the view index value is less than zero'
      CALL SETVS ('114', EXPERR, EXPSIZ)
      ERRSRS = '13'
      CALL ESETUP (USEPRM)
 
      CALL POPST (101)
      CALL PLB   (801)
      CALL RSVWI (-1)
      CALL TSTIGN (STREQ('O*O*') .AND. STRCON(101, '67,801'))
 
      CALL PCLST
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL IDMAT (3, ROTMAT)
      CALL IDMAT (3, MAPMAT)
      CALL SETRVS ('0.,0.5,0.,0.5', LIMIT, ISIZ)
      CALL PSVWR (WKID, 2, ROTMAT, MAPMAT, LIMIT, PCLIP)
      CALL PQEVWI (WKID, 0, ERRIND, SIZB4, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)

      CALL RSVTIP (WKID, -1, 2, PLOWER)
      CALL PQEVWI (WKID, 0, ERRIND, SIZAFT, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. SIZB4.EQ.SIZAFT)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03115                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
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
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03116                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03116 (USEPRM)
 
C   E03116 tests the handling of error 116.
 
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
 
C  type of returned value
      INTEGER      PSET,    PREALI
      PARAMETER   (PSET=0,  PREALI=1)
 
      INTEGER   USEPRM, COL(2,3), COLIA(2,3), COLIA1(2,3)
      INTEGER   DX,DY,DX1,DY1, SPECWT, PSIZ
      INTEGER   IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM7,IDUM8
 
      LOGICAL   STREQ, IAREQ
 
      DATA COL/0,1,1,1,0,1/, COLIA/1,0,0,0,1,0/
 
      CURCON = 'one of the dimensions of pattern colour index array ' //
     1         'is less than one'
      CALL SETVS ('116', EXPERR, EXPSIZ)
      ERRSRS = '15'       
      CALL ESETUP (USEPRM)
                                     
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQWKSL (SPECWT, ERRIND, IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,PSIZ,
     1             IDUM7,IDUM8)
      CALL CHKINQ ('pqwksl', ERRIND)
      IF (PSIZ .LT. 1) THEN
         CALL INMSG ('Skipping test for invalid pattern because ' //
     1               'workstation pattern table size is zero.')
         RETURN
      ENDIF

      DX = 0
      DY = 2
      CALL PSPAR (WKID, 1, 2,3,1,1,2,3,COL)
      CALL RSPAR (WKID, 1, DX,DY,1,1,2,3,COLIA)
      CALL PQPAR (WKID,1,PSET,2,3,ERRIND,DX1,DY1,COLIA1)
      CALL CHKINQ ('pqpar', ERRIND)
      CALL TSTIGN (STREQ('OO**')               .AND.
     1             DX1.EQ.2                    .AND.
     1             DY1.EQ.3                    .AND.
     1             IAREQ(6, COLIA1, COL))
 
      CALL RSPAR (WKID, 1, 2,3, 1,1, 2,0, COLIA)
 
      DX = 2
      DY = 0
      CALL RSPAR (WKID, 1, DX,DY, 1,1,2,3,COLIA)
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03117                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03117 (USEPRM)
 
C  E03117 tests the handling of Error 117.
 
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
 
      INTEGER   USEPRM, DX, DY, COLIA(2,3),ISIZ
      REAL      PX,PY, QX,QY, CPXA(3), CPYA(3), CPZA(3)
      LOGICAL   STREQ, STRCON
 
      CURCON = 'one of the dimensions of the colour index array '//
     1         'is less than one'
      CALL SETVS ('117', EXPERR, EXPSIZ)
      ERRSRS = '16'
      CALL ESETUP (USEPRM)

      CALL POPST (100)
      CALL PLB   (801)
 
      CALL SETVS ('1,1,1,0,0,1', COLIA, ISIZ)
      CALL SETRVS ('0.,3.,4.', CPXA, ISIZ)
      CALL SETRVS ('0.,1.,0.', CPYA, ISIZ)
      CALL SETRVS ('0.,0.,0.', CPZA, ISIZ)
 
      DX = -1
      DY = 3
      CALL RCA3 (CPXA,CPYA,CPZA,2,3,1,1,DX,DY,COLIA)
      CALL TSTIGN (STREQ('O*O*') .AND. STRCON(100, '67,801'))

      DX = 3
      DY = 0
      CALL RCA3 (CPXA,CPYA,CPZA,2,3,1,1,DX,DY,COLIA)
 
      PX = 1.
      PY = 0.
      QX = 3.
      QY = 2.
      DX = 0
      DY = 3
      CALL RCA (PX,PY,QX,QY,2,3,1,1,DX,DY,COLIA)
 
      DX = 2
      DY = -2
      CALL RCA (PX,PY,QX,QY,2,3,1,1,DX,DY,COLIA)
 
      CALL RCA (PX,PY,QX,QY,2,3,1,1,0,3,COLIA)
      CALL RCA3 (CPXA,CPYA,CPZA,2,3,1,1,2,0,COLIA)
      CALL TSTIGN (STREQ('O*O*') .AND. STRCON(100, '67,801'))
 
      CALL PCLST
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.03/e03118                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E03118 (USEPRM)
 
C  E03118 tests the handling of error 118.
 
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
 
C  type of returned values
      INTEGER        PSET,      PREALI
      PARAMETER     (PSET=0,    PREALI=1)
 
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
 
      INTEGER   USEPRM, NCLMOD, IDUM1, IDUM2, LCLMOD, IX
      INTEGER   NUMCP2, ISIZ, SPECWT
      REAL      SPEC1(10), SPEC2(10), SPEC(10)
      LOGICAL   STREQ,  RAREQ
 
      CURCON = 'one of the components of the colour ' //
     1         'specification is out of range'
      CALL SETVS ('118', EXPERR, EXPSIZ)
      ERRSRS = '17'
      CALL ESETUP (USEPRM)
 
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQCMDF (SPECWT,0,ERRIND,NCLMOD,IDUM1,IDUM2)
      CALL CHKINQ ('pqcmdf', ERRIND)
 
      DO 150 IX = 1, NCLMOD
 
         CALL PQCMDF (SPECWT, IX, ERRIND, IDUM1, LCLMOD,IDUM2)
         CALL CHKINQ ('pqcmdf', ERRIND)
         IF (LCLMOD.LT.PRGB .OR. LCLMOD.GT.PHLS) GOTO 150
 
         CALL PSCMD (WKID, LCLMOD)
         CALL SETRVS ('0.5,0.5,0.5', SPEC1, ISIZ)
         CALL PSCR (WKID, 2, 3, SPEC1)
 
         CALL SETRVS ('-0.5, 0., 1.', SPEC, ISIZ)
         CALL RSCR (WKID, 2, 3, SPEC)

         CALL SETRVS ('0., 1.01, 0.5', SPEC, ISIZ)
         CALL RSCR (WKID, 2, 3, SPEC)

         CALL SETRVS ('0., 0.5, -0.01', SPEC, ISIZ)
         CALL RSCR (WKID, 2, 3, SPEC)

         CALL PQCR (WKID,2,10,PSET,ERRIND,NUMCP2,SPEC2)
         CALL CHKINQ ('pqcr', ERRIND)
         CALL TSTIGN (STREQ('OO**')  .AND.
     1                NUMCP2.EQ.3    .AND.
     2                RAREQ(3,SPEC2,SPEC1,0.01,0.01))
 
150   CONTINUE
 
      CALL PCLWK (WKID)
 
      CALL ENDERR
 
      END
