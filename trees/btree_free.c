#include "header.h"

/**
 * btree_free - Frees nodes in a binary tree.
 *
 * @tree: The binary tree to free.
 *
 * Description: Calls this function recursively if the node's left or right
 * values are not NULL, then frees the current node.
 */
void btree_free(BTree *tree)
{
	if (tree->left != NULL)
	{
		btree_free(tree->left);
	}
	if (tree->right != NULL)
	{
		btree_free(tree->right);
	}

	if (tree != NULL) /* Initial tree is NULL. */
	{
		free(tree->str);
		free(tree);
	}
}
