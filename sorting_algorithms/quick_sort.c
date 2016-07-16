#include <stdio.h>

void print_array(int *, int);
int move_pivot(int *arr, int i, int is_last);
void recursive_call(int, int *, int);

void quick_sort(int *arr, int len)
{
        int i, j, tmp;
        int pivot = 1;

        for (i = 1; i < len; ++i) {
                if (arr[i] >= arr[0]) {
                        for (j = i + 1; j < len; ++j) {
                                if (arr[j] < arr[i] && arr[j] < arr[0]) {
                                        /* Swap the values. */
                                        tmp = arr[i];
                                        arr[i] = arr[j];
                                        arr[j] = tmp;
                                        ++i;
                                }
                                if (j == len - 1) {
                                        break;
                                }
                        }
                        if (j >= len - 1) {
                                pivot = move_pivot(arr, i, 1);
                                break;
                        }
                }
                /* All elements < pivot. */
                if (i == len - 1 && arr[i] < arr[0]) {
                        pivot = move_pivot(arr, i, 0);
                } else if (i == len - 1 && arr[i] > arr[0]) {
                        /* All elements except last are < pivot element. */
                        pivot = move_pivot(arr, i, 1);
                }
        }
        if (pivot == 0) {
                recursive_call(i, arr, len);
        }
}

void recursive_call(int i, int *arr, int len)
{
        /* Sort arrays recursively to the left. */
        if (i - 1 > 1) {
                printf("\nleft: \n");
                print_array(arr, i - 1);
                quick_sort(arr, i - 1);
        }
        /* Sort arrays recursively to the right. */
        if (len - i > 1) {
                printf("\nright: \n");
                print_array(arr + i, len - i);
                quick_sort(arr + i, len - i);
        }
}

int move_pivot(int *arr, int i, int is_last)
{
        int tmp;
        if (is_last == 0) {
                tmp = arr[0];
                arr[0] = arr[i];
                arr[i] = tmp;
        }
        if (is_last == 1) {
                tmp = arr[0];
                arr[0] = arr[i - 1];
                arr[i - 1] = tmp;
        }
        return 0;
}
