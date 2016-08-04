#include "header.h"

/**
 * push_queue - Add queue item.
 * @queue: The array of queue items.
 * @str: The string to add to a queure structure.
 * Description: Allocates memory for a new item and assigns the values to the
 * structure. Calls `add_queue_item()` to place the newly allocated struct in
 * the linked list.
 */
int push_queue(Queue **queue, char *str)
{
        Queue *item;

        item = malloc(sizeof(Queue));
        if (item == NULL)
        {
                return (1);
        }

        item->str = strdup(str);
        item->next = NULL;

        add_queue_item(queue, item);

        return(0);
}

/**
 * add_queue_item - Add item to linked list.
 * @queue: The array of queue items.
 * @item: The item to add to the linked list.
 * Description: If the linked list has no items (i.e., it is NULL), then add
 * the item as the first. Otherwise traverse the linked list and add the new
 * item at the end of the queue.
 */
void add_queue_item(Queue **queue, Queue *item)
{
        Queue *tmp = *queue;

        if (*queue == NULL)
        {
                *queue = item;
        }
        else
        {
                while (tmp->next != NULL)
                {
                        tmp = tmp->next;
                }

                tmp->next = item;
        }
}
