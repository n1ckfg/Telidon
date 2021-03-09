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

#ifndef _list_h
#define _list_h

#include <phigs/util/node.h>

/* Macros */
#define LIST_HEAD(pList) ( ((List *)(pList))->pHead)
#define LIST_TAIL(pList) ( ((List *)(pList))->pTail)
#define LIST_EMPTY(pList) ( (((List *)pList)->pHead == NULL) )

/* List type */
typedef struct listType
{
    Node *pHead;
    Node *pTail;
    int   count;
} List;

/* Callbacks */
typedef int (*ListExecCallback)(
    List *pList,
    Node *pNode,
    void *arg1
    );

/*******************************************************************************
 * list_init
 *
 * DESCR:       Initialize linked list datastruct
 * RETURNS:     N/A
 */

void list_init(
    List *pList
    );

/*******************************************************************************
 * list_insert
 *
 * DESCR:       Insert element in list
 * RETURNS:     N/A
 */

void list_insert(
    List *pList,
    Node *pPrev,
    Node *pNode
    );

/*******************************************************************************
 * list_add
 *
 * DESCR:       Add an element to the list
 * RETURNS:     N/A
 */

void list_add(
    List *pList,
    Node *pNode
    );

/*******************************************************************************
 * list_get
 *
 * DESCR:       Get Node from list
 * RETURNS:     Node
 */

Node* list_get(
    List *pList
    );

/*******************************************************************************
 * list_remove
 *
 * DESCR:       Remove an element from the list
 * RETURNS:     N/A
 */

void list_remove(
    List *pList,
    Node *pNode
    );

/*******************************************************************************
 * list_count
 *
 * DESCR:       Get number of elements in list
 * RETURNS:     Number of list elements
 */

int list_count(
    List *pList
    );

/*******************************************************************************
 * list_enqueue
 *
 * DESCR:       Enqueue item on list according to key
 * RETURNS:     N/A
 */

void list_enqueue(
    List *pList,
    Node *pNode,
    int key);

/*******************************************************************************
 * list_requeue
 *
 * DESCR:       Requeue item relative reference based on priority condition
 * RETURNS:     N/A
 */

void list_requeue(
    List *pList,
    Node *pNode,
    Node *pRef,
    NodePrio prio
    );

/*******************************************************************************
 * list_queue_unique
 *
 * DESCR:       Make all nodes in list to an have an unique key
 * RETURNS:     N/A
 */

void list_queue_unique(
    List *pList,
    int startValue
    );

/*******************************************************************************
 * list_dequeue
 *
 * DESCR:       Get node on top if key matches
 * RETURNS:     Node from queue or NULL
 */

Node* list_dequeue(
    List *pList,
    int key
    );

/*******************************************************************************
 * list_exec
 *
 * DESCR:       Execute function for each node in list
 * RETURNS:     End node
 */

Node* list_exec(
    List *pList,
    ListExecCallback exec,
    void *arg1
    );

#endif /* _list_h */

