#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INCREMENTAL SPATIAL SEARCH - search  the  structure  network
     for the next occurrence of a graphical output structure ele-
     ment meeting the specified search criteria

  FORTRAN Syntax
     SUBROUTINE piss ( SRPX, SRPY, SDIST, SPTHSZ, SPATH, MCLIPF, SRCHCI,
                       NFLN, NFLISX, NFLIS, NFLESX, NFLES,
                       IFLN, IFLISX, IFLIS, IFLESX, IFLES,
                       IPTHSZ, ERRIND, FPTHSZ, FPATH )
     REAL        SRPX, SRPY        search reference point (WC)
     REAL        SDIST             search distance
     INTEGER     SPTHSZ            number of elements in starting path
     INTEGER     SPATH(2, SPTHSZ)  starting path
     INTEGER     MCLIPF            modelling clip flag
     INTEGER     SRCHCI            search ceiling index
     INTEGER     NFLN              number of normal filters
     INTEGER     NFLISX(NFLN)      array of end indices of normal filter
                                   inclusion sets
     INTEGER     NFLIS(*)          normal filter inclusion sets
     INTEGER     NFLESX(NFLN)      array of end indices of normal filter
                                   exclusion sets
     INTEGER     NFLES(*)          normal filter exclusion sets
     INTEGER     IFLN              number of inverted filters
     INTEGER     IFLISX(IFLN)      array of end indices of inverted filter
                                   inclusion sets
     INTEGER     IFLIS(*)          inverted filter inclusion sets
     INTEGER     IFLESX(IFLN)      array of end indices of inverted filter
                                   exclusion sets
     INTEGER     IFLES(*)          inverted filter exclusion sets
     INTEGER     IPTHSZ            size of found path array
     INTEGER     ERRIND            OUT error indicator
     INTEGER     FPTHSZ            OUT found path size
     INTEGER     FPATH(2, IPTHSZ)  OUT found path
**************************************************************************/
#ifdef NO_PROTO
niss (srpx, srpy, sdist, spthsz, spath, mclipf, srchci, nfln, nflisx, nflis,
      nflesx, nfles, ifln, iflisx, iflis, iflesx, ifles, ipthsz,
      errind, fpthsz, fpath)
   real    *srpx,
            *srpy,
            *sdist;
   integer      *spthsz,
             spath[][2],
            *mclipf,
            *srchci,
            *nfln,
             nflisx[],
             nflis[],
             nflesx[],
             nfles[],
            *ifln,
             iflisx[],
             iflis[],
             iflesx[],
             ifles[],
            *ipthsz,
            *errind,
            *fpthsz,
             fpath[][2];
#else
niss (real *srpx, real *srpy, real *sdist, integer *spthsz, integer spath[][2],
      integer *mclipf, integer *srchci, integer *nfln, integer nflisx[], integer nflis[],
      integer nflesx[], integer nfles[], integer *ifln, integer iflisx[], integer iflis[],
      integer iflesx[], integer ifles[], integer *ipthsz, integer *errind, integer *fpthsz,
      integer fpath[][2])
#endif
{
   Pint            cerror, i, j;
   Pint            st;
   Pint            ceil;
   Pint            total_length;
   Ppoint          ref;
   Pfloat          dist;
   Pclip_ind       clip;
   Pfilter_list    norm;
   Pfilter_list    invt;
   Pelem_ref_list  sp;
   Pelem_ref_list  fp;
   int             incl_namepos1, incl_namepos2, setsize;
   int             excl_namepos1, excl_namepos2;

   ref.x = *srpx;
   ref.y = *srpy;

   dist = *sdist;

   sp.num_elem_refs = *spthsz;
   if (*spthsz > 0)
      sp.elem_refs = (Pelem_ref *) calloc (*spthsz, sizeof (Pelem_ref));
   for (i = 0; i < *spthsz; i++)
   {
      sp.elem_refs[i].struct_id = spath[i][0];
      sp.elem_refs[i].elem_pos  = spath[i][1];
   }

   clip =  *mclipf;
   switch (*mclipf)
   {
   case 0:
      clip = PIND_NO_CLIP;
      break;
   case 1:
      clip = PIND_CLIP;
      break;
   }

   ceil = *srchci;

   /* normal filter */
   norm.num_filters = *nfln;
   if (*nfln > 0)
      norm.filters = (Pfilter *) calloc (*nfln, sizeof (Pfilter));

   incl_namepos1 = 0;
   excl_namepos1 = 0;
   for (i = 0; i < *nfln; i++)
   {
      /* normal inclusion */
      incl_namepos2 = nflisx[i];
      setsize = incl_namepos2 - incl_namepos1;
      norm.filters[i].incl_set.num_ints = setsize;
      if (setsize > 0)
	 norm.filters[i].incl_set.ints =
            (Pint *) calloc (setsize, sizeof (Pint));
      for (j = 0; j < setsize; j++)
      {
	 norm.filters[i].incl_set.ints[j] = nflis[j + incl_namepos1];
      }
      incl_namepos1 = incl_namepos2;

      /* normal exclusion */
      excl_namepos2 = nflesx[i];
      setsize = excl_namepos2 - excl_namepos1;
      norm.filters[i].excl_set.num_ints = setsize;
      if (nflesx[i] > 0)
	 norm.filters[i].excl_set.ints =
            (Pint *) calloc (nflesx[i], sizeof (Pint));
      for (j = 0; j < nflesx[i]; j++)
      {
	 norm.filters[i].excl_set.ints[j] = nfles[j + excl_namepos1];
      }
      excl_namepos1 = excl_namepos2;
   }


   /* inverted filter */
   invt.num_filters = *ifln;
   if (*ifln > 0)
      invt.filters = (Pfilter *) calloc (*ifln, sizeof (Pfilter));

   incl_namepos1 = 0;
   excl_namepos1 = 0;
   for (i = 0; i < *ifln; i++)
   {
      /* inverted inclusion */
      incl_namepos2 = iflisx[i];
      setsize = incl_namepos2 - incl_namepos1;
      invt.filters[i].incl_set.num_ints = setsize;
      if (setsize > 0)
	 invt.filters[i].incl_set.ints =
            (Pint *) calloc (setsize, sizeof (Pint));
      for (j = 0; j < setsize; j++)
      {
	 invt.filters[i].incl_set.ints[j] = iflis[j + incl_namepos1];
      }
      incl_namepos1 = incl_namepos2;

      /* inverted exclusion */
      excl_namepos2 = iflesx[i];
      setsize = excl_namepos2 - excl_namepos1;
      invt.filters[i].excl_set.num_ints = setsize;
      if (iflesx[i] > 0)
	 invt.filters[i].excl_set.ints =
            (Pint *) calloc (iflesx[i], sizeof (Pint));
      for (j = 0; j < iflesx[i]; j++)
      {
	 invt.filters[i].excl_set.ints[j] = ifles[j + excl_namepos1];
      }
      excl_namepos1 = excl_namepos2;
   }

   st = 0;

   fp.num_elem_refs = *ipthsz;
   fp.elem_refs = (Pelem_ref *) calloc (*ipthsz, sizeof (Pelem_ref));

/**************************************************************************
  C Syntax
     void
     pincr_spa_search ( ref, dist, sp, mclip_flag, ceil,
                        norm, inv, len, st, errind, fp, tot_len )
     Ppoint         *ref;          search reference point
     Pfloat         dist;          search distance
     Pelem_ref_list *sp;           starting path list
     Pclip_ind      mclip_flag;    model clip flag
     Pint           ceil;          search ceiling index
     Pfilter_list   *norm;         normal filter list
     Pfilter_list   *inv;          inverted filter list
     Pint           len;           length of application list
     Pint           st;            starting position
     Pint           *errind;       OUT error indicator
     Pelem_ref_list *fp;           OUT found path
     Pint           *tot_len;      OUT length of list in PHIGS
**************************************************************************/

   pincr_spa_search (&ref, dist, &sp, clip, ceil, &norm, &invt,
           (Pint) *ipthsz, st, &cerror, &fp, &total_length);
   *errind = cerror;

   *fpthsz = total_length;

   for (i = 0; i < *fpthsz; i++)
   {
      fpath[i][0] = fp.elem_refs[i].struct_id;
      fpath[i][1] = fp.elem_refs[i].elem_pos;
   }

   for (i = 0; i < *nfln; i++)
   {
      if (nflesx[i] > 0)
         free (norm.filters[i].excl_set.ints);
      if (nflisx[i] > 0)
         free (norm.filters[i].incl_set.ints);
   }

   for (i = 0; i < *ifln; i++)
   {
      if (iflesx[i] > 0)
         free (invt.filters[i].excl_set.ints);
      if (iflisx[i] > 0)
         free (invt.filters[i].incl_set.ints);
   }

   if (*spthsz > 0)
      free (sp.elem_refs);
}
