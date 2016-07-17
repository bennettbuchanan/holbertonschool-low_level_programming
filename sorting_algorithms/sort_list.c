#include <stdlib.h>
#include "list.h"
#include <stdio.h>

/*
 * sort_list() - Sorts a list using bubble sort method.
 *
 * @list: The address of the list to be sorted.
 * @cmp_func(): Function that compares one string with the next in a node.
 *
 * Return: Void.
 */
void sort_list(List **list, int (*cmp_func)(List *, List *))
{
        char *tmp;
        List *node = *list;
        int is_sorted = 1;

        while (is_sorted == 1) {
                is_sorted = 0;
                while (node->next != NULL) {
                        if (cmp_func(node, node->next) > 0) {
                                tmp = node->str;
                                node->str = node->next->str;
                                node->next->str = tmp;
                                is_sorted = 1;
                        }
                        node = node->next;
                }
                /* Update the node to the head of the list. */
                node = *list;
        }
}
