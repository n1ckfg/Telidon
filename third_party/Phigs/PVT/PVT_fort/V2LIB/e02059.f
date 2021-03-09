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
