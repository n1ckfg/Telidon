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
