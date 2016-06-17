#include "header.h"

/*
 * main() - Take the size of the shape from the command line, and call the
 * functions to print the shape.
 * @argc: The number of command line arguments.
 * @*argv[]: The array of command line arguments.
 * Return: 0 if the argument is negative or 0.
 */
int main (int argc, char *argv[])
{
        int t = 0, n = str_to_int(argv[1]), row_width;

        row_width = n - 1;

        if (n < 0 || argc != 2) {
                return 0;
        }

        if (n % 2 != 0) {
                n = n - 1;
                t = 1;
        }

        top_handler(n, row_width);

        if (t == 1) {
                mid_handler(n, row_width);
        }

        bottom_handler(n, row_width);

        return 0;
}
