C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.02/07                              *
C  *    TEST TITLE : Deferral mode BNIG                    *
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
C operating mode
C                request  sample    event
      INTEGER    PREQU,   PSAMPL,   PEVENT
      PARAMETER (PREQU=0, PSAMPL=1, PEVENT=2)
C echo switch
      INTEGER    PNECHO,   PECHO
      PARAMETER (PNECHO=0, PECHO=1)

C  Declare program-specific variables
      INTEGER    MODMD, SEVRTY, OLDSVR, INMODE, INCLAS, IND
      INTEGER    ITRIM, PCC, CT, INSTAT, INDEV(6)
      INTEGER    SPECWT, SPECON, ACTSEV, ACTPCC, IWK
      INTEGER    ONWK, IDUM1, IDUM2, IDUM3, INWK, ICONID, IWTYPE
      INTEGER    UNDWAY,   INACT
      PARAMETER (UNDWAY=0, INACT=1)

      LOGICAL    SVROK

      CHARACTER  PCCHAR*2, SVRLST*3
      CHARACTER  PCCLBL*34, PCCTAB(17)*34
      CHARACTER  MODLBL*4,  MODTAB(PNIVE:PUQUM)*4
      CHARACTER  SEVLBL*3,  SEVTAB(PIRG:PCBS)*3, SEVCHR*2
      CHARACTER  OLDLBL*10, OLDTAB(PVROK:PVRSIM)*10, EXPLBL*20
      CHARACTER             SVRCOD(PVROK:PVRSIM)*1
      CHARACTER  CNDLBL*200, CDUM1*1

      DATA MODTAB / 'NIVE', 'UWOR', 'UQUM' /
      DATA SEVTAB / 'IRG',  'IMM',  'CBS' /
      DATA OLDTAB / 'CORRECT', 'DEFERRED', 'SIMULATED' /
      DATA SVRCOD / 'c', 'd', 's' /

      CALL INITGL ('05.02/07')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C wkid is the identifier for the workstation under test;
C inwk identifies some input-type workstation.
      CALL MULTWS (0, 'id', ONWK, IDUM1, IDUM2, IDUM3, CDUM1)
      IF (ONWK .EQ. 0) THEN
         CALL INMSG ('No input workstation available; unable ' //
     1               'to test BNIG.')
         GOTO 667
      ENDIF

      DO 20 IWK = 1,ONWK
         CALL MULTWS (IWK, 'id', IDUM1, INWK, ICONID, IWTYPE, CDUM1)
         IF (INWK .NE. WKID) GOTO 30
20    CONTINUE
      CALL INMSG ('No other input workstation available; using ' //
     1            'local input to test BNIG.')
30    CONTINUE

C open output workstation (primary)
      CALL POPWK (WKID, CONID, WTYPE)
C open input workstation (secondary), if distinct from output
      IF (INWK .NE. WKID) CALL POPWK (INWK, ICONID, IWTYPE)

C  picture change categories are numbered from 1 to 17:
C    workstation changes :  1 to 12
C    structure changes   : 13 to 17

C  set pcctab to names of picture change categories
      CALL SETPCL (PCCTAB)

C  invoke PICENV to set up standard picture environment
      CALL PICENV (WKID)

C  <set display update state> BNIG, NIVE
      CALL PSDUS (WKID, PBNIG, PNIVE)

      CALL PQWKC (INWK, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
C  <inquire number of available logical input devices> for input
C     workstation
C  inclas = input class for which a device is available
      CALL PQLI (SPECWT, ERRIND, INDEV(1), INDEV(2), INDEV(3),
     1                           INDEV(4), INDEV(5), INDEV(6))
      CALL CHKINQ ('pqli', ERRIND)
      DO 100 IND = 1, 6
         IF (INDEV(IND) .GT. 0) THEN
            INCLAS = IND
            GOTO 110
         ENDIF
100   CONTINUE
      CALL UNMSG ('No input devices available for workstation ' //
     1            'reported as OUTIN or INPUT.')
110   CONTINUE

      CT = 0
C  for pcc = 1 to 17 = picture change category
      DO 210 PCC = 1,17
         PCCLBL = PCCTAB(PCC)
         WRITE (PCCHAR, '(I2)') PCC
C        for instat = underway, inactive
         DO 200 INSTAT = UNDWAY, INACT
C           <redraw all structures> to make svr = CORRECT
            CALL PRST (WKID, PCONDI)
            IF (INSTAT .EQ. UNDWAY) THEN
C              activate input:
               CT = CT + 1
               IF (MOD (CT,2) .EQ. 0) THEN
                 INMODE = PSAMPL
               ELSE
                 INMODE = PEVENT
               ENDIF

C              vary order of operation:
               IF (MOD(CT, 3) .EQ. 0) THEN
C                 invoke PICCHG for category = pcc
                  CALL PICCHG (WKID, '0,1,2', PCCHAR, ACTSEV, ACTPCC)
C                 use DOIMOD to set mode of input device to inmode
                  CALL DOIMOD (INWK, INCLAS, INMODE)
               ELSE
                  CALL DOIMOD (INWK, INCLAS, INMODE)
                  CALL PICCHG (WKID, '0,1,2', PCCHAR, ACTSEV, ACTPCC)
               ENDIF

               IF (ACTPCC .NE. PCC) THEN
                  CALL INMSG ('Cannot do picture change, '         //
     1                 '[BNIG, NIVE] test with input underway '    //
     2                 'skipped for category = '                   //
     3                 PCCLBL (1:ITRIM(PCCLBL)) // '.')
                  GOTO 180
               ENDIF

               CALL SETMSG ('3 4 13 30 32', 'A picture change of '    //
     1                      'category ' // PCCLBL (1:ITRIM(PCCLBL))   //
     2                      ' performed under mode [BNIG, NIVE] '     //
     3                      'when input is underway should leave the '//
     4                      'state of visual representation CORRECT.')
               CALL IFPF (SVROK(WKID, 'c'))
C  skip_pcc_act:
180            CONTINUE
C              deactivate global input:
               CALL DOIMOD (INWK, INCLAS, PREQU)
            ELSE
C input is inactive
C              invoke PICCHG for category = pcc
               CALL PICCHG (WKID, '0,1,2', PCCHAR, ACTSEV, ACTPCC)

               IF (ACTPCC .NE. PCC) THEN
                  CALL INMSG ('Cannot do picture change, '         //
     1                 '[BNIG, NIVE] test with input inactive '    //
     2                 'skipped for category = '                   //
     3                 PCCLBL (1:ITRIM(PCCLBL)) // '.')
                  GOTO 185
               ENDIF

               CALL SETMSG ('3 4 13 15 32', 'A picture change of '    //
     1                      'category ' // PCCLBL (1:ITRIM(PCCLBL))   //
     2                      ' performed under mode [BNIG, NIVE] '     //
     3                      'when input is inactive should leave '    //
     4                      'the state of visual representation '     //
     5                      'DEFERRED or CORRECT.')
               CALL IFPF (SVROK(WKID, 'dc'))
C  skip_pcc_inact:
185            CONTINUE
            ENDIF
C  next instat
200      CONTINUE
C  next pcc
210   CONTINUE

      CT = 0
      DO 330 MODMD = PUWOR, PUQUM
         MODLBL = MODTAB(MODMD)
      DO 340 SEVRTY = PIRG, PCBS
         SEVLBL = SEVTAB(SEVRTY)
         WRITE (SEVCHR, '(I2)') SEVRTY
      DO 350 OLDSVR = PVROK, PVRSIM
         OLDLBL = OLDTAB (OLDSVR)
         CNDLBL = 'update mode = [BNIG, ' // MODLBL // '], '     //
     1            'picture change severity = ' // SEVLBL // ', ' //
     2            'old state of visual representation = '        //
     3            OLDLBL
      DO 360 INSTAT = UNDWAY, INACT
C        attempt to set SVR to oldsvr
         CALL SETSVR (WKID, OLDSVR)

C        <set display update state> BNIG, modmd
         CALL PSDUS (WKID, PBNIG, MODMD)
C        if (current_SVR not= oldsvr) goto skip_oldsvr
         IF (.NOT. SVROK (WKID, SVRCOD(OLDSVR))) THEN
            CALL INMSG ('Cannot set old state of visual '           //
     1           'representation = ' // OLDLBL (1:ITRIM(OLDLBL))    //
     2           '; skipping test for ' // CNDLBL(1:ITRIM(CNDLBL))  //
     3           '.')
            GOTO 355
         ENDIF

         IF (INSTAT .EQ. UNDWAY) THEN
            CT = CT + 1
            IF (MOD(CT, 2) .EQ. 0) THEN
               INMODE = PSAMPL
            ELSE
               INMODE = PEVENT
            ENDIF

C           vary order of operation:
            IF (MOD(CT, 3) .EQ. 0) THEN
C              attempt to perform sevrty-type operation:
               CALL PICCHG (WKID, SEVCHR,
     1                      '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17',
     2                      ACTSEV, ACTPCC)
               CALL DOIMOD (INWK, INCLAS, INMODE)
            ELSE
               CALL DOIMOD (INWK, INCLAS, INMODE)
C              attempt to perform sevrty-type operation:
               CALL PICCHG (WKID, SEVCHR,
     1                      '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17',
     2                      ACTSEV, ACTPCC)
            ENDIF

            IF (ACTSEV .NE. SEVRTY) THEN
               CALL INMSG ('Cannot do picture change for severity = ' //
     1              SEVLBL // '; skipping test for '                  //
     2              CNDLBL(1:ITRIM(CNDLBL)) // ', and input underway.')
               GOTO 315
            ENDIF

            CALL SETMSG ('3 4 13 30 32', 'If '                        //
     1                   CNDLBL(1:ITRIM(CNDLBL)) // ', and input is ' //
     2                   'underway, then current state of visual '    //
     3                   'representation should be CORRECT.')
            CALL IFPF (SVROK (WKID, 'c'))
C  skip_sev:
315         CONTINUE
C           deactivate global input:
            CALL DOIMOD (INWK, INCLAS, PREQU)
         ELSE
C input is inactive
C           attempt to perform sevrty-type operation:
            CALL PICCHG (WKID, SEVCHR,
     1                   '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17',
     2                   ACTSEV, ACTPCC)

            IF (ACTSEV .NE. SEVRTY) THEN
               CALL INMSG ('Cannot do picture change for severity = ' //
     1              SEVLBL // '; skipping test for '                  //
     2              CNDLBL(1:ITRIM(CNDLBL)) // ', and input inactive.')
               GOTO 325
            ENDIF

C           calculate expected SVRs and label,
C              based on sevrty, defmod, modmd, and oldsvr
            CALL EXSVRS (SEVRTY, PBNIL, MODMD, OLDSVR, SVRLST, EXPLBL)

            CALL SETMSG ('3 4 13 14 15 32', 'If '                     //
     1                   CNDLBL(1:ITRIM(CNDLBL)) // ', and input is ' //
     2                   'inactive, then current state of visual '    //
     3                   'representation should be '                  //
     4                   EXPLBL (1:ITRIM(EXPLBL)) // '.')
            CALL IFPF (SVROK (WKID, SVRLST))
325         CONTINUE
         ENDIF
C  next instat
360   CONTINUE
C  skip_oldsvr:
355   CONTINUE
C  next oldsvr
350   CONTINUE
C  next sevrty
340   CONTINUE
C  next modmd
330   CONTINUE

666   CONTINUE
C close output workstation
      CALL PCLWK (WKID)
C close input workstation, if needed, and PHIGS
      IF (INWK .NE. WKID) CALL PCLWK (INWK)
667   CONTINUE
      CALL ENDIT
      END
