#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array parameter
 * @array: array to sort parameter
 */
void selection_sort(int *array, size_t size)
{
	size_t i, indx;
	int swap_item, increm = 0;
	int temp;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		increm = 0;

		for (indx = i + 1; indx < size; indx++)
		{
			if (array[temp] > array[indx])
			{
				temp = indx;
				increm += 1;
			}
		}

		swap_item = array[i];
		array[i] = array[temp];

		array[temp] = swap_item;

		if (increm != 0)
			print_array(array, size);
	}
}
