#include "lists.h"

/**
 * find_listint_loop - Detects if there's a loop and finds where.
 * @head: Head of the singly linked list.
 *
 * Return: The position of the node where the loop is found otherwise NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *i, *j;
	int flag = 0;

	if (!head || !head->next)
		return (NULL);

	i = head->next;
	j = head->next->next;

	while (i && j && j->next)
	{
		i = i->next;
		j = j->next->next;
		if (i == j)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		for (i = head; i != j; i = i->next, j = j->next)
			;
		return (j);
	}
	return (NULL);
}
