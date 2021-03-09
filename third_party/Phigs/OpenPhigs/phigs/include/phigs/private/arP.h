/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2011 - 2012 Surplus Users Ham Society
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
******************************************************************************/

#ifndef _arP_h
#define _arP_h

#define PHG_AR_FOR_ALL_TOC_ENTRIES(_arh, _e)                        \
    {                                                               \
        Phg_ar_toc *_t;                                             \
        int         _l;                                             \
        for (_t = (_arh)->toc; _t; _t = _t->next) {                 \
            _l = 0;                                                 \
            while (_l < _t->head.numUsed) {                         \
                if (_t->entry[_l].type == PHG_AR_FREE_SPACE)        \
                    _l++;                                           \
                else {                                              \
                    _e = &_t->entry[_l++];

#define PHG_AR_END_FOR_ALL_TOC_ENTRIES }}}}

/******************************************************************************
 * phg_ar_set_conversion
 *
 * DESCR:       Set conversion function
 * RETURNS:     N/A
 */

void phg_ar_set_conversion(
    int from,
    int to
    );

/******************************************************************************
 * phg_ar_convert_afd
 *
 * DESCR:       Convert Archive File Descriptor 
 * RETURNS:     N/A
 */

void phg_ar_convert_afd(
    Phg_ar_descriptor *d
    );

/******************************************************************************
 * phg_ar_convert_bse
 *
 * DESCR:       Convert Archive Begin Structure
 * RETURNS:     N/A
 */

void phg_ar_convert_bse(
    Phg_ar_begin_struct *b
    );

/******************************************************************************
 * phg_ar_convert_afs
 *
 * DESCR:       Convert Archive Free Space
 * RETURNS:     N/A
 */

void phg_ar_convert_afs(
    Phg_ar_free_space *f
    );

/******************************************************************************
 * phg_ar_convert_afie
 *
 * DESCR:       Convert Archive Index Entries
 * RETURNS:     N/A
 */

void phg_ar_convert_afie(
    int n,
    Phg_ar_index_entry *e
    );

/******************************************************************************
 * phg_ar_convert_elements
 *
 * DESCR:       Convert Archive Elements
 * RETURNS:     N/A
 */

void phg_ar_convert_elements(
    int nelts,
    char *buffer,
    Phg_ar_archiving_direction direction
    );

/*******************************************************************************
 * phg_ar_write_baf
 *
 * DESCR:       Begin Archive File (BAF) write
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_write_baf(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_read_baf
 *
 * DESCR:       Begin Archive File (BAF) read
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_read_baf(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_read_afd
 *
 * DESCR:       Archive File Descriptor (AFD) write
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_write_afd(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_read_afd
 *
 * DESCR:       Archive File Descriptor (AFD) read
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_read_afd(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_init_toc
 *
 * DESCR:       Archive File initialize table of contents
 * RETURNS:     Pointer to entry or NULL
 */

Phg_ar_toc* phg_ar_init_toc(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_free_toc
 *
 * DESCR:       Archive File free table of contents
 * RETURNS:     N/A
 */

void phg_ar_free_toc(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_read_toc
 *
 * DESCR:       Table of Contents (TOC) read
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_read_toc(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_write_toc
 *
 * DESCR:       Table of Contents (TOC) write
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_write_toc(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_read_eoa
 *
 * DESCR:       End of Archive (EOA) element read
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_read_eoa(
    Ar_handle arh
    );

/*******************************************************************************
 * phg_ar_read_eoa
 *
 * DESCR:       End of Archive (EOA) element write
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_write_eoa(
    int fd
    );

/*******************************************************************************
 * phg_ar_get_entry_from_archive
 *
 * DESCR:       Archive File entry get
 * RETURNS:     Pointer to archive index entry or NULL
 */

Phg_ar_index_entry* phg_ar_get_entry_from_archive(
    Ar_handle arh,
    Pint struct_id
    );

/*******************************************************************************
 * phg_ar_read_struct_from_archive
 *
 * DESCR:       Archive File entry read
 * RETURNS:     Zero on success, otherwise error
 */

int phg_ar_read_struct_from_archive(
    Ar_handle arh,
    Phg_ar_index_entry *entry,
    caddr_t mem
    );

/*******************************************************************************
 * phg_ar_free_entry
 *
 * DESCR:       Turns a structure entry into free space 
 * RETURNS:     N/A
 */

void phg_ar_free_entry(
    Ar_handle arh,
    Phg_ar_index_entry *entry
    );

/*******************************************************************************
 * phg_ar_write_struct_to_archive
 *
 * DESCR:       Archive File write structure to archive
 * RETURNS:     Zero on success, otherwise error
 */
int phg_ar_write_struct_to_archive(
    Ar_handle arh,
    Pint str,
    Pconf_res res_flag,
    Pint nbytes,
    Pint nelts,
    caddr_t mem
    );

#endif /* _arP_h */

