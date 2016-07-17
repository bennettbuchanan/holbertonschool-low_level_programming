int move_pivot(int *arr, int i, int is_last);
void recursive_call(int, int *, int);
int pivot_edge_cases(int *arr, int i, int len);

/*
 * quick_sort() - Iterates through an array and calls `move_pivot()`
 * according to the relative value to the array. Before the pivot element is
 * moved, however, this function will call `swap_val()` however many times
 * necessary to prepare the array for the pivot move. Once, this has all
 * occurred, the function calls itself recursively.
 *
 * @arr: The array to be sorted.
 * @len: The length of the array.
 *
 * Return: Void.
 */
void quick_sort(int *arr, int len)
{
        int i, j, tmp;
        int pivoted = 1;

        for (i = 1; i < len; ++i) {
                if (arr[i] >= arr[0]) {
                        for (j = i + 1; j < len; ++j) {
                                if (arr[j] < arr[i] && arr[j] < arr[0]) {
                                        tmp = arr[i]; /* Swap the values. */
                                        arr[i] = arr[j];
                                        arr[j] = tmp;
                                        ++i;
                                }
                        }
                        if (j >= len - 1) {
                                pivoted = move_pivot(arr, i, 1);
                                break;
                        }
                }
                pivoted = pivot_edge_cases(arr, i, len);
        }
        if (pivoted == 0) {
                recursive_call(i, arr, len);
        }
}

 /*
  * pivot_edge_cases() - Handles edge cases related to the pivot element. If
  * all elements < pivot, call move_pivot. Or if all elements except the last
  * are < pivot element, call move pivot.
  *
  * @arr: The array with which to swap the values.
  * @i: The the element of the array from which to iterate through.
  * @len: The length of the array.
  *
  * Return: The value of `move_pivot()` (i.e., 0) if called, or 1.
  */
int pivot_edge_cases(int *arr, int i, int len)
{
        if (i == len - 1 && arr[i] < arr[0]) {
                return move_pivot(arr, i, 0);
        } else if (i == len - 1 && arr[i] > arr[0]) {
                return move_pivot(arr, i, 1);
        }
        return 1;
}

/*
 * recursive_call() - If the array has at least two elements, call
 * `quick_sort()` for each side of the array's pivot element.
 *
 * @arr: The array with which to swap the values.
 * @i: The the element of the array from which to iterate through.
 * @len: The length of the array.
 *
 * Return: Void.
 */
void recursive_call(int i, int *arr, int len)
{
        /* Call `quick_sort()` for the array to the left of the sorted pivot
         * element.
         */
        if (i - 1 > 1) {
                quick_sort(arr, i - 1);
        }
        /* Call `quick_sort()` for the array to the right of the sorted pivot
         * element.
         */
        if (len - i > 1) {
                quick_sort(arr + i, len - i);
        }
}

/*
 * move_pivot() - Moves the current pivot point to it's sorted location in the
 * array.
 *
 * @arr: The array with which to swap the values.
 * @i: The the element of the array from which to iterate through.
 * @is_last: This value must be 0 if the pivot is the greatest element in the
 * array (in which case, the pivot element is moved to the last element of the
 * array). The value must be 1 if the pivor is not the greatest element in the
 * array (in which case, the pivot element is moved to the element immediately
 * preceding i).
 *
 * Return: Void.
 */
int move_pivot(int *arr, int i, int is_last)
{
        int tmp;

        tmp = arr[0];
        arr[0] = arr[i - is_last];
        arr[i - is_last] = tmp;

        return 0;
}
