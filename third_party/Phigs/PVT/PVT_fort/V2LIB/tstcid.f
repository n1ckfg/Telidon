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
