#include "sort.h"

/**
 * swapper - Swap two nodes in doubly-linked list.
 * @h: A pointer to doubly-linked list parameter
 * @first_node: A pointer to the first node to swap.
 * @sec_node: The second node to swap.
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
