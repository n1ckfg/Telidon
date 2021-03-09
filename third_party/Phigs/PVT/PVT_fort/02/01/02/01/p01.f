C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.01/01                        *
C  *    TEST TITLE : Simple structure deletion             *
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
 
      INTEGER DELSTR
 
      LOGICAL CSSEQ
 
      CALL INITGL ('02.01.02.01/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C creation of structures
      CALL POPST (100)
      CALL PEXST (105)
      CALL PEXST (110)
      CALL PCLST
 
      CALL SETMSG ('1 2', 'Deleting a structure should remove the ' //
     1             'specified structure from the CSS and all '      //
     2             'references made to that structure contained '   //
     3             'in other structures.')
 
 
      DELSTR = 105
      CALL PDST (DELSTR)
      CALL IFPF (CSSEQ ('100,1, 110,0/'))
 
      CALL ENDIT
      END
