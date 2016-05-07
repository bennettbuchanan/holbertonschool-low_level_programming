#include "param_struct.h"
#include <unistd.h>
#include <stdlib.h>
#include "limits.h"

int print_char(char c);
void print_number(int n);
void print_digits(int, int, int);
int handle_cases(int n);

void print_params_structs_array(struct Param *array)
{
  int i, j, k;

  for(i = 0; array[i].str != NULL; ++i) {
    for(k = 0; array[i].copy[k] != '\0'; ++k) {
      print_char(array[i].copy[k]);
    }
    print_char('\n');
    print_number(array[i].length);

    /* Print each word in the string. */
      for(j = 0; array[i].tab[j] != NULL; ++j) {
        for(k = 0; array[i].tab[j][k] != '\0'; ++k) {
          print_char(array[i].tab[j][k]);
        }
        if (array[i].tab[j + 1] != NULL) {
          print_char(',');
          print_char(' ');
        }
      }
    print_char('\n');
  }
}

void print_number(int n)
{
  int i = 0;
  int tmp = n;
  int power = 1;

  /* If INT_MIN, subtract one from i to account for highest digit. */
  if (n == INT_MIN) {
    i = -1;
  }

  n = handle_cases(n);

  if (n != 0) {
    /* Find the decimal place of n. */
    for(; tmp != 0; ++i) {
      tmp /= 10;
    }
    print_digits(i, power, n);
  }
  print_char('\n');
}

int handle_cases(int n)
{
  /* Handle INT_MIN case. */
  if (n == INT_MIN) {
    print_char('-');
    print_char('2');
    return (147483648);
  }
  /* Handle when n < 0. */
  if (n < 0) {
    n *= -1;
    print_char('-');
  }
  /* Handle case where n == 0. */
  if (n == 0) {
    print_char('0');
  }
  return (n);
}

void print_digits(int i, int power, int n)
{
  int digit, rem;
  int j = i;
  while(j > 0) {
    /* Get the place value. */
    while (i > 1) {
      power *= 10;
      --i;
    }
    /* Get the highest digit. */
    digit = n / power;
    /* Multiply by dividend. */
    power *= digit;
    /* Subtract the power from the original n to get the remainder. */
    rem = n - power;
    print_char(digit + 48);
    power /= 10;
    /* Reassign n to remainder for contination in the while loop. */
    n = rem;
    --j;
    i = j;
    power = 1;
  }
}
