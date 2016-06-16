#include <unistd.h>

int print_char(char c);
int string_to_integer(char *s);

int main (int argc, char *argv[])
{
        int t = 0, i, j;
        int n = string_to_integer(argv[1]);
        int half = n / 2;

        if (n % 2 != 0) {
                n = n - 1;
                t = 1;
        }

        /* Handle the top half. */
        for(i = 0; i < half; ++i) {
                for(j = 0; j <= n; ++j) {
                        if (j == i) {
                                print_char('\\');
                        } else if (j == n - i) {
                                print_char('/');
                        } else {
                                print_char(' ');
                        }
                        if (j == n) {
                                print_char('\n');
                        }
                }
        }

        /* Handle the middle, if n is odd. */
        if (t == 1) {
                for(j = 0; j <= n; ++j) {
                        if (j == half) {
                                print_char('X');
                        } else {
                                print_char(' ');
                        }
                        if (j == n) {
                                print_char('\n');
                        }
                }
        }

        /* Handle the bottom half. */
        for(i -= 1; i >= 0; --i) {
                for(j = 0; j <= n; ++j) {
                        if (j == i) {
                                print_char('/');
                        } else if (j == n - i) {
                                print_char('\\');
                        } else {
                                print_char(' ');
                        }
                        if (j == n) {
                                print_char('\n');
                        }
                }
        }
        return 0;
}

int print_char(char c)
{
      return (write(1, &c, 1));
}

int string_to_integer(char *s)
{
        int long i, n, tmp, digit;
        int place = 0, is_neg = 0;

        for (i = 0; i >= 0; i++) {
                tmp = i - 1;
                if (s[i] == 0) {
                        break;
                } else if (s[i] <= 47 || s[i] >= 58) {
                        if (s[i] == 45) {
                                is_neg += 1;
                        }
                	if (s[tmp] > 47 && s[tmp] < 58) {
                                break;
                        }
                } else if (s[i] > 47 && s[i] < 58) {
                        digit = s[i] - 48;
	                if (place == 0) {
                                n = digit;
                                place += 1;
                                if (is_neg % 2 != 0) {
                                        place += 1;
                                }
                        } else if (place > 0) {
                                n *= 10;
                                n += digit;
                                place += 1;
                        }
                }
        }
        if (n == 2147483648 && place > 10) {
                return (n);
        } else if (n == 2147483648 && place == 10) {
                return 0;
        } else if (n > 2147483648) {
                return 0;
        } else {
                if (is_neg %2 != 0) {
                        print_char('-');
                }
                return n;
        }
}
