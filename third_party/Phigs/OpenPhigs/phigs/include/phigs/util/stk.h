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

#ifndef _stk_h
#define _stk_h

#include <sys/types.h>

struct _Stk;
typedef struct _Stk *Stack;

/*******************************************************************************
 * stack_create
 *
 * DESCR:       Create stack
 * RETURNS:     Stack handle or NULL
 */

Stack stack_create(
   unsigned el_size,
   unsigned el_num
   );

/*******************************************************************************
 * stack_init
 *
 * DESCR:       Initialize stack
 * RETURNS:     TRUE or FALSE
 */

int stack_init(
   Stack stack,
   unsigned el_size,
   unsigned el_num
   );

/*******************************************************************************
 * stack_destroy
 *
 * DESCR:       Destroy stack
 * RETURNS:     N/A
 */

void stack_destroy(
   Stack stack
   );

/*******************************************************************************
 * stack_push
 *
 * DESCR:       Push element on stack
 * RETURNS:     TRUE or FALSE
 */

int stack_push(
   Stack stack,
   caddr_t data
   );

/*******************************************************************************
 * stack_load
 *
 * DESCR:       Load data to element on top of stack
 * RETURNS:     TRUE or FALSE
 */

int stack_load(
   Stack stack,
   caddr_t data
   );

/*******************************************************************************
 * stack_pop
 *
 * DESCR:       Pop element from stack
 * RETURNS:     TRUE or FALSE
 */

int stack_pop(
   Stack stack,
   caddr_t data
   );

/*******************************************************************************
 * stack_peek
 *
 * DESCR:       Peek on element of top of stack
 * RETURNS:     TRUE or FALSE
 */

int stack_peek(
   Stack stack,
   caddr_t data
   );

#endif /* _stk_h */

