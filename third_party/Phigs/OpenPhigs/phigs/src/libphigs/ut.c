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

#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <phigs/phg.h>

/*******************************************************************************
 * phg_grow_scratch
 *
 * DESCR:	Increase scratch buffer memory size
 * RETURNS:	Pointer to memory or NULL
 */

caddr_t phg_grow_scratch(
   Phg_scratch *sc,
   unsigned size
   )
{
    if ( sc->buf ) {
        if ( !( sc->buf = realloc( sc->buf, sc->size = size )) )
	    sc->size = 0;
    } else {
	if ( !( sc->buf = malloc( sc->size = size )) )
	    sc->size = 0;
    }

    return sc->buf;
}

/*******************************************************************************
 * phg_msleep
 *
 * DESCR:	Sleep in msecs granularity
 * RETURNS:	TRUE or FALSE
 */

int phg_msleep(
   unsigned msecs
   )
{
   struct timeval timeout;
   int status;

   if (msecs == 0) {
      status = TRUE;
   }
   else {
      timeout.tv_sec = msecs / 1000;           /* in secs */
      timeout.tv_usec = (msecs % 1000) * 1000; /* in micro secs */
      if (select(0, NULL, NULL, NULL, &timeout) == -1) {
         status = FALSE;
      }
      else {
         status = TRUE;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_mtime
 *
 * DESCR:	Get current time in milleseconds
 * RETURNS:	TRUE or FALSE
 */

int phg_mtime(
   time_t *tm_val
   )
{
   int status;
   struct timeval tv;

   if (gettimeofday(&tv, NULL) == 0) {
      *tm_val = tv.tv_sec * 1000 + tv.tv_usec / 1000;
      status = TRUE;
   }
   else {
      status = FALSE;
   }

   return status;
}

