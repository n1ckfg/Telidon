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

#ifndef _sin_qP_h
#define _sin_qP_h

#define SIN_Q_SIZE                      500

#define SIN_Q_NO_OVERFLOW               0
#define SIN_Q_OVERFLOW_NOT_INQUIRED     1
#define SIN_Q_OVERFLOW_INQUIRED         2
#define SIN_Q_OVERFLOW_WS_FLUSHED       3

typedef struct {
   Ploc3 evt;
} Sin_locator_event_data;

typedef struct {
   Ppick evt;
} Sin_pick_event_data;

typedef struct {
   Pstroke3 evt;
} Sin_stroke_event_data;

typedef struct {
   Pfloat value;
} Sin_valuator_event_data;

typedef struct {
   Pchoice evt;
} Sin_choice_event_data;

typedef struct {
   Phg_string evt;
} Sin_string_event_data;

typedef union {
   Sin_locator_event_data  locator;
   Sin_pick_event_data     pick;
   Sin_stroke_event_data   stroke;
   Sin_valuator_event_data valuator;
   Sin_choice_event_data   choice;
   Sin_string_event_data   string;
} Sin_event_data;

typedef struct _Sin_input_event {
   Pint           wsid;
   Pint           dev_num;
   Pin_class      dev_class;
   unsigned       simul_id;
   Sin_event_data data;
} Sin_input_event;

typedef struct {
   Pint            previous;
   Pint            next;
   Sin_input_event event;
} Sin_q_element;

typedef struct _Sin_event_queue {
   Pint          count;
   Pint          size;
   Pint          last;
   Pint          stack_current;
   unsigned      next_simul_id;
   unsigned      cur_simul_id;
   Pint          overflow;
   Pevent        overflow_dev;
   void          (*event_notify_proc)(void);
   int           free_stack[SIN_Q_SIZE];
   Sin_q_element events[SIN_Q_SIZE];
   Err_handle    erh;
} Sin_event_queue;

#define SIN_Q_FULL( queue) \
    ((queue)->count >= (queue)->size)

#define SIN_Q_EMPTY( queue) \
    ((queue)->count <= 0)

#define SIN_Q_ENOUGH_ROOM( queue, count) \
    ((queue)->count + (count) <= (queue)->size)

#define SIN_Q_NUM_FREE_EVENTS( queue) \
    ((queue)->size - (queue)->count)

#define SIN_Q_SET_OVERFLOW( _queue, _dev) \
    ((_queue)->overflow = SIN_Q_OVERFLOW_NOT_INQUIRED); \
    (_queue)->overflow_dev.ws = (_dev)->wsid; \
    (_queue)->overflow_dev.dev = (_dev)->num; \
    (_queue)->overflow_dev.in_class = SIN_TO_PHIGS_CLASS((_dev)->inp_class)

#define SIN_Q_CLEAR_OVERFLOW( queue) \
    ((queue)->overflow = SIN_Q_NO_OVERFLOW)

#define SIN_Q_OVERFLOWED( queue) \
    ((queue)->overflow)

#define SIN_Q_PUSH_FREE_ELEMENT( queue, index) \
    (queue)->free_stack[++(queue)->stack_current] = (index)

#define SIN_Q_POP_FREE_ELEMENT( queue) \
    (queue)->free_stack[(queue)->stack_current--]

#define SIN_Q_HEAD_EVENT( _queue ) \
    (&(_queue)->events[(_queue)->events[(_queue)->last].next].event)

#define SIN_Q_NEW_SIMUL_ID( _queue ) \
    ((_queue)->next_simul_id++)

#define SIN_Q_SET_CUR_SIMUL_ID( _queue, _event )\
    ((_queue)->cur_simul_id = (_event)->simul_id)

#define SIN_Q_MORE_SIMUL_EVENTS( _queue ) \
    (!SIN_Q_EMPTY(_queue) && SIN_Q_HEAD_EVENT(_queue)->simul_id > 0 \
        && (_queue)->cur_simul_id == SIN_Q_HEAD_EVENT(_queue)->simul_id)

/*******************************************************************************
 * phg_sin_q_enque_free_event
 *
 * DESCR:       Place a free and empty event on the queue and return a pointer 
 *              to it or NULL if the queue is full.
 * RETURNS:     Pointer to event or NULL
 */

Sin_input_event* phg_sin_q_enque_free_event(
    Sin_event_queue *queue
    );

/*******************************************************************************
 * phg_sin_q_next_event
 *
 * DESCR:       Return a pointer to the first event in the queue.
 *              The event is not dequed.  Use sin_q_deque_event() for that.
 * RETURNS:     Pointer to event or NULL
 */

Sin_input_event* phg_sin_q_next_event(
    Sin_event_queue *queue
    );

/*******************************************************************************
 * phg_sin_q_deque_event
 *
 * DESCR:       Remove the first event from the queue.
 *              Does not return the event.
 *              Use sin_q_next_event() prior to calling this function to read 
 *              the event at the head of the queue.
 * RETURNS:     N/A
 */

void phg_sin_q_deque_event(
    Sin_event_queue *queue
    );

/*******************************************************************************
 * phg_sin_q_flush_ws
 *
 * DESCR:       Flush all events on queue from a workstation.
 * RETURNS:     N/A
 */

void phg_sin_q_flush_ws(
    Sin_event_queue *queue,
    int wsid
    );

/*******************************************************************************
 * phg_sin_q_flush_device
 *
 * DESCR:       Flush all events on queue from a device.
 * RETURNS:     N/A
 */

void phg_sin_q_flush_device(
    Sin_event_queue *queue,
    Pint wsid,
    Pin_class in_class,
    Pint num
    );

/*******************************************************************************
 * phg_sin_q_create
 *
 * DESCR:       Create input queue
 * RETURNS:     Input queue handle or NULL
 */

Input_q_handle phg_sin_q_create(
    Err_handle erh
    );

/*******************************************************************************
 * phg_sin_q_destroy
 *  
 * DESCR:       Destroy input queue
 * RETURNS:     N/A
 */

void phg_sin_q_destroy(
    Sin_event_queue *queue
    );

/*******************************************************************************
 * phg_sin_q_overflow_event
 *
 * DESCR:       Get overflow event
 * RETURNS:     Overflow event id or zero
 */

int phg_sin_q_overflow_event(
    Sin_event_queue *queue,
    Pevent *event
    );

/*******************************************************************************
 * phg_sin_q_set_event_notify_proc
 *
 * DESCR:       Set event notify procedure
 * RETURNS:     N/A
 */

void phg_sin_q_set_event_notify_proc(
    Sin_event_queue *queue,
    void (*proc)(void)
    );

#endif /* _sinqP_h */

