#include "sort.h"
#define MIN_SIZE 10

/**
 * partition - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: i
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;

	for (int j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				array[i] ^= array[j];
				array[j] ^= array[i];
				array[i] ^= array[j];
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[hi])
	{
		array[i + 1] ^= array[hi];
		array[hi] ^= array[i + 1];
		array[i + 1] ^= array[hi];
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		if (hi - lo + 1 <= MIN_SIZE)
		{
			insertion_sort(array + lo, hi - lo + 1, size);
			return;
		}

		int pivot = partition(array, lo, hi, size);

		quick_s(array, lo, pivot - 1, size);
		quick_s(array, pivot + 1, hi, size);
	}
}
