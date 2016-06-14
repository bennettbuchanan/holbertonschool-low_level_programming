#include "header.h"

/* Handle s case. */
int s_handler(va_list args)
{
        int len;
        char *s;
        s = va_arg(args, char *);
        len = print_str(s);
        return len;
}

/* Handle d case. */
int d_handler(va_list args)
{
        int len = 0, d;

        d = va_arg(args, int);
        print_number(d);
                if (d < 0) {
                        d *= -1;
                        len += 1;
                }
        return get_num_len(d, 0);
}

/* Handle i case. */
int i_handler(va_list args)
{
        int len = 0, d;

        d = va_arg(args, int);
        print_number(d);
                if (d < 0) {
                        d *= -1;
                        len += 1;
                }
        return get_num_len(d, 0);
}

/* Handle X case. */
int X_handler(va_list args)
{
        int d;

        d = va_arg(args, int);
        return convert_hex_uppercase(d);
}

/* Handle u case. */
int u_handler(va_list args)
{
        unsigned int ui;

        ui = va_arg(args, unsigned int);
        print_unsigned(ui);
        return get_unsigned_len(ui, 0);
}
