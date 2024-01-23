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

	listint_t *current = (*list)->next;

	while (current)
	{
		listint_t *insertion_point = current->prev;
		listint_t *tmp = current->next;

		while (insertion_point && current->n < insertion_point->n)
		{
			if (current->next)
				current->next->prev = insertion_point;
			insertion_point->next = current->next;
			current->prev = insertion_point->prev;
			current->next = insertion_point;
			if (insertion_point->prev)
				insertion_point->prev->next = current;
			insertion_point->prev = current;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			insertion_point = current->prev;
		}

		current = tmp;
	}
}
