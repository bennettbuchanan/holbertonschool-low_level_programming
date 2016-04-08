int (*get_op_func(char c))(int, int);
int (*functionPtr)(int x, int y);

int (*get_op_func(char c))(int, int) {
    /* return a pointer to a function */
    return functionPtr;
    if (c == '+') {
      return functionPtr;
    }
}
