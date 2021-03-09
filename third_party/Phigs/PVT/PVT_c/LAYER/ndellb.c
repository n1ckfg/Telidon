#include <phigs.h>
#include "f2c.h"

/***************************************************************************
NAME
     DELETE ELEMENTS BETWEEN LABELS - delete all elements in  the
     open structure between specified labels

  FORTRAN Syntax
     SUBROUTINE pdellb ( LABEL1, LABEL2 )
     INTEGER     LABEL1, LABEL2    label range
***************************************************************************/
#ifdef NO_PROTO
ndellb (label1, label2)
   integer      *label1,
            *label2;
#else
ndellb (integer *label1, integer *label2)
#endif
{

/***************************************************************************
  C Syntax
     void
     pdel_elems_labels ( label1_id, label2_id )
     Pint        label1_id;        label 1 identifier
     Pint        label2_id;        label 2 identifier
***************************************************************************/

   pdel_elems_labels ((Pint) *label1, (Pint) *label2);
}
