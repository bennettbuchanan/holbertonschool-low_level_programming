#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "header.h"

/*
 * print_dl_list() - Prints the items of the struct from list.h that are nodes
 * in a linked list. The loop stops when the circular linked list has been
 * cycled, then prints out the last items to demonstrate the completed cycle.
 * @list: The linked list to be printed.
 *
 * Return: Void
 */
void print_cl_list(List *list)
{
        List *first = list;

        while(list->next != first) {
                print_string(list->str);
                print_next(list);
                list = list->next;
        }
        print_string(list->str);
        print_next(list);
}

/*
 * print_next() - Print the string of the next item in the list. If the next
 * item is NULL, then print the string "NULL" instead and return. The return is
 * necessary at this point because trying to access list->next->str will result
 * in a segmentation fault.
 * @list The linked list from which to print the data.
 *
 * Return: Void
 */
void print_next(List *list)
{
        print_string("\n\t");
        if (list->next == NULL)  {
                print_string("NULL");
                print_string("\n");
                return;
        }
        print_string(list->next->str);
        print_string("\n");
}
