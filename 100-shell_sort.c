#include "sort.h"

/**
 * shell_sort - A function that sorts an array using Shell sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	unsigned int gap = 1;
	int temp, i, j;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
