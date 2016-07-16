#include <stdio.h>

void print_num(int);
void print_char(char);
void print_str(char *str);

void print_array(int *arr, int len)
{
        int i;

        for (i = 0; i < len; ++i) {
                printf("%d, ", arr[i]);
        }
        printf("\n");
}

/*
 * print_num() - Prints a number to stdout.
 * @n: The number to print.
 *
 * Return: Void.
 */
void print_num(int n)
{
        if (n >= 10) {
                print_num(n / 10);
        }
        print_char(n % 10 + 48);
}


/*
 * print_str() - Prints a string to stdout.
 * @str: A pointer to a string to be printed.
 *
 * Return: Void.
 */
void print_str(char *str)
{
        int i;
        for(i = 0; str[i] != '\0'; ++i) {
                print_char(str[i]);
        }
}
