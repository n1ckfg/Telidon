C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.03.01/04                        *
C  *    TEST TITLE : Character height and expansion factor *
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

      INTEGER  NAHT
      INTEGER  IDUM1,IDUM2,IDUM3,IDUM4,IDUM5

      REAL     MINHT, MAXHT
      REAL     RDUM1,RDUM2

      CHARACTER  MSG*200

      CALL INITGL ('04.02.03.01/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C set-up of workstation and dialogue area - initialize SPECWT
      CALL SETDLG (101, 801,1)

C  <inquire text facilities> to determine
C  naht = # available character heights
C  minht = minimum character height
C  maxht = maximum character height
      CALL PQTXF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3,
     1            NAHT,MINHT,MAXHT, IDUM4,RDUM1,RDUM2, IDUM5)
      CALL CHKINQ ('pqtxf', ERRIND)

      WRITE (MSG, '(A,I5,A, 2(E13.4,A))')
     1      'Number of reported character heights = ', NAHT,
     2      '.  Minimum,maximum reported character heights = ',
     3      MINHT, ', ', MAXHT, '.'
      CALL INMSG (MSG)

      CALL SETMSG ('53', 'Maximum character height should not be ' //
     1             'less than the minimum character height.')
      CALL IFPF (MAXHT .GE. MINHT)

      CALL SETMSG ('53 54', 'The minimum and maximum character ' //
     1             'heights should be positive.')
      CALL IFPF (MINHT.GT.0 .AND. MAXHT.GT.0)

      CALL SETMSG ('53 55 57', 'The reported number of available ' //
     1             'character heights should be at least 0.')
      CALL IFPF (NAHT .GE. 0)

      CALL SETMSG ('3 4 5 6 7 8 28 29 30 36 37 56 57 59 61', 'Test ' //
     1             'cases for the visual effect of approximated '    //
     2             'text attributes (character height and '          //
     3             'character expansion factor) in STRING and CHAR ' //
     4             'precision are not yet available.')
      CALL PASS

      CALL POPST (101)
C  by convention, view #1 is for picture
      CALL PSVWI (1)
C  use individual attributes
      CALL SETASF (PINDIV)
C  set up 102 as sub-structure
      CALL PEXST (102)
      CALL PCLST

      CALL POPST (102)

      CALL SETMSG ('11 14 34 35 36 52 58 59', 'Only the magnitude ' //
     1             'of character expansion factor and character '   //
     2             'height should affect the text primitive.')
      CALL NGTXAT ('T')

666   CONTINUE
C  wrap it up.
      CALL ENDIT
      END
