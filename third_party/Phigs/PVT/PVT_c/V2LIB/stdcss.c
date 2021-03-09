/* stdcss.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__100 = 100;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__902 = 902;
static integer c__103 = 103;
static integer c__960 = 960;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__900 = 900;
static integer c__901 = 901;
static integer c__106 = 106;
static integer c__120 = 120;
static integer c__907 = 907;
static integer c__130 = 130;
static integer c__910 = 910;
static integer c__912 = 912;
static integer c__914 = 914;
static integer c__107 = 107;
static integer c__140 = 140;
static integer c__142 = 142;
static integer c__920 = 920;
static integer c__109 = 109;
static integer c__925 = 925;
static integer c__926 = 926;
static integer c__110 = 110;
static integer c__108 = 108;
static integer c__114 = 114;
static integer c__950 = 950;
static integer c__930 = 930;
static integer c__935 = 935;
static integer c__113 = 113;
static integer c__961 = 961;
static integer c__111 = 111;
static integer c__940 = 940;
static integer c__115 = 115;
static integer c__942 = 942;
static integer c__916 = 916;
static integer c__947 = 947;
static integer c__955 = 955;

#ifndef NO_PROTO
/* Subroutine */ int stdcss_(void)
#else /* NO_PROTO */
/* Subroutine */ int stdcss_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), ndas (void), nqedm (integer *
	    , integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ndas (), nqedm ();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), unmsg_(char *, ftnlen), nexst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), unmsg_(), nexst ();
#endif /* NO_PROTO */
    static integer stype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer edmode;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */

/*  Stdcss sets up a "standard" CSS network for several of the PVT */
/*  tests.  <Open structure> and <execute structure> set up the CSS */
/*  network as follows: */
/*                  100 */
/*                 /  \ */
/*                /    \ */
/*              1/      \2 */
/*              /        \ */
/*             /          \ */
/*         101              102     120   130             140 */
/*          |              / | \     |    /|               | */
/*          |2            /  |  \    |   / |              1| */
/*          |           1/  2|  5\  2|  /3 |5              | */
/*          |           /    |    \  | /   |               | */
/*         103         /     |     \ |/    |              142 */
/*                  104     105     106   107 */
/*                  | |       |     |    / /\ */
/*                 2| |5     /|\    |   / /  \ */
/*                  | |    1/ | \2 1| 1/ /4   \5 */
/*                  109    /  |  \  | / /      \ */
/*                        /   |   \ |/ /       113 */
/*                      110   |    108 */
/*                            |     | */
/*                            |3    |2 */
/*                            |     | */
/*                            |     | */
/*                            |    111 */
/*                            |   / | */
/*                            |  /  | */
/*                            |1/  3| */
/*                            |/    | */
/*                           114   115 */
/*  The nodes of the graph between (100 and 200) represent structures, */
/*  and the labelled edges are references to invoke (lower) */
/*  structures.  The labels (1-5) represent the element position of */
/*  the <execute structure> function within the calling structure. */
/*  <Execute structure> and <label> are the structure elements of the */
/*  individual structures contained in the network.  The values */
/*  between 100 and 199, inclusive, represent structures associated */
/*  with <execute structure> and the values between 900 and 999 */
/*  represent label identifiers for <label>. */
/* open-structure status    none,        open */
/* edit mode */
    nqedm (&errind, &edmode);
    if (errind == 0 && edmode == 0) {
/*        lovely */
    } else {
	unmsg_("STDCSS invoked with edit-mode not = INSERT", 42L);
    }
/* close any structure left opened */
    nqopst (&errind, &stype, &strid);
    chkinq_("pqopst", &errind, 6L);
    if (stype == 1) {
	nclst ();
    }
/* delete old CSS */
    ndas ();
    nopst (&c__100);
    nexst (&c__101);
    nexst (&c__102);
    nclst ();
    nopst (&c__101);
    nlb (&c__902);
    nexst (&c__103);
    nlb (&c__960);
    nclst ();
    nopst (&c__102);
    nexst (&c__104);
    nexst (&c__105);
    nlb (&c__900);
    nlb (&c__901);
    nexst (&c__106);
    nclst ();
    nopst (&c__120);
    nlb (&c__907);
    nexst (&c__106);
    nclst ();
    nopst (&c__130);
    nlb (&c__910);
    nlb (&c__912);
    nexst (&c__106);
    nlb (&c__914);
    nexst (&c__107);
    nclst ();
    nopst (&c__140);
    nexst (&c__142);
    nclst ();
    nopst (&c__104);
    nlb (&c__920);
    nexst (&c__109);
    nlb (&c__925);
    nlb (&c__926);
    nexst (&c__109);
    nclst ();
    nopst (&c__105);
    nexst (&c__110);
    nexst (&c__108);
    nexst (&c__114);
    nlb (&c__950);
    nclst ();
    nopst (&c__106);
    nexst (&c__108);
    nclst ();
    nopst (&c__107);
    nexst (&c__108);
    nlb (&c__930);
    nlb (&c__935);
    nexst (&c__108);
    nexst (&c__113);
    nclst ();
    nopst (&c__108);
    nlb (&c__961);
    nexst (&c__111);
    nclst ();
    nopst (&c__111);
    nexst (&c__114);
    nlb (&c__940);
    nexst (&c__115);
    nlb (&c__942);
    nlb (&c__916);
    nlb (&c__947);
    nlb (&c__955);
    nlb (&c__947);
    nlb (&c__955);
    nlb (&c__940);
    nlb (&c__947);
    nclst ();
    nopst (&c__113);
    nlb (&c__901);
    nclst ();
    nopst (&c__114);
    nlb (&c__901);
    nclst ();
    nopst (&c__115);
    nlb (&c__901);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* stdcss_ */

