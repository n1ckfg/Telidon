#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     EVALUATE VIEW ORIENTATION MATRIX - calculate  transformation
     matrix  that orients View Reference Coordinate  (VRC) system
     in the World (WC) Coordinate system

  FORTRAN Syntax
     SUBROUTINE pevom ( VWRX, VWRY, VUPX, VUPY, ERRIND, VWORMT )
     REAL        VWRX, VWRY        view reference point (WC)
     REAL        VUPX, VUPY        view up vector (WC)
     INTEGER     ERRIND            OUT error indicator
     REAL        VWORMT(3, 3)      OUT view orientation matrix
**************************************************************************/
#ifdef NO_PROTO
nevom (vwrx, vwry, vupx, vupy, errind, vwormt)
   real    *vwrx,
            *vwry,
            *vupx,
            *vupy,
             vwormt[3][3];
   integer      *errind;
#else
nevom (real *vwrx, real *vwry, real *vupx, real *vupy, integer *errind, real vwormt[3][3])
#endif
{
   Pint      cerror, i, j;
   Ppoint    vrp;
   Pvec      vup;
   Pmatrix   matrix;


   vrp.x = *vwrx;
   vrp.y = *vwry;

   vup.delta_x = *vupx;
   vup.delta_y = *vupy;

/**************************************************************************
  C Syntax
     void
     peval_view_ori_matrix ( vrp, vup, errind, m )
     Ppoint      *vrp;             view reference point
     Pvec        *vup;             view up vector
     Pint        *errind;          OUT error indicator
     Pmatrix     m;                OUT view orientation matrix
**************************************************************************/

   peval_view_ori_matrix (&vrp, &vup, &cerror, matrix);
   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 vwormt[i][j] = matrix[j][i];
}
