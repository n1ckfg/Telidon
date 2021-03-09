      SUBROUTINE PRPFNT (SPECWT, BESTFN)

C  PRPFNT looks for a stroke text font other than 1, preferably not
C  #2 and not monospaced.

C  Input parameters:
C    SPECWT : workstation type
C  Output parameters:
C    BESTFN : selected font

      INTEGER   SPECWT, BESTFN
      REAL      RDUM1,RDUM2,RDUM3,RDUM4

      CALL SUBFNT (SPECWT, BESTFN, RDUM1,RDUM2,RDUM3,RDUM4)

      END
