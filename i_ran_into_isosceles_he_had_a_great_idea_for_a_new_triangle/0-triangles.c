#include <unistd.h>
#include "my_functions.h"

int print_char(char c)
{
  return (write(1, &c, 1));
}

/* call function to print triangles */
void triangles_in_the_term(int h, int n){
  int i, numspaces, numstars;
  /* print n number of triangles */
  for (; n > 0; n--) {
    /* print h number of lines */
    for (i = 0; i < h; i++) {
      /* find the number of spaces for i line */
      numspaces = (h - 1) - i;
      /* print space numspaces of times */
      for (; numspaces > 0; numspaces--) {
	print_char(' ');
      }
      /* find the number of * for i line */
      numstars = (i * 2) + 1;
      /* print * numstars of times */
      for (; numstars > 0; numstars--) {
	print_char('*');
      }
      /* print a new line */
      print_char('\n');
    }
  }
}
