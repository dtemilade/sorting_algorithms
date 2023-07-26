#include "sort.h"

/**
 * shell_sort - prototype that sorts an array of integers
 * @array: parameter for array
 * @size: size parameter for array
 *
 * Description: sorts an array of integers in ascending order using the shell
 *
 * Return: no return
 */

void shell_sort(int *array, size_t size)
{
/*Introducing parameters*/
int retval;
unsigned int z, a, dist = 1;

/*check for error*/
if (!array || size < 2)
return;

/*conditional statement for the shell sort*/
while (dist < size / 3)
dist = dist * 3 + 1;

while (dist)
{
for (a = dist; a < size; a++)
{
retval = array[a];
z = a;

while (z > dist - 1 && array[z - dist] >= retval)
{
array[z] = array[z - dist];
z = z - dist;
}

array[z] = retval;
}
dist = (dist - 1) / 3;
print_array(array, size);
}
}
