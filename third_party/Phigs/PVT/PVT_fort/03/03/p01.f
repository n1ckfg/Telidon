C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 03.03/01                              *
C  *    TEST TITLE : Preservation of structure contents    *
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

C element type
      INTEGER    PEPM3,       PEPM,        PETX3,       PETX
      PARAMETER (PEPM3  =  4, PEPM   =  5, PETX3  =  6, PETX   =  7)
      INTEGER    PEGDP3,      PEGDP,       PEPLI,       PEPMI
      PARAMETER (PEGDP3 = 16, PEGDP  = 17, PEPLI  = 18, PEPMI  = 19)
      INTEGER    PEPARF,      PEADS,       PERES,       PEIASF
      PARAMETER (PEPARF = 52, PEADS  = 53, PERES  = 54, PEIASF = 55)

      REAL      XVALS(4), YVALS(4), XPOS,YPOS, RCONT(20), RELTOL,ABSTOL

      LOGICAL   CONOK, RAREQ, SETEQ, APPEQ

C  set up parameters for name-set:
      INTEGER   NMVALS(7), NUMRLS, GDPID, ARID,ARNM
      INTEGER   STRUID(1), ELEMNO, ELTAB(4), ELTYPE
      INTEGER   IX, ITRIM, DRLENS(2), LDRACT, SLEN(20)
C  expected sizes
      INTEGER   EXISZ(4), EXRSZ(4), EXSSZ(4)
C  actual sizes
      INTEGER   ACISZ,    ACRSZ,    ACSSZ, ICONT(20)
                         
      CHARACTER DATREC(30)*80, MSG*300, SCONT(20)*80, SVALS(2)*80

      DATA  XVALS  / 2.2,      3.3E22,  4.4E-33, -5.5/
      DATA  YVALS  /-1.2E-22, -2.3E33, -3.4,      0.0/
      DATA  NMVALS / 2,3,5,8,13,63,0 /
      DATA  ELTAB  / PEPM, PETX, PEADS, PEGDP/
C expected element sizes:
      DATA  EXISZ  /1, 0, 7, 2/
      DATA  EXRSZ  /8, 2, 0, 6/
      DATA  EXSSZ  /0, 1, 0, 2/

      CALL INITGL ('03.03/01')

C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)

C  tolerance for floating-point equality
      RELTOL = 1E-5
      ABSTOL = 0.0

C  set up parameters for text:
      XPOS = 9.8
      YPOS = 7.6

C  set up additional parameters for GDP:
      NUMRLS = 3
      GDPID  = 33
           
      SVALS(1) = '  string#1'
      SVALS(2) = 'and #2'

      DRLENS(1) = ITRIM(SVALS(1))
      DRLENS(2) = ITRIM(SVALS(2))

      CALL PPREC (3, NMVALS, 2, YVALS, 2, DRLENS, SVALS, 30,
     1            ERRIND, LDRACT, DATREC)
      CALL CHKINQ ('pprec', ERRIND)
      EXSSZ(4) = LDRACT

      STRUID(1) = 101

C set up structure
      CALL POPST (STRUID(1))
      CALL PPM   (4, XVALS,YVALS)
      CALL PTX   (XPOS,YPOS, 'Text string.')
      CALL PADS  (7, NMVALS)
      CALL PGDP  (NUMRLS, XVALS,YVALS, GDPID, LDRACT, DATREC)
      CALL PCLST

      ARID = 10
      CALL AVARNM (ARNM)

C archive and retrieve it
      CALL POPARF (ARID, ARNM)
      CALL PDASAR (ARID)
      CALL PARST  (ARID, 1, STRUID)
      CALL PDST   (STRUID(1))
      CALL PREST  (ARID, 1, STRUID)
      CALL PCLARF (ARID)

      CALL SETMSG ('1 4 9 12', 'When a structure is archived and '  //
     1             'retrieved, all the structure elements and all ' //
     2             'the parameter values therein should be '        //
     3             'accurately restored.')

      CONOK = .TRUE.
      DO 100 ELEMNO = 1,4
         MSG = 'OK'
C        <inquire element type and size> with struid,elemno
C           to determine eltype, elsize
         CALL PQETS (STRUID(1), ELEMNO,
     1               ERRIND, ELTYPE, ACISZ,ACRSZ,ACSSZ)
         IF (ERRIND .EQ. 201 .OR. ERRIND .EQ. 202) THEN
            CONOK = .FALSE.
            WRITE (MSG, '(A,I2,A)') 'Element number ', ELEMNO,
     1                              ' reported as non-existent.'
            CALL INMSG (MSG)
            GOTO 300
         ENDIF
         CALL CHKINQ ('pqets', ERRIND)

         IF (ELTYPE .NE. ELTAB(ELEMNO)) THEN
            WRITE (MSG, '(A,I3,A,I2,A)')
     1            'element type ', ELTYPE, ' in position #', ELEMNO, '.'
            GOTO 150
         ENDIF
                                            
         IF (ACISZ .EQ. EXISZ (ELEMNO) .AND.
     1       ACRSZ .EQ. EXRSZ (ELEMNO) .AND.
     2       ACSSZ .EQ. EXSSZ (ELEMNO) ) THEN
C           OK so far
         ELSE
            WRITE (MSG, '(A,I2,A)')
     1            'element size from PQETS in position #', ELEMNO, '.'
            GOTO 150
         ENDIF

         SCONT(1) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'
         SCONT(2) = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'
         CALL PQECO (STRUID(1), ELEMNO, 20,20,20, ERRIND,
     1               ACISZ,       ICONT,
     2               ACRSZ,       RCONT,
     3               ACSSZ, SLEN, SCONT)
         CALL CHKINQ ('pqeco', ERRIND)

         IF (ACISZ .EQ. EXISZ (ELEMNO) .AND.
     1       ACRSZ .EQ. EXRSZ (ELEMNO) .AND.
     2       ACSSZ .EQ. EXSSZ (ELEMNO) ) THEN
C           OK so far
         ELSE
            WRITE (MSG, '(A,I2,A)')
     1            'element size from PQECO in position #', ELEMNO, '.'
            GOTO 190
         ENDIF

         GOTO (110,120,130,140), ELEMNO                      
         CALL UNMSG ('Element number out of expected range.')

C  polymarker
110      CONTINUE                                            
         IF (ICONT(1) .EQ. 4                            .AND.
     1       RAREQ (4, RCONT(1), XVALS, ABSTOL, RELTOL) .AND.
     2       RAREQ (4, RCONT(5), YVALS, ABSTOL, RELTOL) ) THEN
C           OK
         ELSE
            MSG = 'contents for polymarker.'
         ENDIF
         GOTO 190

C  text
120      CONTINUE
         IF (APPEQ (RCONT(1), XPOS, ABSTOL, RELTOL) .AND.
     1       APPEQ (RCONT(2), YPOS, ABSTOL, RELTOL) .AND.
     2       SLEN(1)  .EQ. 12                       .AND.
     3       SCONT(1) .EQ. 'Text string.'  ) THEN
C           OK
         ELSE
            MSG = 'contents for text.'
         ENDIF
         GOTO 190

C  add names to set
130      CONTINUE
         IF (SETEQ(7, ICONT, NMVALS)) THEN
C           OK
         ELSE
            MSG = 'contents for add names to set.'
         ENDIF
         GOTO 190

C  generalized drawing primitive
140      CONTINUE
         IF ( ICONT(1) .EQ. NUMRLS                       .AND.
     1        ICONT(2) .EQ. GDPID                        .AND.
     2        RAREQ (3, RCONT(1), XVALS, ABSTOL, RELTOL) .AND.
     3        RAREQ (3, RCONT(4), YVALS, ABSTOL, RELTOL) ) THEN
C           OK so far
         ELSE
            MSG = 'numeric contents for generalized drawing primitive.'
            GOTO 190
         ENDIF

C  check size and contents of data records in GDP
         DO 145 IX = 1,ACSSZ
            IF (SLEN(IX).NE.80 .OR. SCONT(IX).NE.DATREC(IX)) THEN
               MSG = 'data record contents for generalized ' //
     1               'drawing primitive.'
               GOTO 190
            ENDIF
145      CONTINUE

         GOTO 190

190      CONTINUE

C  skip_contents:
150      CONTINUE
         IF (MSG .EQ. 'OK') THEN
C           do nothing
         ELSE
            CONOK = .FALSE.
            CALL INMSG ('Incorrect ' // MSG)
         ENDIF

100   CONTINUE

      CALL PQETS (STRUID(1), 5, ERRIND, ELTYPE, ACISZ,ACRSZ,ACSSZ)
      IF (ERRIND .EQ. 202) THEN
C        OK - non-existent as expected
      ELSE
         CONOK = .FALSE.
         CALL INMSG ('Extra element found at end of ' //
     1               'retrieved structure.')
      ENDIF

C  end_tests:
300   CONTINUE
      CALL IFPF (CONOK)

666   CONTINUE
      CALL ENDIT
      END
