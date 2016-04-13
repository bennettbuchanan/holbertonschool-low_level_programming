#include <stdlib.h>
#include <unistd.h>

char *int_to_str(int, int, char *);
int find_len(int);
char *min(char *);
char *test(int n, int j, int len, char *str);

char *int_to_string(int n) {
  char *str;
  int len;
  str = malloc(sizeof(char) * 509);

  if (str == NULL) {
    return NULL;
  }

  /* find the length and pass it to function return string */
  len = find_len(n);
  str = int_to_str(n, len, str);

  if (n < 0) {
    str[len + 1] = '\0';
  }
  if (n > 0) {
    str[len] = '\0';
  }

  return (str);
}

int find_len(int n)
{
  int i;
  int len = 0;
  if (n == -2147483648) {
    len = 10;
    return len;
  }
  if (n < 0) {
    n *= -1;
  }
  for (i = n; i > 0; i = i / 10) /* find the decimal len of n */
    {
      len++;
    }
  return len;
}

char *int_to_str(int n, int len, char *str)
{
  int j = 0;
  if (n == 0)
    {
      str[0] = '0';
      str[1] = '\0';
      return (str);
    }
  /* If n is INT_MIN, remove store minus sign and first digit */
  if (n == -2147483648)
    {
      n = 147483648;
      str = min(str);
      len -= 1;
      j += 2;
    }

  str = test(n, j, len, str);
  return (str);
}

char *test(int n, int j, int len, char *str)
{
  int digit, len_stored, i;
  int power = 1;
  if (n < 0 && j != 2) /* make n make positive */
    {
      n *= -1;
      str[0] = '-';
      j++;
    }
  len_stored = len; /* store value of len for later subtraction */
  for (;len > 0; len--) /* subtract len by one for each iteration */
    {
      for (i = 1; len_stored > i; i++)
      {
        power *= 10;
      }
      digit = n / power; /* divide n by power to find the digit */
      str[j] = digit + 48; /* print digit plus 48 on ascii */
      j++;
      n = n - (digit * power);
      power = 1;
      len_stored--;
    }
  return(str);
}

/* for number -2147483648, print minus sign and first digit */
char *min(char *str)
{
  str[0] = '-'; /* print minus sign */
  str[1] = '2'; /* print digit '2' */
  return (str);
}
