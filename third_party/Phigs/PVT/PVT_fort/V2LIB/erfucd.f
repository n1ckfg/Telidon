      SUBROUTINE ERFUCD (FUNNAM, FUNCCD)

C  ERFUCD accepts a character string identifying a generic function
C  and returns the standard function code.
C
C  Input parameter:
C    FUNNAM : generic name of function
C  Output parameter:
C    FUNCCD : integer code for offending function

      INTEGER    FUNCCD, IX,IY, LEADNB, ITRIM
      CHARACTER  FUNNAM*(*), WNAM*100, TRUNAM*100

      FUNCCD = -1
      IF (FUNNAM.EQ.' ') RETURN

C  check whether already enclosed in angle brackets
      IX = INDEX (FUNNAM, '<')
      IF (IX.GT.0) THEN
         WNAM = FUNNAM(IX:)
      ELSE
         IX = LEADNB(FUNNAM)
         IY = ITRIM(FUNNAM)
         WNAM = '<' // FUNNAM(IX:IY) // '>'
      ENDIF

C  WNAM now has canonical function name
      DO 100 IY = 0,182
         CALL ERFUNM (IY, TRUNAM)
         IF (WNAM.EQ.TRUNAM) THEN
            FUNCCD = IY
            RETURN
         ENDIF
100   CONTINUE

      END
