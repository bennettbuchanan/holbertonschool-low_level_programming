void swap_int(int *a, int *b)
{
  int temp;
  /* store the value located at address of a */
  temp = *a;
  /* reassign the value of *a to the value of *b */
  *a = *b;
  *b = temp;
}
