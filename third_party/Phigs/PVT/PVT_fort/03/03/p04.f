C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/04                              *
C  *    TEST TITLE : Selection of structures for           *
C  *                 retrieving                            *
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

      INTEGER     ARRSIZ
      PARAMETER  (ARRSIZ = 50)

      INTEGER     SPCSTR(ARRSIZ)
      INTEGER     ARID,ARNM, SPCSIZ

      LOGICAL     CSSIDS

      CALL INITGL ('03.03/04')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  open new archive file, with arid = archive identifier
      CALL AVARNM (ARNM)
      ARID = 4
      CALL POPARF (ARID, ARNM)
C  <delete all structures from archive> to ensure empty file
      CALL PDASAR (ARID)

C  set up standard networks in archive = arid
      CALL STDCSS
      CALL PARAST (ARID)
C  <delete all structures> to ensure empty CSS
      CALL PDAS

C  spcstr = specified structures = 114,111,115,109,140,142
      CALL SETVS ('114,111,115,109,140,142', SPCSTR, SPCSIZ)

C  <retrieve structures> with arid, spcstr
      CALL PREST (ARID, SPCSIZ, SPCSTR)

      CALL SETMSG ('9 12', 'When no references to non-existent '   //
     1             'structures are created, then exactly those '   //
     2             'structures explicitly listed in the input '    //
     3             'parameter of <retrieve structures> should be ' //
     4             'reported as existing in a previously empty CSS.')
      CALL IFPF (CSSIDS ('114,111,115,109,140,142'))

C  <delete all structures> to ensure empty CSS
      CALL PDAS
C  spcstr = specified structures = 107,114,105
      CALL SETVS ('107,114,105', SPCSTR, SPCSIZ)

C  <retrieve structure networks> with arid, spcstr
      CALL PRESN (ARID, SPCSIZ, SPCSTR)

      CALL SETMSG ('10 12', 'The structures explicitly listed in '   //
     1             'the input parameter of <retrieve structure '     //
     2             'networks> and all their descendants in the '     //
     3             'archive file should be reported as existing in ' //
     4             'a previously empty CSS.')
      CALL IFPF (CSSIDS ('105,110,114,108,111,115,107,113'))

C  <delete all structures> to ensure empty CSS
      CALL PDAS
C  <retrieve all structures> with arid
      CALL PRAST (ARID)

      CALL SETMSG ('11 12', '<Retrieve all structures> should cause ' //
     1             'all structures currently in the archive file to ' //
     2             'be reported as existing in a previously empty '   //
     3             'CSS.')
      CALL IFPF (CSSIDS ('100,101,102,103,104,105,106,107,108,109,' //
     1                   '110,111,113,114,115,120,130,140,142'))

C  <close archive file> with arid
      CALL PCLARF (ARID)

666   CONTINUE
      CALL ENDIT
      END
