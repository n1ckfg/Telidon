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
******************************************************************************/

#ifndef _ar_h
#define _ar_h

#include <stdint.h>

#ifdef VAX
#define PHG_AR_HOST_FLOAT_FORMAT 0x2
#else /* !VAX */
#define PHG_AR_HOST_FLOAT_FORMAT 0x0
#endif /* VAX */

#ifdef MSBFIRST
#define PHG_AR_HOST_BYTE_ORDER   0x1
#else /* LSBFIRST */
#define PHG_AR_HOST_BYTE_ORDER   0x0
#endif

#ifdef DEBUG
#define TOCSIZE                  256
#else
#define TOCSIZE                  4
#endif

/* Archive element opcodes */
#define PHG_AR_BAF               0x1010      /* Begin Archive File */
#define PHG_AR_AFD               0x1111      /* Archive File Descriptor */
#define PHG_AR_BSE               0x1212      /* Begin Structure Element */
#define PHG_AR_ESE               0x1313      /* End Structure Element */
#define PHG_AR_EOA               0x1414      /* End Of Archive */
#define PHG_AR_AFS               0x1515      /* Archive Free Space */
#define PHG_AR_AFI               0x1616      /* Archive File Index element */

#define PHG_AR_STRUCT            0x1         /* block contains structure */
#define PHG_AR_FREE_SPACE        0x2         /* block is free space */

#define PHG_AR_TMPMEM_BLOCKSIZE  20          /* size of memblock increament */


typedef enum {
    PHG_AR_WRITING_ARCHIVE,
    PHG_AR_READING_ARCHIVE
} Phg_ar_archiving_direction;

/* Archive file element definitions */
typedef struct {
    uint16_t opcode;
    uint8_t  length;
    uint8_t  pad;
} Phg_ar_begin_archive;

typedef struct {
    uint16_t opcode;
    uint8_t  pad[2];
} Phg_ar_end_archive;

typedef struct {
    uint16_t opcode;
    uint8_t  format;
    uint8_t  pad1;
    int32_t  phigs_version;
    int32_t  version;
    uint16_t length;
    uint8_t  pad2[2];
} Phg_ar_descriptor;

typedef struct {
    uint16_t opcode;
    uint8_t  pad[2];
    int32_t  id;
    uint32_t nelts;
    int32_t  length;
} Phg_ar_begin_struct;

typedef struct {
    uint16_t opcode;
    uint8_t  pad[2];
    int32_t  length;
} Phg_ar_free_space;

typedef struct {
    uint16_t opcode;
    uint8_t  pad[2];
    uint16_t numUsed;
    uint16_t numAvail;
    uint32_t nextpos;
    uint32_t length;
} Phg_ar_index;

typedef struct {
    uint8_t  type;
    uint8_t  pad[3];
    uint32_t length;
    uint32_t position;
    int32_t  str;
    uint32_t nelts;
} Phg_ar_index_entry;

typedef struct _Phg_ar_toc {
   Phg_ar_index       head;
   Phg_ar_index_entry *entry;
   struct _Phg_ar_toc *next;
} Phg_ar_toc;

typedef struct _Ar_struct {
   char              fname[PHG_MAX_NAMELEN + 1];
   Pint              arid;
   Pint              fd;
   Phg_ar_toc        *toc;
   uint8_t           format;
   uint32_t          afiOffset;
   struct _Ar_struct *next;
} Ar_struct;

typedef Ar_struct *Ar_handle;

/*******************************************************************************
 * phg_ar_open
 *
 * DESCR:       Open archive file
 * RETURNS:     N/A
 */

void phg_ar_open(
    Phg_args_ar_open *args,
    Phg_ret *ret
    );

/*******************************************************************************
 * phg_ar_close
 *
 * DESCR:       Close archive file
 * RETURNS:     N/A
 */

void phg_ar_close(
    Pint ar_id
    );

/*******************************************************************************
 * phg_ar_archive
 *
 * DESCR:       Put structure networks in archive
 * RETURNS:     N/A
 */

void phg_ar_archive(
    Phg_args_ar_info *args
    );

/*******************************************************************************
 * phg_ar_retreive
 *
 * DESCR:       Get structure networks from archive
 * RETURNS:     N/A
 */

void phg_ar_retrieve(
    Phg_args_ar_info *args
    );

/*******************************************************************************
 * phg_ar_delete
 *
 * DESCR:       Delete structure networks from archive
 * RETURNS:     N/A
 */

void phg_ar_delete(
    Phg_args_ar_info *args
    );

/*******************************************************************************
 * phg_ar_get_names
 *
 * DESCR:       Get archive catalog of names
 * RETURNS:     N/A
 */

void phg_ar_get_names(
    Pint arid,
    Phg_ret *ret
    );

/*******************************************************************************
 * phg_ar_get_hierarchy
 *
 * DESCR:       Get archive hierachy
 * RETURNS:     N/A
 */

void phg_ar_get_hierarchy(
    Phg_args_q_ar_hierarchy *args,
    Phg_ret *ret
    );

/*******************************************************************************
 * phg_inq_ar_conflicting
 *
 * DESCR:       Get list of conflicting structures in archive
 * RETURNS:     N/A
 */

void phg_inq_ar_conflicting(
    Phg_args_q_conflicting *args,
    Phg_ret *ret
    );

#endif /* _ar_h */

