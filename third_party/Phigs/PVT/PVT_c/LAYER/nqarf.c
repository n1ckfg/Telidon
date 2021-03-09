#include <phigs.h>
#include "f2c.h"
#include "f2c.h"
#include "fio.h"

/**************************************************************************
NAME
     INQUIRE ARCHIVE FILES - obtain currently open archive file
     identifiers and names

  FORTRAN Syntax
     SUBROUTINE pqarf ( N, ERRIND, NUMBER, AFID, ARCFIL )
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NUMBER            OUT number of archive files open
     INTEGER     AFID              OUT Nth open archive file identifier
     INTEGER     ARCFIL            OUT Nth open archive file name
**************************************************************************/
#ifdef NO_PROTO
nqarf (n, errind, number, afid, arcfil)
   integer      *n,
            *errind,
            *number,
            *afid,
            *arcfil;
#else
nqarf (integer *n, integer *errind, integer *number, integer *afid, 
       integer *arcfil)
#endif
{
   Pint             cerror, i;
   Par_file_list    *ar_files;
   Pstore           store;

/*
Problem here and in general is that non-zero errind may indicate
PHIGS/C problem for the function being simulated or an unrelated
problem, like with pdel_store.  Use negative for latter case.
*/

/* Create the memory buffer if not already created. */

   pcreate_store (&cerror, &store);
   if (cerror)
   {
   /******* Cannot create memory buffer  ********/
      *errind = -cerror;
      return;
   }

/**************************************************************************
  C Syntax
     void
     pinq_ar_files ( store, errind, ar_files )
     Pstore      store;            handle to Store object
     Pint        *errind;          OUT error indicator
     Par_file_list                 **ar_files;OUT list of archive file
**************************************************************************/

   pinq_ar_files (store, &cerror, &ar_files);
   *errind = cerror;
   if (*errind) return;

   *number = ar_files->num_ar_files;

/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   if (*n == 0)
   {

      pdel_store (&cerror, &store);
      *errind = -cerror;
      return;
   }

   if ((*n <= *number) && (*number > 0))
   {
      *afid = ar_files->ar_files[*n - 1].id;

   /*** Now, search through the list f2c keeps on open
        Fortran units searching for the file name with
        ar_files->ar_files[*n-1].id, then get the LUN
        associated with it for Fortan.    ***/

      *arcfil = -1;

      for (i = 1; i < MXUNIT; i++)
      {
	 if (f__units[i].uinode && f__units[i].ufnm)
	 {
	    if (strcmp(f__units[i].ufnm, ar_files->ar_files[*n - 1].name) == 0)
	    {
	       *arcfil = i;
	       break;
	    }
	 }
      }

      if (*arcfil == -1)
      {				/*** Did not find it ***/

         pdel_store (&cerror, &store);
	 *errind = -1;
	 return;
      }
   }

   pdel_store (&cerror, &store);
   *errind = -cerror;
}
