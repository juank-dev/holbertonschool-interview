#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: head of the singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 **/
int is_palindrome(listint_t **head)
{
	listint_t  *left = *head;
	listint_t *right = *head;

	int length = 0, length2;
	int count = 1, count2 = 1;

	while (left != NULL)
	{
		length += 1;
		left = left->next;
	}

	left = *head;
	length2 = length;

	while (length / 2 >= count2)
	{
		while (length2 > count)
		{
			count++;
			right = right->next;
		}

		if (left->n != right->n)
			return (0);

		left = left->next;
		right = *head;
		length2 = length - count2;
		count2++;
		count = 1;
	}
	return (1);
}