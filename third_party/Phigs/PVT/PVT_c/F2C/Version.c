static char junk[] = "\n@(#) LIBI77 VERSION pjw,dmg-mods 6 April 1993\n";

/*
2.01	$ format added
2.02	Coding bug in open.c repaired
2.03	fixed bugs in lread.c (read * with negative f-format) and lio.c
	and lio.h (e-format conforming to spec)
2.04	changed open.c and err.c (fopen and freopen respectively) to
	update to new c-library (append mode)
2.05	added namelist capability
2.06	allow internal list and namelist I/O
*/

/*
close.c:
	allow upper-case STATUS= values
endfile.c
	create fort.nnn if unit nnn not open;
	else if (file length == 0) use creat() rather than copy;
	use local copy() rather than forking /bin/cp;
	rewind, fseek to clear buffer (for no reading past EOF)
err.c
	use neither setbuf nor setvbuf; make stderr buffered
fio.h
	#define _bufend
inquire.c
	upper case responses;
	omit byfile test from SEQUENTIAL=
	answer "YES" to DIRECT= for unopened file (open to debate)
lio.c
	flush stderr, stdout at end of each stmt
	space before character strings in list output only at line start
lio.h
	adjust LEW, LED consistent with old libI77
lread.c
	use atof()
	allow "nnn*," when reading complex constants
open.c
	try opening for writing when open for read fails, with
	special uwrt value (2) delaying creat() to first write;
	set curunit so error messages don't drop core;
	no file name ==> fort.nnn except for STATUS='SCRATCH'
rdfmt.c
	use atof(); trust EOF == end-of-file (so don't read past
	end-of-file after endfile stmt)
sfe.c
	flush stderr, stdout at end of each stmt
wrtfmt.c:
	use upper case
	put wrt_E and wrt_F into wref.c, use sprintf()
		rather than ecvt() and fcvt() [more accurate on VAX]
*/

/* 16 Oct. 1988: uwrt = 3 after write, rewind, so close won't zap the file. */

/* 10 July 1989: change _bufend to buf_end in fio.h, wsfe.c, wrtfmt.c */

/* 28 Nov. 1989: corrections for IEEE and Cray arithmetic */
/* 29 Nov. 1989: change various int return types to long for f2c */
/* 30 Nov. 1989: various types from f2c.h */
/*  6 Dec. 1989: types corrected various places */
/* 19 Dec. 1989: make iostat= work right for internal I/O */
/*  8 Jan. 1990: add rsne, wsne -- routines for handling NAMELIST */
/* 28 Jan. 1990: have NAMELIST read treat $ as &, general white
		 space as blank */
/* 27 Mar. 1990: change an = to == in rd_L(rdfmt.c) so formatted reads
		 of logical values reject letters other than fFtT;
		 have nowwriting reset cf */
/* 14 Aug. 1990: adjust lread.c to treat tabs as spaces in list input */
/* 17 Aug. 1990: adjust open.c to recognize blank='Z...' as well as
		 blank='z...' when reopening an open file */
/* 30 Aug. 1990: prevent embedded blanks in list output of complex values;
		 omit exponent field in list output of values of
		 magnitude between 10 and 1e8; prevent writing stdin
		 and reading stdout or stderr; don't close stdin, stdout,
		 or stderr when reopening units 5, 6, 0. */
/* 18 Sep. 1990: add component udev to unit and consider old == new file
		 iff uinode and udev values agree; use stat rather than
		 access to check existence of file (when STATUS='OLD')*/
/* 2 Oct. 1990:  adjust rewind.c so two successive rewinds after a write
		 don't clobber the file. */
/* 9 Oct. 1990:  add #include "fcntl.h" to endfile.c, err.c, open.c;
		 adjust g_char in util.c for segmented memories. */
/* 17 Oct. 1990: replace abort() and _cleanup() with calls on
		 sig_die(...,1) (defined in main.c). */
/* 5 Nov. 1990:  changes to open.c: complain if new= is specified and the
		 file already exists; allow file= to be omitted in open stmts
		 and allow status='replace' (Fortran 90 extensions). */
/* 11 Dec. 1990: adjustments for POSIX. */
/* 15 Jan. 1991: tweak i_ungetc in rsli.c to allow reading from
		 strings in read-only memory. */
/* 25 Apr. 1991: adjust namelist stuff to work with f2c -i2 */
/* 26 Apr. 1991: fix some bugs with NAMELIST read of multi-dim. arrays */
/* 16 May 1991:  increase LEFBL in lio.h to bypass NeXT bug */
/* 17 Oct. 1991: change type of length field in sequential unformatted
		 records from int to long (for systems where sizeof(int)
		 can vary, depending on the compiler or compiler options). */
/* 25 Nov. 1991: change uint to Uint in lwrite.c; change sizeof(int) to
		 sizeof(uioint) in fseeks in sue.c (missed on 17 Oct.). */
/* 1 Dec. 1991:  uio.c: add test for read failure (seq. unformatted reads);
		 adjust an error return from EOF to off end of record */
/* 12 Dec. 1991: rsli.c: fix bug with internal list input that caused
		 the last character of each record to be ignored.
		 iio.c: adjust error message in internal formatted
		 input from "end-of-file" to "off end of record" if
		 the format specifies more characters than the
		 record contains. */
/* 17 Jan. 1992: lread.c, rsne.c: in list and namelist input,
		 treat "r* ," and "r*," alike (where r is a
		 positive integer constant), and fix a bug in
		 handling null values following items with repeat
		 counts (e.g., 2*1,,3); for namelist reading
		 of a numeric array, allow a new name-value subsequence
		 to terminate the current one (as though the current
		 one ended with the right number of null values).
		 lio.h, lwrite.c: omit insignificant zeros in
		 list and namelist output. To get the old
		 behavior, compile with -DOld_list_output . */
/* 18 Jan. 1992: make list output consistent with F format by
		 printing .1 rather than 0.1 (introduced yesterday). */
/* 3 Feb. 1992:  rsne.c: fix namelist read bug that caused the
		 character following a comma to be ignored. */
/* 19 May 1992:  adjust iio.c, ilnw.c, rdfmt.c and rsli.c to make err=
		 work with internal list and formatted I/O. */
/* 18 July 1992: adjust rsne.c to allow namelist input to stop at
		 an & (e.g. &end). */
/* 23 July 1992: switch to ANSI prototypes unless KR_headers is #defined ;
		 recognize Z format (assuming 8-bit bytes). */
/* 14 Aug. 1992: tweak wrt_E in wref.c to avoid -NaN */
/* 23 Oct. 1992: Supply missing l_eof = 0 assignment to s_rsne() in rsne.c
		 (so end-of-file on other files won't confuse namelist
		 reads of external files).  Prepend f__ to external
		 names that are only of internal interest to lib[FI]77. */
/* 1 Feb. 1993:  backspace.c: fix bug that bit when last char of 2nd
		 buffer == '\n'.
		 endfile.c: guard against tiny L_tmpnam; close and reopen
		 files in t_runc().
		 lio.h: lengthen LINTW (buffer size in lwrite.c).
		 err.c, open.c: more prepending of f__ (to [rw]_mode). */
/* 5 Feb. 1993:  tweaks to NAMELIST: rsne.c: ? prints the namelist being
		 sought; namelists of the wrong name are skipped (after
		 an error message; xwsne.c: namelist writes have a
		 newline before each new variable.
		 open.c: ACCESS='APPEND' positions sequential files
		 at EOF (nonstandard extension -- that doesn't require
		 changing data structures). */
/* 9 Feb. 1993:  Change some #ifdef MSDOS lines to #ifdef NON_UNIZ_STDIO.
		 err.c: under NON_UNIX_STDIO, avoid close(creat(name,0666))
		 when the unit has another file descriptor for name. */
/* 4 March 1993: err.c, open.c: take declaration of fdopen from rawio.h;
		 open.c: always give f__w_mode[] 4 elements for use
		 in t_runc (in endfile.c -- for change of 1 Feb. 1993). */
/* 6 March 1993: uio.c: adjust off-end-of-record test for sequential
		 unformatted reads to respond to err= rather than end=. */
/* 12 March 1993: various tweaks for C++ */
/* 6 April 1993: adjust error returns for formatted inputs to flush
		 the current input line when err=label is specified.
		 To restore the old behavior (input left mid-line),
		 either adjust the #definition of errfl in fio.h or
		 omit the invocation of f__doend in err__fl (in err.c).	*/

/*
static char junk[] = "\n@(#)LIBF77 VERSION 2.01 12 March 1993\n";

2.00	11 June 1980.  File version.c added to library.
2.01	31 May 1988.  s_paus() flushes stderr; names of hl_* fixed
	[ d]erf[c ] added
	 8 Aug. 1989: #ifdefs for f2c -i2 added to s_cat.c
	29 Nov. 1989: s_cmp returns long (for f2c)
	30 Nov. 1989: arg types from f2c.h
	12 Dec. 1989: s_rnge allows long names
	19 Dec. 1989: getenv_ allows unsorted environment
	28 Mar. 1990: add exit(0) to end of main()
	 2 Oct. 1990: test signal(...) == SIG_IGN rather than & 01 in main
	17 Oct. 1990: abort() calls changed to sig_die(...,1)
	22 Oct. 1990: separate sig_die from main
	25 Apr. 1991: minor, theoretically invisible tweaks to s_cat, sig_die
	31 May  1991: make system_ return status
	18 Dec. 1991: change long to ftnlen (for -i2) many places
	28 Feb. 1992: repair z_sqrt.c (scribbled on input, gave wrong answer)
	18 July 1992: for n < 0, repair handling of 0**n in pow_[dr]i.c
			and m**n in pow_hh.c and pow_ii.c;
			catch SIGTRAP in main() for error msg before abort
	23 July 1992: switch to ANSI prototypes unless KR_headers is #defined
	23 Oct. 1992: fix botch in signal_.c (erroneous deref of 2nd arg);
			change Cabs to f__cabs.
	12 March 1993: various tweaks for C++.
*/
