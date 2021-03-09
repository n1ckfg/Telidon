      SUBROUTINE IACANS (RESP)

C  IACANS gets a single-line character string response (RESP) from
C  the operator in accordance with DINTYP.  For DINTYP 1, IACANS
C  simply issues a Fortran read statement. For DINTYP 2, IACANS
C  invokes the PHIGS <request string> function.  If the response
C  is non-blank, leading blanks are deleted.

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

C regeneration flag
      INTEGER    PPOSTP,     PPERFO
      PARAMETER (PPOSTP = 0, PPERFO = 1)

C input device status
      INTEGER    PNONE,     POK,     PNPICK,     PNCHOI
      PARAMETER (PNONE = 0, POK = 1, PNPICK = 2, PNCHOI = 3)

      INTEGER   RQSTAT,LOSTR,LEADNB

      CHARACTER RESP*(*), MSG*100

100   CONTINUE
C  force screen update
      CALL PUWK (WKID, PPERFO)
      RESP = ' '
C  get response
      IF (DINTYP .EQ. 1) THEN
         READ (*,'(A)') RESP
      ELSEIF (DINTYP .EQ. 2) THEN
         CALL PRQST (WKID, DSTDNR, RQSTAT,LOSTR,RESP)
         IF (RQSTAT .NE. POK) THEN
            WRITE (MSG, '(A,I5)') 'Non-OK status from ' //
     1                            '<request string>: ', RQSTAT
            CALL UNMSG (MSG)
         ENDIF

C  ensure trailing blanks
         IF (LOSTR .LT. LEN(RESP)) RESP(LOSTR+1:) = ' '

      ELSE
         WRITE (MSG, '(A,I5)') 'Invalid input type in IACANS: ', DINTYP
         CALL UNMSG (MSG)
      ENDIF

C  delete leading blanks
      IF (RESP .NE. ' ') RESP = RESP(LEADNB(RESP):)

C  check for toggling
      IF (SCRMOD.EQ.3 .AND. (RESP.EQ.'T' .OR. RESP.EQ.'t')) THEN
         CALL PSTCTL (4)
         GOTO 100
      ENDIF

      END
