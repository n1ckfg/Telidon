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
