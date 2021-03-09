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

Copyright (c) 1989,1990, 1991  X Consortium

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

Copyright (c) 1989,1990, 1991 by Sun Microsystems, Inc.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Sun Microsystems,
and the X Consortium, not be used in advertising or publicity 
pertaining to distribution of the software without specific, written 
prior permission.  

SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, 
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT 
SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL 
DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

/* Initialise css */

#include <stdlib.h>
#include <phigs/phg.h>
#include <phigs/css.h>
#include <phigs/private/phgP.h>
#include <phigs/private/hdlP.h>
#include <phigs/private/cssP.h>

#define CSS_STAB_SIZE		1009
#define CHOICE_POPUP_STAB_SIZE	5

/*******************

    phg_css_init - initialise css data, tables, etc.

*******************/

Css_handle phg_css_init(Err_handle erh, Css_ssh_type ssh_type)
{
    Css_handle	cssh;
    Css_func	*fptr;
   
    if ( !(cssh = (Css_handle) calloc((unsigned)1,sizeof(Css_struct))) )
        return(NULL);					/* out of memory */
    fptr = cssh->el_funcs;
    fptr[(int)PELEM_NIL] = phg_css_no_data;
    fptr[(int)PELEM_ADD_NAMES_SET] = hdl_generic_elmt;
    fptr[(int)PELEM_REMOVE_NAMES_SET] = hdl_generic_elmt;
    fptr[(int)PELEM_FILL_AREA] = hdl_generic_elmt;
    fptr[(int)PELEM_FILL_AREA3] = hdl_generic_elmt;
    fptr[(int)PELEM_FILL_AREA_SET] = hdl_generic_elmt;
    fptr[(int)PELEM_FILL_AREA_SET3] = hdl_generic_elmt;
    fptr[(int)PELEM_FILL_AREA_SET3_DATA] = hdl_generic_elmt;
    fptr[(int)PELEM_SET_OF_FILL_AREA_SET3_DATA] = hdl_generic_elmt;
    fptr[(int)PELEM_POLYLINE] = hdl_generic_elmt;
    fptr[(int)PELEM_POLYLINE3] = hdl_generic_elmt;
    fptr[(int)PELEM_POLYMARKER] = hdl_generic_elmt;
    fptr[(int)PELEM_POLYMARKER3] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT] = hdl_generic_elmt;
    fptr[(int)PELEM_INT_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_INT_COLR_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_INT_STYLE] = hdl_generic_elmt;
    fptr[(int)PELEM_BACK_INT_STYLE] = hdl_generic_elmt;
    fptr[(int)PELEM_INT_STYLE_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_BACK_INT_STYLE_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_LINE_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_LINE_COLR_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_LINEWIDTH] = hdl_generic_elmt;
    fptr[(int)PELEM_LINETYPE] = hdl_generic_elmt;
    fptr[(int)PELEM_MARKER_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_MARKER_COLR_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_MARKER_SIZE] = hdl_generic_elmt;
    fptr[(int)PELEM_MARKER_TYPE] = hdl_generic_elmt;
    fptr[(int)PELEM_EDGE_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_EDGE_COLR_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_EDGEWIDTH] = hdl_generic_elmt;
    fptr[(int)PELEM_EDGETYPE] = hdl_generic_elmt;
    fptr[(int)PELEM_EDGE_FLAG] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT_FONT] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT_PREC] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT_PATH] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT_ALIGN] = hdl_generic_elmt;
    fptr[(int)PELEM_CHAR_HT] = hdl_generic_elmt;
    fptr[(int)PELEM_CHAR_EXPAN] = hdl_generic_elmt;
    fptr[(int)PELEM_CHAR_SPACE] = hdl_generic_elmt;
    fptr[(int)PELEM_CHAR_UP_VEC] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT_COLR_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_INDIV_ASF] = hdl_generic_elmt;
    fptr[(int)PELEM_LOCAL_MODEL_TRAN3] = hdl_generic_elmt;
    fptr[(int)PELEM_GLOBAL_MODEL_TRAN3] = hdl_generic_elmt;
    fptr[(int)PELEM_VIEW_IND] = hdl_generic_elmt;
    fptr[(int)PELEM_EXEC_STRUCT] = phg_css_struct_ref;
    fptr[(int)PELEM_LABEL] = hdl_generic_elmt;
    fptr[(int)PELEM_PICK_ID] = hdl_generic_elmt;
    fptr[(int)PELEM_HLHSR_ID] = hdl_generic_elmt;
    fptr[(int)PELEM_INT_COLR] = hdl_generic_elmt;
    fptr[(int)PELEM_BACK_INT_COLR] = hdl_generic_elmt;
    fptr[(int)PELEM_LINE_COLR] = hdl_generic_elmt;
    fptr[(int)PELEM_MARKER_COLR] = hdl_generic_elmt;
    fptr[(int)PELEM_EDGE_COLR] = hdl_generic_elmt;
    fptr[(int)PELEM_TEXT_COLR] = hdl_generic_elmt;
    fptr[(int)PELEM_LIGHT_SRC_STATE] = hdl_generic_elmt;
    fptr[(int)PELEM_INT_SHAD_METH] = hdl_generic_elmt;
    fptr[(int)PELEM_BACK_INT_SHAD_METH] = hdl_generic_elmt;
    fptr[(int)PELEM_INT_REFL_EQN] = hdl_generic_elmt;
    fptr[(int)PELEM_BACK_INT_REFL_EQN] = hdl_generic_elmt;
    fptr[(int)PELEM_REFL_PROPS] = hdl_generic_elmt;
    fptr[(int)PELEM_BACK_REFL_PROPS] = hdl_generic_elmt;
    fptr[(int)PELEM_FACE_DISTING_MODE] = hdl_generic_elmt;
    fptr[(int)PELEM_FACE_CULL_MODE] = hdl_generic_elmt;

    if ( !(cssh->stab = phg_css_stab_init(CSS_STAB_SIZE)) ) {
	free((char *)cssh);
	return(NULL);					/* out of memory */
    }
    cssh->open_struct = NULL;
    cssh->el_ptr = NULL;
    cssh->el_index = 0;
    cssh->edit_mode = PEDIT_INSERT;
    cssh->erh = erh;
    if ( !(cssh->ws_list = (Css_ws_list)
	    malloc((MAX_NO_OPEN_WS+1) * sizeof(Css_ws_on))) ) {
	phg_css_stab_free(cssh->stab);
	free((char *)cssh);
	return(NULL);					/* out of memory */
    }
    cssh->mem = NULL;		/* don't allocate space until it's needed */
    cssh->ssh_type = ssh_type;
    return(cssh);   
}

/*******************

    phg_css_destroy - free memory used by css

*******************/

void phg_css_destroy(Css_handle cssh)
{
    phg_css_delete_all_structs(cssh);
    phg_css_stab_free(cssh->stab);
    free((char *)cssh->ws_list);
    if (cssh->mem)
	free(cssh->mem);
    free((char *)cssh);
}

