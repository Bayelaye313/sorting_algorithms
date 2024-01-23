#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *base;

	if (array == NULL || size < 2)
		return;

	base = malloc(sizeof(int) * size);
	if (base == NULL)
		return;

	merge_partition(0, size, array, base, 1);

	free(base);
}

/**
 * merge - A function that sorts the subarrays.
 * @lo: Lower index.
 * @mi: Middle index.
 * @hi: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * @debug: Flag for debugging prints.
 * Return: Nothing
 */
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src, int debug)
{
	size_t i = lo, j = mi, k = lo;

	if (debug)
	{
		printf("Merging...\n");
		printf("[left]: ");
		print_array(src + lo, mi - lo);
		printf("[right]: ");
		print_array(src + mi, hi - mi);
	}

	for (; k < hi; k++)
	{
		if (i < mi && (j >= hi || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}

	if (debug)
	{
		printf("[Done]: ");
		print_array(dest + lo, hi - lo);
	}
}

/**
 * merge_partition - A funtion that splits the array recursively.
 * @lo: Lower index.
 * @hi: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * @debug: Flag for debugging prints.
 * Return: Nothing.
 */
void merge_partition(size_t lo, size_t hi, int *array, int *base, int debug)
{
	size_t mi;

	if (hi - lo < 2)
		return;

	mi = (lo + hi) / 2;

	merge_partition(lo, mi, array, base, debug);
	merge_partition(mi, hi, array, base, debug);
	merge(lo, mi, hi, array, base, debug);

	for (mi = lo; mi < hi; mi++)
		base[mi] = array[mi];
}
