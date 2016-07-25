#include <stdlib.h>
#include <string.h>
#include "tree.h"

BTree *new_node(char *data);

/**
 * btree_insert - Insert a new node in a binary tree. Makes a recursive call
 * function based on value.
 *
 * @tree: The binary tree to insert the node into.
 * @data: The data string to be inserted.
 *
 * Description: Insert a new node in a binary tree. Makes a recursive call
 * function based on value. Returns 1 if the memory allocation fails, 0 upon
 * successful insertion.
 */
int btree_insert(BTree **tree, char *data)
{
	BTree *curr = *tree;

	if (*tree == NULL) /* Initial tree is NULL. */
	{
		*tree = new_node(data);
		if (tree == NULL)
		{
			return (1);
		}
	}
	else
	{
		if (strcmp(data, curr->str) <= 0)
		{
			btree_insert(&curr->left, data);
		}
		else
		{
			btree_insert(&curr->right, data);
		}
	}

	return (0);
}

/**
 * new_node - Allocate memory for a new node and store the data in the
 * struct value str.
 *
 * @data: The string to store in the data.
 *
 * Description: Allocate memory for a new node and store the data in the
 * struct value str. Returns a newly allocated node.
 */
BTree *new_node(char *data)
{
	BTree *node;

	node = malloc(sizeof(BTree));
	if (node == NULL)
	{
		return (NULL);
	}

	node->str = strdup(data);
	node->left = NULL;
	node->right = NULL;

	return (node);
}
