      REAL FUNCTION SATAN2 (Y, X)

C  Safe version of arctan-2 function; returns zero when both x and y
C  are zero.

      REAL  X,Y

      IF (X .EQ. 0.0 .AND. Y .EQ. 0.0) THEN
         SATAN2 = 0.0
      ELSE
         SATAN2 = ATAN2(Y,X)
      ENDIF

      END
