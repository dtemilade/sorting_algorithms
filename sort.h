#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void swap(int *a, int *b);
void arr_sort(int *array, unsigned int i, unsigned int     j, size_t size);
unsigned int sect(int *array, size_t i, size_t j, size_t size);
void Ind_Arr(int *array, int fst, int lst);
void Arr_Cpy(int *frm, int fst, int lst, int *dest);
void Merge_Down(int *frm, int fst, int MidPt, int lst, int *dest);
void Merge_Down_Split(int *frm, int fst, int lst, int *dest);
void swap_adj(listint_t **list, listint_t *lft, listint_t *ryt);


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/* void sort_deck(deck_node_t **deck); */

#endif
