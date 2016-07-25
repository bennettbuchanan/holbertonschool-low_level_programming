#include "header.h"

/**
 * array_to_btree - Convert an array to a binary tree.
 *
 * @array: An array of strings.
 *
 * Description: Takes an array of strings and calls `btree_insert()` to insert
 * each array item into the newly created tree. Return the newly created
 * binary tree.
 */
BTree *array_to_btree(char **array)
{

	BTree *tree = NULL;
	int i;

	for (i = 0; array[i] != '\0'; ++i)
	{
		btree_insert(&tree, array[i]);
	}

	return (tree);
}
