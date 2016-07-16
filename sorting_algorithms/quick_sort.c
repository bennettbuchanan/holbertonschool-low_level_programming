#include <stdio.h>

void print_array(int *, int);
void move_pivot(int *arr, int i, int is_last);
void recursive_call(int, int *, int);

void quick_sort(int *arr, int len)
{
        int i, j, tmp;

        for (i = 1; i < len; ++i) {
                /* Case where all elements are less than the pivot. */
                if (i + 1 == len && arr[i] < arr[0]) {
                        move_pivot(arr, i, 0);
                        break;
                }
                if (arr[i] > arr[0]) {
                        /* Case where all elements except the last are less
                         * than the pivot element.
                         */
                        if (i == len - 1) {
                                move_pivot(arr, i, 1);
                                break;
                        }
                        for (j = i + 1; j < len; ++j) {
                                while (arr[j] < arr[i] && arr[j] < arr[0]) {
                                        /* Swap the values. */
                                        tmp = arr[i];
                                        arr[i] = arr[j];
                                        arr[j] = tmp;
                                        ++j;
                                        ++i;
                                        if (j == len) {
                                                --j;
                                                break;
                                        }
                                }
                                if (j + 1 == len) {
                                        /* Move pivot to center. */
                                        move_pivot(arr, i, 1);
                                        break;
                                }
                        }
                        if (j + 1 == len) {
                                break;
                        }
                }
        }
        recursive_call(i, arr, len);
}

void recursive_call(int i, int *arr, int len)
{
        /* Sort arrays recursively to the left. */
        if (i - 1 > 1) {
                quick_sort(arr, i - 1);
        }
        /* Sort arrays recursively to the right. */
        if (len - i > 1) {
                quick_sort(arr + i, len - i);
        }
}

void move_pivot(int *arr, int i, int is_last)
{
        int tmp;
        if (is_last == 0) {
                tmp = arr[0];
                arr[0] = arr[i];
                arr[i] = tmp;
        } else {
                tmp = arr[0];
                arr[0] = arr[i - 1];
                arr[i - 1] = tmp;
        }
}
