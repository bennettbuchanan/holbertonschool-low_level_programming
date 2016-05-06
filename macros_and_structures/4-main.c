#include "param_struct.h"
#include <stdio.h>
#include <stdlib.h>

struct Param *params_to_struct_array(int ac, char **av);
void print_params_structs_array(struct Param *array);

int main(int ac, char **av)
{
  struct Param *array;

  array = params_to_struct_array(ac, av);
  print_params_structs_array(array);
  return(0);
}
