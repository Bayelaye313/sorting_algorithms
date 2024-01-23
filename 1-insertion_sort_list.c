#include "sort.h"

/**
 * insertion_sort_list - Sorts a dbllist of integers in ascending order
 * using the Insertion sort algorithm.
 * @list: Doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			temp = current;

			if (temp->next)
				temp->next->prev = temp->prev;

			temp->prev->next = temp->next;

			current = temp->prev;

			temp->prev = current->prev;
			temp->next = current;

			if (current->prev)
				current->prev->next = temp;

			current->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);

			current = current->prev;
		}

		current = current->next;
	}
}
