#include "header.h"

/**
 * ntree_insert - Insert a node in a tree.
 * @tree: The tree to build.
 * @arr: The array representing the path of the tree.
 * @str: The string to insert into the path.
 * Description:	Allocates memory for a new node and list. Calls the node
 * handler function if the tree already has a root node. Otherwise it simply
 * creates the root node. Returns 0 on success, 1 upon failure.
 */
int ntree_insert(NTree **tree, char **arr, char *str)
{
	NTree *node;
	List *list;

	if (str == NULL)
	{
		return (0);
	}

	node = malloc(sizeof(NTree));
	if (node == NULL)
	{
		return (1);
	}

	list = malloc(sizeof(List));
	if (list == NULL)
	{
		return (1);
	}

	node->str = strdup(str);
	node->children = list;
	node->children->node = NULL;
	node->children->next = NULL;

	if (*tree != NULL)
	{
		return (handle_node(tree, node, arr));
	}
	else
	{
		*tree = node;
	}

	return (0);
}

/**
 * handle_node - Handles the insertion of a node.
 * @tree: The tree to be inserted into.
 * @node: The node to be inserted.
 * @arr: The array path designating the location to insert the node.
 * Description: Inserts a node if it is an immediate child of the series of
 * parent nodes. Otherwise this function calls `add_list()` to traverse the
 * linked list of preexisting child nodes, and adds the node accordingly.
 */
int handle_node(NTree **tree, NTree *node, char **arr)
{
	NTree *tmp = *tree;
	NTree *tmp1 = *tree;
	int i;

	for (i = 0; arr[i] != '\0'; ++i)
	{
		if (tmp->children->node == NULL)
		{
			tmp->children->node = node;
			break;
		}
		else
		{
			if (arr[i + 1] != NULL)
			{
				tmp = trav_list(tmp->children, arr[i + 1]);
			}
			else
			{
				tmp = NULL;
			}
		}
		if (tmp != NULL)
		{
			tmp1 = tmp;
		}
		else
		{
			if (add_list(tmp1, node) == 1)
			{
				return (1);
			}
			break;
		}
	}

	return (0);
}

/**
 * add_list - Add a list to children->next.
 * @tmp1: The current node of the tree that is the immediate parent.
 * @node: The child node to be added as a child of tmp1.
 * Description:	Allocates memory for a new list and redirects the current
 * pointer to the child linked list to this list, making it the new first item
 * in the linked list. Returns 1 upon failure, 0 upon success.
 */
int add_list(NTree *tmp1, NTree *node)
{
	List *list;

	list = malloc(sizeof(List));
	if (list == NULL)
	{
		return (1);
	}

	list->node = node;
	list->next = NULL;

	/* If the list is empty, add list to next. */
	if (tmp1->children == NULL)
	{
		tmp1->children = list;
	}
	else
	{
		list->next = tmp1->children;
		tmp1->children = list;
	}
	return (0);
}

/**
 * trav_list - Traverses a list to find any matching node.
 * @list: The linked list to traverse.
 * @str: The string to find as a matching item.
 * Description: Finds a node with a matching string it if exists in the linked
 * list. In this case, it returns a pointer to this node. Otherwise this
 * function returns NULL.
 */
NTree *trav_list(List *list, char *str)
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
