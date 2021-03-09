C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.05/02                              *
C  *    TEST TITLE : Delete structure networks from        *
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

      INTEGER    ALLSTR(ARRSIZ), ALLLEN, SPCSTR(ARRSIZ), SPCLEN,
     1           ANSSTR(ARRSIZ), ANSLEN, DELSTR(ARRSIZ), DELLEN,
     2           ACTSTR(ARRSIZ), ACTLEN, NEWSTR(ARRSIZ), NEWLEN,
     3           ARID, ARNM

      LOGICAL    SETEQ, FAILFL

      CALL INITGL ('03.05/02')

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
C  allstr = all strucutures = 100,101,102,103,104,105,106,107,108,109,
C                             110,111,113,114,115,120,130,140,142
      CALL SETVS ('100,101,102,103,104,105,106,107,108,109,' //
     1            '110,111,113,114,115,120,130,140,142',
     2             ALLSTR, ALLLEN)
C  spcstr = specified network structures = 107,114,105
      CALL SETVS ('107,114,105', SPCSTR, SPCLEN)
C   delstr = deleted network structures = 105,110,114,108,111,115,107,113
      CALL SETVS ('105,110,114,108,111,115,107,113', DELSTR, DELLEN)
C  <delete structure networks from archive> arid, spcstr
      CALL PDSNAR (ARID, SPCLEN, SPCSTR)
C  <retrieve structure identifiers> with arid
C     to determine actstr = actual list of archived structures
      CALL PRSID (ARID, ARRSIZ, ACTLEN, ACTSTR)

      CALL SETMSG ('2 4', 'Only the structures explicitly listed as ' //
     1             'parameters of <delete structure networks from '   //
     2             'archive> and their descendants should be '        //
     3             'deleted from the specified open archive file.')
C  pass/fail depending on (actstr = (allstr - delstr))
      CALL SETDIF (ALLLEN, ALLSTR, DELLEN, DELSTR, ANSLEN, ANSSTR)
      CALL IFPF (ACTLEN .EQ. ANSLEN .AND. SETEQ(ACTLEN, ACTSTR, ANSSTR))


C  delete with a structure network not in archive
C  spcstr = 155
      CALL SETVS ('155', SPCSTR, SPCLEN)

C  <delete structure networks from archive> arid, spcstr
      CALL ERRCTL (.TRUE.)
      CALL PDSNAR (ARID, SPCLEN, SPCSTR)
      CALL ERRCTL (.FALSE.)
C  <retrieve structure identifiers> with arid
C     to determine newstr = new list of archived structures
      CALL PRSID (ARID, ARRSIZ, NEWLEN, NEWSTR)

      CALL SETMSG ('2 5', 'If the specified structure does not '     //
     1             'exist in the archive file, then <delete '        //
     2             'structure networks from archive> should result ' //
     3             'in no action with regards to that structure '    //
     4             'network.')
C  pass/fail depending on (newstr = actstr)
      CALL IFPF (NEWLEN .EQ. ACTLEN .AND. SETEQ(NEWLEN, NEWSTR, ACTSTR))


      CALL SETMSG ('2 5', 'If the specified structure does not '     //
     1             'exist in the archive file, then <delete '        //
     2             'structure networks from archive> should signal ' //
     3             'error 407.')
C  pass/fail depending on (error = 407)
      CALL SIGTST (407, FAILFL)


C  delete with structure networks both in and not-in archive
C  spcstr = 104, 177, 140
      CALL SETVS ('104,177,140', SPCSTR, SPCLEN)
C  delstr = 104, 109, 140, 142
      CALL SETVS ('104,109,140,142', DELSTR, DELLEN)

C  <delete structure networks from archive> arid, spcstr
      CALL ERRCTL (.TRUE.)
      CALL PDSNAR (ARID, SPCLEN, SPCSTR)
      CALL ERRCTL (.FALSE.)
C  <retrieve structure identifiers> with arid
C     to determine actstr = new list of archived structures
      CALL PRSID (ARID, ARRSIZ, ACTLEN, ACTSTR)
      CALL SETMSG ('2 4 5', 'If the list of specified structures to ' //
     1             'be deleted from the archive file contains '       //
     2             'structure networks that exist and do not exist '  //
     3             'in the archive file, then those structure '       //
     4             'networks that exist should be deleted from the '  //
     5             'archive and no action is taken for those '        //
     6             'structures that do not exist in the archive '     //
     7             'file.')
C  pass/fail depending on (actstr = (newstr - delstr))
      CALL SETDIF (NEWLEN, NEWSTR, DELLEN, DELSTR, ANSLEN, ANSSTR)
      CALL IFPF (ACTLEN .EQ. ANSLEN .AND. SETEQ(ACTLEN, ACTSTR, ANSSTR))


      CALL SETMSG ('2 5', 'If the list of specified structure '    //
     1             'networks to be deleted from the archive file ' //
     2             'contains structures that do not exist in the ' //
     3             'archive file, then error 407 should be '       //
     4             'signalled.')
C  pass/fail depending on (error = 407)
      CALL SIGTST (407, FAILFL)

C  <close archive file> with arid
      CALL PCLARF (ARID)

666   CONTINUE
      CALL ENDIT
      END
