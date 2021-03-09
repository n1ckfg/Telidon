/* fort/04/02/05/02/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

struct {
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

/* Table of constant values */

static integer c__0 = 0;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/07                        * */
/*  *    TEST TITLE : Interior style index facilities       * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer mhi, ise, npe, mpi;
    static char msg[900];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer nahs;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     pass_(void), nqir (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqif (), pass_(), nqir ();
#endif /* NO_PROTO */
    static integer ints;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsir ();
#endif /* NO_PROTO */
    static integer styi, idum1, idum2, idum3, idum4;
    static logical goth1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer patel;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static integer rstyi;
    static logical failed;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), nqepai (
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), nqepai ();
#endif /* NO_PROTO */
    static integer errind, naints, undhat, listel, undpat, specon, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), errctl_(logical *), sigtst_(integer *, 
	    logical *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), errctl_(), sigtst_(), 
	    xpopph_();
#endif /* NO_PROTO */
    static logical styval;

    /* Fortran I/O blocks */
    static icilist io___24 = { 0, msg, 0, "(A,I5,A,I5,A)", 900, 1 };
    static icilist io___26 = { 0, msg, 0, "(A,I5,A)", 900, 1 };
    static icilist io___27 = { 0, msg, 0, "(A,A,I5,A)", 900, 1 };
    static icilist io___28 = { 0, msg, 0, "(A,I5,A)", 900, 1 };
    static icilist io___29 = { 0, msg, 0, "(A,I5,A)", 900, 1 };
    static icilist io___30 = { 0, msg, 0, "(A,A,I5,A)", 900, 1 };
    static icilist io___31 = { 0, msg, 0, "(A,A,I5,A)", 900, 1 };
    static icilist io___32 = { 0, msg, 0, "(A,I5,A,I5,A)", 900, 1 };


/* type of returned value */
/* interior style */
    initgl_("04.02.05.02/07", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* styval = true = all interior style indices accepted as valid */
    styval = TRUE_;
/* goth1 = false = haven't found hatch style #1 yet */
/*  loop thru list of available hatch styles to determine */
/*    naints = number of available interior styles */
/*    mhi = maximum defined hatch style index */
/*    nahs = number of available hatch styles */
    nqif (&specwt, &c__0, &c__0, &errind, &naints, &idum1, &nahs, &idum2, &
	    idum3);
    chkinq_("pqif", &errind, 4L);
    mhi = -9999;
    i__1 = nahs;
    for (listel = 1; listel <= i__1; ++listel) {
	nqif (&specwt, &c__0, &listel, &errind, &idum1, &idum2, &idum3, &styi,
		 &idum4);
	chkinq_("pqif", &errind, 4L);
	if (mhi < styi) {
	    mhi = styi;
	}
	if (styi == 1) {
	    goth1 = TRUE_;
	}
/* L100: */
    }
/*  undhat = undefined hatch index */
    undhat = mhi + 1;
/* go thru list of available interior styles to determine what to do. */
    i__1 = naints;
    for (ise = 1; ise <= i__1; ++ise) {
	nqif (&specwt, &ise, &c__0, &errind, &idum1, &ints, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
/* got PATTERN interior style: */
	if (ints == 2) {
/* loop thru pattern table to determine */
/*   mpi = maximum defined pattern index */
/*   npe = number of pattern entries */
	    nqepai (&globnu_1.wkid, &c__0, &errind, &npe, &idum1);
	    chkinq_("pqepai", &errind, 6L);
	    mpi = 1;
	    i__2 = npe;
	    for (listel = 1; listel <= i__2; ++listel) {
		nqepai (&globnu_1.wkid, &listel, &errind, &idum1, &patel);
		chkinq_("pqepai", &errind, 6L);
		if (mpi < patel) {
		    mpi = patel;
		}
/* L200: */
	    }
	    undpat = mpi + 1;
/*  <set interior representation>, index #3, PATTERN, pattern inde
x=mpi */
	    nsir (&globnu_1.wkid, &c__3, &c__2, &mpi, &c__1);
#ifndef NO_PROTO
	    setmsg_("16 40", "For PATTERN interior style, <inquire interior "
		    "representation> should report a defined interior style i"
		    "ndex realized as itself.", 5L, 126L);
#else /* NO_PROTO */
	    setmsg_("16 40", "For PATTERN interior style, <inquire interior \
representation> should report a defined interior style index realized as its\
elf.", 5L, 126L);
#endif /* NO_PROTO */
/*  <inquire interior representation>, index #3 to determine */
/*  rstyi = realized interior style index */
	    nqir (&globnu_1.wkid, &c__3, &c__1, &errind, &idum1, &rstyi, &
		    idum2);
	    chkinq_("pqir", &errind, 4L);
	    if (rstyi == mpi) {
		pass_();
	    } else {
		fail_();
		s_wsfi(&io___24);
		do_fio(&c__1, "Pattern index set as ", 21L);
		do_fio(&c__1, (char *)&mpi, (ftnlen)sizeof(integer));
		do_fio(&c__1, "but realized as ", 16L);
		do_fio(&c__1, (char *)&rstyi, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 900L);
	    }
#ifndef NO_PROTO
	    errctl_((logical*)&c__1);
	    setmsg_("38", "Any positive pattern index should be accepted as "
		    "valid.", 2L, 55L);
#else /* NO_PROTO */
	    errctl_(&c__1);
	    setmsg_("38", "Any positive pattern index should be accepted as \
valid.", 2L, 55L);
#endif /* NO_PROTO */
	    nsir (&globnu_1.wkid, &c__3, &c__2, &undpat, &c__1);
#ifndef NO_PROTO
	    errctl_((logical*)&c__0);
#else /* NO_PROTO */
	    errctl_(&c__0);
#endif /* NO_PROTO */
	    sigtst_(&c__0, &failed);
	    if (failed) {
		s_wsfi(&io___26);
		do_fio(&c__1, "Pattern index set as ", 21L);
		do_fio(&c__1, (char *)&undpat, (ftnlen)sizeof(integer));
		do_fio(&c__1, " signalled error.", 17L);
		e_wsfi();
		inmsg_(msg, 900L);
	    }
#ifndef NO_PROTO
	    setmsg_("16 41", "For PATTERN interior style, <inquire interior "
		    "representation> should report an undefined interior styl"
		    "e index realized as 1.", 5L, 124L);
#else /* NO_PROTO */
	    setmsg_("16 41", "For PATTERN interior style, <inquire interior \
representation> should report an undefined interior style index realized as \
1.", 5L, 124L);
#endif /* NO_PROTO */
/*  <inquire interior representation>, index #3 to determine */
/*  rstyi = realized interior style index */
	    nqir (&globnu_1.wkid, &c__3, &c__1, &errind, &idum1, &rstyi, &
		    idum2);
	    chkinq_("pqir", &errind, 4L);
	    if (rstyi == 1) {
		pass_();
	    } else {
		fail_();
		s_wsfi(&io___27);
		do_fio(&c__1, "Undefined pattern index ", 24L);
		do_fio(&c__1, "realized as ", 12L);
		do_fio(&c__1, (char *)&rstyi, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 900L);
	    }
/* end PATTERN */
	} else {
/* handle all non-PATTERN styles */
/*   <set interior representation> index #4, interior style = ints
, */
/*    interior style index = undhat */
#ifndef NO_PROTO
	    errctl_((logical*)&c__1);
#else /* NO_PROTO */
	    errctl_(&c__1);
#endif /* NO_PROTO */
	    nsir (&globnu_1.wkid, &c__4, &ints, &undhat, &c__1);
#ifndef NO_PROTO
	    errctl_((logical*)&c__0);
#else /* NO_PROTO */
	    errctl_(&c__0);
#endif /* NO_PROTO */
	    if (globnu_1.errsig != 0) {
		styval = FALSE_;
		s_wsfi(&io___28);
		do_fio(&c__1, "Interior style index set as ", 28L);
		do_fio(&c__1, (char *)&undhat, (ftnlen)sizeof(integer));
		do_fio(&c__1, " signalled error.", 17L);
		e_wsfi();
		inmsg_(msg, 900L);
	    } else {
#ifndef NO_PROTO
		errctl_((logical*)&c__1);
#else /* NO_PROTO */
		errctl_(&c__1);
#endif /* NO_PROTO */
		i__2 = -undhat;
		nsir (&globnu_1.wkid, &c__5, &ints, &i__2, &c__1);
#ifndef NO_PROTO
		errctl_((logical*)&c__0);
#else /* NO_PROTO */
		errctl_(&c__0);
#endif /* NO_PROTO */
		if (globnu_1.errsig != 0) {
		    styval = FALSE_;
		    s_wsfi(&io___29);
		    do_fio(&c__1, "Interior style index set as ", 28L);
		    i__2 = -undhat;
		    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
		    do_fio(&c__1, " signalled error.", 17L);
		    e_wsfi();
		    inmsg_(msg, 900L);
		}
	    }
/* got HATCH interior style */
	    if (ints == 3) {
/* <inquire interior representation> realized to determine */
/*   rstyi = realized interior style index */
		nqir (&globnu_1.wkid, &c__4, &c__1, &errind, &idum1, &rstyi, &
			idum2);
		chkinq_("pqir", &errind, 4L);
		if (goth1) {
/*  require coercion to #1 */
#ifndef NO_PROTO
		    setmsg_("16 41", "For HATCH interior style, <inquire int"
			    "erior representation> should report an undefined"
			    " interior style index realized as #1, when hatch"
			    " style #1 is supported on the workstation.", 5L, 
			    176L);
#else /* NO_PROTO */
		    setmsg_("16 41", "For HATCH interior style, <inquire int\
erior representation> should report an undefined interior style index realiz\
ed as #1, when hatch style #1 is supported on the workstation.", 5L, 176L);
#endif /* NO_PROTO */
		    if (rstyi == 1) {
			pass_();
		    } else {
			fail_();
			s_wsfi(&io___30);
			do_fio(&c__1, "Undefined hatch index ", 22L);
			do_fio(&c__1, "realized as ", 12L);
			do_fio(&c__1, (char *)&rstyi, (ftnlen)sizeof(integer))
				;
			do_fio(&c__1, ".", 1L);
			e_wsfi();
			inmsg_(msg, 900L);
		    }
		} else {
/*  require coercion to something else */
#ifndef NO_PROTO
		    setmsg_("16 41", "For HATCH interior style, <inquire int"
			    "erior representation> should report an undefined"
			    " interior style index realized as something othe"
			    "r than itself or #1, when hatch style #1 is not "
			    "supported on the workstation.", 5L, 211L);
#else /* NO_PROTO */
		    setmsg_("16 41", "For HATCH interior style, <inquire int\
erior representation> should report an undefined interior style index realiz\
ed as something other than itself or #1, when hatch style #1 is not supporte\
d on the workstation.", 5L, 211L);
#endif /* NO_PROTO */
		    if (rstyi == 1 || rstyi == undhat) {
			fail_();
			s_wsfi(&io___31);
			do_fio(&c__1, "Undefined hatch index ", 22L);
			do_fio(&c__1, "realized as ", 12L);
			do_fio(&c__1, (char *)&rstyi, (ftnlen)sizeof(integer))
				;
			do_fio(&c__1, ".", 1L);
			e_wsfi();
			inmsg_(msg, 900L);
		    } else {
			pass_();
		    }
		}
		nsir (&globnu_1.wkid, &c__4, &c__3, &mhi, &c__1);
#ifndef NO_PROTO
		setmsg_("16 40", "For HATCH interior style, <inquire interio"
			"r representation> should report a defined interior s"
			"tyle index realized as itself.", 5L, 124L);
#else /* NO_PROTO */
		setmsg_("16 40", "For HATCH interior style, <inquire interio\
r representation> should report a defined interior style index realized as i\
tself.", 5L, 124L);
#endif /* NO_PROTO */
/*  <inquire interior representation>, index #4 to determine 
*/
/*  rstyi = realized interior style index */
		nqir (&globnu_1.wkid, &c__4, &c__1, &errind, &idum1, &rstyi, &
			idum2);
		chkinq_("pqir", &errind, 4L);
		if (rstyi == mhi) {
		    pass_();
		} else {
		    fail_();
		    s_wsfi(&io___32);
		    do_fio(&c__1, "Hatch index set as ", 19L);
		    do_fio(&c__1, (char *)&mhi, (ftnlen)sizeof(integer));
		    do_fio(&c__1, "but realized as ", 16L);
		    do_fio(&c__1, (char *)&rstyi, (ftnlen)sizeof(integer));
		    do_fio(&c__1, ".", 1L);
		    e_wsfi();
		    inmsg_(msg, 900L);
		}
	    }
	}
/* L600: */
    }
#ifndef NO_PROTO
    setmsg_("37", "Any value for interior style index (except for pattern in"
	    "dices) should be accepted as valid.", 2L, 92L);
#else /* NO_PROTO */
    setmsg_("37", "Any value for interior style index (except for pattern in\
dices) should be accepted as valid.", 2L, 92L);
#endif /* NO_PROTO */
    ifpf_(&styval);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

