C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.02.01/04                        *
C  *    TEST TITLE : Deletion of multiple structures       *
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
 
C PHIGS parameter types
      INTEGER DELSTR
 
      LOGICAL CSSEQ
 
      CHARACTER MSG*300
 
      CALL INITGL ('02.01.02.01/04')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C creation of structures
      CALL POPST (100)
      CALL PEXST (103)
      CALL PEXST (104)
      CALL PCLST
      CALL POPST (102)
      CALL PEXST (106)
      CALL PEXST (109)
      CALL PCLST
      CALL POPST (103)
      CALL PEXST (105)
      CALL PEXST (105)
      CALL PCLST
      CALL POPST (104)
      CALL PEXST (106)
      CALL PCLST
      CALL POPST (106)
      CALL PEXST (107)
      CALL PEXST (108)
      CALL PCLST
      CALL POPST (109)
      CALL PEXST (108)
      CALL PEXST (110)
      CALL PCLST
 
      CALL SETMSG ('1 2', 'Changes to the CSS should be ' //
     1             'reflected when deleting more '        //
     2             'than one structure.')
 
      DELSTR = 103
      CALL PDST (DELSTR)
      IF (.NOT. CSSEQ ('100,1, 104,1, 106,1, 107,0/ ' //
     1                 '100,1, 104,1, 106,2, 108,0/ ' //
     2                 '102,1, 106,1, 107,0/ '        //
     3                 '102,1, 106,2, 108,0/ '        //
     4                 '102,2, 109,1, 108,0/ '        //
     5                 '102,2, 109,2, 110,0/ '        //
     6                 '105,0/ ')) THEN
         GOTO 555
      ENDIF
 
      DELSTR = 106
      CALL PDST (DELSTR)
      IF (.NOT. CSSEQ ('102,1, 109,1, 108,0/ ' //
     1                 '102,1, 109,2, 110,0/ ' //
     2                 '100,1, 104,0/ '        //
     3                 '107,0/ '               //
     4                 '105,0/ ')) THEN
         GOTO 555
      ENDIF
 
      DELSTR = 102
      CALL PDST (DELSTR)
      IF (.NOT. CSSEQ ('109,1, 108,0/ ' //
     1                 '109,2, 110,0/ ' //
     2                 '100,1, 104,0/ ' //
     3                 '107,0/ '        //
     4                 '105,0/ ')) THEN
         GOTO 555
      ENDIF
 
      DELSTR = 110
      CALL PDST (DELSTR)
      IF (.NOT. CSSEQ ('109,1, 108,0/ '//
     1                 '100,1, 104,0/ '//
     2                 '107,0/ '       //
     3                 '105,0/ ')) THEN
         GOTO 555
      ELSE
         CALL PASS
         GOTO 666
      ENDIF
 
C fail test
555   CONTINUE
      CALL FAIL
      WRITE (MSG, '(A, I3)')
     1  'Failure occurred when deleting structure ', DELSTR
      CALL INMSG (MSG)
 
 666  CONTINUE
      CALL ENDIT
      END
