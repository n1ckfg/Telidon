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

#ifndef _errP_h
#define _errP_h

/*******************************************************************************
 * phg_get_funcname
 *
 * DESCR:       Get function name based on function number
 * RETURNS:     Pointer to string with function name or NULL
 */

char* phg_get_funcname(
   Pint funcnum
   );

/*******************************************************************************
 * phg_get_errmsg
 *
 * DESCR:       Get error message based on error number
 * RETURNS:     Pointer to string with error message or NULL
 */

char* phg_get_errmsg(
   Pint errnum
   );

#endif /* _errP_h */

