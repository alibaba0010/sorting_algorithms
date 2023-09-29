#include "sort.h"

/**
 * swap_ints - It swaps two integers in an array.
 * @a: The 1st integer to swap.
 * @b: The 2nd integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending
 * order.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, x, y;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (x = gap; x < size; x++)
		{
			y = x;
			while (y >= gap && array[y - gap] > array[y])
			{
				swap_ints(array + y, array + (y - gap));
				y -= gap;
			}
		}
		print_array(array, size);
	}
}
