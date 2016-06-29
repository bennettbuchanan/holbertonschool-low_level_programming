#include "header.h"

/*
 * print_string() - Prints a string to stdout.
 * @str: A pointer to a string to be printed.
 *
 * Return: Void.
 */
void print_string(char *str)
{
        int i;
        for(i = 0; str[i] != '\0'; ++i) {
                print_char(str[i]);
        }
}
