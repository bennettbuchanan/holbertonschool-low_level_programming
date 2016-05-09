#include <stdlib.h>
#include "list.h"

void rev_list(List **list)
{
  List *prev = NULL;
  List *current = *list;
  List *next;

  while (current != NULL)
  {
    /* Struct next to points to the next element. */
    next = current->next;
    /* The current struct's next pointer points to initialized struct. */
    current->next = prev;
    /* Replace the previous element with the current. */
    prev = current;
    /* Move to the next element. */
    current = next;
  }
  *list = prev;
}
