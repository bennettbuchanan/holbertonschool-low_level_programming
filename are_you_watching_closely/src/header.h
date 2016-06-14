#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int handle_char(char c, va_list args);
void print_base16(void);
int print_str(char *);
int print_char(char);
void print_num(int);
int get_num_len(int n, int i);
void print_unsigned(unsigned int n);
int get_unsigned_len(unsigned int n, int i);
void print_neg_num(int n);
void min();
void print_number(int n);
int convert_hex(unsigned long int number);
int convert_octal(int n);
int s_handler(va_list);
int d_handler(va_list);
int i_handler(va_list);
int X_handler(va_list);
int u_handler(va_list);
int p_handler(va_list);
int default_handler(char);
int c_handler(va_list);
int o_handler(va_list);
int x_handler(va_list);
int convert_hex_uppercase(unsigned long int n);
