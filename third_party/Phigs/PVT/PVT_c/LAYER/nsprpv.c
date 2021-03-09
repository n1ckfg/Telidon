#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET PATTERN REFERENCE POINT AND VECTORS -  create  structure
     element  to  set current pattern reference point and vectors
     attributes

  FORTRAN Syntax
     SUBROUTINE psprpv ( RFX, RFY, RFZ, RFVX, RFVY, RFVZ )
     REAL        RFX, RFY, RFZ       pattern reference point (MC)
     REAL        RFVX(2), RFVY(2), RFVZ(2)pattern reference vectors (MC)
**************************************************************************/
#ifdef NO_PROTO
nsprpv (rfx, rfy, rfz, rfvx, rfvy, rfvz)
   real    *rfx,
            *rfy,
            *rfz,
             rfvx[2],
             rfvy[2],
             rfvz[2];
#else
nsprpv (real *rfx, real *rfy, real *rfz, real rfvx[2], real rfvy[2],
	real rfvz[2])
#endif
{
   Ppoint3   ref_pt;
   Pvec3     pat_ref_vec[2];
   ref_pt.x = *rfx;
   ref_pt.y = *rfy;
   ref_pt.z = *rfz;

   pat_ref_vec[0].delta_x = rfvx[0];
   pat_ref_vec[0].delta_y = rfvy[0];
   pat_ref_vec[0].delta_z = rfvz[0];

   pat_ref_vec[1].delta_x = rfvx[1];
   pat_ref_vec[1].delta_y = rfvy[1];
   pat_ref_vec[1].delta_z = rfvz[1];

/**************************************************************************
  C Syntax
     void
     pset_pat_ref_point_vecs ( ref_pt, pat_ref_vec )
     Ppoint3     *ref_pt;            pattern reference point
     Pvec3       pat_ref_vec[2];     direction vectors; 1=X axis of pattern,
**************************************************************************/

   pset_pat_ref_point_vecs (&ref_pt, pat_ref_vec);
}
