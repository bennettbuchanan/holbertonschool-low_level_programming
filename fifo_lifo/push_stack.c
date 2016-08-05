#include "header.h"

/**
 * push_stack - Add stack item.
 * @stack: The array of stack items.
 * @str: The string to add to a queure structure.
 * Description: Allocates memory for a new item and assigns the values to the
 * structure. Calls `insert_stack_item()` to place the newly allocated struct in
 * the linked list.
 */
int push_stack(Stack **stack, char *str)
{
	Stack *item;

	item = malloc(sizeof(Stack));
	if (item == NULL)
	{
		return (1);
	}

	item->str = strdup(str);
	item->next = NULL;

	insert_stack_item(stack, item);

	return (0);
}

/**
 * insert_stack_item - Add item to linked list.
 * @stack: The array of stack items.
 * @item: The item to add to the linked list.
 * Description: If the linked list has no items (i.e., it is NULL), then add
 * the item as the first. Otherwise traverse the linked list and add the new
 * item at the end of the stack.
 */
void insert_stack_item(Stack **stack, Stack *item)
{
	Stack *tmp = *stack;

	if (*stack == NULL)
	{
		*stack = item;
	}
	else
	{
		item->next = tmp;
		*stack = item;
	}
}
