void bubble_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {402, 94111, 98, -1, 0};

  print_array(array, 5);
  bubble_sort(array, 5);
  print_array(array, 5);

  return (0);
}
