/*
 * insertion_sort() - Orders an array using an insertion sort method.
 * @arr: The array to rearrange.
 * @len: The length of the array.
 *
 * Return: Void.
 */
void insertion_sort(int *arr, int len)
{
        int i, j, k;

        for (i = 0; i < len; ++i) {
                for (j = i; j > 0; --j) {
                        k = i;
                        while (arr[k] < arr[k - 1] && k != 0) {
                                arr[len] = arr[k];
                                arr[k] = arr[k - 1];
                                arr[k - 1] = arr[len];
                                --k;
                        }
                }
        }
        arr[len] = '\0';
}
