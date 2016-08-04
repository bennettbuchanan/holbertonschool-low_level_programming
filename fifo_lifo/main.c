#include "header.h"

/* The function 'print_queue' is provided */
void print_queue(const Queue *);

int push_queue(Queue **, char *);
char *pop_queue(Queue **);

int main(int ac, char **av)
{
        Queue *queue;
        int i;
        char *str;

        queue = NULL;
        i = 0;
        while (i < ac)
        {
                push_queue(&queue, av[i]);
                ++i;
        }
        print_queue(queue);
        str = pop_queue(&queue);
        printf("%s\n", str);
        print_queue(queue);
        str = pop_queue(&queue);
        printf("%s\n", str);
        print_queue(queue);
        str = pop_queue(&queue);
        printf("%s\n", str);
        print_queue(queue);
        return (0);
}
