#include "header.h"

/*
 * array_to_dcl_list() - Takes an array of strings and creates a linked list
 * with the items in the array.
 * @array: The array of items used to create a new linked list.
 *
 * Return: The linked list of array items.
 */
List *array_to_dcl_list(char **array)
{
        List *list;
        int i;
        list = NULL;

        for(i = 0; array[i] != '\0'; ++i) {
                if (add_end_dcl_list(&list, array[i]) == 1) {
                        return NULL;
                }
        }
        return list;
}
