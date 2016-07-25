#include "header.h"

/**
 * btree_depth - Find the depth of the binary tree.
 *
 * @tree: The binary tree to find the depth of.
 *
 * Description: If the tree is NULL, return -1. Otherwise, make a recursive
 * call, adding 1 for one level until both left and right nodes are NULL.
 */
int btree_depth(BTree *tree)
{
	if (tree == NULL) /* Initial tree is NULL. */
	{
		return (-1);
	}
	else
	{
		if (tree->left != NULL)
		{
			return (btree_depth(tree->left) + 1);
		}
		if (tree->right != NULL)
		{
			return (btree_depth(tree->right) + 1);
		}
	}
	return (0);
}
