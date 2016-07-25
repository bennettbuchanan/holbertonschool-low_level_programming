#include "header.h"

/**
 * btree_depth - Find the depth of the binary tree.
 *
 * @tree: The binary tree to find the depth of.
 *
 * Description: If the tree is NULL, return -1. Otherwise, make a recursive
 * call that returns the greater path for each split, left and right.
 */
int btree_depth(BTree *tree)
{
	int left, right;

	if (tree == NULL) /* Initial tree is NULL. */
	{
		return (-1);
	}

	left = btree_depth(tree->left);
	right = btree_depth(tree->right);

	if (left > right) {
		return left + 1;
	}
	return right + 1;
}
