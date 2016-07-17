#include <string.h>
#include "list.h"

int node_cmp(List *node1, List *node2)
{
  return (strcmp(node1->str, node2->str));
}
