#include "header.h"

/*
 * free_dl_list() - Iterates through a given linked list and frees each string
 * and the corresponding node.
 * @list: A linked list.
 *
 * Return: Void
 */
void free_dl_list(List *list) {
        List *tmp;
        while(list != NULL) {
                tmp = list;
                free(list->str);
                free(tmp);
                list = list->next;
        }
}
