C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.03/01                              *
C  *    TEST TITLE : Setting and inquiring the workstation *
C  *                 transformation                        *
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

C device coordinate units
      INTEGER    PMETRE,     POTHU
      PARAMETER (PMETRE = 0, POTHU = 1)

      INTEGER     ADMAXX,ADMAXY,ADMAXZ, DCUN
      REAL        DCMAXX,DCMAXY,DCMAXZ
      INTEGER     ADMX2X,ADMX2Y,DCUN2
      REAL        DCMX2X,DCMX2Y
      LOGICAL     DCINFO, RAREQ
      REAL        WKWIN(6), WKVWP(6), ZERO
      REAL        RQWIN(6), CUWIN(6), RQVWP(6), CUVWP(6)
      INTEGER     SPECON, SPECWT, WTUPD

      CALL INITGL ('06.03/01')
      ZERO = 0.0
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL SETMSG ('1 2', '<Inquire display space size 3> should '    //
     1             'report the maximum display volume size as '       //
     2             'positive numbers in both DC and addressable '     //
     3             'units.')

C  <inquire display space size 3> to determine
C     dcun   = device coordinate units
C     dcmax  = maximum size in DC units
C     admax  = maximum size in addressable units
      DCUN = -6
      CALL PQDSP3 (SPECWT, ERRIND, DCUN, DCMAXX,DCMAXY,DCMAXZ,
     1                                   ADMAXX,ADMAXY,ADMAXZ)
      DCINFO = ERRIND .EQ. 0   .AND.
     1         DCMAXX .GT. 0.0 .AND.
     2         DCMAXY .GT. 0.0 .AND.
     3         DCMAXZ .GT. 0.0 .AND.
     4         ADMAXX .GT. 0   .AND.
     5         ADMAXY .GT. 0   .AND.
     6         ADMAXZ .GT. 0
      CALL IFPF (DCINFO)

      CALL SETMSG ('2 4', 'The reported DC units should be either '   //
     1             'METRES or OTHER.')
      CALL IFPF (DCUN .EQ. PMETRE .OR. DCUN .EQ. POTHU)

      CALL SETMSG ('1 2 3', '<Inquire display space size> should '    //
     1             'report the same values as <inquire display '      //
     2             'space size 3> for DC units and for the first '    //
     3             'two dimensions of the display space.')

C  <inquire display space size> to determine
C     dcun2  = device coordinate units
C     dcmx2 = maximum size in DC units
C     admx2 = maximum size in addressable units
      DCUN2 = -6
      CALL PQDSP (SPECWT, ERRIND, DCUN2, DCMX2X,DCMX2Y, ADMX2X,ADMX2Y)
      CALL CHKINQ ('pqdsp', ERRIND)
      CALL IFPF (DCUN2  .EQ. DCUN   .AND.
     1           DCMX2X .EQ. DCMAXX .AND.
     2           DCMX2Y .EQ. DCMAXY .AND.
     3           ADMX2X .EQ. ADMAXX .AND.
     4           ADMX2Y .EQ. ADMAXY )

      WKWIN(1) = 0.0
      WKWIN(2) = 1.0
      WKWIN(3) = 0.2
      WKWIN(4) = 0.8
      WKWIN(5) = 0.1
      WKWIN(6) = 1.0
C  <set workstation window 3>
      CALL PSWKW3 (WKID, WKWIN)

      CALL SETMSG ('1 6 8 12 14', 'Requested workstation window '     //
     1             'should be reported by <inquire workstation '      //
     2             'transformation 3> as most recently set by <set '  //
     3             'workstation window 3>.')

C  <inquire workstation transformation 3> to determine requested 3D window:
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL IFPF (RAREQ(6, RQWIN, WKWIN, ZERO, ZERO))

      CALL SETMSG ('1 6 8 13 14', 'Requested workstation window '     //
     1             'should be reported by <inquire workstation '      //
     2             'transformation> as most recently set by <set '    //
     3             'workstation window 3>.')

C  <inquire workstation transformation> to determine requested 2D window:
      CALL PQWKT  (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt', ERRIND)
      CALL IFPF   (RAREQ(4, RQWIN, WKWIN, ZERO, ZERO))

      IF (.NOT. DCINFO) THEN
         CALL INMSG ('Skipping viewport 3 tests because DC ' //
     1               'information is unavailable.')
         GOTO 110
      ENDIF

      WKVWP(1) = 0.0*DCMAXX
      WKVWP(2) = 0.4*DCMAXX
      WKVWP(3) = 0.8*DCMAXY
      WKVWP(4) = 1.0*DCMAXY
      WKVWP(5) = 0.0*DCMAXZ
      WKVWP(6) = 0.1*DCMAXZ

C  <set workstation viewport 3>
      CALL PSWKV3 (WKID, WKVWP)

      CALL SETMSG ('1 9 11 12 14', 'Requested workstation viewport '  //
     1             'should be reported by <inquire workstation '      //
     2             'transformation 3> as most recently set by <set '  //
     3             'workstation viewport 3>.')

C  <inquire workstation transformation 3> to determine requested
C     3D viewport:
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL IFPF (RAREQ(6, RQVWP, WKVWP, ZERO, ZERO))

      CALL SETMSG ('1 9 11 13 14', 'Requested workstation viewport '  //
     1             'should be reported by <inquire workstation '      //
     2             'transformation> as most recently set by <set '    //
     3             'workstation viewport 3>.')

C  <inquire workstation transformation> to determine requested
C     2D viewport:
      CALL PQWKT  (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt', ERRIND)
      CALL IFPF   (RAREQ(4, RQVWP, WKVWP, ZERO, ZERO))

C  end_viewport_3:
110   CONTINUE

      WKWIN(1) = 0.0
      WKWIN(2) = 0.4
      WKWIN(3) = 0.6
      WKWIN(4) = 1.0
C  <set workstation window>
      CALL PSWKW (WKID, WKWIN(1), WKWIN(2), WKWIN(3), WKWIN(4))

      CALL SETMSG ('1 7 8 12 14', 'Requested workstation window '     //
     1             'should be reported by <inquire workstation '      //
     2             'transformation 3> as most recently set by <set '  //
     3             'workstation window>, with z-values unchanged.')

C  <inquire workstation transformation 3> to determine requested 3D window:
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL IFPF   (RAREQ(6, RQWIN, WKWIN, ZERO, ZERO))

      IF (.NOT. DCINFO) THEN
         CALL INMSG ('Skipping viewport tests because DC ' //
     1               'information is unavailable.')
         GOTO 120
      ENDIF

      WKVWP(1) = 0.8*DCMAXX
      WKVWP(2) = 0.9*DCMAXX
      WKVWP(3) = 0.1*DCMAXY
      WKVWP(4) = 0.2*DCMAXY

C  <set workstation viewport>
      CALL PSWKV (WKID, WKVWP(1), WKVWP(2), WKVWP(3), WKVWP(4))

      CALL SETMSG ('1 10 11 12 14', 'Requested workstation viewport ' //
     1             'should be reported by <inquire workstation '      //
     2             'transformation 3> as most recently set by <set '  //
     3             'workstation viewport>, with z-values unchanged.')

C  <inquire workstation transformation 3> to determine requested
C     3D viewport:
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL IFPF (RAREQ(6, RQVWP, WKVWP, ZERO, ZERO))

C  end_viewport:
120   CONTINUE

      IF (.NOT. DCINFO) THEN
         CALL INMSG ('Skipping flat viewport tests because DC ' //
     1               'information is unavailable.')
         GOTO 130
      ENDIF

C  Set up viewport with zero thickness in z-dimension
      WKVWP(1) = 0.0*DCMAXX
      WKVWP(2) = 0.4*DCMAXX
      WKVWP(3) = 0.8*DCMAXY
      WKVWP(4) = 1.0*DCMAXY
      WKVWP(5) = 0.3*DCMAXZ
      WKVWP(6) = WKVWP(5)
C  <set workstation viewport 3>
      CALL PSWKV3 (WKID, WKVWP)

      CALL SETMSG ('1 9 11 12 14', 'Requested flat workstation '      //
     1             'viewport should be reported by <inquire '         //
     2             'workstation transformation 3> as most recently '  //
     3             'set by <set workstation viewport 3>, with '       //
     4             'unchanged window.')

C  <inquire workstation transformation 3> to determine requested
C     3D window and viewport:
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL IFPF (RAREQ(6, RQWIN, WKWIN, ZERO, ZERO) .AND.
     1           RAREQ(6, RQVWP, WKVWP, ZERO, ZERO))

C  end_flat_viewport:
130   CONTINUE

C  Set up window with zero thickness in z-dimension
      WKWIN(1) = 0.1
      WKWIN(2) = 1.0
      WKWIN(3) = 0.0
      WKWIN(4) = 0.9
      WKWIN(5) = 0.0
      WKWIN(6) = WKWIN(5)
C  <set workstation window 3>
      CALL PSWKW3 (WKID, WKWIN)

      CALL SETMSG ('1 6 8 12 14', 'Requested flat workstation '       //
     1             'window should be reported by <inquire '           //
     2             'workstation transformation 3> as most recently '  //
     3             'set by <set workstation window 3>, with '         //
     4             'unchanged viewport.')

C  <inquire workstation transformation 3> to determine requested
C     3D window and viewport:
      CALL PQWKT3 (WKID, ERRIND, WTUPD, RQWIN, CUWIN, RQVWP, CUVWP)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL IFPF (RAREQ(6, RQWIN, WKWIN, ZERO, ZERO) .AND.
     1           RAREQ(6, RQVWP, WKVWP, ZERO, ZERO))

666   CONTINUE
      CALL ENDIT
      END
