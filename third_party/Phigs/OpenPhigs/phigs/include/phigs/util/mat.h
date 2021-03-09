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

#ifndef _mat_h
#define _mat_h

#define PHG_COPY_MAT(to, from) \
   memcpy(to, from, sizeof(Pmatrix3));

int phg_mat_equal(Pfloat *a, Pfloat *b);
void phg_mat_transpose(Pmatrix3 m);
Pfloat phg_mat_trace(Pmatrix3 m);
void phg_mat_mul_pt(Pfloat *new_pt, Ppoint3 *opt, Pmatrix3 mat);
void phg_mat_mul(Pmatrix3 m , Pmatrix3 a, Pmatrix3 b);
void phg_mat_mul_3x3(Pmatrix m, Pmatrix a, Pmatrix b);
void phg_mat_zero(Pmatrix3 mat);
void phg_mat_identity(Pmatrix3 mat);
void phg_mat_translate(Pmatrix3 mat, Pvec3 *v);
void phg_mat_scale(Pmatrix3 mat, Pvec3 *v);
void phg_mat_copy(Pmatrix3 m1, Pmatrix3 m2);
void phg_mat_copy_3x3(Pmatrix m1, Pmatrix m2);
int phg_vector_equal(Pvec3 *a, Pvec3 *b);
void phg_vector_add(Pvec3 *a, Pvec3 *b, Pvec3 *c);
void phg_vector_sub(Pvec3 *a, Pvec3 *b, Pvec3 *c);
void phg_vector_scale(Pvec3 *a, Pfloat scale);
Pfloat phg_vector_dot_prod(Pvec3 *a, Pvec3 *b);
void phg_vector_cross_prod(Pvec3 *a, Pvec3 *b, Pvec3 *c);
Pfloat phg_vector_length(Pvec3 *a);
void phg_vector_normalize(Pvec3 *v);
void phg_mat_print(Pmatrix3 m);
void phg_mat_print_3x3(Pmatrix m);
void phg_mat_inv(Pmatrix3 a);
int phg_tranpt3(Ppoint3 *p, Pmatrix3 m, Ppoint3 *r);
int phg_tranpts3(Pmatrix3 m, int n, Ppoint3 *p, Ppoint3 *r);
void phg_tranpt4(Ppoint4 *p, Pmatrix3 m, Ppoint4 *r);
void phg_tranpts4(Pmatrix3 m, int n, Ppoint4 *p, Ppoint4 *r);

#endif

