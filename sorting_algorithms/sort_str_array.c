int is_sorted(char **arr);
void print_char(char);
int str_len(char *str);
int val_cmp(char *str1, char *str2);

/*
 * sort_str_array() - Sort an array of strings using the bubble sort method.
 * Use a while loop to determine when the function should end (i.e., only
 * after `is_sorted()` returns 0, indicating the strings are sorted).
 *
 * @arr: An array of char arrays.
 *
 * Return: Void.
 */
void sort_str_array(char **arr)
{
        int i;
        char *tmp;

        while (is_sorted(arr) == 1) {
                for (i = 0; arr[i + 1] != '\0'; ++i) {
                        if (val_cmp(arr[i], arr[i + 1]) == 1) {
                                tmp = arr[i];
                                arr[i] = arr[i + 1];
                                arr[i + 1] = tmp;
                        }
                }
        }
}

/*
 * is_sorted() - Determine whether an array of strings is sorted based on
 * the ascii values of the strings.
 *
 * @arr: An array of char arrays.
 *
 * Return: 1, if the strings are not sorted, 0 if they are.
 */
int is_sorted(char **arr)
{
        int i;

        for (i = 0; arr[i] != '\0'; ++i) {
                if (arr[i + 1] == '\0') {
                        break;
                }
                if (val_cmp(arr[i], arr[i + 1]) == 1) {
                        return 1;
                }
        }
        return 0;
}

/*
 * val_cmp() - Compare the values of two strings to determine if the first
 * string should be ordered before the second, based on ascii values.
 *
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: 1, if the strings are not in order, 0 if they are.
 */
int val_cmp(char *str1, char *str2)
{
        int i;
        for (i = 0; str1[i] >= str2[i]; ++i) {
                if (i > str_len(str1) || i > str_len(str2)) {
                        break;
                } else if (str1[i] > str2[i]) {
                        return 1;
                }
        }
        return 0;
}

/*
 * str_len() - Find the length of a string.
 *
 * @str: The string to find the length of.
 *
 * Return: The decimal length of the string (e.g., for "abc", return 3).
 */
int str_len(char *str)
{
        int i = 0;

        while (str[i] != '\0') {
                ++i;
        }
        return i;
}
