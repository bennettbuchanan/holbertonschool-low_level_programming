#include <stdio.h>
#include <stdlib.h>
#include "param_struct.h"

int find_len(char *str);
char **string_split(char *, int);

struct Param *params_to_struct_array(int ac, char **av)
{
  struct Param *array;
  int i, len;
  char *param;
  array = malloc(sizeof(struct Param) * ac);
  if (array == NULL)
    return (NULL);

  /* For each argument, assign the values. */
  for(i = 0; i < ac; ++i) {
    len = find_len(av[i]);
    array[i].str = av[i];
    array[i].length = len;
    array[i].copy = array[i].str;
    param = malloc(sizeof(char) * (len + 1));
    if (param == NULL)
      return (NULL);
    param = av[i];
    array[i].tab = string_split(av[i], len);
  }
  array[i].str = NULL;
  return(array);
}

char **string_split(char *str, int len) {
  int i, j;
  int k = 0;
  char **str_arr = (char **)malloc((len + 1) * sizeof(char *));
  if (str_arr == NULL)
    return (NULL);
  for (i = 0; i < len; i++) {
    str_arr[i] = malloc(sizeof(char *));
    if (str_arr[i] == NULL)
      return (NULL);

  }
  for (i = 0; i < len; i++) { /* Place the values within the array. */
    if (str[i] == ' ' && str[i + 1] != ' ') {
      if (str[i + 1] != '\0') {
        k++;
        j = 0;
      }
    }
    if (str[i] != ' ') {
      str_arr[k][j] = str[i];
      j++;
    }
  }
  str_arr[k + 1] = NULL;

  return (str_arr);
}

int find_len(char *str)
{
  int i = 0;

  /* Increment through the string until NULL terminator. */
  while (str[i] != '\0') {
    ++i;
  }

  /* Var i is now the length of the string passed. */
  return (i);
}
