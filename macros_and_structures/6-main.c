#include "param_struct.h"

struct Param *params_to_struct_array(int ac, char **av);
void free_params_structs_array(struct Param *array);

int main(int ac, char **av)
{
  struct Param *array;

  array = params_to_struct_array(ac, av);
  free_params_structs_array(array);
  return(0);
}
