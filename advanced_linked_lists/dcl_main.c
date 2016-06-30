#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "header.h"

int add_end_dcl_list(List **, char *);
int add_begin_dcl_list(List **, char *);
void print_dcl_list(List *);

int main(void)
{
  List *list;

  list = NULL;
  printf("FIRST EXAMPLE:\n");
  print_dcl_list(list);
  list = NULL;
  if (add_begin_dcl_list(&list, "Holberton") == 1)
    return (1);
  printf("SECOND EXAMPLE:\n");
  print_dcl_list(list);
  free_dcl_list(list);
  return (0);
}
