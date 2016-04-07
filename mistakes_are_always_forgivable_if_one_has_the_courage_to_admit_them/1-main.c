#include <stdio.h>
int advanced_search(int *, int, int (*)(int));

int check(int a)
{
  return (a == 402);
}

int check2(int a)
{
  return (a == 201);
}

int main(void)
{
  int array[6] = {98, 402, 35, 402, 1024, 64};

  printf(
"%d\n", advanced_search(array, 6, &check));
  printf("%d\n", advanced_search(array, 6, &check2));
  return (0);
}
