      LOGICAL FUNCTION STRCON (STRID, STRG)

C  Strcon is used to check the contents of a single structure.
C
C  Strid is the identifier of the structure to be examined.
C  Strg is a string representing a list of integers, which are
C  interpreted as type-content pairs.  Only the first integer
C  in an element's content is checked, i.e. that mapped to
C  the first slot in the integer array by PQCECO or PQECO
C
C  If the structure contains a sequence of elements exactly matching
C  these type-content pairs, strcon returns TRUE, otherwise FALSE.
C  A blank string may be used to designate an empty structure, but
C  the structure must exist.

C structure status indicator
      INTEGER    PSNOEX,     PSEMPT,     PSNEMP
      PARAMETER (PSNOEX = 0, PSEMPT = 1, PSNEMP = 2)

      INTEGER    TYPCON(300), EP, SIZE, LSTELE, STRID, ERRIND
      INTEGER    IDIM,RDIM,SDIM, ISIZ,RSIZ,SSIZ, ELTYPE, STAT
      PARAMETER (IDIM = 20, RDIM = 20, SDIM = 20)

      INTEGER    IA(IDIM), SL(SDIM), ICON,ITYP, NOELEM
      REAL       RA(RDIM)
      CHARACTER  SA(SDIM)*80, MSG*100

C  error code for non-existent element
      PARAMETER (NOELEM = 202)

      CHARACTER  STRG*(*)

C generate integer array from strg
      CALL SETVS (STRG, TYPCON, SIZE)

      IF (MOD(SIZE,2) .NE. 0) THEN
         MSG = 'Illegal string passed to strcon; must be ' //
     1         'even number of elements: ' // STRG
         CALL UNMSG (MSG)
      ENDIF
C last element
      LSTELE = SIZE/2

C check structure existence
      CALL PQSTST (STRID, ERRIND, STAT)
      CALL CHKINQ ('pqstst', ERRIND)

      IF (STAT .EQ. PSNOEX) THEN
         WRITE (MSG, '(A,I7)')
     1     'Non-existent structure passed to strcon: ', STRID
         CALL UNMSG (MSG)
      ENDIF

C check that structure is not too long
      CALL PQETS (STRID, LSTELE+1, ERRIND, ELTYPE, ISIZ,RSIZ,SSIZ)
      IF (ERRIND .NE. NOELEM) THEN
         GOTO 666
      ENDIF

      IF (LSTELE .GT. 0) THEN
C check that structure is not too short
         CALL PQETS (STRID, LSTELE, ERRIND, ELTYPE, ISIZ,RSIZ,SSIZ)
         IF (ERRIND .EQ. NOELEM) THEN
            GOTO 666
         ENDIF
      ENDIF

      DO 100 EP = 1, LSTELE
         CALL PQETS (STRID, EP, ERRIND, ELTYPE, ISIZ,RSIZ,SSIZ)
         IF (ERRIND .EQ. 0) THEN
C  Normal return from pqets
            ICON = EP*2
            ITYP = ICON-1
            IF (ELTYPE .NE. TYPCON(ITYP)) THEN
C  types don't match
               GOTO 666
            ENDIF
            CALL PQECO (STRID, EP, IDIM,RDIM,SDIM,
     1                  ERRIND, ISIZ,IA, RSIZ,RA, SSIZ,SL,SA)
            IF (ERRIND .NE. 0) THEN
C  weird errind from pqeco
               WRITE (MSG, '(A,I7)')
     1           'Strange errind from pqeco in strcon: ', ERRIND
               CALL UNMSG (MSG)
            ENDIF
            IF (IA(1) .NE. TYPCON(ICON)) THEN
C  contents don't match
               GOTO 666
            ENDIF
         ELSE
C  weird errind from pqets
            WRITE (MSG, '(A,I7)')
     1        'Strange errind from pqets in strcon: ', ERRIND
            CALL UNMSG (MSG)
         ENDIF
100   CONTINUE
      STRCON = .TRUE.
      GOTO 667

666   CONTINUE
      STRCON = .FALSE.

667   CONTINUE

      END
