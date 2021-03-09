      SUBROUTINE PSTCTL (CTL)

C  PSTCTL controls the posting of structures.

C  CTL function
C  --- --------
C   0  unpost both picture and dialogue structure
C   1  post picture only
C   2  post dialogue only
C   3  post both
C   4  switch picture/dialogue posting; dialogue if neither or both

C  POSTAT keeps track of current posting status:
C  POSTAT  status
C  ------  ------
C     0    neither posted
C     1    picture posted
C     2    dialogue posted
C     3    both posted

      SAVE

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

      INTEGER    CTL, POSTAT

C  action table: what to do based on POSTAT and CTL
      CHARACTER  ACT(0:3, 0:4)*4, DOACT*4

      DATA       POSTAT / 0 /
C                POSTAT: 0         1        2        3
      DATA       ACT /  'n',      'Up',    'Ud',    'UpUd',
     1                  'Pp',     'n',     'UdPp',  'Ud',
     1                  'Pd',     'UpPd',  'n',     'Up',
     1                  'PpPd',   'Pd',    'Pp',    'n',
     1                  'Pd',     'UpPd',  'UdPp',  'Up' /

      DOACT = ACT(POSTAT, CTL)
      IF (DOACT .EQ. 'n') RETURN
      IF (INDEX(DOACT, 'Up') .GT. 0) CALL PUPOST (WKID, PSTRID)
      IF (INDEX(DOACT, 'Ud') .GT. 0) CALL PUPOST (WKID, DSTRID)
      IF (INDEX(DOACT, 'Pp') .GT. 0) CALL  PPOST (WKID, PSTRID, 0.0)
      IF (INDEX(DOACT, 'Pd') .GT. 0) CALL  PPOST (WKID, DSTRID, 1.0)

      IF (CTL .EQ. 4) THEN
         IF (POSTAT .EQ. 2) THEN
            POSTAT = 1
         ELSE
            POSTAT = 2
         ENDIF
      ELSE
         POSTAT = CTL
      ENDIF

      END
