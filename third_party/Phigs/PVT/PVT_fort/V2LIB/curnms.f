      SUBROUTINE CURNMS (MXNOFL, MXN, STPATH, EXPATH, EXNMST)

C  CURNMS performs an incremental spatial search, with filters set
C  so as to accept only the expected nameset.  It issues "pass"
C  if the search halts at the expected location, and does not
C  find any primitive thereafter;  otherwise it issues "fail".
C  Always: search reference point is 1,1,1, search distance is 0.1,
C  search ceiling is 1, and modelling clip is off.

C  Input parameters:
C    MXNOFL : Maximum number of entries in normal filter list
C    MXN    : Maximum number of names - gives size of universe
C    STPATH : starting path
C    EXPATH : expected found path
C    EXNMST : expected current name set

C clipping indicator
C                noclip      clip
      INTEGER    PNCLIP,     PCLIP
      PARAMETER (PNCLIP = 0, PCLIP = 1)

      INTEGER    IPTHSZ,       MXI
      PARAMETER (IPTHSZ = 100, MXI = 100)
      INTEGER    FPATH(2,IPTHSZ), ERRIND, FPTHSZ

      INTEGER    NORACT, MXNOFL, MXN, IX, IVAL, ILAST
      INTEGER    ISTPTH(10), ISTSIZ, IEXPTH(10), IEXSIZ, PERM(10)
      INTEGER    NORSIZ, NORINX(10), NORINC(10),  NOREXX(10), NOREXC(1),
     1           INVSIZ, INVINX(1),  INVINC(MXI), INVEXX(1),  INVEXC(1)

      CHARACTER  STPATH*(*), EXPATH*(*), EXNMST*(*), MSG*300

      LOGICAL    IAREQL

C  Exclusion sets are always empty
      DATA   NOREXX / 10*0 /, INVEXX / 0 /
C  Normal inclusion sets are all singletons
      DATA   NORINX / 1,2,3,4,5,6,7,8,9,10 /
C  Only one inverted inclusion and exclusion set
      DATA   INVSIZ / 1 /

      IF (MXN .GT. MXI) THEN
         CALL UNMSG ('Nameset universe too large for CURNMS.')
      ENDIF

C  encode starting path
      CALL SETVS (STPATH, ISTPTH, ISTSIZ)
C  encode expected found path
      CALL SETVS (EXPATH, IEXPTH, IEXSIZ)

C  normal filter has one inclusion set per name - this ensures that
C  nameset has at least all the expected names.
      CALL SETVS (EXNMST, NORINC, NORSIZ)

      IF (NORSIZ .LE. 1) GOTO 70
C  mix up NORINC
      CALL RNPERM (NORSIZ, PERM)
      IVAL = NORINC(PERM(1))
      DO 80 IX = 1,NORSIZ-1
         NORINC(PERM(IX)) = NORINC(PERM(IX+1))
80    CONTINUE
      NORINC(PERM(NORSIZ)) = IVAL
70    CONTINUE

C  inverted filter has all names in its one inclusion set *except*
C  those expected - this ensures that no extra names are in name
C  set.
      INVINX(1) = MXN - NORSIZ
C  put universe in INVINC
      DO 100 IVAL = 1,MXN
         INVINC(IVAL) = IVAL-1
100   CONTINUE

C  take out those in expected name set.

C  This loop works only if maximum nameset value < MXN - NORINC ...
C  i.e. assumes that there are enough inverted values at the end of
C  INVINC to overwrite normal values.

      ILAST = MXN
      DO 200 IVAL = 1,NORSIZ
         INVINC (NORINC(IVAL) + 1) = INVINC (ILAST)
         ILAST = ILAST-1
200   CONTINUE

C  if filter list is too long cut back to max
      NORACT = MIN(NORSIZ, MXNOFL)

      CALL PISS3 (1.0,1.0,1.0, 0.1, ISTSIZ/2, ISTPTH, PNCLIP, 1,
     1            NORACT, NORINX, NORINC, NOREXX, NOREXC,
     2            INVSIZ, INVINX, INVINC, INVEXX, INVEXC,
     3            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND.
     1    IAREQL (2*FPTHSZ, FPATH, IEXSIZ, IEXPTH)) THEN
C        OK so far
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'ISS did not return correct ' //
     1      'found path; error indicator = ', ERRIND, '.'
         CALL INMSG (MSG)
         RETURN
      ENDIF

C The 2nd call to ISS is valid only if the maximum length of the normal
C filter list is >= size of nameset being tested.  Otherwise, if filter
C list has been truncated, a primitive with a "too-small" nameset might
C be found and cause the test to fail.

      IF (NORACT .LT. NORSIZ) THEN
         CALL PASS
         CALL INMSG ('Inverse test skipped because of limitation ' //
     1               'on size of normal filter list.')
         RETURN
      ENDIF

      CALL PISS3 (1.0,1.0,1.0, 0.1, IEXSIZ/2, IEXPTH, PNCLIP, 1,
     1            NORACT, NORINX, NORINC, NOREXX, NOREXC,
     2            INVSIZ, INVINX, INVINC, INVEXX, INVEXC,
     3            IPTHSZ, ERRIND, FPTHSZ, FPATH)

      IF (ERRIND .EQ. 0 .AND. FPTHSZ .EQ. 0) THEN
         CALL PASS
      ELSE
         CALL FAIL
         WRITE (MSG, '(A,I5,A)') 'ISS did not return null ' //
     1      'path as expected; error indicator = ', ERRIND, '.'
         CALL INMSG (MSG)
      ENDIF

      END
