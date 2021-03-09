#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE VIEW REPRESENTATION - obtain view representation  on
     workstation

  FORTRAN Syntax
     SUBROUTINE pqvwr ( WKID, VIEWI, CURQ, ERRIND, VWUPD, VWORMT,
                                              VWMPMT, VWCPLM, XYCLPI, BCLIPI, FCLIPI )
     INTEGER     WKID              workstation identifier
     INTEGER     VIEWI             view index requested
     INTEGER     CURQ              whether current or requested values are
                                   to be returned (PCURVL, PRQSVL)
     INTEGER     ERRIND            OUT error indicator
     INTEGER     VWUPD             OUT viewing transformation update state
     REAL        VWORMT(4, 4)      OUT view orientation matrix
     REAL        VWMPMT(4, 4)      OUT view mapping matrix
     REAL        VWCPLM(6)         OUT view clipping limits (NPC)
     INTEGER     XYCLPI            OUT x-y clipping indicator (PNCLIP, PCLIP)
     INTEGER     BCLIPI            OUT back clipping indicator (PNCLIP, PCLIP)
     INTEGER     FCLIPI            OUT front clipping indicator (PNCLIP, PCLIP)
**************************************************************************/
#ifdef NO_PROTO
nqvwr (wkid, pvwi, curq, errind, vwupd, vwormt, vwmpmt, vwcplm, xyclpi, bclipi, fclipi)
   integer      *wkid,
            *pvwi,
            *curq,
            *errind,
            *vwupd,
            *xyclpi,
            *bclipi,
            *fclipi;
   real     vwormt[4][4],
             vwmpmt[4][4],
             vwcplm[6];
#else
nqvwr (integer *wkid, integer *pvwi, integer *curq,
       integer *errind, integer *vwupd, real vwormt[4][4],
       real vwmpmt[4][4], real vwcplm[6],
       integer *xyclpi, integer *bclipi, integer *fclipi)
#endif
{
   Pint      cerror, i, j;
   Pupd_st   update_state;
   Pview_rep3 cur_rep;
   Pview_rep3 req_rep;
   Pview_rep3 *repptr;
/**************************************************************************
  C Syntax
     void
     pinq_view_rep ( ws, view_index, errind, update_state, cur_rep, req_rep )
     Pint        ws;               workstation identifier
     Pint        view_index;       view index
     Pint        *errind;          OUT error indicator
     Pupd_st     *update_state;    OUT transformation update state
     Pview_rep3  *cur_rep;         OUT current view representation
     Pview_rep3  *req_rep;         OUT requested view representation
**************************************************************************/

   pinq_view_rep ((Pint) *wkid, (Pint) *pvwi, &cerror, &update_state, 
                   &cur_rep, &req_rep);
   *errind = cerror;

   *vwupd = update_state;
   switch (update_state)
   {
   case PUPD_NOT_PEND:
      *vwupd = 0;
      break;
   case PUPD_PEND:
      *vwupd = 1;
      break;
   }

   switch (*curq)
   {
   case 0:			/***  PCURVL ***/
      repptr = &cur_rep;
      break;
   case 1:			/***  PRQSVL ***/
      repptr = &req_rep;
      break;
   default:
      repptr = NULL;
      return (-666);
   }

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
   {
      for (j = 0; j < 4; j++)
      {
	 vwormt[i][j] = repptr->ori_matrix[j][i];
	 vwmpmt[i][j] = repptr->map_matrix[j][i];
      }
   }

   vwcplm[0] = repptr->clip_limit.x_min;
   vwcplm[1] = repptr->clip_limit.x_max;
   vwcplm[2] = repptr->clip_limit.y_min;
   vwcplm[3] = repptr->clip_limit.y_max;
   vwcplm[4] = repptr->clip_limit.z_min;
   vwcplm[5] = repptr->clip_limit.z_max;

   *xyclpi = repptr->xy_clip;
   *bclipi = repptr->back_clip;
   *fclipi = repptr->front_clip;
}

