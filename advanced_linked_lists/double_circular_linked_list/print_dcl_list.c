#include "header.h"

/*
 * print_dcl_list() - Prints the items of the struct from list.h that are
 * nodes in a linked list. The loop stops when the circular linked list has
 * been cycled, then prints out the last items to demonstrate the completed
 * cycle. If the list is NULL, do nothing.
 * @list: The linked list to be printed.
 *
 * Return: Void
 */
void print_dcl_list(List *list)
{
        List *first = list;

        if(list != NULL) {
                while(list->next != first) {
                        print_string(list->str);
                        print_prev(list);
                        print_next(list);
                        list = list->next;
                }
                print_string(list->str);
                print_prev(list);
                print_next(list);
        }
}

/*
 * print_next() - Print the string of the next item in the list. If the next
 * item is NULL, then print the string "NULL" instead and return. The return
 * is necessary at this point because trying to access list->next->str will
 * result in a segmentation fault.
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

/*
 * print_prev() - Print the string of the previous item in the list. If the
 * previous item is NULL, then print the string "NULL" instead.
 * @list: The linked list from which to print the data.
 *
 * Return: Void
 */
void print_prev(List *list)
{
        print_string("\n\t");
        if (list->prev == NULL) {
                print_string("NULL");
        } else {
                print_string(list->prev->str);
        }
}
