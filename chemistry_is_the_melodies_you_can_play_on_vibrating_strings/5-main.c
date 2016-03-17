void reverse_array(int *a, int n);
void print_array(int *a, int n);

int main(void)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  print_array(a, sizeof(a) / sizeof(int));
  reverse_array(a, sizeof(a) / sizeof(int));
  print_array(a, sizeof(a) / sizeof(int));
  return (0);
}