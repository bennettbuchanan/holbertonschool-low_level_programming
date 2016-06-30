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
        while (list != NULL) {
                tmp = list;
                list = list->next;
                free(tmp->str);
                free(tmp);
        }
}
