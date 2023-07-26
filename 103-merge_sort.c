#include "sort.h"

/**
 * Ind_Arr - prototype that prints array of integers for range of indicies
 * @array: parameter for array of values to be printed
 * @fst: parameter for starting index value
 * @lst: parameter for ending index value
 * Return: no return
 */
void Ind_Arr(int *array, int fst, int lst)
{
/*introducing parameter*/
int k;

/*conditional statement for the process*/
for (k = fst; k < lst; k++)
if (k < lst - 1)
printf("%i, ", array[k]);
else
printf("%i\n", array[k]);
}

/**
 * Arr_Cpy - prototype for simple 1 for 1 copy of source[] to dest[]
 * @frm: parameter for array of values to be sorted
 * @fst: parameter for starting index value
 * @lst: parameter for ending index value
 * @dest: parameter for array to store sorted integers
 * Return: no return */
void Arr_Cpy(int *frm, int fst, int lst, int *dest)
{
/*introducing parameter*/
int k;

/*conditional statement for the process*/
for (k = fst; k < lst; k++)
dest[k] = frm[k];
}

/**
 * Merge_Down - prototype that sorts subsections ("runs") of source[] by ascending value
 * @frm: parameter for array of values to be sorted
 * @fst: parameter for left run starting index value
 * @MidPt: parameter for right run starting index value
 * @lst: parameter for right run ending index value
 * @dest: parameter for array to store sorted integers
 * Return: no return
 */	
void Merge_Down(int *frm, int fst, int MidPt, int lst, int *dest)
{
/*introducing parameters*/
int k, j, l;

k = fst, j = MidPt;

printf("Merging...\n");
printf("[left]: ");
Ind_Arr(frm, fst, MidPt);
printf("[right]: ");
Ind_Arr(frm, MidPt, lst);
/*conditions when elements still remains*/
for (l = fst; l < lst; l++)
{
if (k < MidPt && (j >= lst || frm[k] <= frm[j]))
{
dest[l] = frm[k];
k++;
}
else
{
dest[l] = frm[j];
j++;
}
}
printf("[Done]: ");
Ind_Arr(dest, fst, lst);
}

/**
 * Merge_Down_Split - prototype that recursive engine of merge_sort
 * @frm: parameter for array of integers to be sorted
 * @fst: parameter for starting index value
 * @lst: parameter for ending index value
 * @dest: parameter for array to store sorted integers
 * Return: no return
 */
void Merge_Down_Split(int *frm, int fst, int lst, int *dest)
{
int MidPt;

if (lst - fst < 2)
return;
/* split the run longer than 1 item into halves */
MidPt = (lst + fst) / 2;

Merge_Down_Split(dest, fst, MidPt, frm);
Merge_Down_Split(dest, MidPt, lst, frm);  
Merge_Down(frm, fst, MidPt, lst, dest);
}

/**
 * merge_sort - prototype that sorts an array of integers in ascending order
 * @array: parameter for array of integers to be sorted
 * @size: parameter for amount of elements in array
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
int *q;

if (!array || size < 2)
return;

q = malloc(sizeof(int) * size);
if (!q)
return;

Arr_Cpy(array, 0, size, q);
Merge_Down_Split(q, 0, size, array);

free(q);
}
