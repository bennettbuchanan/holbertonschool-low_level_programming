#include "header.h"
#include <stdio.h>

int main(void)
{
	BTree *tree;
	char *a[] = {"f", "r", "c", "b", "a", NULL};
	int depth;

	tree = array_to_btree(a);

	if (tree == NULL) {
		printf("%s\n", "Tree is NULL.");
	} else {
		print_tree(tree);
	}

	depth = btree_depth(tree);

	printf("%d\n", depth);
	btree_free(tree);

	return 0;
}

void print_tree(BTree *tree)
{
	BTree *curr = tree;

	/* Print the string of a node. */
	if (curr != NULL) {
		printf("%s\n", curr->str);
	}

	if (curr->left != NULL) {
		print_tree(curr->left);
 	}

	if (curr->right != NULL) {
		print_tree(curr->right);
	}
}
