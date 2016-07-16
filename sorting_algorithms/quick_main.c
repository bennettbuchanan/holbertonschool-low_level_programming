void quick_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {8, 1, 5, 3, 2, 7, 6};

  print_array(array, 7);
  quick_sort(array, 7);
  print_array(array, 7);
  return (0);
}
