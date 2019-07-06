/*
 * Copyright 2018 NXP
 *
 * include/queue.h
 *
 * Author Ming Qian<ming.qian@nxp.com>
 */
#ifndef _INCLUDE_QUEUE_H
#define _INCLUDE_QUEUE_H
#ifdef __cplusplus
extern "C"
{
#endif

typedef void *Queue;
typedef int (*queue_callback)(unsigned long item, void *arg);

Queue pitcher_init_queue(void);
void pitcher_destroy_queue(Queue q);
int pitcher_queue_push_back(Queue q, unsigned long item);
int pitcher_queue_pop(Queue q, unsigned long *item);
void pitcher_queue_clear(Queue q, queue_callback func, void *arg);
/*queue_callback retuen 0: keep item in queue, others: remove it from queue*/
void pitcher_queue_enumerate(Queue q, queue_callback func, void *arg);
int pitcher_queue_is_empty(Queue q);
long pitcher_queue_count(Queue q);
int pitcher_queue_find(Queue q, queue_callback func, void *arg,
		int (*compeare)(unsigned long item, unsigned long key),
		unsigned long key);
#ifdef __cplusplus
}
#endif
#endif
