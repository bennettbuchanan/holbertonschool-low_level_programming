int advanced_search(int *array, int size, int (*action_func)(int)) {
  int i, num;
  /* For every iteration, send the array item to function */
  for (i = 0; i < size; i++) {
    num = action_func(array[i]);
    /* If the check returns true, return the array element */
    if (num == 1) {
      return (i);
    }
  }
  return (-1);
}
