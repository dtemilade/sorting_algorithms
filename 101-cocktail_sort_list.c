#include "sort.h"

/**
 * swap_adj - prototype that swaps two adjacent nodes of a doubly linked list
 * @list: parameter for doubly linked list of integers to be sorted
 * @lft: parameter for node closer to head
 * @ryt: parameter for node closer to tail
 * Return: no return
 */
void swap_adj(listint_t **list, listint_t *lft, listint_t *ryt)
{
/*introducing parameter*/
listint_t *swap;

/*swapping process with conditional statement*/
if (lft->prev)
lft->prev->next = ryt;
else
*list = ryt;
if (ryt->next)
ryt->next->prev = lft;
ryt->prev = lft->prev;
lft->prev = ryt;
swap = ryt;
lft->next = ryt->next;
swap->next = lft;

print_list(*list);
}

/**
 * cocktail_sort_list - prototype that sorts a doubly linked list of integers
 * @list: parameter for doubly linked list of integers to be sorted
 * Return: no return */
void cocktail_sort_list(listint_t **list)
{
listint_t *tmp;
bool frnt, bk;
int adjst = 1000000, ind;

/*check for error*/
if (!list || !(*list) || !(*list)->next)
return;

/*conditional statement for cocktail*/
tmp = *list;
do {
frnt = bk = false;
for (ind = 0; tmp->next && ind < adjst; ind++)
{
if (tmp->next->n < tmp->n)
{
swap_adj(list, tmp, tmp->next);
frnt = true;
}
else
tmp = tmp->next;
}
if (!tmp->next)
adjst = ind;
if (frnt)
tmp = tmp->prev;
adjst--;
for (ind = 0; tmp->prev && ind < adjst; ind++)
{
if (tmp->n < tmp->prev->n)
{
swap_adj(list, tmp->prev, tmp);
bk = true;
}
else
tmp = tmp->prev;
}
if (bk)
tmp = tmp->next;
}
while (frnt || bk);
}
