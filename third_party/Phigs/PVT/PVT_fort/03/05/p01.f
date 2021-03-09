C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.05/01                              *
C  *    TEST TITLE : Delete specified structures from      *
C  *                 archive                               *
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
     3        DUMINT(20)
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

C  Declare program-specific variables
      INTEGER    ARRSIZ
      PARAMETER (ARRSIZ = 100)

      INTEGER ALLSTR(ARRSIZ), ALLLEN, SPCSTR(ARRSIZ), SPCLEN,
     1        ANSSTR(ARRSIZ), ANSLEN, TEMSTR(ARRSIZ), TEMLEN,
     2        ACTSTR(ARRSIZ), ACTLEN, NEWSTR(ARRSIZ), NEWLEN,
     3        ARID, ARNM

      LOGICAL SETEQ, FAILFL

      CALL INITGL ('03.05/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  set up standard networks in CSS
      CALL STDCSS
C  open new archive file, with arid = archive identifier
      ARID = 2
      CALL AVARNM (ARNM)
      CALL POPARF (ARID, ARNM)
C  <archive all structures>, into arid
      CALL PARAST (ARID)
C  all structures
      CALL SETVS ('100,101,102,103,104,105,106,107,108,109,110,111,' //
     1            '113,114,115,120,130,140,142',  ALLSTR, ALLLEN)
C  spcstr = specified structures = 103,105,113
      CALL SETVS ('103,105,113', SPCSTR, SPCLEN)

C  <delete structures from archive> arid, spcstr
      CALL PDSTAR (ARID, SPCLEN, SPCSTR)
C  <retrieve structure identifiers> with arid
C     to determine actstr = actual list of archived structures
      CALL PRSID (ARID, ARRSIZ, ACTLEN, ACTSTR)
      CALL SETMSG ('1 4', 'Only the structures explicitly listed as ' //
     1             'parameters of <delete structures from archive> '  //
     2             'should be deleted from the specified open '       //
     3             'archive file.')
C  pass/fail depending on (actstr = (allstr - spcstr))
      CALL SETDIF (ALLLEN, ALLSTR, SPCLEN, SPCSTR, ANSLEN, ANSSTR)
      CALL IFPF (ACTLEN .EQ. ANSLEN .AND. SETEQ(ACTLEN, ACTSTR, ANSSTR))

C  delete structure identifier not in archive
      CALL SETVS ('155', SPCSTR, SPCLEN)
      CALL ERRCTL (.TRUE.)
      CALL PDSTAR (ARID, SPCLEN, SPCSTR)
      CALL ERRCTL (.FALSE.)
C  <retrieve structure identifiers> with arid
C     to determine newstr = new list of archived structures
      CALL PRSID (ARID, ARRSIZ, NEWLEN, NEWSTR)

      CALL SETMSG ('1 5', 'If the specified structure does not '   //
     1             'exist in the archive file, then <delete '      //
     2             'structures from archive> should result in no ' //
     3             'action for that structure.')
C  pass/fail depending on (newstr = actstr)
      CALL IFPF (ACTLEN .EQ. NEWLEN .AND. SETEQ(NEWLEN, NEWSTR, ACTSTR))

      CALL SETMSG ('1 5', 'If the specified structure does not ' //
     1             'exist in the archive file, then <delete '    //
     2             'structures from archive> should signal error 407.')
C  pass/fail depending on (error = 407)
      CALL SIGTST (407, FAILFL)

C  delete with structure identifiers both in and not-in archive
C  spcstr = 102, 177, 142
      CALL SETVS ('102,177,142', SPCSTR, SPCLEN)
      CALL ERRCTL (.TRUE.)
      CALL PDSTAR (ARID, SPCLEN, SPCSTR)
      CALL ERRCTL (.FALSE.)
C  <retrieve structure identifiers> with arid
C     to determine actstr = new list of archived structures
      CALL PRSID (ARID, ARRSIZ, ACTLEN, ACTSTR)

      CALL SETMSG ('1 4 5', 'If the list of specified structures to ' //
     1             'be deleted from the archive file contains '       //
     2             'structures that exist and do not exist in the '   //
     3             'archive file, then those structures that exist '  //
     4             'should be deleted from the archive and no '       //
     5             'action is taken for those structures that do '    //
     6             'not exist in the archive file.')
C  pass/fail depending on (actstr = (newstr - structures 102 and 142))
      CALL SETVS ('102,142', TEMSTR, TEMLEN)
      CALL SETDIF (NEWLEN, NEWSTR, TEMLEN, TEMSTR, ANSLEN, ANSSTR)
      CALL IFPF (ACTLEN .EQ. ANSLEN .AND. SETEQ(ACTLEN, ACTSTR, ANSSTR))

      CALL SETMSG ('1 5', 'If the list of specified structures to ' //
     1             'be deleted from the archive file contains '     //
     2             'structures that do not exist in the archive '   //
     3             'file, then error 407 should be signalled.')
C  pass/fail depending on (error = 407)
      CALL SIGTST (407, FAILFL)

C  <close archive file> with arid
      CALL PCLARF (ARID)

666   CONTINUE
      CALL ENDIT
      END
