#include <unistd.h>

int print_char(char c);
int str_to_int(char *s);
void top_handler(int n, int row_width, int new_line);
void mid_handler(int n, int row_width, int new_line);
void bottom_handler(int n, int row_width, int new_line);
int limits_handler(int n, int place, int is_neg);

int main (int argc, char *argv[])
{
        int t = 0, n = str_to_int(argv[1]), row_width, new_line;

        if (n % 2 != 0) {
                n = n - 1;
                t = 1;
                row_width = n;
                new_line = n;
        } else {
                row_width = n - 1;
                new_line = n - 1;
        }

        top_handler(n, row_width, new_line);

        if (t == 1) {
                mid_handler(n, row_width, new_line);
        }

        bottom_handler(n, row_width, new_line);

        return 0;
}

void top_handler(int n, int row_width, int new_line)
{
        int i, j;

        for(i = 0; i < n / 2; ++i) {
                for(j = 0; j <= row_width; ++j) {
                        if (j == i) {
                                print_char('\\');
                        } else if (j == new_line - i) {
                                print_char('/');
                        } else {
                                print_char(' ');
                        }
                }
                print_char('\n');
        }
}

void mid_handler(int n, int row_width, int new_line)
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

void bottom_handler(int n, int row_width, int new_line)
{
        int i, j;

        for(i = n / 2 - 1; i >= 0; --i) {
                for(j = 0; j <= row_width; ++j) {
                        if (j == i) {
                                print_char('/');
                        } else if (j == new_line - i) {
                                print_char('\\');
                        } else {
                                print_char(' ');
                        }
                }
                print_char('\n');
        }
}

int str_to_int(char *s)
{
        int long i, n, tmp, place = 0, is_neg = 0;

        for (i = 0; i >= 0 && s[i] != '\0'; i++) {
                tmp = i - 1;
                if (s[i] <= 47 || s[i] >= 58) {
                        if (s[i] == 45) {
                                is_neg += 1;
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

int limits_handler(int n, int place, int is_neg)
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

int print_char(char c)
{
      return (write(1, &c, 1));
}
