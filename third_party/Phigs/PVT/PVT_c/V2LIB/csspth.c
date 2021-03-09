/* csspth.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__101 = 101;
static integer c__102 = 102;
static integer c__103 = 103;
static integer c__107 = 107;
static integer c__109 = 109;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__106 = 106;
static integer c__108 = 108;

#ifndef NO_PROTO
/* Subroutine */ int csspth_(void)
#else /* NO_PROTO */
/* Subroutine */ int csspth_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), nopst ();
#endif /* NO_PROTO */

/*  Csspth sets up the "standard" CSS network for testing */
/*  ancestor and descendant paths. */
/*  Use <open structure> and <execute structure> to set up */
/*  the CSS as follows: */

/*                   101        106       108 */
/*                  / | \       / */
/*                 /  |  \    1/ */
/*               1/  2|  3\   / */
/*               /    |    \ / */
/*              /     |    107 */
/*             /      | */
/*          102      103 */
/*          | \      / \\ */
/*          |  \   1/   \\ */
/*         1|  2\  /    2\\3 */
/*          |    \/       \\ */
/*          |    104      105 */
/*          |     |      / */
/*          |    1|    1/ */
/*           \    |    / */
/*            \   |   / */
/*             \  |  / */
/*              \ | / */
/*               109 */
    nopst (&c__101);
    nexst (&c__102);
    nexst (&c__103);
    nexst (&c__107);
    nclst ();
    nopst (&c__102);
    nexst (&c__109);
    nexst (&c__104);
    nclst ();
    nopst (&c__103);
    nexst (&c__104);
    nexst (&c__105);
    nexst (&c__105);
    nclst ();
    nopst (&c__104);
    nexst (&c__109);
    nclst ();
    nopst (&c__105);
    nexst (&c__109);
    nclst ();
    nopst (&c__106);
    nexst (&c__107);
    nclst ();
    nopst (&c__108);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* csspth_ */

