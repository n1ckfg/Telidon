C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/08                              *
C  *    TEST TITLE : Archiving and retrieving with         *
C  *                 multiple files                        *
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
 
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6
      INTEGER    MXARNO, ARID1, ARID2, ARNM
      INTEGER    SPCST1(ARRSIZ), SPCSZ1, SPCST2(ARRSIZ), SPCSZ2
      INTEGER    ACTST1(ARRSIZ), ACTSZ1, ACTST2(ARRSIZ), ACTSZ2
 
      LOGICAL    SETEQ, CSSIDS, AR1OK, AR2OK
 
      CHARACTER  CHSPC1*30, CHSPC2*30
 
      CALL INITGL ('03.03/08')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C  <inquire phigs facilities> to determine
C     mxarno = maximum number of simultaneously open archive files
      CALL PQPHF (0, ERRIND, IDUM1, MXARNO, IDUM2, IDUM3,
     1            IDUM4, IDUM5, IDUM6)
      CALL CHKINQ ('pqphf', ERRIND)
 
      IF (MXARNO .LE. 1) THEN
         CALL INMSG ('Skippping tests: cannot open multiple ' //
     1               'archive files.')
         GOTO 666
      ENDIF
 
C  set up standard networks in CSS
      CALL STDCSS
C  open 2 archive files
      CALL AVARNM (ARNM)
      ARID1 = 11
      CALL POPARF (ARID1, ARNM)
 
      CALL AVARNM (ARNM)
      ARID2 = 12
      CALL POPARF (ARID2, ARNM)
 
      CHSPC1 = '111,114,115'
      CHSPC2 = '109,113'
      CALL SETVS (CHSPC1, SPCST1, SPCSZ1)
      CALL SETVS (CHSPC2, SPCST2, SPCSZ2)
 
C  <archive structures> spcst1 into arid1 and spcst2 into arid2
      CALL PDASAR (ARID1)
      CALL PDASAR (ARID2)
      CALL PARST  (ARID1, SPCSZ1, SPCST1)
      CALL PARST  (ARID2, SPCSZ2, SPCST2)
 
C  <retrieve structure identifiers> with arid1 and arid2
      CALL PRSID (ARID1, ARRSIZ, ACTSZ1, ACTST1)
      CALL PRSID (ARID2, ARRSIZ, ACTSZ2, ACTST2)
 
      CALL SETMSG ('1 4', 'If more than one archive file is open, ' //
     1             '<archive structures> should affect only the '   //
     2             'open archive file specified in its parameter '  //
     3             'list.')
C  pass/fail depending on (actst1 = spcst1 and actst2 = spcst2)
      CALL IFPF (ACTSZ1 .EQ. SPCSZ1             .AND.
     1           ACTSZ2 .EQ. SPCSZ2             .AND.
     2           SETEQ (ACTSZ1, ACTST1, SPCST1) .AND.
     3           SETEQ (ACTSZ2, ACTST2, SPCST2) )
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid1
      CALL PRAST (ARID1)
      AR1OK = CSSIDS (CHSPC1)
 
C  clear CSS
      CALL PDAS
C  <retrieve all structures> from arid2
      CALL PRAST (ARID2)
      AR2OK = CSSIDS (CHSPC2)
 
      CALL SETMSG ('11 12', 'If more than one archive file is open, ' //
     1             '<retrieve all structures> should affect only '    //
     2             'the open archive file specified in its '          //
     3             'parameter list.')
      CALL IFPF (AR1OK .AND. AR2OK)
 
C  <close archive file> with arid1 and arid2
      CALL PCLARF (ARID1)
      CALL PCLARF (ARID2)
 
C  done:
666   CONTINUE
      CALL ENDIT
      END
