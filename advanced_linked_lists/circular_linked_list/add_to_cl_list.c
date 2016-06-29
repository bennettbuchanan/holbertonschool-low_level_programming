#include "header.h"

/*
 * add_end_cl_list() - Adds a new List struct at the end of a linked list and
 * updates the appended item to point to the first list item, thereby creating
 * a curcluar linked list.
 * @list: The address of the first item in the list.
 * @str: The string to add as part of the new node's str attribute.
 *
 * Return: 0 if the node was successfully allocated and added and returns 1
 * if the memory allocation failed.
 */
int add_end_cl_list(List **list, char *str)
{
        List *tmp = *list;
        List *first = *list;
        List *node = malloc(sizeof(List));
        if (node == NULL) {
                return (1);
        }

        node->str = strdup(str);

        if(*list == NULL) {
                node->next = node;
                node->prev = node;
                *list = node;
        } else {
                while(tmp->next != first) {
                        tmp = tmp->next;
                }
                tmp->next = node;
                node->prev = tmp;
                node->next = first;
        }
        return 0;
}

/*
 * add_begin_cl_list() - Adds a new List struct at the beginning of a linked
 * list and updates the item to point to the first list item, thereby creating
 * a curcluar linked list.
 * @list: The address of the first item in the list.
 * @str: The string to add as part of the new node's str attribute.
 *
 * Return: 0 if the node was successfully allocated and added and returns 1
 * if the memory allocation failed.
 */
int add_begin_cl_list(List **list, char *str)
{
        List *node;
        List *tmp = *list;
        List *first = *list;
        node = malloc(sizeof(List));
        if (node == NULL) {
                return (1);
        }

        node->str = strdup(str);
        if (*list == NULL) {
                node->next = node;
                node->prev = node;
        } else {
                while(tmp->next != first) {
                        tmp = tmp->next;
                }
                tmp->next = node;
                node->next = first;
                node->prev = tmp;
        }
        *list = node; /* List points to the newly allocated struct. */

        return 0;
}
