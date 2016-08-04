#ifndef _STACK_H_
#define _STACK_H_

typedef struct Stack
{
    char *str;
    struct Stack *next;
} Stack;

#endif
