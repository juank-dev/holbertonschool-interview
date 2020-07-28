#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *tmp = *head;
	listint_t *node;
	listint_t *tmp2;

	if (*head == NULL)
		return (NULL);

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = number;
	if (number < tmp->n)
	{
		node->next = *head;
		*head = node;
	}
	while (tmp->next != NULL)
	{
		if (number < tmp->next->n)
			break;
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	tmp->next = node;
	node->next = tmp2;
	return (node);
}
