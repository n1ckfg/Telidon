      SUBROUTINE UNREP (FNTID, UNRPSZ, UNRPLS, PRIM, RESULT)

C  UNREP displays some unrepresentable character codes in the
C  requested font and then reports whether these were correctly
C  identified by the operator.

C  Input parameters:
C    FNTID  : Font identifier to be used in displayed text
C    UNRPSZ : Size of list of unrepresentable character codes
C    UNRPLS : List of unrepresentable character codes
C    PRIM   : indicates primitive and mode to be tested:
C             T - text/individual
C             A - annotation text/individual
C             U - text/bundled
C             B - annotation text/bundled
C  Output parameters:
C    RESULT : pass/fail result: P or F

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

C text precision
      INTEGER    PSTRP,     PCHARP,     PSTRKP
      PARAMETER (PSTRP = 0, PCHARP = 1, PSTRKP = 2)

      INTEGER    FNTID, UNRPSZ, UNRPLS(UNRPSZ), PREC, NUNREP
      INTEGER    UPTR,RPTR, ULS(10), RLS(10), ANSSIZ, ANSLIS(20)
      INTEGER    TRUANS(10), RNDINT, PERM(20), IX

      REAL       NPCX,NPCY, NPCPWC

      CHARACTER  RESULT*1, STR*10, REPCH(10)*1, PRIM*1

      LOGICAL    IAREQL

      DATA  REPCH / '*','@','&','#','^','%','$','!','?','}' /

      IF (FNTID.LT.1 .OR. FNTID.GT.2) THEN
         CALL UNMSG ('UNREP called with illegal font identifier.')
      ENDIF

      CALL PSTXI (2)
      DO 100 PREC = PSTRP, PSTRKP
         IF (PRIM.EQ.'U' .OR. PRIM.EQ.'B') THEN
            CALL PSTXR (WKID, 2, FNTID, PREC, 1.0, 0.2, 1)
         ELSEIF (PRIM.EQ.'T' .OR. PRIM.EQ.'A') THEN
            CALL PSTXFN (FNTID)
            CALL PSTXPR (PREC)
            CALL PSCHSP (0.15)
         ELSE
            CALL UNMSG ('UNREP called with PRIM = ' // PRIM)
         ENDIF

         IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
            CALL PSCHH  (0.04)
         ELSE
            CALL WCNPC  (0.0,0.0, NPCX,NPCY, NPCPWC)
            CALL PSATCH (0.04 * NPCPWC)
         ENDIF

C  number unrepresented
         NUNREP = MIN(UNRPSZ, RNDINT (2,6))
C  str = random mix of ASCII and unrepresented character codes
         CALL RNSET (10-NUNREP, 10,     RLS)
         CALL RNSET (NUNREP,    UNRPSZ, ULS)
         CALL RNPERM (10, PERM)
         UPTR = 0
         RPTR = 0
         DO 110 IX = 1,10
            IF (PERM(IX) .LE. NUNREP) THEN
               UPTR = UPTR+1
               STR(IX:IX) = CHAR(UNRPLS(ULS(UPTR)))
               TRUANS(UPTR) = IX
            ELSE
               RPTR = RPTR+1
               STR(IX:IX) = REPCH(RLS(RPTR))
            ENDIF
110      CONTINUE

         IF (PRIM.EQ.'T' .OR. PRIM.EQ.'U') THEN
            CALL PTX  (.05, .5, '1-10: ' // STR)
         ELSE
            CALL PATR (.05, .5, 0.0,0.0, '1-10: ' // STR)
         ENDIF

         CALL DILIST ('APPEARANCE OF UNREPRESENTED CHARACTER '     //
     1                'CODES: The implementation should have a '   //
     2                'special symbol to indicate the presence '   //
     3                'of a non-representable character code '     //
     4                'within a character string.  List, in '      //
     5                'order, all the character positions '        //
     6                'containing this special symbol.',
     7                ANSSIZ, ANSLIS)
         CALL PEMST (102)
         IF (IAREQL (ANSSIZ,ANSLIS, NUNREP,TRUANS)) THEN
C           OK so far
         ELSE
            IF (ANSSIZ.EQ.1 .AND. ANSLIS(1).EQ.0) CALL OPCOFL
            RESULT = 'F'
            RETURN
         ENDIF
100   CONTINUE
      RESULT = 'P'

      END
