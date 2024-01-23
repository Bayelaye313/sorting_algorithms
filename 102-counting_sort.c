#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void counting_sort(int *array, size_t size);
void counting_sort(int *array, size_t size)
{
	int j, max = array[0];
	int *count_array, *tmp;
	size_t i;

	if (!array || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = calloc(max + 1, sizeof(int));
	tmp = malloc(size * sizeof(int));

	if (!count_array || !tmp)
	{
		free(count_array);
		free(tmp);
		return;
	}

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (j = 1; j <= max; j++)
		count_array[j] += count_array[j - 1];

	print_array(count_array, max + 1);

	for (i = size; i > 0; i--)
	{
		count_array[array[i - 1]]--;
		tmp[count_array[array[i - 1]]] = array[i - 1];
	}

	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	free(tmp);
	free(count_array);
}
