#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int print_char(char c);
int addInt(int a, int b);
int (*get_op_func(char c))(int, int);
int (*functionPtr)(int,int);
void min(void);
int print_char(char c);
void print_number(int n);

int main(int argc, char **argv) {
  int i, result, first, second;
  char * operation;
  char op;
  if (argc == 4) {
    for (i = 0; i < argc; i++) {
      if (i == 2) {
        first = atoi(argv[1]);
        second = atoi(argv[3]);
        operation = argv[2];
        op = operation[0];
        if (op == '+' || op == '-' || op == '/' || op == '*' || op == '%') {
          functionPtr = get_op_func(op); /* assign pointer function */
          result = functionPtr(first, second);
          print_number(result);
          print_char('\n');
          return (0);
        }
        if (op != '+' || op != '-' || op != '/' || op != '*' || op != '%') {
          return (1);
        }
      }
    }
  }
  return (1);
}

/* for number -2147483648, print minus sign and first digit */
void min(void)
{
   print_char('-'); /* print minus sign */
   print_char('2'); /* print digit '2' */
}

/* call print_number function to print each digit using print_char */
void print_number(int n)
{
  int length = 0;
  int power = 1;
  int digit, length_stored, i;
  if (n == -2147483648)
    {n = 147483648;
      min();} /* call min function */
  if (n < 0 && n != -2147483648)/* print '-' and make n make positive*/
    {n *= -1;
     print_char('-');} /* print minus sign */
  if (n == 0)
    {print_char('0');} /* print digit '0' */
  for (i = n; i > 0; i = i / 10)/* find the decimal length of n */
    {length++;}
    length_stored = length; /* store value of length for later subtraction*/
  for (;length > 0; length--) /* subtract length by one for each iteration */
    {for (i = 1; length_stored > i; i++)
      {power *= 10;}
      digit = n / power; /* divide n by power to find the digit */
      print_char(digit + 48); /* print digit plus 48 on ascii */
      n = n - (digit * power);
      power = 1;
      length_stored--;}
}

int print_char(char c)
{
  /* write a character to output */
  return (write(1, &c, 1));
}
