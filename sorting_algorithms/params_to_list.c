#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *str);

List *array_to_list(char **arr)
{
        List *list;
        int i = 0;
        int j;

        /* Create a pointer to the first item of the list. */
        list = NULL;

        /* For every array item, create a new list item. */
        for(j = 0; arr[j] != '\0'; ++j) {
                if (add_node(&list, arr[i]) == 1) {
                        return (NULL);
                }
                ++i;
        }
        return(list);
}
