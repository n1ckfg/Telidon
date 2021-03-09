C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.01.02/09                           *
C  *    TEST TITLE : Visual effect of modelling            *
C  *                 transformation                        *
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
C
C  Aspect source
C                BUNDLED     INDIVIDUAL
      INTEGER    PBUNDL,     PINDIV
      PARAMETER (PBUNDL = 0, PINDIV = 1)
 
      INTEGER    IDUM1,IDUM2,IDUM3, IDUM4
      INTEGER    PICSTR, TXCI, NGBOX, MODTRN
      REAL       NOMMS, MSCF, RDUM1, RDUM2
 
      CALL INITGL ('06.01.02/09')
      CALL XPOPPH (ERRFIL, MEMUN)
C
C  Set-up of workstation and dialogue area
      PICSTR = 101
      TXCI = 1
      CALL SETDLG (PICSTR, 801,TXCI)
      CALL POPST (PICSTR)
C  By convention, view #1 is for picture
      CALL PSVWI (1)
C  Use individual attributes
      CALL SETASF (PINDIV)
 
C  Adjust polymarker size
      CALL PQPMF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS, RDUM1,
     1            RDUM2, IDUM4)
      CALL CHKINQ ('pqpmf', ERRIND)
      MSCF = .02 / (NOMMS*WCPDC)
      CALL PSMKSC (MSCF)
 
C  Adjust polyline width
      CALL PQPLF (SPECWT, 0, ERRIND, IDUM1,IDUM2,IDUM3, NOMMS, RDUM1,
     1            RDUM2, IDUM4)
      CALL CHKINQ ('pqplf', ERRIND)
      MSCF = .01 / (NOMMS*WCPDC)
      CALL PSLWSC (MSCF)
 
      CALL PEXST (106)
      CALL PEXST (102)
      CALL PCLST
 
C  *** *** *** *** ***   3D Transformations    *** *** *** *** ***
 
      CALL SETMSG ('1 8 9 15 16 17', 'The modelling coordinates of ' //
     1             'a 3D polyline should be transformed into world ' //
     2             'coordinates by 3D local and global modelling '   //
     3             'transformation.')
      NGBOX = MODTRN(3)
 
      CALL DCHPFV ('3D MODELLING TRANSFORMATION: Which box ' //
     1             'contains something other than a single ' //
     2             'line segment with circled endpoints? ', 6, NGBOX)
 
      CALL PEMST (102)
      CALL PEMST (106)
 
C  *** *** *** *** ***   2D Transformations    *** *** *** *** ***
 
      CALL SETMSG ('4 8 12 15 16 17 18', 'The modelling coordinates ' //
     1             'of a 3D polyline should be transformed into '     //
     2             'world coordinates by 2D local and global '        //
     3             'modelling transformation.')
      NGBOX = MODTRN(2)
 
      CALL DCHPFV ('2D MODELLING TRANSFORMATION: Which box ' //
     1             'contains something other than a single ' //
     2             'line segment with circled endpoints? ', 6, NGBOX)
 
C  Wrap it up.
      CALL ENDIT
      END
