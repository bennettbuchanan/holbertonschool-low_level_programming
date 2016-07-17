void quick_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {-9, 1, 0, 0, -2, -9, -9};

  print_array(array, 7);
  quick_sort(array, 7);
  print_array(array, 7);
  return (0);
}
