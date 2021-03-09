      SUBROUTINE RNSET  (SIZE, MAXMEM, SET)

C RNSET returns a random set of SIZE distinct integers, chosen from
C the universe of 1-MAXMEM, returned in SET.  For example, if SIZE is
C specified as 4, and MAXMEM as 7, SET might = [2,5,7,4].

      INTEGER   SIZE, MAXMEM, SET (SIZE)

      CALL RNBSET (SIZE, 1, MAXMEM, SET)

      END
