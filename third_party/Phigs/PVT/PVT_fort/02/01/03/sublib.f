C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.01.03/tstcid                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTCID (ORGID, RESID, ORGSTB, ORGRFB,
     1                   ORGPTB, RSSTB, RSRFB, RSPTB, ORGSTE,
     2                   ORGCHE, ORGPTE, RSSTE, RSCHE, RSPTE,
     3                   SRSTR, TCNUM, EXCSS)

C Input Parameters:
C INTEGER orgid           original structure identifier
C INTEGER resid           resulting structure identifier

C   The following 6 input parameters identify various structure
C   states before the change function is executed.
C INTEGER orgstb          original structure open state (NOPEN, NCLOS)
C INTEGER orgrfb          original structure referenced state (NREF, NNRF)
C INTEGER orgptb          original structure posted state (NPST, NNPT)
C INTEGER rsstb           resulting structure open state (NOPEN, NCLOS)
C INTEGER rsrfb           resulting structure referenced state (NREF, NNRF)
C INTEGER rsptb           resulting structure posted state (NPST, NNPT)

C   The following 6 input parameters identify various expected structure
C   states after the change function is executed.
C INTEGER orgste          original structure open state (NOPEN, NCLOS)
C INTEGER orgche          original structure contents (NEMP, NORG)
C INTEGER orgpte          original structure posted state (NPST, NNPT)
C INTEGER rsste           resulting structure open state (NOPEN, NCLOS)
C INTEGER rsche           resulting structure contents (NEMP, NORG)
C INTEGER rspte           resulting structure posted state (NPST, NNPT)

C CHARACTER srstr         identification of SR numbers
C CHARACTER tcnum         identification of test case number
C CHARACTER excss         representation of expected CSS state


C TSTCID is used to generate the test messages associated with
C <change structure identifer>.  The conditions
C stated are tested and pass/fail is returned.

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

C Enumeration values for subroutine parameters:
C   structure state: non-existent   opened       closed
      INTEGER        NOEXE,         NOPEN,       NCLOS
      PARAMETER     (NOEXE = -1,    NOPEN = 0,   NCLOS = 1)

C   structure posted state:
C                    structure posted     structure not posted
      INTEGER         NPST,                NNPT
      PARAMETER      (NPST = 0,            NNPT = 1)

C   structure reference status:
C                    referenced  not referenced
      INTEGER        NREF,       NNRF
      PARAMETER     (NREF = 2,   NNRF = 3)

C   structure contents:
C                    empty     original
      INTEGER        NEMP,     NORG
      PARAMETER     (NEMP = 0, NORG = 1)

      INTEGER ORGID, RESID, ORGSTB, ORGRFB, ORGPTB, RSSTB,
     1        RSRFB, RSPTB, ORGSTE, ORGCHE, ORGPTE, RSSTE, RSCHE,
     2        RSPTE, INTP1, INTP2, INTP3, INTP4, SRPT, MSGSZ,
     3        CSSSZ, TCSZ, OPSTRA, PSTSTA

      INTEGER ITRIM

      CHARACTER STRG*300, SRSTR*(*), MSGBUF*900, INVMSG*29
      CHARACTER TCNUM*(*), EXCSS*(*)
      CHARACTER*200 STRST1, STRST2, STRST3, STRST4

      LOGICAL CSSEQ, CONTOK

      REAL    RDUM1

C check the input parameters to ensure they are in bounds

      INVMSG = ' has invalid value in TSTCID.'

      IF (ORGSTB .NE. NOEXE  .AND.
     1    ORGSTB .NE. NOPEN  .AND.
     2    ORGSTB .NE. NCLOS)    CALL UNMSG ('Orgstb' // INVMSG)

      IF (ORGRFB .NE. NOEXE .AND.
     1    ORGRFB .NE. NREF  .AND.
     2    ORGRFB .NE. NNRF)     CALL UNMSG ('Orgrfb' // INVMSG)

      IF (ORGPTB .NE. NOEXE .AND.
     1    ORGPTB .NE. NPST  .AND.
     2    ORGPTB .NE. NNPT)     CALL UNMSG ('Orgptb' // INVMSG)

      IF (RSSTB  .NE. NOEXE  .AND.
     1    RSSTB  .NE. NOPEN  .AND.
     2    RSSTB  .NE. NCLOS)    CALL UNMSG ('Rsstb' // INVMSG)

      IF (RSRFB  .NE. NOEXE  .AND.
     1    RSRFB  .NE. NREF   .AND.
     2    RSRFB  .NE. NNRF)     CALL UNMSG ('Rsrfb' // INVMSG)

      IF (RSPTB  .NE. NOEXE  .AND.
     1    RSPTB  .NE. NPST   .AND.
     2    RSPTB  .NE. NNPT)     CALL UNMSG ('Rsptb' // INVMSG)

      IF (ORGSTE .NE. NOEXE  .AND.
     1    ORGSTE .NE. NOPEN  .AND.
     2    ORGSTE .NE. NCLOS)    CALL UNMSG ('Orgste' // INVMSG)

      IF (ORGCHE .NE. NOEXE  .AND.
     1    ORGCHE .NE. NEMP)     CALL UNMSG ('Orgche' // INVMSG)

      IF (ORGPTE .NE. NOEXE  .AND.
     1    ORGPTE .NE. NPST   .AND.
     2    ORGPTE .NE. NNPT)     CALL UNMSG ('Orgpte' // INVMSG)

      IF (RSSTE  .NE. NOPEN  .AND.
     1    RSSTE  .NE. NCLOS)    CALL UNMSG ('Rsste' // INVMSG)

      IF (RSCHE  .NE. NEMP   .AND.
     1    RSCHE  .NE. NORG)     CALL UNMSG ('Rsche' // INVMSG)

      IF (RSPTE  .NE. NPST   .AND.
     1    RSPTE  .NE. NNPT)     CALL UNMSG ('Rspte' // INVMSG)

      CALL TCSCID (ORGSTB, ORGRFB, ORGPTB, STRST1, INTP1)
      CALL TCSCID (RSSTB,  RSRFB,  RSPTB,  STRST2, INTP2)
      CALL TCSCID (ORGSTE, ORGCHE, ORGPTE, STRST3, INTP3)
      CALL TCSCID (RSSTE,  RSCHE,  RSPTE,  STRST4, INTP4)

C Test condition number
      TCSZ = ITRIM (TCNUM)

C generating the string test condition used in setmsg
      MSGBUF = '<Change structure identifier> with the '             //
     1         'precondition being '                                 //
     2         '(original structure = ' // STRST1(1:INTP1)           //
     3         ' and the resulting structure = ' // STRST2(1:INTP2)  //
     4         ') should yield the expected results of (original '   //
     5         'structure = '//STRST3(1:INTP3)//' and resulting '    //
     6         'structure = '//STRST4(1:INTP4)                       //
     7         ') after execution of the function as stated by '     //
     8         'test condition '//TCNUM(1:TCSZ)//' of the '          //
     9         'truth table.'

      SRPT  = ITRIM (SRSTR)
      MSGSZ = ITRIM (MSGBUF)
      CALL SETMSG (SRSTR(1:SRPT), MSGBUF(1:MSGSZ))

C subroutine to set the initial state of the CSS
      CALL STDCSS

C when necessary, initialize the open, close status of the specific
C structure
      IF (ORGSTB .EQ. NOPEN) THEN
         IF (RSSTB  .EQ. NOPEN) THEN
            CALL UNMSG ('Bad pre-condition: both original and ' //
     1                  'resulting OPEN.')
         ELSE
            CALL POPST (ORGID)
         ENDIF
      ELSE
         IF (RSSTB  .EQ. NOPEN) THEN
            CALL POPST (RESID)
         ENDIF
      ENDIF

C when necessary intialize the posting status of the specific structure
      IF (ORGPTB .EQ. NPST) CALL PPOST (WKID, ORGID, 1.)
      IF (RSPTB  .EQ. NPST) CALL PPOST (WKID, RESID, 1.)

C Formulate a string indicating the element types and contents for
C the original structure, before execution of function
      CALL ELSTR (ORGID, STRG)

      CALL PCSTID (ORGID, RESID)

C comparison of the original expected state to the actual state
      CALL ACTST (ORGID, STRG, ORGCHE, OPSTRA, CONTOK, PSTSTA, RDUM1)
      IF (OPSTRA .EQ. ORGSTE      .AND.
     1    CONTOK                  .AND.
     2    PSTSTA .EQ. ORGPTE)        THEN
C OK so far - do nothing
      ELSE
          CALL FAIL
          CALL INMSG ('The actual original structure status is ' //
     1                'incorrect.')
          GOTO 750
      ENDIF

C comparison of the resulting expected state to the actual state
      CALL ACTST (RESID, STRG, RSCHE, OPSTRA, CONTOK, PSTSTA, RDUM1)
      IF (OPSTRA .EQ. RSSTE     .AND.
     1    CONTOK                .AND.
     2    PSTSTA .EQ. RSPTE)       THEN
          CALL PASS
      ELSE
          CALL FAIL
          CALL INMSG ('The actual resulting structure status is ' //
     1                'incorrect.')
      ENDIF

C generate a test condition string dealing with the state of the
C CSS.

 750  CONTINUE
      MSGBUF = '<Change structure identifier> with the '             //
     1         'precondition being '                                 //
     2         '(original structure = ' // STRST1(1:INTP1)           //
     3         ' and resulting structure = ' // STRST2(1:INTP2)      //
     4         ') should change the contents of the CSS in '         //
     5         'accordance with the substitution of the '            //
     6         'resulting identifier for the original '              //
     7         'identifier.'

      CSSSZ = ITRIM (MSGBUF)
      CALL SETMSG (SRSTR(1:SRPT), MSGBUF(1:CSSSZ))

      CALL IFPF (CSSEQ(EXCSS))

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.01.03/tcscid                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TCSCID (OPSTRA, STRSTA, PSTSTA, STRST, INTP)

C     Input Parameters:
C     INTEGER opstra     open structure indicator (NOEXE, NOPEN, NCLOS)
C     INTEGER strsta     structure status indicator (NOEXE, NREF, NNRF,
C                                                    NEMP,  NORG )
C     INTEGER pststa     posted structure indicator (NOEXE, NPST, NNPT)

C     Output Parameters:
C     CHARACTER strst    string indicating a structure's state as
C                        determined by the input parameters
C     INTEGER intp       the actual length of the string

C Tcscid returns a string and its length indicating the state of a
C structure.  The structure can be: open or closed, referenced or not
C referenced, empty or with original contents, and posted or not posted.

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

C Enumeration values for subroutine parameters:
C   structure state: non-existent   opened       closed
      INTEGER        NOEXE,         NOPEN,       NCLOS
      PARAMETER     (NOEXE = -1,    NOPEN = 0,   NCLOS = 1)

C   structure posted state:
C                    structure posted     structure not posted
      INTEGER         NPST,                NNPT
      PARAMETER      (NPST = 0,            NNPT = 1)

C   structure reference status:
C                    referenced  not referenced
      INTEGER        NREF,       NNRF
      PARAMETER     (NREF = 2,   NNRF = 3)

C   structure contents:
C                    empty     original
      INTEGER        NEMP,     NORG
      PARAMETER     (NEMP = 0, NORG = 1)

      INTEGER OPSTRA, PSTSTA, STRSTA, INTP, ITRIM

      CHARACTER STRST*(*)

      CHARACTER OPSTAB (NOPEN:NCLOS)*30, STRTAB (NEMP:NNRF)*30,
     1          PSTTAB (NPST:NNPT)*30
      DATA OPSTAB / 'OPEN,', 'CLOSED,' /

      DATA STRTAB / 'EMPTY,'          ,
     1              'ORIGINAL,'       ,
     2              'REFERENCED,'     ,
     3              'NOT-REFERENCED,' /

      DATA PSTTAB / 'and POSTED', 'and NOT-POSTED'  /

      IF (OPSTRA .EQ. NOEXE) THEN
          IF (PSTSTA .EQ. NOEXE   .AND.
     1        STRSTA .EQ. NOEXE)    THEN
             STRST = 'NON-EXISTENT'
             GOTO 250
          ELSE
             CALL UNMSG ('Problem with the structure state being '//
     1                   'non-existent in subroutine TCSCID.')
          ENDIF
      ENDIF

      STRST        = OPSTAB (OPSTRA)
      INTP  = ITRIM (STRST) + 2
      STRST(INTP:) = STRTAB (STRSTA)
      INTP  = ITRIM (STRST) + 2
      STRST(INTP:) = PSTTAB (PSTSTA)

 250  CONTINUE
      INTP = ITRIM (STRST)

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.01.03/tstcir                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TSTCIR (TCNUM, ORGID, RESID, EXCSS,
     1                   ORGSTB,         ORGPTB, RSSTB,        RSPTB,
     2                   ORGSTE, ORGCHE, ORGPTE, RSSTE, RSCHE, RSPTE)

C Input Parameters:
C CHARACTER tcnum         identification of test case number
C INTEGER   orgid         original structure identifier
C INTEGER   resid         resulting structure identifier
C CHARACTER excss         representation of expected CSS state

C   The following 4 input parameters identify various structure
C   states before the change function is executed.
C INTEGER orgstb          original structure open state (NOPEN, NCLOS)
C INTEGER orgptb          original structure posted state (NPSTO, NNPT)
C INTEGER rsstb           resulting structure open state (NOPEN, NCLOS)
C INTEGER rsptb           resulting structure posted state (NPSTR, NNPT)

C   The following 6 input parameters identify various expected structure
C   states after the change function is executed.
C INTEGER orgste          original structure open state (NOPEN, NCLOS)
C INTEGER orgche          original structure contents (NEMP, NORG)
C INTEGER orgpte          original structure posted state (NPSTR, NPSTO, NNPT)
C INTEGER rsste           resulting structure open state (NOPEN, NCLOS)
C INTEGER rsche           resulting structure contents (NEMP, NORG)
C INTEGER rspte           resulting structure posted state (NPSTR, NPSTO, NNPT)

C TSTCIR is used to generate the test messages associated with
C <change structure identifier and references>.  The conditions
C stated are tested and pass/fail is returned.

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

C Enumeration values for subroutine parameters:
C   structure state: non-existent   opened       closed
      INTEGER        NOEXE,         NOPEN,       NCLOS
      PARAMETER     (NOEXE = -1,    NOPEN = 0,   NCLOS = 1)

C   structure posted state:
C                                           posted        posted
C                    not posted   posted    priority=R,   priority=O
      INTEGER        NNPT,        NPST,     NPSTR,        NPSTO
      PARAMETER     (NNPT = 1,    NPST = 0, NPSTR = 4,    NPSTO = 5)

C   structure contents:
C                    empty     original
      INTEGER        NEMP,     NORG
      PARAMETER     (NEMP = 0, NORG = 1)

      INTEGER ORGID, RESID, ORGSTB, ORGPTB, RSSTB,
     1        RSPTB, ORGSTE, ORGCHE, ORGPTE, RSSTE, RSCHE,
     2        RSPTE, INTP1, INTP2, INTP3, INTP4, MSGSZ,
     3        CSSSZ, TCSZ, OPSTRA, PSTSTA

      INTEGER ITRIM

      CHARACTER STRG*300, MSGBUF*900, INVMSG*29
      CHARACTER TCNUM*(*), EXCSS*(*)

      LOGICAL CSSEQ, CONTOK

      CHARACTER*200 STRST1, STRST2, STRST3, STRST4

      REAL          ORGPRI, RESPRI, PSTPRI

C set priorities
      ORGPRI = 0.1
      RESPRI = 0.2

C check the input parameters to ensure they are in bounds

      INVMSG = ' has invalid value in TSTCIR.'

      IF (ORGSTB .NE. NOEXE  .AND.
     1    ORGSTB .NE. NOPEN  .AND.
     2    ORGSTB .NE. NCLOS)    CALL UNMSG ('Orgstb' // INVMSG)

      IF (ORGPTB .NE. NOEXE .AND.
     1    ORGPTB .NE. NPSTO .AND.
     2    ORGPTB .NE. NNPT)     CALL UNMSG ('Orgptb' // INVMSG)

      IF (RSSTB  .NE. NOEXE  .AND.
     1    RSSTB  .NE. NOPEN  .AND.
     2    RSSTB  .NE. NCLOS)    CALL UNMSG ('Rsstb' // INVMSG)

      IF (RSPTB  .NE. NOEXE  .AND.
     1    RSPTB  .NE. NPSTR  .AND.
     2    RSPTB  .NE. NNPT)     CALL UNMSG ('Rsptb' // INVMSG)

      IF (ORGSTE .NE. NOEXE  .AND.
     1    ORGSTE .NE. NOPEN)    CALL UNMSG ('Orgste' // INVMSG)

      IF (ORGCHE .NE. NOEXE  .AND.
     1    ORGCHE .NE. NEMP)     CALL UNMSG ('Orgche' // INVMSG)

      IF (ORGPTE .NE. NOEXE  .AND.
     1    ORGPTE .NE. NNPT)     CALL UNMSG ('Orgpte' // INVMSG)

      IF (RSSTE  .NE. NOPEN  .AND.
     1    RSSTE  .NE. NCLOS)    CALL UNMSG ('Rsste' // INVMSG)

      IF (RSCHE  .NE. NEMP   .AND.
     1    RSCHE  .NE. NORG)     CALL UNMSG ('Rsche' // INVMSG)

      IF (RSPTE  .NE. NPSTR  .AND.
     1    RSPTE  .NE. NPSTO  .AND.
     2    RSPTE  .NE. NNPT)     CALL UNMSG ('Rspte' // INVMSG)

      CALL TCSCIR (ORGSTB, NOEXE,  ORGPTB, STRST1, INTP1)
      CALL TCSCIR (RSSTB,  NOEXE,  RSPTB,  STRST2, INTP2)
      CALL TCSCIR (ORGSTE, ORGCHE, ORGPTE, STRST3, INTP3)
      CALL TCSCIR (RSSTE,  RSCHE,  RSPTE,  STRST4, INTP4)

C Test condition number
      TCSZ = ITRIM (TCNUM)

C generating the string test condition used in setmsg
      MSGBUF =  '<Change structure identifier and '                  //
     1          'references> with the precondition '                 //
     2          'being (original structure = '//STRST1(1:INTP1)      //
     3          ' and the resulting structure = '//STRST2(1:INTP2)   //
     4          ') should yield the expected results of (original '  //
     5          'structure = '//STRST3(1:INTP3)//' and resulting '   //
     6          'structure = '//STRST4(1:INTP4)                      //
     7          ') after execution of the function as stated by '    //
     8          'test condition '//TCNUM(1:TCSZ)//' of the '         //
     9          'truth table.'

      MSGSZ = ITRIM (MSGBUF)
      CALL SETMSG ('1', MSGBUF(1:MSGSZ))

C subroutine to set the initial state of the CSS
      CALL STDCSS

C when necessary, initialize the open, close status of the specific
C structure
      IF (ORGSTB .EQ. NOPEN) THEN
         IF (RSSTB  .EQ. NOPEN) THEN
            CALL UNMSG ('Bad pre-condition: both original and ' //
     1                  'resulting OPEN.')
         ELSE
            CALL POPST (ORGID)
         ENDIF
      ELSE
         IF (RSSTB  .EQ. NOPEN) THEN
            CALL POPST (RESID)
         ENDIF
      ENDIF

C when necessary intialize the posting status of the specific structure
      IF (ORGPTB .EQ. NPSTO) CALL PPOST (WKID, ORGID, ORGPRI)
      IF (RSPTB  .EQ. NPSTR) CALL PPOST (WKID, RESID, RESPRI)

C Formulate a string indicating the element types and contents for
C the original structure, before execution of function.
      CALL ELSTR (ORGID, STRG)

      CALL PCSTIR (ORGID, RESID)

C get actual original status
      CALL ACTST (ORGID, STRG, ORGCHE, OPSTRA, CONTOK, PSTSTA, PSTPRI)

C comparison of the original expected state to the actual state
      IF (OPSTRA .EQ. ORGSTE    .AND.
     1    CONTOK                .AND.
     2    PSTSTA .EQ. ORGPTE)  THEN
C OK so far - do nothing
      ELSE
C no need to check priority, since original should always be unposted
C or non-existent
           CALL FAIL
           CALL INMSG ('The original structure status is incorrect.')
           GOTO 750
      ENDIF

C get actual resulting status
      CALL ACTST (RESID, STRG, RSCHE, OPSTRA, CONTOK, PSTSTA, PSTPRI)

C comparison of the resulting expected state to the actual state
      IF (OPSTRA .EQ. RSSTE  .AND. CONTOK) THEN
C OK so far - do nothing
      ELSE
          CALL FAIL
          CALL INMSG ('The resulting structure open status or ' //
     1                'contents is incorrect.')
          GOTO 750
      ENDIF

      IF     (RSPTE  .EQ. NPSTR) THEN
         CALL IFPF (PSTSTA .EQ. NPST  .AND.  PSTPRI .EQ. RESPRI)
      ELSEIF (RSPTE  .EQ. NPSTO) THEN
         CALL IFPF (PSTSTA .EQ. NPST  .AND.  PSTPRI .EQ. ORGPRI)
      ELSEIF (RSPTE  .EQ. NNPT)  THEN
         CALL IFPF (PSTSTA .EQ. NNPT)
      ENDIF

C generate a test condition string dealing with the state of the CSS.

 750  CONTINUE
      MSGBUF =  '<Change structure identifier and '                  //
     1          'references> with the precondition being '           //
     2          '(original structure = ' // STRST1(1:INTP1)          //
     3          ' and resulting structure = ' // STRST2(1:INTP2)     //
     4          ') should change the contents of the CSS in '        //
     5          'accordance with the substitution of the '           //
     6          'resulting identifier for the original '             //
     7          'identifier.'

      CSSSZ = ITRIM (MSGBUF)
      CALL SETMSG ('1 7 8', MSGBUF(1:CSSSZ))

      CALL IFPF (CSSEQ(EXCSS))

      END



C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.01.03/tcscir                         *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE TCSCIR (OPSTRA, STRSTA, PSTSTA, STRST, INTP)

C     Input Parameters:
C     INTEGER opstra     open structure indicator (NOEXE, NOPEN, NCLOS)
C     INTEGER strsta     structure status indicator (NOEXE, NEMP,  NORG )
C     INTEGER pststa     posted structure indicator (NOEXE, NNPT, NPSTR, NPSTO)

C     Output Parameters:
C     CHARACTER strst    string indicating a structure's state as
C                        determined by the input parameters
C     INTEGER intp       the actual length of the string

C Tcscir returns a string and its length indicating the state of a
C structure.  The structure can be: open or closed, referenced or not
C referenced, empty or with original contents, and posted or not posted.

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

C Enumeration values for subroutine parameters:
C   structure state: non-existent   opened       closed
      INTEGER        NOEXE,         NOPEN,       NCLOS
      PARAMETER     (NOEXE = -1,    NOPEN = 0,   NCLOS = 1)

C   structure posted state:
C                    not posted   posted:priority=R,   posted:priority=O
      INTEGER        NNPT,        NPSTR,               NPSTO
      PARAMETER     (NNPT = 1,    NPSTR = 4,           NPSTO = 5)

C   structure contents:
C                    empty     original
      INTEGER        NEMP,     NORG
      PARAMETER     (NEMP = 0, NORG = 1)

      INTEGER OPSTRA, PSTSTA, STRSTA, INTP, ITRIM

      CHARACTER STRST*(*)

      CHARACTER OPSTAB (NOPEN:NCLOS)*30, STRTAB (NOEXE:NORG)*30,
     1          PSTTAB (NNPT:NPSTO)*50
      DATA OPSTAB / 'OPEN', 'CLOSED' /

      DATA STRTAB / ' ', ', EMPTY,', ', ORIGINAL,' /

      DATA PSTTAB / 'and NOT-POSTED', ' ', ' ',
     1              'and POSTED with old resulting priority',
     2              'and POSTED with old original priority' /

      IF (OPSTRA .EQ. NOEXE) THEN
          IF (PSTSTA .EQ. NOEXE   .AND.
     1        STRSTA .EQ. NOEXE)    THEN
             STRST = 'NON-EXISTENT'
             GOTO 250
          ELSE
             CALL UNMSG ('Problem with the structure state being '//
     1                   'non-existent in subroutine TCSCIR.')
          ENDIF
      ENDIF

      STRST        = OPSTAB (OPSTRA)
      INTP  = ITRIM (STRST) + 1
      STRST(INTP:) = STRTAB (STRSTA)
      INTP  = ITRIM (STRST) + 2
      STRST(INTP:) = PSTTAB (PSTSTA)

 250  CONTINUE
      INTP = ITRIM (STRST)

      END

C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.01.03/elstr                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ELSTR (STRID, STRG)

C     Input Parameter:
C     INTEGER strid              structure identifier

C     Output Parameter:
C     CHARACTER strg             string identifying element types
C                                and contents for strid

C  Elstr returns the character string STRG which contains integer-like
C  substrings separated by commas. The substrings of STRG represent an
C  ordered listing of label identifiers and execute structure identifiers
C  used to indicate the structure element positions of a particular
C  structure in the network.

C  e.g. The structure 110 creates STRG = "66, 111, 66, 120, 67, 901"
C             <open structure> 110
C             <execute structure> 111
C             <execute structure> 120
C             <label> 901
C             <close structure>

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

C PHIGS enumeration parameter for PEEXST and PELB
      INTEGER    PEEXST,      PELB
      PARAMETER (PEEXST = 66, PELB = 67)

C structure status indicator   non-existent, empty,      non-empty
      INTEGER                  PSNOEX,       PSEMPT,     PSNEMP
      PARAMETER               (PSNOEX = 0,   PSEMPT = 1, PSNEMP = 2)

C array length parameter values
      INTEGER    LINT,      LRL,      LSTR
      PARAMETER (LINT = 50, LRL = 50, LSTR = 50)

      INTEGER   ELPOS, ELTYPE, INTG, INTLEN, RL, RLLEN, STLEN, STR,
     1          STRID, INTAR(LINT), STRL(LSTR), NXCHAR, IEXIST

      REAL      RLAR(LRL)

      CHARACTER STRG*(*), STRAR(LSTR)*80

C initialize values
      STRG    = ' '
      NXCHAR  = 1
      ELPOS   = 1

C check the status of the structure
      CALL PQSTST (STRID, ERRIND, IEXIST)
      CALL CHKINQ ('pqstst', ERRIND)
      IF (IEXIST .EQ. PSNOEX  .OR.
     1    IEXIST .EQ. PSEMPT)    RETURN

C create the string STRG for the network structure STRID
900   CONTINUE
      CALL PQETS (STRID, ELPOS, ERRIND, ELTYPE, INTLEN, RLLEN, STLEN)
      IF (ERRIND .NE. 0) GOTO 950
      CALL PQECO (STRID, ELPOS, LINT, LRL, LSTR, ERRIND, INTG,
     1            INTAR, RL, RLAR, STR, STRL, STRAR)
      CALL CHKINQ ('pqeco', ERRIND)

      IF (ELTYPE .EQ. PEEXST .OR.
     1    ELTYPE .EQ. PELB)      THEN
         WRITE (STRG(NXCHAR : NXCHAR + 2), '(I2, A)') ELTYPE, ','
         NXCHAR = NXCHAR + 3
      ELSE
         CALL NCMSG ('Problem with the element type ' //
     1               'in subroutine elstr.')
      ENDIF

      WRITE (STRG(NXCHAR:NXCHAR+3),'(I3, A)') INTAR(1), ','
      NXCHAR = NXCHAR + 4

      ELPOS = ELPOS + 1
      GOTO 900

 950  CONTINUE
      STRG(NXCHAR-1:) = ' '

      END


C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 02.01.03/actst                          *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE ACTST (ACSTID, STRG, EXPCON, 
     1                  OPSTRA, CONTOK, PSTSTA, PSTPRI)

C     Input Parameters :
C     INTEGER   acstid   structure identifier
C     CHARACTER strg     string identifying expected element type
C                        and content for structure acstid
C     INTEGER   expcon   expected contents: (NOEXE, NORG, NEMP)

C     Output Parameters:
C     INTEGER opstra     open structure indicator     (NOEXE, NOPEN, NCLOS)
C     LOGICAL contok     structure contents as expected
C     INTEGER pststa     posted structure indicator   (NOEXE, NPST, NNPT)
C     INTEGER pstpri     posted structure priority

C ACTST returns values indicating if a structure is non-existent
C open, closed, empty, original, and posted, not posted.

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

C open-structure status:
C                none-open   open-structure
      INTEGER    PNONST,     POPNST
      PARAMETER (PNONST = 0, POPNST = 1)

C structure status indicator:
C                non-existent,  empty,      non-empty
      INTEGER    PSNOEX,        PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0,    PSEMPT = 1, PSNEMP = 2)

C Enumeration values for subroutine parameters:
C   structure state: non-existent   opened       closed
      INTEGER        NOEXE,         NOPEN,       NCLOS
      PARAMETER     (NOEXE = -1,    NOPEN = 0,   NCLOS = 1)

C   structure posted state:
C                    structure posted     structure not posted
      INTEGER         NPST,                NNPT
      PARAMETER      (NPST = 0,            NNPT = 1)

C   structure reference status:
C                    referenced  not referenced
      INTEGER        NREF,       NNRF
      PARAMETER     (NREF = 2,   NNRF = 3)

C   structure contents:
C                    empty     original  bad-contents
      INTEGER        NEMP,     NORG,     NBCON
      PARAMETER     (NEMP = 0, NORG = 1, NBCON = -66)

      CHARACTER STRG*(*)

      INTEGER IDSTR, STYPE, OPSTRA, EXPCON, PSTSTA, POSTNM,
     1        IEXIST, IDUM2, ACSTID, STRID, PSTLT

      REAL    RDUM1, PSTPRI

      LOGICAL STRCON, CONTOK

C determine if a structure is empty, non-existent, has the original
C contents, or none of these.
      CALL PQSTST (ACSTID, ERRIND, IEXIST)
      CALL CHKINQ ('pqstst', ERRIND)

      IF (IEXIST .EQ. PSNOEX) THEN
C non-existent
         OPSTRA = NOEXE
         CONTOK = (EXPCON .EQ. NOEXE)
         PSTSTA = NOEXE
         PSTPRI = 0.0
         RETURN
      ENDIF

C set CONTOK = contents OK
      CONTOK = ((EXPCON .EQ. NEMP) .AND. (IEXIST .EQ. PSEMPT)) .OR.
     1         ((EXPCON .EQ. NORG) .AND. (STRCON (ACSTID, STRG)))

C determine if a structure is opened or closed
      CALL PQOPST (ERRIND, STYPE, IDSTR)
      CALL CHKINQ ('pqopst', ERRIND)
      IF (STYPE .EQ. POPNST  .AND.
     1    IDSTR .EQ. ACSTID)   THEN
         OPSTRA = NOPEN
      ELSE
         OPSTRA = NCLOS
      ENDIF

C determine if a structure is posted or not
      PSTSTA = NNPT
      CALL PQPOST (WKID, 0, ERRIND, POSTNM, IDUM2, RDUM1)
      CALL CHKINQ ('pqpost', ERRIND)
      DO 200 PSTLT = 1, POSTNM
         CALL PQPOST (WKID, PSTLT, ERRIND, IDUM2, STRID, PSTPRI)
         CALL CHKINQ ('pqpost', ERRIND)
         IF (STRID .EQ. ACSTID) THEN
             PSTSTA = NPST
             GOTO 210
         ENDIF
200   CONTINUE
210   CONTINUE

      END
