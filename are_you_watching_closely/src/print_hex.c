#include "header.h"

int convert_hex(unsigned long int n) {
        char arr[100];
        int i = 0, rem, len;

        while (n != 0) {
                /* Find the remainder of n / 16. */
                rem = n % 16;

                /* If the remainder is a single digit add 48. Otherwise, rem
                 * > 9 and < 16, thus rem should be the corresponding
                 * character.
                 */
                if (rem < 10){
                        rem = rem + 48;
                } else {
                        rem = rem + 87;
                }
                n = n / 16;
                arr[i] = rem;
                ++i;
        }
        i -= 1;
        len = i;
        /* Print the array backwards. */
        for(; i >= 0; --i){
                print_char(arr[i]);
        }
        return len;
}

int convert_hex_uppercase(unsigned long int n) {
        char arr[100];
        int i = 0, rem, len;

        while (n != 0) {
                /* Find the remainder of n / 16. */
                rem = n % 16;

                /* If the remainder is a single digit add 55. Otherwise, rem
                 * > 9 and < 16, thus rem should be the corresponding
                 * character.
                 */
                if (rem < 10){
                        rem = rem + 48;
                } else {
                        rem = rem + 55;
                }
                n = n / 16;
                arr[i] = rem;
                ++i;
        }
        i -= 1;
        len = i;
        /* Print the array backwards. */
        for(; i >= 0; --i){
                print_char(arr[i]);
        }
        return len;
}

int convert_octal(int n) {
        char arr[100];
        int i = 0, rem, len;

        while (n != 0) {
                /* Find the remainder of n / 8. */
                rem = n % 8;
                rem = rem + 48;
                n = n / 8;
                arr[i] = rem;
                ++i;
        }
        i -= 1;
        len = i;
        /* Print the array backwards. */
        for(; i >= 0; --i){
                print_char(arr[i]);
        }
        return len;
}
