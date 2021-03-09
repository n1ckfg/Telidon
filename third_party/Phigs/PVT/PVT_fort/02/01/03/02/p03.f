C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 02.01.03.02/03                        *
C  *    TEST TITLE : The effects of <change structure      *
C  *                 references> on posted structures      *
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
 
      INTEGER NUMB, STRID, ORGID, RESID
 
      REAL ORGPRI, RESPRI, PRIORT
 
C  Declare program-specific variables
 
      CALL INITGL ('02.01.03.02/03')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
 
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
 
      CALL SETMSG ('5', 'When the original and resulting structures ' //
     1             'are posted then <change structure references> '   //
     2             'should cause the original structure to become '   //
     3             'unposted and the resulting structure to remain '  //
     4             'posted with unchanged priority.')
 
      CALL STDCSS
      ORGID  =  108
      ORGPRI =  .42
      RESID  =  104
      RESPRI =  .37
      CALL PPOST (WKID, ORGID, ORGPRI)
      CALL PPOST (WKID, RESID, RESPRI)
      CALL PCSTRF (ORGID, RESID)
 
C  Use <inquire posted structures> to determine
C  numb   = number of posted structures
C  strid  = posted structure identifier
C  priort = posted structure priority
 
      CALL PQPOST (WKID, 0, ERRIND, NUMB, STRID, PRIORT)
      CALL CHKINQ ('pqpost', ERRIND)
 
      IF (NUMB .EQ. 1) THEN
         CALL PQPOST (WKID, 1, ERRIND, NUMB, STRID, PRIORT)
         CALL CHKINQ ('pqpost', ERRIND)
         CALL IFPF (STRID  .EQ. RESID    .AND.
     1              PRIORT .EQ. RESPRI)
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('5', 'When the original structure is not posted '  //
     1             'and the resulting structure is posted then '      //
     2             '<change structure references> should cause the '  //
     3             'original structure to remain unposted and the '   //
     4             'resulting structure to remain posted with '       //
     5             'unchanged priority.')
 
      CALL STDCSS
      ORGID  =  108
      ORGPRI =  .42
      RESID  =  104
      RESPRI =  .37
      CALL PPOST (WKID, RESID, RESPRI)
      CALL PCSTRF (ORGID, RESID)
 
C  Use <inquire posted structures> to determine
C  numb   = number of posted structures
C  strid  = posted structure identifier
C  priort = posted structure priority
 
      CALL PQPOST (WKID, 0, ERRIND, NUMB, STRID, PRIORT)
      CALL CHKINQ ('pqpost', ERRIND)
 
      IF (NUMB .EQ. 1) THEN
         CALL PQPOST (WKID, 1, ERRIND, NUMB, STRID, PRIORT)
         CALL CHKINQ ('pqpost', ERRIND)
         CALL IFPF (STRID  .EQ. RESID    .AND.
     1              PRIORT .EQ. RESPRI)
      ELSE
         CALL FAIL
      ENDIF
 
      CALL SETMSG ('6', 'When the original structure is posted and '  //
     1             'the resulting structure is not posted then '      //
     2             '<change structure references> should cause the '  //
     3             'original structure to become unposted and the '   //
     4             'resulting structure to become posted with the '   //
     5             'priority of the original structure.')
 
      CALL STDCSS
      ORGID  =  108
      ORGPRI =  .42
      RESID  =  104
      RESPRI =  .37
      CALL PPOST (WKID, ORGID, ORGPRI)
      CALL PCSTRF (ORGID, RESID)
 
C  Use <inquire posted structures> to determine
C  numb   = number of posted structures
C  strid  = posted structure identifier
C  priort = posted structure priority
 
      CALL PQPOST (WKID, 0, ERRIND, NUMB, STRID, PRIORT)
      CALL CHKINQ ('pqpost', ERRIND)
 
      IF (NUMB .EQ. 1) THEN
         CALL PQPOST (WKID, 1, ERRIND, NUMB, STRID, PRIORT)
         CALL CHKINQ ('pqpost', ERRIND)
         CALL IFPF (STRID  .EQ. RESID    .AND.
     1              PRIORT .EQ. ORGPRI)
      ELSE
         CALL FAIL
      ENDIF
 
666   CONTINUE
      CALL ENDIT
      END
