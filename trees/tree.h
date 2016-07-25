#ifndef _TREE_H_
#define _TREE_H_

typedef struct BTree {
  char *str;
  struct BTree *left;
  struct BTree *right;
} BTree;

#endif
