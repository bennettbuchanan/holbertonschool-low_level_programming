#include <stdio.h>
#include <unistd.h>
int main()
{
write(1, "Hello C\n", 13);
  return 0;
}