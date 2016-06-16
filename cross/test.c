#include <unistd.h>

int print_char(char c);
int string_to_integer(char *s);
void top_handler(int n);
void mid_handler(int n);
void bottom_handler(int n);

int main (int argc, char *argv[])
{
        int t = 0;
        int n = string_to_integer(argv[1]);

        if (n % 2 != 0) {
                n = n - 1;
                t = 1;
        }

        top_handler(n);

        if (t == 1) {
                mid_handler(n);
        }

        bottom_handler(n);

        return 0;
}

void top_handler(int n)
{
        int i, j;
        /* Handle the top n / 2. */
        for(i = 0; i < n / 2; ++i) {
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
}

void mid_handler(int n)
{
        int j;
        for(j = 0; j <= n; ++j) {
                if (j == n / 2) {
                        print_char('X');
                } else {
                        print_char(' ');
                }
                if (j == n) {
                        print_char('\n');
                }
        }
}

void bottom_handler(int n)
{
        int i, j;
        /* Handle the bottom n / 2. */
        for(i = n / 2 - 1; i >= 0; --i) {
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
