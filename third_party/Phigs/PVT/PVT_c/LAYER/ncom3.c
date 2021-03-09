#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     COMPOSE MATRIX 3 - generate the composition of two homogene-
     ous 3D matrices

  FORTRAN Syntax
     SUBROUTINE pcom3 ( XFRMTA, XFRMTB, ERRIND, XFRMTO )
     REAL        XFRMTA(4, 4)      transformation matrix A
     REAL        XFRMTB(4, 4)      transformation matrix B
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMTO(4, 4)      OUT composed transformation matrix
**************************************************************************/
#ifdef NO_PROTO
ncom3 (xfrmta, xfrmtb, errind, xfrmto)
   real     xfrmta[4][4],
             xfrmtb[4][4],
             xfrmto[4][4];
   integer      *errind;
#else
ncom3 (real xfrmta[4][4], real xfrmtb[4][4], integer *errind, real xfrmto[4][4])
#endif
{
   Pint      i, j, cerror;
   Pmatrix3  a,
             b,
             result;
/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/
   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 a[i][j] = xfrmta[j][i];

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 b[i][j] = xfrmtb[j][i];

/**************************************************************************
  C Syntax
     void
     pcompose_matrix3 ( a, b, errind, m )
     Pmatrix3    a;                matrix a
     Pmatrix3    b;                matrix b
     Pint        *errind;          OUT error indicator
     Pmatrix3    m;                OUT result matrix
**************************************************************************/

   pcompose_matrix3 (a, b, &cerror, result);

   *errind = cerror;

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 xfrmto[i][j] = result[j][i];
}
