#include "header.h"

/**
 * path_exists - Determine if a given path exists in a tree.
 * @tree: The tree to find the path.
 * @arr: The array of strings that determines the path.
 * Description: If the array is NULL, return 0 because there can be no path.
 * If the array greater than two elements, call find_node to handle the path
 * search. If the array is one element long, simply check to see if it
 * represents the path.
 */
int path_exists(NTree *tree, char **arr)
{
	if (arr == NULL)
	{
		return (0);
	}

	if (tree != NULL && arr[1] != NULL)
	{
		return (find_node(tree, arr));
	}

	/* If the tree is a length of one and it matches, return 1. */
	if (arr[1] == NULL)
	{
		if (strcmp(tree->str, arr[0]) == 0)
		{
			return (1);
		}
	}

	return (0);
}

/**
 * find_node - Use the array to find the path.
 * @tree: The tree to find the path.
 * @arr: The array of strings that determines the path.
 * Description:	If there are no more children, the path has not been reached
 * and return 0. Otherwise, call `traverse_list` to see if the next array
 * element is in the linked list. If not found, then return NULL and the
 * function returns 0.
 */
int find_node(NTree *tree, char **arr)
{
	NTree *tmp = tree;
	int i;

	for (i = 0; arr[i + 1] != '\0'; ++i)
	{
		if (tmp->children->node == NULL)
		{
			return (0);
		}
		else
		{
			tmp = traverse_list(tmp->children, arr[i + 1]);
		}

		if (tmp == NULL)
		{
			return (0);
		}
	}

	return (1);
}

/**
 * traverse_list - Search a linked list for a string.
 * @list: The linked list.
 * @str: The string to find in the element's node.
 * Description: Traverse a linked list. If list's node has a string that
 * matches `str`, then return that node. Otherwise return NULL.
 */
NTree *traverse_list(List *list, char *str)
{
	if (strcmp(str, list->node->str) == 0)
	{
		return (list->node);
	}

	while (list->next != NULL)
	{
		list = list->next;
		if (strcmp(str, list->node->str) == 0)
		{
			return (list->node);
		}
	}

	return (NULL);
}
