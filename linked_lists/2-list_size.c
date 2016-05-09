#include <stdlib.h>
#include "list.h"

int list_size(List *list)
{
  int len = 0;

  /* If the list exists, traverse it and count the nodes. */
  while(list != NULL) {
    list = list->next;
    ++len;
  }

  return (len);
}
