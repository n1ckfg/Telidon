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

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <phigs/phg.h>
#include <phigs/util/node.h>
#include <phigs/util/list.h>
#include <phigs/util/stk.h>

typedef struct {
   Node    node;
   caddr_t data;
} SNode;

typedef struct _Stk {
   unsigned el_size;
   unsigned el_num;
   List     free_list;
   List     used_list;
} Stk;

/*******************************************************************************
 * stack_push_data
 *
 * DESCR:       Helper function push data to stack
 * RETURNS:     N/A
 */

static void stack_push_data(
   Stack stack,
   SNode *snode,
   caddr_t data
   )
{
   memcpy(snode->data, data, stack->el_size);
   list_insert(&stack->used_list, NULL, &snode->node);
}

/*******************************************************************************
 * stack_create
 *
 * DESCR:       Create stack
 * RETURNS:     Stack handle or NULL
 */

Stack stack_create(
   unsigned el_size,
   unsigned el_num
   )
{
   Stack stack;

   stack = (Stack) malloc(sizeof(Stk));
   if (stack != NULL) {
      if (!stack_init(stack, el_size, el_num)) {
         stack_destroy(stack);
         stack = NULL;
      }
   }

   return stack;
}

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
   )
{
   int status;
   unsigned i;
   SNode *snode;

   stack->el_size = el_size;
   stack->el_num  = el_num;
   list_init(&stack->free_list);
   list_init(&stack->used_list);

   for (i = 0; i < el_num; i++) {
      snode = (SNode *) malloc(sizeof(SNode) + el_size);
      if (snode == NULL) {
         status = FALSE;
         break;
      }
      else {
         snode->data = (caddr_t) &snode[1];
         list_insert(&stack->free_list, NULL, &snode->node);
         status = TRUE;
      }
   }

   return status;
}

/*******************************************************************************
 * stack_destroy
 *
 * DESCR:       Destroy stack
 * RETURNS:     N/A
 */

void stack_destroy(
   Stack stack
   )
{
   SNode *snode;

   snode = (SNode *) list_get(&stack->used_list);
   while (snode != NULL) {
      free(snode);
      snode = (SNode *) list_get(&stack->used_list);
   }

   snode = (SNode *) list_get(&stack->free_list);
   while (snode != NULL) {
      free(snode);
      snode = (SNode *) list_get(&stack->free_list);
   }

   free(stack);
}

/*******************************************************************************
 * stack_push
 *
 * DESCR:       Push element on stack
 * RETURNS:     TRUE or FALSE
 */

int stack_push(
   Stack stack,
   caddr_t data
   )
{
   int status;
   SNode *snode;

   snode = (SNode *) list_get(&stack->free_list);
   if (snode == NULL) {
      snode = (SNode *) malloc(sizeof(SNode) + stack->el_size);
      if (snode == NULL) {
         status = FALSE;
      }
      else {
         stack->el_num++;
         snode->data = (caddr_t) &snode[1];
         stack_push_data(stack, snode, data);
         status = TRUE;
      }
   }
   else {
      stack_push_data(stack, snode, data);
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * stack_load
 *
 * DESCR:       Load data to element on top of stack
 * RETURNS:     TRUE or FALSE
 */

int stack_load(
   Stack stack,
   caddr_t data
   )
{
   int status;
   SNode *snode;

   snode = (SNode *) LIST_HEAD(&stack->used_list);
   if (snode == NULL) {
      status = FALSE;
   }
   else {
      memcpy(snode->data, data, stack->el_size);
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * stack_pop
 *
 * DESCR:       Pop element from stack
 * RETURNS:     TRUE or FALSE
 */

int stack_pop(
   Stack stack,
   caddr_t data
   )
{
   int status;
   SNode *snode;

   snode = (SNode *) list_get(&stack->used_list);
   if (snode == NULL) {
      status = FALSE;
   }
   else {
      memcpy(data, snode->data, stack->el_size);
      list_insert(&stack->free_list, NULL, &snode->node);
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * stack_peek
 *
 * DESCR:       Peek on element of top of stack
 * RETURNS:     TRUE or FALSE
 */

int stack_peek(
   Stack stack,
   caddr_t data
   )
{
   int status;
   SNode *snode;

   snode = (SNode *) LIST_HEAD(&stack->used_list);
   if (snode == NULL) {
      status = FALSE;
   }
   else {
      memcpy(data, snode->data, stack->el_size);
      status = TRUE;
   }

   return status;
}

