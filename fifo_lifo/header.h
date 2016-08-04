#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

void print_queue(const Queue *);
void print_stack(const Stack *);
int push_queue(Queue **, char *);
void add_queue_item(Queue **, Queue *);
char *pop_queue(Queue **);
int push_stack(Stack **, char *);
void insert_stack_item(Stack **, Stack *);
char *pop_stack(Stack **);
