      INTEGER FUNCTION ITRIM (WORD)

C itrim returns the position of the rightmost non-blank within
C a string, zero if all blank.

      INTEGER   LW, ILO, IHI, IMID

      CHARACTER WORD*(*)

      LW  = LEN(WORD)
      ILO = 0
      IHI = LW+1

C do binary search looking for trailing blank portion of word
100   CONTINUE
      IF (IHI-ILO .LE. 1) GOTO 666
      IMID = (IHI+ILO)/2
      IF (WORD(IMID:) .EQ. ' ') THEN
         IHI = IMID
      ELSE
         ILO = IMID
      ENDIF
      GOTO 100

666   CONTINUE
      ITRIM = ILO

      END
