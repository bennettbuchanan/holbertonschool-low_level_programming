#include <stdlib.h>
#include <string.h>
#include "tree.h"

int btree_insert(BTree **tree, char *data);
BTree *array_to_btree(char **array);
void print_tree(BTree *node);
void btree_free(BTree *tree);
int btree_depth(BTree *tree);
BTree *btree_find(BTree *tree, char *str);
