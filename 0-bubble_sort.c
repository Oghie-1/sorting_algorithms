#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;
int swapped;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{

/* Flag to optimize for already sorted array */
swapped = 0;
for (j = 0; j < size - 1 - i; j++)
{
if (array[j] > array[j + 1])
{
/* Swap array[j] and array[j+1] */
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;

/* Mark that a swap occurred */ 
swapped = 1;
print_array(array, size);
}
}

/* If no two elements were swapped in inner loop, array is already sorted */
if (swapped == 0)
break;
}
}
