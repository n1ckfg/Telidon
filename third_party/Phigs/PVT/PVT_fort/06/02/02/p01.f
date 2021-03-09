C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 06.02.02/01                           *
C  *    TEST TITLE : View index                            *
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
 
      INTEGER    ISIZ,    RSIZ,    SSIZ
      INTEGER    ILEN,    RLEN,    SLEN
      PARAMETER (ILEN=20, RLEN=20, SLEN=20)
 
      INTEGER    IAR(ILEN), LSTRAR(SLEN), CELTYP, VWI, UNAVID
      REAL       RAR(RLEN)
      CHARACTER  STRAR(SLEN)*80, MSG*300
 
      INTEGER    SPECON, SPECWT,
     1           IDUM1, IDUM2, IDUM3, IDUM4, IDUM5, IDUM6, IDUM7
 
C element type
      INTEGER    PERMCV,      PEVWI,       PEEXST,      PELB
      PARAMETER (PERMCV = 64, PEVWI  = 65, PEEXST = 66, PELB   = 67)
 
      CALL INITGL ('06.02.02/01')
 
C open PHIGS
      CALL XPOPPH (ERRFIL, MEMUN)
      CALL POPST (10)
      VWI = 0
      CALL PSVWI (VWI)
 
      CALL SETMSG ('1 2', '<Inquire current element type and size> '  //
     1             'should return view index as the type of the '     //
     2             'created element and the appropriate element '     //
     3             'size.')
 
      CALL PQCETS (ERRIND, CELTYP, ISIZ, RSIZ, SSIZ)
      CALL IFPF ( ERRIND .EQ. 0      .AND.
     1            CELTYP .EQ. PEVWI  .AND.
     2            ISIZ   .EQ. 1      .AND.
     3            RSIZ   .EQ. 0      .AND.
     4            SSIZ   .EQ. 0 )
 
      CALL SETMSG ('1 3', '<Inquire current element content> should ' //
     1             'return the standard representation for view '     //
     2             'index, when the index is 0.')
      CALL PQCECO (ILEN,RLEN,SLEN, ERRIND, ISIZ, IAR, RSIZ, RAR,
     1             SSIZ, LSTRAR, STRAR)
 
      CALL IFPF ( ERRIND .EQ. 0      .AND.
     1            ISIZ   .EQ. 1      .AND.
     2            IAR(1) .EQ. VWI    .AND.
     3            RSIZ   .EQ. 0      .AND.
     4            SSIZ   .EQ. 0 )
 
C  <inquire workstation state table lengths> to determine
C     unavid = view index not available for primary workstation type
 
C open workstation
      CALL POPWK  (WKID, CONID, WTYPE)
      CALL PQWKC  (WKID, ERRIND, SPECON, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)
 
      CALL PQWKSL (SPECWT, ERRIND, IDUM1, IDUM2, IDUM3,
     1             IDUM4, IDUM5, IDUM6, IDUM7, UNAVID)
      CALL CHKINQ ('pqwksl', ERRIND)
      UNAVID = UNAVID+3
 
      CALL SETMSG ('1 3', 'Any non-negative view index should be '    //
     1             'accepted as valid, even if not supported by '     //
     2             'some workstation types.')
 
      CALL ERRCTL (.TRUE.)
      CALL PSVWI (UNAVID)
      IF (ERRSIG .NE. 0) THEN
         CALL FAIL
         WRITE (MSG, '(A,I5,A,I5,A)')
     1         '<Set view index> with view index = ', UNAVID,
     2         ' failed with error code = ', ERRSIG, '.'
         CALL INMSG (MSG)
         GOTO 666
      ENDIF
 
      CALL PQCECO (ILEN,RLEN,SLEN, ERRIND, ISIZ, IAR, RSIZ, RAR,
     1             SSIZ, LSTRAR, STRAR)
      CALL IFPF ( ERRIND .EQ. 0      .AND.
     1            ISIZ   .EQ. 1      .AND.
     2            IAR(1) .EQ. UNAVID .AND.
     3            RSIZ   .EQ. 0      .AND.
     4            SSIZ   .EQ. 0 )
 
666   CONTINUE
      CALL ERRCTL (.FALSE.)
      CALL ENDIT
      END
