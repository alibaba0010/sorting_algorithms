#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int max, u;

	for (max = array[0], u = 1; u < size; u++)
	{
		if (array[u] > max)
			max = array[u];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, x;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (x = 0; x < (max + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[i]] += 1;
	for (x = 0; x < (max + 1); x++)
		count[x] += count[x - 1];
	print_array(count, max + 1);

	for (x = 0; x < (int)size; x++)
	{
		sorted[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
