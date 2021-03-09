C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 05.02/02                              *
C  *    TEST TITLE : Display surface flag                  *
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
     3        DUMINT(20)
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

C clear control flag
      INTEGER    PCONDI,   PALWAY
      PARAMETER (PCONDI=0, PALWAY=1)
C deferral mode
      INTEGER    PASAP,   PBNIG,   PBNIL,   PASTI,   PWAITD
      PARAMETER (PASAP=0, PBNIG=1, PBNIL=2, PASTI=3, PWAITD=4)
C display surface empty
      INTEGER    PNEMPT,   PEMPTY
      PARAMETER (PNEMPT=0, PEMPTY=1)
C dynamic modification
      INTEGER    PIRG,   PIMM,   PCBS
      PARAMETER (PIRG=0, PIMM=1, PCBS=2)
C modification mode
      INTEGER    PNIVE,   PUWOR,   PUQUM
      PARAMETER (PNIVE=0, PUWOR=1, PUQUM=2)
C regeneration flag
      INTEGER    PPOSTP,   PPERFO
      PARAMETER (PPOSTP=0, PPERFO=1)
C state of visual representation
      INTEGER    PVROK,   PVRDFR,   PVRSIM
      PARAMETER (PVROK=0, PVRDFR=1, PVRSIM=2)


C  Declare program-specific variables

      LOGICAL SURFOK


C parameters used in posting a structure
      REAL  PLX(5), PLY(5), PFX(7), PFY(7), PMX(3), PMY(3)
      DATA  PLX /0.1, 0.9, 0.9, 0.1, 0.1/
      DATA  PLY /0.1, 0.1, 0.9, 0.9, 0.1/
      DATA  PFX /1.1, 1.2, 1.2, 0.8, 0.8, 1.1, 1.1/
      DATA  PFY /0.6, 0.6, 1.4, 1.4, 1.2, 1.2, 0.6/
      DATA  PMX /0.5, 0.6, 0.7/
      DATA  PMY /0.5, 0.4, 0.3/

      CALL INITGL ('05.02/02')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  DESIGN:
C create structure 101 with
C  polymarker in default workstation window
      CALL POPST(101)
      CALL PPM (3, PMX, PMY)
      CALL PCLST
C create structure 102 with
C  polyline in default workstation window
      CALL POPST(102)
      CALL PPL (5, PLX, PLY)
      CALL PCLST
C create structure 103 with
C  fill area outside default workstation window
      CALL POPST(103)
      CALL PFA (7, PFX, PFY)
      CALL PCLST

C open workstation
      CALL POPWK (WKID, CONID, WTYPE)

C  <set display update state> ASAP, NIVE
      CALL PSDUS (WKID, PASAP, PNIVE)
      CALL SETMSG ('4 9 10 12', 'After <open workstation>, until '    //
     1             'something is drawn inside the workstation '       //
     2             'window, the display surface should be reported '  //
     3             'as EMPTY.')
      CALL IFPF (SURFOK (WKID, PEMPTY))

C  <post structure> 101
      CALL PPOST (WKID, 101, 0.5)
      CALL SETMSG ('4 10 11', 'After a visible primitive is first '   //
     1             'posted to a workstation with deferral mode '      //
     2             'ASAP, the display surface should be reported as ' //
     3             'NOTEMPTY.')
      CALL IFPF (SURFOK (WKID, PNEMPT))

C  <post structure> 102
      CALL PPOST (WKID, 102, 0.5)
      CALL SETMSG ('4 10 11', 'After posting of additional visible '  //
     1             'primitives to a workstation with deferral mode '  //
     2             'ASAP, the display surface should be continue to ' //
     3             'be reported as NOTEMPTY.')
      CALL IFPF (SURFOK (WKID, PNEMPT))

C  <unpost all structures> from workstation
      CALL PUPAST (WKID)
      CALL SETMSG ('4 10 12', 'After all structures have been '       //
     1             'unposted from a workstation with deferral mode '  //
     2             'ASAP, the display surface should be reported as ' //
     3             'EMPTY.')
      CALL IFPF (SURFOK (WKID, PEMPTY))

C  <post structure> 103 (off-screen)
      CALL PPOST (WKID, 103, 0.5)
      CALL SETMSG ('4 10 12', 'If a structure is posted to a '        //
     1             'workstation with deferral mode ASAP, but none '   //
     2             'of its primitives lie within the workstation '    //
     3             'window, the display surface should still be '     //
     4             'reported as NOTEMPTY.')
      CALL IFPF (SURFOK (WKID, PNEMPT))

C  <set display update state> WAIT, NIVE
      CALL PSDUS (WKID, PWAITD, PNIVE)
C  <unpost all structures> from workstation
      CALL PUPAST (WKID)
C  <post structure> 101
      CALL PPOST (WKID, 101, 0.5)
C  <redraw all structures>
      CALL PRST (WKID, PALWAY)

      CALL SETMSG ('4 10 11', 'After a visible primitive is first '   //
     1             'posted and the workstation is then explicitly '   //
     2             'updated, the display surface should be reported ' //
     3             'as NOTEMPTY.')
      CALL IFPF (SURFOK (WKID, PNEMPT))

C  <unpost all structures> from workstation
      CALL PUPAST (WKID)
C  <update workstation> with PERFORM
      CALL PUWK (WKID, PPERFO)
      CALL SETMSG ('4 10 12', 'After all structures have been '       //
     1             'unposted and the workstation is then explicitly ' //
     2             'updated, the display surface should be reported ' //
     3             'as EMPTY.')
      CALL IFPF (SURFOK (WKID, PEMPTY))

      CALL ENDIT
      END
