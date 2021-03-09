#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     EVALUATE VIEW ORIENTATION MATRIX 3- calculate transformation
     matrix that orients the View Reference Coordinate (VRC) sys-
     tem in the World Coordinate (WC) system

  FORTRAN Syntax
     SUBROUTINE pevom3 ( VWRX, VWRY, VWRZ, VPNX, VPNY, VPNZ, VUPX, VUPY,
          VUPZ, ERRIND, VWORMT )
     REAL        VWRX, VWRY, VWRZ  view reference point (WC)
     REAL        VPNX, VPNY, VPNZ  view plane normal (WC)
     REAL        VUPX, VUPY, VUPZ  view up vector (WC)
     INTEGER     ERRIND            OUT error indicator
     REAL        VWORMT(4, 4)      OUT view orientation matrix
**************************************************************************/
#ifdef NO_PROTO
nevom3 (vwrx, vwry, vwrz, vpnx, vpny, vpnz, vupx, vupy, vupz, errind, vwormt)
   real    *vwrx,
            *vwry,
            *vwrz,
            *vpnx,
            *vpny,
            *vpnz,
            *vupx,
            *vupy,
            *vupz,
             vwormt[4][4];
   integer      *errind;
#else
nevom3 (real *vwrx, real *vwry, real *vwrz, real *vpnx, real *vpny, real *vpnz,
     real *vupx, real *vupy, real *vupz, integer *errind, real vwormt[4][4])
#endif
{
   Pint      cerror, i, j;
   Ppoint3   vrp;
   Pvec3     vpn;
   Pvec3     vup;
   Pmatrix3  matrix;


   vrp.x = *vwrx;
   vrp.y = *vwry;
   vrp.z = *vwrz;

   vpn.delta_x = *vpnx;
   vpn.delta_y = *vpny;
   vpn.delta_z = *vpnz;

   vup.delta_x = *vupx;
   vup.delta_y = *vupy;
   vup.delta_z = *vupz;

/**************************************************************************
  C Syntax
     void
     peval_view_ori_matrix3 ( vrp, vpn, vup, errind, m )
     Ppoint3     *vrp;             view reference point
     Pvec3       *vpn;             view plane normal
     Pvec3       *vup;             view up vector
     Pint        *errind;          OUT error indicator
     Pmatrix3    m;                OUT view orientation matrix
**************************************************************************/

   peval_view_ori_matrix3 (&vrp, &vpn, &vup, &cerror, matrix);

   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 vwormt[i][j] = matrix[j][i];
}
