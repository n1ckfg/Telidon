/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2014 Surplus Users Ham Society
*
*   Open PHIGS is free software: you can redistribute it and/or modify
*   it under the terms of the GNU Lesser General Public License as published by
*   the Free Software Foundation, either version 2.1 of the License, or
*   (at your option) any later version.
*
*   Open PHIGS is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public License
*   along with Open PHIGS. If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************

Copyright (c) 1989, 1990, 1991  X Consortium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from the X Consortium.

Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. 

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the name of Sun Microsystems,
not be used in advertising or publicity pertaining to distribution of 
the software without specific, written prior permission.  

SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, 
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT 
SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL 
DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <errno.h>
#include <phigs/private/arP.h>

/* parameters for LSEEK */
#ifndef L_SET
#define L_SET       0  /* absolute offset */
#endif
#ifndef L_INCR
#define L_INCR      1  /* relative to current offset */
#endif
#ifndef L_XTND
#define L_XTND      2  /* relative to end of file */
#endif

#define GET_ARH(id, arh) \
    for (arh = PHG_AR_LIST; \
         (arh != NULL) && (arh->arid != (id)); \
         arh = arh->next);

static int search_integer_list(
    int target,
    int *intlist,
    int num
    );

static int intcompare(
    const void *a,
    const void *b
    );

static int get_ar_structure_network_ids(
    Ar_handle arh,
    Pint struct_id,
    Pint_list *lst
    );

static int get_css_struct_ids(
    Pint_list *lst
    );

static int get_css_network_sids(
    Pint sid,
    Pint_list *lst
    );

static int compile_network_sids(
    Ar_handle arh,
    Pint_list *in,
    Pstruct_net_source where,
    Pint_list *out
    );

static void merge_and_remove_duplicates(
    int nl,
    Pint_list lsts[],
    Pint_list *result
    );

static void ar_archive(
    Ar_handle arh,
    Phg_args_ar_info *args
    );

/*******************************************************************************
 * phg_ar_open
 *
 * DESCR:	Open archive file
 * RETURNS:	N/A
 */

void phg_ar_open(
    Phg_args_ar_open *args,
    Phg_ret *ret
    )
{
    int		      err;
    Ar_handle	      arh;
    struct stat	      finfo;
    int               fd;
    
    ret->err = !0;
    
    if ( (err = stat(args->fname, &finfo)) && errno != ENOENT) {
	ERR_BUF(PHG_ERH, ERR400);		    /* can't open file */
    } else if (!err && (fd = open(args->fname, O_RDONLY | O_CREAT, 0644) == -1)) {
	ERR_BUF(PHG_ERH, ERR400);		    /* can't open file */
    } else if (!(arh = (Ar_handle)calloc((unsigned)1, sizeof(Ar_struct)))) {
	ERR_BUF(PHG_ERH, ERR900);		    /* out of memory */
    } else {
	/* fill in archive structure and put on beginning of ar_list */
	arh->arid = args->arid;
	*arh->fname = '\0';
	strncat(arh->fname, args->fname, PHG_MAX_NAMELEN);
	arh->toc = NULL;
	arh->next = PHG_AR_LIST;
	PHG_AR_LIST = arh;
	close(fd);
	if (!err && finfo.st_size) {
	    /* file exists and is not empty, so read it */
	    if ((arh->fd = open(arh->fname, O_RDWR)) == -1)
		arh->fd = open(arh->fname, O_RDONLY);
	    if (    phg_ar_read_baf(arh) ||
		    phg_ar_read_afd(arh) ||
		    phg_ar_read_toc(arh) ||
		    phg_ar_read_eoa(arh)) {
		ERR_BUF(PHG_ERH, ERR403);	    /* bad archive file */
	    } else {
		ret->err = 0;
	    }
	} else {
	    /* File couldn't be opened, attempt to create new archive */
	    if ((arh->fd = open(arh->fname, O_RDWR | O_CREAT, 0644)) == -1) {
		ERR_BUF(PHG_ERH, ERR400);
	    } else {
		arh->format = PHG_AR_HOST_BYTE_ORDER | 
			      PHG_AR_HOST_FLOAT_FORMAT;
		arh->toc = NULL;
		if (	(!phg_ar_init_toc(arh)) ||
			(phg_ar_write_baf(arh)) ||
			(phg_ar_write_afd(arh))) {
		    ERR_BUF(PHG_ERH, ERR400);
		} else {
		    arh->afiOffset = (uint32_t)lseek(arh->fd, 0L, L_XTND);
		    if (phg_ar_write_toc(arh)) {
			ERR_BUF(PHG_ERH, ERR400);
		    } else {
			ret->err = 0;
		    }
		}
	    }
	}
    }
}

/*******************************************************************************
 * phg_ar_close
 *
 * DESCR:	Close archive file
 * RETURNS:	N/A
 */

void phg_ar_close(
    Pint ar_id
    )
{
    Ar_handle	arh, arp, tmp_arp = NULL;

    GET_ARH(ar_id, arh);
    if ( (phg_ar_write_toc(arh)) ||
	 (phg_ar_write_eoa(arh->fd))) {
	ERR_BUF(PHG_ERH, ERR406);  /* archive file is full */
    }

    close(arh->fd);
    phg_ar_free_toc(arh);
    
    for (arp = PHG_AR_LIST; arp; arp = arp->next) {
	if (arp == arh) {
	    if (tmp_arp) 
		tmp_arp = arp->next;
	    else
		PHG_AR_LIST = arh->next;
	    break;
	}
	tmp_arp = arp;
    }
    free(arh);
}

/*******************************************************************************
 * phg_ar_archive
 *
 * DESCR:	Put structure networks in archive
 * RETURNS:	N/A
 */

void phg_ar_archive(
    Phg_args_ar_info *args
    )
{
    Pint_list sidlist, arids;
    Ar_handle arh;
    Phg_ar_index_entry *entry;
    int i;

    GET_ARH(args->arid, arh);

    /** Get sids of all the structures we want to archive **/
    switch (args->op) {
    
	case PHG_ARGS_AR_STRUCTS :
	    sidlist.num_ints = args->data.num_ints;
	    sidlist.ints = args->data.ints;
	    break;
	    
	case PHG_ARGS_AR_NETWORKS :
	    if (compile_network_sids((Ar_handle)NULL, &(args->data),
				     PNET_CSS, &(args->data))) {
		return;			       
	    }
	    break;
	    
	case PHG_ARGS_AR_ALL :
	    if (get_css_struct_ids(&args->data)) {
		return;
	    }
	    break;
	    
	default :
	    return;
	    break;
    }
    
    /** Now all of the css ids we're going to archive are in args->data **/
    
    /** Now put all of the archive ids into a list **/
    arids.num_ints = 0;
    PHG_AR_FOR_ALL_TOC_ENTRIES(arh, entry)
	arids.num_ints++;
    PHG_AR_END_FOR_ALL_TOC_ENTRIES
    
    if ( arids.num_ints > 0 && !(arids.ints = (Pint *)
	    malloc((unsigned)(arids.num_ints * sizeof(Pint))))) {
	ERR_BUF(PHG_ERH, ERR900);
	if (args->op != PHG_ARGS_AR_STRUCTS)
	    free(args->data.ints);
	return;
    }
    
    i = 0;
    PHG_AR_FOR_ALL_TOC_ENTRIES(arh, entry)
	arids.ints[i++] = entry->str;
    PHG_AR_END_FOR_ALL_TOC_ENTRIES
    
    if (args->resflag == PRES_ABANDON && arids.num_ints > 0) {
	for (i = 0; i < args->data.num_ints; i++) {
	    if (search_integer_list(args->data.ints[i],
				    arids.ints, arids.num_ints)) {
		ERR_BUF(PHG_ERH, ERR405);	    
		return;
	    }
	}
    }

    ar_archive(arh, args);
}

/*******************************************************************************
 * phg_ar_retreieve
 *
 * DESCR:	Get structure networks from archive
 * RETURNS:	N/A
 */

void phg_ar_retrieve(
    Phg_args_ar_info *args
    )
{

    Pint_list ar_structs, css_ids;
    Ar_handle arh;
    int	i, eln;
    Phg_args_del_el del_el;
    Phg_elmt_info *el_head;
    Phg_args_add_el add_el;
    Phg_args_set_el_ptr set_el_ptr;
    Phg_ar_index_entry *entry;
    caddr_t buffer;
    caddr_t ptr;
    Pedit_mode cur_edit_mode;
    Pint struct_id, cur_open_struct, cur_elem_ptr, cur_struct_state;

    GET_ARH(args->arid, arh);
    
    switch (args->op) {
    
	case PHG_ARGS_AR_STRUCTS :
	    ar_structs.num_ints = args->data.num_ints;
	    ar_structs.ints = args->data.ints;
	    break;
	    
	case PHG_ARGS_AR_NETWORKS :
	    if (compile_network_sids(arh, &(args->data), PNET_AR,
					   &(args->data)))
		return;
	    ar_structs.num_ints = args->data.num_ints;
	    ar_structs.ints = args->data.ints;
	    break;
	    
	case PHG_ARGS_AR_ALL :
	    i = 0;
	    PHG_AR_FOR_ALL_TOC_ENTRIES(arh, entry)
		i++;
	    PHG_AR_END_FOR_ALL_TOC_ENTRIES
	    
	    ar_structs.num_ints = i;
	    if (!(ar_structs.ints = (Pint *)malloc((unsigned)(i * sizeof(Pint))))) {
		ERR_BUF(PHG_ERH, ERR900);
		return;
	    }
	    
	    i = 0;
	    PHG_AR_FOR_ALL_TOC_ENTRIES(arh, entry)
		ar_structs.ints[i++] = entry->str;
	    PHG_AR_END_FOR_ALL_TOC_ENTRIES

	    break;
	    
	default :
	    return;
	    break;
    }
    
    /* Now we know which structures to retrieve */
    
    if (get_css_struct_ids(&css_ids)) {
	free(ar_structs.ints);
        return;
    }
    
    /* if resolution flag is abandon, and there are conflicts, give up */
    if (args->resflag == PRES_ABANDON && css_ids.num_ints > 0) {
	for (i = 0; i < ar_structs.num_ints; i++) {
	    if (search_integer_list(ar_structs.ints[i],
				    css_ids.ints, css_ids.num_ints)) {
		ERR_BUF(PHG_ERH, ERR405);
		free(css_ids.ints);
		if (args->op != PHG_ARGS_AR_STRUCTS)
		    free(ar_structs.ints);
		return;	    
	    }
	}
    }
    
    for (i = 0; i < ar_structs.num_ints; i++) {
	if ( !(entry = phg_ar_get_entry_from_archive(arh,
		ar_structs.ints[i])) ) {
	   ERR_BUF(PHG_ERH, ERR408);
           /* Structure not in archive, create an empty one in CSS if */
           /* it isn't already there */
           if (args->resflag != PRES_MAINTAIN || !(css_ids.num_ints > 0 &&
               search_integer_list(ar_structs.ints[i],
                                   css_ids.ints, css_ids.num_ints))) {
               del_el.op = PHG_ARGS_EMPTY_STRUCT;
               del_el.data.struct_id = ar_structs.ints[i];
               phg_del_el(PHG_CSS, &del_el);
           }
           continue;
	} else if (!(buffer = malloc((unsigned)entry->length))) {
	    ERR_BUF(PHG_ERH, ERR900);
	    free(css_ids.ints);
	    if (args->op != PHG_ARGS_AR_STRUCTS)
		free(ar_structs.ints);
	    return;
	}
	if (phg_ar_read_struct_from_archive(arh, entry, buffer)) {
	    ERR_BUF(PHG_ERH, ERR403);	/* bad archive file */
	    free(css_ids.ints);
	    if (args->op != PHG_ARGS_AR_STRUCTS)
		free(ar_structs.ints);
	    free(buffer);
	    return;
	}
	
	struct_id = ar_structs.ints[i];
	if (args->resflag != PRES_ABANDON && css_ids.num_ints > 0 &&
		search_integer_list(ar_structs.ints[i],
				    css_ids.ints, css_ids.num_ints)) {

	    if (args->resflag == PRES_MAINTAIN)
		continue;
	    else {
		/* remove structure from CSS */
		del_el.op = PHG_ARGS_EMPTY_STRUCT;
		del_el.data.struct_id = ar_structs.ints[i];
                phg_del_el(PHG_CSS, &del_el);
		struct_id = ar_structs.ints[i];
	    }
	}

        /* To do this right the id of the current open structure must */
        /* be retrieved along with the element pointer and edit mode. */
        /* The edit mode needs to be set to insert and everything */
        /* restored after the close. Also after the close, if the */
        /* structure being opened is the one just retrieved, the */
        /* element pointer should not be reset. */
        cur_struct_state = PSL_STRUCT_STATE(PHG_PSL);
        if (cur_struct_state == PSTRUCT_ST_STOP)
        {
            cur_open_struct = PHG_PSL->open_struct;
            cur_elem_ptr = CSS_INQ_EL_INDEX(PHG_CSS);
        }
        cur_edit_mode = PHG_PSL->edit_mode;
        PHG_PSL->edit_mode = PEDIT_INSERT;

	/* Create new structure and add the elements. */
	if (phg_css_open_struct(PHG_CSS, struct_id) == NULL) {
	    free(css_ids.ints);
	    if (args->op != PHG_ARGS_AR_STRUCTS)
		free(ar_structs.ints);
	    free(buffer);
	    return;
	}

        ptr = buffer;
	for (eln = 0; eln < entry->nelts; eln++) {
	    el_head = (Phg_elmt_info *) ptr;
	    add_el.el_type = el_head->elementType;
            add_el.el_size = el_head->length - sizeof(Phg_elmt_info);
	    add_el.el_data = &el_head[1];
            phg_add_el(PHG_CSS, &add_el);
	    ptr += el_head->length;
	}

	/* close the structure */
        phg_close_struct(PHG_CSS);

        /* Restore things */
        PHG_PSL->edit_mode = cur_edit_mode;
        if (cur_struct_state == PSTRUCT_ST_STOP)
        {
	    phg_css_open_struct(PHG_CSS, cur_open_struct);
            if (cur_open_struct != ar_structs.ints[i])
            {
                set_el_ptr.op = PHG_ARGS_SETEP_ABS;
                set_el_ptr.data = cur_elem_ptr;
                phg_set_el_ptr(PHG_CSS, &set_el_ptr);
            }
        }

	free(buffer);
    }
    
    free(css_ids.ints);
    if (args->op != PHG_ARGS_AR_STRUCTS)
	free(ar_structs.ints);
}

/*******************************************************************************
 * phg_ar_delete
 *
 * DESCR:	Delete structure networks from archive
 * RETURNS:	N/A
 */

void phg_ar_delete(
    Phg_args_ar_info *args
    )
{
    Ar_handle arh;
    Pint id;
    Phg_args_ar_open ar_open;
    Phg_ret ret;
    char *arname;
    int already_warned = 0;
    int i, j;
    Phg_ar_index_entry *entry;

    GET_ARH(args->arid, arh);
    
    switch (args->op) {
    
	case PHG_ARGS_AR_STRUCTS :
	    for (i = 0; i < args->data.num_ints; i++) {
		if (!(entry = phg_ar_get_entry_from_archive(arh, 
				    args->data.ints[i]))) {
		    if (!already_warned) {
			ERR_BUF(PHG_ERH, ERR407);  /* just warn once */
			already_warned = 1;
		    }
		} else {
		    phg_ar_free_entry(arh, entry);
		}
	    }
	    break;
	    
	case PHG_ARGS_AR_NETWORKS :
	    {
		int	 nl = args->data.num_ints;
		Pint_list *lsts = (Pint_list *)malloc((unsigned)(nl * sizeof(Pint_list)));
		int	 upper_bound = 0;
		Pint_list	 ids;

		/* create list of all sids under specified structures */
		for (i = 0; i < nl; i++) {
		    if (!phg_ar_get_entry_from_archive(arh,
				    args->data.ints[i])) {
			if (!already_warned) {
			    ERR_BUF(PHG_ERH, ERR407);	/* just warn once */
			    already_warned = 1;
			}
			lsts[i].num_ints = 0;
		    } else {
			if (get_ar_structure_network_ids(arh, 
				args->data.ints[i], &lsts[i])) {
			    ERR_BUF(PHG_ERH, ERR900);
			    for (j = 0; j < i; j++)
				free(lsts[j].ints);
			    free(lsts);
			    return;
			}
		    }

		    qsort((char *)lsts[i].ints, lsts[i].num_ints, 
			    sizeof(Pint), intcompare);
	
		    upper_bound += lsts[i].num_ints;
		}
		
		ids.ints = (Pint *)malloc((unsigned)(upper_bound * sizeof(Pint)));
		
		merge_and_remove_duplicates(nl, lsts, &ids);
		
		for (i = 0; i < ids.num_ints; i++) {
		    phg_ar_free_entry(arh, 
			phg_ar_get_entry_from_archive(arh, ids.ints[i]));
		}
		
		for (i = 0; i < nl; i++) {
		    if (lsts[i].num_ints) 
			free(lsts[i].ints);
		}
		free(lsts);
		free(ids.ints);
		
	    }
	    break;

	case PHG_ARGS_AR_ALL :
	    /* delete all structs by removing the file and reopening anew */
	    id = arh->arid;
	    if (!(arname = malloc((unsigned)(strlen(arh->fname) + 1)))) {
		ERR_BUF(PHG_ERH, ERR900);
		return;
	    }
	    strcpy(arname, arh->fname);
            phg_ar_close(id);
	    unlink(arname);
	    ar_open.fname = arname;
	    ar_open.name_length = sizeof(arname);
	    ar_open.arid = id;
            phg_ar_open(&ar_open, &ret);
	    free(arname);
	    break;

	default :
	    return;
    }
}

/*******************************************************************************
 * phg_ar_get_names
 *
 * DESCR:       Get archive catalog of names
 * RETURNS:     N/A
 */

void phg_ar_get_names(
    Pint arid,
    Phg_ret *ret
    )
{
    Ar_handle arh;
    int i;
    Phg_ar_index_entry *entry;
    
    ret->err = !0;

    GET_ARH(arid, arh);
    
    /* count the structures */
    ret->data.int_list.num_ints = 0;
    PHG_AR_FOR_ALL_TOC_ENTRIES(arh, entry)
	ret->data.int_list.num_ints++;
    PHG_AR_END_FOR_ALL_TOC_ENTRIES
    
    if (ret->data.int_list.num_ints <= 0) {
	ret->err = 0;
    }
    else if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, 
		                ret->data.int_list.num_ints * sizeof(Pint))) {
	ERR_BUF(PHG_ERH, ERR900);
    } else {
        /* catalog the ids */
        ret->data.int_list.ints = (Pint *) PHG_SCRATCH.buf;
	i = 0;
	PHG_AR_FOR_ALL_TOC_ENTRIES(arh, entry)
	    ret->data.int_list.ints[i++] = entry->str;
	PHG_AR_END_FOR_ALL_TOC_ENTRIES
	ret->err = 0;
    }
}

/*******************************************************************************
 * phg_ar_get_hierarchy
 *
 * DESCR:       Get archive hierachy
 * RETURNS:     N/A
 */

void phg_ar_get_hierarchy(
    Phg_args_q_ar_hierarchy *args,
    Phg_ret *ret
    )
{
    Phg_args_q_hierarchy *hier = &(args->hier);
    Pelem_ref_list allpaths, curpath;
    Pint_list counts;
    int	retval = TRUE;
    Phg_args_hierarchy_dir dir = hier->dir;
    Pint struct_id = hier->struct_id;
    Ppath_order order = hier->order;
    Pint depth = hier->depth;
    Ar_handle arh;

    ret->err = !0;
    
    GET_ARH(args->arid, arh);

    if (!phg_ar_get_entry_from_archive(arh, struct_id)) {
	ERR_BUF(PHG_ERH, ERR201);
	return;
    }

    /* alloc 1024 cells, use realloc later if it's not big enough */
    if (!(allpaths.elem_refs = 
		(Pelem_ref *)PHG_SCRATCH_SPACE(&PHG_SCRATCH,
		    1024 * sizeof(Pelem_ref)))) {
        ERR_BUF(PHG_ERH, ERR900);
        return;                                         /* out of memory */
    }
    
    /* start out with room for a current path depth of 
     * PHG_AR_TMPMEM_BLOCKSIZE and a total of PHG_AR_TMPMEM_BLOCKSIZE paths*/
    curpath.elem_refs = (Pelem_ref *) malloc(PHG_AR_TMPMEM_BLOCKSIZE * 
				      sizeof(Pelem_ref));
    if (!(curpath.elem_refs)) {
        ERR_BUF(PHG_ERH, ERR900);
        return;                                         /* out of memory */
    }
    counts.ints = (Pint *) malloc(PHG_AR_TMPMEM_BLOCKSIZE * sizeof(Pint));
    if (!(counts.ints)) {
	free(curpath.elem_refs);
        ERR_BUF(PHG_ERH, ERR900);
        return;                                         /* out of memory */
    }

    allpaths.num_elem_refs = curpath.num_elem_refs = counts.num_ints = 0;
    if (dir == PHG_ARGS_HIER_DESCENDANTS)
        retval = phg_ar_inq_descendants(arh, struct_id, &allpaths, 
			&curpath, &counts, order, depth);
    else 
        retval = phg_ar_inq_ancestors(arh, struct_id, &allpaths, 
			&curpath, &counts, order, depth);
				   
    if (!retval) {
        ERR_BUF(PHG_ERH, ERR900);                       /* out of memory */
        goto free_and_return;
    }
    
    /* make sure scratch has enough space before copying counts array */
    if (allpaths.num_elem_refs*sizeof(Pelem_ref) + counts.num_ints*sizeof(Pint) >
            PHG_SCRATCH.size) {
	    
        int increm = counts.num_ints * sizeof(Pint);
 
        PHG_SCRATCH.buf = realloc(PHG_SCRATCH.buf, PHG_SCRATCH.size+increm);
        if (PHG_SCRATCH.buf) {
            PHG_SCRATCH.size += increm;
            allpaths.elem_refs = (Pelem_ref *)PHG_SCRATCH.buf;
        } else {
            ERR_BUF(PHG_ERH, ERR900);                   /* out of memory */
            goto free_and_return;
        }
    }

    ret->data.hierarchy.paths = allpaths.elem_refs;
    ret->data.hierarchy.num_pairs = allpaths.num_elem_refs;
    ret->data.hierarchy.counts.num_ints = counts.num_ints;

    ret->data.hierarchy.counts.ints =
        (Pint *)(allpaths.elem_refs + allpaths.num_elem_refs);
	
    while (counts.num_ints--)
        ret->data.hierarchy.counts.ints[counts.num_ints] =
            counts.ints[counts.num_ints];

    ret->err = 0;

free_and_return:
    free(curpath.elem_refs);
    free(counts.ints);
}

/*******************************************************************************
 * phg_inq_ar_conflicting
 *
 * DESCR:       Get list of conflicting structures in archive
 * RETURNS:     N/A
 */

void phg_inq_ar_conflicting(
    Phg_args_q_conflicting *args,
    Phg_ret *ret
    )
{
    Pint_list css_ids, ar_net_ids;
    int i;
    Phg_ar_index_entry *entry;
    Ar_handle arh;
    
    ret->err = !0;
    
    GET_ARH(args->arid, arh);
    
    /* get the CSS structure ids */
    if (args->op == PHG_ARGS_CONF_NET && args->src == PNET_CSS) {
	if (get_css_network_sids(args->struct_id, &css_ids))
	    return;
    } else {
	if (get_css_struct_ids(&css_ids))
	    return;
    }

    qsort((char *)css_ids.ints, css_ids.num_ints, sizeof(Pint), 
		    intcompare);

    /* we know that scratch is at least as big as sizeof(Pint)*(#sids)
     * because of previous calls, so we don't need to count the conflicting
     * ones before using scratch. */
    ret->data.int_list.ints = (Pint *)PHG_SCRATCH.buf;
    ret->data.int_list.num_ints = 0;
    
    if (args->op == PHG_ARGS_CONF_NET && args->src == PNET_AR) {
    
	if (get_ar_structure_network_ids(arh,
					 args->struct_id, &ar_net_ids)) {
	    free(css_ids.ints);
	    return;
	}

	/* now figure out which are in both css and archive net */
	if (css_ids.num_ints > 0)
	    for (i = 0; i < ar_net_ids.num_ints; i++) {
		if (search_integer_list(ar_net_ids.ints[i],
					css_ids.ints, css_ids.num_ints)) {
		    ret->data.int_list.ints[ret->data.int_list.num_ints++]
			    = ar_net_ids.ints[i];
		}
	    }
		
	free(ar_net_ids.ints);

    } else {

	/* check each entry to see if it's in CSS id list.  If it is,
	 * then add to list of conflicting structures */
	if (css_ids.num_ints > 0)
	    PHG_AR_FOR_ALL_TOC_ENTRIES(arh, entry)
		if (search_integer_list((int)entry->str, css_ids.ints, 
				                    css_ids.num_ints)) {
		    ret->data.int_list.ints[ret->data.int_list.num_ints++] =
		    entry->str;
		}
	    PHG_AR_END_FOR_ALL_TOC_ENTRIES
    }

    free(css_ids.ints);
    
    ret->err = 0;
}

/*******************************************************************************
 * search_integer_list
 *
 * DESCR:	Perform a binary search on a sorted list of ints helper function
 * RETURNS:	One if found otherwise Zero
 */

static int search_integer_list(
    int target,
    int *intlist,
    int num
    )
{
    int *base = intlist;
    int *last = &intlist[num-1];
    int *ptr;
    
    while (last >= base) {
    
	ptr = base + ((last - base) / 2);
	
	if (target == *ptr)
	    return 1;
	else if (target < *ptr)
	    last = ptr - 1;
	else
	    base = ptr + 1;
	    
    }
    
    return 0;
}

/*******************************************************************************
 * intcompare
 *
 * DESCR:	Comapre two ingegers helper function
 * RETURNS:	One if equal otherwise Zero
 */

static int intcompare(
    const void *a,
    const void *b
    )
{
    return(*((int *)a) - *((int *)b));
}

/*******************************************************************************
 * get_ar_structure_network_ids
 *
 * DESCR:     Return an ordered, duplicates removed, list of structure ids in a 
 *            structure network rooted at the specified struct_id.  IT IS THE
 *            CALLERS RESPONSIBILITY TO FREE THE lst->ints STRUCTURE WHEN
 *            IT'S NOT NEEDED
 * RETURNS    Zero on success, otherwise non-zero
 */

static int get_ar_structure_network_ids(
    Ar_handle arh,
    Pint struct_id,
    Pint_list *lst
    )
{
    Phg_args_q_ar_hierarchy args;
    Phg_ret ret;
    int i, j;
    Phg_args_q_hierarchy *hier = &args.hier;
    
    args.arid   = arh->arid;
    hier->dir	= PHG_ARGS_HIER_DESCENDANTS;
    hier->depth	= 0;
    hier->order	= PORDER_TOP_FIRST;
    hier->struct_id = struct_id;
    phg_ar_get_hierarchy(&args, &ret);
	
    /** this won't put on the root structure, so explicitly add it in **/
    if (ret.err)
        return(1);
    else {
        lst->num_ints = ret.data.hierarchy.num_pairs + 1;
        if (!(lst->ints = 
		    (Pint *)malloc((unsigned)(lst->num_ints * sizeof(Pint))))) {
	    ERR_BUF(PHG_ERH, ERR900);
	    return(1);
        } else {
	    /* copy list */
	    for (i = 0; i < lst->num_ints - 1; i++) {
	        lst->ints[i] = ret.data.hierarchy.paths[i].struct_id;
	    }
	    lst->ints[lst->num_ints - 1] = struct_id;

	    /* sort and remove duplicates */
	    qsort((char *)lst->ints, lst->num_ints,
			sizeof(Pint), intcompare);
	    for (i = j = 0; j < lst->num_ints; j++) {
	        while ((j + 1 < lst->num_ints) &&
		       (lst->ints[j] == lst->ints[j+1]))
		    j++;
	        lst->ints[i++] = lst->ints[j];
	    }
	    lst->num_ints = i;
	}
	return(0);
    }
}

/*******************************************************************************
 * get_css_network_sids
 *
 * DESCR:       CALLERS RESPONSIBILE FOR FREEING ints FIELD
 * RETURNS      Zero on success, otherwise non-zero
 */

static int get_css_struct_ids(
    Pint_list *lst
    )
{
    Phg_ret ret;

    ret.err = 0;
    phg_css_inq_struct_ids(PHG_CSS, &ret);
    if (ret.err)
        return(1);
    else {
        lst->num_ints = ret.data.int_list.num_ints;
	if (lst->num_ints == 0) {
	    lst->ints = NULL;
	} else if (!(lst->ints = (Pint *)malloc((unsigned)(lst->num_ints * 
						    sizeof(Pint))))) {
	    ERR_BUF(PHG_ERH, ERR900);
	    return(1);
        } else {
	    memcpy(lst->ints, ret.data.int_list.ints,
                   lst->num_ints * sizeof(Pint));
        }
    }

    return(0);
}

/*******************************************************************************
 * get_css_network_sids
 *
 * DESCR:       CALLERS RESPONSIBILE FOR FREEING lst->ints FIELD
 * RETURNS      Zero on success, otherwise non-zero
 */

static int get_css_network_sids(
    Pint sid,
    Pint_list *lst
    )
{
    Phg_ret ret;
    int i;

    phg_css_inq_hierarchy(PHG_CSS, PHG_ARGS_HIER_DESCENDANTS, sid,
                          PORDER_TOP_FIRST, 0, &ret);

    if (ret.err)
	return(1);
    else if (ret.data.hierarchy.num_pairs == 0) {
	lst->num_ints = 1;
	if (!(lst->ints = (Pint *)malloc(sizeof(Pint)))) {
	    ERR_BUF(PHG_ERH, ERR900);
	    return(1);
	} else {
	    lst->ints[0] = sid;
	}
    } else {
	lst->num_ints = ret.data.hierarchy.num_pairs;
	if (!(lst->ints = (Pint *)malloc((unsigned)(lst->num_ints * sizeof(Pint))))) {
	    ERR_BUF(PHG_ERH, ERR900);
	    return(1);
	} else {
	    for (i = 0; i < lst->num_ints; i++) {
		lst->ints[i] = ret.data.hierarchy.paths[i].struct_id;
	    }
	}
    }
    
    return(0);
}

/*******************************************************************************
 * compile_network_sids
 *
 * DESCR:   Takes in a list of structure ids, which are interpreted as a list of
 *          structure network roots.  Returns a sorted, duplicates removed, list
 *          of all of the structures in those networks.  Can come from either
 *          the CSS or the archive
 *          CALLER RESPONSIBLE FOR FREEING out->ints
 * RETURNS  Zero on success, otherwise non-zero
 */

static int compile_network_sids(
    Ar_handle arh,                      /* ignore if where == PNET_CSS */
    Pint_list *in,                      /* list of networks (by root sid) */
    Pstruct_net_source where,           /* get from CSS or archive? */
    Pint_list *out                      /* list of sids in network */
    )
{
    Phg_ret ret;
    int nl = in->num_ints;
    Pint_list *lsts = (Pint_list *)malloc((unsigned)(nl * sizeof(Pint_list)));
    int	i, j, upper_bound = 0;

    if (!lsts) {
	ERR_BUF(PHG_ERH, ERR900);
	return(1);
    }

    for (i = 0; i < nl; i++) {
    
	if (where == PNET_AR) {
	    if (!phg_ar_get_entry_from_archive(arh, in->ints[i])) {
		lsts[i].num_ints = 1;
		lsts[i].ints = (Pint *)malloc(sizeof(Pint));
		lsts[i].ints[0] = in->ints[i];
	    } else {
		if (get_ar_structure_network_ids(arh, in->ints[i],
				    &lsts[i])) {
		    ERR_BUF(PHG_ERH, ERR900);
		    for (j = 0; j < i; j++)
			free(lsts[j].ints);
		    free(lsts);
		    return(1);
		}
	    }
	    
	} else { /* where == PNET_CSS */
            ret.err = 0;
	    phg_css_inq_struct_status(PHG_CSS, in->ints[i], &ret);
            if (ret.err || ret.data.idata == PSTRUCT_STATUS_NON_EXISTENT) {
		ERR_BUF(PHG_ERH, ERR200);
		lsts[i].num_ints = 0;
	    } else {
		if (get_css_network_sids(in->ints[i], &lsts[i])) {
		    for (j = 0; j < i; j++)
			free(lsts[j].ints);
		    free(lsts);
		    return(1);
		}
	    }
	}
	
	qsort((char *)lsts[i].ints, lsts[i].num_ints, sizeof(Pint), 
		    intcompare);

	upper_bound += lsts[i].num_ints;
    }

    out->ints = (Pint *)malloc((unsigned)(upper_bound * sizeof(Pint)));

    merge_and_remove_duplicates(nl, lsts, out);

    for (i = 0; i < nl; i++) {
	if (lsts[i].num_ints)
	    free(lsts[i].ints);
    }
	
    free(lsts);
    
    return(0);
}

/*******************************************************************************
 * merge_and_remove_duplicates
 *
 * DESCR:       Merge nl sorted lists, removing duplicates
 * RETURNS:     N/A
 */

static void merge_and_remove_duplicates(
    int nl,                                     /* number of lists */
    Pint_list lsts[],                           /* array of intlsts */
    Pint_list *result                           /* pointer to resulting list */
    )
{
    int i, j;
    int	done = 0;
    int	*inds = (int *)malloc((unsigned)(nl * sizeof(int)));

    for (i = 0; i < nl; i++)
	inds[i] = 0;
	
    i = 0;
    
    while (!done) {
    
	int min_lst = -1;
	Pint min_num = 9999999;
	
	/* find smallest number in first elements of all lists */
	for (j = 0; j < nl; j++) {
	    if (inds[j] < lsts[j].num_ints && 
		    ((lsts[j].ints[inds[j]] < min_num) ||
		    (min_lst == -1))) {
		min_num = lsts[j].ints[inds[j]];
		min_lst = j;
	    }
	}
	
	/* put onto main list */
	if (min_lst == -1) {
	    done = 1;
	} else {
	    if (i == 0 || min_num != result->ints[i - 1]) {
		/* not a duplicate */
		result->ints[i++] = min_num;
	    }
	    inds[min_lst]++;
	}
    }
    result->num_ints = i;
    free(inds);
}

/*******************************************************************************
 * ar_archive
 *
 * DESCR:       Archive selected elements
 * RETURNS:     N/A
 */

static void ar_archive(
    Ar_handle arh,
    Phg_args_ar_info *args
    )
{
    Pint struct_id;
    Pint el_id;
    Phg_ret ret;
    int	i, num_els = 0;
    unsigned struct_length = 0;
    caddr_t buffer = NULL;
    unsigned buf_size = 0;

    for ( i = 0; i < args->data.num_ints; i++ ) { /* for all structs */
	struct_id = args->data.ints[i];
	el_id = 1;
	struct_length = 0;
	num_els = 0;
	ret.err = 0;
	do {	/* get element info and buffer it */
	    phg_css_inq_el_content( PHG_CSS, struct_id, el_id, &ret );
	    if ( ret.err == 0 ) {
		/* Get buffer space if buffer too small. */
		if ( buf_size < (struct_length +
			        (unsigned) ret.data.el_info.el_head->length) ) {
		    if ( !buffer )	/* first element of first struct */
			buffer = malloc( buf_size =
			    (unsigned) ret.data.el_info.el_head->length );
		    else
			buffer = realloc( buffer, buf_size = struct_length +
			    (unsigned) ret.data.el_info.el_head->length );
		    if ( !buffer ) {
			ERR_BUF( PHG_ERH, ERR900 );
			return;
		    }
		}
		/* Concatenate the element data to the current list. */
		memcpy(&buffer[struct_length],
		       ret.data.el_info.el_head,
		       (int)ret.data.el_info.el_head->length);
		struct_length += (unsigned) ret.data.el_info.el_head->length;
		++num_els;
		++el_id;
	    }
	} while ( ret.err == 0 );

	/* Write the entire structure to the archive. */
	if ( phg_ar_write_struct_to_archive( arh, args->data.ints[i], 
			args->resflag, (Pint)struct_length, (Pint)num_els, buffer ) ) {
	    ERR_BUF(PHG_ERH, ERR406);
	    if (buffer)
		free(buffer);
	    return;
	}
    }

    if (buffer)
	free(buffer);
}

