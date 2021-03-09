C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 09.01/01                              *
C  *    TEST TITLE : Testing the error handling mode       *
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

      INTEGER         POFF,      PON
      PARAMETER      (POFF=0,    PON=1)

      INTEGER    HNDMOD

      CALL INITGL ('09.01/01')

      CALL XPOPPH (ERRFIL, MEMUN)

      CALL SETMSG ('2 3', 'After opening PHIGS, <inquire error ' //
     1             'handling mode> should return ON.')

      CALL PQERHM (ERRIND, HNDMOD)
      CALL IFPF (ERRIND.EQ.0 .AND. HNDMOD.EQ.PON)
C
      CALL SETMSG ('1 3', 'After <set error handling mode> to OFF, ' //
     1             '<inquire error handling mode> should return OFF.')

      CALL PSERHM (POFF)
      CALL PQERHM (ERRIND, HNDMOD)
      CALL IFPF (ERRIND.EQ.0 .AND. HNDMOD.EQ.POFF)

      CALL SETMSG ('1 3', 'After <set error handling mode> to ON, ' //
     1             '<inquire error handling mode> should return ON.')

      CALL PSERHM (PON)
      CALL PQERHM (ERRIND, HNDMOD)
      CALL IFPF (ERRIND.EQ.0 .AND. HNDMOD.EQ.PON)

      CALL ENDIT

      END
