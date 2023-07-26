#include "sort.h"

/**
 * counting_sort - prototype that sort out array with counting sort
 * @array: input array, contains integers
 * @size: Size of array
 * Return: no return
 */

void counting_sort (int *array, size_t size)
{
	/*introducing parameters*/
	int  j, l, *iter, *retval, h = 0;
	size_t m, n, i, k;

	/*check for error*/
	if (!array || size < 2)
		return;

	/* check for maximum number*/
	for (i = 0; i < size; i++)
	{
		if (array[i] > h)
			h = array[i];
	}
	/*iteration process*/
	iter = malloc((h + 1) * sizeof(size_t));
	for (j = 0; j <= h; j++)
		iter[j] = 0;
	for (k = 0; k < size; k++)
		iter[array[k]]++;
	for (l = 1; l <= h; l++)
		iter[l] += iter[l - 1];
	/*process completed, print array */
	print_array(iter, h + 1);
	retval = malloc(size * sizeof(int));

	/*positioning the output in array */
	for (m = 0; m < size; m++)
	{
		retval[iter[array[m]] - 1] = array[m];
		iter[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = retval[n];

	/*frees the memory */
	free(iter);
	free(retval);
}
