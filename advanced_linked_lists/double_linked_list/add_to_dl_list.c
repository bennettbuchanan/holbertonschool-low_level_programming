#include "list.h"
#include "header.h"
#include <string.h>
#include <stdlib.h>

/*
 * add_end_dl_list() - Adds a new List struct at the end of a linked list.
 * @list: The address of the first item in the list.
 * @str: The string to add as part of the new node's str attribute.
 *
 * Return: 0 if the node was successfully allocated and added and returns 1
 * if the memory allocation failed.
 */
int add_end_dl_list(List **list, char *str)
{
        List *tmp = *list;
        List *node = malloc(sizeof(List));
        if (node == NULL) {
                return (1);
        }

        node->str = strdup(str);
        node->next = NULL;

        if(*list == NULL) {
                *list = node;
        } else {
                while(tmp->next != NULL) {
                        tmp = tmp->next;
                }
                tmp->next = node;
                node->prev = tmp;
        }
        return 0;
}

/*
 * add_begin_dl_list() - Adds a new List struct at the beginning of a linked
 * list.
 * @list: The address of the first item in the list.
 * @str: The string to add as part of the new node's str attribute.
 *
 * Return: 0 if the node was successfully allocated and added and returns 1
 * if the memory allocation failed.
 */
int add_begin_dl_list(List **list, char *str)
{
        List *node;
        List *tmp;
        node = malloc(sizeof(List));
        if (node == NULL) {
                return (1);
        }

        node->str = strdup(str);
        node->next = *list;

        if (*list == NULL) {
                node->prev = NULL;
        } else {
                tmp = *list;
                tmp->prev = node;
                node->prev = NULL;
        }

        /* Update *list to point to the newly allocated struct. */
        *list = node;

        return 0;
}
