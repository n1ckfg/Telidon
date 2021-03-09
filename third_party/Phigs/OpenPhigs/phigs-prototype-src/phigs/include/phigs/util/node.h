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

#ifndef _node_h
#define _node_h

/* Macros */
#define NODE_NEXT(pNode) ( ((Node *)(pNode))->pNext)
#define NODE_PREV(pNode) ( ((Node *)(pNode))->pPrev)

typedef enum {
    NODE_PRIO_LOWER,
    NODE_PRIO_HIGHER
} NodePrio;

/* Node type */
typedef struct nodeType
{
    struct nodeType *pNext;
    struct nodeType *pPrev;
    int             key;
} Node;

#endif /* _node_h */

