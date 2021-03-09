C  *********************************************************
C  *                                                       *
C  *    SUBROUTINE 03.05/setdif                            *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      SUBROUTINE SETDIF (BASSIZ, BASEL, SUBSIZ, SUBEL, ANSSIZ, ANSEL)

C  Setdif performs set difference:
C     ansel = basel - subel
C
C  Input parameters:
C     basel  : source set
C     bassiz : size of basel
C     subel  : subtracted set
C     sunsiz : size of subel
C  Output parameter:
C     ansel  : result set
C     anssiz : size of ansel

      INTEGER BASSIZ, BASEL(*), SUBSIZ, SUBEL(*), ANSSIZ, ANSEL(*),
     1        INDX1, INDX2

      ANSSIZ = 0
      DO 100, INDX1 = 1, BASSIZ
         DO 200, INDX2 = 1, SUBSIZ
            IF (BASEL(INDX1) .EQ. SUBEL(INDX2)) THEN
               GOTO 100
            ENDIF
200      CONTINUE
         ANSSIZ = ANSSIZ + 1
         ANSEL(ANSSIZ) = BASEL(INDX1)
100   CONTINUE
      END
