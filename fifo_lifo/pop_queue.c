#include "header.h"

/**
 * pop_queue - Pop first item in a linked list.
 * @queue: The linked list to remove an item from.
 * Description: If the linked list is not NULL, move the pointer to the next
 * item and return the first string item in the linked list. If the linked
 * list is NULL, return NULL.
 */
char *pop_queue(Queue **queue)
{
	Queue *tmp = *queue;

	if (*queue != NULL)
	{
		*queue = tmp->next;
		return (tmp->str);
	}

	return (NULL);
}
