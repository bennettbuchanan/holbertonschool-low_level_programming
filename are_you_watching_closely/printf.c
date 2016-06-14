#include "header.h"

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
                        if (format[i + 1] == '%') {
                                i += 1;
                        } else {
                                i += 2;
                        }
                }
                len += print_char(format[i]);
                ++i;
        }
        va_end(args);

        return len;
}

int handle_char(char c, va_list args)
{
        /* Handle all the cases passed in the string. */
        switch(c) {
                case 's':
                        return s_handler(args);
                case 'd':
                        return d_handler(args);
                case 'i':
                        return i_handler(args);
                case 'u':
                        return u_handler(args);
                case 'c':
                        return c_handler(args);
                case 'p':
                        return p_handler(args);
                case 'o':
                        return o_handler(args);
                case 'X':
                        return X_handler(args);
                case 'x':
                        return x_handler(args);
                case '%':
                        return 0;
                default:
                        return default_handler(c);
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
