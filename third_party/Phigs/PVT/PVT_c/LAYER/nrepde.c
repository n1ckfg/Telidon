#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     RETRIEVE PATHS TO  DESCENDANTS  -  retrieve  descendants  of
     specified structure from archive file

  FORTRAN Syntax
     SUBROUTINE prepde ( AFID, STRID, PTHORD, PTHDEP, IPTHSZ, N, OL, APTHSZ, PATHS )
     INTEGER     AFID              archive file identifier
     INTEGER     STRID             structure identifier
     INTEGER     PTHORD            path order (PPOTOP, PPOBOT)
     INTEGER     PTHDEP            path depth
     INTEGER     IPTHSZ            size of path buffer
     INTEGER     N                 element of list of paths
     INTEGER     OL                OUT number of paths available
     INTEGER     APTHSZ            OUT actual size of the Nth structure path
     INTEGER     PATHS(2, IPTHSZ)  OUT Nth structure path
**************************************************************************/
#ifdef NO_PROTO
nrepde (afid, strid, pthord, pthdep, ipthsz, n, ol, apthsz, fpath)
   integer      *afid,
            *strid,
            *pthord,
            *pthdep,
            *ipthsz,
            *n,
            *ol,
            *apthsz,
             fpath[][2];
#else
nrepde (integer *afid, integer *strid, integer *pthord, integer *pthdep, 
        integer *ipthsz, integer *n,
	integer *ol, integer *apthsz, integer fpath[][2])
#endif
{

   Pint      i, errind;
   Ppath_order order;
   Pstore    store;
   Pelem_ref_list_list *path;
/* Create the memory buffer if not already created. */

   pcreate_store (&errind, &store);
   if (errind)
   {
   /* Cannot create memory buffer */
      return;
   }

   order = *pthord;
   switch (*pthord)
   {
   case 0:
      order = PORDER_TOP_FIRST;
      break;
   case 1:
      order = PORDER_BOTTOM_FIRST;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pret_paths_descs ( ar_id, struct_id, po, pd, store, paths)
     Pint           ar_id;         archive identifier
     Pint           struct_id;     structure identifier
     Ppath_order    po;            path order
     Pint           pd;            path depth
     Pstore         store;         handle to Store object
     Pelem_ref_list_list           **paths;OUT path list
**************************************************************************/

   pret_paths_descs ((Pint) *afid, (Pint) *strid, order, (Pint) *pthdep, 
                     store, &path);

   *ol = path->num_elem_ref_lists;

   if (*n != 0)
   { /*** Not getting just the size of the list ****/
      if (path->num_elem_ref_lists <= *n - 1)
      {
      /* Requesting a path element larger than the list */
	 return;
      }

      /* Check that the input buffer is large enough to
	 hold all the elements of the path to be returned */
      if ( *apthsz > *ipthsz) {
	    *apthsz = 2001;     /* This is the FORTAN error for insufficient space */
	    return;             /* we use this error because C does not have one   */
      }

      *apthsz = path->elem_ref_lists[*n - 1].num_elem_refs;

      for (i = 0; i < *apthsz; i++)
      {
	 fpath[i][0] = path->elem_ref_lists[*n - 1].elem_refs[i].struct_id;
	 fpath[i][1] = path->elem_ref_lists[*n - 1].elem_refs[i].elem_pos;
      }
   }

   pdel_store (&errind, &store);
}
