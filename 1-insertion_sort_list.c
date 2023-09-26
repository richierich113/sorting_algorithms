#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: doubly-linked list parameter
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev_node, *temp;
	listint_t *nxt_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (nxt_node = (*list)->next; nxt_node != NULL; nxt_node = temp)
	{
		temp = nxt_node->next;

		prev_node = nxt_node->prev;

		while (prev_node != NULL && nxt_node->n < prev_node->n)
		{
			swap_nodes(list, &prev_node, nxt_node);
			print_list((const listint_t *)*list);
		}
	}
}
