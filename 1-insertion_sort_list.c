#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of int in ascending order
 * using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *node = (*list)->next;

	while (node)
	{
		listint_t *insertion_point = node->prev;
		listint_t *tmp = node->next;

		while (insertion_point && node->n < insertion_point->n)
		{
			if (node->next)
				node->next->prev = insertion_point;
			insertion_point->next = node->next;
			node->prev = insertion_point->prev;
			node->next = insertion_point;
			if (insertion_point->prev)
				insertion_point->prev->next = node;
			insertion_point->prev = node;
			if (node->prev == NULL)
				*list = node;
			print_list(*list);
			insertion_point = node->prev;
		}

		node = tmp;
	}
}
