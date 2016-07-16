/*
 * bubble_sort() - Orders an array using the bubble sort method.
 * @arr: The array to be sorted.
 * @len: The length of the array.
 *
 * Return: Void.
 */
void bubble_sort(int *arr, int len)
{
        int i;
        int is_sorted = 1;

        while (is_sorted == 1) {
                is_sorted = 0;
                for (i = 0; i < len - 1; ++i) {
                        if (arr[i + 1] < arr[i]) {
                                arr[len] = arr[i];
                                arr[i] = arr[i + 1];
                                arr[i + 1] = arr[len];
                                is_sorted = 1;
                        }
                }
        }
        arr[len] = '\0';
}
