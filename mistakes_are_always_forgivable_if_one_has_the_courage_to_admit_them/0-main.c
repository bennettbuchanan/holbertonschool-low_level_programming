#include <stdio.h>
void array_iterator(int *, int, void (*)(int));

void action(int elem)
{
  printf("%d\n", elem);
}

int main(void)
{
  int array[6] = {98, 402, 35, 42, 1024, 64};

  array_iterator(array, 6, &action);
  return (0);
}
