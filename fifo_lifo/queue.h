#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct Queue
{
    char *str;
    struct Queue *next;
} Queue;

#endif
