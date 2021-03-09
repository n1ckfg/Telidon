C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.05/03                              *
C  *    TEST TITLE : Delete all structures from archive    *
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
 
      INTEGER    ARRSIZ
      PARAMETER (ARRSIZ = 100)
 
      INTEGER    ARID, ARNM, ACTSTR(ARRSIZ), ACTLEN
 
      CALL INITGL ('03.05/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  set up standard networks in CSS
      CALL STDCSS
C  open new archive file, with arid = archive identifier
      ARID = 3
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
 
C  <archive all structures>, into arid
      CALL PARAST (ARID)
C  <delete all structures from archive> arid
      CALL PDASAR (ARID)
 
      CALL SETMSG ('3 4', 'After <delete all structures from '    //
     1             'archive>, the specified archive file should ' //
     2             'be empty.')
C  <retrieve structure identifiers> with arid
C     to determine actstr = actual list of archived structures
      CALL PRSID (ARID, ARRSIZ, ACTLEN, ACTSTR)
C  pass/fail depending on (actstr = empty)
      CALL IFPF (ACTLEN .EQ. 0)
 
C     <close archive file> with arid
      CALL PCLARF (ARID)
 
666   CONTINUE
      CALL ENDIT
      END
