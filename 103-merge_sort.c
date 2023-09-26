#include "sort.h"

/**
 * merge_subarr - Merge two subarrays into a single sorted subarray.
 * @subarr: The original array containing two sorted subarrays.
 * @buff: A buffer to store the merged subarray.
 * @front: The front index of the first subarray.
 * @mid: The middle index (end of the first subarray).
 * @back: The back index of the second subarray.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
                  size_t back)
{
    size_t i, j, k = 0;

    printf("Merging...\n[left]: ");
    print_array(subarr + front, mid - front);

    printf("[right]: ");
    print_array(subarr + mid, back - mid);

    for (i = front, j = mid; i < mid && j < back; k++)
        buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
    for (; i < mid; i++)
        buff[k++] = subarr[i];
    for (; j < back; j++)
        buff[k++] = subarr[j];
    for (i = front, k = 0; i < back; i++)
        subarr[i] = buff[k++];

    printf("[Done]: ");
    print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: The subarray to be sorted.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_recursive(subarr, buff, front, mid);
        merge_sort_recursive(subarr, buff, mid, back);
        merge_subarr(subarr, buff, front, mid, back);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    int *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    merge_sort_recursive(array, buff, 0, size);

    free(buff);
}