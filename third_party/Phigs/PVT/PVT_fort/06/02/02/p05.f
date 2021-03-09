C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.02/05                           *
C  *    TEST TITLE : Order of view indices                 *
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
 
      INTEGER    NDVI, IDUM1
 
C relative input priority
      INTEGER    PHIGHR,     PLOWER
      PARAMETER (PHIGHR = 0, PLOWER = 1)
 
 
      CALL INITGL ('06.02.02/05')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
 
C  <Inquire list of view indices> to determine
C     ndvi = number of defined indices in the view table
      CALL PQEVWI (WKID, 0, ERRIND, NDVI, IDUM1)
      CALL CHKINQ ('pqevwi', ERRIND)
 
      CALL SETMSG ('18 20 21', '<Set view transformation input '      //
     1             'priority> should be able to set a middle view '   //
     2             'to priority higher than the first view.')
      CALL TSTVIP (NDVI/2, 1, PHIGHR, NDVI)
 
      CALL SETMSG ('18 20 21', '<Set view transformation input '      //
     1             'priority> should be able to set a middle view '   //
     2             'to priority lower than the last view.')
      CALL TSTVIP (NDVI/2, NDVI, PLOWER, NDVI)
 
      CALL SETMSG ('18 20 21', '<Set view transformation input '      //
     1             'priority> should be able to set the first view '  //
     2             'to priority lower than a middle view.')
      CALL TSTVIP (1, NDVI/2, PLOWER, NDVI)
 
      CALL SETMSG ('18 20 21', '<Set view transformation input '      //
     1             'priority> should be able to set the last view '   //
     2             'to priority higher than a middle view.')
      CALL TSTVIP (NDVI, NDVI/2, PHIGHR, NDVI)
 
      CALL SETMSG ('18 22', '<Set view transformation input '         //
     1             'priority> should have no effect when the '        //
     2             'specified view is the same as the reference '     //
     3             'view.')
      CALL TSTVIP (2, 2, PLOWER, NDVI)
 
666   CONTINUE
      CALL ENDIT
      END
