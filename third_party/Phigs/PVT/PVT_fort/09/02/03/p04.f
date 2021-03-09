C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.02.03/04                           *
C  *    TEST TITLE : Error indicator = 106                 *
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

C  text precision      
      INTEGER       PSTRP,      PCHARP,      PSTRKP
      PARAMETER    (PSTRP=0,    PCHARP=1,    PSTRKP=2)

      INTEGER    IX, NPAIR, SPECWT
      INTEGER    IVAL1,IVAL2,IVAL3,IVAL4,IVAL5
      INTEGER    TXTFNT, TXTPRC, HIFONT

      REAL       RVAL1,RVAL2,RVAL3,RVAL4,RA2(2),RB2(2)

      CALL INITGL ('09.02.03/04')

      CALL XPOPPH (ERRFIL, MEMUN)

      CURCON = 'the specified font is not available for the ' //
     1         'requested text precision on the specified workstation'
      CALL SETVS ('106', EXPERR, EXPSIZ)
      ERRSRS = '4'

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQTXF (SPECWT,0,ERRIND,NPAIR,IVAL1,IVAL2,IVAL3,RVAL1,RVAL2,
     1            IVAL4,RVAL3,RVAL4,IVAL5)
      CALL CHKINQ ('pqtxf', ERRIND)
      IF (NPAIR .EQ. 0) THEN
         CALL INMSG ('There are no text font and precision pairs, '//
     1               'skip the test.')
         GOTO 666
      ENDIF

      HIFONT = 1
C  must find a non-STROKE font
      DO 50 IX = 1, NPAIR     
         CALL PQTXF (SPECWT,IX,ERRIND,IVAL1,TXTFNT,TXTPRC,
     1               IVAL2,RVAL1,RVAL2,IVAL3,RVAL3,RVAL4,IVAL4)
         CALL CHKINQ ('pqtxf',ERRIND)
         IF (TXTPRC .EQ. PSTRKP) THEN
            IF (TXTFNT .GT. HIFONT) HIFONT=TXTFNT
         ENDIF
50    CONTINUE
      HIFONT = HIFONT+1

      CALL RQTXX (SPECWT, HIFONT, 1.,0.1,0.1,1,1,1,'TEXT',
     1            ERRIND, RA2, RB2, RVAL1, RVAL2)

666   CONTINUE

      CALL ENDIT

      END
