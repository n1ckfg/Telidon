C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/07                              *
C  *    TEST TITLE : Partial networks in archive           *
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
      PARAMETER (ARRSIZ = 50)
      INTEGER    ARID, ARNM
      INTEGER    ACTSTR(ARRSIZ), ACTSIZ, SPCSTR(ARRSIZ), SPCSIZ
 
      LOGICAL    SETEQ, STRCON, CSSIDS
 
      CALL INITGL ('03.03/07')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  open new archive file, with arid = archive identifier
      CALL AVARNM (ARNM)
      ARID = 7
      CALL POPARF (ARID, ARNM)
 
C  *** *** ***   partial archive networks   *** *** ***
C
C  set up structures:
C     CSS     : 101-C, 104-C, with 101-C invoking 104-C
      CALL PDAS
      CALL SETSTR (101, 'L931,E104')
      CALL SETSTR (104, 'L931,L932')
 
C  <archive structures> 101
      CALL SETVS  ('101', SPCSTR, SPCSIZ)
      CALL PARST  (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('1 4', 'When <archive structures> specifies a '  //
     1             'referring structure, but not the structure to ' //
     2             'which it refers, only the specified structure ' //
     3             'should be archived.')
C  <retrieve structure identifiers> to determine:
C     actstr = actual list of structures
C  pass/fail depending on (actstr = [101])
      CALL PRSID (ARID, ARRSIZ, ACTSIZ, ACTSTR)
      CALL IFPF (ACTSIZ .EQ. SPCSIZ .AND. SETEQ(ACTSIZ, ACTSTR, SPCSTR))
 
C  *** *** ***   completing CSS networks   *** *** ***
C
C  clear CSS
      CALL PDAS
C  <retrieve structures> 101
      CALL PREST  (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('9 12 19', 'If <retrieve structures> specifies a ' //
     1             'referring structure but not the structure to '    //
     2             'which it refers, and no structure with the '      //
     3             'referred identifier exists in the CSS, then an '  //
     4             'empty structure should be created in the CSS '    //
     5             'with the corresponding identifier when the '      //
     6             'referring structure is retrieved.')
C  pass/fail depending on (CSS = 101-C, 104-E)
      IF (CSSIDS ('101,104')) THEN
         CALL IFPF (STRCON (101, '67,931,66,104') .AND.
     1              STRCON (104, ' '))
      ELSE
         CALL FAIL
      ENDIF
 
C  set up structures:
C     archive : 101-C, 104-C, with 101-C invoking 104-C
      CALL PDAS
      CALL SETSTR (101, 'E104,L3')
      CALL SETSTR (104, 'L3')
      CALL PDASAR (ARID)
      CALL PARAST (ARID)
C  clear CSS
      CALL PDAS
C  <retrieve structures> 101
      CALL PREST  (ARID, SPCSIZ, SPCSTR)
 
      CALL SETMSG ('9 12 19', 'If <retrieve structures> specifies a ' //
     1             'referring structure but not the structure to '    //
     2             'which it refers, and no structure with the '      //
     3             'referred identifier exists in the CSS, then an '  //
     4             'empty structure should be created in the CSS '    //
     5             'with the corresponding identifier when the '      //
     6             'referring structure is retrieved, even if the '   //
     7             'referred structure exists in the archive.')
C  pass/fail depending on (CSS = 101-C, 104-E)
      IF (CSSIDS ('101,104')) THEN
         CALL IFPF (STRCON (101, '66,104,67,3') .AND.
     1              STRCON (104, ' '))
      ELSE
         CALL FAIL
      ENDIF
 
C  <close archive file> with arid
      CALL PCLARF (ARID)
 
666   CONTINUE
      CALL ENDIT
      END
