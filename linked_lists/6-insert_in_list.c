#include <stdlib.h>
#include "list.h"

char *str_copy(char *, int);
int list_size(List *list);

void insert(List *node, List **list, int index)
{
  List *tmp, *tmp1;
  tmp = *list;
  tmp1 = *list;

  if(index == 0) {
    /* The pointer next of the structure points to NULL. */
    node->next = *list;
    /* The original pointer to NULL points to the newly allocated struct. */
    *list = node;
  }
  if (index != 0) {
    /* Traverse tmp1 to the location passed as the index. */
    while(index > 1) {
      /* tmp1 points to the next element in the array. */
      tmp1 = tmp1->next;
      /* tmp points to the location where the node is to be inserted. */
      tmp = tmp->next;
      --index;
    }
    node->next = tmp1->next;
    tmp->next = node;
  }
}

int insert_in_list(List **list, char *str, int index)
{
  List *node;
  int str_len, list_len;

  /* If the index is less than zero, do not add the new node. */
  if(index >= 0) {
    list_len = list_size(*list);
    /* Reset the index to the last position if index exceeds list length. */
    if(list_len < index) {
      index = list_len;
    }
    /* Allocate memory for the new node. */
    node = malloc(sizeof(List));
    if (node == NULL)
      return (1);
    /* Find the length of the string. */
    for(str_len = 0; str[str_len] != '\0'; ++str_len);
    /* Copy the string parameter str into the node. */
    node->str = str_copy(str, str_len);
    /* Insert the node at the index. */
    insert(node, list, index);
  }
  return (0);
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
