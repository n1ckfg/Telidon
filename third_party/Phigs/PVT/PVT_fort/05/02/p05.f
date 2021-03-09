C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.02/05                              *
C  *    TEST TITLE : Deferral mode WAIT and ASTI           *
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

C deferral mode
      INTEGER    PASAP,     PBNIG,     PBNIL,     PASTI,     PWAITD
      PARAMETER (PASAP = 0, PBNIG = 1, PBNIL = 2, PASTI = 3, PWAITD = 4)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C dynamic modification
      INTEGER    PIRG,      PIMM,      PCBS
      PARAMETER (PIRG = 0,  PIMM = 1,  PCBS = 2)
C state of visual representation
C                correct    deferred    simulated
      INTEGER    PVROK,     PVRDFR,     PVRSIM
      PARAMETER (PVROK = 0, PVRDFR = 1, PVRSIM = 2)
C clear control flag
C                conditionally  always
      INTEGER    PCONDI,        PALWAY
      PARAMETER (PCONDI = 0,    PALWAY = 1)


C  Declare program-specific variables
      INTEGER    DEFMOD, MODMD, SEVRTY, OLDSVR, ACTSEV, ACTPCC
      INTEGER    ITRIM, PCC

      LOGICAL    SVROK

      CHARACTER  SVRLBL*20, PCCHAR*2, SVRLST*3
      CHARACTER  PCCLBL*34, PCCTAB(17)*34
      CHARACTER  DEFLBL*4,  DEFTAB(PASAP:PWAITD)*4
      CHARACTER  MODLBL*4,  MODTAB(PNIVE:PUQUM)*4
      CHARACTER  SEVLBL*3,  SEVTAB(PIRG:PCBS)*3, SEVCHR*2
      CHARACTER  OLDLBL*10, OLDTAB(PVROK:PVRSIM)*10, EXPLBL*40
      CHARACTER             SVRCOD(PVROK:PVRSIM)*1

      DATA DEFTAB / 'ASAP', 'BNIG', 'BNIL', 'ASTI', 'WAIT' /
      DATA MODTAB / 'NIVE', 'UWOR', 'UQUM' /
      DATA SEVTAB / 'IRG',  'IMM',  'CBS' /             
      DATA OLDTAB / 'CORRECT', 'DEFERRED', 'SIMULATED' /
      DATA SVRCOD / 'c', 'd', 's' /

      CALL INITGL ('05.02/05')

C open PHIGS and workstation
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPWK (WKID, CONID, WTYPE)

C  picture change categories are numbered from 1 to 17:
C    workstation changes :  1 to 12
C    structure changes   : 13 to 17

C  set pcctab to names of picture change categories
      CALL SETPCL (PCCTAB)

C  invoke PICENV to set up standard picture environment
      CALL PICENV (WKID)

      DO 100 DEFMOD = PWAITD, PASTI, -1
C        set deflbl = string for defmod
         DEFLBL = DEFTAB (DEFMOD)
         IF (DEFMOD .EQ. PASTI) THEN
            SVRLBL = 'DEFERRED or CORRECT'
            SVRLST = 'cd'
         ELSE
            SVRLBL = 'DEFERRED'
            SVRLST = 'd'
         ENDIF
C        <set display update state> defmod, NIVE
         CALL PSDUS (WKID, DEFMOD, PNIVE)
C        for pcc = 1 to 17 = picture change category
         DO 110 PCC = 1,17
C           <redraw all structures>/COND to make state of visual
C           representation = CORRECT
            CALL PRST (WKID, PCONDI)

C           attempt visual change of type pcc
            WRITE (PCCHAR, '(I2)') PCC
            CALL PICCHG (WKID, '0,1,2', PCCHAR, ACTSEV, ACTPCC)
            PCCLBL = PCCTAB(PCC)
            IF (ACTPCC .EQ. 0) THEN
               CALL INMSG ('Picture change failed, NIVE test skipped '//
     1            'for category = ' // PCCLBL (1:ITRIM(PCCLBL)) // '.')
               GOTO 110
            ENDIF

            CALL SETMSG ('3 4 13 14 15 23 29', 'A picture change of ' //
     1                   'category ' // PCCLBL (1:ITRIM(PCCLBL))      //
     2                   ' performed under mode [' // DEFLBL          //
     3                   ', NIVE] should leave the state of visual '  //
     4                   'representation as '                         //
     5                   SVRLBL (1:ITRIM(SVRLBL)) // '.')

C           pass/fail depending on ( svr = DEFERRED or
C                                   (svr = CORRECT  and defmod = ASTI) )
            CALL IFPF (SVROK (WKID, SVRLST))
C        next pcc
110      CONTINUE

         DO 130 MODMD = PUWOR, PUQUM
            MODLBL = MODTAB (MODMD)
         DO 140 SEVRTY = PIRG, PCBS
            SEVLBL = SEVTAB (SEVRTY)
         DO 150 OLDSVR = PVROK, PVRSIM
            OLDLBL = OLDTAB (OLDSVR)
C           attempt to set SVR to oldsvr
            CALL SETSVR (WKID, OLDSVR)

C           <set display update state> defmod, modmd
            CALL PSDUS (WKID, DEFMOD, MODMD)

C           if (current_SVR not= oldsvr) goto skip_svr
            IF (.NOT. SVROK (WKID, SVRCOD(OLDSVR))) THEN
               CALL INMSG ('Cannot set old state of visual '        //
     1              'representation = ' // OLDLBL (1:ITRIM(OLDLBL)) //
     3              '; skipping test for update mode = '            //
     4              '[' // DEFLBL // ', ' // MODLBL                 //
     5              '], picture change severity = ' // SEVLBL       //
     6              ', and old state of visual representation = '   //
     7              OLDLBL (1:ITRIM(OLDLBL)) // '.')
               GOTO 150
            ENDIF

C           attempt to perform sevrty-type operation:
            WRITE (SEVCHR, '(I2)') SEVRTY
            CALL PICCHG (WKID, SEVCHR,
     1                   '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17',
     2                   ACTSEV, ACTPCC)
            IF (ACTSEV .NE. SEVRTY) THEN
               CALL INMSG ('Picture change failed for severity = ' //
     1              SEVLBL // '; skipping test for update mode = ' //
     2              '[' // DEFLBL // ', ' // MODLBL                //
     3              '], picture change severity = ' // SEVLBL      //
     4              ', and old state of visual representation = '  //
     5              OLDLBL (1:ITRIM(OLDLBL)) // '.')
               GOTO 150
            ENDIF

C           calculate expected SVRs and label,
C              based on sevrty, defmod, modmd, and oldsvr
            CALL EXSVRS (SEVRTY, DEFMOD, MODMD, OLDSVR, SVRLST, EXPLBL)
C           set up label for expected value(s)

            CALL SETMSG ('3 4 13 14 15 19 20 21 24 25 26 27 28 29',
     1                   'If update mode = [' // DEFLBL // ', '       //
     2                   MODLBL // '], picture change severity = '    //
     3                   SEVLBL // ', and old state of visual '       //
     4                   'representation = '                          //
     5                   OLDLBL (1:ITRIM(OLDLBL)) // ', then current '//
     6                   'state of visual representation should be '  //
     7                   EXPLBL (1:ITRIM(EXPLBL)) // '.')
            CALL IFPF (SVROK (WKID, SVRLST))

C  skip_svr:
C     next oldsvr
150      CONTINUE
C     next sevrty
140      CONTINUE
C     next modmd
130      CONTINUE

C  next defmod
100   CONTINUE

666   CONTINUE
      CALL ENDIT
      END
