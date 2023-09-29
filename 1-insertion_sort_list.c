#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			iswap_nodes(list, current->prev, current);
		}

		current = next;
	}
}

/**
 * iswap_nodes - insert and swap a node into a sorted doubly linked list
 * @sort_list: Double pointer to the element of the sorted list
 * @node1: Pointer to the node1
 * @node2: Pointer to the node2
 *
 * Return: void
 */
void iswap_nodes(listint_t **sort_list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;

	if (node1 == *sort_list)
		*sort_list = node2;

	print_list(*sort_list);
}
