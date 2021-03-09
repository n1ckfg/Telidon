C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.03.02/02                        *
C  *    TEST TITLE : <Change structure references> where   *
C  *                 changes occur to the CSS              *
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
 
      INTEGER ORGID, RESID
 
      LOGICAL CSSEQ
 
C  Declare program-specific variables
 
      CALL INITGL ('02.01.03.02/02')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
      CALL SETMSG ('1', '<Change structure references> when the '     //
     1             'original structure is referenced and the '        //
     2             'resulting structure is not referenced should '    //
     3             'replace all execute structure elements which '    //
     4             'reference original structure identifier with '    //
     5             'elements which reference resulting structure '    //
     6             'identifier.')
 
      CALL STDCSS
      ORGID = 108
      RESID = 140
      CALL PCSTRF (ORGID, RESID)
      CALL IFPF (CSSEQ ('100,1, 101,2, 103,0/'        //
     1           '100,2, 102,1, 104,2, 109,0/'        //
     2           '100,2, 102,1, 104,5, 109,0/'        //
     3           '100,2, 102,2, 105,1, 110,0/'        //
     4           '100,2, 102,2, 105,3, 114,0/'        //
     5           '100,2, 102,2, 105,2, 140,1, 142,0/' //
     6           '100,2, 102,5, 106,1, 140,1, 142,0/' //
     7           '108,2, 111,1, 114,0/'               //
     8           '108,2, 111,3, 115,0/'               //
     9           '120,2, 106,1, 140,1, 142,0/'        //
     O           '130,3, 106,1, 140,1, 142,0/'        //
     1           '130,5, 107,1, 140,1, 142,0/'        //
     2           '130,5, 107,4, 140,1, 142,0/'        //
     3           '130,5, 107,5, 113,0/'))
 
      CALL SETMSG ('1 4', 'When the original structure and '          //
     1             'resulting structure are referenced then <change ' //
     2             'structure references> should cause the initial '  //
     3             'references made to resulting structure to '       //
     4             'remain as is.')
 
      CALL STDCSS
      ORGID = 108
      RESID = 104
      CALL PCSTRF (ORGID, RESID)
      CALL IFPF (CSSEQ ('100,1, 101,2, 103,0/'                       //
     1          '108,2, 111,1, 114,0/'                               //
     2          '108,2, 111,3, 115,0/'                               //
     3          '100,2, 102,2, 105,1, 110,0/'                        //
     4          '100,2, 102,2, 105,3, 114,0/'                        //
     5          '100,2, 102,2, 105,2, 104,2, 109,0/'                 //
     6          '100,2, 102,2, 105,2, 104,5, 109,0/'                 //
     7          '100,2, 102,1, 104,2, 109,0/'                        //
     8          '100,2, 102,1, 104,5, 109,0/'                        //
     9          '100,2, 102,5, 106,1, 104,2, 109,0/'                 //
     O          '100,2, 102,5, 106,1, 104,5, 109,0/'                 //
     1          '120,2, 106,1, 104,2, 109,0/'                        //
     2          '120,2, 106,1, 104,5, 109,0/'                        //
     3          '130,3, 106,1, 104,2, 109,0/'                        //
     4          '130,3, 106,1, 104,5, 109,0/'                        //
     5          '130,5, 107,1, 104,2, 109,0/'                        //
     6          '130,5, 107,1, 104,5, 109,0/'                        //
     7          '130,5, 107,4, 104,2, 109,0/'                        //
     8          '130,5, 107,4, 104,5, 109,0/'                        //
     9          '130,5, 107,5, 113,0/ 140,1, 142,0/'))
 
666   CONTINUE
      CALL ENDIT
      END
