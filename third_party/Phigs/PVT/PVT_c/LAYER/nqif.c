#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE INTERIOR FACILITIES -  obtain  list  of  workstation
     interior facilities from workstation description table

  FORTRAN Syntax
     SUBROUTINE pqif ( WTYPE, NI, NH, ERRIND, NIS, IS, NHS, HS, NPFAI )
     INTEGER     WTYPE             workstation type
     INTEGER     NI                list element of interior styles requested
     INTEGER     NH                list element of hatch styles requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NIS               OUT number of available interior styles
     INTEGER     IS                OUT NIth element of list of available interior
                                   styles
     INTEGER     NHS               OUT number of available hatch styles
     INTEGER     HS                OUT NHth element of list of available hatch
                                   style indices
     INTEGER     NPFAI             OUT number of predefined interior indices
**************************************************************************/
#ifdef NO_PROTO
nqif (wtype, ni, nh, errind, nis, is, nhs, hs, npfai)
   integer      *wtype,
            *ni,
            *nh,
            *errind,
            *nis,
            *is,
            *nhs,
            *hs,
            *npfai;
#else
nqif (integer *wtype, integer *ni, integer *nh, integer *errind, 
      integer *nis, integer *is, integer *nhs, integer *hs, integer *npfai)
#endif
{
   Pint      length, cerror, start, total_length;
   Pint_facs facilities;

   start = *nh - (*nh > 0);
   length = (*nh != 0);

   facilities.hatch_styles.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_int_facs ( type, h_len, h_st, errind, facil, tot_h_len )
     Pint        type;             workstation type
     Pint        h_len;            length of hatch style list
     Pint        h_st;             starting position
     Pint        *errind;          OUT error indicator
     Pint_facs   *facil;           OUT interior facilities
     Pint        *tot_h_len;       OUT len of hatch list in PHIGS
**************************************************************************/

   pinq_int_facs ((Pint) *wtype, length, start, &cerror, &facilities, 
                  &total_length);
   *errind = cerror;

   *nhs = total_length;
   *nis = facilities.num_int_styles;
   *npfai = facilities.num_pred_inds;

   *is = facilities.int_styles[*ni - 1];
   if (facilities.int_styles[*ni - 1] == PSTYLE_HOLLOW)
      *is = 0;
   if (facilities.int_styles[*ni - 1] == PSTYLE_SOLID)
      *is = 1;
   if (facilities.int_styles[*ni - 1] == PSTYLE_PAT)
      *is = 2;
   if (facilities.int_styles[*ni - 1] == PSTYLE_HATCH)
      *is = 3;
   if (facilities.int_styles[*ni - 1] == PSTYLE_EMPTY)
      *is = 4;

   *hs = *facilities.hatch_styles.ints;
   free (facilities.hatch_styles.ints);
}
