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
#include <phigs/phg.h>
#include <phigs/util.h>
#include <phigs/ar.h>
#include <phigs/private/arP.h>

/* For in place conversions which happen in this file */
#define CONVERT_UINT32(swp, val) \
    if ((swp)->conv_long)  ((*(swp)->conv_long)((uint32_t *) &(val))) 

#define CONVERT_UINT16(swp, val) \
    if ((swp)->conv_short)  ((*(swp)->conv_short)((uint16_t *) &(val))) 

static Phg_swap  clientSwapStructure;	
static Phg_swap  *swp = &clientSwapStructure;

static int fromFormat;
static int toFormat;

typedef struct {
    Phg_conv_short s;          /* Function to convert a short */
    Phg_conv_long  l;          /* Function to convert a long */
    Phg_conv_float f;          /* Function to convert a float */
} ThreeFuncs;

static ThreeFuncs ConversionFunction[4][4] = {
	{   /* From Big Endian Ieee */
	    { 0, 0, 0 },
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_float },
	    { 0, 0, conv_ieee_to_vax },
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_ieee_to_vax }
	},
	{
	    /* From Big Endian DecF */
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_float },
	    { 0, 0, 0 },
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_ieee_to_vax },
	    { 0, 0, conv_ieee_to_vax }
	},
	{
	    /* From Little Endian Ieee */
	    { 0, 0, conv_vax_to_ieee },
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_vax_to_ieee },
	    { 0, 0, 0 },
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_float }
	},
	{
	    /* From Little Endian DecF */
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_vax_to_ieee },
	    { 0, 0, conv_vax_to_ieee },
	    { conv_swap_uint16, conv_swap_uint32, conv_swap_float },
	    { 0, 0, 0 }
	}
};


/******************************************************************************
 * phg_ar_set_conversion
 *
 * DESCR:	Set conversion function
 * RETURNS:	N/A
 */

void phg_ar_set_conversion(
    int from,
    int to
    )
{
    toFormat = to;
    fromFormat = from;
    
    swp->conv_short = ConversionFunction[from][to].s;
    swp->conv_long  = ConversionFunction[from][to].l;
    swp->conv_float = ConversionFunction[from][to].f;
}

/******************************************************************************
 * phg_ar_convert_afd
 *
 * DESCR:	Convert Archive File Descriptor
 * RETURNS:	N/A
 */

void phg_ar_convert_afd(
    Phg_ar_descriptor *d
    )
{
    d->opcode = PHG_AR_AFD;
    CONVERT_UINT32(swp, d->phigs_version);
    CONVERT_UINT32(swp, d->version);
    CONVERT_UINT16(swp, d->length);
}

/******************************************************************************
 * phg_ar_convert_bse
 *
 * DESCR:	Convert Archive Begin Structure
 * RETURNS:	N/A
 */

void phg_ar_convert_bse(
    Phg_ar_begin_struct *b
    )
{
    b->opcode = PHG_AR_BSE;
    CONVERT_UINT32(swp, b->id);
    CONVERT_UINT32(swp, b->nelts);
    CONVERT_UINT32(swp, b->length);
}

/******************************************************************************
 * phg_ar_convert_afs
 *
 * DESCR:	Convert Archive Free Space
 * RETURNS:	N/A
 */

void phg_ar_convert_afs(
    Phg_ar_free_space *f
    )
{
    f->opcode = PHG_AR_AFS;
    CONVERT_UINT32(swp, f->length);
}

/******************************************************************************
 * phg_ar_convert_afi
 *
 * DESCR:	Convert Archive Index
 * RETURNS:	N/A
 */

void phg_ar_convert_afi(
    Phg_ar_index *index
    )
{
    index->opcode = PHG_AR_AFI;
    CONVERT_UINT16(swp, index->numUsed);
    CONVERT_UINT16(swp, index->numAvail);
    CONVERT_UINT32(swp, index->nextpos);
    CONVERT_UINT32(swp, index->length);
}

/******************************************************************************
 * phg_ar_convert_afie
 *
 * DESCR:	Convert Archive Index Entries
 * RETURNS:	N/A
 */

void phg_ar_convert_afie(
    int n,
    Phg_ar_index_entry *e
    )
{
    int i;

    for (i = 0; i < n; i++) {
    	CONVERT_UINT32(swp, (e[i].length));
    	CONVERT_UINT32(swp, (e[i].position));
    	CONVERT_UINT32(swp, (e[i].str));
    	CONVERT_UINT32(swp, (e[i].nelts));
    }
}

/******************************************************************************
 * phg_ar_convert_elements
 *
 * DESCR:	Convert Archive Elements
 * RETURNS:	N/A
 */

void phg_ar_convert_elements(
    int nelts,
    char *buffer,
    Phg_ar_archiving_direction direction
    )
{
    char *ptr = buffer;
    Phg_elmt_info *head;
    int command;
    uint16_t type;
    uint16_t length;
    void (*localswapshort)(uint16_t *);

    /* if the formats are there are no conversions that will need to be
     * performed, then just return */
     
    if (!(swp->conv_short) && !(swp->conv_long) && !(swp->conv_float))
	return;
	

    localswapshort = ConversionFunction[fromFormat][PHG_AR_HOST_BYTE_ORDER |
						  PHG_AR_HOST_FLOAT_FORMAT].s;

    /* For each element in the structure */
    for (command = 0; command < nelts; command++) {
    
	head = (Phg_elmt_info *) ptr;

	if (direction == PHG_AR_READING_ARCHIVE) {
	
	    /* we are reading fram an archive so we must 'decode' */
	    if (localswapshort != NULL) {
		(*localswapshort)(&head->elementType);
		type = head->elementType;
		(*localswapshort)(&head->length);
		length = head->length;
	    } else {
		type = head->elementType;
		length = head->length;
	    }
#ifdef TODO
	    (*cPEXOutputCmd[type])(swp, ptr);
#endif
	    
	} else {
	
	    /* we are writing to an archive, so we must 'encode' */
	    type = head->elementType;
	    length = head->length;
#ifdef TODO
	    (*uPEXOutputCmd[type])(swp, ptr);
#endif
	    
	}
	
	ptr += length * sizeof(uint32_t);
    }
}

