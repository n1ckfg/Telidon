#include <phigs.h>
#include "f2c.h"

/***********************************************************
NAME
     COMPOSE MATRIX  - generate the composition of two  homogene-
     ous 2D matrices

  FORTRAN Syntax
     SUBROUTINE pcom ( XFRMTA, XFRMTB, ERRIND, XFRMTO )
     REAL        XFRMTA(3, 3)      transformation matrix A
     REAL        XFRMTB(3, 3)      transformation matrix B
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMTO(3, 3)      OUT composed transformation matrix
***********************************************************/
#ifdef NO_PROTO
ncom (xfrmta, xfrmtb, errind, xfrmto)
   real     xfrmta[3][3],
             xfrmtb[3][3],
             xfrmto[3][3];
   integer      *errind;
#else
ncom (real xfrmta[3][3], real xfrmtb[3][3], integer *errind, real xfrmto[3][3])
#endif
{
   Pint      i, j, cerror;
   Pmatrix   a,
             b,
             result;
/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 a[i][j] = xfrmta[j][i];

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 b[i][j] = xfrmtb[j][i];

/***********************************************************
  C Syntax
     void
     pcompose_matrix ( a, b, errind, m )
     Pmatrix     a;                matrix a
     Pmatrix     b;                matrix b
     Pint        *errind;          OUT error indicator
     Pmatrix     m;                OUT result matrix
***********************************************************/

   pcompose_matrix (a, b, &cerror, result);

   *errind = cerror;

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 xfrmto[i][j] = result[j][i];
}
