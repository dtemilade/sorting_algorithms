#include "sort.h"

/**
 * bubble_sort - prototypes that sorts an array in ascending order;
 * @array: unsort array
 * @size: size of the array
 *
 * Description: array is sort using the bubble sort algorithm
 *
 * Return: no return
 */

void bubble_sort(int *array, size_t size)
{
int tmp;
unsigned int i, j, swap, sort = 0;

/*check for error*/
if (!array || size < 2)
return;

/*conditional statement for bubble*/
for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - 1; j++)
{
/*compare process with swap checker*/
swap = 0;
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
swap = 1;
sort = 1;
}

/*array list upon swapping*/
if (swap)
print_array(array, size);

}

if (!sort)
return;

}
}
