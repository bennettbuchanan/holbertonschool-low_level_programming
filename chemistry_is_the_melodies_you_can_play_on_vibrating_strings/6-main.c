#include <stdio.h>

void print(int *a)
{
    printf("%lu, %lu, ", sizeof(a), sizeof(*a));
}

int main(void)
{
    int a[3];

    print(a);
    printf("%lu, %lu\n", sizeof(a), sizeof(*a));
    return (0);
}