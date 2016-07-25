#include "header.h"
#include "stdio.h"

void print_preorder(BTree *tree);
int test_insert();

int main() {
 test_insert();
 return 0;
}

int test_insert() {
 BTree *tree = NULL;
 BTree *found;
 printf("The numbers should be in ascending order.\n");
 btree_insert(&tree, "q - 1");
 btree_insert(&tree, "w - 6");
 btree_insert(&tree, "e - 2");
 btree_insert(&tree, "r - 7");
 btree_insert(&tree, "t - 8");
 btree_insert(&tree, "y - 10");
 btree_insert(&tree, "u - 9");
 btree_insert(&tree, "i - 3");
 btree_insert(&tree, "o - 4");
 btree_insert(&tree, "p - 5");
 print_preorder(tree);
 found = btree_find(tree, "o - 4");
 if (found != NULL) {
 	printf("Found node with string: %s\n", found->str);
} else {
	printf("%s\n", "not found");
}
 btree_free(tree);
 return 0;
}

void print_preorder(BTree *tree) {
 if (tree == NULL) return;
 printf("%s\n", tree->str);
 print_preorder(tree->left);
 print_preorder(tree->right);
}
