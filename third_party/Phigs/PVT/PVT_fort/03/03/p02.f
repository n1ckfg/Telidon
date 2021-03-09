C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/02                              *
C  *    TEST TITLE : Selection of structures for archiving *
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
      PARAMETER (ARRSIZ=50)
      INTEGER    ARNM, ARID
      INTEGER    EXPSTR(ARRSIZ), EXPSIZ, ACTSTR(ARRSIZ), ACTSIZ
      INTEGER    SPCSTR(ARRSIZ), SPCSIZ
 
      LOGICAL    SETEQ
 
      CALL INITGL ('03.03/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  set up standard networks in CSS
      CALL STDCSS
C  open new archive file, with arid = archive identifier
      CALL AVARNM (ARNM)
      ARID = 2
      CALL POPARF (ARID, ARNM)
C  <delete all structures from archive> to ensure empty file
      CALL PDASAR (ARID)
C  expstr = expected structures = 114,102,100,140,107
      CALL SETVS ('114,102,100,140,107', EXPSTR, EXPSIZ)
C  <archive structures> with expstr, arid
      CALL PARST (ARID, EXPSIZ, EXPSTR)
 
      CALL SETMSG ('1 4', 'Exactly those structures explicitly '      //
     1             'listed in the input parameter of <archive '       //
     2             'structures> should be reported as existing in a ' //
     3             'previously empty archive file.')
C  <retrieve structure identifiers> with arid
C     to determine: actstr = actual list of structures
      CALL PRSID (ARID, ARRSIZ, ACTSIZ, ACTSTR)
      CALL IFPF (ACTSIZ .EQ. EXPSIZ .AND. SETEQ(ACTSIZ, ACTSTR, EXPSTR))
 
C  <delete all structures from archive> to ensure empty file
      CALL PDASAR (ARID)
C  spcstr = specified structures = 107,114,105
      CALL SETVS ('107,114,105', SPCSTR, SPCSIZ)
C  expstr = expected structures = 105,110,114,108,111,115,107,113
      CALL SETVS ('105,110,114,108,111,115,107,113', EXPSTR, EXPSIZ)
C  <archive structure networks> with spcstr, arid
      CALL PARSN (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('2 4', 'The structures explicitly listed in the '  //
     1             'input parameter of <archive structure networks> ' //
     2             'and all their descendants in the CSS should be '  //
     3             'reported as existing in a previously empty '      //
     4             'archive file.')
C  <retrieve structure identifiers> with arid
C     to determine: actstr = actual list of structures
      CALL PRSID (ARID, ARRSIZ, ACTSIZ, ACTSTR)
      CALL IFPF (ACTSIZ .EQ. EXPSIZ .AND. SETEQ(ACTSIZ, ACTSTR, EXPSTR))
 
C  <delete all structures from archive> to ensure empty file
      CALL PDASAR (ARID)
C  expstr = expected structures = 100,101,102,103,104,105,106,107,108,109,
C                                 110,111,113,114,115,120,130,140,142
      CALL SETVS ('100,101,102,103,104,105,106,107,108,109,110,111,' //
     1            '113,114,115,120,130,140,142', EXPSTR, EXPSIZ)
C  <archive all structures> with arid
      CALL PARAST (ARID)
 
      CALL SETMSG ('3 4', '<Archive all structures> should cause ' //
     1             'all structures currently in the CSS to be '    //
     2             'reported as existing in a previously empty '   //
     3             'archive file.')
C  <retrieve structure identifiers> with arid
C     to determine: actstr = actual list of structures
      CALL PRSID (ARID, ARRSIZ, ACTSIZ, ACTSTR)
      CALL IFPF (ACTSIZ .EQ. EXPSIZ .AND. SETEQ(ACTSIZ, ACTSTR, EXPSTR))
 
C  <close archive file> with arid
      CALL PCLARF (ARID)
 
666   CONTINUE
      CALL ENDIT
      END
