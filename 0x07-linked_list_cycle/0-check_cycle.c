#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - validate the linked list is a circle
 * @list: pointer head
 * Return: 0: the linked list is a circle 1: is not a circle
 */

int check_cycle(listint_t *list)
{
	listint_t *hare = list;
	listint_t *tortoise = list;

	if (list == NULL || list->next == NULL)
		return (0);

	if (list->next == list)
		return (1);

	while (hare->next != NULL && hare->next->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (hare == tortoise)
			return (1);
	}
	return (0);
}



