#include <stdio.h>
#include <unistd.h>

void print_num(int);
void print_char(char);
void print_str(char *str);
void print_array_str(char **array);

void print_array(int *arr, int len)
{
        int i;

        for (i = 0; i < len; ++i) {
                if (i + 1 == len) {
                        printf("%d", arr[i]);
                        break;
                }
                printf("%d, ", arr[i]);
        }
        printf("\n");
}

void print_array_str(char **array)
{
        int i, j;

        for (i = 0; array[i] != '\0'; ++i) {
                for (j = 0; array[i][j] != '\0'; ++j) {
                        print_char(array[i][j]);
                }
                if (array[i + 1] != '\0') {
                        print_char(',');
                        print_char(' ');
                }
        }
        print_char('\n');
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
