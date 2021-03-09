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
#include <phigs/phg.h>
#include <phigs/util/list.h>

/*******************************************************************************
 * list_init
 *
 * DESCR:	Initialize linked list datastruct
 * RETURNS:	N/A
 */

void list_init(
    List *pList
    )
{
    pList->pHead = NULL;
    pList->pTail = NULL;
    pList->count = 0;
}

/*******************************************************************************
 * list_insert
 *
 * DESCR:	Insert element in list
 * RETURNS:	N/A
 */

void list_insert(
    List *pList,
    Node *pPrev,
    Node *pNode
    )
{
    Node *pNext;
  
    if (pPrev == NULL) {
        pNext = pList->pHead;   /* Put node at beginnig of list */
        pList->pHead = pNode;
    }
    else {
        pNext = pPrev->pNext;   /* next points to previous next */
        pPrev->pNext = pNode;
    }

    if (pNext == NULL)
    {
        pList->pTail = pNode;   /* Put node at end of list */
    }
    else
    {
        pNext->pPrev = pNode;   /* next previous points to node */
    }

    /* Setup pointers */
    pNode->pNext = pNext;
    pNode->pPrev = pPrev;

    pList->count++;
}

/*******************************************************************************
 * list_add
 *
 * DESCR:	Add an element to the list
 * RETURNS:	N/A
 */

void list_add(
    List *pList,
    Node *pNode
    )
{
    list_insert(pList, pList->pTail, pNode);
}

/*******************************************************************************
 * list_get
 *
 * DESCR:	Get Node from list
 * RETURNS:	Node
 */

Node* list_get(
    List *pList
    )
{
    Node *pNode;

    pNode = pList->pHead;
    if (pNode != NULL)
    {
        pList->pHead = pNode->pNext;

        if (pNode->pNext == NULL)
        {
            pList->pTail = NULL;
        }
        else
        {
            pNode->pNext->pPrev = NULL;
        }

      pList->count--;
    }

    return pNode;
}

/*******************************************************************************
 * list_remove
 *
 * DESCR:	Remove an element from the list
 * RETURNS:	N/A
 */

void list_remove(
    List *pList,
    Node *pNode
    )
{
    /* Is this the first node? */
    if (pNode->pPrev == NULL)
    {
        pList->pHead = pNode->pNext;
    }
    else
    {
        pNode->pPrev->pNext = pNode->pNext;
    }

    /* Is this the last node? */
    if (pNode->pNext == NULL)
    {
        pList->pTail = pNode->pPrev;
    }
    else
    {
        pNode->pNext->pPrev = pNode->pPrev;
    }

    pList->count--;
}

/*******************************************************************************
 * list_count
 *
 * DESCR:	Get number of elements in list
 * RETURNS:	Number of list elements
 */

int list_count(
    List *pList
    )
{
    return pList->count;
}

/*******************************************************************************
 * list_enqueue
 *
 * DESCR:	Enqueue item on list according to key
 * RETURNS:	N/A
 */

void list_enqueue(
    List *pList,
    Node *pNode,
    int key)
{
    Node *pCurr;
    int done;

    pCurr = pList->pHead;
    done = FALSE;

    while ((pCurr != NULL) &&
           (done == FALSE))
    {
        if (key < pCurr->key)
        {
            list_insert(pList, pCurr->pPrev, pNode);
            pNode->key = key;
            done = TRUE;
        }

        /* Advance */
        pCurr = pCurr->pNext;

    }

    if (done == FALSE)
    {
        list_add(pList, pNode);
        pNode->key = key;
    }
}

/*******************************************************************************
 * list_requeue
 *
 * DESCR:	Requeue item relative reference based on priority condition
 * RETURNS:	N/A
 */

void list_requeue(
    List *pList,
    Node *pNode,
    Node *pRef,
    NodePrio prio
    )
{
#ifdef DEBUG
    printf("Node: %d\n"
           "Ref: %d\n",
           pNode->key,
           pRef->key);
#endif

    /* Set node priority lower than reference */
    if (prio == NODE_PRIO_LOWER) {

        /* If priority is higher than reference */
        if (pNode->key < pRef->key) {
            list_remove(pList, pNode);

#ifdef DEBUG
            printf("Old prio: %d\n", pNode->key);
#endif

            /* Set priority one unit higher than reference */
            pNode->key = pRef->key + 1;

#ifdef DEBUG
            printf("New prio: %d\n", pNode->key);
#endif

            /* Node should be placed after reference */
            list_insert(pList, pRef, pNode);
        }

        /* Nothing to do, priority already lower than reference */
    }

    /* Set node priority higher than reference */
    else {

        /* If priority is lower than reference */
        if (pNode->key > pRef->key) {
            list_remove(pList, pNode);

#ifdef DEBUG
            printf("Old prio: %d\n", pNode->key);
#endif

            /* Do not allow negative key */
            if ((pRef->key - 1) < 0) {
                pNode->key = 0;
            }
            else {
                pNode->key = pRef->key - 1;
            }

#ifdef DEBUG
            printf("New prio: %d\n", pNode->key);
#endif

            /* Node should be placed before reference */
            list_insert(pList, NODE_PREV(pRef), pNode);
        }

        /* Nothing to do, priority already higher than reference */
    }
}

/*******************************************************************************
 * list_queue_unique
 *
 * DESCR:	Make all nodes in list to an have an unique key
 * RETURNS:	N/A
 */

void list_queue_unique(
    List *pList,
    int startValue
    )
{
    int key;
    Node *pNode;

    key = startValue;

    for (pNode = LIST_HEAD(pList);
         pNode != NULL;
         pNode = NODE_NEXT(pNode)) {
        pNode->key = key++;
    }
}

/*******************************************************************************
 * list_dequeue
 *
 * DESCR:	Get node on top if key matches
 * RETURNS:	Node from queue or NULL
 */

Node* list_dequeue(
    List *pList,
    int key
    )
{
    Node *pNode;

    pNode = pList->pHead;
    if (pNode != NULL)
    {
        if (key == pNode->key)
        {
            list_remove(pList, pNode);
        }
        else
        {
            pNode = NULL;
        }
    }

    return pNode;
}

/*******************************************************************************
 * list_exec
 *
 * DESCR:	Execute function for each node in list
 * RETURNS:	End node
 */

Node* list_exec(
    List *pList,
    ListExecCallback exec,
    void *arg1
    )
{
    Node *pNode, *pNext;

    pNode = pList->pHead;
    while (pNode != NULL)
    {
        pNext = pNode->pNext;
        if ((*exec)(pList, pNode, arg1) == FALSE)
        {
            break;
        }
        pNode = pNext;
    }

    return pNode;
}

