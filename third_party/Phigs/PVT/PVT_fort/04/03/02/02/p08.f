C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.03.02.02/08                        *
C  *    TEST TITLE : Non-explicitly defined color models   *
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

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C aspect source
C                bundled     individual
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)

C     colour available
      INTEGER    PMONOC,   PCOLOR
      PARAMETER (PMONOC = 0, PCOLOR = 1)

      INTEGER      PICSTR, TXCI, COLSIZ, HICOL
      INTEGER      LIMCMD (100), NLIMCM
      INTEGER      LRGCMD (100), NLRGCM
      INTEGER      IDUM1, IDUM2, IDUM3, IDUM4, IDUM5
      INTEGER      IDUM6, IDUM7, NMOD, CMOD, I

      LOGICAL      UNDCMD

      CALL INITGL ('04.03.02.02/08')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)

      CALL POPST (PICSTR)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  make sure colro coordinate labels are visible
      CALL PSTXCI (1)
      CALL PEXST  (102)
      CALL PCLST

C  Determine list of color models to test.
      CALL PQCMDF ( SPECWT, 0, ERRIND, NMOD, CMOD, IDUM1)
      CALL CHKINQ ('pqcmdf', ERRIND)

      NLIMCM = 0
      NLRGCM = 0
      DO 100, I= 1,NMOD
         CALL PQCMDF ( SPECWT, I, ERRIND, IDUM1, CMOD, IDUM2 )
         CALL CHKINQ ('pqcmdf', ERRIND)

C    implementor-defined color models (i.e. all those < 1)
         IF ( CMOD .LT. 1 ) THEN
            NLIMCM = NLIMCM + 1
            LIMCMD (NLIMCM) = CMOD
         ENDIF

C    registered, non-explicitly defined color models (i.e. all those > 4)
         IF ( CMOD .GT. 4 ) THEN
            NLRGCM = NLRGCM + 1
            LRGCMD (NLRGCM) = CMOD
         ENDIF
100   CONTINUE

C  Determine the size of color table COLSIZ
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, COLSIZ, IDUM7)
      CALL CHKINQ ('pqwksl', ERRIND)

      IF (COLSIZ .GT. 2) THEN
         HICOL = MIN (COLSIZ-1, 9)
      ELSE
         CALL INMSG ('Color table too small to allow testing ' //
     1               'of non-explicitly defined color models.')
         GOTO 190
      ENDIF
      CALL POPST (102)

C  **** **** **** ****  Registered Color Models  **** **** **** ****

      IF ( NLRGCM .EQ. 0 ) THEN
         CALL INMSG ('No registered color models are ' //
     1               'supported; skipping test.')
         GOTO 110
      ENDIF

      CALL SETMSG ('16 17 21 28 32', 'Registered colour models ' //
     1             'should work as described by the ISO register.')
      IF (UNDCMD (NLRGCM,LRGCMD,HICOL, 'ISO register')) THEN
         CALL PASS
      ELSE
         CALL OPFAIL
      ENDIF

110   CONTINUE

C  **** **** ****  Implementor defined Color Models   **** **** ****

      IF ( NLIMCM .EQ. 0 ) THEN
         CALL INMSG ('No implementor defined color models are ' //
     1               'supported; skipping test.')
         GOTO 190
      ENDIF

      CALL SETMSG ('16 17 21 29 32', 'Implementor defined ' //
     1             'colour models should work as described ' //
     2             'by the implementor''s documentation.')
      IF (UNDCMD (NLIMCM,LIMCMD,HICOL,
     1            'implementor''s documentation')) THEN
         CALL PASS
      ELSE
         CALL OPFAIL
      ENDIF

190   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
