void array_iterator(int *array, int size, void (*action_func)(int)) {
  int i;
  /* for every iteration, send the array item to function */
  for (i = 0; i < size; i++) {
    action_func(array[i]);
  }
}
