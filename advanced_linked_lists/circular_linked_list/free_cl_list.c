#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*
 * free_cl_list() - Iterates through a given linked list and frees each string
 * and the corresponding node. Exits loop prior to complete cycle and frees the
 * last node in the list.
 * @list: A linked list.
 *
 * Return: Void
 */
void free_cl_list(List *list) {
        List *tmp;
        List *first = list;
        while(list->next != first) {
                tmp = list;
                list = list->next;
                free(tmp->str);
                free(tmp);
        }
        free(list->str);
        free(list);
}
