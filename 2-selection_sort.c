#include "sort.h"

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

/**
 * selection_sort - prototypes that arranges an array in descending order
 * @array: the array
 * @size: the length of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
/*introducing parameters*/
size_t i, low, j;

/*conditional statement for selection process*/
for (i = 0; i < size - 1; i++)
{
low = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[low])
low = j;
}
if (low != i)
{
swap(&array[i], &array[low]);
print_array(array, size);
}
}
}
