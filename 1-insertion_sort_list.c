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
			swapper(list, &prev_node, nxt_node);
			print_list((const listint_t *)*list);
		}
	}
}


/**
 * swapper - Swap two nodes in doubly-linked list.
 * @h: A pointer to doubly-linked list parameter
 * @first_node: A pointer to the first node to swap parameter
 * @sec_node: The second node to swap parameter
 */
void swapper(listint_t **h, listint_t **first_node, listint_t *sec_node)
{
	(*first_node)->next = sec_node->next;

	if (sec_node->next != NULL)
		sec_node->next->prev = *first_node;

	sec_node->prev = (*first_node)->prev;
	sec_node->next = *first_node;

	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = sec_node;
	else
		*h = sec_node;


	(*first_node)->prev = sec_node;
	*first_node = sec_node->prev;
}
