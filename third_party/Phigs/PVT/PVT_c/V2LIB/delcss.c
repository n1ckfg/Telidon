/* delcss.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__100 = 100;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__103 = 103;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__106 = 106;
static integer c__120 = 120;
static integer c__130 = 130;
static integer c__107 = 107;
static integer c__140 = 140;
static integer c__142 = 142;
static integer c__109 = 109;
static integer c__110 = 110;
static integer c__114 = 114;
static integer c__108 = 108;
static integer c__113 = 113;
static integer c__111 = 111;
static integer c__115 = 115;

#ifndef NO_PROTO
/* Subroutine */ int delcss_(void)
#else /* NO_PROTO */
/* Subroutine */ int delcss_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), nopst ();
#endif /* NO_PROTO */

/*  Delcss sets up the "standard" CSS network for module 02.01.02.02: */
/*  Use <open structure> and <execute structure> to set up */
/*  the CSS as follows: */


/*                  100 */
/*                 /  \ */
/*                /    \ */
/*              1/      \2 */
/*              /        \ */
/*             /          \ */
/*         101              102     120   130             140 */
/*         | |             / | \     |    /|               | */
/*        1| |2           /  |  \    |   / |              1| */
/*         | |          1/  2|  3\  1|  /1 |2              | */
/*         | |          /    |    \  | /   |               | */
/*         103         /     |     \ |/    |              142 */
/*                  104     105     106   107 */
/*                  | |       |     |    / /\ */
/*                 1| |2     /|\    |   / /  \ */
/*                  | |    1/ | \3 1| 1/ /2   \3 */
/*                  109    /  |  \  | / /      \ */
/*                        /   |   \ |/ /       113 */
/*                      110   |    108 */
/*                            |     | */
/*                            |2    |1 */
/*                            |     | */
/*                            |     | */
/*                            |    111 */
/*                            |   / | */
/*                            | 1/  | */
/*                            | /  2| */
/*                            |/    | */
/*                           114   115 */
/* The nodes of the graph (100 and above) represent structures, and the */

/* labelled edges are references to invoke (lower) structures.  The */
/* labels (1-3) represent the element position of the <execute structure> 
*/
/* function within the calling structure. */
/* creation of structures */
    nopst (&c__100);
    nexst (&c__101);
    nexst (&c__102);
    nclst ();
    nopst (&c__101);
    nexst (&c__103);
    nexst (&c__103);
    nclst ();
    nopst (&c__102);
    nexst (&c__104);
    nexst (&c__105);
    nexst (&c__106);
    nclst ();
    nopst (&c__120);
    nexst (&c__106);
    nclst ();
    nopst (&c__130);
    nexst (&c__106);
    nexst (&c__107);
    nclst ();
    nopst (&c__140);
    nexst (&c__142);
    nclst ();
    nopst (&c__104);
    nexst (&c__109);
    nexst (&c__109);
    nclst ();
    nopst (&c__105);
    nexst (&c__110);
    nexst (&c__114);
    nexst (&c__108);
    nclst ();
    nopst (&c__106);
    nexst (&c__108);
    nclst ();
    nopst (&c__107);
    nexst (&c__108);
    nexst (&c__108);
    nexst (&c__113);
    nclst ();
    nopst (&c__108);
    nexst (&c__111);
    nclst ();
    nopst (&c__111);
    nexst (&c__114);
    nexst (&c__115);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* delcss_ */

