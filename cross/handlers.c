#include "header.h"

/*
 * top_handler() - Print the top half of the shape.
 * @n: The command line argument to determine the size of the shape.
 * @row_width: The width of the row.
 *
 * Return: NULL
 */
void top_handler(int n, int row_width)
{
        int i, j;

        for(i = 0; i < n / 2; ++i) {
                for(j = 0; j <= row_width; ++j) {
                        if (j == i) {
                                print_char('\\');
                        } else if (j == row_width - i) {
                                print_char('/');
                        } else {
                                print_char(' ');
                        }
                }
                print_char('\n');
        }
}

/*
 * mid_handler() - Prints the middle line of an X of odd n.
 * @n: The command line argument to determine the size of the shape.
 * @row_width: The width of the row.
 *
 * Return: NULL
 */
void mid_handler(int n, int row_width)
{
        int j;

        for(j = 0; j <= row_width; ++j) {
                if (j == n / 2) {
                        print_char('X');
                } else {
                        print_char(' ');
                }
        }
        print_char('\n');
}

/*
 * bottom_handler() - Print the bottom half of the shape.
 * @n: The command line argument to determine the size of the shape.
 * @row_width: The width of the row.
 *
 * Return: NULL
 */
void bottom_handler(int n, int row_width)
{
        int i, j;

        for(i = n / 2 - 1; i >= 0; --i) {
                for(j = 0; j <= row_width; ++j) {
                        if (j == i) {
                                print_char('/');
                        } else if (j == row_width - i) {
                                print_char('\\');
                        } else {
                                print_char(' ');
                        }
                }
                print_char('\n');
        }
}
