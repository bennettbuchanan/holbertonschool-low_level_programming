#include "header.h"

/*
 * str_to_int() - Convert a string to an integer.
 * @*s: The string that is to be converted.
 *
 * Return: -1 if the string is negative. (This function is designed
 * specifically to be used with printing the X shape. There cannot be a shape
 * of negative size, hence return -1 to indicate the argument was negative.)
 * Otherwise, return the int of the string number.
 */
int str_to_int(char *s)
{
        int long i, n, tmp, place = 0, is_neg = 0;

        for (i = 0; i >= 0 && s[i] != '\0'; i++) {
                tmp = i - 1;
                if (s[i] <= 47 || s[i] >= 58) {
                        if (s[i] == 45) {
                                is_neg += 1;
                                /* Return -1 if the string is negative */
                                return -1;
                        }
                	if (s[tmp] > 47 && s[tmp] < 58) {
                                break;
                        }
                } else if (s[i] > 47 && s[i] < 58) {
	                if (place == 0) {
                                n = s[i] - 48;
                                place += 1;
                                if (is_neg % 2 != 0) {
                                        place += 1;
                                }
                        } else if (place > 0) {
                                n *= 10;
                                n += s[i] - 48;
                                place += 1;
                        }
                }
        }
        return limits_handler(n, place, is_neg);
}

/*
 * limits_handler() - Handles the limits of an integer for the str_to_int
 * function. If the number is negative, it prepends the minus sign.
 * @n: The number passed.
 * @place: The place value of the number (i.e., 3, if n is 100).
 * @is_neg: 1 if n is negative, 0 otherwise.
 *
 * Return: n.
 */
int limits_handler(long int n, int place, int is_neg)
{
        if (n == 2147483648 && place > 10) {
                return n;
        } else if ((n == 2147483648 && place == 10) || n > 2147483648) {
                return 0;
        } else {
                if (is_neg % 2 != 0) {
                        print_char('-');
                }
                return n;
        }
        return 0;
}
