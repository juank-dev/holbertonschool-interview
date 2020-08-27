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
    int len = 0, max = 0;
    while (left != NULL)
    {
        max += 1;
        left = left->next;
    }
    left = *head;
    return(recursive(left, right, max, len));

}

int recursive(listint_t *left, listint_t *right, int max, int len)
{
    int count = 0;
    if(right != NULL)
    {
        len++;
        if (recursive(left, right->next, max, len) == 0)
            return(0);
    }
    else
        return(1);
    
     
    while(count < max - len)
    {
       left = left->next;
       count++;
    }
    
    if(left->n == right->n)
    {
        return(1);
    }
    else
        return(0);
    
}