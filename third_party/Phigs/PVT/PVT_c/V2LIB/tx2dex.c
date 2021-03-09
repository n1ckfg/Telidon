/* tx2dex.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b3 = 1.f;
static real c_b4 = 0.f;
#else /* NO_PROTO */
static real c_b3 = (float)1.;
static real c_b4 = (float)0.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int tx2dex_(integer *specwt, real *chupx, real *chupy, real *
	chht, integer *txpath, integer *txalh, integer *txalv, real *tposx, 
	real *tposy, char *str, integer *exix, real *exxlo, real *exylo, real 
	*exxhi, real *exyhi, ftnlen str_len)
#else /* NO_PROTO */
/* Subroutine */ int tx2dex_(specwt, chupx, chupy, chht, txpath, txalh, txalv,
	 tposx, tposy, str, exix, exxlo, exylo, exxhi, exyhi, str_len)
integer *specwt;
real *chupx, *chupy, *chht;
integer *txpath, *txalh, *txalv;
real *tposx, *tposy;
char *str;
integer *exix;
real *exxlo, *exylo, *exxhi, *exyhi;
ftnlen str_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int etp_(real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp_();
#endif /* NO_PROTO */
    static real recx[2], recy[2], xfrm[9]	/* was [3][3] */, rdum1, 
	    rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), nqtxx (integer *, integer *, real *, 
	    real *, real *, integer *, integer *, integer *, char *, integer *
	    , real *, real *, real *, real *, ftnlen);
    extern doublereal satan2_(real *, real *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), nqtxx ();
    extern doublereal satan2_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real rotang;

/*  This subroutine computes the expected lower-left and upper-right */
/*  corner of a text extent rectangle, including the effect of text */
/*  position and character-up vector, which are not taken into */
/*  account by <inquire text extent>. */
/*  <inquire text extent> with */
/*    workstation type           = primary workstation type */
/*      (ignored because font #1 is workstation-independent) */
/*    text font                  = 1 */
/*    character expansion factor = 1.0 */
/*    character spacing          = 0.0 */
/*      (three above set as assumed by spatial search, see SR15) */
/*    character height           = chht */
/*    text path                  = txpath */
/*    text alignment             = txal */
/*    character string           = str */
/*      to determine: */
/*    recxlo,recxhi,recylo,recyhi = text extent rectangle */
/*      in TLC, with assumed text position = 0,0 character up vector */
/*      = (0,1), and text precision = STROKE */
    nqtxx (specwt, &c__1, &c_b3, &c_b4, chht, txpath, txalh, txalv, str, &
	    errind, recx, recy, &rdum1, &rdum2, str_len);
    chkinq_("pqtxx", &errind, 5L);
/*  rotang = rotation angle for character up vector */
#ifndef NO_PROTO
    rotang = satan2_(chupy, chupx) - 1.5707963250000001f;
#else /* NO_PROTO */
    rotang = satan2_(chupy, chupx) - (float)1.5707963250000001;
#endif /* NO_PROTO */
/*  xfrm = 2D transform for rotation by rotang and shift by tpos */
    ebltm_(&c_b4, &c_b4, tposx, tposy, &rotang, &c_b3, &c_b3, xfrm);
/*  Get lower-left and upper-right corner: */
/*  transform recxlo,recylo, using xfrm to exxlo,exylo */
    etp_(recx, recy, xfrm, &exxlo[*exix], &exylo[*exix]);
/*  transform recxhi,recyhi, using xfrm to exxhi,exyhi */
    etp_(&recx[1], &recy[1], xfrm, &exxhi[*exix], &exyhi[*exix]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tx2dex_ */

