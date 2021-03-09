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

******************************************************************/

/* Hash table code. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <phigs/phg.h>
#include <phigs/util/htab.h>

typedef struct _Htab_entry {
    int			key;
    caddr_t		cdata;	/* client data */
    struct _Htab_entry	*next;
} Htab_entry;

typedef struct _Htab {
    int		num_entries;	/* in table */
    int		hash_size;
    Htab_entry	**tbl;		/* *tbl[num_entries] */
    int		search_used;	/* non-zero if first/next search ever used*/
    int		cur_list;	/* for first and next searches only */
    Htab_entry	*next_entry;	/* for first and next searches only */
} Htab;

/*******************************************************************************
 * get_entry
 *
 * DESCR:       Get hash table entry helper function
 * RETURNS:     Entry
 */

static Htab_entry** get_entry(
    Hash_table htab,
    int	key
    )
{
    Htab_entry **entry_p;

    /* Returns either a pointer to the pointer to the entry (not a pointer
     * to the entry itself) or a pointer to the place the pointer to the
     * entry should exist if it were to be added.
     */
    entry_p = &htab->tbl[PHG_ABS(key) % htab->hash_size];
    for (; (*entry_p != NULL) && ((*entry_p)->key != key);
           entry_p = &(*entry_p)->next)
        ;

    return entry_p;
}

/*******************************************************************************
 * phg_htab_create
 *
 * DESCR:       Create hash table
 * RETURNS:     Hash table or NULL
 */

Hash_table phg_htab_create(
    int	hash_size
    )
{
    Hash_table htab;

    /* Get a block of memory for the Htab structure and the table. */
    if (hash_size <= 0) {
	hash_size = 1;	/* makes it an essentially linear table. */
    }

    htab = (Hash_table) malloc(sizeof(Htab) +
	                       sizeof(Htab_entry *) * (unsigned) hash_size);
    memset(htab, 0,
           sizeof (Htab) + sizeof(Htab_entry *) * (unsigned) hash_size);
    if (htab != NULL) {
        htab->tbl = (Htab_entry **) &htab[1];
	/* Initialize the table. */
	htab->num_entries = 0;
	htab->hash_size = hash_size;
    }
    else {
	htab = NULL;
    }

    return htab;
}

/*******************************************************************************
 * phg_htab_destroy
 *
 * DESCR:       Destroy hash table
 * RETURNS:	N/A
 */

void phg_htab_destroy(
    Hash_table htab,
    void (*destroy_entry)()
    )
{
    int	i;
    Htab_entry *entry, *next;

    for (i = 0; i < htab->hash_size; i++ ) {
	for (entry = htab->tbl[i]; entry != NULL; entry = next) {
	    next = entry->next;
	    if (destroy_entry != NULL)
		(*destroy_entry)(entry->key, entry->cdata);
	    free(entry);
	}
    }
    free(htab);
}

/*******************************************************************************
 * phg_htab_delete_entry
 *
 * DESCR:       Delete hash table entry
 * RETURNS:	Pointer to client data or NULL
 */

caddr_t phg_htab_delete_entry(
    Hash_table htab,
    int	key
    )
{
    caddr_t cdata;
    Htab_entry **entry_p, *tmp;

    /* If the entry exists, free it return the client's data. */
    if (*(entry_p = get_entry( htab, key )) != NULL) {
	cdata = (*entry_p)->cdata;
	tmp = *entry_p;
	*entry_p = tmp->next;
	/* Update the first/next search field. */
	if (tmp == htab->next_entry)
	    htab->next_entry = tmp->next;
	free(tmp);
	--htab->num_entries;
    }
    else {
	cdata = NULL;
    }

    return cdata;
}

/*******************************************************************************
 * phg_htab_add_entry
 *
 * DESCR:       Add hash table entry
 * RETURNS:	TRUE or FALSE
 */

int phg_htab_add_entry(
    Hash_table htab,
    int	key,
    caddr_t cdata
    )
{
    int ret;
    Htab_entry **entry_p;

    entry_p = get_entry(htab, key);

    /* If found, just replace the client data. */
    if (*entry_p != NULL) {
	(*entry_p)->cdata = cdata;
    }
    else {
	/* Create the entry and link it into the table. */
	*entry_p = (Htab_entry *) malloc(sizeof(Htab_entry));
        if (*entry_p != NULL) {
	    (*entry_p)->key = key;
	    (*entry_p)->cdata = cdata;
	    (*entry_p)->next = NULL;
	    ++htab->num_entries;

	    /* Update the first/next search fields if the "next_entry" is
	     * the end of the list this entry was added to.
	     */
	    if (htab->search_used && (htab->next_entry == NULL) &&
		(PHG_ABS(key) % htab->hash_size == htab->cur_list)) {
		htab->next_entry = *entry_p;
            }
	}
    }

    if (*entry_p == NULL) {
        ret = FALSE;
    }
    else {
        ret = TRUE;
    }

    return ret;
}

/*******************************************************************************
 * phg_htab_get_entry
 *
 * DESCR:       Get hash table entry
 * RETURNS:	TRUE or FALSE
 */

int phg_htab_get_entry(
    Hash_table htab,
    int	key,
    caddr_t *cdata_p
    )
{
    int ret;
    Htab_entry **entry_p;

    if (*(entry_p = get_entry(htab, key)) != NULL) {
	if (cdata_p != NULL) {
	    *cdata_p = (*entry_p)->cdata;
        }
    }

    if (*entry_p == NULL) {
        ret = FALSE;
    }
    else {
        ret = TRUE;
    }

    return ret;
}

/*******************************************************************************
 * phg_htab_get_keys
 *
 * DESCR:       Get all keys in hash table
 * RETURNS:	Number of keys
 */

int phg_htab_get_keys(
    Hash_table htab,
    int *keys
    )
{
    int bucket, index;
    Htab_entry *entry_p;

    for (index = 0, bucket = 0; bucket < htab->hash_size; bucket++) {
        for (entry_p = htab->tbl[bucket];
             entry_p != NULL;
             entry_p = entry_p->next) {
            keys[index] = entry_p->key;
            index++;
        }
    }

    return index;
}

/*******************************************************************************
 * phg_htab_change_data
 *
 * DESCR:       Replace hash table entry
 * RETURNS:	TRUE or FALSE
 */

void phg_htab_change_data(
    Hash_table htab,
    int	key,
    caddr_t cdata
    )
{
    Htab_entry	**entry_p;

    if (*(entry_p = get_entry( htab, key )) != NULL) {
	(*entry_p)->cdata = cdata;
    }
}

/*******************************************************************************
 * phg_htab_num_entries
 *
 * DESCR:       Get number hash table entries
 * RETURNS:	Number of entrues
 */

int phg_htab_num_entries(
    Hash_table htab
    )
{
    return htab->num_entries;
}

/*******************************************************************************
 * phg_htab_first_entry
 *
 * DESCR:       Get first hash table entry
 * RETURNS:	TRUE or FALSE
 */

int phg_htab_first_entry(
    Hash_table htab,
    int	*key,
    caddr_t *cdata
    )
{
    htab->search_used = 1;	/* this is never reset to 0 */
    for (htab->cur_list = 0;
         htab->cur_list < htab->hash_size;
	 htab->cur_list++) {
	if (htab->tbl[htab->cur_list] != NULL) {
	    htab->next_entry = htab->tbl[htab->cur_list]->next;
	    if (cdata != NULL) *cdata = htab->tbl[htab->cur_list]->cdata;
	    if (key != NULL) *key = htab->tbl[htab->cur_list]->key;
	    return TRUE;
	}
    }

    return FALSE;
}

/*******************************************************************************
 * phg_htab_next_entry
 *
 * DESCR:       Get next hash table entry
 * RETURNS:	TRUE or FALSE
 */

int phg_htab_next_entry(
    Hash_table htab,
    int	*key,
    caddr_t *cdata
    )
{
    int	ret = FALSE;

    if (htab->next_entry != NULL) {
	if (cdata != NULL) *cdata = htab->next_entry->cdata;
	if (key != NULL) *key = htab->next_entry->key;
	htab->next_entry = htab->next_entry->next;
	ret = TRUE;

    }
    else {
	++htab->cur_list;
	for (; htab->cur_list < htab->hash_size; htab->cur_list++ ) {
	    if (htab->tbl[htab->cur_list] != NULL) {
		htab->next_entry = htab->tbl[htab->cur_list]->next;
		if (cdata != NULL) *cdata = htab->tbl[htab->cur_list]->cdata;
		if (key != NULL) *key = htab->tbl[htab->cur_list]->key;
		ret = TRUE;
		break;
	    }
	}

    }

    return ret;
}

