#include <stdlib.h>
#include "list.h"

void free_list(List *list) {
        List *tmp;

        /* Traverse the list and free the nodes. */
        while(list != NULL) {
                /* Store next node in tmp to allow freeing of current node. */
                tmp=list->next;
                free(list->str);
                free(list);
                list = tmp;
        }
}
