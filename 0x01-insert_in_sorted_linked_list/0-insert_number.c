#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - insert a new node at listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *tmp = *head;
	listint_t *node;
	listint_t *tmp2;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = number;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	if (number < tmp->n)
	{
		node->next = *head;
		*head = node;
		return (node);
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
