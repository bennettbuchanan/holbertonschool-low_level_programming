#include "header.h"
int print_str(char *);
int print_char(char);
void print_num(int);
int get_num_len(int n, int i);

int printf(const char *format, ...)
{
        int i = 0;
        int len = 0;
        va_list args;
        va_start(args, format);


        /* Iterate through the string array. */
        while(format[i] != '\0') {
                /*
                 * If a special char is encountered, determine if the following
                 * char is a special type char (e.g., 's', 'd', etc.).
                 */

                if (format[i] == '%') {
                        len += handle_char(format[i + 1], args);
                        i += 2;
                }
                len += print_char(format[i]);
                ++i;
        }
        va_end(args);

        return len;
}

int handle_char(char c, va_list args)
{
        char d, *s;
        int len = 0;

        switch(c) {
                case 's':
                        s = va_arg(args, char *);
                        len = print_str(s);
                        return len;
                case 'd':
                        d = va_arg(args, int);
                        print_num(d);
                        len = get_num_len(d, 0);
                        return len;
        }
        return 0;
}

/*
 * print_str() - Prints the string passed as parameter to stdout.
 * @s: The string to be printed.
 *
 * Return: The number of chars printed.
 */
int print_str(char *s)
{
        int i;
        for(i = 0; s[i] != '\0'; ++i) {
                write (1, &s[i], 1);
        }
        return i;
}

/*
 * print_char() - Prints the char passed as parameter to stdout.
 * @c: The char to be printed.
 *
 * Return: The return 1 to track the number of chars printed.
 */
int print_char(char c)
{
        write(1, &c, 1);
        return 1;
}

/*
 * print_num() - Prints the number passed as parameter to stdout.
 * @arg1: The number to be printed.
 *
 * Return: Null.
 */
void print_num(int n)
{
        if (n >= 10)
                {
                        print_num(n / 10);
                }
        print_char(n % 10 + 48);
}

/*
 * get_num_len() - Recursively divide a number by ten, adding one to i for each
 operation. Return the length of the number given.
 * @n: The number to find the length.
 * @i: The iteration starting point. This should be 0.
 *
 * Return: The lenth of the number passed.
 */
int get_num_len(int n, int i)
{
        if (n >= 10)
                {
                        return get_num_len(n / 10, i + 1);
                }
        return i + 1;
}
