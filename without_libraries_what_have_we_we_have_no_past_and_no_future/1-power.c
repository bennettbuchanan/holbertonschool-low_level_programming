int power(int x, int y) {
  long z;
  if (y < 0 || x < 0) {
    return -1;
  }
  if (y == 0) {
    return 1;
  }
  if (y == 1) {
    return x;
  }
  y -= 1;
  z = x * power(x, y);
  if (z > 2147483647) {
    return -1;
  }
  if (z < 0) {
    return -1;
  }
  return x * power(x, y); /* recursively call the function */
}
