C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.02/08                              *
C  *    TEST TITLE : Categories of picture change          *
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

C clear control flag
      INTEGER    PCONDI,   PALWAY
      PARAMETER (PCONDI=0, PALWAY=1)
C deferral mode
      INTEGER    PASAP,   PBNIG,   PBNIL,   PASTI,   PWAITD
      PARAMETER (PASAP=0, PBNIG=1, PBNIL=2, PASTI=3, PWAITD=4)
C display surface empty
      INTEGER    PNEMPT,   PEMPTY
      PARAMETER (PNEMPT=0, PEMPTY=1)
C dynamic modification
      INTEGER    PIRG,   PIMM,   PCBS
      PARAMETER (PIRG=0, PIMM=1, PCBS=2)
C modification mode
      INTEGER    PNIVE,   PUWOR,   PUQUM
      PARAMETER (PNIVE=0, PUWOR=1, PUQUM=2)
C state of visual representation
      INTEGER    PVROK,   PVRDFR,   PVRSIM
      PARAMETER (PVROK=0, PVRDFR=1, PVRSIM=2)

C parameters for <inquire workstation connection and type>
      INTEGER   SPECWT, SPECON

      INTEGER   PCSEV(17), NG, IWK, ISTR, REPSEV
      INTEGER   PCC, ACTSEV, ACTPCC, ITRIM

      LOGICAL   VALCAT, SVROK

      CHARACTER PCCCHR*2, PCCTAB(17)*34, SEVLBL(PIRG:PCBS)*3
      CHARACTER PCCMSG*34, SEVMSG*3, SVRMSG*40, SVRLST*3

      DATA PCSEV  / 17 * 666 /

      CALL INITGL ('05.02/08')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C  picture change categories are numbered from 1 to 17:
C    workstation changes :  1 to 12
C    structure changes   : 13 to 17
      CALL SETPCL (PCCTAB)

C  <set display update state> WAIT, UQUM
      CALL PSDUS (WKID, PWAITD, PUQUM)
C  valcat = true = valid category
      VALCAT = .TRUE.
C  <inquire dynamics of workstation attr> to determine
C   pcsev(1 to 12) = picture change severity
      CALL PQDSWA (SPECWT, ERRIND,  PCSEV(01), PCSEV(02), PCSEV(03),
     1                   PCSEV(04), PCSEV(05), PCSEV(06), PCSEV(07),
     2                   PCSEV(08), PCSEV(09), PCSEV(10), PCSEV(11),
     3                   PCSEV(12) )
C  ng = an invalid code for picture change
      NG = -1
      DO 100 IWK = 1,12
         IF ((PCSEV(IWK) .LT. PIRG .OR. PCSEV(IWK) .GT. PCBS) .OR.
     1       ERRIND .NE. 0) THEN
             VALCAT = .FALSE.
             PCSEV(IWK) = NG
         ENDIF
100   CONTINUE
      CALL SETMSG ('6', '<Inquire dynamics of workstation '           //
     1             'attributes> should report the modification '      //
     2             'severity for the 12 kinds of workstation '        //
     3             'changes as IMM,IRG,CBS.')
      CALL IFPF (VALCAT)

      VALCAT = .TRUE.
C  <inquire dynamics of struc> to determine
C     pcsev(13 to 17) = picture change severity
      CALL PQDSTR (SPECWT, ERRIND, PCSEV(13), PCSEV(14), PCSEV(15),
     1                             PCSEV(16), PCSEV(17))

      DO 200 ISTR = 13, 17
         IF ((PCSEV(ISTR) .LT. PIRG .OR. PCSEV(ISTR) .GT. PCBS) .OR.
     1       ERRIND .NE. 0) THEN
            VALCAT = .FALSE.
            PCSEV(IWK) = NG
         ENDIF
200   CONTINUE
      CALL SETMSG ('7', '<Inquire dynamics of structures> should '    //
     1             'report the modification severity for the 5 '      //
     2             'kinds of structure changes as IMM,IRG,CBS.')
      CALL IFPF (VALCAT)

C  severity label:
      SEVLBL(PIRG) = 'IRG'
      SEVLBL(PCBS) = 'CBS'
      SEVLBL(PIMM) = 'IMM'

C  invoke PICENV to set up standard picture environment
      CALL PICENV (WKID)

C  pcc = 1 to 17 = picture change category
      DO 350 PCC = 1, 17
         REPSEV = PCSEV(PCC)
         IF (REPSEV .EQ. NG) GOTO 310

C <redraw all structures> to make svr CORRECT
         CALL PRST (WKID, PALWAY)
C invoke PICCHG to generate an example of pcc
         WRITE (PCCCHR, '(I2)') PCC
         CALL PICCHG (WKID, '0,1,2', PCCCHR, ACTSEV, ACTPCC)
         IF (ACTPCC .EQ. 0) GOTO 310

C        calculate expected SVRs and label,
C           based on sevrty, defmod, modmd, and oldsvr
         CALL EXSVRS (REPSEV, PWAITD, PUQUM, PVROK, SVRLST, SVRMSG)

         PCCMSG = PCCTAB (PCC)
         SEVMSG = SEVLBL (REPSEV)
         CALL SETMSG ('6 7 13 14 15 16 19 20 21 24 26 28', 'Picture ' //
     1                'change category ' // PCCMSG(1:ITRIM(PCCMSG))   //
     2                ' reported as having severity = ' // SEVMSG     //
     3                ' should set state of visual representation to '//
     4                SVRMSG(1:ITRIM(SVRMSG)) // '.')
         CALL IFPF (SVROK (WKID, SVRLST))
310      CONTINUE
350   CONTINUE

666   CONTINUE
      CALL ENDIT
      END
