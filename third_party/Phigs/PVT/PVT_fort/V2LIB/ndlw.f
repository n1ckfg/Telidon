      SUBROUTINE NDLW (REQLW, NOMLW, MINLW)

C  NDLW attempts to set linewidth to a requested value, but not
C  near the default (=1).
C
C  Input parameters:
C    REQLW  : requested linewidth - actual will be no greater
C    NOMLW  : nominal linewidth
C    MINLW  : minimum linewidth

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      REAL      REQLW, NOMLW, MINLW, NDLWSC

      IF (.98 .LT. NDLWSC .AND. NDLWSC .LT. 1.02) THEN
C  default near maximum requested - set to min
         NDLWSC = MINLW/NOMLW
      ELSE
C  get requested scale factor
         NDLWSC = REQLW / (NOMLW*WCPDC)
      ENDIF
      CALL PSLWSC (NDLWSC)

      END
