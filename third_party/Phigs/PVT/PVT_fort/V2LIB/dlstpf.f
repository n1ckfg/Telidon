      SUBROUTINE DLSTPF (PROMPT, EXPSIZ, EXPLST, SLSW)

C  DLSTPF gets an integer list response from the operator, and
C  issues pass/fail as a result of comparing the operator response
C  to the expected list. A list with one element = 0 indicates "fail
C  - cannot answer" and triggers an operator comment.

C  Input parameters:
C    PROMPT : prompt to be sent to operator.
C    EXPSIZ : expected size of list
C    EXPLST : expected contents of list
C    SLSW   : S/L switch to indicate comparison by set-equality
C             (unordered) of list-equality (ordered)

      INTEGER     EXPSIZ, EXPLST(*), ANSSIZ, ANSLST(100)

      CHARACTER   PROMPT*(*), SLSW*1

      LOGICAL     IAREQL, SETEQ

      CALL DILIST (PROMPT, ANSSIZ, ANSLST)
      IF (ANSSIZ.EQ.1 .AND. ANSLST(1).EQ.0) THEN
         CALL OPFAIL
      ELSE
         IF (SLSW .EQ. 'L') THEN
            CALL IFPF (IAREQL(ANSSIZ,ANSLST, EXPSIZ,EXPLST))
         ELSEIF (SLSW .EQ. 'S') THEN
            CALL IFPF (ANSSIZ.EQ.EXPSIZ .AND.
     1                 SETEQ(ANSSIZ, ANSLST, EXPLST))
         ELSE
            CALL UNMSG ('DLSTPF called with SLSW = ' // SLSW // '.')
         ENDIF
      ENDIF

      END
