#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

void print_queue(const Queue *);
int push_queue(Queue **, char *);
void add_queue_item(Queue **, Queue *);
char *pop_queue(Queue **);
