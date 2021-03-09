C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02052                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02052 (USEPRM)
 
C  E02052 tests the handling of error number 52
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150
 
      INTEGER      USEPRM, IX, IDUM1, NMTYPE, MXTYPE, THISTY

      LOGICAL      STREQ
 
      CURCON  = 'the workstation type is not recognized ' //
     1          'by the implementation'
      CALL SETVS ('52,55', EXPERR, EXPSIZ)
      ERRSRS = '2'
      CALL ESETUP (USEPRM)
 
      CALL PQEWK (1, ERRIND, NMTYPE, MXTYPE)
      CALL CHKINQ ('pqewk', ERRIND)
      DO 50 IX = 1, NMTYPE
         CALL PQEWK (IX, ERRIND, IDUM1, THISTY)
         CALL CHKINQ ('pqewk', ERRIND)
         IF (THISTY .GT. MXTYPE) THISTY = MXTYPE
50    CONTINUE
 
      CALL ROPWK (WKID, CONID, MXTYPE+1)
      CALL TSTIGN (STREQ('OC**'))
 
C  **** Examine saved errors
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02053                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02053 (USEPRM)
 
C  E02053 tests the handling of error number 53
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150
 
      INTEGER      USEPRM, IX,IDUM1,IDUM2,IDUM3,NWKALL, NUMOWK, OPWKID
      INTEGER      OWKID, OCONID, OWTYPE
      CHARACTER*1  CDUM, OWCAT
      LOGICAL      STREQ, IGNOK
 
      CURCON =  'the specified workstation identifier is in use'
      CALL SETVS ('53', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)

C  **** Generate errors

      IGNOK = .TRUE.
      CALL MULTWS (0, 'a',NWKALL,IDUM1,IDUM2,IDUM3,CDUM)
      DO 150 IX = 1, NWKALL
         CALL MULTWS (IX, 'a',IDUM1,OWKID,OCONID,OWTYPE,
     1                OWCAT)
         CALL POPWK (OWKID, OCONID, OWTYPE)
         CALL ROPWK (OWKID, OCONID, OWTYPE)
         CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
         CALL CHKINQ ('pqopwk', ERRIND)
         IF (.NOT. (STREQ('OO**') .AND. NUMOWK.EQ.1 .AND.
     1              OPWKID.EQ.OWKID)) IGNOK = .FALSE.
         CALL PCLWK (OWKID)
150   CONTINUE
      CALL TSTIGN (IGNOK)
 
C  **** Examine saved errors
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02054                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02054 (USEPRM)
 
C  E02054 tests the handling of error number 54
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150
 
C control flag
C                conditionally  always
      INTEGER    PCONDI,        PALWAY
      PARAMETER (PCONDI = 0,    PALWAY = 1)
C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)
C modification mode
      INTEGER    PNIVE,     PUWOR,     PUQUM
      PARAMETER (PNIVE = 0, PUWOR = 1, PUQUM = 2)
C relative input priority
      INTEGER     PHIGHR,     PLOWER
      PARAMETER  (PHIGHR=0,   PLOWER=1)
C deferring model
      INTEGER     PASAP,     PBNIG,    PBNIL,    PAST1,    PWAIT
      PARAMETER  (PASAP=0,   PBNIG=1,  PBNIL=2,  PAST1=3,  PWAIT=4)
 
      INTEGER   USEPRM, COLIA(1,1), ISIZ, XYCLPI, BCLIPI
      INTEGER   FCLIPI, NUMOWK, OPWKID
      REAL      VWORMT(4,4), VWMPMT(4,4), VWCPLM(6), CSPEC(3)
      LOGICAL   STREQ
 
      CURCON = 'the specified workstation is not open'
 
      CALL SETVS ('54,3', EXPERR, EXPSIZ)
      ERRSRS = '4'
      CALL ESETUP (USEPRM)
 
C   generate errors 
      CALL RCLWK (WKID)
      CALL TSTIGN (STREQ('OC**'))
                              
      CALL RRST (WKID, PALWAY)
      CALL TSTIGN (STREQ('OC**'))
                              
      CALL RUWK (WKID, PPERFO)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL RSTXR (WKID, 1, 1, PSTRP, 1., 0.1, 1)
      CALL TSTIGN (STREQ('OC**'))
 
      CALL SETVS ('1', COLIA, ISIZ)
      CALL RSPAR (WKID, 1,1,1,1,1,1,1, COLIA)
 
      CALL SETRVS ('1.,0.,0.', CSPEC, ISIZ)
      CALL RSCR (WKID, 1, 3, CSPEC)
 
      CALL RSHRM (WKID, 0)
 
      CALL IDMAT (4, VWORMT)
      CALL IDMAT (4, VWMPMT)
      CALL SETRVS ('0.,1.,0.,1.,0.,1.', VWCPLM, ISIZ)
      XYCLPI = PCLIP
      BCLIPI = PCLIP
      FCLIPI = PCLIP
      CALL RSVWR3 (WKID, 1, VWORMT, VWMPMT, VWCPLM, XYCLPI, BCLIPI,
     1             FCLIPI)
 
      CALL RSVTIP (WKID, 1, 1, PHIGHR)
 
      CALL POPST (101)
      CALL RUPOST (WKID, 101)
      CALL TSTIGN (STREQ('OCO*'))
      CALL PCLST
 
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL RRST (WKID+1, PALWAY)
      CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. NUMOWK.EQ.1 .AND.
     1             OPWKID.EQ.WKID)
 
      CALL RSDUS (WKID+1, PASAP, PNIVE)
 
      CALL RSPAR (WKID+1, 1,1,1,1,1,1,1, COLIA)
 
      CALL RSWKW (WKID+1, 0.,1.,0.,1.)
      CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OO**') .AND. NUMOWK.EQ.1 .AND.
     1             OPWKID.EQ.WKID)
 
      CALL POPST (101)
      CALL RPOST (WKID+1, 101, 1.0)
      CALL PQOPWK (1, ERRIND, NUMOWK, OPWKID)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OOO*') .AND. NUMOWK.EQ.1 .AND.
     1             OPWKID.EQ.WKID)
 
      CALL PCLST
      CALL PCLWK (WKID)
 
C  examine saved errors
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02056                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02056 (USEPRM)
 
C  E02056 tests the handling of error number 56.
      INTEGER USEPRM
 
      CALL SETMSG ('6', 'Test for error 56 (writing to workstation ' //
     1             'not of category MO) not yet available.')
      CALL PASS
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02057                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02057 (USEPRM)
 
C  E02057 tests the handling of error number 57.
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150
 
C workstation category
      INTEGER    POUTPT,     PINPUT,     POUTIN,     PMO,     PMI
      PARAMETER (POUTPT = 0, PINPUT = 1, POUTIN = 2, PMO = 3, PMI = 4)

C  relative input priority
      INTEGER     PHIGHR,   PLOWER
      PARAMETER  (PHIGHR=0, PLOWER=1)
 
      INTEGER   USEPRM, ISIZ, NWKMI,IDUM1,IDUM2,IDUM3
      INTEGER   OWKID,OCONID,OWTYPE, RNDINT
      CHARACTER*1   CDUM, OWCAT

      REAL  ROTMT2(3,3), MAPMT2(3,3), LIMIT2(6)

      LOGICAL  STREQ
 
      CURCON = 'the specified workstation is of category MI'
      CALL SETVS ('57', EXPERR, EXPSIZ)
      ERRSRS = '7'
      CALL ESETUP (USEPRM)
 
      CALL MULTWS (0, 'n',NWKMI,IDUM1,IDUM2,IDUM3,CDUM)
      IF (NWKMI .EQ. 0) THEN
         CALL INMSG ('There is no accessible workstation with '//
     1               'category of MI, the test is skipped.')
         RETURN
      ENDIF

      CALL MULTWS (RNDINT(1,NWKMI), 'n', IDUM1,OWKID,OCONID,OWTYPE,
     1             OWCAT)

C  **** Generate errors
 
      CALL POPWK (OWKID, OCONID, OWTYPE)
                               
      CALL ETR (.4, .6, MAPMT2)
      CALL ETR (.5, .7, ROTMT2)
      CALL SETRVS ('0.1,0.9,0.2,0.9', LIMIT2, ISIZ)   
      CALL RSVWR (OWKID, 1,ROTMT2,MAPMT2,LIMIT2,0)
      CALL TSTIGN (STREQ('OO**'))

      CALL RSVTIP (OWKID, 1, 1, 1)
      CALL RSWKW  (OWKID, 0.,1.,0.,1.)

      CALL RSWKV (OWKID, 0.,1.,0.,1.)
      CALL PCLWK (OWKID)
 
C  **** Examine saved errors
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02058                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02058 (USEPRM)
 
C  E02058 tests the handling of error number 58.
      INTEGER USEPRM
 
      CALL SETMSG ('8', 'Test for error 58 (metafile retrieval '   //
     1             'from workstation not of category MI) not yet ' //
     1             'available.')
      CALL PASS
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02059                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02059 (USEPRM)
 
C  E02059 tests the handling of error number 59.
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150
 
C off/on switch for edge flag and error handling mode
      INTEGER    POFF,     PON
      PARAMETER (POFF = 0, PON = 1)
 
C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)
 
C colour model
      INTEGER    PRGB,     PCIE,     PHSV,     PHLS
      PARAMETER (PRGB = 1, PCIE = 2, PHSV = 3, PHLS = 4)
 
C workstation category
      INTEGER    POUTPT,     PINPUT,     POUTIN,     PMO,     PMI
      PARAMETER (POUTPT = 0, PINPUT = 1, POUTIN = 2, PMO = 3, PMI = 4)
 
      INTEGER    USEPRM, NWKNOT, IDUM1,IDUM2,IDUM3
      INTEGER    OWKID,OCONID,OWTYPE
      INTEGER    IIN2,INSET2(10), IEX2,EXSET2(10), RNDINT

      CHARACTER*1  CDUM, OWCAT

      LOGICAL    STREQ
 
      CURCON = 'the workstation type does not have ' //
     1         'output capability'
      CALL SETVS ('59', EXPERR, EXPSIZ)
      ERRSRS = '9'
      CALL ESETUP (USEPRM)
 
      CALL MULTWS (0, 'in', NWKNOT,IDUM1,IDUM2,IDUM3,CDUM)
      IF (NWKNOT .EQ. 0) THEN
         CALL INMSG ('All accessible workstations have output '//
     1               'capability. This test is skipped.')
         RETURN
      ENDIF
 
      CALL MULTWS (RNDINT(1,NWKNOT), 'in', IDUM1,OWKID,OCONID,
     1             OWTYPE,OWCAT)
 
C  **** Generate errors:
 
      CALL POPWK (OWKID,OCONID,OWTYPE)
      CALL RUWK  (OWKID, 0)
 
      CALL RSPLR (OWKID,1,1,1.0,1)
 
      CALL RSTXR (OWKID,1,1,PSTRP,1.,1.,0)
 
      CALL RSEDR (OWKID,1,POFF,1,1.0,0)
 
      CALL SETVS ('1,5,2',INSET2, IIN2)
      CALL SETVS ('4',EXSET2,IEX2)
      CALL RSIVFT (OWKID,IIN2,INSET2,IEX2,EXSET2)
 
      CALL RSCMD (OWKID, PRGB)
 
      CALL POPST (101)
      CALL RPOST (OWKID,100,0.5)
      CALL TSTIGN (STREQ('OOO*'))
 
      CALL PCLST
      CALL PCLWK (OWKID)
 
C  **** Examine saved errors
 
      CALL ENDERR
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02060                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02060 (USEPRM)
 
C  E02060 tests the handling of error number 60.
      INTEGER USEPRM
 
      CALL SETMSG ('10', 'Test for error 60 (using pick on '     //
     1             'workstation not of category OUTIN) not yet ' //
     2             'available.')
      CALL PASS
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02061                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02061 (USEPRM)
 
C  E02061 tests the handling of error number 61.
      INTEGER USEPRM
 
      CALL SETMSG ('11', 'Test for error 61 (graphical input from ' //
     1             'workstation not of category OUTIN or INPUT) '   //
     2             'not yet available.')
      CALL PASS
 
      END
 
C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 09.01.02/e02063                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************
 
      SUBROUTINE E02063 (USEPRM)
 
C  E02063 tests the handling of error number 63.
 
      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)
 
      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150
 
      INTEGER    IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,IDUM6
      INTEGER    MAXWK, USEPRM, IX, NMOPWK
      INTEGER    NWKALL,OWKID,OCONID,OWTYPE
      CHARACTER  CDUM, OWCAT
      LOGICAL    STREQ

      CURCON = 'it would exceed the maximum number of ' //
     1         'simultaneously open workstations'
 
      CALL SETVS ('63', EXPERR, EXPSIZ)
      ERRSRS = '12'
      CALL ESETUP (USEPRM)
 
      CALL MULTWS (0, 'a', NWKALL,IDUM1,IDUM2,IDUM3,CDUM)
      CALL PQPHF (0, ERRIND, MAXWK,IDUM1,IDUM2,IDUM3,IDUM4,IDUM5,
     1            IDUM6)
      CALL CHKINQ ('pqphf',ERRIND)
 
      IF (NWKALL .LE. MAXWK) THEN
         CALL INMSG ('The number of all accessible workstations '   //
     1               'is less than or equal to maximum number of '  //
     2               'simultaneously open workstations; therefore ' //
     3               'this test is skipped.')
         RETURN
      ENDIF
 
      DO 150 IX = 1, MAXWK+1
         CALL MULTWS (IX, 'a', IDUM1, OWKID, OCONID, OWTYPE, OWCAT)
         IF (IX .LE. MAXWK) THEN
            CALL POPWK (OWKID, OCONID, OWTYPE)
         ELSE
            CALL ROPWK (OWKID, OCONID, OWTYPE)
         ENDIF
150   CONTINUE

      CALL PQOPWK (0, ERRIND, NMOPWK, IDUM1)
      CALL CHKINQ ('pqopwk', ERRIND)
      CALL TSTIGN (STREQ('OO**')  .AND. NMOPWK.EQ.MAXWK)
 
      CALL ENDERR
 
      END
