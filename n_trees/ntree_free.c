#include "header.h"

/**
 * free_node - Frees a node.
 * @tree: The current node in the tree.
 * Description: If the tree is not null, call `free_node`; For the child
 * element, call `free_list`, then free the node's allocated memory.
 */
void ntree_free(NTree *tree)
{
	if (tree != NULL)
	{
		free_list(tree->children);

		free(tree->str);
		free(tree->children);
		free(tree);
	}
}

/**
 * free_list - Travere a list free list structs.
 * @list: The list to traverse.
 * Description: For every list struct, call `free_node`, then free the list
 * struct itself. If traversal occurred, then free the list at the end.
 * Otherwise the `free_node` function will handle that list item.
 */
void free_list(List *list)
{
	int t = 0;
	List *tmp;

	while (list->next != NULL)
	{
		tmp = list;
		ntree_free(list->node);
		list = list->next;
		if (t > 0)
		{
			free(tmp);
		}
		++t;
	}

	if (list->node != NULL)
	{
		ntree_free(list->node);
	}

	if (list->next == NULL && t > 0)
	{
		free(list);
	}
}
