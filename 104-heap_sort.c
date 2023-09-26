#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * max_heapify - Maintain the max heap property of a binary tree.
 * @array: An array representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The index of the root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
    size_t left, right, largest;

    left = 2 * root + 1;
    right = 2 * root + 2;
    largest = root;

    if (left < base && array[left] > array[largest])
        largest = left;
    if (right < base && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap_ints(array + root, array + largest);
        print_array(array, size);
        max_heapify(array, size, base, largest);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm.
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    /* Build a max heap */
    for (i = (size / 2) - 1; i >= 0; i--)
        max_heapify(array, size, size, i);

    /* Extract elements from the heap one by one */
    for (i = size - 1; i > 0; i--)
    {
        swap_ints(array, array + i);
        print_array(array, size);
        max_heapify(array, size, i, 0);
    }
}
