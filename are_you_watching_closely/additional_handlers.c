#include "header.h"

/* Handle s case. */
int p_handler(va_list args)
{
        unsigned long int addr;
        addr = va_arg(args, unsigned long int);
        print_str("0x");
        return convert_hex(addr);
}

/* Handle defualt case. */
int default_handler(char c)
{
        print_char('%');
        print_char(c);
        return 2;
}

/* Handle c case. */
int c_handler(va_list args)
{
        int c;
        c = va_arg(args, int);
        print_char(c);
        return 1;
}

/* Handle o case. */
int o_handler(va_list args)
{
        int o;
        o = va_arg(args, int);
        return convert_octal(o);
}

/* Handle x case. */
int x_handler(va_list args)
{
        int d;
        d = va_arg(args, int);
        return convert_hex(d);
}
