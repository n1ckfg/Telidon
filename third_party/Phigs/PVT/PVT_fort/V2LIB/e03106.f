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
