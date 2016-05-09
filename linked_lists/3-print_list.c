#include <stdlib.h>
#include "list.h"

int print_char(char c);

void print_list(List *list)
{
  int i;

  /* If there is a list, traverse it and count the nodes. */
  while(list != NULL) {
    for(i = 0; list->str[i] != '\0'; ++i) {
      print_char(list->str[i]);
    }
    if(list->next != NULL) {
      print_char(',');
      print_char(' ');
    }
    list = list->next;
  }
  print_char('\n');
}
