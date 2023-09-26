#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	/* Initialize 'max' to the first element of the array */
	for (max = array[0], i = 1; i < size; i++)
	{
		/* Update 'max' if a larger value is encountered */
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description:
 * - Prints the counting array after setting it up.
 * - Allocates memory for a sorted array.
 * - Counts the occurrences of each element in 'count'.
 * - Modifies the original array based on the sorted values.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	/* Allocate memory for the sorted array */
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	/* Find the maximum value in the input array */
	max = get_max(array, size);

	/* Allocate memory for the counting array 'count' */
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	/* Initialize counting array 'count' to all zeros */
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	/* Count the occurrences of each element in the input array */
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	/* Print the counting array 'count' */
	print_array(count, max + 1);

	/* Calculate cumulative counts in 'count' */
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];

	/* Rearrange elements in the sorted array */
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	/* Free dynamically allocated memory */
	free(sorted);
	free(count);
}
