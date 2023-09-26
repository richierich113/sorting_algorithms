#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list parameter
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nxt_node;

	if (list == NULL || (*list)->next == NULL)
		return;

	nxt_node = (*list)->next;

	while (nxt_node)
	{
		while ((nxt_node->prev) && (nxt_node->prev->n > nxt_node->n))
		{
			nxt_node = swap_node(nxt_node, list);
			print_list(*list);
		}
		nxt_node = nxt_node->next;
	}
}


/**
 * swap_node - swap a node with previous node
 * @node: node parameter
 * @list: node list parameter
 * Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev;
	listint_t *current = node;

	prev_node->next = current->next;

	if (current->next)
		current->next->prev = prev_node;

	current->next = prev_node;
	current->prev = prev_node->prev;
	prev_node->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
