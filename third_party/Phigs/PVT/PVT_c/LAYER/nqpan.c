#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PATHS TO ANCESTORS - obtain ancestors  of  specified
     structure

  FORTRAN Syntax
     SUBROUTINE pqpan ( STRID, PTHORD, PTHDEP, IPTHSZ, N, ERRIND, OL,
                          APTHSZ, PATHS )
     INTEGER     STRID             structure identifier
     INTEGER     PTHORD            path order (PPOTOP, PPOBOT)
     INTEGER     PTHDEP            path depth
     INTEGER     IPTHSZ            size of path buffer
     INTEGER     N                 element of list of paths
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of paths available
     INTEGER     APTHSZ            OUT actual size of the Nth structure path
     INTEGER     PATHS(2, IPTHSZ)  OUT Nth structure path
**************************************************************************/
#ifdef NO_PROTO
nqpan (strid, pthord, pthdep, ipthsz, n, errind, ol, apthsz, fpath)
   integer      *strid,
            *pthord,
            *pthdep,
            *ipthsz,
            *n,
            *errind,
            *ol,
            *apthsz,
             fpath[][2];
#else
nqpan (integer *strid, integer *pthord, integer *pthdep, integer *ipthsz, 
       integer *n,
       integer *errind, integer *ol, integer *apthsz, integer fpath[][2])
#endif
{

   Pelem_ref_list_list *path;
   Pint      cerror, i;
   Ppath_order order;
   Pstore    store;

/* Create the memory buffer if not already created. */
   pcreate_store (&cerror, &store);
   *errind = cerror;

   if (*errind)
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
     pinq_paths_ances ( struct_id, order, depth, store, errind, paths )
     Pint          struct_id;      structure identifier
     Ppath_order   order;          path order
     Pint          depth;          path depth
     Pstore        store;          handle to Store object
     Pint        *errind;          OUT error indicator
     Pelem_ref_list_list           **paths;OUT structure path list
**************************************************************************/

   pinq_paths_ances ((Pint) *strid, order, (Pint) *pthdep, store, 
                     &cerror, &path);
   *errind = cerror;
   if (*errind)
   {
   /* Problem with the inquire */
      return;
   }

   *ol = path->num_elem_ref_lists;
   if (*n != 0)
   {  /*** Not getting just the size of the list ****/
      if (path->num_elem_ref_lists <= *n - 1)
      {
      /* Requesting a path element larger than the list */
	 return;
      }

      /* Check that the input buffer is large enough to
	 hold all the elements of the path to be returned */
      if ( *apthsz > *ipthsz) {
	    *errind = 2001;    /* FORTRAN error for insufficient space */
	    return;            /* we use this error because C does not
                                  have an equivalent.  */
      }

      *apthsz = path->elem_ref_lists[*n - 1].num_elem_refs;

      for (i = 0; i < *apthsz; i++)
      {
	 fpath[i][0] = path->elem_ref_lists[*n - 1].elem_refs[i].struct_id;
	 fpath[i][1] = path->elem_ref_lists[*n - 1].elem_refs[i].elem_pos;
      }
   }

   pdel_store (&cerror, &store);
   *errind = 0;
}
