C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.03.02/01                        *
C  *    TEST TITLE : <Change structure references> where   *
C  *                 no changes occur to the CSS           *
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
 
      CHARACTER*700 CSSEXP
      PARAMETER (CSSEXP = '100,1, 101,2, 103,0/'                      //
     1                    '100,2, 102,1, 104,2, 109,0/'               //
     2                    '100,2, 102,1, 104,5, 109,0/'               //
     3                    '100,2, 102,2, 105,1, 110,0/'               //
     4                    '100,2, 102,2, 105,2, 108,2, 111,1, 114,0/' //
     5                    '100,2, 102,2, 105,2, 108,2, 111,3, 115,0/' //
     6                    '100,2, 102,2, 105,3, 114,0/'               //
     7                    '100,2, 102,5, 106,1, 108,2, 111,1, 114,0/' //
     8                    '100,2, 102,5, 106,1, 108,2, 111,3, 115,0/' //
     9                    '120,2, 106,1, 108,2, 111,1, 114,0/'        //
     O                    '120,2, 106,1, 108,2, 111,3, 115,0/'        //
     1                    '130,3, 106,1, 108,2, 111,1, 114,0/'        //
     2                    '130,3, 106,1, 108,2, 111,3, 115,0/'        //
     3                    '130,5, 107,1, 108,2, 111,1, 114,0/'        //
     4                    '130,5, 107,1, 108,2, 111,3, 115,0/'        //
     5                    '130,5, 107,4, 108,2, 111,1, 114,0/'        //
     6                    '130,5, 107,4, 108,2, 111,3, 115,0/'        //
     7                    '130,5, 107,5, 113,0/'                      //
     8                    '140,1, 142,0/')
 
      INTEGER ORGID, RESID
 
      LOGICAL CSSEQ
 
C  Declare program-specific variables
 
      CALL INITGL ('02.01.03.02/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('2', '<Change structure references> when the '     //
     1             'original structure is non-existent and the '      //
     2             'resulting structure exists and is not '           //
     3             'referenced should have no effect on the '         //
     4             'contents of the CSS.')
 
      CALL STDCSS
      ORGID = 300
      RESID = 120
      CALL PCSTRF (ORGID, RESID)
 
      CALL IFPF (CSSEQ (CSSEXP))
 
      CALL SETMSG ('2', '<Change structure references> when the '     //
     1             'original structure exists and is not referenced ' //
     2             'and the resulting structure exists and is '       //
     3             'referenced should have no effect on the '         //
     4             'contents of the CSS.')
 
      CALL STDCSS
      ORGID = 130
      RESID = 103
      CALL PCSTRF (ORGID, RESID)
 
      CALL IFPF (CSSEQ (CSSEXP))
 
      CALL SETMSG ('2', '<Change structure references> when the '     //
     1             'original structure and resulting structure are '  //
     2             'non-existent should have no effect on the '       //
     3             'contents of the CSS.')
 
      CALL STDCSS
      ORGID = 300
      RESID = 320
      CALL PCSTRF (ORGID, RESID)
 
      CALL IFPF (CSSEQ (CSSEXP))
 
      CALL SETMSG ('3', '<Change structure references> when the '     //
     1             'original structure identifier and resulting '     //
     2             'identifier are the same and the common '          //
     3             'structure exists and is referenced should have '  //
     4             'no effect on the contents of the CSS.')
 
      CALL STDCSS
      ORGID = 107
      RESID = 107
      CALL PCSTRF (ORGID, RESID)
 
      CALL IFPF (CSSEQ (CSSEXP))
 
666   CONTINUE
      CALL ENDIT
 
      END
