#include "search_algos.h"

/**
 * binary_search - calls to binary_search
 * to return the index of the number
 * @array: input array
 * @size: size of the array
 * @value: value to search for
 * Return: index of the number
 */

int binary_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	size_t start = 0;
	size_t end = size - 1;

	while (start <= end)
	{
		size_t middle = (start + end) / 2;

		printf("Searching in array: ");

		for (size_t i = start; i <= end; i++)
		{
			if (i == start)
				printf("%d", array[i]);
			else
				printf(", %d", array[i]);
		}
		printf("\n");

		if (array[middle] == value)
		{
			printf("Found %d at index: %d", value, array[middle]);
			return (middle);
		}
		else if (array[middle] < value)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	printf("Found %d at index: -1\n", value);
	return (-1);
}
