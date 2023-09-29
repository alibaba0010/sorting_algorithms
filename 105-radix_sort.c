#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

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
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t u;

	for (u = 0; u < size; u++)
		count[(array[u] / sig) % 10] += 1;

	for (u = 0; u < 10; u++)
		count[u] += count[u - 1];

	for (u = size - 1; (int)u >= 0; u--)
	{
		buff[count[(array[u] / sig) % 10] - 1] = array[u];
		count[(array[u] / sig) % 10] -= 1;
	}

	for (u = 0; u < size; u++)
		array[u] = buff[u];
}

/**
 * radix_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
