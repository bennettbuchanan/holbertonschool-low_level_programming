#include <stdlib.h>
#include <unistd.h>

int find_len(char *str);

char **string_split(char *str) {
  int i, j, len;
  int k = 0;
  char **str_arr;
  len = find_len(str);
  str_arr = malloc(sizeof(char **) * 5);
  if (str_arr == NULL) {
    return (NULL);}
  for (i = 0; i < 5; i++) { /* Allot memory for each char in the array */
    str_arr[i] = malloc(sizeof(char) * 10);
    if (str_arr[i] == NULL) {
      return (NULL);}
  }
  for (i = 0; i < len; i++) { /* Assign decimals to the str_arr array */
    if (str[i] == ' ' && str[i + 1] != ' ') {
      if (str[i + 1] != '\0') {
        k++;
        j = 0;}}
    if (str[i] != ' ') {
      str_arr[k][j] = str[i];
      j++;}
  }
  str_arr[k + 1] = NULL;
  return (str_arr);
}

int find_len(char *str) {
  int i = 0;

  /* Find the length of a string */
  while (str[i] != '\0') {
    i++;
  }
  return i;
}
