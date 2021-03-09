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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <phigs/phg.h>

/*******************************************************************************
 * ptranslate3
 *
 * DESCR:       Generate 3D translation matrix
 * RETURNS:     N/A
 */

void ptranslate3(
    Pvec3 *trans_vector,       /* translation vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[0][3] = trans_vector->delta_x;
        m[1][3] = trans_vector->delta_y;
        m[2][3] = trans_vector->delta_z;
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0;
        m[0][1] = m[0][2] = m[1][0] = m[1][2] = m[2][0] = m[2][1]
                = m[3][0] = m[3][1] = m[3][2] = 0.0;
    }
}

/*******************************************************************************
 * ptranslate
 *
 * DESCR:       Generate translation matrix
 * RETURNS:     N/A
 */

void ptranslate(
    Pvec *trans_vector,        /* translation vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[0][2] = trans_vector->delta_x;
        m[1][2] = trans_vector->delta_y;
        m[0][0] = m[1][1] = m[2][2] = 1.0;
        m[0][1] = m[1][0] = m[2][0] = m[2][1] = 0.0;
    }
}

/*******************************************************************************
 * pscale3
 *
 * DESCR:       Generate 3D scaling matrix
 * RETURNS:     N/A
 */

void pscale3(
    Pvec3 *scale_vector,       /* scale factor vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[0][0] = scale_vector->delta_x;
        m[1][1] = scale_vector->delta_y;
        m[2][2] = scale_vector->delta_z;
        m[3][3] = 1.0;
        m[0][1] = m[0][2] = m[0][3]
                = m[1][0] = m[1][2] = m[1][3]
                = m[2][0] = m[2][1] = m[2][3]
                = m[3][0] = m[3][1] = m[3][2] = 0.0;
    }
}

/*******************************************************************************
 * pscale
 *
 * DESCR:       Generate scaling matrix
 * RETURNS:     N/A
 */

void pscale(
    Pvec *scale_vector,        /* scale factor vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[0][0] = scale_vector->delta_x;
        m[1][1] = scale_vector->delta_y;
        m[2][2] = 1.0;
        m[0][1] = m[0][2] = m[1][0] = m[1][2] = m[2][0] = m[2][1] = 0.0;
    }
}

/*******************************************************************************
 * protate_x
 *
 * DESCR:       Generate matrix for rotation around x-axis
 * RETURNS:     N/A
 */

void protate_x(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[1][1] = m[2][2] = cos(angle);
        m[1][2] = -(m[2][1] = sin(angle));
        m[0][0] = m[3][3] = 1.0;
        m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][3] = m[2][0] = m[2][3]
                = m[3][0] = m[3][1] = m[3][2] = 0.0;
    }
}

/*******************************************************************************
 * protate_y
 *
 * DESCR:       Generate matrix for rotation around y-axis
 * RETURNS:     N/A
 */

void protate_y(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[0][0] = m[2][2] = cos(angle);
        m[2][0] = -(m[0][2] = sin(angle));
        m[1][1] = m[3][3] = 1.0;
        m[0][1] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][1] = m[2][3]
                = m[3][0] = m[3][1] = m[3][2] = 0.0;
    }
}

/*******************************************************************************
 * protate_z
 *
 * DESCR:       Generate matrix for rotation around z-axis
 * RETURNS:     N/A
 */

void protate_z(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[0][0] = m[1][1] = cos(angle);
        m[0][1] = -(m[1][0] = sin(angle));
        m[2][2] = m[3][3] = 1.0;
        m[0][2] = m[0][3] = m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3]
                = m[3][0] = m[3][1] = m[3][2] = 0.0;
    }
}

/*******************************************************************************
 * protate
 *
 * DESCR:       Generate rotation matrix
 * RETURNS:     N/A
 */

void protate(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        m[0][0] = m[1][1] = cos(angle);
        m[0][1] = -(m[1][0] = sin(angle));
        m[2][2] = 1.0;
        m[0][2] = m[1][2] = m[2][0] = m[2][1] = 0.0;
    }
}

/*******************************************************************************
 * pcompose_matrix3
 *
 * DESCR:       Generate combined 3D transformation matrix
 * RETURNS:     N/A
 */

void pcompose_matrix3(
    Pmatrix3 a,                /* matrix a */
    Pmatrix3 b,                /* matrix b */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT result matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        phg_mat_mul(m, a, b);
    }
}


/*******************************************************************************
 * pcompose_matrix
 *
 * DESCR:       Generate combined transformation matrix
 * RETURNS:     N/A
 */

void pcompose_matrix(
    Pmatrix a,                 /* matrix a */
    Pmatrix b,                 /* matrix b */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT result matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        phg_mat_mul_3x3(m, a, b);
    }
}

/*******************************************************************************
 * ptran_point3
 *
 * DESCR:       Translate 3D point using transformation matrix
 * RETURNS:     N/A
 */

void ptran_point3(
    Ppoint3 *p,                /* point */
    Pmatrix3 m,                /* transformation matrix */
    Pint *error_ind,           /* OUT error indicator */
    Ppoint3 *r                 /* OUT transformed point */
    )
{
    /* TODO: need error code for w = 0. */
    float w;                   /* homogeneous coordinate */
    Ppoint3 t;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else if (PHG_NEAR_ZERO( w = m[3][0]*p->x + m[3][1]*p->y
                  + m[3][2]*p->z + m[3][3])) {
        *error_ind = -999;
    } else {
        *error_ind = 0;
        w = 1.0 / w;
        if (r != p) {
            r->x = w * (m[0][0] * p->x +
                        m[0][1] * p->y +
                        m[0][2] * p->z +
                        m[0][3]);
            r->y = w * (m[1][0] * p->x +
                        m[1][1] * p->y +
                        m[1][2] * p->z +
                        m[1][3]);
            r->z = w * (m[2][0] * p->x +
                        m[2][1] * p->y +
                        m[2][2] * p->z +
                        m[2][3]);
        } else {
            t.x =  w * (m[0][0] * p->x +
                        m[0][1] * p->y +
                        m[0][2] * p->z +
                        m[0][3]);
            t.y =  w * (m[1][0] * p->x +
                        m[1][1] * p->y +
                        m[1][2] * p->z +
                        m[1][3]);
            t.z =  w * (m[2][0] * p->x +
                        m[2][1] * p->y +
                        m[2][2] * p->z +
                        m[2][3]);

            r->x = t.x;
            r->y = t.y;
            r->z = t.z;
        }
    }
}

/*******************************************************************************
 * ptran_point
 *
 * DESCR:       Translate point using transformation matrix
 * RETURNS:     N/A
 */

void ptran_point(
    Ppoint *p,                 /* point */
    Pmatrix m,                 /* transformation matrix */
    Pint *error_ind,           /* OUT error indicator */
    Ppoint *r                  /* OUT transformed point */
    )
{
    /* TODO: need error code for w = 0. */
    float w;                   /* homogenous coordinate */
    Ppoint t;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else if (PHG_NEAR_ZERO( w = m[2][0] * p->x + m[2][1] * p->y + m[2][2])) {
        *error_ind = -999;
    } else {
        *error_ind = 0;
        w = 1.0 / w;
        if (p != r) {
            r->x = w * (m[0][0] * p->x +
                        m[0][1] * p->y + m[0][2]);
            r->y = w * (m[1][0] * p->x +
                        m[1][1] * p->y + m[1][2]);
        } else {
            t.x =  w * (m[0][0] * p->x +
                        m[0][1] * p->y + m[0][2]);
            t.y =  w * (m[1][0] * p->x +
                        m[1][1] * p->y + m[1][2]);

            r->x = t.x;
            r->y = t.y;
        }
    }
}

/*******************************************************************************
 * void build_transform3
 *
 * DESCR:       Generate 3D transformation matrix helper function
 * RETURNS:     N/A
 */

static void build_transform3(
    Ppoint3 *pt,               /* fixed point */
    Pvec3 *shift,              /* shift vector */
    Pfloat ax,                 /* rotation angle X */
    Pfloat ay,                 /* rotation angle Y */
    Pfloat az,                 /* rotation angle Z */
    Pvec3 *scl,                /* scale vector */
    Pmatrix3 m                 /* OUT transformation matrix */
    )
{
    /* Translate pt to the origin, scale, rotate, translate back to pt,
     * shift:
     *			T * Tf~ * Rz * Ry * Rx * S * Tf.
     *
     *    where:	T is the "shift" transform,
     *			Tf ia the translation of pt to the origin and
     *			Tf~ is it's inverse,
     *			Ri is the rotation transform about the i'th axis,
     *			S is the scaling transform.
     */
    float *r;
    float cz, sz, cx, sx, cy, sy;

    cx = cos(ax);
    sx = sin(ax);
    cy = cos(ay);
    sy = sin(ay);
    cz = cos(az);
    sz = sin(az);

    r = m[0];
    r[0] = cz * cy * scl->delta_x;
    r[1] = (cz * sx * sy - sz * cx) * scl->delta_y;
    r[2] = (cz * sy * cx + sz * sx) * scl->delta_z;
    r[3] = shift->delta_x + pt->x -
        (r[0] * pt->x + r[1] * pt->y + r[2] * pt->z);

    r = m[1];
    r[0] = sz * cy * scl->delta_x;
    r[1] = (sz * sx * sy + cz * cx) * scl->delta_y;
    r[2] = (sz * sy * cx - cz * sx) * scl->delta_z;
    r[3] = shift->delta_y + pt->y -
        (r[0] * pt->x + r[1] * pt->y + r[2] * pt->z);

    r = m[2];
    r[0] = -sy * scl->delta_x;
    r[1] = cy * sx * scl->delta_y;
    r[2] = cy * cx * scl->delta_z;
    r[3] = shift->delta_z + pt->z -
        (r[0] * pt->x + r[1] * pt->y + r[2] * pt->z);

    r = m[3];
    r[0] = r[1] = r[2] = 0.0;
    r[3] = 1.0;
}

/*******************************************************************************
 * pbuild_tran_matrix3
 *
 * DESCR:       Generate 3D transformation matrix
 * RETURNS:     N/A
 */

void pbuild_tran_matrix3(
    Ppoint3 *pt,               /* fixed point */
    Pvec3 *shift,              /* shift vector */
    Pfloat x_angle,            /* rotation angle X */
    Pfloat y_angle,            /* rotation angle Y */
    Pfloat z_angle,            /* rotation angle Z */
    Pvec3 *scale,              /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 matrix            /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
       *error_ind = 0;
       build_transform3(pt, shift, x_angle, y_angle, z_angle, scale, matrix);
    }
}

/*******************************************************************************
 * void build_transform
 *
 * DESCR:       Generate transformation matrix helper function
 * RETURNS:     N/A
 */

static void build_transform(
    Ppoint *pt,                /* fixed point */
    Pvec *shift,               /* shift vector */
    Pfloat ang,                /* rotation angle */
    Pvec *scl,                 /* scale vector */
    Pmatrix m                  /* OUT transformation matrix */
    )
{
    /* Translate pt to the origin, scale, rotate, translate back to pt,
     * shift:
     *			T * Tf~ * R * S * Tf.
     *
     *    where:	T is the "shift" transform,
     *			Tf ia the translation of pt to the origin and
     *			Tf~ is it's inverse,
     *			R is the rotation transform,
     *			S is the scaling transform.
     */
    float *r;
    float c, s;

    c = cos(ang);
    s = sin(ang);

    r = m[0];
    r[0] = c * scl->delta_x;
    r[1] = -s * scl->delta_y;
    r[2] = shift->delta_x + pt->x -
           c * scl->delta_x * pt->x + s * scl->delta_y * pt->y;

    r = m[1];
    r[0] = s * scl->delta_x;
    r[1] = c * scl->delta_y;
    r[2] = shift->delta_y + pt->y -
           (s * scl->delta_x * pt->x + c * scl->delta_y * pt->y);

    r = m[2];
    r[0] = r[1] = 0.0;
    r[2] = 1.0;
}

/*******************************************************************************
 * void build_tran_matrix
 *
 * DESCR:       Generate transformation matrix
 * RETURNS:     N/A
 */

void pbuild_tran_matrix(
    Ppoint *pt,                /* fixed point */
    Pvec *shift,               /* shift vector */
    Pfloat angle,              /* rotation angle */
    Pvec *scale,               /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix matrix             /* OUT transformation matrix */
    )
{
    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        build_transform(pt, shift, angle, scale, matrix);
    }
}

/*******************************************************************************
 * pcompose_tran_matrix3
 *
 * DESCR:       Combine 3D transformation with other transformation matrix
 * RETURNS:     N/A
 */

void pcompose_tran_matrix3(
    Pmatrix3 m,                /* transformation matrix */
    Ppoint3 *pt,               /* fixed point */
    Pvec3 *shift,              /* shift vector */
    Pfloat x_ang,              /* rotation angle X */
    Pfloat y_ang,              /* rotation angle Y */
    Pfloat z_ang,              /* rotation angle Z */
    Pvec3 *scale,              /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 result            /* OUT transformation matrix */
    )
{
    Pmatrix3 xform;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        build_transform3(pt, shift, x_ang, y_ang, z_ang, scale, xform);
        /* Assuming pre-multiplication of old by new. */
        phg_mat_mul(result, xform, m);
    }
}

/*******************************************************************************
 * pcompose_tran_matrix
 *
 * DESCR:       Combine transformation with other transformation matrix
 * RETURNS:     N/A
 */

void pcompose_tran_matrix(
    Pmatrix m,                 /* transformation matrix */
    Ppoint *pt,                /* fixed point */
    Pvec *shift,               /* shift vector */
    Pfloat angle,              /* rotation angle */
    Pvec *scale,               /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix result             /* OUT transformation matrix */
    )
{
    Pmatrix xform;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else {
        *error_ind = 0;
        build_transform( pt, shift, angle, scale, xform);
        /* Assuming pre-multiplication of old by new. */
        phg_mat_mul_3x3(result, xform, m);
    }
}

/*******************************************************************************
 * peval_view_ori_matrix3
 *
 * DESCR:       Generate 3D view orientation matrix
 * RETURNS:     N/A
 */

void peval_view_ori_matrix3(
    Ppoint3 *vrp,              /* view reference point */
    Pvec3 *vpn,                /* view plane normal */
    Pvec3 *vup,                /* view up vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT view orientation matrix */
    )
{
    /*  Translate to VRP then change the basis.
     *  The old basis is: e1 = < 1, 0, 0>,  e2 = < 0, 1, 0>, e3 = < 0, 0, 1>.
     * The new basis is: ("x" means cross product)
		e3' = VPN / |VPN|
		e1' = VUP x VPN / |VUP x VPN|
		e2' = e3' x e1'
     * Therefore the transform from old to new is x' = ATx, where:

	     | e1' 0 |         | 1 0 0 -vrp.x |
	 A = |       |,    T = | 0 1 0 -vrp.y |
	     | e2' 0 |         | 0 0 1 -vrp.z |
	     |       |         | 0 0 0    1   |
	     | e3' 0 |
	     |       |
	     | -0-  1|
     */

    /* These ei's are really ei primes. */
    Pfloat *e1 = m[0], *e3 = m[2], *e2 = m[1];
    double s, mag_vpn;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else if ( PHG_ZERO_MAG(mag_vpn = PHG_MAG_V3(vpn)) ) {
        *error_ind = ERR159;
    } else if ( PHG_ZERO_MAG(PHG_MAG_V3(vup)) ) {
        *error_ind = ERR160;
    } else {
        /* e1' = VUP x VPN / |VUP x VPN|, but do the division later. */
        e1[0] = vup->delta_y * vpn->delta_z - vup->delta_z * vpn->delta_y;
        e1[1] = vup->delta_z * vpn->delta_x - vup->delta_x * vpn->delta_z;
        e1[2] = vup->delta_x * vpn->delta_y - vup->delta_y * vpn->delta_x;
        s = sqrt(e1[0] * e1[0] + e1[1] * e1[1] + e1[2] * e1[2]);

	/* Check for vup and vpn colinear (zero dot product). */
        if ( PHG_ZERO_MAG(s) ) {
            *error_ind = ERR161;
        } else {
            *error_ind = 0;
            /* Normalize e1 */
            s = 1.0 / s;
            e1[0] *= s;
            e1[1] *= s;
            e1[2] *= s;

            /* e3 = VPN / |VPN| */
            s = 1.0 / mag_vpn;
            e3[0] = s * vpn->delta_x;
            e3[1] = s * vpn->delta_y;
            e3[2] = s * vpn->delta_z;

            /* e2 = e3 x e1 */
            e2[0] = e3[1] * e1[2] - e3[2] * e1[1];
            e2[1] = e3[2] * e1[0] - e3[0] * e1[2];
            e2[2] = e3[0] * e1[1] - e3[1] * e1[0];

            /* Add the translation */
            e1[3] = -( e1[0] * vrp->x + e1[1] * vrp->y + e1[2] * vrp->z);
            e2[3] = -( e2[0] * vrp->x + e2[1] * vrp->y + e2[2] * vrp->z);
            e3[3] = -( e3[0] * vrp->x + e3[1] * vrp->y + e3[2] * vrp->z);

            /* Homogeneous entries */
            m[3][0] = m[3][1] = m[3][2] = 0.0;
            m[3][3] = 1.0;
        }
    }
}

/*******************************************************************************
 * peval_view_ori_matrix
 *
 * DESCR:       Generate view orientation matrix
 * RETURNS:     N/A
 */

void peval_view_ori_matrix(
    Ppoint *vrp,               /* view reference point */
    Pvec *vup,                 /* view up vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT view orientation matrix */
    )
{
    /* The old basis is: e1 = < 1, 0>,  e2 = < 0, 1>
     * The new basis is: e1' = < vup.y, -vup.x> / |vup|,  e2' = vup / |vup|.
     * Therefore the transform for old to new is x' = ATx, where:

	     | e1' 0 |         | 1 0 -vrp.x |
	 A = |       |,    T = | 0 1 -vrp.y |
	     | e2' 0 |         | 0 0    1   |
	     |       |
	     | -0-  1|
     */

    double s;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else if ( PHG_ZERO_MAG(s = PHG_MAG_V2(vup)) ) {
        *error_ind = ERR160;
    } else {
        *error_ind = 0;

        /* Compute the new basis, note that m[0] is e1' and m[1] is e2'. */
        s = 1.0 / s;
        m[0][0] = s * vup->delta_y;
        m[0][1] = s * -vup->delta_x;
        m[1][0] = s * vup->delta_x;
        m[1][1] = s * vup->delta_y;

        /* Add the translation */
        m[0][2] = -( m[0][0] * vrp->x + m[0][1] * vrp->y);
        m[1][2] = -( m[1][0] * vrp->x + m[1][1] * vrp->y);

        /* Homogeneous entries */
        m[2][0] = m[2][1] = 0.0;
        m[2][2] = 1.0;
    }
}

/*******************************************************************************
 * peval_view_map_matrix3
 *
 * DESCR:       Generate 3D view mapping matrix
 * RETURNS:     N/A
 */

void peval_view_map_matrix3(
    Pview_map3 *map,           /* view mapping */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT view mapping matrix */
    )
{
    /* Procedure:
      (Perspective):
	 - Translate to PRP,			Tc
	 - Convert to left handed coords,	Tlr
	 - Shear,				H
	 - Scale to canonical view volume,	S
	 - Normalize perspective view volume,	Ntp
	 - Scale to viewport,			Svp
	 - Convert to right handed coords,	Tlr
	 - Translate to viewport,		Tvp

      (Parallel):
	 - Translate to view plane,		Tc
	 - Shear about the view plane,		H
	 - Translate back,			Tc inverse
	 - Translate window to origin,		Tl
	 - Scale to canonical view volume,	S
	 - Scale to viewport,			Svp
	 - Translate to viewport,		Tvp

	 See pevalviewmappingmatrix3_debug for the matrices.
     */

    Pfloat *r;
    Ppoint3 *prp = &map->proj_ref_point;
    Plimit3 *vp = &map->proj_vp;
    Plimit3 *win = &map->win;

    /* These are ordered roughly by the number of times used, the most
     * used is first.  Those used twice or less aren't declared register.
     */
    double sz, sx, sy;
    double zf;
    double dx = vp->x_max - vp->x_min;
    double dy = vp->y_max - vp->y_min;
    double hx, hy;
    double d;
    double dz = vp->z_max - vp->z_min;
    double vvz = map->front_plane - map->back_plane;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else if ( !(win->x_min < win->x_max) || !(win->y_min < win->y_max)) {
        *error_ind = ERR151;
    } else if ( !(vp->x_min < vp->x_max) || !(vp->y_min < vp->y_max)
        || !(vp->z_min <= vp->z_max) ) {
        *error_ind = ERR152;
    } else if ( PHG_NEAR_ZERO( vvz) && vp->z_min != vp->z_max) {
        *error_ind = ERR158;
    } else if ( map->proj_type == PTYPE_PERSPECT
        && prp->z < map->front_plane && prp->z > map->back_plane ) {
        *error_ind = ERR162;
    } else if ( prp->z == map->view_plane) {
        *error_ind = ERR163;
    } else if ( map->front_plane < map->back_plane) {
        *error_ind = ERR164;
    } else if ( !PHG_IN_RANGE( PDT_NPC_XMIN, PDT_NPC_XMAX, vp->x_min)
        || !PHG_IN_RANGE( PDT_NPC_XMIN, PDT_NPC_XMAX, vp->x_max)
        || !PHG_IN_RANGE( PDT_NPC_YMIN, PDT_NPC_YMAX, vp->y_min)
        || !PHG_IN_RANGE( PDT_NPC_YMIN, PDT_NPC_YMAX, vp->y_max)
        || !PHG_IN_RANGE( PDT_NPC_ZMIN, PDT_NPC_ZMAX, vp->z_min)
        || !PHG_IN_RANGE( PDT_NPC_ZMIN, PDT_NPC_ZMAX, vp->z_max) ) {
        *error_ind = ERR155;
    } else if ( map->proj_type == PTYPE_PERSPECT) {
        *error_ind = 0;
        d = prp->z - map->view_plane;
        sz = 1.0 / (prp->z - map->back_plane);
        sx = sz * d * 2.0 / (win->x_max - win->x_min);
        sy = sz * d * 2.0 / (win->y_max - win->y_min);
        hx = (prp->x - 0.5 * (win->x_min + win->x_max)) / d;
        hy = (prp->y - 0.5 * (win->y_min + win->y_max)) / d;

        r = m[0];
        r[0] = 0.5 * dx * sx;
        r[1] = 0.0;
        r[2] = -(0.5 * dx * (sx * hx + sz) + sz * vp->x_min);
        r[3] = -(0.5 * dx * sx * (prp->x - hx * prp->z)
            - sz * prp->z * (0.5 * dx + vp->x_min));

        r = m[1];
        r[0] = 0.0;
        r[1] = 0.5 * dy * sy;
        r[2] = -(0.5 * dy * (sy * hy + sz) + sz * vp->y_min);
        r[3] = -(0.5 * dy * sy * (prp->y - hy * prp->z)
            - sz * prp->z * (0.5 * dy + vp->y_min));

        r = m[2];
        r[0] = r[1] = 0.0;
        zf = (prp->z - map->front_plane) / (prp->z - map->back_plane);
        if ( PHG_NEAR_ZERO( 1.0 - zf)) {
            r[2] = 0.0;
            r[3] = sz * prp->z * vp->z_max;
        } else {
            r[2] = sz * ((dz / (1.0 - zf)) - vp->z_max);
            r[3] = sz * prp->z * vp->z_max - (dz/(1.0-zf)) * (sz * prp->z - zf);
        }

        r = m[3];
        r[0] = r[1] = 0.0;
        r[2] = -sz;
        r[3] = sz * prp->z;
    } else {	/* parallel */
        *error_ind = 0;
        sx = dx / (win->x_max - win->x_min);
        sy = dy / (win->y_max - win->y_min);
        hx = (prp->x - 0.5 * (win->x_min + win->x_max))
            / (map->view_plane - prp->z);
        hy = (prp->y - 0.5 * (win->y_min + win->y_max))
            / (map->view_plane - prp->z);

        r = m[0];
        r[0] = sx;
        r[1] = 0.0;
        r[2] = sx * hx;
        r[3] = vp->x_min - sx * (hx * map->view_plane + win->x_min);

        r = m[1];
        r[0] = 0.0;
        r[1] = sy;
        r[2] = sy * hy;
        r[3] = vp->y_min - sy * (hy * map->view_plane + win->y_min);

        r  = m[2];
        r[0] = r[1] = 0.0;
        if ( PHG_NEAR_ZERO(vvz)) {
            r[2] = 0.0;
        }
        else {
            r[2] = dz / vvz;
        }
        r[3] = vp->z_min - r[2] * map->back_plane;

        r = m[3];
        r[0] = r[1] = r[2] = 0.0;
        r[3] = 1.0;
    }
}

/*******************************************************************************
 * peval_view_map_matrix
 *
 * DESCR:       Generate view mapping matrix
 * RETURNS:     N/A
 */

void peval_view_map_matrix(
    Pview_map *map,            /* view mapping */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT view mapping matrix */
    )
{
    /* 1. Translate window's lower-left-corner to 0,0.
     * 2. Scale size of window to size of viewport.
     * 3. Translate 0,0 to viewport's lower-left-corner.
     *
     * Matrices are:
     * 1:  1 0 -win->xmin   2:  scale.x 0       0   3:  1 0  vp->xmin
     *     0 1 -win->ymin        0      scale.y 0       0 1  vp->ymin
     *     0 0   1               0      0       1       0 0   1
     */

    float sx, sy;              /* scale factors: len(vp) / len(win) */
    Plimit *win = &map->win;
    Plimit *vp = &map->proj_vp;

    ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

    if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
        *error_ind = ERR2;
    } else if ( !(win->x_min < win->x_max) || !(win->y_min < win->y_max)) {
        *error_ind = ERR151;
    } else if ( !(vp->x_min < vp->x_max) || !(vp->y_min < vp->y_max)) {
        *error_ind = ERR152;
    } else if ( !PHG_IN_RANGE( PDT_NPC_XMIN, PDT_NPC_XMAX, vp->x_min)
        || !PHG_IN_RANGE( PDT_NPC_XMIN, PDT_NPC_XMAX, vp->x_max)
        || !PHG_IN_RANGE( PDT_NPC_YMIN, PDT_NPC_YMAX, vp->y_min)
        || !PHG_IN_RANGE( PDT_NPC_YMIN, PDT_NPC_YMAX, vp->y_max)) {
        *error_ind = ERR155;
    } else {
        *error_ind = 0;
        sx = (vp->x_max - vp->x_min) / (win->x_max - win->x_min);
        sy = (vp->y_max - vp->y_min) / (win->y_max - win->y_min);
        m[0][0] = sx;
        m[0][1] = 0.0;
        m[0][2] = sx * (-win->x_min) + vp->x_min;

	m[1][0] = 0.0;
        m[1][1] = sy;
        m[1][2] = sy * (-win->y_min) + vp->y_min;

	m[2][0] = 0.0;
        m[2][1] = 0.0;
        m[2][2] = 1.0;
    }
}

