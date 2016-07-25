#include "header.h"

/**
 * btree_find - Traverse a binary tree recursively until the value is found.
 *
 * @tree: The binary tree.
 * @str: The string to find in the tree.
 *
 * Description: Traverse a binary tree recursively until the value is found.
 * The node with the string, or NULL if it does not exist.
 */
BTree *btree_find(BTree *tree, char *str)
{
	if (tree == NULL)
	{
		return (NULL);
	}
	else if (strcmp(str, tree->str) == 0)
	{
		return (tree);
	}
	else
	{
		if (strcmp(str, tree->str) <= 0)
		{
			return (btree_find(tree->left, str));
		}
		return (btree_find(tree->right, str));
	}
}
