void insertion_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {402, -94111, 0, 12, -1};

  print_array(array, 5);
  insertion_sort(array, 5);
  print_array(array, 5);
  return (0);
}
