C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 04.02.05.02/07                        *
C  *    TEST TITLE : Interior style index facilities       *
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

C type of returned value
      INTEGER    PSET,     PREALI
      PARAMETER (PSET = 0, PREALI = 1)

C interior style
      INTEGER    PHOLLO,   PSOLID,   PPATTR,   PHATCH,   PISEMP
      PARAMETER (PHOLLO=0, PSOLID=1, PPATTR=2, PHATCH=3, PISEMP=4)

      INTEGER    NAINTS, INTS, STYI, RSTYI, NAHS, MHI, UNDHAT
      INTEGER    MPI, NPE, PATEL, LISTEL, UNDPAT, ISE, SPECWT, SPECON
      INTEGER    IDUM1, IDUM2, IDUM3, IDUM4

      LOGICAL    FAILED, STYVAL, GOTH1

      CHARACTER  MSG*900

      CALL INITGL ('04.02.05.02/07')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
C open workstation
      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

C styval = true = all interior style indices accepted as valid
      STYVAL = .TRUE.
C goth1 = false = haven't found hatch style #1 yet

C  loop thru list of available hatch styles to determine
C    naints = number of available interior styles
C    mhi = maximum defined hatch style index
C    nahs = number of available hatch styles
      CALL PQIF (SPECWT, 0, 0, ERRIND, NAINTS, IDUM1, NAHS, IDUM2,
     1           IDUM3)
      CALL CHKINQ ('pqif', ERRIND)
      MHI = -9999
      DO 100 LISTEL = 1,NAHS
         CALL PQIF (SPECWT, 0, LISTEL, ERRIND, IDUM1, IDUM2, IDUM3,
     1              STYI, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)
         IF (MHI .LT. STYI) MHI = STYI
         IF (STYI .EQ. 1) GOTH1 = .TRUE.
100   CONTINUE
C  undhat = undefined hatch index
      UNDHAT = MHI + 1

C go thru list of available interior styles to determine what to do.
      DO 600 ISE = 1, NAINTS
         CALL PQIF (SPECWT, ISE, 0, ERRIND, IDUM1, INTS, IDUM2,
     1              IDUM3, IDUM4)
         CALL CHKINQ ('pqif', ERRIND)

C got PATTERN interior style:
         IF (INTS .EQ. PPATTR) THEN
C loop thru pattern table to determine
C   mpi = maximum defined pattern index
C   npe = number of pattern entries
            CALL PQEPAI (WKID, 0, ERRIND, NPE, IDUM1)
            CALL CHKINQ ('pqepai', ERRIND)
            MPI = 1
            DO 200 LISTEL = 1, NPE
               CALL PQEPAI (WKID, LISTEL, ERRIND, IDUM1, PATEL)
               CALL CHKINQ ('pqepai', ERRIND)
               IF (MPI .LT. PATEL) MPI = PATEL
200         CONTINUE
            UNDPAT = MPI + 1
C  <set interior representation>, index #3, PATTERN, pattern index=mpi
            CALL PSIR (WKID, 3, PPATTR, MPI, 1 )

            CALL SETMSG ('16 40', 'For PATTERN interior style, '    //
     1                   '<inquire interior representation> should '//
     2                   'report a defined interior style index '   //
     3                   'realized as itself.')
C  <inquire interior representation>, index #3 to determine
C  rstyi = realized interior style index
            CALL PQIR (WKID, 3, PREALI, ERRIND, IDUM1, RSTYI, IDUM2)
            CALL CHKINQ ('pqir', ERRIND)
            IF (RSTYI .EQ. MPI) THEN
               CALL PASS
            ELSE
               CALL FAIL
               WRITE (MSG, '(A,I5,A,I5,A)') 'Pattern index set as ',
     1                     MPI, 'but realized as ', RSTYI, '.'
               CALL INMSG (MSG)
            ENDIF

            CALL ERRCTL (.TRUE.)
            CALL SETMSG ('38', 'Any positive pattern index ' //
     1                   'should be accepted as valid.')
            CALL PSIR (WKID, 3, PPATTR, UNDPAT, 1)
            CALL ERRCTL (.FALSE.)
            CALL SIGTST (0, FAILED)
            IF (FAILED) THEN
               WRITE (MSG, '(A,I5,A)') 'Pattern index set as ',
     1                     UNDPAT,' signalled error.'
               CALL INMSG (MSG)
            ENDIF

            CALL SETMSG ('16 41', 'For PATTERN interior style, '     //
     1                   '<inquire interior representation> should ' //
     2                   'report an undefined interior style index ' //
     3                   'realized as 1.')

C  <inquire interior representation>, index #3 to determine
C  rstyi = realized interior style index
            CALL PQIR (WKID, 3, PREALI, ERRIND, IDUM1, RSTYI, IDUM2)
            CALL CHKINQ ('pqir', ERRIND)
            IF (RSTYI .EQ. 1) THEN
               CALL PASS
            ELSE
               CALL FAIL
               WRITE (MSG, '(A,A,I5,A)') 'Undefined pattern index ',
     1                'realized as ', RSTYI, '.'
               CALL INMSG (MSG)
            ENDIF
C end PATTERN
         ELSE

C handle all non-PATTERN styles
C   <set interior representation> index #4, interior style = ints,
C    interior style index = undhat
            CALL ERRCTL (.TRUE.)
            CALL PSIR (WKID, 4, INTS, UNDHAT, 1)
            CALL ERRCTL (.FALSE.)
            IF (ERRSIG .NE. 0) THEN
               STYVAL = .FALSE.
               WRITE (MSG, '(A,I5,A)') 'Interior style index set as ',
     1                     UNDHAT, ' signalled error.'
               CALL INMSG (MSG)
            ELSE
               CALL ERRCTL (.TRUE.)
               CALL PSIR (WKID, 5, INTS, -UNDHAT, 1)
               CALL ERRCTL (.FALSE.)
               IF (ERRSIG .NE. 0) THEN
                  STYVAL = .FALSE.
                  WRITE (MSG, '(A,I5,A)')
     1                        'Interior style index set as ',
     2                        -UNDHAT, ' signalled error.'
                  CALL INMSG (MSG)
               ENDIF
            ENDIF

C got HATCH interior style
            IF (INTS .EQ. PHATCH) THEN
C <inquire interior representation> realized to determine
C   rstyi = realized interior style index
               CALL PQIR (WKID, 4, PREALI, ERRIND, IDUM1, RSTYI, IDUM2)
               CALL CHKINQ ('pqir', ERRIND)
               IF (GOTH1) THEN
C  require coercion to #1
                  CALL SETMSG ('16 41', 'For HATCH interior style, '  //
     1                         '<inquire interior representation> '   //
     2                         'should report an undefined interior ' //
     3                         'style index realized as #1, when '    //
     4                         'hatch style #1 is supported on the '  //
     5                         'workstation.')
                  IF (RSTYI .EQ. 1) THEN
                     CALL PASS
                  ELSE
                     CALL FAIL
                     WRITE (MSG, '(A,A,I5,A)')'Undefined hatch index ',
     1                   'realized as ', RSTYI, '.'
                     CALL INMSG (MSG)
                  ENDIF
               ELSE
C  require coercion to something else
                  CALL SETMSG ('16 41', 'For HATCH interior style, '  //
     1                         '<inquire interior representation> '   //
     2                         'should report an undefined interior ' //
     3                         'style index realized as something '   //
     4                         'other than itself or #1, when hatch ' //
     5                         'style #1 is not supported on the '    //
     6                         'workstation.')
                  IF (RSTYI.EQ.1 .OR. RSTYI.EQ.UNDHAT) THEN
                     CALL FAIL
                     WRITE (MSG, '(A,A,I5,A)') 'Undefined hatch index ',
     1                   'realized as ', RSTYI, '.'
                     CALL INMSG (MSG)
                  ELSE
                     CALL PASS
                  ENDIF
               ENDIF

               CALL PSIR (WKID, 4, PHATCH, MHI, 1 )
               CALL SETMSG ('16 40', 'For HATCH interior style, ' //
     1                      '<inquire interior representation> '  //
     2                      'should report a defined interior '   //
     3                      'style index realized as itself.')
C  <inquire interior representation>, index #4 to determine
C  rstyi = realized interior style index
               CALL PQIR (WKID, 4, PREALI, ERRIND, IDUM1, RSTYI, IDUM2)
               CALL CHKINQ ('pqir', ERRIND)
               IF (RSTYI .EQ. MHI) THEN
                  CALL PASS
               ELSE
                  CALL FAIL
                  WRITE (MSG, '(A,I5,A,I5,A)') 'Hatch index set as ',
     1                        MHI, 'but realized as ', RSTYI, '.'
                  CALL INMSG (MSG)
               ENDIF
            ENDIF
         ENDIF
600   CONTINUE

      CALL SETMSG ('37', 'Any value for interior style index ' //
     1             '(except for pattern indices) should be '   //
     2             'accepted as valid.')
      CALL IFPF (STYVAL)

666   CONTINUE
      CALL ENDIT
      END
