      SUBROUTINE SETPST (NUMSTR, STRID, NUMWKS, ACWKID, STINWK)

C  SETPST sets up the complete state of posting among a set
C  of structures and workstations.

C  ------- INPUT PARAMETERS
C  numstr   : number of structures
C  strid    : list of structure identifiers
C  numwks   : number of workstations
C  acwkid   : list of workstation identifiers
C  stinwk   : 2D array, indicating what is to be posted

      INTEGER     NUMSTR, STRID(NUMSTR), NUMWKS, ACWKID(NUMWKS)
      INTEGER     STINWK(NUMSTR, NUMWKS), IWK, ISTR

      DO 100 IWK = 1, NUMWKS
         CALL PUPAST (ACWKID(IWK))
         DO 200 ISTR = 1, NUMSTR
            IF (STINWK (ISTR, IWK) .EQ. 1) THEN
               CALL PPOST (ACWKID(IWK), STRID(ISTR), 1.0)
            ENDIF
200      CONTINUE
100   CONTINUE
      END
