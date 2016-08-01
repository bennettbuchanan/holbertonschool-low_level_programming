#include <stdlib.h>
#include "tree.h"
#include <string.h>

NTree *trav_list(List *, char *);
int add_list(NTree *, NTree *);
int handle_node(NTree **, NTree *, char **);
int find_node(NTree *tree, char **arr);
NTree *traverse_list(List *list, char *str);
