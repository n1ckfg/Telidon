C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.02/01                              *
C  *    TEST TITLE : Setting and inquiring conflict        *
C  *                 resolution flags                      *
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
 
C conflict resolution
C                maintain    abandon     update
      INTEGER    PCRMNT,     PCRABA,     PCRUPD
      PARAMETER (PCRMNT = 0, PCRABA = 1, PCRUPD = 2)
 
      INTEGER    ARCRST, RECRST, ARCRIQ, RECRIQ
 
      CHARACTER  MSG*300
 
C  Throughout, use variable names:
C  arcrst : archival conflict resolution flag, as set
C  recrst : retrieval conflict resolution flag, as set
C  arcriq : archival conflict resolution flag, as inquired
C  recriq : retrieval conflict resolution flag, as inquired
 
      CALL INITGL ('03.02/01')
 
C  <open phigs>
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL SETMSG ('1 3', 'Immediately after <open phigs>, the '  //
     1             'archival conflict resolution flag should be ' //
     2             'reported as UPDATE and the retrieval '        //
     3             'conflict resolution flag should be reported ' //
     4             'as ABANDON.')
      CALL PQCNRS (ERRIND, ARCRIQ, RECRIQ)
      CALL IFPF (ERRIND .EQ. 0      .AND.
     1           ARCRIQ .EQ. PCRUPD .AND.
     2           RECRIQ .EQ. PCRABA)
 
      CALL SETMSG ('2 3', 'It should be possible to set and inquire ' //
     1             'the conflict resolution flags to all '            //
     2             'combinations of valid values: MAINTAIN, '         //
     3             'ABANDON, and UPDATE.')
 
      DO 100 ARCRST = PCRMNT, PCRUPD
      DO 200 RECRST = PCRMNT, PCRUPD
C  <set conflict resolution> with arcrst, recrst
         CALL PSCNRS (ARCRST, RECRST)
C  <inquire conflict resolution>
         CALL PQCNRS (ERRIND, ARCRIQ, RECRIQ)
         IF (ERRIND .EQ. 0       .AND.
     1       ARCRIQ .EQ. ARCRST  .AND.
     2       RECRIQ .EQ. RECRST)  THEN
C           OK so far
         ELSE
            WRITE (MSG, '(5(A,I4),A)') 'Set conflict flags as [',
     1             ARCRST, ',', RECRST, '], but reported as [',
     2             ARCRIQ, ',', RECRIQ, '], with error code = ',
     3             ERRIND, '.'
            CALL INMSG (MSG)
            CALL FAIL
            GOTO 500
         ENDIF
200   CONTINUE
100   CONTINUE
 
      CALL PASS
 
C  end_set_loop:
500   CONTINUE
 
C  <set conflict resolution> with MAINTAIN, MAINTAIN
      CALL PSCNRS (PCRMNT, PCRMNT)
 
C  <close phigs>
      CALL PCLPH
C  <open phigs> again
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL SETMSG ('1 3', 'Immediately after re-opening phigs, the ' //
     1             'archival conflict resolution flag should be '    //
     2             'reported as UPDATE and the retrieval conflict '  //
     3             'resolution flag should be reported as ABANDON.')
      CALL PQCNRS (ERRIND, ARCRIQ, RECRIQ)
      CALL IFPF (ERRIND .EQ. 0      .AND.
     1           ARCRIQ .EQ. PCRUPD .AND.
     2           RECRIQ .EQ. PCRABA)
 
      CALL ENDIT
      END
