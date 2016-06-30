#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int add_end_dcl_list(List **, char *);
int add_begin_dcl_list(List **, char *);
void print_dcl_list(List *);

int main(void)
{
  List *list;

  list = NULL;
  if (add_end_dcl_list(&list, "Holberton") == 1 ||
      add_end_dcl_list(&list, "School") == 1 ||
      add_end_dcl_list(&list, "Full") == 1 ||
      add_end_dcl_list(&list, "Stack") == 1 ||
      add_end_dcl_list(&list, "Engineer") == 1)
    return (1);
  printf("FIRST EXAMPLE:\n");
  print_dcl_list(list);
  list = NULL;
  if (add_begin_dcl_list(&list, "Holberton") == 1 ||
      add_begin_dcl_list(&list, "School") == 1 ||
      add_begin_dcl_list(&list, "Full") == 1 ||
      add_begin_dcl_list(&list, "Stack") == 1 ||
      add_begin_dcl_list(&list, "Engineer") == 1)
    return (1);
  printf("SECOND EXAMPLE:\n");
  print_dcl_list(list);
  return (0);
}
