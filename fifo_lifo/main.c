#include <stdlib.h>
#include "queue.h"
#include "header.h"

int main(int ac, char **av)
{
        Queue *queue;
        int i;

        queue = NULL;
        i = 0;
        while (i < ac)
        {
                push_queue(&queue, av[i]);
                ++i;
        }
        print_queue(queue);
        return (0);
}
