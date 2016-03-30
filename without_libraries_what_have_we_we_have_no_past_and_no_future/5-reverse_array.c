void reverse_array(int *a, int n)
{
  int temp;
  int half;
  int i;
  n -= 1;
  half = n / 2;
  for (i = 0; n > half; n--)
  {
  	temp = a[n]; /* store last char in temp */
  	a[n] = a[i]; /* assign last character as first */
  	a[i] = temp; /* assign first character as temp */
  	i++; 
  }
}