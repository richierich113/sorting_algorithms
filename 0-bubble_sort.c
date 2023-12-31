#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array parameter
 * @size: array size parameter
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, indx, temp_holder1, temp_holder2;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (indx = 0; indx < size - i - 1; indx++)
		{
			if (array[indx] > array[indx + 1])
			{
				temp_holder1 = array[indx];
				temp_holder2 = array[indx + 1];
				array[indx] = temp_holder2;
				array[indx + 1] = temp_holder1;
				print_array(array, size);
			}
		}
	}
}
