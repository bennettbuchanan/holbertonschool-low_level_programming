#include "header.h"

/**
 * pop_stack - Pop the first item in a linked list.
 * @stack: The linked list to remove an item from.
 * Description: If the linked list is not NULL, move the pointer to the next
 * item and return the first string item in the linked list. If the linked
 * list is NULL, return NULL.
 */
char *pop_stack(Stack **stack)
{
	Stack *tmp = *stack;

	if (*stack != NULL)
	{
		*stack = tmp->next;
		return (tmp->str);
	}

	return (NULL);
}
