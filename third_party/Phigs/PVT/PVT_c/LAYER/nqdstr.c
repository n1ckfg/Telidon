#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE DYNAMICS OF STRUCTURES - obtain dynamics  of  struc-
     tures for workstation type

  FORTRAN Syntax
     SUBROUTINE pqdstr ( WTYPE, ERRIND, STRCON, POST, UNPOST, DELETE, REFMOD )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     STRCON            OUT structure content
     INTEGER     POST              OUT posting a structure
     INTEGER     UNPOST            OUT unposting a structure
     INTEGER     DELETE            OUT deleting a structure
     INTEGER     REFMOD            OUT reference modification
**************************************************************************/
#ifdef NO_PROTO
nqdstr (wtype, errind, strcon, post, unpost, delete, refmod)
   integer      *wtype,
            *errind,
            *strcon,
            *post,
            *unpost,
            *delete,
            *refmod;
#else
nqdstr (integer *wtype, integer *errind, integer *strcon, integer *post, integer *unpost,
        integer *delete, integer *refmod)
#endif
{
   Pdyns_structs dynamics;
   Pint cerror;
/**************************************************************************
  C Syntax
     void
     pinq_dyns_structs ( type, errind, dynamics )
     Pint            type;         workstation type
     Pint           *errind;       OUT error indicator
     Pdyns_structs  *dynamics      OUT structure dynamics
**************************************************************************/

   pinq_dyns_structs ((Pint) *wtype, &cerror, &dynamics);
   *errind = cerror;

   *strcon = dynamics.content;
   switch (dynamics.content)
   {
   case PDYN_IRG:
      *strcon = 0;
      break;
   case PDYN_IMM:
      *strcon = 1;
      break;
   case PDYN_CBS:
      *strcon = 2;
      break;
   }

   *post = dynamics.post;
   switch (dynamics.post)
   {
   case PDYN_IRG:
      *post = 0;
      break;
   case PDYN_IMM:
      *post = 1;
      break;
   case PDYN_CBS:
      *post = 2;
      break;
   }

   *unpost = dynamics.unpost;
   switch (dynamics.unpost)
   {
   case PDYN_IRG:
      *unpost = 0;
      break;
   case PDYN_IMM:
      *unpost = 1;
      break;
   case PDYN_CBS:
      *unpost = 2;
      break;
   }

   *delete = dynamics.del;
   switch (dynamics.del)
   {
   case PDYN_IRG:
      *delete = 0;
      break;
   case PDYN_IMM:
      *delete = 1;
      break;
   case PDYN_CBS:
      *delete = 2;
      break;
   }

   *refmod = dynamics.ref;
   switch (dynamics.ref)
   {
   case PDYN_IRG:
      *refmod = 0;
      break;
   case PDYN_IMM:
      *refmod = 1;
      break;
   case PDYN_CBS:
      *refmod = 2;
      break;
   }
}
