C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.01/05                        *
C  *    TEST TITLE : Unposting structures by deletion      *
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
 
C PHIGS parameter types
      INTEGER STRID, IDUM1, PSTNUM
 
      REAL RDUM1
 
      CALL INITGL ('02.01.02.01/05')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL SETMSG ('4', 'Deleting a closed posted structure '      //
     1             'should cause that structure to become '        //
     2             'unposted from the workstation to which it is ' //
     3             'posted.')
 
      STRID = 25
      RDUM1 = 0.02
C post structure
      CALL PPOST (WKID, STRID, RDUM1)
      CALL PDST (STRID)
 
C Use inquire posted structure to determine:
C    pstnum = number of posted structures
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      CALL IFPF   (PSTNUM .EQ. 0)
 
      CALL SETMSG ('4', 'Deleting an open posted structure '       //
     1             'should cause that structure to become '        //
     2             'unposted from the workstation to which it is ' //
     3             'posted.')
 
      STRID = 40
      RDUM1 = 0.02
      CALL POPST (STRID)
C post structure
      CALL PPOST (WKID, STRID, RDUM1)
      CALL PDST (STRID)
 
C Use inquire posted structure to determine:
C    pstnum = number of posted structures
      CALL PQPOST (WKID, 0, ERRIND, PSTNUM, IDUM1, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      CALL IFPF (PSTNUM .EQ. 0)
 
      CALL ENDIT
      END
