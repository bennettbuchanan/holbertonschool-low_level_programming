#include <stdlib.h>
#include <unistd.h>

void print_number(int n);
void min();
int print_char(char c);

int **alloc_grid(int width, int height) {
  int i, j;
  int **grid;

  grid = malloc(sizeof(int **) * width);
  if (grid == NULL) {
    return (NULL);
  }
  for (i = 0; i < height; i++) {
    grid[i] = malloc(sizeof(int) * height);
    if (grid[i] == NULL) {
      return (NULL);
    }
  }
  /* Assign decimals to the grid array */
  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {
      grid[i][j] = 0;
    }
  }

  return (grid);
  free(grid);
}

void print_grid(int **grid, int width, int height) {
  int i, j, x;

  /* Print the grid array */
  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {
      x = grid[i][j];
      print_number(x);
      if (j != width - 1) {
        print_char(',');
        print_char(' ');
      }
    }
    print_char('\n');
  }
}

int print_char(char c)
{
  return (write(1, &c, 1));
}

/* for number -2147483648, print minus sign and first digit */
void min()
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
    length_stored = length;/* store value of length for later subtraction*/
  for (;length > 0; length--)/* subtract length by one for each iteration */
    {for (i = 1; length_stored > i; i++)
      {power *= 10;}
      digit = n / power; /* divide n by power to find the digit */
      print_char(digit + 48); /* print digit plus 48 on ascii */
      n = n - (digit * power);
      power = 1;
      length_stored--;}
}
