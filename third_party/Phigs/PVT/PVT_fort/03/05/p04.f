C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.05/04                              *
C  *    TEST TITLE : Deleting from archive when multiple   *
C  *                 archive files are open                *
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
      INTEGER    ARID1, ARID2, ARNM1, ARNM2, SPCSTR(ARRSIZ), SPCLEN,
     1           EXPSTR(ARRSIZ), EXPLEN, NEWSTR(ARRSIZ), NEWLEN, MXARNO,
     2           IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6
 
      LOGICAL    SETEQ
 
      CALL INITGL ('03.05/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  <inquire phigs facilities> to determine
C     mxarno = maximum number of simultaneously open archive files
      CALL PQPHF (0, ERRIND, IDUM1, MXARNO, IDUM2, IDUM3, IDUM4, IDUM5,
     1            IDUM6)
      CALL CHKINQ ('pqphf', ERRIND)
 
      IF (MXARNO .LE. 1) THEN
         CALL INMSG ('Skipping test: cannot open multiple ' //
     1               'archive files.')
         GOTO 666
      ENDIF
 
C  set up standard networks in CSS
      CALL STDCSS
C  open new archive file, with arid1 = archive identifier
      ARID1 = 4
      CALL AVARNM (ARNM1)
      CALL POPARF (ARID1, ARNM1)
C  open 2nd archive file, with arid2
      ARID2 = 5
      CALL AVARNM (ARNM2)
      CALL POPARF (ARID2, ARNM2)
 
C  <archive all structures> into arid1 and arid2
      CALL PARAST (ARID1)
      CALL PARAST (ARID2)
 
C  expstr = expected structures = 100,101,102,103,104,105,106,107,108,110
C                                 111,113,114,115,120,130,140,142,109
      CALL SETVS ('100,101,102,103,104,105,106,107,108,110,111,113,' //
     1            '114,115,120,130,140,142,109', EXPSTR, EXPLEN)
 
C  spcstr = specified structures = 114,102,100,140,107
      CALL SETVS ('114,102,100,140,107', SPCSTR, SPCLEN)
 
C  <delete structures from archive> with arid1, spcstr
      CALL PDSTAR (ARID1, SPCLEN, SPCSTR)
C  <retrieve structure indentiers> with arid2
C     to determine newstr = new list of archived structures
      CALL PRSID (ARID2, ARRSIZ, NEWLEN, NEWSTR)
 
      CALL SETMSG ('1 4', 'If more than one archive file is open, ' //
     1             '<delete structures from archive> should not '   //
     2             'affect any open archive file other than the '   //
     3             'file specified.')
C  pass/fail depending on (newstr = expstr)
      CALL IFPF (NEWLEN .EQ. EXPLEN .AND. SETEQ(NEWLEN, NEWSTR, EXPSTR))
 
C  <delete all structures from archive> arid1
      CALL PDASAR (ARID1)
C  <retrieve structure identifiers> with arid2 to determine newstr
      CALL PRSID (ARID2, ARRSIZ, NEWLEN, NEWSTR)
 
      CALL SETMSG ('3 4', 'If more than one archive file is open, '   //
     1             '<delete all structures from archive> should not ' //
     2             'affect any open archive file other than the '     //
     3             'file specified.')
C  pass/fail depending on (newstr = expstr)
      CALL IFPF (NEWLEN .EQ. EXPLEN .AND. SETEQ(NEWLEN, NEWSTR, EXPSTR))
 
C  <archive all structures> into arid1
      CALL PARAST (ARID1)
C  spcstr = specified structures = 107, 114, 105
      CALL SETVS ('107,114,105', SPCSTR, SPCLEN)
C  <delete structure networks from archive> with arid1, spcstr
      CALL PDSNAR (ARID1, SPCLEN, SPCSTR)
C  <retrieve structure identifiers> with arid2 to determine newstr
      CALL PRSID (ARID2, ARRSIZ, NEWLEN, NEWSTR)
 
      CALL SETMSG ('2 4', 'If more than one archive file is open, '   //
     1             '<delete structure networks from archive> should ' //
     2             'not affect any open archive file other than the ' //
     3             'file specified.')
C  pass/fail depending on (newstr = expstr)
      CALL IFPF (NEWLEN .EQ. EXPLEN .AND. SETEQ(NEWLEN, NEWSTR, EXPSTR))
 
C  <close archive file> with arid1 and arid2
      CALL PCLARF (ARID1)
      CALL PCLARF (ARID2)
 
C  done:
666   CONTINUE
      CALL ENDIT
      END
