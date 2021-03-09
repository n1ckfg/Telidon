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

#ifndef _conv_h
#define _conv_h

#include <stdint.h>

/*******************************************************************************
 * conv_swap_uint32
 *
 * DESCR:	Byte swap a long
 * RETURNS:	N/A
 */

void conv_swap_uint32(
    uint32_t *i
    );

/*******************************************************************************
 * conv_swap_uint16
 *
 * DESCR:	Byte swap a short
 * RETURNS:	N/A
 */

void conv_swap_uint16(
    uint16_t *i
    );

/*******************************************************************************
 * conv_swap_float
 *
 * DESCR:	Byte swap a float
 * RETURNS:	N/A
 */

void conv_swap_float(
    float *f
    );

/*******************************************************************************
 * conv_vax_to_ieee
 * 
 * DESCR:	Convert floating point in VAX format to IEEE format
 * RETURNS:	N/A
 */

void conv_vax_to_ieee(
    float *f
    );

/*******************************************************************************
 * conv_ieee_to_vax
 * 
 * DESCR:	Convert IEEE floating point number to VAX format
 * RETURNS:	N/A
 */
    
void conv_ieee_to_vax(
    float *f
    );

/*******************************************************************************
 * conv_swap_ieee_to_vax
 *
 * DESCR:	Byte swap and convert a float
 * RETURNS:	N/A
 */

void conv_swap_ieee_to_vax(
    float *f
    );

/*******************************************************************************
 * conv_swap_vax_to_ieee
 *
 * DESCR:	Byte swap and convert a float
 * RETURNS:	N/A
 */

void conv_swap_vax_to_ieee(
    float *f
    );

#endif /* _conv_h */

