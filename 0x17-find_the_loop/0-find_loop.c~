#include "lists.h"

/**
 * find_listint_loop - Detects if there's a loop and finds where.
 * @head: Head of the singly linked list.
 *
 * Return: The position of the node where the loop is found otherwise NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;
	int flag = 0;

	if (!head || !head->next)
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		for (slow = head; slow != fast; slow = slow->next, fast = fast->next)
			;
		return (fast);
	}
	return (NULL);
}
