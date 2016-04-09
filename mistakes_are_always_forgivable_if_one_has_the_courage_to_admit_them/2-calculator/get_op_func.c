int (*get_op_func(char c))(int, int);
int (*functionPtr)(int x, int y);
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

int (*get_op_func(char c))(int, int) {
    int i;
    int (*p[5]) (int a, int b);
    char op_array[5];
    /* return a pointer to a function */
    p[0] = op_add;
    p[1] = op_sub;
    p[2] = op_mul;
    p[3] = op_div;
    p[4] = op_mod;
    op_array[0] = '+';
    op_array[1] = '-';
    op_array[2] = '*';
    op_array[3] = '/';
    op_array[4] = '%';
    for (i = 0; i < 5; i++) {
      if (c == op_array[i]) {
        int (*functionPtr)(int x, int y) = p[i];
        return functionPtr;
        break;
      }
    }
  return 0;
}
