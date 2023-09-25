#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */


void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The pivot index.
 */


int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
swap(&array[i], &array[j]);
print_array(array, size);
}
}

swap(&array[i + 1], &array[high]);
print_array(array, size);
return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the quicksort algorithm.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */


void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_idx = lomuto_partition(array, low, high, size);
quicksort(array, low, pivot_idx - 1, size);
quicksort(array, pivot_idx + 1, high, size);
}
}

/**
 * quick_sort - Initiates the quicksort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */


void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort(array, 0, size - 1, size);
}
