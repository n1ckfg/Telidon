      SUBROUTINE VARFNT (BESTFN, NCBHTW, NCBWDW, NCBHTI, NCBWDI)

C  VARFNT looks for a stroke text font other than 1, preferably not
C  #2 and not monospaced, and returns nominal size for "W" and "i".

C  Output parameters:
C    BESTFN        : selected font
C    NCBHTW,NCBWDW : nominal height, width of "W" in selected font
C    NCBHTI,NCBWDI : nominal height, width of "i" in selected font

      COMMON /DIALOG/ DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT,
     2                DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS
      INTEGER         DOUTYP, DINTYP, DSTDNR, DSTRID, PSTRID, DTCLIM,
     1                SCRMOD, DTXCI, SPECWT
      REAL            DSIZE, EFRAC, DYXRAT, SYXRAT, MTRPDC, WCPDC, QVIS

      INTEGER    BESTFN
      REAL       NCBHTW, NCBWDW, NCBHTI, NCBWDI

      CALL SUBFNT (SPECWT, BESTFN, NCBHTW, NCBWDW, NCBHTI, NCBWDI)

      END
