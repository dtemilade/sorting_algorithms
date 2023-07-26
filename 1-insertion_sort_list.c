#include "sort.h"

/**
 * swap_nodes - prototypes that swap nodes in a listint_t doubly-linked list.
 * @h: pointer parameter for head of the doubly-linked list.
 * @n1: pointer parameter for node 1.
 * @n2: pointer parameter for node 2.
 * Return: no return
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
/*swapping process with conditional statement*/
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;
if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;
else
*h = n2;
(*n1)->prev = n2;
*n1 = n2->prev;
}


/**
 * insertion_sort_list - prototype that sorts integers doubly linked list
 * @list: A pointer to the head of the doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
/*introducing parameters*/
listint_t *x, *new, *tmp;

/*check for error*/
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

/*process with conditional statement*/
for (x = (*list)->next; x != NULL; x = tmp)
{
tmp = x->next;
new = x->prev;
while (new != NULL && x->n < new->n)
{
swap_nodes(list, &new, x);
print_list((const listint_t *)*list);
}
}

}
