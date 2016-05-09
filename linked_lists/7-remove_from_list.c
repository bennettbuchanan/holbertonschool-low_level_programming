#include <stdlib.h>
#include "list.h"
#include <stdio.h>

int list_size(List *list);

void remove_from_list(List **list, int index)
{
  List *prev, *head;
  int list_len, j;
  prev = *list;
  head = *list;
  list_len = list_size(*list);
  if (index == 0) {
    head = head->next;
    *list = head;
  }
  if(index < list_len && index > 0) {
    /* Traverse the list so that prev is prior to the index. */
    for(j = index; j > 1; --j) {
      prev = prev->next;
    }
    /* Traverse the list so that head is the same as the index. */
    for(; index > 0; --index) {
      head = head->next;
    }
    prev->next = head->next; /* Link the previous node with the next node. */
    free(head->str);
    free(head);
  }
}

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
