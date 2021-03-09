/* fort/05/02/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__8 = 8;
static integer c__2 = 2;
static integer c__7 = 7;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.02/07                              * */
/*  *    TEST TITLE : Deferral mode BNIG                    * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static char modtab[4*3] = "NIVE" "UWOR" "UQUM";
    static char sevtab[3*3] = "IRG" "IMM" "CBS";
    static char oldtab[10*3] = "CORRECT   " "DEFERRED  " "SIMULATED ";
    static char svrcod[1*3] = "c" "d" "s";
#else /* NO_PROTO */
    static char modtab[4*3+1] = "NIVEUWORUQUM";
    static char sevtab[3*3+1] = "IRGIMMCBS";
    static char oldtab[10*3+1] = "CORRECT   DEFERRED  SIMULATED ";
    static char svrcod[1*3+1] = "cds";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[3], a__2[5], a__3[6], a__4[8], a__5[7];
    integer i__1, i__2[3], i__3[5], i__4[6], i__5[8], i__6[7];
    logical L__1;
    char ch__1[122], ch__2[177], ch__3[189], ch__4[279], ch__5[284], ch__6[
	    290], ch__7[303];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static integer ct, pcc, ind, iwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nqli (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nqli ();
#endif /* NO_PROTO */
    static integer inwk, onwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int nrst (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nrst ();
#endif /* NO_PROTO */
    static char cdum1[1];
    static integer idum1, idum2, idum3, modmd;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer indev[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nclwk (integer *), unmsg_(char *, ftnlen), nsdus (
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *);
    extern logical svrok_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
    extern integer itrim_();
    extern /* Subroutine */ int nqwkc (), nclwk (), unmsg_(), nsdus (), 
	    nopwk ();
    extern logical svrok_();
#endif /* NO_PROTO */
    static char pcctab[34*17];
    static integer actpcc;
    static char cndlbl[200], pcclbl[34], pcchar[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int picchg_(integer *, char *, char *, integer *, 
	    integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int picchg_();
#endif /* NO_PROTO */
    static integer iconid, inclas;
    static char modlbl[4];
    static integer inmode;
    static char oldlbl[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), doimod_(
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), doimod_();
#endif /* NO_PROTO */
    static integer errind, specon, instat, actsev, specwt;
    static char sevlbl[3];
    static integer oldsvr;
    static char sevchr[2], explbl[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */
    static integer iwtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int setpcl_(char *, ftnlen), picenv_(integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), setsvr_(integer *, 
	    integer *), exsvrs_(integer *, integer *, integer *, integer *, 
	    char *, char *, ftnlen, ftnlen), multws_(integer *, char *, 
	    integer *, integer *, integer *, integer *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setpcl_(), picenv_(), setmsg_(), setsvr_(), 
	    exsvrs_(), multws_();
#endif /* NO_PROTO */
    static integer sevrty;
    static char svrlst[3];

    /* Fortran I/O blocks */
    static icilist io___25 = { 0, pcchar, 0, "(I2)", 2, 1 };
    static icilist io___35 = { 0, sevchr, 0, "(I2)", 2, 1 };


/* deferral mode */
/* modification mode */
/* dynamic modification */
/* state of visual representation */
/*                correct    deferred    simulated */
/* clear control flag */
/*                conditionally  always */
/* operating mode */
/*                request  sample    event */
/* echo switch */
/*  Declare program-specific variables */
    initgl_("05.02/07", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* wkid is the identifier for the workstation under test; */
/* inwk identifies some input-type workstation. */
    multws_(&c__0, "id", &onwk, &idum1, &idum2, &idum3, cdum1, 2L, 1L);
    if (onwk == 0) {
	inmsg_("No input workstation available; unable to test BNIG.", 52L);
	goto L667;
    }
    i__1 = onwk;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	multws_(&iwk, "id", &idum1, &inwk, &iconid, &iwtype, cdum1, 2L, 1L);
	if (inwk != globnu_1.wkid) {
	    goto L30;
	}
/* L20: */
    }
#ifndef NO_PROTO
    inmsg_("No other input workstation available; using local input to test "
	    "BNIG.", 69L);
#else /* NO_PROTO */
    inmsg_("No other input workstation available; using local input to test \
BNIG.", 69L);
#endif /* NO_PROTO */
L30:
/* open output workstation (primary) */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* open input workstation (secondary), if distinct from output */
    if (inwk != globnu_1.wkid) {
	nopwk (&inwk, &iconid, &iwtype);
    }
/*  picture change categories are numbered from 1 to 17: */
/*    workstation changes :  1 to 12 */
/*    structure changes   : 13 to 17 */
/*  set pcctab to names of picture change categories */
    setpcl_(pcctab, 34L);
/*  invoke PICENV to set up standard picture environment */
    picenv_(&globnu_1.wkid);
/*  <set display update state> BNIG, NIVE */
    nsdus (&globnu_1.wkid, &c__1, &c__0);
    nqwkc (&inwk, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire number of available logical input devices> for input */
/*     workstation */
/*  inclas = input class for which a device is available */
    nqli (&specwt, &errind, indev, &indev[1], &indev[2], &indev[3], &indev[4],
	     &indev[5]);
    chkinq_("pqli", &errind, 4L);
    for (ind = 1; ind <= 6; ++ind) {
	if (indev[ind - 1] > 0) {
	    inclas = ind;
	    goto L110;
	}
/* L100: */
    }
#ifndef NO_PROTO
    unmsg_("No input devices available for workstation reported as OUTIN or "
	    "INPUT.", 70L);
#else /* NO_PROTO */
    unmsg_("No input devices available for workstation reported as OUTIN or \
INPUT.", 70L);
#endif /* NO_PROTO */
L110:
    ct = 0;
/*  for pcc = 1 to 17 = picture change category */
    for (pcc = 1; pcc <= 17; ++pcc) {
	s_copy(pcclbl, pcctab + (pcc - 1) * 34, 34L, 34L);
	s_wsfi(&io___25);
	do_fio(&c__1, (char *)&pcc, (ftnlen)sizeof(integer));
	e_wsfi();
/*        for instat = underway, inactive */
	for (instat = 0; instat <= 1; ++instat) {
/*           <redraw all structures> to make svr = CORRECT */
	    nrst (&globnu_1.wkid, &c__0);
	    if (instat == 0) {
/*              activate input: */
		++ct;
		if (ct % 2 == 0) {
		    inmode = 1;
		} else {
		    inmode = 2;
		}
/*              vary order of operation: */
		if (ct % 3 == 0) {
/*                 invoke PICCHG for category = pcc */
		    picchg_(&globnu_1.wkid, "0,1,2", pcchar, &actsev, &actpcc,
			     5L, 2L);
/*                 use DOIMOD to set mode of input device 
to inmode */
		    doimod_(&inwk, &inclas, &inmode);
		} else {
		    doimod_(&inwk, &inclas, &inmode);
		    picchg_(&globnu_1.wkid, "0,1,2", pcchar, &actsev, &actpcc,
			     5L, 2L);
		}
		if (actpcc != pcc) {
/* Writing concatenation */
#ifndef NO_PROTO
		    i__2[0] = 87, a__1[0] = "Cannot do picture change, [BNIG"
			    ", NIVE] test with input underway skipped for cat"
			    "egory = ";
#else /* NO_PROTO */
		    i__2[0] = 87, a__1[0] = "Cannot do picture change, [BNIG\
, NIVE] test with input underway skipped for category = ";
#endif /* NO_PROTO */
		    i__2[1] = itrim_(pcclbl, 34L), a__1[1] = pcclbl;
		    i__2[2] = 1, a__1[2] = ".";
		    s_cat(ch__1, a__1, i__2, &c__3, 122L);
		    inmsg_(ch__1, itrim_(pcclbl, 34L) + 88);
		    goto L180;
		}
/* Writing concatenation */
		i__3[0] = 29, a__2[0] = "A picture change of category ";
		i__3[1] = itrim_(pcclbl, 34L), a__2[1] = pcclbl;
		i__3[2] = 35, a__2[2] = " performed under mode [BNIG, NIVE] ";

#ifndef NO_PROTO
		i__3[3] = 40, a__2[3] = "when input is underway should leave"
			" the ";
		i__3[4] = 39, a__2[4] = "state of visual representation CORR"
			"ECT.";
#else /* NO_PROTO */
		i__3[3] = 40, a__2[3] = "when input is underway should leave\
 the ";
		i__3[4] = 39, a__2[4] = "state of visual representation CORR\
ECT.";
#endif /* NO_PROTO */
		s_cat(ch__2, a__2, i__3, &c__5, 177L);
		setmsg_("3 4 13 30 32", ch__2, 12L, itrim_(pcclbl, 34L) + 143)
			;
		L__1 = svrok_(&globnu_1.wkid, "c", 1L);
		ifpf_(&L__1);
/*  skip_pcc_act: */
L180:
/*              deactivate global input: */
		doimod_(&inwk, &inclas, &c__0);
	    } else {
/* input is inactive */
/*              invoke PICCHG for category = pcc */
		picchg_(&globnu_1.wkid, "0,1,2", pcchar, &actsev, &actpcc, 5L,
			 2L);
		if (actpcc != pcc) {
/* Writing concatenation */
#ifndef NO_PROTO
		    i__2[0] = 87, a__1[0] = "Cannot do picture change, [BNIG"
			    ", NIVE] test with input inactive skipped for cat"
			    "egory = ";
#else /* NO_PROTO */
		    i__2[0] = 87, a__1[0] = "Cannot do picture change, [BNIG\
, NIVE] test with input inactive skipped for category = ";
#endif /* NO_PROTO */
		    i__2[1] = itrim_(pcclbl, 34L), a__1[1] = pcclbl;
		    i__2[2] = 1, a__1[2] = ".";
		    s_cat(ch__1, a__1, i__2, &c__3, 122L);
		    inmsg_(ch__1, itrim_(pcclbl, 34L) + 88);
		    goto L185;
		}
/* Writing concatenation */
		i__4[0] = 29, a__3[0] = "A picture change of category ";
		i__4[1] = itrim_(pcclbl, 34L), a__3[1] = pcclbl;
		i__4[2] = 35, a__3[2] = " performed under mode [BNIG, NIVE] ";

		i__4[3] = 36, a__3[3] = "when input is inactive should leave "
			;
		i__4[4] = 35, a__3[4] = "the state of visual representation ";

		i__4[5] = 20, a__3[5] = "DEFERRED or CORRECT.";
		s_cat(ch__3, a__3, i__4, &c__6, 189L);
		setmsg_("3 4 13 15 32", ch__3, 12L, itrim_(pcclbl, 34L) + 155)
			;
		L__1 = svrok_(&globnu_1.wkid, "dc", 2L);
		ifpf_(&L__1);
/*  skip_pcc_inact: */
L185:
		;
	    }
/*  next instat */
/* L200: */
	}
/*  next pcc */
/* L210: */
    }
    ct = 0;
    for (modmd = 1; modmd <= 2; ++modmd) {
	s_copy(modlbl, modtab + (modmd << 2), 4L, 4L);
	for (sevrty = 0; sevrty <= 2; ++sevrty) {
	    s_copy(sevlbl, sevtab + sevrty * 3, 3L, 3L);
	    s_wsfi(&io___35);
	    do_fio(&c__1, (char *)&sevrty, (ftnlen)sizeof(integer));
	    e_wsfi();
	    for (oldsvr = 0; oldsvr <= 2; ++oldsvr) {
		s_copy(oldlbl, oldtab + oldsvr * 10, 10L, 10L);
/* Writing concatenation */
		i__5[0] = 21, a__4[0] = "update mode = [BNIG, ";
		i__5[1] = 4, a__4[1] = modlbl;
		i__5[2] = 3, a__4[2] = "], ";
		i__5[3] = 26, a__4[3] = "picture change severity = ";
		i__5[4] = 3, a__4[4] = sevlbl;
		i__5[5] = 2, a__4[5] = ", ";
#ifndef NO_PROTO
		i__5[6] = 37, a__4[6] = "old state of visual representation "
			"= ";
#else /* NO_PROTO */
		i__5[6] = 37, a__4[6] = "old state of visual representation \
= ";
#endif /* NO_PROTO */
		i__5[7] = 10, a__4[7] = oldlbl;
		s_cat(cndlbl, a__4, i__5, &c__8, 200L);
		for (instat = 0; instat <= 1; ++instat) {
/*        attempt to set SVR to oldsvr */
		    setsvr_(&globnu_1.wkid, &oldsvr);
/*        <set display update state> BNIG, modmd */
		    nsdus (&globnu_1.wkid, &c__1, &modmd);
/*        if (current_SVR not= oldsvr) goto skip_oldsvr */

		    if (! svrok_(&globnu_1.wkid, svrcod + oldsvr, 1L)) {
/* Writing concatenation */
#ifndef NO_PROTO
			i__3[0] = 48, a__2[0] = "Cannot set old state of vis"
				"ual representation = ";
#else /* NO_PROTO */
			i__3[0] = 48, a__2[0] = "Cannot set old state of vis\
ual representation = ";
#endif /* NO_PROTO */
			i__3[1] = itrim_(oldlbl, 10L), a__2[1] = oldlbl;
			i__3[2] = 20, a__2[2] = "; skipping test for ";
			i__3[3] = itrim_(cndlbl, 200L), a__2[3] = cndlbl;
			i__3[4] = 1, a__2[4] = ".";
			s_cat(ch__4, a__2, i__3, &c__5, 279L);
			inmsg_(ch__4, itrim_(oldlbl, 10L) + 68 + itrim_(
				cndlbl, 200L) + 1);
			goto L355;
		    }
		    if (instat == 0) {
			++ct;
			if (ct % 2 == 0) {
			    inmode = 1;
			} else {
			    inmode = 2;
			}
/*           vary order of operation: */
			if (ct % 3 == 0) {
/*              attempt to perform sevrty-type ope
ration: */
#ifndef NO_PROTO
			    picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8"
				    ",9,10,11,12,13,14,15,16,17", &actsev, &
				    actpcc, 2L, 41L);
#else /* NO_PROTO */
			    picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8\
,9,10,11,12,13,14,15,16,17", &actsev, &actpcc, 2L, 41L);
#endif /* NO_PROTO */
			    doimod_(&inwk, &inclas, &inmode);
			} else {
			    doimod_(&inwk, &inclas, &inmode);
/*              attempt to perform sevrty-type ope
ration: */
#ifndef NO_PROTO
			    picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8"
				    ",9,10,11,12,13,14,15,16,17", &actsev, &
				    actpcc, 2L, 41L);
#else /* NO_PROTO */
			    picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8\
,9,10,11,12,13,14,15,16,17", &actsev, &actpcc, 2L, 41L);
#endif /* NO_PROTO */
			}
			if (actsev != sevrty) {
/* Writing concatenation */
#ifndef NO_PROTO
			    i__3[0] = 40, a__2[0] = "Cannot do picture chang"
				    "e for severity = ";
#else /* NO_PROTO */
			    i__3[0] = 40, a__2[0] = "Cannot do picture chang\
e for severity = ";
#endif /* NO_PROTO */
			    i__3[1] = 3, a__2[1] = sevlbl;
			    i__3[2] = 20, a__2[2] = "; skipping test for ";
			    i__3[3] = itrim_(cndlbl, 200L), a__2[3] = cndlbl;
			    i__3[4] = 21, a__2[4] = ", and input underway.";
			    s_cat(ch__5, a__2, i__3, &c__5, 284L);
			    inmsg_(ch__5, itrim_(cndlbl, 200L) + 84);
			    goto L315;
			}
/* Writing concatenation */
			i__3[0] = 3, a__2[0] = "If ";
			i__3[1] = itrim_(cndlbl, 200L), a__2[1] = cndlbl;
			i__3[2] = 15, a__2[2] = ", and input is ";
#ifndef NO_PROTO
			i__3[3] = 39, a__2[3] = "underway, then current stat"
				"e of visual ";
			i__3[4] = 33, a__2[4] = "representation should be CO"
				"RRECT.";
#else /* NO_PROTO */
			i__3[3] = 39, a__2[3] = "underway, then current stat\
e of visual ";
			i__3[4] = 33, a__2[4] = "representation should be CO\
RRECT.";
#endif /* NO_PROTO */
			s_cat(ch__6, a__2, i__3, &c__5, 290L);
			setmsg_("3 4 13 30 32", ch__6, 12L, itrim_(cndlbl, 
				200L) + 90);
			L__1 = svrok_(&globnu_1.wkid, "c", 1L);
			ifpf_(&L__1);
/*  skip_sev: */
L315:
/*           deactivate global input: */
			doimod_(&inwk, &inclas, &c__0);
		    } else {
/* input is inactive */
/*           attempt to perform sevrty-type operation:
 */
#ifndef NO_PROTO
			picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8,9,1"
				"0,11,12,13,14,15,16,17", &actsev, &actpcc, 2L,
				 41L);
#else /* NO_PROTO */
			picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8,9,1\
0,11,12,13,14,15,16,17", &actsev, &actpcc, 2L, 41L);
#endif /* NO_PROTO */
			if (actsev != sevrty) {
/* Writing concatenation */
#ifndef NO_PROTO
			    i__3[0] = 40, a__2[0] = "Cannot do picture chang"
				    "e for severity = ";
#else /* NO_PROTO */
			    i__3[0] = 40, a__2[0] = "Cannot do picture chang\
e for severity = ";
#endif /* NO_PROTO */
			    i__3[1] = 3, a__2[1] = sevlbl;
			    i__3[2] = 20, a__2[2] = "; skipping test for ";
			    i__3[3] = itrim_(cndlbl, 200L), a__2[3] = cndlbl;
			    i__3[4] = 21, a__2[4] = ", and input inactive.";
			    s_cat(ch__5, a__2, i__3, &c__5, 284L);
			    inmsg_(ch__5, itrim_(cndlbl, 200L) + 84);
			    goto L325;
			}
/*           calculate expected SVRs and label, */
/*              based on sevrty, defmod, modmd, and ol
dsvr */
			exsvrs_(&sevrty, &c__2, &modmd, &oldsvr, svrlst, 
				explbl, 3L, 20L);
/* Writing concatenation */
			i__6[0] = 3, a__5[0] = "If ";
			i__6[1] = itrim_(cndlbl, 200L), a__5[1] = cndlbl;
			i__6[2] = 15, a__5[2] = ", and input is ";
#ifndef NO_PROTO
			i__6[3] = 39, a__5[3] = "inactive, then current stat"
				"e of visual ";
#else /* NO_PROTO */
			i__6[3] = 39, a__5[3] = "inactive, then current stat\
e of visual ";
#endif /* NO_PROTO */
			i__6[4] = 25, a__5[4] = "representation should be ";
			i__6[5] = itrim_(explbl, 20L), a__5[5] = explbl;
			i__6[6] = 1, a__5[6] = ".";
			s_cat(ch__7, a__5, i__6, &c__7, 303L);
			setmsg_("3 4 13 14 15 32", ch__7, 15L, itrim_(cndlbl, 
				200L) + 82 + itrim_(explbl, 20L) + 1);
			L__1 = svrok_(&globnu_1.wkid, svrlst, 3L);
			ifpf_(&L__1);
L325:
			;
		    }
/*  next instat */
/* L360: */
		}
/*  skip_oldsvr: */
L355:
/*  next oldsvr */
/* L350: */
		;
	    }
/*  next sevrty */
/* L340: */
	}
/*  next modmd */
/* L330: */
    }
/* L666: */
/* close output workstation */
    nclwk (&globnu_1.wkid);
/* close input workstation, if needed, and PHIGS */
    if (inwk != globnu_1.wkid) {
	nclwk (&inwk);
    }
L667:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

