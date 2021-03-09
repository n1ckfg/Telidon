C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01/06                              *
C  *    TEST TITLE : Emergency close phigs                 *
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

C archive state
C                closed   open
      INTEGER    PARCL,   PAROP
      PARAMETER (PARCL=0, PAROP=1)
C structure state value
      INTEGER    PSTCL,     PSTOP
      PARAMETER (PSTCL = 0, PSTOP = 1)
C system state value
      INTEGER    PPHCL,     PPHOP
      PARAMETER (PPHCL = 0, PPHOP = 1)
C workstation state
      INTEGER    PWSCL,     PWSOP
      PARAMETER (PWSCL = 0, PWSOP = 1)

      INTEGER   SYSVAL, WKVAL, STVAL, ARVAL, ARID, ARNM
      
      CALL INITGL ('09.01/06')

      CALL SETMSG ('11', 'If <emergency close phigs> is called, ' //
     1             'open structure should be closed, open archive ' //
     2             'files should be closed, all open workstations ' //
     3             'should be updated and closed, and PHIGS should ' //
     4             'be closed.')

      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPWK (WKID, CONID, WTYPE)
      CALL POPST (100)
      ARID = 11
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)

      CALL PECLPH

      CALL PQSYS (SYSVAL)
      CALL PQWKST (WKVAL)
      CALL PQSTRS (STVAL)
      CALL PQARS (ARVAL)

      CALL IFPF (SYSVAL .EQ. PPHCL .AND. WKVAL .EQ. PWSCL .AND. 
     1           STVAL  .EQ. PSTCL .AND. ARVAL .EQ. PARCL) 

      CALL ENDIT

      END

