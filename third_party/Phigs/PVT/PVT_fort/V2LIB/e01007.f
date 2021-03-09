      SUBROUTINE E01007 (USEPRM)

C  E01007 tests the handling of error number 7: function requires
C  state (PHOP,*,*,AROP), when PHIGS is open.

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

C  path order
      INTEGER      PPOTOP,     PPOBOT
      PARAMETER   (PPOTOP=0,   PPOBOT=1)

      INTEGER   ARID, STID, STLIST(2), PATHOD, PATHDP, N, OL,
     1          USEPRM, APTHSZ, PATHS(2, 10)

      LOGICAL   STREQ

      CURCON = 'PHIGS is open but no archive file is open'
      CALL SETVS ('7,404', EXPERR,EXPSIZ)
      ERRSRS = '7'
      CALL ESETUP (USEPRM)

      CALL POPST (100)
      CALL PTX (0.5,0.5,'TEXT')
      CALL PEXST (101)
      CALL PCLST
      CALL POPST (101)
      CALL PTX (0.3,0.7,'TEXT')
      CALL PCLST

      ARID = 11
      STID = 101
      STLIST(1) = 100
      STLIST(2) = 101
      PATHOD = PPOTOP
      PATHDP = 0

      CALL RCLARF (ARID)
      CALL TSTIGN (STREQ('O**C'))

      CALL RARST (ARID, 2, STLIST)
      CALL TSTIGN (STREQ('O**C'))

      CALL RRSID (ARID, 2, N, STLIST)

      CALL RREST (ARID, 2, STLIST)

      CALL RRAST (ARID)
      CALL TSTIGN (STREQ('O**C'))

      CALL RREPAN (ARID, STID, PATHOD, PATHDP, 10, 0, OL,
     1             APTHSZ, PATHS)
      CALL TSTIGN (STREQ('O**C'))

      CALL RDSTAR (ARID, 2, STLIST)
      CALL TSTIGN (STREQ('O**C'))

      CALL ENDERR

      END
