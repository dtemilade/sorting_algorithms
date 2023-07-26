#include "sort.h"

/**
 * quick_sort - prototypes that sorts an array in ascending order;
 * @array: unsort array
 * @size: size of the array
 *
 * Description: array is sort using the quick sort algorithm
 * Returns: no return
 */

void quick_sort(int *array, size_t size)
{
/*check for error*/
if (!array || size < 2)
return;

arr_sort(array, 0, size - 1, size);
}

/**
 * arr_sort - prototype that sort array using quick sort
 * @array: array to be sort
 * @i: least index of array
 * @j: highest index of array
 * @size: size of the array
 * Returns: no return
 */

void arr_sort(int *array, unsigned int i, unsigned int j, size_t size)
{
/*introducing parameter*/
unsigned int x;


/*conditional statement for array sort process*/
if (i < j)
{
x = sect(array, i, j, size);
if (x != 0)
arr_sort(array, i, x - 1, size);
arr_sort(array, x + 1, j, size);
}
}

/**
 * sect - prototype that places pivot at correct position in an array
 * @array: array to be sort
 * @i: least index of array
 * @j: highest index of array
 * @size: size of the array
 * Return: the index of pivot
 */

unsigned int sect(int *array, size_t i, size_t j, size_t size)
{
/*introducing parameter*/
int p, q, pivot;

pivot = array[j];
p = i - 1;

/*conditional statement for array sort process*/
for (q = i; q < (int)j; q++)
{
if (array[q] < pivot)
{
p++;
if (p != q)
{
swap(&array[p], &array[q]);
print_array(array, size);
}
}
}

if (array[j] < array[p + 1])
{
swap(&array[i + 1], &array[j]);
print_array(array, size);
}
return (p + 1);
}

/**
 * swap - prototypes that swaps the integer values
 * @a: parameter for first integer
 * @b: parameter for second integer
 * Return: no return
 */
void swap(int *a, int *b)
{
/*introducing parameter*/
int tmp;

/*swapping process*/
tmp = *a;
*a = *b;
*b = tmp;
}
